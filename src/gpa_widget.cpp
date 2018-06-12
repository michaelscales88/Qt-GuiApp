#include "gpa_widget.h"

GpaWidget::GpaWidget(QWidget *parent)
          :QWidget(parent)
{
   QLabel *label = new QLabel(this);
   label->setText("Select your GPA:");
   slider = new QSlider(this);
   slider->setRange(0, 500);
   slider->setOrientation(Qt::Horizontal);
   connect(
      slider, SIGNAL(valueChanged(int)),
      SLOT(ChangeSpinBox(int))
   );

   spinner = new QDoubleSpinBox(this);
   spinner->setRange(0, 5.0);
   spinner->setSingleStep(0.01);
   connect(
      spinner, SIGNAL(valueChanged(double)),
      SLOT(ChangeSlider(double))
   );
   spinner->setValue(4.0);
   QHBoxLayout *layout = new QHBoxLayout;
   layout->addWidget(label);
   layout->addWidget(spinner);
   layout->addWidget(slider);
   setLayout(layout);
}

GpaWidget::~GpaWidget() {}

