include $(GNUSTEP_MAKEFILES)/common.make

PACKAGE_NAME = gnustep-boron
SUBPROJECT_NAME = SDServices

$(SUBPROJECT_NAME)_C_FILES = \
  UniversalAccess.c

$(SUBPROJECT_NAME)_HEADER_FILES = \
  HIServices.h \
  Accessibility.h \
  AXError.h \
  AXConstants.h \
  AXActionConstants.h \
  AXAttributeConstants.h \
  AXNotificationConstants.h \
  AXRoleConstants.h \
  AXValueConstants.h \
  AXUIElement.h \
  UniversalAccess.h

$(SUBPROJECT_NAME)_INCLUDE_DIRS = -I../../Headers
$(SUBPROJECT_NAME)_HEADER_FILES_DIR = ../../Headers/HIServices
$(SUBPROJECT_NAME)_HEADER_FILES_INSTALL_DIR = HIServices

$(SUBPROJECT_NAME)_NEEDS_GUI = NO

include $(GNUSTEP_MAKEFILES)/subproject.make
-include Makefile.postamble
