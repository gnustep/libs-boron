/* Base32.h

   Copyright (C) 2017 Free Software Foundation, Inc.

   Author: Daniel Ferreira
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

#ifndef __BASE32_H_
#define __BASE32_H_

#include <CoreFoundation/CoreFoundation.h>

CFStringRef Base32CreateEncoded(CFStringRef text);
CFStringRef Base32CreateDecoded(CFStringRef text);

#endif
