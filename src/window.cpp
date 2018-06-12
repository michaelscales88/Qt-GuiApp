#include "window.h"

Window::Window(QWidget *parent)
       :QWidget(parent), layout(0), showWidgets(false)
{
   setLayout((layout = new FlowLayout));
   resize(400, 600);
}

Window::~Window() {}

void Window::addWidget(QWidget *item)
{
   if (!item) return;

   layout->addWidget(item);
   item->show();
}

