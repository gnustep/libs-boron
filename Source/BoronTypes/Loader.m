/* Loader.c

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

#include "Cache.h"
#include <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>

// FIXME: Currently, we are only loading system UTIs from a
// (very badly defined) static location.
//
// This function should iterate through GNUstep apps and have
// a minimally decent mechanism (possibly insired in Apple's
// CoreServices bundle) to store the system UTIs plist.
__attribute__((constructor))
static void UTILoad() {
  // HACK: This is needed to avoid some issues with CoreBase and constant
  // strings.
  [NSString load];
  
  // We use Objective-C and Base here because CoreBase's plist parser is
  // broken.
  NSString *path = @"/usr/local/share/GNUstep/utis.plist";
  NSData *data = [NSData dataWithContentsOfFile:path];
  NSError *err = NULL;
  NSDictionary *plist = [NSPropertyListSerialization propertyListWithData:data options:0 format:NULL error:&err];

  _UTAddPropertyListToCache((CFDictionaryRef)plist);
}
