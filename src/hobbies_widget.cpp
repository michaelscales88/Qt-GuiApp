#include "hobbies_widget.h"

HobbiesWidget::HobbiesWidget(QWidget *parent)
              :QWidget(parent)
{
   QVBoxLayout *layout = new QVBoxLayout;
   QLabel *label = new QLabel(this);
   QListWidget *list = new QListWidget(this);
   cout << "create hobbies widget" << endl;
   label->setText("Select your hobbies");
   layout->addWidget(label);
   layout->addWidget(list);
   setLayout(layout);
}

