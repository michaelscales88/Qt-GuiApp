#include <QApplication>
#include <QTextEdit>
#include <cstdlib>
#include <iostream>

#include "test.h"

using namespace std;

#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

#include "test.h"

using namespace std;

int main(int argc, char *argv[]) {
   QApplication app(argc, argv);
   QWidget *window = new QWidget;
   window->setWindowTitle("Enter Your Age");
   QSpinBox *spinBox = new QSpinBox;
   QSlider *slider = new QSlider(Qt::Vertical);
   spinBox->setRange(0, 130);
   slider->setRange(0, 130);
   QObject::connect(spinBox, SIGNAL(valueChanged(int)),
   slider, SLOT(setValue(int)));
   QObject::connect(slider, SIGNAL(valueChanged(int)),
   spinBox, SLOT(setValue(int)));
   spinBox->setValue(35);
   QHBoxLayout *layout = new QHBoxLayout;
   layout->addWidget(spinBox);
   layout->addWidget(slider);
   window->setLayout(layout);
   cout << fnTest() << endl;
   window->show();
   return app.exec();
}
