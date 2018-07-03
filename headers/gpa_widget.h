/* Graphical User Interface Assignment Interface3 (I3)
 * Developer: Michael Scales
 */
#pragma once
#include <QtGui>

#include <math.h>
#include <base.h>

using namespace std;

class GpaWidget : public Base
{
  Q_OBJECT

public:
  GpaWidget(QWidget *parent = 0);
  ~GpaWidget() {}

  /* getOutput:
    *   Return a QHBoxLayout with a output label and output
    *   display for the widget.
    */
  QHBoxLayout *getOutput();

private slots:
  /* changeSpinBox:
    *    Fn transforms between double and int. Uses a factor
    *    of 100 in order to cover 100s precision. E.g. 4.00
    */
  void changeSpinBox(int sliderValue);

  /* changeSlider:
    *    Fn transforms the double back into an integer
    *    between 0 - 500. The range covers 0.00 - 5.00.
    */
  void changeSlider(double spinBoxValue);

  /* updateDisplay:
    *    Sets the display to the value of the spinner.
    */
  void updateDisplay(double value);

private:
  QSlider *slider;
  QDoubleSpinBox *spinner;
  QHBoxLayout *wigOutput;
  QLineEdit *display;

  /* convertSpinBoxValueToSlider:
    *    Convert the double back into an int for the slider.
    */
  static int convertSpinBoxValueToSlider(double value)
  {
    return qRound(value * 100);
  }
};
