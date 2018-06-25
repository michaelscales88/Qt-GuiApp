/* Graphical User Interface Assignment Interface1 (I1)
 * Developer: Michael Scales
 */
#pragma once
#include <QtGui>

#include "base.h"

using namespace std;

class HobbiesWidget: public Base
{
   Q_OBJECT

public:
   HobbiesWidget( QWidget *parent = 0 );
   ~HobbiesWidget() {}
   QHBoxLayout* getOutput();

private slots:
   /* updateDisplay:
    *    Sets the display field to the selected value in the
    *    list.
    */
   void updateDisplay();

private:
   QHBoxLayout* wigOutput;
   void addItems(QListWidget* list);
   QListWidget* list;
   QLineEdit* display;
};
