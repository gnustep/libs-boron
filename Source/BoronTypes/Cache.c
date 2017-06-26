/* Cache.c

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
#include <pthread.h>
#include "PlistParser.h"

static CFMutableDictionaryRef typeMap = NULL;
static CFMutableDictionaryRef tagClassMap = NULL;

void _UTAddPropertyListToCache(CFPropertyListRef plist)
{
  static pthread_mutex_t mutex;
  pthread_mutex_lock(&mutex);
  
  if (typeMap == NULL)
    typeMap = CFDictionaryCreateMutable(NULL, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);

  if (tagClassMap == NULL)
    tagClassMap = CFDictionaryCreateMutable(NULL, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);

  _UTParseAppPropertyListIntoMaps(plist, typeMap, tagClassMap);
  
  pthread_mutex_unlock(&mutex);
}

CFDictionaryRef _UTCacheCopyTypeMap()
{
  if (typeMap == NULL)
    return NULL;

  return CFDictionaryCreateCopy(NULL, typeMap);
}

CFDictionaryRef _UTCacheCopyTagMap()
{
  if (tagClassMap == NULL)
    return NULL;

  return CFDictionaryCreateCopy(NULL, tagClassMap);
}
