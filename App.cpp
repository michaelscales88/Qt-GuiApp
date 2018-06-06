#include <QApplication>
#include <QTextEdit>
#include <cstdlib>
#include <iostream>

#include "test.h"

int main(int argv, char **args) {
   QApplication app(argv, args);
   QTextEdit textEdit;

   textEdit.show();
   return app.exec();
}

