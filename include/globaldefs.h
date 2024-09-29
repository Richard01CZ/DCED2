/*
 *	This file is part of DON|City Editor 2
 */

#pragma once

#ifndef GLOBALDEFS_H
#define GLOBALDEFS_H

#include <qcolor.h>
#include <qapplication.h>
#include <qsettings.h>
#include <qstatusbar.h>
#include "MLWrapper.h"
#include "mainwidget.h"

// Types
enum Type { Object, ObjDef, Init, All };

#define BOXLAYOUT_DEFAULT_MARGIN 11
#define BOXLAYOUT_DEFAULT_SPACING 6

#ifndef NO_STATIC_COLORS

static QColor *backColor1 = 0;
static QColor *backColor2 = 0;
static QColor *selectedBack = 0;

static void init_colors();

#endif //NO_STATIC_COLORS

struct charstruct
{
	char mychar[256];
};

extern CMLWrapper *sceneWrapper;
extern QSettings *settings;
extern QStatusBar *status_bar;
extern MainWidget *main_widget;

extern void init_settings();
extern void dcDebug( QString title, QString message );
extern short eType2sType( Type type );
extern Type sType2eType( short nDatablockType );

#endif //GLOBALDEFS_H
