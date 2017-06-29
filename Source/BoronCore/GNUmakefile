include $(GNUSTEP_MAKEFILES)/common.make

PACKAGE_NAME = gnustep-boron
SUBPROJECT_NAME = BoronCore

ADDITIONAL_CCFLAGS = -std=c++11

$(SUBPROJECT_NAME)_C_FILES = \
  TextCommon.c

$(SUBPROJECT_NAME)_CC_FILES = \
  TextEncodingConverter.cpp

$(SUBPROJECT_NAME)_HEADER_FILES = \
  CarbonCore.h \
  MacErrors.h \
  TextCommon.h \
  TextEncodingConverter.h

$(SUBPROJECT_NAME)_INCLUDE_DIRS = -I../../Headers
$(SUBPROJECT_NAME)_HEADER_FILES_DIR = ../../Headers/CarbonCore
$(SUBPROJECT_NAME)_HEADER_FILES_INSTALL_DIR = CarbonCore

$(SUBPROJECT_NAME)_NEEDS_GUI = NO

include $(GNUSTEP_MAKEFILES)/subproject.make
-include Makefile.postamble
