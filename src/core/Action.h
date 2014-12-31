/**************************************************************************
* Otter Browser: Web browser controlled by the user, not vice-versa.
* Copyright (C) 2013 - 2014 Michal Dutkiewicz aka Emdek <michal@emdek.pl>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
**************************************************************************/

#ifndef OTTER_ACTION_H
#define OTTER_ACTION_H

#include <QtWidgets/QAction>

namespace Otter
{

class Action : public QAction
{
	Q_OBJECT
	Q_ENUMS(ActionIdentifier)

public:
	enum ActionIdentifier
	{
		NewTabAction = 0,
		NewTabPrivateAction,
		NewWindowAction,
		NewWindowPrivateAction,
		OpenAction,
		SaveAction,
		CloneTabAction,
		CloseTabAction,
		ReopenTabAction,
		CloseWindowAction,
		SessionsAction,
		SaveSessionAction,
		OpenLinkAction,
		OpenLinkInCurrentTabAction,
		OpenLinkInNewTabAction,
		OpenLinkInNewTabBackgroundAction,
		OpenLinkInNewWindowAction,
		OpenLinkInNewWindowBackgroundAction,
		CopyLinkToClipboardAction,
		BookmarkLinkAction,
		SaveLinkToDiskAction,
		SaveLinkToDownloadsAction,
		OpenSelectionAsLinkAction,
		OpenFrameInCurrentTabAction,
		OpenFrameInNewTabAction,
		OpenFrameInNewTabBackgroundAction,
		CopyFrameLinkToClipboardAction,
		ReloadFrameAction,
		ViewFrameSourceAction,
		OpenImageInNewTabAction,
		SaveImageToDiskAction,
		CopyImageToClipboardAction,
		CopyImageUrlToClipboardAction,
		ReloadImageAction,
		ImagePropertiesAction,
		SaveMediaToDiskAction,
		CopyMediaUrlToClipboardAction,
		ToggleMediaControlsAction,
		ToggleMediaLoopAction,
		ToggleMediaPlayPauseAction,
		ToggleMediaMuteAction,
		GoAction,
		GoBackAction,
		GoForwardAction,
		GoToPageAction,
		GoToHomePageAction,
		GoToParentDirectoryAction,
		RewindAction,
		FastForwardAction,
		StopAction,
		StopScheduledReloadAction,
		ReloadAction,
		ReloadOrStopAction,
		ReloadAndBypassCacheAction,
		ScheduleReloadAction,
		UndoAction,
		RedoAction,
		CutAction,
		CopyAction,
		CopyPlainTextAction,
		CopyAddressAction,
		PasteAction,
		PasteAndGoAction,
		DeleteAction,
		SelectAllAction,
		ClearAllAction,
		CheckSpellingAction,
		FindAction,
		FindNextAction,
		FindPreviousAction,
		QuickFindAction,
		SearchAction,
		SearchMenuAction,
		CreateSearchAction,
		ZoomInAction,
		ZoomOutAction,
		ZoomOriginalAction,
		ScrollToStartAction,
		ScrollToEndAction,
		ScrollPageUpAction,
		ScrollPageDownAction,
		ScrollPageLeftAction,
		ScrollPageRightAction,
		PrintAction,
		PrintPreviewAction,
		ActivateAddressFieldAction,
		ActivateSearchFieldAction,
		ActivateContentAction,
		ActivateTabOnLeftAction,
		ActivateTabOnRightAction,
		BookmarksAction,
		AddBookmarkAction,
		QuickBookmarkAccessAction,
		PopupsPolicyAction,
		ImagesPolicyAction,
		CookiesAction,
		CookiesPolicyAction,
		ThirdPartyCookiesPolicyAction,
		PluginsPolicyAction,
		LoadPluginsAction,
		EnableJavaScriptAction,
		EnableJavaAction,
		EnableReferrerAction,
		ProxyMenuAction,
		EnableProxyAction,
		ViewSourceAction,
		ValidateAction,
		InspectPageAction,
		InspectElementAction,
		WorkOfflineAction,
		FullScreenAction,
		ShowMenuBarAction,
		ShowSidebarAction,
		ShowErrorConsoleAction,
		LockToolBarsAction,
		ContentBlockingAction,
		HistoryAction,
		ClearHistoryAction,
		TransfersAction,
		PreferencesAction,
		WebsitePreferencesAction,
		QuickPreferencesAction,
		ResetQuickPreferencesAction,
		SwitchApplicationLanguageAction,
		AboutApplicationAction,
		AboutQtAction,
		ExitAction,
		OtherAction
	};

	explicit Action(int identifier, QObject *parent = NULL);

	void setOverrideText(const QString &text);
	QList<QKeySequence> getShortcuts() const;
	int getIdentifier() const;
	bool event(QEvent *event);
	static bool isLocal(int identifier);

public slots:
	void setup(Action *action = NULL);

protected:
	void update(bool reset = false);

private:
	QString m_overrideText;
	int m_identifier;
	bool m_isOverridingText;
};

}

#endif
