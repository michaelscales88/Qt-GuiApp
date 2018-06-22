/* Graphical User Interface Assignment Interface1 (I1)
 * Developer: Michael Scales
 */
#pragma once
#include <QtGui>

#include "student_selector.h"

using namespace std;

class OutputWidget: public QWidget
{
   Q_OBJECT

public:
   OutputWidget( QWidget *parent = 0 );
   ~OutputWidget() {}
   void addOutput( QHBoxLayout *item = 0 );
   void linkResults(StudentSelector* select);

private slots:
   /* Display the results:
    *    Submits the form to process the information
    *    and makes the area visible.
    */
   void submitForm() {
      emit requestData(true);
      resultArea->show();
   }

   /* Display the results:
    *    Receive the information from the component and
    *    generate the message..
    */
   void receiveData(int value) {
      if (value == -2) {
         resultArea->setText(
            "Based on your information, we have selected "
            "the following schools for you:\n\nTexas State University\n"
            "Awesome University\nUniversity of Texas\nGeorge Washing University\n\n"
            "Required funds: $14,000 (first year)"
         );
       }
       else {
         resultArea->setText(
            "Based on your information, we have selected "
            "the following majors which may interest you:\n\nComputer Science"
            "\nGeology\nUnderwater Basket Weaving\nCarpentry\n\n"
            "Required funds: $14,000 (next year)"
         );
       }
   }

signals:
   void requestData(bool value);

private:
   QVBoxLayout *layout;
   QTextEdit* resultArea;
};
