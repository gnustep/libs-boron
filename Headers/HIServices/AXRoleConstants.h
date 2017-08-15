/* AXRoleConstants.h

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

#ifndef __gnustep_boron_AXRoleConstants
#define __gnustep_boron_AXRoleConstants

#include <CoreFoundation/CFString.h>

#define kAXApplicationRole CFSTR("AXApplication")
#define kAXSystemWideRole CFSTR("AXSystemWide")
#define kAXWindowRole CFSTR("AXWindow")
#define kAXSheetRole CFSTR("AXSheet")
#define kAXDrawerRole CFSTR("AXDrawer")
#define kAXGrowAreaRole CFSTR("AXGrowArea")
#define kAXImageRole CFSTR("AXImage")
#define kAXUnknownRole CFSTR("AXUnknown")
#define kAXButtonRole CFSTR("AXButton")
#define kAXRadioButtonRole CFSTR("AXRadioButton")
#define kAXCheckBoxRole CFSTR("AXCheckBox")
#define kAXPopUpButtonRole CFSTR("AXPopUpButton")
#define kAXMenuButtonRole CFSTR("AXMenuButton")
#define kAXTabGroupRole CFSTR("AXTabGroup")
#define kAXTableRole CFSTR("AXTable")
#define kAXColumnRole CFSTR("AXColumn")
#define kAXRowRole CFSTR("AXRow")
#define kAXOutlineRole CFSTR("AXOutline")

#define kAXBrowserRole CFSTR("AXBrowser")
#define kAXScrollAreaRole CFSTR("AXScrollArea")
#define kAXScrollBarRole CFSTR("AXScrollBar")
#define kAXRadioGroupRole CFSTR("AXRadioGroup")
#define kAXListRole CFSTR("AXList")
#define kAXGroupRole CFSTR("AXGroup")
#define kAXValueIndicatorRole CFSTR("AXValueIndicator")
#define kAXComboBoxRole CFSTR("AXComboBox")
#define kAXSliderRole CFSTR("AXSlider")
#define kAXIncrementorRole CFSTR("AXIncrementor")
#define kAXBusyIndicatorRole CFSTR("AXBusyIndicator")
#define kAXProgressIndicatorRole CFSTR("AXProgressIndicator")
#define kAXRelevanceIndicatorRole CFSTR("AXRelevanceIndicator")
#define kAXToolbarRole CFSTR("AXToolbar")
#define kAXDisclosureTriangleRole CFSTR("AXDisclosureTriangle")


#define kAXTextFieldRole CFSTR("AXTextField")
#define	kAXTextAreaRole CFSTR("AXTextArea")
#define kAXStaticTextRole CFSTR("AXStaticText")

#define kAXMenuBarRole CFSTR("AXMenuBar")
#define kAXMenuBarItemRole CFSTR("AXMenuBarItem")
#define kAXMenuRole CFSTR("AXMenu")
#define kAXMenuItemRole CFSTR("AXMenuItem")

#define kAXSplitGroupRole CFSTR("AXSplitGroup")
#define kAXSplitterRole CFSTR("AXSplitter")
#define kAXColorWellRole CFSTR("AXColorWell")

#define kAXTimeFieldRole CFSTR("AXTimeField")
#define kAXDateFieldRole CFSTR("AXDateField")

#define kAXHelpTagRole CFSTR("AXHelpTag")

#define kAXMatteRole CFSTR("AXMatte")

#define kAXDockItemRole CFSTR("AXDockItem")

#define kAXRulerRole CFSTR("AXRuler")
#define kAXRulerMarkerRole CFSTR("AXRulerMarker")
#define kAXGridRole CFSTR("AXGrid")
#define kAXLevelIndicatorRole CFSTR("AXLevelIndicator")
#define kAXCellRole CFSTR("AXCell")

#define kAXLayoutAreaRole CFSTR("AXLayoutArea")
#define kAXLayoutItemRole CFSTR("AXLayoutItem")

#define kAXHandleRole CFSTR("AXHandle")
#define kAXPopoverRole CFSTR("AXPopover")

#define kAXCloseButtonSubrole CFSTR("AXCloseButton")
#define kAXMinimizeButtonSubrole CFSTR("AXMinimizeButton")
#define kAXZoomButtonSubrole CFSTR("AXZoomButton")
#define kAXToolbarButtonSubrole CFSTR("AXToolbarButton")
#define kAXFullScreenButtonSubrole CFSTR("AXFullScreenButton")
#define kAXSecureTextFieldSubrole CFSTR("AXSecureTextField")
#define kAXTableRowSubrole CFSTR("AXTableRow")
#define kAXOutlineRowSubrole CFSTR("AXOutlineRow")
#define kAXUnknownSubrole CFSTR("AXUnknown")

#define kAXStandardWindowSubrole CFSTR("AXStandardWindow")
#define kAXDialogSubrole CFSTR("AXDialog")
#define kAXSystemDialogSubrole CFSTR("AXSystemDialog")
#define kAXFloatingWindowSubrole CFSTR("AXFloatingWindow")
#define kAXSystemFloatingWindowSubrole CFSTR("AXSystemFloatingWindow")
#define kAXIncrementArrowSubrole CFSTR("AXIncrementArrow")
#define kAXDecrementArrowSubrole CFSTR("AXDecrementArrow")
#define kAXIncrementPageSubrole CFSTR("AXIncrementPage")
#define kAXDecrementPageSubrole CFSTR("AXDecrementPage")
#define kAXSortButtonSubrole CFSTR("AXSortButton")
#define kAXSearchFieldSubrole CFSTR("AXSearchField")
#define kAXTimelineSubrole CFSTR("AXTimeline")
#define kAXRatingIndicatorSubrole CFSTR("AXRatingIndicator")
#define kAXContentListSubrole CFSTR("AXContentList")
#define kAXDefinitionListSubrole CFSTR("AXDefinitionList")
#define kAXDescriptionListSubrole CFSTR("AXDescriptionList")
#define kAXToggleSubrole CFSTR("AXToggle")
#define kAXSwitchSubrole CFSTR("AXSwitch")

#define kAXApplicationDockItemSubrole CFSTR("AXApplicationDockItem")
#define kAXDocumentDockItemSubrole CFSTR("AXDocumentDockItem")
#define kAXFolderDockItemSubrole CFSTR("AXFolderDockItem")
#define kAXMinimizedWindowDockItemSubrole CFSTR("AXMinimizedWindowDockItem")
#define kAXURLDockItemSubrole CFSTR("AXURLDockItem")
#define kAXDockExtraDockItemSubrole CFSTR("AXDockExtraDockItem")
#define kAXTrashDockItemSubrole CFSTR("AXTrashDockItem")
#define kAXSeparatorDockItemSubrole CFSTR("AXSeparatorDockItem")
#define kAXProcessSwitcherListSubrole CFSTR("AXProcessSwitcherList")

#endif
