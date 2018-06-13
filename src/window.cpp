#include "window.h"

Window::Window(QWidget *parent)
       :QWidget(parent), showWidgets(false)
{
   QVBoxLayout *mainLayout = new QVBoxLayout;
   wLayout = new FlowLayout;
   hLayout = new QHBoxLayout;
   mainLayout->addLayout(wLayout);
   mainLayout->addLayout(hLayout);
   setLayout(mainLayout);
   resize(400, 600);
}

void Window::addWidget(QWidget *item)
{
   if (!item) return;

   wLayout->addWidget(item);
   item->show();
}

void Window::initView()
{
   QPushButton *quitBtn = new QPushButton(tr("Exit"));
   hLayout->addWidget(new QPushButton(tr("Submit")));
   hLayout->addWidget(quitBtn);
   connect(
      quitBtn, SIGNAL(clicked()),
      this, SLOT(close())
   );
   show();
}
