/*************************************************************************************
 *  Copyright (C) 2008-2009 by Aleix Pol <aleixpol@gmail.com>                        *
 *  Copyright (C) 2008-2009 by Alex Fiestas <alex@eyeos.org>                         *
 *                                                                                   *
 *  This program is free software; you can redistribute it and/or                    *
 *  modify it under the terms of the GNU General Public License                      *
 *  as published by the Free Software Foundation; either version 2                   *
 *  of the License, or (at your option) any later version.                           *
 *                                                                                   *
 *  This program is distributed in the hope that it will be useful,                  *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of                   *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                    *
 *  GNU General Public License for more details.                                     *
 *                                                                                   *
 *  You should have received a copy of the GNU General Public License                *
 *  along with this program; if not, write to the Free Software                      *
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA   *
 *************************************************************************************/

#include "kamosoplugin.h"
#include <KUrl>
#include "youtubemanager.h"
#include "src/plugins/youtube/ui_auth.h"
#include <kwallet.h>
#include <KIO/Job>

class YoutubePlugin : public KamosoPlugin
{
	Q_OBJECT
	Q_INTERFACES(KamosoPlugin)
	public:
		YoutubePlugin(QObject* parent, const QVariantList& args);
		virtual QAction* thumbnailsAction(const QList<KUrl>& url);
		bool showDialog();
		void showVideoDialog();
		bool askNewData();
		void login();
	public slots:
		void upload();
		void authenticated(bool);
		void uploadDone(bool);
		void loginDone(KIO::Job *job, const QByteArray &data);
	private:
		QList<KUrl> mSelectedUrls;
		YoutubeManager *m_manager;
		Ui::authWidget *m_auth;
		QWidget *m_authWidget;
		KWallet::Wallet *m_wallet;
		QString videoTitle;
		QString videoDesc;
		QString videoTags;
		QByteArray m_authToken;
};
