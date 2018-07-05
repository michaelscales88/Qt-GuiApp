/* Graphical User Interface Assignment Interface4 (I4)
 * Developer: Michael Scales
 */
#pragma once
#include <QtGui>

#include "base.h"

using namespace std;

class HobbiesWidget : public Base
{
  Q_OBJECT

public:
  HobbiesWidget(QWidget *parent = 0);
  ~HobbiesWidget() {}
  QHBoxLayout *getOutput();

private slots:
  /* updateDisplay:
    *    Sets the display field to the selected value in the
    *    list.
    */
  void updateDisplay();

private:
  QHBoxLayout *wigOutput;
  QListWidget *list;
  QLineEdit *display;
  
  /* addItems:
    *    Add a list of hobbies to the widget.
    */
  void addItems(QListWidget *list);
};
