#include <QApplication>
#include <QTextEdit>
#include <cstdlib>
#include <iostream>

#include "test.h"

using namespace std;

int main(int argv, char **args) {
   QApplication app(argv, args);
   QTextEdit textEdit;
   cout << fnTest() << endl;
   textEdit.show();
   return app.exec();
}

