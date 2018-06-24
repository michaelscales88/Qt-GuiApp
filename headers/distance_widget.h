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
      viewDisplay->setText(QString::number(value));
      outputDisplay->setText(QString::number(value));
   }

private:
   QHBoxLayout* wigOutput;
   QLineEdit* viewDisplay;
   QLineEdit* outputDisplay;
};
