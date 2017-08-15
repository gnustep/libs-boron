enum {
  kUnicodeUseFallbacksBit = 0,
  kUnicodeKeepInfoBit = 1,
  kUnicodeDirectionalityBits = 2,
  kUnicodeVerticalFormBit = 4,
  kUnicodeLooseMappingsBit = 5,
  kUnicodeStringUnterminatedBit = 6,
  kUnicodeTextRunBit = 7,
  kUnicodeKeepSameEncodingBit = 8,
  kUnicodeForceASCIIRangeBit = 9,
  kUnicodeNoHalfwidthCharsBit = 10,
  kUnicodeTextRunHeuristicsBit = 11,
  kUnicodeMapLineFeedToReturnBit = 12,
  kUnicodeUseExternalEncodingFormBit = 13
};

enum {
  kUnicodeUseFallbacksMask = 1L << kUnicodeUseFallbacksBit,
  kUnicodeKeepInfoMask = 1L << kUnicodeKeepInfoBit,
  kUnicodeDirectionalityMask = 3L << kUnicodeDirectionalityBits,
  kUnicodeVerticalFormMask = 1L << kUnicodeVerticalFormBit,
  kUnicodeLooseMappingsMask = 1L << kUnicodeLooseMappingsBit,
  kUnicodeStringUnterminatedMask = 1L << kUnicodeStringUnterminatedBit,
  kUnicodeTextRunMask = 1L << kUnicodeTextRunBit,
  kUnicodeKeepSameEncodingMask = 1L << kUnicodeKeepSameEncodingBit,
  kUnicodeForceASCIIRangeMask = 1L << kUnicodeForceASCIIRangeBit,
  kUnicodeNoHalfwidthCharsMask = 1L << kUnicodeNoHalfwidthCharsBit,
  kUnicodeTextRunHeuristicsMask = 1L << kUnicodeTextRunHeuristicsBit,
  kUnicodeMapLineFeedToReturnMask = 1L << kUnicodeMapLineFeedToReturnBit,
  kUnicodeUseExternalEncodingFormMask = 1L << kUnicodeUseExternalEncodingFormBit
};

enum {
  kUnicodeDefaultDirection = 0,
  kUnicodeLeftToRight = 1,
  kUnicodeRightToLeft = 2
};

enum {
  kUnicodeDefaultDirectionMask = kUnicodeDefaultDirection << kUnicodeDirectionalityBits,
  kUnicodeLeftToRightMask = kUnicodeLeftToRight << kUnicodeDirectionalityBits,
  kUnicodeRightToLeftMask = kUnicodeRightToLeft << kUnicodeDirectionalityBits
};

enum {
  kUnicodeMatchUnicodeBaseBit = 0,
  kUnicodeMatchUnicodeVariantBit = 1,
  kUnicodeMatchUnicodeFormatBit = 2,
  kUnicodeMatchOtherBaseBit = 3,
  kUnicodeMatchOtherVariantBit = 4,
  kUnicodeMatchOtherFormatBit = 5
};

enum {
  kUnicodeMatchUnicodeBaseMask = 1L << kUnicodeMatchUnicodeBaseBit,
  kUnicodeMatchUnicodeVariantMask = 1L << kUnicodeMatchUnicodeVariantBit,
  kUnicodeMatchUnicodeFormatMask = 1L << kUnicodeMatchUnicodeFormatBit,
  kUnicodeMatchOtherBaseMask = 1L << kUnicodeMatchOtherBaseBit,
  kUnicodeMatchOtherVariantMask = 1L << kUnicodeMatchOtherVariantBit,
  kUnicodeMatchOtherFormatMask = 1L << kUnicodeMatchOtherFormatBit
};

enum {
  kUnicodeFallbackSequencingBits = 0
};

enum {
  kUnicodeFallbackSequencingMask = 3L << kUnicodeFallbackSequencingBits,
  kUnicodeFallbackInterruptSafeMask = 1L << 2
};

enum {
  kUnicodeFallbackDefaultOnly = 0,
  kUnicodeFallbackCustomOnly = 1,
  kUnicodeFallbackDefaultFirst = 2,
  kUnicodeFallbackCustomFirst = 3
};
