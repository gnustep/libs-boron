/* AXAttributeConstants.h

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

#ifndef __gnustep_boron_AXAttributeConstants
#define __gnustep_boron_AXAttributeConstants

#include <CoreFoundation/CFString.h>

#define kAXRoleAttribute CFSTR("AXRole")
#define kAXSubroleAttribute CFSTR("AXSubrole")
#define kAXRoleDescriptionAttribute CFSTR("AXRoleDescription")

#define kAXHelpAttribute CFSTR("AXHelp")

#define kAXTitleAttribute CFSTR("AXTitle")

#define kAXValueAttribute CFSTR("AXValue")
#define kAXValueDescriptionAttribute CFSTR("AXValueDescription")
#define kAXMinValueAttribute CFSTR("AXMinValue")
#define kAXMaxValueAttribute CFSTR("AXMaxValue")
#define kAXValueIncrementAttribute CFSTR("AXValueIncrement")
#define kAXAllowedValuesAttribute CFSTR("AXAllowedValues")
#define kAXPlaceholderValueAttribute CFSTR("AXPlaceholderValue")

#define kAXEnabledAttribute CFSTR("AXEnabled")

#define kAXElementBusyAttribute CFSTR("AXElementBusy")
#define kAXFocusedAttribute CFSTR("AXFocused")

#define kAXParentAttribute CFSTR("AXParent")
#define kAXChildrenAttribute CFSTR("AXChildren")
#define kAXSelectedChildrenAttribute CFSTR("AXSelectedChildren")
#define kAXVisibleChildrenAttribute CFSTR("AXVisibleChildren")

#define kAXWindowAttribute CFSTR("AXWindow")
#define kAXTopLevelUIElementAttribute CFSTR("AXTopLevelUIElement")

#define kAXPositionAttribute CFSTR("AXPosition")
#define kAXSizeAttribute CFSTR("AXSize")
#define kAXOrientationAttribute CFSTR("AXOrientation")

#define kAXDescriptionAttribute CFSTR("AXDescription")
#define kAXDescription CFSTR("AXDescription")

#define kAXSelectedTextAttribute CFSTR("AXSelectedText")
#define kAXSelectedTextRangeAttribute CFSTR("AXSelectedTextRange")
#define kAXSelectedTextRangesAttribute CFSTR("AXSelectedTextRanges")

#define kAXVisibleCharacterRangeAttribute CFSTR("AXVisibleCharacterRange")

#define kAXNumberOfCharactersAttribute CFSTR("AXNumberOfCharacters")

#define kAXSharedTextUIElementsAttribute CFSTR("AXSharedTextUIElements")
#define kAXSharedCharacterRangeAttribute CFSTR("AXSharedCharacterRange")
#define kAXSharedFocusElementsAttribute CFSTR("AXSharedFocusElements")

#define kAXInsertionPointLineNumberAttribute CFSTR("AXInsertionPointLineNumber")
#define kAXMainAttribute CFSTR("AXMain")
#define kAXMinimizedAttribute CFSTR("AXMinimized")
#define kAXCloseButtonAttribute CFSTR("AXCloseButton")
#define kAXZoomButtonAttribute CFSTR("AXZoomButton")
#define kAXMinimizeButtonAttribute CFSTR("AXMinimizeButton")
#define kAXToolbarButtonAttribute CFSTR("AXToolbarButton")
#define kAXFullScreenButtonAttribute CFSTR("AXFullScreenButton")
#define kAXProxyAttribute CFSTR("AXProxy")
#define kAXGrowAreaAttribute CFSTR("AXGrowArea")
#define kAXModalAttribute CFSTR("AXModal")
#define kAXDefaultButtonAttribute CFSTR("AXDefaultButton")
#define kAXCancelButtonAttribute CFSTR("AXCancelButton")

#define kAXMenuItemCmdCharAttribute CFSTR("AXMenuItemCmdChar")
#define kAXMenuItemCmdVirtualKeyAttribute CFSTR("AXMenuItemCmdVirtualKey")
#define kAXMenuItemCmdGlyphAttribute CFSTR("AXMenuItemCmdGlyph")
#define kAXMenuItemCmdModifiersAttribute CFSTR("AXMenuItemCmdModifiers")
#define kAXMenuItemMarkCharAttribute CFSTR("AXMenuItemMarkChar")
#define kAXMenuItemPrimaryUIElementAttribute CFSTR("AXMenuItemPrimaryUIElement")

typedef uint32_t AXMenuItemModifiers;
#define kAXMenuItemModifierNone 0
#define kAXMenuItemModifierShift (1 << 0)
#define kAXMenuItemModifierOption (1 << 1)
#define kAXMenuItemModifierControl (1 << 2)
#define kAXMenuItemModifierNoCommand (1 << 3)

#define kAXMenuBarAttribute CFSTR("AXMenuBar")
#define kAXWindowsAttribute CFSTR("AXWindows")
#define kAXFrontmostAttribute CFSTR("AXFrontmost")
#define kAXHiddenAttribute CFSTR("AXHidden")
#define kAXMainWindowAttribute CFSTR("AXMainWindow")
#define kAXFocusedWindowAttribute CFSTR("AXFocusedWindow")
#define kAXFocusedUIElementAttribute CFSTR("AXFocusedUIElement") 
#define kAXExtrasMenuBarAttribute CFSTR("AXExtrasMenuBar")

#define kAXHeaderAttribute CFSTR("AXHeader")
#define kAXEditedAttribute CFSTR("AXEdited")
#define kAXValueWrapsAttribute CFSTR("AXValueWraps")
#define kAXTabsAttribute CFSTR("AXTabs")
#define kAXTitleUIElementAttribute CFSTR("AXTitleUIElement")
#define kAXHorizontalScrollBarAttribute CFSTR("AXHorizontalScrollBar")
#define kAXVerticalScrollBarAttribute CFSTR("AXVerticalScrollBar")
#define kAXOverflowButtonAttribute CFSTR("AXOverflowButton")
#define kAXFilenameAttribute CFSTR("AXFilename")
#define kAXExpandedAttribute CFSTR("AXExpanded")
#define kAXSelectedAttribute CFSTR("AXSelected")
#define kAXSplittersAttribute CFSTR("AXSplitters")
#define kAXNextContentsAttribute CFSTR("AXNextContents")
#define kAXDocumentAttribute CFSTR("AXDocument")
#define kAXDecrementButtonAttribute CFSTR("AXDecrementButton")
#define kAXIncrementButtonAttribute CFSTR("AXIncrementButton")
#define kAXPreviousContentsAttribute CFSTR("AXPreviousContents")

#define kAXContentsAttribute CFSTR("AXContents")

#define kAXIncrementorAttribute CFSTR("AXIncrementor")

#define kAXHourFieldAttribute CFSTR("AXHourField")
#define kAXMinuteFieldAttribute CFSTR("AXMinuteField")
#define kAXSecondFieldAttribute CFSTR("AXSecondField")

#define kAXAMPMFieldAttribute CFSTR("AXAMPMField")

#define kAXDayFieldAttribute CFSTR("AXDayField")
#define kAXMonthFieldAttribute CFSTR("AXMonthField")
#define kAXYearFieldAttribute CFSTR("AXYearField")

#define kAXColumnTitleAttribute CFSTR("AXColumnTitles")

#define kAXURLAttribute CFSTR("AXURL")
#define kAXLabelUIElementsAttribute CFSTR("AXLabelUIElements")
#define kAXLabelValueAttribute CFSTR("AXLabelValue")
#define kAXShownMenuUIElementAttribute CFSTR("AXShownMenuUIElement")
#define kAXServesAsTitleForUIElementsAttribute CFSTR("AXServesAsTitleForUIElements")
#define kAXLinkedUIElementsAttribute CFSTR("AXLinkedUIElements")

#define kAXRowsAttribute CFSTR("AXRows")
#define kAXVisibleRowsAttribute CFSTR("AXVisibleRows")
#define kAXSelectedRowsAttribute CFSTR("AXSelectedRows")
#define kAXColumnsAttribute CFSTR("AXColumns")

#define kAXVisibleColumnsAttribute CFSTR("AXVisibleColumns")
#define kAXSelectedColumnsAttribute CFSTR("AXSelectedColumns")
#define kAXSortDirectionAttribute CFSTR("AXSortDirection")

#define kAXIndexAttribute CFSTR("AXIndex")

#define kAXDisclosingAttribute CFSTR("AXDisclosing")
#define kAXDisclosedRowsAttribute CFSTR("AXDisclosedRows")
#define kAXDisclosedByRowAttribute CFSTR("AXDisclosedByRow")
#define kAXDisclosureLevelAttribute CFSTR("AXDisclosureLevel")

#define kAXMatteHoleAttribute CFSTR("AXMatteHole")
#define kAXMatteContentUIElementAttribute CFSTR("AXMatteContentUIElement")

#define kAXMarkerUIElementsAttribute CFSTR("AXMarkerUIElements")
#define kAXUnitsAttribute CFSTR("AXUnits")
#define kAXUnitDescriptionAttribute CFSTR("AXUnitDescription")
#define kAXMarkerTypeAttribute CFSTR("AXMarkerType")
#define kAXMarkerTypeDescriptionAttribute CFSTR("AXMarkerTypeDescription")

#define kAXIsApplicationRunningAttribute CFSTR("AXIsApplicationRunning")

#define kAXSearchButtonAttribute CFSTR("AXSearchButton")
#define kAXClearButtonAttribute CFSTR("AXClearButton")

#define kAXFocusedApplicationAttribute CFSTR("AXFocusedApplication")

#define kAXRowCountAttribute CFSTR("AXRowCount")
#define kAXColumnCountAttribute CFSTR("AXColumnCount")
#define kAXOrderedByRowAttribute CFSTR("AXOrderedByRow")

#define kAXWarningValueAttribute CFSTR("AXWarningValue")
#define kAXCriticalValueAttribute CFSTR("AXCriticalValue")

#define kAXSelectedCellsAttribute CFSTR("AXSelectedCells")
#define kAXVisibleCellsAttribute CFSTR("AXVisibleCells")
#define kAXRowHeaderUIElementsAttribute CFSTR("AXRowHeaderUIElements")
#define kAXColumnHeaderUIElementsAttribute CFSTR("AXColumnHeaderUIElements")

#define kAXRowIndexRangeAttribute CFSTR("AXRowIndexRange")
#define kAXColumnIndexRangeAttribute CFSTR("AXColumnIndexRange")

#define kAXHorizontalUnitsAttribute CFSTR("AXHorizontalUnits")
#define kAXVerticalUnitsAttribute CFSTR("AXVerticalUnits")
#define kAXHorizontalUnitDescriptionAttribute CFSTR("AXHorizontalUnitDescription")
#define kAXVerticalUnitDescriptionAttribute CFSTR("AXVerticalUnitDescription")
#define kAXHandlesAttribute CFSTR("AXHandles")

#define kAXTextAttribute CFSTR("AXText")
#define kAXVisibleTextAttribute CFSTR("AXVisibleText")
#define kAXIsEditableAttribute CFSTR("AXIsEditable")
#define kAXColumnTitlesAttribute CFSTR("AXColumnTitles")

#define kAXIdentifierAttribute CFSTR("AXIdentifier")

#define kAXAlternateUIVisibleAttribute CFSTR("AXAlternateUIVisible")

#define kAXLineForIndexParameterizedAttribute CFSTR("AXLineForIndex")
#define kAXRangeForLineParameterizedAttribute CFSTR("AXRangeForLine")
#define kAXStringForRangeParameterizedAttribute CFSTR("AXStringForRange")
#define kAXRangeForPositionParameterizedAttribute CFSTR("AXRangeForPosition")
#define kAXRangeForIndexParameterizedAttribute CFSTR("AXRangeForIndex")
#define kAXBoundsForRangeParameterizedAttribute CFSTR("AXBoundsForRange")
#define kAXRTFForRangeParameterizedAttribute CFSTR("AXRTFForRange")
#define kAXAttributedStringForRangeParameterizedAttribute CFSTR("AXAttributedStringForRange")
#define kAXStyleRangeForIndexParameterizedAttribute CFSTR("AXStyleRangeForIndex")

#define kAXCellForColumnAndRowParameterizedAttribute CFSTR("AXCellForColumnAndRow")

#define kAXLayoutPointForScreenPointParameterizedAttribute CFSTR("AXLayoutPointForScreenPoint")
#define kAXLayoutSizeForScreenSizeParameterizedAttribute CFSTR("AXLayoutSizeForScreenSize")
#define kAXScreenPointForLayoutPointParameterizedAttribute CFSTR("AXScreenPointForLayoutPoint")
#define kAXScreenSizeForLayoutSizeParameterizedAttribute CFSTR("AXScreenSizeForLayoutSize")

#endif
