#include "output_widget.h"

OutputWidget::OutputWidget(QWidget *parent)
             :QWidget(parent)
{
   // Configure view
   QGroupBox *grpBox = new QGroupBox(tr("Output"));
   layout = new QVBoxLayout;
   layout->addStretch(1);
   grpBox->setLayout(layout);
   grpBox->show();
   resultArea = new QTextEdit;
   resultArea->hide();

   // Add the GroupBox to the QWidget
   QHBoxLayout *wigLayout = new QHBoxLayout;
   wigLayout->addWidget(grpBox);
   wigLayout->addWidget(resultArea);
   setLayout(wigLayout);
}

void OutputWidget::addOutput(QHBoxLayout *item)
{
   if (!item) return;

   layout->addLayout(item);
}

void OutputWidget::linkResults(StudentSelector* select)
{
   connect(
      select, SIGNAL(transmitData(int)),
      this, SLOT(receiveData(int))
   );
   connect(
      this, SIGNAL(requestData(bool)),
      select, SLOT(dataRequested(bool))
   );
}
