/* Base32.c

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

/*
 * This is heavily based on "decode-dyn-uti.swift", authored by Jacob
 * Bandes-Storch (https://gist.github.com/jtbandes/19646e7457208ae9b1ad),
 * licensed under the public domain.
 *
 * We implement a custom Base32 encoder/decoder for the Apple UTI dynamic
 * identifier format.
 */

#include "Base32.h"
#include <stdarg.h>

static const char base32[32] = {
  'a', 'b', 'c', 'd',
  'e', 'f', 'g', 'h',
  'k', 'm', 'n', 'p',
  'q', 'r', 's', 't',
  'u', 'v', 'w', 'x',
  'y', 'z', '0', '1',
  '2', '3', '4', '5',
  '6', '7', '8', '9'
};

// FIXME: this is retarded
static CFIndex _indexOf(char c) {
  for (int i = 0; i < 32; i++) {
    if (base32[i] == c)
      return i;
  }

  return -1;
}

CFStringRef Base32CreateEncoded(CFStringRef text) {
  CFMutableStringRef ret = CFStringCreateMutable(NULL, 0);

  CFIndex encoded = 0;
  CFIndex encodedBits = 0;

  for (CFIndex i = 0; i < CFStringGetLength(text); i++) {
    char c = CFStringGetCharacterAtIndex(text, i);

    encoded = (encoded << 8) | c;
    encodedBits += 8;

    while (encodedBits >= 5) {
      CFIndex extra = encodedBits - 5;
      CFStringAppendFormat(ret, NULL, CFSTR("%c"), base32[(encoded >> extra)]);
      
      encoded &= (1 << extra) - 1;
      encodedBits = extra;
    }
  }
  if (encodedBits > 0) {
    CFStringAppendFormat(ret, NULL, CFSTR("%c"), base32[encoded]);
  }

  return ret;
}

CFStringRef Base32CreateDecoded(CFStringRef text) {
  CFMutableStringRef ret = CFStringCreateMutable(NULL, 0);

  CFIndex decoded = 0;
  CFIndex decodedBits = 0;

  for (CFIndex i = 0; i < CFStringGetLength(text); i++) {
    char c = CFStringGetCharacterAtIndex(text, i);
    
    CFIndex pos = _indexOf(c);
    if (pos == -1) return NULL;

    decoded = (decoded << 5) | pos;
    decodedBits += 5;

    if (decodedBits >= 8) {
      CFIndex extra = decodedBits - 8;

      CFStringAppendFormat(ret, NULL, CFSTR("%c"), (decoded >> extra));
      decoded &= (1 << extra) - 1;
      decodedBits = extra;
    }
  }

  return ret;
}
