/* Graphical User Interface Assignment Interface1 (I1)
 * Developer: Michael Scales
 */
#pragma once
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QSignalMapper>
#include <QLineEdit>

#include "base.h"

using namespace std;

class DollarsWidget: public Base
{
   Q_OBJECT

public:
   DollarsWidget( QWidget *parent = 0 );
   ~DollarsWidget() {}
   QHBoxLayout* getOutput();

private:
   QHBoxLayout* wigOutput;
};
