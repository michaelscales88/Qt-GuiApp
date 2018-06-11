#include "gpa_widget.h"

string test() {
   return "test";
}

GpaWidget::GpaWidget() { cout << test() << endl; }

GpaWidget::~GpaWidget() { cout << "destroy" << endl; }

