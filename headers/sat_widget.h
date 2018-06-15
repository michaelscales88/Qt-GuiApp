/* Graphical User Interface Assignment Interface1 (I1)
 * Developer: Michael Scales
 */
#pragma once
#include <iostream>
#include <string>
#include <QWidget>
#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QStringList>
#include <QString>
#include <QSignalMapper>
#include <QLineEdit>

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
