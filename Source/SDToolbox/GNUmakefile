include $(GNUSTEP_MAKEFILES)/common.make

PACKAGE_NAME = gnustep-boron
SUBPROJECT_NAME = SDToolbox

$(SUBPROJECT_NAME)_C_FILES = \
  KeyboardEvents.c

$(SUBPROJECT_NAME)_HEADER_FILES = \
  CarbonEventsCore.h \
  Events.h

$(SUBPROJECT_NAME)_INCLUDE_DIRS = -I../../Headers
$(SUBPROJECT_NAME)_HEADER_FILES_DIR = ../../Headers/HIToolbox
$(SUBPROJECT_NAME)_HEADER_FILES_INSTALL_DIR = HIToolbox

$(SUBPROJECT_NAME)_NEEDS_GUI = NO

include $(GNUSTEP_MAKEFILES)/subproject.make
-include Makefile.postamble
