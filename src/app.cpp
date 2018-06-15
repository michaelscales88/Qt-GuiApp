#include <QApplication>

#include "dollars_widget.h"
#include "gpa_widget.h"
#include "hobbies_widget.h"
#include "output_widget.h"
#include "sat_widget.h"
#include "student_selector.h"
#include "window.h"

using namespace std;

int main(int argc, char *argv[]) {
   QApplication app(argc, argv);
   Window window;
   window.setWindowTitle("Informed Decision");
   OutputWidget* output = new OutputWidget();
   StudentSelector* studentType = new StudentSelector();
   window.setOutput(output);
   window.addWidget(studentType);
   output->linkResults(studentType);
   window.addWidget(new GpaWidget);
   window.addWidget(new SatWidget);
   window.addWidget(new DollarsWidget);
   window.addWidget(new HobbiesWidget);
   window.initView();
   return app.exec();
}
