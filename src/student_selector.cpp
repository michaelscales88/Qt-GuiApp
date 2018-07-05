/* Graphical User Interface Assignment Interface4 (I4)
 * Developer: Michael Scales
 */
#include "student_selector.h"

StudentSelector::StudentSelector(QWidget *parent)
    : Base(parent)
{
    // Configure view
    QGroupBox *groupBox = new QGroupBox(tr("Select student type"));
    QVBoxLayout *layout = new QVBoxLayout;
    btnGroup = new QButtonGroup;
    QRadioButton *radio1 = new QRadioButton(tr("High School Student"));
    QRadioButton *radio2 = new QRadioButton(tr("Freshmen"));
    QRadioButton *radio3 = new QRadioButton(tr("Sophmore"));
    // Allows us to access the buttons
    btnGroup->addButton(radio1);
    btnGroup->addButton(radio2);
    btnGroup->addButton(radio3);
    layout->addWidget(radio1);
    layout->addWidget(radio2);
    layout->addWidget(radio3);
    layout->addStretch(1);
    groupBox->setLayout(layout);
    groupBox->show();

    // Configure the output area
    wigOutput = new QHBoxLayout;
    QLabel *label = new QLabel(tr("Student Type:"));
    QLineEdit *display = new QLineEdit;
    display->setReadOnly(true);
    display->setText(tr("High School Student"));
    QSignalMapper *mapper = new QSignalMapper(this);
    // Connect the radiobuttons to show which type of student
    // we are in the output area
    connect(
        mapper, SIGNAL(mapped(const QString &)),
        display, SLOT(setText(const QString &)));
    connect(
        radio1, SIGNAL(clicked()),
        mapper, SLOT(map()));
    mapper->setMapping(radio1, tr("High School Student"));
    connect(
        radio2, SIGNAL(clicked()),
        mapper, SLOT(map()));
    mapper->setMapping(radio2, tr("Freshmen"));
    connect(
        radio3, SIGNAL(clicked()),
        mapper, SLOT(map()));
    mapper->setMapping(radio3, tr("Sophmore"));
    radio1->setChecked(true);
    wigOutput->addWidget(label);
    wigOutput->addWidget(display);

    // Add the GroupBox to the QWidget
    QHBoxLayout *wigLayout = new QHBoxLayout;
    wigLayout->addWidget(groupBox);
    setLayout(wigLayout);
}

QHBoxLayout *StudentSelector::getOutput()
{
    return wigOutput;
}

void StudentSelector::dataRequested(bool value)
{
    if (value)
    {
        int id = btnGroup->checkedId();
        emit transmitData(id);
    }
}