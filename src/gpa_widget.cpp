/* Graphical User Interface Assignment Interface1 (I1)
 * Developer: Michael Scales
 */
#include "gpa_widget.h"

GpaWidget::GpaWidget(QWidget *parent)
          :Base(parent)
{
   // Configure view
   QLabel *label = new QLabel(this);
   label->setText("Select your GPA:");
   slider = new QSlider(this);
   slider->setRange(0, 500);
   slider->setOrientation(Qt::Horizontal); 
   spinner = new QDoubleSpinBox(this);
   spinner->setRange(0, 5.0);
   spinner->setSingleStep(0.01);
      QHBoxLayout *layout = new QHBoxLayout;
   layout->addWidget(label);
   layout->addWidget(spinner);
   layout->addWidget(slider);
   setLayout(layout);

   // Connect the spinbox and the slider so they
   // update one another to match.
   connect(
      slider, SIGNAL(valueChanged(int)),
      SLOT(ChangeSpinBox(int))
   );
   connect(
      spinner, SIGNAL(valueChanged(double)),
      SLOT(ChangeSlider(double))
   );

   // Configure the display area for the widget
   wigOutput = new QHBoxLayout;
   QLabel *displayLabel = new QLabel(tr("Your gpa:"));
   display = new QLineEdit;
   display->setReadOnly(true);

   // Set the display to update based on the input
   connect(
      spinner, SIGNAL(valueChanged(double)),
      this, SLOT(updateDisplay(double))
   );
   wigOutput->addWidget(displayLabel);
   wigOutput->addWidget(display);
   spinner->setValue(4.0);
}

QHBoxLayout* GpaWidget::getOutput() { return wigOutput; }

