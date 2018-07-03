/* Graphical User Interface Assignment Interface3 (I3)
 * Developer: Michael Scales
 */
#pragma once
#include <QtGui>

using namespace std;

class Base : public QWidget
{
public:
  Base(QWidget *parent = 0) : QWidget(parent){};
  ~Base() {}

  /* getOutput:
    *   Requires all extended QWidgets for the application to implement
    *   a getOutput methods for all classes in the heirarchy.
    */
  virtual QHBoxLayout *getOutput() { return new QHBoxLayout; }
};
