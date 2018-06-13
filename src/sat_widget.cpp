#include "sat_widget.h"

SatWidget::SatWidget(QWidget *parent)
          :QWidget(parent)
{
   QLabel *label = new QLabel(this);
   label->setText("Enter your SAT score:");
   QComboBox *combo = new QComboBox(this);
   QStringList list;
   for (int i = 0; i <= 2400; i++) list << QString::number(i);
   combo->addItems(list);
   combo->setCurrentIndex(1400);

   QHBoxLayout *layout = new QHBoxLayout();
   layout->addWidget(label);
   layout->addWidget(combo);
   setLayout(layout);
}

