/* UTType.h

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

#ifndef _gnustep_boron_UTType
#define _gnustep_boron_UTType

#include <CoreFoundation/CoreFoundation.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const CFStringRef kUTExportedTypeDeclarationsKey;
extern const CFStringRef kUTImportedTypeDeclarationsKey;
extern const CFStringRef kUTTypeIdentifierKey;
extern const CFStringRef kUTTypeTagSpecificationKey;
extern const CFStringRef kUTTypeConformsToKey;
extern const CFStringRef kUTTypeDescriptionKey;
extern const CFStringRef kUTTypeIconFileKey;
extern const CFStringRef kUTTypeReferenceURLKey;
extern const CFStringRef kUTTypeVersionKey;

extern const CFStringRef kUTTagClassFilenameExtension;
extern const CFStringRef kUTTagClassMIMEType;
extern const CFStringRef kUTTagClassNSPboardType;
extern const CFStringRef kUTTagClassOSType;

extern CFStringRef
UTTypeCreatePreferredIdentifierForTag(
  CFStringRef              inTagClass,
  CFStringRef              inTag,
  CFStringRef   inConformingToUTI);

extern CFArrayRef
UTTypeCreateAllIdentifiersForTag(
  CFStringRef              inTagClass,
  CFStringRef              inTag,
  CFStringRef   inConformingToUTI);

extern CFStringRef
UTTypeCopyPreferredTagWithClass(
  CFStringRef   inUTI,
  CFStringRef   inTagClass);

extern CFArrayRef
UTTypeCopyAllTagsWithClass(
  CFStringRef   inUTI,
  CFStringRef   inTagClass);

extern Boolean
UTTypeEqual(
  CFStringRef   inUTI1,
  CFStringRef   inUTI2);

extern Boolean
UTTypeConformsTo(
  CFStringRef   inUTI,
  CFStringRef   inConformsToUTI);

extern CFStringRef
UTTypeCopyDescription(CFStringRef inUTI);

extern Boolean
UTTypeIsDeclared(CFStringRef inUTI);

extern Boolean
UTTypeIsDynamic(CFStringRef inUTI);

extern CFDictionaryRef
UTTypeCopyDeclaration(CFStringRef inUTI);

extern CFURLRef
UTTypeCopyDeclaringBundleURL(CFStringRef inUTI);

extern CFStringRef
UTCreateStringForOSType(OSType inOSType);

extern OSType
UTGetOSTypeFromString(CFStringRef inString);

#ifdef __cplusplus
}
#endif

#endif
