/* Graphical User Interface Assignment Interface1 (I1)
 * Developer: Michael Scales
 */
#pragma once
#include <QtGui>

#include "student_selector.h"

using namespace std;

class OutputWidget : public QWidget
{
  Q_OBJECT

public:
  OutputWidget(QWidget *parent = 0);
  ~OutputWidget() {}
  /* addOutput:
    *   
    *   
    */
  void addOutput(QHBoxLayout *item = 0);
  /* linkResults:
    *   
    */
  void linkResults(StudentSelector *select);

private slots:
  /* submitForm:
    *    Submits the form to process the information
    *    and makes the area visible.
    */
  void submitForm();

  /* receiveData:
    *    Receive the information from the component and
    *    generate the message..
    */
  void receiveData(int value);

signals:
  /* requestData:
    *    Signals that the data from the other forms has 
    *    been requested.
    */
  void requestData(bool value);

private:
  QVBoxLayout *layout;
  QTextEdit *resultArea;
};
