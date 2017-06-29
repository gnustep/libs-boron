/* MacTypes.h

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

/*
 * Unlike the original MacTypes.h, this version only includes
 * some types required by Carbon, instead of having an enormous
 * set of system types.
 */

#ifndef __gnustep_boron_MacTypes
#define __gnustep_boron_MacTypes

#include <stdbool.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Use base types from CoreBase */
/*
 * FIXME: importing some CF-only definitions might break stuff here?
 * CoreBase should probably export types in an internal CFTypes.h header
 * that we could import from here.
 */
#include <CoreFoundation/CFBase.h>

/* Additional Carbon types for integers */
typedef SInt32 Fixed;
typedef SInt32 Fract;
typedef UInt32 UnsignedFixed;
typedef short ShortFixed;

typedef void *LogicalAddress;
typedef const void *ConstLogicalAddress;
typedef void *PhysicalAddress;
typedef unsigned long ByteCount;
typedef unsigned long ByteOffset;
typedef SInt32 Duration;
typedef UInt32 OptionBits;
typedef unsigned long ItemCount;
typedef UInt32 PBVersion;
typedef FourCharCode ResType;

/* Common Constants */
#define noErr 0
#define kNilOptions 0
#define kInvalidID 0
#define kVariableLengthArray 1
#define kUnknownType 0x3F3F3F3F

/* Geometry Structs */
struct Point
{
  short v;
  short h;
};
typedef struct Point Point;

struct Rect
{
  short top;
  short left;
  short bottom;
  short right;
};
typedef struct Rect Rect;

struct FixedPoint
{
  Fixed x;
  Fixed y;
};
typedef struct FixedPoint FixedPoint;

struct FixedRect
{
  Fixed left;
  Fixed top;
  Fixed right;
  Fixed bottom;
};
typedef struct FixedRect FixedRect;

#ifdef __cplusplus
}
#endif

#endif

