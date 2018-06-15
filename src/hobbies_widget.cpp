/* Graphical User Interface Assignment Interface1 (I1)
 * Developer: Michael Scales
 */
#include "hobbies_widget.h"

HobbiesWidget::HobbiesWidget(QWidget *parent)
              :Base(parent)
{
   // Configure view
   QVBoxLayout *layout = new QVBoxLayout;
   QLabel *label = new QLabel(this);
   list = new QListWidget(this);
   label->setText("Select your hobbies");
   addItems(list);   // Seed the list with some hobbies
   layout->addWidget(label);
   layout->addWidget(list);
   setLayout(layout);

   // Configure the display area for the widget
   wigOutput = new QHBoxLayout;
   QLabel *displayLabel = new QLabel(tr("Your hobbies:"));
   display = new QLineEdit;
   display->setReadOnly(true);

   // Update the output based on the selection in the
   // list
   connect(
      list, SIGNAL(itemSelectionChanged()),
      this, SLOT(updateDisplay())
   );
   wigOutput->addWidget(displayLabel);
   wigOutput->addWidget(display);
}

QHBoxLayout* HobbiesWidget::getOutput() { return wigOutput; }

void HobbiesWidget::addItems(QListWidget* list)
{
   list->addItem(tr("Football"));
   list->addItem(tr("Soccer"));
   list->addItem(tr("Baseball"));
   list->addItem(tr("Reading"));
   list->addItem(tr("Video Games"));
}

