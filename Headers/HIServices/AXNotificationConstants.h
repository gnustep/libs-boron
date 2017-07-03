/* AXNotificationConstants.h

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

#ifndef __gnustep_boron_AXNotificationConstants
#define __gnustep_boron_AXNotificationConstants

#include <CoreFoundation/CFString.h>

#define kAXMainWindowChangedNotification CFSTR("AXMainWindowChanged")
#define kAXFocusedWindowChangedNotification CFSTR("AXFocusedWindowChanged")
#define kAXFocusedUIElementChangedNotification CFSTR("AXFocusedUIElementChanged")
#define kAXApplicationActivatedNotification CFSTR("AXApplicationActivated")
#define kAXApplicationDeactivatedNotification CFSTR("AXApplicationDeactivated")
#define kAXApplicationHiddenNotification CFSTR("AXApplicationHidden")
#define kAXApplicationShownNotification CFSTR("AXApplicationShown")
#define kAXWindowCreatedNotification CFSTR("AXWindowCreated")
#define kAXWindowMovedNotification CFSTR("AXWindowMoved")
#define kAXWindowResizedNotification CFSTR("AXWindowResized")
#define kAXWindowMiniaturizedNotification CFSTR("AXWindowMiniaturized")
#define kAXWindowDeminiaturizedNotification CFSTR("AXWindowDeminiaturized")
#define kAXDrawerCreatedNotification CFSTR("AXDrawerCreated")
#define kAXSheetCreatedNotification CFSTR("AXSheetCreated")
#define kAXHelpTagCreatedNotification CFSTR("AXHelpTagCreated")
#define kAXValueChangedNotification CFSTR("AXValueChanged")
#define kAXUIElementDestroyedNotification CFSTR("AXUIElementDestroyed")
#define kAXElementBusyChangedNotification CFSTR("AXElementBusyChanged")
#define kAXMenuOpenedNotification CFSTR("AXMenuOpened")
#define kAXMenuClosedNotification CFSTR("AXMenuClosed")
#define kAXMenuItemSelectedNotification CFSTR("AXMenuItemSelected")
#define kAXRowCountChangedNotification CFSTR("AXRowCountChanged")
#define kAXRowExpandedNotification CFSTR("AXRowExpanded")
#define kAXRowCollapsedNotification CFSTR("AXRowCollapsed")
#define kAXSelectedCellsChangedNotification CFSTR("AXSelectedCellsChanged")
#define kAXUnitsChangedNotification CFSTR("AXUnitsChanged")  
#define kAXSelectedChildrenMovedNotification CFSTR("AXSelectedChildrenMoved")
#define kAXSelectedChildrenChangedNotification CFSTR("AXSelectedChildrenChanged")
#define kAXResizedNotification CFSTR("AXResized")
#define kAXMovedNotification CFSTR("AXMoved")
#define kAXCreatedNotification CFSTR("AXCreated")
#define kAXSelectedRowsChangedNotification CFSTR("AXSelectedRowsChanged")
#define kAXSelectedColumnsChangedNotification CFSTR("AXSelectedColumnsChanged")
#define kAXSelectedTextChangedNotification CFSTR("AXSelectedTextChanged")
#define kAXTitleChangedNotification CFSTR("AXTitleChanged")
#define kAXLayoutChangedNotification CFSTR("AXLayoutChanged")
#define kAXAnnouncementRequestedNotification CFSTR("AXAnnouncementRequested")
#define kAXUIElementsKey CFSTR("AXUIElementsKey")
#define kAXPriorityKey CFSTR("AXPriorityKey")
#define kAXAnnouncementKey CFSTR("AXAnnouncementKey")

typedef CFIndex AXPriority;
#define kAXPriorityLow 10
#define kAXPriorityMedium 50
#define kAXPriorityHigh 90

#endif
