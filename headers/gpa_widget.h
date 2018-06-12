#pragma once
#include <iostream>
#include <string>
#include <QWidget>
#include <QHBoxLayout>
#include <QDoubleSpinBox>
#include <QSlider>
#include <QLabel>

#include <math.h>

using namespace std;


class GpaWidget: public QWidget
{
   Q_OBJECT

public:
   GpaWidget( QWidget *parent = 0 );
   ~GpaWidget();

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

private:
   QSlider *slider;
   QDoubleSpinBox *spinner;

   /* Transform doubles:
    *    Convert the double back into an int for the slider.
    */ 
   static int convertSpinBoxValueToSlider(double value) {
      return qRound(value * 100);
   }
};

