/* Graphical User Interface Assignment Interface1 (I1)
 * Developer: Michael Scales
 */
#pragma once
#include <QtGui>

#include "base.h"

using namespace std;

class StudentSelector : public Base
{
  Q_OBJECT

public:
  StudentSelector(QWidget *parent = 0);
  ~StudentSelector() {}

  /* getOutput:
    *   Return a QHBoxLayout with a output label and output
    *   display for the widget.
    */
  QHBoxLayout *getOutput();

private slots:
  /* dataRequested:
    *   Let the output area output area tell the widget
    *   that it wants the current selected value.
    */
  void dataRequested(bool value);

signals:
  /* transmitData:
    *   Signal the data from the widget.
    */
  void transmitData(int value);

private:
  QHBoxLayout *wigOutput;
  QButtonGroup *btnGroup;
};
