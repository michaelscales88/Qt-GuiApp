#include "gpa_widget.h"

GpaWidget::GpaWidget(QWidget *parent)
          :QWidget(parent)
{
   cout << "create gpa widget" << endl;
   setWindowTitle(tr("World Time Clock"));
   resize(200, 200);
}

GpaWidget::~GpaWidget() { cout << "destroyed gpa widget" << endl; }
