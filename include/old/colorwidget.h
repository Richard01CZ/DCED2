#ifndef MY_COLORPICKER_H
#define MY_COLORPICKER_H

#include <qframe.h>
class QWidget;
class QPoint;
class QPainter;
class QMouseEvent;
class QPixmap;

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

#endif //MY_COLORPICKER_H