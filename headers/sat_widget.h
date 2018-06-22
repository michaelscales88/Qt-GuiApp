/* Graphical User Interface Assignment Interface1 (I1)
 * Developer: Michael Scales
 */
#pragma once
#include <QtGui>

#include "base.h"

using namespace std;

class SatWidget: public Base
{
   Q_OBJECT

public:
   SatWidget( QWidget *parent = 0 );
   ~SatWidget() {}
   QHBoxLayout* getOutput();

private slots:
   /* 
    *
    */
   void updateDisplay(int value) {
      display->setText(QString::number(value));
   }

private:
   QHBoxLayout* wigOutput;
   void addItems(QComboBox* combo);
   QLineEdit* display;
};
