/* AXError.h

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

#ifndef __gnustep_boron_AXError
#define __gnustep_boron_AXError

typedef int AXError;

#define kAXErrorSuccess 0,
#define kAXErrorFailure -25200
#define kAXErrorIllegalArgument -25201
#define kAXErrorInvalidUIElement -25202
#define kAXErrorInvalidUIElementObserver -25203
#define kAXErrorCannotComplete -25204
#define kAXErrorAttributeUnsupported -25205
#define kAXErrorActionUnsupported -25206
#define kAXErrorNotificationUnsupported -25207
#define kAXErrorNotImplemented -25208
#define kAXErrorNotificationAlreadyRegistered -25209
#define kAXErrorNotificationNotRegistered -25210
#define kAXErrorAPIDisabled -25211
#define kAXErrorNoValue -25212
#define kAXErrorParameterizedAttributeUnsupported -25213
#define	kAXErrorNotEnoughPrecision -25214

#endif
