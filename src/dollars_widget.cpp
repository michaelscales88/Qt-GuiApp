/* Graphical User Interface Assignment Interface1 (I2)
 * Developer: Michael Scales
 */
#include "dollars_widget.h"

DollarsWidget::DollarsWidget(QWidget *parent)
    : Base(parent)
{
    QLabel *label = new QLabel;
    QLineEdit *input = new QLineEdit;
    label->setText("Enter your available funds: $");
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(label);
    layout->addWidget(input);
    setLayout(layout);

    // Configure the display area for the widget
    wigOutput = new QHBoxLayout;
    QLabel *displayLabel = new QLabel(tr("Your funds: $"));
    QLineEdit *display = new QLineEdit;
    display->setReadOnly(true);

    // Update the display area with our input
    connect(
        input, SIGNAL(textChanged(const QString &)),
        display, SLOT(setText(const QString &)));
    wigOutput->addWidget(displayLabel);
    wigOutput->addWidget(display);
}

QHBoxLayout *DollarsWidget::getOutput() { return wigOutput; }
