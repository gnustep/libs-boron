/* PlistParser.c

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

struct _UTParserContext {
  CFMutableDictionaryRef typeMap;
  CFMutableDictionaryRef tagClassMap;
  Boolean exporting;
  CFStringRef typeIdentifier;
};

static void _appendIdentifierToTagMatchArray(CFMutableDictionaryRef tagMap, CFStringRef singleTag, CFStringRef typeIdentifier) {
  CFMutableArrayRef matchedIds = (CFMutableArrayRef)CFDictionaryGetValue(tagMap, singleTag);
  if (matchedIds == NULL) {
    matchedIds = CFArrayCreateMutable(NULL, 0, &kCFTypeArrayCallBacks);
    CFDictionaryAddValue(tagMap, singleTag, matchedIds);
    CFRelease(matchedIds);
  }
  
  CFArrayAppendValue(matchedIds, typeIdentifier);
}

static void _UTParseItemTag(const void *key, const void *value, void *ctx)
{
  struct _UTParserContext *context = (struct _UTParserContext *)ctx;

  CFStringRef typeIdentifier = context->typeIdentifier;
  CFMutableDictionaryRef tagClassMap = context->tagClassMap;

  CFStringRef class = (CFStringRef)key;
  CFTypeRef tag = (CFTypeRef)value;
  
  CFMutableDictionaryRef tagMap = (CFMutableDictionaryRef)CFDictionaryGetValue(tagClassMap, class);

  if (tagMap == NULL) {
    tagMap = CFDictionaryCreateMutable(NULL, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
    CFDictionaryAddValue(tagClassMap, class, tagMap);
    CFRelease(tagMap);
  }

  // The values for a tag can be either an array or a single string.
  if (CFGetTypeID(tag) == CFArrayGetTypeID()) {
    for (CFIndex i = 0; i < CFArrayGetCount((CFArrayRef)tag); i++) {
      CFStringRef singleTag = CFArrayGetValueAtIndex(tag, i);
      _appendIdentifierToTagMatchArray(tagMap, singleTag, typeIdentifier);
    }
  } else {
    _appendIdentifierToTagMatchArray(tagMap, tag, typeIdentifier);
  }
}

static void _UTParseItem(const void *item_, void *ctx)
{
  struct _UTParserContext *context = (struct _UTParserContext *)ctx;
  
  CFDictionaryRef item = (CFDictionaryRef)item_;
  Boolean isExported = context->exporting;
  
  CFMutableDictionaryRef typeMap = context->typeMap;
  
  CFMutableDictionaryRef type = CFDictionaryCreateMutableCopy(NULL, 0, item);
  CFDictionaryAddValue(type, CFSTR("GSUTIIsExported"), isExported ? kCFBooleanTrue : kCFBooleanFalse);
  
  CFStringRef typeIdentifier = CFDictionaryGetValue(type, kUTTypeIdentifierKey);
  
  if (CFDictionaryGetValue(typeMap, typeIdentifier) != NULL) {
    /*
     * NOTE: Apple has a mechanism in LaunchServices (which can be verified
     * in the `lsregister` commandline tool) which ultimately consider repeated
     * UTIs as "inactive" and they are utterly ignored by the API.
     *
     * Since we don't understand how this mechanism works, we'll just stop
     * any repeated type identifiers from being processed. Later we might want
     * to refine this logic.
     */
    return;
  }
  
  CFDictionaryAddValue(typeMap, typeIdentifier, type);

  context->typeIdentifier = typeIdentifier;
  CFDictionaryRef tags = CFDictionaryGetValue(type, kUTTypeTagSpecificationKey);
  if (tags != NULL)
    CFDictionaryApplyFunction(tags, &_UTParseItemTag, context);
  
  CFRelease(type);
}

void _UTParseAppPropertyListIntoMaps(CFPropertyListRef plist,
    CFMutableDictionaryRef typeMap, CFMutableDictionaryRef tagClassMap)
{
  struct _UTParserContext context;
  context.typeMap = typeMap;
  context.tagClassMap = tagClassMap;
  
  CFArrayRef exportedTypes = CFDictionaryGetValue((CFDictionaryRef)plist,
      kUTExportedTypeDeclarationsKey);
  CFArrayRef importedTypes = CFDictionaryGetValue((CFDictionaryRef)plist,
      kUTImportedTypeDeclarationsKey);
  
  context.exporting = TRUE;
  CFArrayApplyFunction(exportedTypes, CFRangeMake(0, CFArrayGetCount(exportedTypes)), &_UTParseItem, &context);
  
  context.exporting = FALSE;
  CFArrayApplyFunction(importedTypes, CFRangeMake(0, CFArrayGetCount(importedTypes)), &_UTParseItem, &context);
}
