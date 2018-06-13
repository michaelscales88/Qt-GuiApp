#include "hobbies_widget.h"

HobbiesWidget::HobbiesWidget(QWidget *parent)
              :QWidget(parent)
{
   QVBoxLayout *layout = new QVBoxLayout;
   QLabel *label = new QLabel(this);
   QListWidget *list = new QListWidget(this);
   label->setText("Select your hobbies");
   layout->addWidget(label);
   layout->addWidget(list);
   setLayout(layout);
}

