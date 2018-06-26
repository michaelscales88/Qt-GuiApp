/* Graphical User Interface Assignment Interface1 (I2)
 * Developer: Michael Scales
 */
#include "output_widget.h"

OutputWidget::OutputWidget(QWidget *parent)
    : QWidget(parent)
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
    if (!item)
        return;

    layout->addLayout(item);
}

void OutputWidget::linkResults(StudentSelector *select)
{
    connect(
        select, SIGNAL(transmitData(int)),
        SLOT(receiveData(int)));
    connect(
        this, SIGNAL(requestData(bool)),
        select, SLOT(dataRequested(bool)));
}

void OutputWidget::receiveData(int value)
{
    if (value == -2)
    {
        resultArea->setText(
            "Based on your information, we have selected "
            "the following schools for you:\n\nTexas State University\n"
            "Awesome University\nUniversity of Texas\nGeorge Washing University\n\n"
            "Required funds: $14,000 (first year)");
    }
    else
    {
        resultArea->setText(
            "Based on your information, we have selected "
            "the following majors which may interest you:\n\nComputer Science"
            "\nGeology\nUnderwater Basket Weaving\nCarpentry\n\n"
            "Required funds: $14,000 (next year)");
    }
}

void OutputWidget::submitForm()
{
    emit requestData(true);
    resultArea->show();
}