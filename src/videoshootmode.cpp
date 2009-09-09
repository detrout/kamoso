/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) <year>  <name of author>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "videoshootmode.h"
#include <QPushButton>
#include <KIcon>
#include <KLocalizedString>
#include "kamoso.h"
#include <QAction>

VideoShootMode::VideoShootMode(Kamoso* camera)
	: ShootMode(camera)
{
	QAction* sound=new QAction(KIcon("audio-input-microphone"), i18n("Record audio"), this);
	sound->setCheckable(true);
	sound->setChecked(true);
	
	mActions += sound;
}

QWidget* VideoShootMode::mainAction()
{
	QPushButton* action = new QPushButton(controller());
	action->setIcon(icon());
	action->setIconSize(QSize(32,32));
	action->setToolTip(name());
	action->setCheckable(true);
	
	#warning TODO
	connect(action, SIGNAL(clicked(bool)), this, SLOT(videoPressed(bool)));
	return action;
}

void VideoShootMode::videoPressed(bool pressed)
{
	if(pressed)
		controller()->startVideo(mActions.first()->isChecked());
	else
		controller()->stopVideo();
}

QIcon VideoShootMode::icon() const
{
	return KIcon("media-record");
}

QString VideoShootMode::name() const
{
	return i18n("Take a video");
}
