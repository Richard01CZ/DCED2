/*
 *  --------------------Class ColorWidget------------------------
 *
 *	This is the color chooser from the right side of the QColorDialog.
 *  Most of the code is from the Trolls, so
 *  Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
 *  Have fun ;)
 */

#ifndef MY_COLORWIDGET_H
#define MY_COLORWIDGET_H

#include <qpainter.h>
#include <qlayout.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qdrawutil.h>
#include <qvalidator.h>
#include <qdragobject.h>
#include <qgridview.h>
#include <qapplication.h>
#include <qstyle.h>
#include <qsettings.h>
#include <qpopupmenu.h>

class QColorShowLabel;

class ColorPicker : public QFrame
{
    Q_OBJECT
public:
    ColorPicker(QWidget* parent=0, const char* name=0);
    ~ColorPicker();

public slots:
    void setCol( int h, int s );

signals:
    void newCol( int h, int s );

protected:
    QSize sizeHint() const;
    void drawContents(QPainter* p);
    void mouseMoveEvent( QMouseEvent * );
    void mousePressEvent( QMouseEvent * );

private:
    int hue;
    int sat;

    QPoint colPt();
    int huePt( const QPoint &pt );
    int satPt( const QPoint &pt );
    void setCol( const QPoint &pt );

    QPixmap *pix;
};

static int pWidth = 200;
static int pHeight = 200;

class ColorLuminancePicker : public QWidget
{
    Q_OBJECT
public:
    ColorLuminancePicker(QWidget* parent=0, const char* name=0);
    ~ColorLuminancePicker();

public slots:
    void setCol( int h, int s, int v );
    void setCol( int h, int s );

signals:
    void newHsv( int h, int s, int v );

protected:
    void paintEvent( QPaintEvent*);
    void mouseMoveEvent( QMouseEvent * );
    void mousePressEvent( QMouseEvent * );

private:
    enum { foff = 3, coff = 4 }; //frame and contents offset
    int val;
    int hue;
    int sat;

    int y2val( int y );
    int val2y( int val );
    void setVal( int v );

    QPixmap *pix;
};

class ColNumLineEdit : public QLineEdit
{
public:
    ColNumLineEdit( QWidget *parent, const char* name=0 )
	: QLineEdit( parent, name ) { setMaxLength( 3 );}
    QSize sizeHint() const {
	return QSize( fontMetrics().width( "999" ) + 2 * ( margin() + frameWidth() ),
		      QLineEdit::sizeHint().height() ); }
    void setNum( int i ) {
	QString s;
	s.setNum(i);
	bool block = signalsBlocked();
	blockSignals(TRUE);
	setText( s );
	blockSignals(block);
    }
    int val() const { return text().toInt(); }
};

class ColorShowLabel;

class ColorShower : public QWidget
{
    Q_OBJECT
public:
    ColorShower( QWidget *parent, const char *name=0 );

    //things that don't emit signals
    void setHsv( int h, int s, int v );

    int currentAlpha() const { return alphaEd->val(); }
    void setCurrentAlpha( int a ) { alphaEd->setNum( a ); }
    void showAlpha( bool b );


    QRgb currentColor() const { return curCol; }

public slots:
    void setRgb( QRgb rgb );

signals:
    void newCol( QRgb rgb );
private slots:
    void rgbEd();
    void hsvEd();
private:
    void showCurrentColor();
    int hue, sat, val;
    QRgb curCol;
    ColNumLineEdit *hEd;
    ColNumLineEdit *sEd;
    ColNumLineEdit *vEd;
    ColNumLineEdit *rEd;
    ColNumLineEdit *gEd;
    ColNumLineEdit *bEd;
    ColNumLineEdit *alphaEd;
    QLabel *alphaLab;
    ColorShowLabel *lab;
    bool rgbOriginal;
};

class ColorShowLabel : public QFrame
{
    Q_OBJECT

public:
    ColorShowLabel( QWidget *parent ) : QFrame( parent, "qt_colorshow_lbl" ) {
	setFrameStyle( QFrame::Panel|QFrame::Sunken );
	setBackgroundMode( PaletteBackground );
	setAcceptDrops( TRUE );
	mousePressed = FALSE;
    }
    void setColor( QColor c ) { col = c; }

signals:
    void colorDropped( QRgb );

protected:
    void drawContents( QPainter *p );
    void mousePressEvent( QMouseEvent *e );
    void mouseMoveEvent( QMouseEvent *e );
    void mouseReleaseEvent( QMouseEvent *e );
#ifndef QT_NO_DRAGANDDROP
    void dragEnterEvent( QDragEnterEvent *e );
    void dragLeaveEvent( QDragLeaveEvent *e );
    void dropEvent( QDropEvent *e );
#endif

private:
    QColor col;
    bool mousePressed;
    QPoint pressPos;

};

class ColorWidget : public QObject
{
	Q_OBJECT
public:
    ColorWidget( QWidget *p );
    QRgb currentColor() const { return cs->currentColor(); }
    void setCurrentColor( QRgb rgb );

    int currentAlpha() const { return cs->currentAlpha(); }
    void setCurrentAlpha( int a ) { cs->setCurrentAlpha( a ); }
    void showAlpha( bool b ) { cs->showAlpha( b ); }

public slots:
    void newHsv( int h, int s, int v );
    void newColorTypedIn( QRgb rgb );

public:
    ColorPicker *cp;
    ColorLuminancePicker *lp;
    ColorShower *cs;
    int nextCust;

signals:
	void colorChanged( QColor color );
};

#endif MY_COLORWIDGET_H