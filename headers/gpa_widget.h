/* Graphical User Interface Assignment Interface1 (I1)
 * Developer: Michael Scales
 */
#pragma once
#include <QWidget>
#include <QHBoxLayout>
#include <QDoubleSpinBox>
#include <QSlider>
#include <QLabel>
#include <QSignalMapper>
#include <QLineEdit>
#include <QVariant>
#include <QString>

#include <math.h>
#include <base.h>

using namespace std;


class GpaWidget: public Base
{
   Q_OBJECT

public:
   GpaWidget( QWidget *parent = 0 );
   ~GpaWidget() {}
   QHBoxLayout* getOutput();

private slots:
   /* Update the spinbox:
    *    Fn transforms between double and int. Uses a factor
    *    of 100 in order to cover 100s precision. E.g. 4.00
    */
   void ChangeSpinBox(int sliderValue) {
      if (convertSpinBoxValueToSlider(slider->value()) != sliderValue) {
         spinner->setValue((double)sliderValue / 100);
      }
   }

   /* Update the slider:
    *    Fn transforms the double back into an integer
    *    between 0 - 500. The range covers 0.00 - 5.00.
    */
   void ChangeSlider(double spinBoxValue) {
      slider->setValue(convertSpinBoxValueToSlider(spinBoxValue));
   }

   /* Update the display:
    *    Sets the display to the value of the spinner.
    */
   void updateDisplay(double value) {
      display->setText(QString("%1").arg(value));
   }

private:
   QSlider *slider;
   QDoubleSpinBox *spinner;
   QHBoxLayout* wigOutput;
   QLineEdit* display;

   /* Transform doubles:
    *    Convert the double back into an int for the slider.
    */ 
   static int convertSpinBoxValueToSlider(double value) {
      return qRound(value * 100);
   }
};

