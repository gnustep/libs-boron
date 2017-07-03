/* UniversalAccess.h

   Copyright (C) 2017 Free Software Foundation, Inc.

   Written by: Daniel Ferreira
   Date: July, 2017

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

#ifndef __gnustep_boron_UniversalAccess
#define __gnustep_boron_UniversalAccess

#include <CoreFoundation/CFBase.h>
#include <CoreGraphics/CoreGraphics.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef uint32_t UAZoomChangeFocusType;

enum
{
  kUAZoomFocusTypeOther = 0,
  kUAZoomFocusTypeInsertionPoint = 1
};

extern Boolean 
UAZoomEnabled(void);

extern OSStatus 
UAZoomChangeFocus(
  const CGRect *inRect,
  const CGRect *inHighlightRect,
  UAZoomChangeFocusType inType);

#ifdef __cplusplus
}
#endif

#endif
