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
   hLayout->addWidget(new QPushButton(tr("Submit")));
   hLayout->addWidget(new QPushButton(tr("Exit")));
   show();
}
