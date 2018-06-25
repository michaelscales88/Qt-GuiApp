/* Graphical User Interface Assignment Interface1 (I1)
 * Developer: Michael Scales
 */
#include "distance_widget.h"

DistanceWidget::DistanceWidget(QWidget *parent)
    : Base(parent)
{
    // Configure view
    QLabel* viewLabel = new QLabel(
        tr("Select the maximum distance you are willing to travel:")
    );
    viewDisplay = new QLineEdit(this);
    QDial *viewDial = new QDial(this);
    viewDial->setMinimum(0);
    viewDial->setMaximum(10001);
    viewDisplay->setReadOnly(true);
    QHBoxLayout *displayLayout = new QHBoxLayout;
    displayLayout->addWidget(viewLabel);
    displayLayout->addWidget(viewDisplay);
    QVBoxLayout *layout = new QVBoxLayout;    
    layout->addLayout(displayLayout);
    layout->addWidget(viewDial);
    setLayout(layout);

    // Configure the output area
    wigOutput = new QHBoxLayout;
    QLabel *outputLabel = new QLabel(tr("Maximum distance:"));
    outputDisplay = new QLineEdit;
    outputDisplay->setReadOnly(true);
    // Update the display with the selection from the combobox
    connect(viewDial, SIGNAL(valueChanged(int)), this, SLOT(updateDisplay(int)));
    viewDial->setValue(50);
    wigOutput->addWidget(outputLabel);
    wigOutput->addWidget(outputDisplay);
}

QHBoxLayout *DistanceWidget::getOutput()
{
    return wigOutput;
}
