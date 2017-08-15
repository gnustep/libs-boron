/* UTI.c

   Copyright (C) 2017 Free Software Foundation, Inc.

   Written by: Daniel Ferreira
   Date: June, 2017

   This file is part of GNUstep Boron Library.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; see the file COPYING.LIB.
   If not, see <http://www.gnu.org/licenses/> or write to the
   Free Software Foundation, 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#include <CoreFoundation/CoreFoundation.h>
#include <LaunchServices/UTType.h>
#include <LaunchServices/UTCoreTypes.h>
#include "Base32.h"
#include "Cache.h"

/*
 * Helper to verify whether a CFDictionaryRef contains a key-value
 * subset of another CFDictionaryRef.
 */
struct _isSubsetContext {
  CFDictionaryRef b;
  Boolean ret;
};
static void _isSubsetCallback(const void *k, const void *v, void *ctx) {
  CFStringRef value = (CFStringRef)v;
  struct _isSubsetContext *context = (struct _isSubsetContext *)ctx;
  
  CFStringRef bValue = CFDictionaryGetValue(context->b, k);
  if (bValue == NULL)
    context->ret = FALSE;
  else
    context->ret = context->ret && !CFStringCompare(bValue, value, 0);
}
static Boolean _isSubset(CFDictionaryRef a, CFDictionaryRef b) {
  struct _isSubsetContext ctx;
  ctx.b = b;
  ctx.ret = TRUE;

  CFDictionaryApplyFunction(a, &_isSubsetCallback, &ctx);
  return ctx.ret;
}

/*
 * The dynamic identifier handling code is inspired in a writeup
 * by Alastair Houghton, which can be found locally in
 * ./dynamic-utis.html.
 *
 * This is *NOT* a full implementation of the format as described
 * by him. It's just enough to handle the case of dynamic identifiers
 * created by the API itself.
 */

static CFStringRef _UTTypeGetDecodedDynamicAlias(char alias) {
  switch (alias) {
    case '0': return kUTTypeConformsToKey;
    case '1': return kUTTagClassFilenameExtension;
    case '2': return kUTTagClassOSType;
    case '3': return kUTTagClassMIMEType;
    case '4': return kUTTagClassNSPboardType;
    case '5': return CFSTR("public.url-scheme");
    case '6': return kUTTypeData;
    case '7': return kUTTypeText;
    case '8': return kUTTypePlainText;
    case '9': return kUTTypeUTF16PlainText;
    case 'A': return CFSTR("com.apple.traditional-mac-plain-text");
    case 'B': return kUTTypeImage;
    case 'C': return kUTTypeVideo;
    case 'D': return kUTTypeAudio;
    case 'E': return kUTTypeDirectory;
    case 'F': return kUTTypeFolder;
  }

  return NULL;
}

static CFStringRef _UTTypeEncodeToDynamicAlias(CFStringRef text) {
  /* FIXME: Cache these values! */
  CFStringRef aliases[16] = {
    kUTTypeConformsToKey,
    kUTTagClassFilenameExtension,
    kUTTagClassOSType,
    kUTTagClassMIMEType,
    kUTTagClassNSPboardType,
    CFSTR("public.url-scheme"),
    kUTTypeData,
    kUTTypeText,
    kUTTypePlainText,
    kUTTypeUTF16PlainText,
    CFSTR("com.apple.traditional-mac-plain-text"),
    kUTTypeImage,
    kUTTypeVideo,
    kUTTypeAudio,
    kUTTypeDirectory,
    kUTTypeFolder
  };
  CFStringRef strings[16] = {
    CFSTR("0"),
    CFSTR("1"),
    CFSTR("2"),
    CFSTR("3"),
    CFSTR("4"),
    CFSTR("5"),
    CFSTR("6"),
    CFSTR("7"),
    CFSTR("8"),
    CFSTR("9"),
    CFSTR("A"),
    CFSTR("B"),
    CFSTR("C"),
    CFSTR("D"),
    CFSTR("E"),
    CFSTR("F")
  };
  CFDictionaryRef map = CFDictionaryCreate(NULL, (const void **)aliases, (const void **)strings, 16, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);

  CFStringRef ret = (CFStringRef)CFDictionaryGetValue(map, text);
  return ret ?: text;
}

static CFStringRef _UTTypeCreateDynamicIdentifier(CFStringRef key, CFStringRef value, CFStringRef conformsTo) {
  CFMutableStringRef dynamic = CFStringCreateMutable(NULL, 0);
  CFStringAppend(dynamic, CFSTR("?"));
  
  if (conformsTo != NULL) {
    CFStringAppend(dynamic, _UTTypeEncodeToDynamicAlias(kUTTypeConformsToKey));
    CFStringAppend(dynamic, CFSTR("="));
    CFStringAppend(dynamic, _UTTypeEncodeToDynamicAlias(conformsTo));
    CFStringAppend(dynamic, CFSTR(":"));
  }

  CFStringAppend(dynamic, _UTTypeEncodeToDynamicAlias(key));
  CFStringAppend(dynamic, CFSTR("="));
  CFStringAppend(dynamic, _UTTypeEncodeToDynamicAlias(value));
  
  CFStringRef encoded = Base32CreateEncoded(dynamic);
  CFRelease(dynamic);

  CFMutableStringRef ret = CFStringCreateMutable(NULL, 0);
  CFStringAppend(ret, CFSTR("dyn.a"));
  CFStringAppend(ret, encoded);
  CFRelease(encoded);

  return ret;
}

static CFDictionaryRef _UTTypeCreateTypeFromDynamicIdentifier(CFStringRef identifier) {
  CFMutableDictionaryRef ret = CFDictionaryCreateMutable(NULL, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);

  CFStringRef encoded = CFStringCreateWithSubstring(NULL, identifier, CFRangeMake(5, CFStringGetLength(identifier) - 5));
  CFStringRef dynamic_ = Base32CreateDecoded(encoded);
  CFMutableStringRef dynamic = CFStringCreateMutableCopy(NULL, 0, dynamic_);
  CFRelease(encoded);
  CFRelease(dynamic_);

  // Remove first '?' character in decoded string.
  CFStringDelete(dynamic, CFRangeMake(0, 1));

  CFArrayRef pairs = CFStringCreateArrayBySeparatingStrings(NULL, dynamic, CFSTR(":"));
  CFRelease(dynamic);

  for (CFIndex i = 0; i < CFArrayGetCount(pairs); i++) {
    CFStringRef pair = CFArrayGetValueAtIndex(pairs, i);
    CFArrayRef keyVal = CFStringCreateArrayBySeparatingStrings(NULL, pair, CFSTR("="));
    
    CFStringRef key = CFArrayGetValueAtIndex(keyVal, 0);
    CFStringRef value = CFArrayGetValueAtIndex(keyVal, 1);

    if (CFStringGetLength(key) == 1)
      key = _UTTypeGetDecodedDynamicAlias(CFStringGetCharacterAtIndex(key, 0));
    if (CFStringGetLength(value) == 1)
      value = _UTTypeGetDecodedDynamicAlias(CFStringGetCharacterAtIndex(value, 0));
    
    CFDictionaryAddValue(ret, key, value);
    CFRelease(keyVal);
  }

  CFRelease(pairs);
  return ret;
}

static CFArrayRef
_UTTypeCreateAllIdentifiersForTagInternal(
  CFStringRef              inTagClass,
  CFStringRef              inTag,
  CFStringRef   inConformingToUTI,
  Boolean ignoreConformingTo)
{
  /*
   * NOTE: the documentation states that this function returns NULL
   * if inTagClass is not a known tag class. However, observed
   * behavior is to return a dynamic identifier anyway.
   */

  if (inTagClass == NULL || inTag == NULL)
    return NULL;

  CFDictionaryRef tagClassMap = _UTCacheCopyTagMap();
  CFDictionaryRef tagMap = CFDictionaryGetValue(tagClassMap, inTagClass);
  
  if (tagMap == NULL) {
    CFRelease(tagClassMap);
    
    CFStringRef dynamic = _UTTypeCreateDynamicIdentifier(inTagClass, inTag, inConformingToUTI);
    CFArrayRef ret = CFArrayCreate(NULL, (const void **)&dynamic, 1, &kCFTypeArrayCallBacks);
    CFRelease(dynamic);
    
    return ret;
  }
  
  CFArrayRef allTypes = CFDictionaryGetValue(tagMap, inTag);
  if (allTypes == NULL || CFArrayGetCount(allTypes) == 0) {
    CFRelease(tagClassMap);

    CFStringRef dynamic = _UTTypeCreateDynamicIdentifier(inTagClass, inTag, inConformingToUTI);
    CFArrayRef ret = CFArrayCreate(NULL, (const void **)&dynamic, 1, &kCFTypeArrayCallBacks);
    CFRelease(dynamic);
    
    return ret;
  }

  CFMutableArrayRef filteredTypes = CFArrayCreateMutableCopy(NULL, 0, allTypes);

  if (inConformingToUTI != NULL && !ignoreConformingTo) {
    for (CFIndex i = 0; i < CFArrayGetCount(filteredTypes); i++) {
      CFStringRef typeId = CFArrayGetValueAtIndex(allTypes, i);
      if (!UTTypeConformsTo(typeId, inConformingToUTI)) {
        CFArrayRemoveValueAtIndex(filteredTypes, i);
        i--;
      }
    }
  }

  if (CFArrayGetCount(filteredTypes) == 0) {
    CFRelease(tagClassMap);

    CFStringRef dynamic = _UTTypeCreateDynamicIdentifier(inTagClass, inTag, inConformingToUTI);
    CFArrayAppendValue(filteredTypes, dynamic);
    CFRelease(dynamic);
    
    return filteredTypes;
  }

  CFRelease(tagClassMap);
  return filteredTypes;
}

CFStringRef
UTTypeCreatePreferredIdentifierForTag(
  CFStringRef              inTagClass,
  CFStringRef              inTag,
  CFStringRef   inConformingToUTI)
{
  /*
   * NOTE: Despite the documentation, OSX ignores inConformingToUTI in
   * this function (except for dynamic-id generation purposes).
   */

  CFStringRef ret;
  CFDictionaryRef typeMap = _UTCacheCopyTypeMap();

  CFArrayRef allTypes = _UTTypeCreateAllIdentifiersForTagInternal(inTagClass, inTag, inConformingToUTI, TRUE);
  if (allTypes == NULL)
    return NULL;

  for (CFIndex i = 0; i < CFArrayGetCount(allTypes); i++) {
    CFStringRef typeId = CFArrayGetValueAtIndex(allTypes, i);
    if (UTTypeIsDynamic(typeId))
      continue;

    CFDictionaryRef type = CFDictionaryGetValue(typeMap, typeId);

    if (CFDictionaryGetValue(type, CFSTR("GSUTIIsExported")) == kCFBooleanTrue) {
      ret = typeId;
      goto found;
    }
  }
  
  // TODO: public.* identifiers should take precedence

  /*
   * The documentation states that behavior is undefined in this case.
   * So we just pick the first value in the array.
   */
  ret = CFArrayGetValueAtIndex(allTypes, 0);

found:
  CFRelease(allTypes);
  CFRelease(typeMap);
  
  return CFStringCreateCopy(NULL, ret);
}

CFArrayRef
UTTypeCreateAllIdentifiersForTag(
  CFStringRef              inTagClass,
  CFStringRef              inTag,
  CFStringRef   inConformingToUTI)
{
  return _UTTypeCreateAllIdentifiersForTagInternal(inTagClass, inTag, inConformingToUTI, FALSE);
}

CFStringRef
UTTypeCopyPreferredTagWithClass(
  CFStringRef   inUTI,
  CFStringRef   inTagClass)
{
  CFArrayRef allTags = UTTypeCopyAllTagsWithClass(inUTI, inTagClass);
  if (allTags == NULL || CFArrayGetCount(allTags) == 0)
    return NULL;

  CFStringRef ret = CFArrayGetValueAtIndex(allTags, 0);

  CFRelease(allTags);
  return CFStringCreateCopy(NULL, ret);
}

CFArrayRef
UTTypeCopyAllTagsWithClass(
  CFStringRef   inUTI,
  CFStringRef   inTagClass)
{
  /*
   * NOTE: Despite the documentation, we don't return NULL if we
   * don't find the UTI or the tag class. Instead, we return an
   * empty array.
   */

  if (inUTI == NULL || inTagClass == NULL)
    return NULL;
  
  CFDictionaryRef type;
  if (UTTypeIsDynamic(inUTI))
    type = _UTTypeCreateTypeFromDynamicIdentifier(inUTI);
  else
    type = UTTypeCopyDeclaration(inUTI);

  if (type == NULL) {
    CFRelease(type);
    return CFArrayCreate(NULL, NULL, 0, &kCFTypeArrayCallBacks);
  }

  CFDictionaryRef tags;
  if (UTTypeIsDynamic(inUTI))
    tags = type;
  else
    tags = CFDictionaryGetValue(type, kUTTypeTagSpecificationKey);
  
  if (tags == NULL) {
    CFRelease(type);
    return CFArrayCreate(NULL, NULL, 0, &kCFTypeArrayCallBacks);
  }
  
  CFArrayRef ret;
  CFTypeRef tag = CFDictionaryGetValue(tags, inTagClass);
  if (tag == NULL) {
    CFRelease(type);
    return CFArrayCreate(NULL, NULL, 0, &kCFTypeArrayCallBacks);
  }

  if (CFGetTypeID(tag) == CFArrayGetTypeID()) {
    // NOTE: An easier way to do this would be to CFArrayCreateCopy(), but
    // some weird bug in CoreBase does not allow us to do this.
    ret = CFArrayCreateMutable(NULL, 0, &kCFTypeArrayCallBacks);
    for (CFIndex i = 0; i < CFArrayGetCount(tag); i++) {
      CFArrayAppendValue(ret, CFArrayGetValueAtIndex(tag, i));
    }
  }
  else
    ret = CFArrayCreate(NULL, (const void **)&tag, 1, &kCFTypeArrayCallBacks);

  CFRelease(type);
  return ret;
}

Boolean
UTTypeEqual(
  CFStringRef   inUTI1,
  CFStringRef   inUTI2)
{
  if (!UTTypeIsDynamic(inUTI1) && !UTTypeIsDynamic(inUTI2))
    return CFStringCompare(inUTI1, inUTI2, kCFCompareCaseInsensitive) == 0;
  
  CFDictionaryRef type1, type2;
  
  if (UTTypeIsDynamic(inUTI1))
    type1 = _UTTypeCreateTypeFromDynamicIdentifier(inUTI1);
  else
    type1 = UTTypeCopyDeclaration(inUTI1);
  
  if (UTTypeIsDynamic(inUTI2))
    type2 = _UTTypeCreateTypeFromDynamicIdentifier(inUTI2);
  else
    type2 = UTTypeCopyDeclaration(inUTI2);

  if (type1 == NULL || type2 == NULL)
    return FALSE;

  // FIXME: I do not know if this is right at all. Further investigation
  // of Apple implementation edge-cases would be useful to determine
  // behavior here.
  Boolean ret = _isSubset(type1, type2) || _isSubset(type2, type1);
  CFRelease(type1);
  CFRelease(type2);

  return ret;
}

Boolean
UTTypeConformsTo(
  CFStringRef   inUTI,
  CFStringRef   inConformsToUTI)
{
  CFDictionaryRef type;
  if (UTTypeIsDynamic(inUTI))
    type = _UTTypeCreateTypeFromDynamicIdentifier(inUTI);
  else
    type = UTTypeCopyDeclaration(inUTI);

  if (type == NULL)
    return FALSE;
  
  CFTypeRef conformsToDecl = CFDictionaryGetValue(type, kUTTypeConformsToKey);
  if (conformsToDecl == NULL) {
    CFRelease(type);
    return FALSE;
  }

  CFArrayRef conformsTo;
  if (CFGetTypeID(conformsToDecl) == CFArrayGetTypeID()) {
    // NOTE: An easier way to do this would be to CFArrayCreateCopy(), but
    // some weird bug in CoreBase does not allow us to do this.
    conformsTo = CFArrayCreateMutable(NULL, 0, &kCFTypeArrayCallBacks);
    for (CFIndex i = 0; i < CFArrayGetCount(conformsToDecl); i++) {
      CFArrayAppendValue(conformsTo, CFArrayGetValueAtIndex(conformsToDecl, i));
    }
  }
  else
    conformsTo = CFArrayCreate(NULL, (const void **)&conformsToDecl, 1, &kCFTypeArrayCallBacks);
  
  // FIXME: We're doing a DFS for superclass search. Would a BFS
  // be statistically more efficient?
  Boolean ret = FALSE;
  for (CFIndex i = 0; i < CFArrayGetCount(conformsTo); i++) {
    CFStringRef uti = CFArrayGetValueAtIndex(conformsTo, i);
    
    ret = ret || UTTypeEqual(uti, inConformsToUTI);
    if (ret) break;

    ret = ret || UTTypeConformsTo(uti, inConformsToUTI);
    if (ret) break;
  }

  CFRelease(conformsTo);
  return ret;
}

CFStringRef
UTTypeCopyDescription(CFStringRef inUTI)
{
  CFDictionaryRef declaration = UTTypeCopyDeclaration(inUTI);
  CFStringRef description = CFDictionaryGetValue(declaration, kUTTypeDescriptionKey);
  CFStringRef ret = CFStringCreateCopy(NULL, description);

  CFRelease(declaration);
  return ret;
}

Boolean
UTTypeIsDeclared(CFStringRef inUTI)
{
  if (inUTI == NULL)
    return FALSE;

  if (UTTypeIsDynamic(inUTI))
    return FALSE;

  CFDictionaryRef typeMap = _UTCacheCopyTypeMap();
  CFDictionaryRef type = CFDictionaryGetValue(typeMap, inUTI);
  Boolean ret = (type == NULL);

  CFRelease(typeMap);
  return ret;
}

Boolean
UTTypeIsDynamic(CFStringRef inUTI)
{
  return CFStringHasPrefix(inUTI, CFSTR("dyn"));
}

CFDictionaryRef
UTTypeCopyDeclaration(CFStringRef inUTI)
{
  if (inUTI == NULL)
    return NULL;

  if (UTTypeIsDynamic(inUTI))
    return NULL;

  CFDictionaryRef typeMap = _UTCacheCopyTypeMap();
  CFDictionaryRef type = CFDictionaryGetValue(typeMap, inUTI);
  if (type == NULL) {
    CFRelease(typeMap);
    return NULL;
  }
  
  CFRelease(typeMap);
  return CFDictionaryCreateCopy(NULL, type);
}

CFURLRef
UTTypeCopyDeclaringBundleURL(CFStringRef inUTI)
{
  // FIXME: unimplemented. Requires an overhaul in the loader
  // to actually load UTIs from third parties and map them to
  // bundles.
  return NULL;
}

CFStringRef
UTCreateStringForOSType(OSType inOSType)
{
  // FIXME: unimplemented. Can be fixed stand-alone.
  return NULL;
}

OSType
UTGetOSTypeFromString(CFStringRef inString)
{
  // FIXME: unimplemented. Can be fixed stand-alone.
  return 0;
}
