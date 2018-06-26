/* Graphical User Interface Assignment Interface1 (I2)
 * Developer: Michael Scales
 */
#pragma once
#include <QtGui>

#include "base.h"

using namespace std;

class SatWidget : public Base
{
  Q_OBJECT

public:
  SatWidget(QWidget *parent = 0);
  ~SatWidget() {}
  
  /* getOutput:
    *   Return a QHBoxLayout with a output label and output
    *   display for the widget.
    */
  QHBoxLayout *getOutput();

private slots:
  /* updateDisplay:
    *   Set the widgets output display based on the users 
    *   selected SAT value.
    */
  void updateDisplay(int value);

private:
  QHBoxLayout *wigOutput;
  QLineEdit *display;

  /* addItems:
    *   Set the combo box items to contain values between
    *   0 - 2400 to represent the SAT score.
    */
  void addItems(QComboBox *combo);
};
