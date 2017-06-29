/* MacErrors.h

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

#ifndef __gnustep_boron_MacErrors 
#define __gnustep_boron_MacErrors 

#ifdef __cplusplus
extern "C" {
#endif

enum
{
  paramErr = -50,
  noHardwareErr = -200,
  notEnoughHardwareErr = -201,
  userCanceledErr = -128,
  qErr = -1,
  vTypErr = -2,
  corErr = -3,
  unimpErr = -4,
  SlpTypeErr = -5,
  seNoDB = -8,
  controlErr = -17,
  statusErr = -18,
  readErr = -19,
  writErr = -20,
  badUnitErr = -21,
  unitEmptyErr = -22,
  openErr = -23,
  closErr = -24,
  dRemovErr = -25,
  dInstErr = -26
};

enum {
  kTextUnsupportedEncodingErr = -8738,
  kTextMalformedInputErr = -8739,
  kTextUndefinedElementErr = -8740,
  kTECMissingTableErr = -8745,
  kTECTableChecksumErr = -8746,
  kTECTableFormatErr = -8747,
  kTECCorruptConverterErr = -8748,
  kTECNoConversionPathErr = -8749,
  kTECBufferBelowMinimumSizeErr = -8750,
  kTECArrayFullErr = -8751,
  kTECBadTextRunErr = -8752,
  kTECPartialCharErr = -8753,
  kTECUnmappableElementErr = -8754,
  kTECIncompleteElementErr = -8755,
  kTECDirectionErr = -8756,
  kTECGlobalsUnavailableErr = -8770,
  kTECItemUnavailableErr = -8771,

  kTECUsedFallbacksStatus = -8783,
  kTECNeedFlushStatus = -8784,
  kTECOutputBufferFullStatus = -8785,

  unicodeChecksumErr = -8769,
  unicodeNoTableErr = -8768,
  unicodeVariantErr = -8767,
  unicodeFallbacksErr = -8766,
  unicodePartConvertErr = -8765,
  unicodeBufErr = -8764,
  unicodeCharErr = -8763,
  unicodeElementErr = -8762,
  unicodeNotFoundErr = -8761,
  unicodeTableFormatErr = -8760,
  unicodeDirectionErr = -8759,
  unicodeContextualErr = -8758,
  unicodeTextEncodingDataErr = -8757
};

enum {
  abortErr = -27,
  iIOAbortErr = -27,
  notOpenErr = -28,
  unitTblFullErr = -29,
  dceExtErr = -30,
  slotNumErr = -360,
  gcrOnMFMErr = -400,
  dirFulErr = -33,
  dskFulErr = -34,
  nsvErr = -35,
  ioErr = -36,
  bdNamErr = -37,
  fnOpnErr = -38,
  eofErr = -39,
  posErr = -40,
  mFulErr = -41,
  tmfoErr = -42,
  fnfErr = -43,
  wPrErr = -44,
  fLckdErr = -45   /*file is locked*/
};

#ifdef __cplusplus
}
#endif

#endif

