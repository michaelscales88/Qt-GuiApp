/* Graphical User Interface Assignment Interface1 (I1)
 * Developer: Michael Scales
 */
#pragma once
#include <QGroupBox>
#include <QWidget>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QSignalMapper>
#include <QButtonGroup>

#include "base.h"

using namespace std;

class StudentSelector: public Base
{
   Q_OBJECT

public:
   StudentSelector( QWidget *parent = 0 );
   ~StudentSelector() {}
   QHBoxLayout* getOutput();

private slots:
   void dataRequested(bool value) {
      if (value) {
         int id = btnGroup->checkedId();
         emit transmitData(id);
      }
   }

signals:
   void transmitData(int value);

private:
QHBoxLayout* wigOutput;
   QButtonGroup* btnGroup;
};
