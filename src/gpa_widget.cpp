/* Graphical User Interface Assignment Interface3 (I3)
 * Developer: Michael Scales
 */
#include "gpa_widget.h"

GpaWidget::GpaWidget(QWidget *parent)
    : Base(parent)
{
    // Configure view
    QLabel *label = new QLabel(this);
    label->setText("Select your GPA:");
    slider = new QSlider(this);
    slider->setRange(0, 500);
    slider->setOrientation(Qt::Horizontal);
    spinner = new QDoubleSpinBox(this);
    spinner->setRange(0, 5.0);
    spinner->setSingleStep(0.01);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(label);
    layout->addWidget(spinner);
    layout->addWidget(slider);
    setLayout(layout);

    // Connect the spinbox and the slider so they
    // update one another + match.
    connect(
        slider, SIGNAL(valueChanged(int)),
        SLOT(changeSpinBox(int)));
    connect(
        spinner, SIGNAL(valueChanged(double)),
        SLOT(changeSlider(double)));

    // Configure the display area for the widget
    wigOutput = new QHBoxLayout;
    QLabel *displayLabel = new QLabel(tr("Your gpa:"));
    display = new QLineEdit;
    display->setReadOnly(true);

    // Set the display to update based on the spinner value
    connect(
        spinner, SIGNAL(valueChanged(double)),
        SLOT(updateDisplay(double)));
    wigOutput->addWidget(displayLabel);
    wigOutput->addWidget(display);
    spinner->setValue(4.0);
}

QHBoxLayout *GpaWidget::getOutput() { return wigOutput; }

void GpaWidget::changeSpinBox(int sliderValue)
{
    if (convertSpinBoxValueToSlider(slider->value()) != sliderValue)
    {
        spinner->setValue((double)sliderValue / 100);
    }
}

void GpaWidget::changeSlider(double spinBoxValue)
{
    slider->setValue(convertSpinBoxValueToSlider(spinBoxValue));
}

void GpaWidget::updateDisplay(double value)
{
    display->setText(QString("%1").arg(value));
}
