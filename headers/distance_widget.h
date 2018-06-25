/* Graphical User Interface Assignment Interface1 (I1)
 * Developer: Michael Scales
 */
#pragma once
#include <QtGui>

#include "base.h"

using namespace std;

class DistanceWidget: public Base
{
   Q_OBJECT

public:
   DistanceWidget( QWidget *parent = 0 );
   ~DistanceWidget() {}
   QHBoxLayout* getOutput();

private slots:
   /* 
    *
    */
   void updateDisplay(int value) {
        QString text; 
        if (value < 1) text = QString("< 1 mi");
        else if (value > 10000) text = QString("> 10,0000 mi");
        else text = QString("%1 mi").arg(value);
        viewDisplay->setText(text);
        outputDisplay->setText(text);
   }

private:
   QHBoxLayout* wigOutput;
   QLineEdit* viewDisplay;
   QLineEdit* outputDisplay;
};
