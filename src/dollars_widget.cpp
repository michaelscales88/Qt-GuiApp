#include "dollars_widget.h"

DollarsWidget::DollarsWidget(QWidget *parent)
              :QWidget(parent)
{
   QLabel *label = new QLabel;
   QLineEdit *input = new QLineEdit;
   input->setText("Enter your funds...");
   label->setText("Enter your available funds");

   QHBoxLayout *layout = new QHBoxLayout;
   layout->addWidget(label);
   layout->addWidget(input);
   setLayout(layout);
}

