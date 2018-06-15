/* Graphical User Interface Assignment Interface1 (I1)
 * Developer: Michael Scales
 */
#include "window.h"

Window::Window(QWidget *parent)
       :QWidget(parent)
{
   QVBoxLayout *mainLayout = new QVBoxLayout;
   wLayout = new FlowLayout;
   rLayout = new QHBoxLayout;
   hLayout = new QHBoxLayout;
   QSpacerItem* verticalSpacer = new QSpacerItem(
      10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding
   );
   mainLayout->addLayout(wLayout);  // widgets layout
   mainLayout->addSpacerItem(verticalSpacer);
   mainLayout->addLayout(rLayout);  // result area layout
   mainLayout->addLayout(hLayout);  // buttons layout
   setLayout(mainLayout);
   resize(600, 600);
}

void Window::addWidget(Base *item)
{
   if (!item) return;

   wLayout->addWidget(item);
   outputWidget->addOutput(item->getOutput());
   item->show();
}

void Window::setOutput(OutputWidget *item)
{
   if (!item) return;

   rLayout->addWidget((outputWidget = item));
   outputWidget->show();
}

void Window::initView()
{
   QPushButton *submitBtn = new QPushButton(tr("Submit"));
   QPushButton *quitBtn = new QPushButton(tr("Exit"));
   hLayout->addWidget(submitBtn);
   hLayout->addWidget(quitBtn);
   connect(
      submitBtn, SIGNAL(clicked()),
      outputWidget, SLOT(submitForm())
   );
   connect(
      quitBtn, SIGNAL(clicked()),
      this, SLOT(close())
   );

   show();
}
