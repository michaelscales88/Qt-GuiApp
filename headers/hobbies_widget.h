#pragma once
#include <iostream>
#include <string>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QLabel>
#include <QString>
#include <QSignalMapper>
#include <QLineEdit>

#include "base.h"

using namespace std;

class HobbiesWidget: public Base
{
   Q_OBJECT

public:
   HobbiesWidget( QWidget *parent = 0 );
   ~HobbiesWidget() {}
   QHBoxLayout* getOutput();

private slots:
   /* Update the display field:
    *    Sets the display field to the selected value in the
    *    list.
    */
   void updateDisplay() {
      if (list->currentItem()) {
         const QString& value = list->currentItem()->text();
         display->setText(value);
      }
   }

private:
   QHBoxLayout* wigOutput;
   void addItems(QListWidget* list);
   QListWidget* list;
   QLineEdit* display;
};
