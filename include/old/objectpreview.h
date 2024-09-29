/****************************************************************************
** Form interface generated from reading ui file 'objectpreview.ui'
**
** Created: Mi 21. Jan 23:24:50 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef OBJECTPREVIEW_H
#define OBJECTPREVIEW_H

#include <qvariant.h>
#include <qwidget.h>
#include "MLWrapper.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QPushButton;
class QGroupBox;
class QLabel;
class QFrame;

class ObjectPreview : public QWidget
{
    Q_OBJECT

public:
    ObjectPreview( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ObjectPreview();

	ObjectInfo_t * getInputFields();

    QPushButton* changeButton;
    QGroupBox* translationBox;
    QLabel* scalingTitleLabel;
    QLabel* rotationTitleLabel;
    QLabel* positionTitleLabel;
    QLabel* scalingValueLabel;
    QLabel* positionValueLabel;
    QLabel* rotationValueLabel;
    QLabel* extraValueLabel;
    QLabel* extraTitleLabel;
    QLabel* objectNameLabel;
    QGroupBox* additionalBox;
    QFrame* modelFrame;
    QLabel* modelValueLabel;
    QLabel* modelTitleLabel;
    QFrame* sectorFrame;
    QLabel* sectorTitleLabel;
    QLabel* sectorValueLabel;

public slots:
	void setInputFields( ObjectInfo_t * );
	void changeObject();

protected:
    QGridLayout* ObjectPreviewLayout;
    QHBoxLayout* layout1;
    QVBoxLayout* additionalBoxLayout;
	ObjectInfo_t * inputFields;

protected slots:
    virtual void languageChange();

signals:
	void editObject( ObjectInfo_t * );

};

#endif // OBJECTPREVIEW_H
