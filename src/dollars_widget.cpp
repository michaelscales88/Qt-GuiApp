#include "dollars_widget.h"

DollarsWidget::DollarsWidget(QWidget *parent)
              :QWidget(parent)
{
   QLabel *label = new QLabel;
   label->setText("Enter your available funds");

   QHBoxLayout *layout = new QHBoxLayout;
   layout->addWidget(label);
   setLayout(layout);
}

