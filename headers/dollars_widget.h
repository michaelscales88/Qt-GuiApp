/* Graphical User Interface Assignment Interface1 (I2)
 * Developer: Michael Scales
 */
#pragma once
#include <QtGui>

#include "base.h"

using namespace std;

class DollarsWidget : public Base
{
    Q_OBJECT

  public:
    DollarsWidget(QWidget *parent = 0);
    ~DollarsWidget() {}

    /* getOutput:
    *   Return a QHBoxLayout with a output label and output
    *   display for the widget.
    */
    QHBoxLayout *getOutput();

  private:
    QHBoxLayout *wigOutput;
};
