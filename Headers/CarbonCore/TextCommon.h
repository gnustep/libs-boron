/*
This file is part of Darling.

Copyright (C) 2017 Lubos Dolezel

Darling is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Darling is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Darling.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _TEXTCOMMON_H
#define _TEXTCOMMON_H

#include <CoreFoundation/CFBase.h>
#include <MacTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef UInt8* TextPtr;
typedef const UInt8* ConstTextPtr;
typedef UInt32 TextEncoding;
typedef UInt32 TextEncodingBase;
typedef UInt32 TextEncodingFormat;
typedef UInt32 TextEncodingVariant;

enum
{
  kTextFlushDefault = 0,
  kTextCenter = 1,
  kTextFlushRight = -1,
  kTextFlushLeft = -2
};

enum
{
  kTextEncodingMacRoman = 0,
  kTextEncodingMacJapanese = 1,
  kTextEncodingMacChineseTrad = 2,
  kTextEncodingMacKorean = 3,
  kTextEncodingMacArabic = 4,
  kTextEncodingMacHebrew = 5,
  kTextEncodingMacGreek = 6,
  kTextEncodingMacCyrillic = 7,
  kTextEncodingMacDevanagari = 9,
  kTextEncodingMacGurmukhi = 10,
  kTextEncodingMacGujarati = 11,
  kTextEncodingMacOriya = 12,
  kTextEncodingMacBengali = 13,
  kTextEncodingMacTamil = 14,
  kTextEncodingMacTelugu = 15,
  kTextEncodingMacKannada = 16,
  kTextEncodingMacMalayalam = 17,
  kTextEncodingMacSinhalese = 18,
  kTextEncodingMacBurmese = 19,
  kTextEncodingMacKhmer = 20,
  kTextEncodingMacThai = 21,
  kTextEncodingMacLaotian = 22,
  kTextEncodingMacGeorgian = 23,
  kTextEncodingMacArmenian = 24,
  kTextEncodingMacChineseSimp = 25,
  kTextEncodingMacTibetan = 26,
  kTextEncodingMacMongolian = 27,
  kTextEncodingMacEthiopic = 28,
  kTextEncodingMacCentralEurRoman = 29,
  kTextEncodingMacVietnamese = 30,
  kTextEncodingMacExtArabic = 31,
  kTextEncodingMacSymbol = 33,
  kTextEncodingMacDingbats = 34,
  kTextEncodingMacTurkish = 35,
  kTextEncodingMacCroatian = 36,
  kTextEncodingMacIcelandic = 37,
  kTextEncodingMacRomanian = 38,
  kTextEncodingMacCeltic = 39,
  kTextEncodingMacGaelic = 40,
  kTextEncodingMacKeyboardGlyphs = 41
};

enum
{
  kTextEncodingMacTradChinese = kTextEncodingMacChineseTrad,
  kTextEncodingMacRSymbol = 8,
  kTextEncodingMacSimpChinese = kTextEncodingMacChineseSimp,
  kTextEncodingMacGeez = kTextEncodingMacEthiopic,
  kTextEncodingMacEastEurRoman = kTextEncodingMacCentralEurRoman,
  kTextEncodingMacUninterp = 32
};

enum
{
  kTextEncodingMacUnicode = 0x7E
};

enum
{
  kTextEncodingMacFarsi = 0x8C,
  kTextEncodingMacUkrainian = 0x98,
  kTextEncodingMacInuit = 0xEC,
  kTextEncodingMacVT100 = 0xFC
};

enum
{
  kTextEncodingMacHFS = 0xFF
};

enum
{
  kTextEncodingUnicodeDefault = 0x0100,
  kTextEncodingUnicodeV1_1 = 0x0101,
  kTextEncodingISO10646_1993 = 0x0101,
  kTextEncodingUnicodeV2_0 = 0x0103,
  kTextEncodingUnicodeV2_1 = 0x0103,
  kTextEncodingUnicodeV3_0 = 0x0104,
  kTextEncodingUnicodeV3_1 = 0x0105,
  kTextEncodingUnicodeV3_2 = 0x0106,
  kTextEncodingUnicodeV4_0 = 0x0108,
  kTextEncodingUnicodeV5_0 = 0x010A,
  kTextEncodingUnicodeV5_1 = 0x010B,
  kTextEncodingUnicodeV6_0 = 0x010D,
  kTextEncodingUnicodeV6_1 = 0x010E,
  kTextEncodingUnicodeV6_3 = 0x0110,
  kTextEncodingUnicodeV7_0 = 0x0111
};

enum
{
  kTextEncodingISOLatin1 = 0x0201,
  kTextEncodingISOLatin2 = 0x0202,
  kTextEncodingISOLatin3 = 0x0203,
  kTextEncodingISOLatin4 = 0x0204,
  kTextEncodingISOLatinCyrillic = 0x0205,
  kTextEncodingISOLatinArabic = 0x0206,
  kTextEncodingISOLatinGreek = 0x0207,
  kTextEncodingISOLatinHebrew = 0x0208,
  kTextEncodingISOLatin5 = 0x0209,
  kTextEncodingISOLatin6 = 0x020A,
  kTextEncodingISOLatin7 = 0x020D,
  kTextEncodingISOLatin8 = 0x020E,
  kTextEncodingISOLatin9 = 0x020F,
  kTextEncodingISOLatin10 = 0x0210
};

enum
{
  kTextEncodingDOSLatinUS = 0x0400,
  kTextEncodingDOSGreek = 0x0405,
  kTextEncodingDOSBalticRim = 0x0406,
  kTextEncodingDOSLatin1 = 0x0410,
  kTextEncodingDOSGreek1 = 0x0411,
  kTextEncodingDOSLatin2 = 0x0412,
  kTextEncodingDOSCyrillic = 0x0413,
  kTextEncodingDOSTurkish = 0x0414,
  kTextEncodingDOSPortuguese = 0x0415,
  kTextEncodingDOSIcelandic = 0x0416,
  kTextEncodingDOSHebrew = 0x0417,
  kTextEncodingDOSCanadianFrench = 0x0418,
  kTextEncodingDOSArabic = 0x0419,
  kTextEncodingDOSNordic = 0x041A,
  kTextEncodingDOSRussian = 0x041B,
  kTextEncodingDOSGreek2 = 0x041C,
  kTextEncodingDOSThai = 0x041D,
  kTextEncodingDOSJapanese = 0x0420,
  kTextEncodingDOSChineseSimplif = 0x0421,
  kTextEncodingDOSKorean = 0x0422,
  kTextEncodingDOSChineseTrad = 0x0423,
  kTextEncodingWindowsLatin1 = 0x0500,
  kTextEncodingWindowsANSI = 0x0500,
  kTextEncodingWindowsLatin2 = 0x0501,
  kTextEncodingWindowsCyrillic = 0x0502,
  kTextEncodingWindowsGreek = 0x0503,
  kTextEncodingWindowsLatin5 = 0x0504,
  kTextEncodingWindowsHebrew = 0x0505,
  kTextEncodingWindowsArabic = 0x0506,
  kTextEncodingWindowsBalticRim = 0x0507,
  kTextEncodingWindowsVietnamese = 0x0508,
  kTextEncodingWindowsKoreanJohab = 0x0510
};

enum
{
  kTextEncodingUS_ASCII = 0x0600,
  kTextEncodingANSEL = 0x0601,
  kTextEncodingJIS_X0201_76 = 0x0620,
  kTextEncodingJIS_X0208_83 = 0x0621,
  kTextEncodingJIS_X0208_90 = 0x0622,
  kTextEncodingJIS_X0212_90 = 0x0623,
  kTextEncodingJIS_C6226_78 = 0x0624,
  kTextEncodingShiftJIS_X0213 = 0x0628,
  kTextEncodingJIS_X0213_MenKuTen = 0x0629,
  kTextEncodingGB_2312_80 = 0x0630,
  kTextEncodingGBK_95 = 0x0631,
  kTextEncodingGB_18030_2000 = 0x0632,
  kTextEncodingGB_18030_2005 = 0x0632,
  kTextEncodingKSC_5601_87 = 0x0640,
  kTextEncodingKSC_5601_92_Johab = 0x0641,
  kTextEncodingCNS_11643_92_P1 = 0x0651,
  kTextEncodingCNS_11643_92_P2 = 0x0652,
  kTextEncodingCNS_11643_92_P3 = 0x0653
};

enum
{
  kTextEncodingISO_2022_JP = 0x0820,
  kTextEncodingISO_2022_JP_2 = 0x0821,
  kTextEncodingISO_2022_JP_1 = 0x0822,
  kTextEncodingISO_2022_JP_3 = 0x0823,
  kTextEncodingISO_2022_CN = 0x0830,
  kTextEncodingISO_2022_CN_EXT = 0x0831,
  kTextEncodingISO_2022_KR = 0x0840
};

enum
{
  kTextEncodingEUC_JP = 0x0920,
  kTextEncodingEUC_CN = 0x0930,
  kTextEncodingEUC_TW = 0x0931,
  kTextEncodingEUC_KR = 0x0940
};

enum
{
  kTextEncodingShiftJIS = 0x0A01,
  kTextEncodingKOI8_R = 0x0A02,
  kTextEncodingBig5 = 0x0A03,
  kTextEncodingMacRomanLatin1 = 0x0A04,
  kTextEncodingHZ_GB_2312 = 0x0A05,
  kTextEncodingBig5_HKSCS_1999 = 0x0A06,
  kTextEncodingVISCII = 0x0A07,
  kTextEncodingKOI8_U = 0x0A08,
  kTextEncodingBig5_E = 0x0A09
};

enum
{
  kTextEncodingNextStepLatin = 0x0B01,
  kTextEncodingNextStepJapanese = 0x0B02
};

enum
{
  kTextEncodingEBCDIC_LatinCore = 0x0C01,
  kTextEncodingEBCDIC_CP037 = 0x0C02
};

enum
{
  kTextEncodingMultiRun = 0x0FFF,
  kTextEncodingUnknown = 0xFFFF
};

enum
{
  kTextEncodingEBCDIC_US = 0x0C01
};

enum
{
  kTextEncodingDefaultVariant = 0
};

enum
{
  kMacRomanDefaultVariant = 0,
  kMacRomanCurrencySignVariant = 1,
  kMacRomanEuroSignVariant = 2
};

enum
{
  kMacCyrillicDefaultVariant = 0,
  kMacCyrillicCurrSignStdVariant = 1,
  kMacCyrillicCurrSignUkrVariant = 2,
  kMacCyrillicEuroSignVariant = 3
};

enum
{
  kMacIcelandicStdDefaultVariant = 0,
  kMacIcelandicTTDefaultVariant = 1,
  kMacIcelandicStdCurrSignVariant = 2,
  kMacIcelandicTTCurrSignVariant = 3,
  kMacIcelandicStdEuroSignVariant = 4,
  kMacIcelandicTTEuroSignVariant = 5
};

enum
{
  kMacCroatianDefaultVariant = 0,
  kMacCroatianCurrencySignVariant = 1,
  kMacCroatianEuroSignVariant = 2
};

enum
{
  kMacRomanianDefaultVariant = 0,
  kMacRomanianCurrencySignVariant = 1,
  kMacRomanianEuroSignVariant = 2
};


enum
{
  kMacJapaneseStandardVariant = 0,
  kMacJapaneseStdNoVerticalsVariant = 1,
  kMacJapaneseBasicVariant = 2,
  kMacJapanesePostScriptScrnVariant = 3,
  kMacJapanesePostScriptPrintVariant = 4,
  kMacJapaneseVertAtKuPlusTenVariant = 5
};

enum
{
  kMacArabicStandardVariant = 0,
  kMacArabicTrueTypeVariant = 1,
  kMacArabicThuluthVariant = 2,
  kMacArabicAlBayanVariant = 3
};

enum
{
  kMacFarsiStandardVariant = 0,
  kMacFarsiTrueTypeVariant = 1
};

enum
{
  kMacHebrewStandardVariant = 0,
  kMacHebrewFigureSpaceVariant = 1
};

enum
{
  kMacGreekDefaultVariant = 0,
  kMacGreekNoEuroSignVariant = 1,
  kMacGreekEuroSignVariant = 2
};

enum
{
  kMacVT100DefaultVariant = 0,
  kMacVT100CurrencySignVariant = 1,
  kMacVT100EuroSignVariant = 2
};

enum
{
  kUnicodeNoSubset = 0,
  kUnicodeNormalizationFormD = 5,
  kUnicodeNormalizationFormC = 3,
  kUnicodeHFSPlusDecompVariant = 8,
  kUnicodeHFSPlusCompVariant = 9
};

enum
{
  kISOLatin1StandardVariant = 0,
  kISOLatin1MusicCDVariant = 1
};

enum
{
  kISOLatinArabicImplicitOrderVariant = 0,
  kISOLatinArabicVisualOrderVariant = 1,
  kISOLatinArabicExplicitOrderVariant = 2
};

enum
{
  kISOLatinHebrewImplicitOrderVariant = 0,
  kISOLatinHebrewVisualOrderVariant = 1,
  kISOLatinHebrewExplicitOrderVariant = 2
};

enum
{
  kWindowsLatin1StandardVariant = 0,
  kWindowsLatin1PalmVariant = 1
};

enum
{
  kDOSJapaneseStandardVariant = 0,
  kDOSJapanesePalmVariant = 1
};

enum
{
  kEUC_CN_BasicVariant = 0,
  kEUC_CN_DOSVariant = 1
};

enum
{
  kEUC_KR_BasicVariant = 0,
  kEUC_KR_DOSVariant = 1
};

enum
{
  kShiftJIS_BasicVariant = 0,
  kShiftJIS_DOSVariant = 1,
  kShiftJIS_MusicCDVariant = 2
};

enum
{
  kBig5_BasicVariant = 0,
  kBig5_StandardVariant = 1,
  kBig5_ETenVariant = 2,
  kBig5_DOSVariant = 3
};

enum
{
  kMacRomanLatin1DefaultVariant = 0,
  kMacRomanLatin1StandardVariant = 2,
  kMacRomanLatin1TurkishVariant = 6,
  kMacRomanLatin1CroatianVariant = 8,
  kMacRomanLatin1IcelandicVariant = 11,
  kMacRomanLatin1RomanianVariant = 14
};

enum
{
  kUnicodeNoCompatibilityVariant = 1,
  kUnicodeNoCorporateVariant = 4
};

enum
{
  kMacRomanStandardVariant = 0,
  kMacIcelandicStandardVariant = 0,
  kMacIcelandicTrueTypeVariant = 1,
  kJapaneseStandardVariant = 0,
  kJapaneseStdNoVerticalsVariant = 1,
  kJapaneseBasicVariant = 2,
  kJapanesePostScriptScrnVariant = 3,
  kJapanesePostScriptPrintVariant = 4,
  kJapaneseVertAtKuPlusTenVariant = 5,
  kTextEncodingShiftJIS_X0213_00 = 0x0628,
  kHebrewStandardVariant = 0,
  kHebrewFigureSpaceVariant = 1,
  kUnicodeCanonicalDecompVariant = 2,
  kUnicodeMaxDecomposedVariant = 2,
  kUnicodeCanonicalCompVariant = 3,
  kUnicodeNoComposedVariant = 3
};

enum
{
  kTextEncodingDefaultFormat = 0,
  kUnicodeUTF16Format = 0,
  kUnicodeUTF7Format = 1,
  kUnicodeUTF8Format = 2,
  kUnicodeUTF32Format = 3,
  kUnicodeUTF16BEFormat = 4,
  kUnicodeUTF16LEFormat = 5,
  kUnicodeUTF32BEFormat = 6,
  kUnicodeUTF32LEFormat = 7,
  kUnicodeSCSUFormat = 8,
  kUnicode16BitFormat = 0,
  kUnicode32BitFormat = 3
};

enum
{
  kTextEncodingFullName = 0,
  kTextEncodingBaseName = 1,
  kTextEncodingVariantName = 2,
  kTextEncodingFormatName = 3
};

enum
{
  kTextScriptDontCare = -128,
  kTextLanguageDontCare = -128,
  kTextRegionDontCare = -128
};

enum
{
  kTECKeepInfoFixBit = 0,
  kTECFallbackTextLengthFixBit = 1,
  kTECTextRunBitClearFixBit = 2,
  kTECTextToUnicodeScanFixBit = 3,
  kTECAddForceASCIIChangesBit = 4,
  kTECPreferredEncodingFixBit = 5,
  kTECAddTextRunHeuristicsBit = 6,
  kTECAddFallbackInterruptBit = 7
};

enum
{
  kTECKeepInfoFixMask = 1L << kTECKeepInfoFixBit,
  kTECFallbackTextLengthFixMask = 1L << kTECFallbackTextLengthFixBit,
  kTECTextRunBitClearFixMask = 1L << kTECTextRunBitClearFixBit,
  kTECTextToUnicodeScanFixMask = 1L << kTECTextToUnicodeScanFixBit,
  kTECAddForceASCIIChangesMask = 1L << kTECAddForceASCIIChangesBit,
  kTECPreferredEncodingFixMask = 1L << kTECPreferredEncodingFixBit,
  kTECAddTextRunHeuristicsMask = 1L << kTECAddTextRunHeuristicsBit,
  kTECAddFallbackInterruptMask = 1L << kTECAddFallbackInterruptBit
};

enum
{
  kUnicodeByteOrderMark = 0xFEFF,
  kUnicodeObjectReplacement = 0xFFFC,
  kUnicodeReplacementChar = 0xFFFD,
  kUnicodeSwappedByteOrderMark = 0xFFFE,
  kUnicodeNotAChar = 0xFFFF
};

TextEncoding CreateTextEncoding(TextEncodingBase encodingBase, TextEncodingVariant encodingVariant, TextEncodingFormat encodingFormat);

#ifdef __cplusplus
}
#endif

#endif

