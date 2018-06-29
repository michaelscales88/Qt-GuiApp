/* Graphical User Interface Assignment Interface3 (I3)
 * Developer: Michael Scales
 */
#pragma once
#include <QtGui>

#include "base.h"

using namespace std;

class DistanceWidget : public Base
{
  Q_OBJECT

public:
  DistanceWidget(QWidget *parent = 0);
  ~DistanceWidget() {}

  /* getOutput:
    *   Return a QHBoxLayout with a output label and output
    *   display for the widget.
    */
  QHBoxLayout *getOutput();

private slots:
  /* updateDisplay:
    *   Takes an integer signal and determines the range.
    *   Updates the display label and the output label.
    */
  void updateDisplay(int value);

private:
  QHBoxLayout *wigOutput;
  QLineEdit *viewDisplay;
  QLineEdit *outputDisplay;
};
