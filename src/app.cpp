#include <QApplication>
#include <QStyle>
#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>

#include "dollars_widget.h"
#include "gpa_widget.h"
#include "hobbies_widget.h"
#include "sat_widget.h"
#include "window.h"

using namespace std;

/*
 * Input widget -> take input/display selection
 * Output widget -> display static data for each area
 * */

int main(int argc, char *argv[]) {
   QApplication app(argc, argv);
   Window window;
   window.setWindowTitle("Informed Decision");
   window.addWidget(new GpaWidget);
   /*layout->addWidget(gpaWidget);
   gpaWidget->show();
   DollarsWidget dollarWidget = DollarsWidget();
   SatWidget satWidget = SatWidget();
   HobbiesWidget hobbiesWidget = HobbiesWidget();*/
   window.show();
   return app.exec();
}
