/* Graphical User Interface Assignment Interface1 (I1)
 * Developer: Michael Scales
 */
#include "sat_widget.h"

SatWidget::SatWidget(QWidget *parent)
    : Base(parent)
{
    // Configure view
    QLabel *label = new QLabel(this);
    label->setText("Enter your SAT score:");
    QComboBox *combo = new QComboBox(this);
    addItems(combo); // Seed the combobox with values
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(label);
    layout->addWidget(combo);
    setLayout(layout);

    // Configure the output area
    wigOutput = new QHBoxLayout;
    QLabel *displayLabel = new QLabel(tr("Sat score:"));
    display = new QLineEdit;
    display->setReadOnly(true);
    // Update the display with the selection from the combobox
    connect(
        combo, SIGNAL(currentIndexChanged(int)),
        this, SLOT(updateDisplay(int)));
    combo->setCurrentIndex(1400);
    wigOutput->addWidget(displayLabel);
    wigOutput->addWidget(display);
}

QHBoxLayout *SatWidget::getOutput()
{
    return wigOutput;
}

void SatWidget::addItems(QComboBox *combo)
{
    QStringList list;
    for (int i = 0; i <= 2400; i++)
        list << QString::number(i);
    combo->addItems(list);
}

void SatWidget::updateDisplay(int value)
{
    display->setText(QString::number(value));
}
