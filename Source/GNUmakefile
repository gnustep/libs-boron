include $(GNUSTEP_MAKEFILES)/common.make
include ../Version

PACKAGE_NAME = gnustep-boron

LIBRARY_NAME = libgnustep-boron

ADDITIONAL_INCLUDE_DIRS = -I../Headers
ADDITIONAL_CFLAGS = -DBUILDING_SELF_BORON
ADDITIONAL_CXXFLAGS = -DBUILDING_SELF_BORON
ADDITIONAL_OBJCFLAGS = -DBUILDING_SELF_BORON

libgnustep-boron_INTERFACE_VERSION = $(MAJOR_VERSION)
libgnustep-boron_SUBPROJECTS = BoronTypes BoronCore

ifeq ($(GNUSTEP_TARGET_OS), mingw32)
  ADDITIONAL_LDFLAGS = -L/mingw/bin
endif

include $(GNUSTEP_MAKEFILES)/library.make

-include Makefile.postamble

