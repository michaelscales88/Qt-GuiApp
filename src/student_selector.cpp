#include "student_selector.h"

StudentSelector::StudentSelector(QWidget *parent)
                :QWidget(parent)
{
   // Create the GroupBox
   QGroupBox *groupBox = new QGroupBox(tr("Select student type"));
   QVBoxLayout *layout = new QVBoxLayout;
   QRadioButton *radio1 = new QRadioButton(tr("High School Student"));
   QRadioButton *radio2 = new QRadioButton(tr("Freshmen"));
   QRadioButton *radio3 = new QRadioButton(tr("Sophmore"));
   radio1->setChecked(true);
   layout->addWidget(radio1);
   layout->addWidget(radio2);
   layout->addWidget(radio3);
   layout->addStretch(1);
   groupBox->setLayout(layout);
   groupBox->show();

   // Add the GroupBox to the QWidget
   QHBoxLayout *wigLayout = new QHBoxLayout;
   wigLayout->addWidget(groupBox);
   setLayout(wigLayout);
}
