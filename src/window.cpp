/* Graphical User Interface Assignment Interface1 (I1)
 * Developer: Michael Scales
 */
#include "window.h"

Window::Window()
{
    createMenus();
    initWidgetsDock();
    initTextEditDock();
    setWindowTitle(tr("Informed Decision"));
    show();
}

void Window::initTextEditDock() {
    QDockWidget *dock = new QDockWidget(this);
    dock->setWidget(new QTextEdit);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    viewMenu->addAction(dock->toggleViewAction());
}

void Window::initWidgetsDock()
{
    // Create the widgets for the dock
    OutputWidget *output = new OutputWidget();
    StudentSelector *studentType = new StudentSelector();
    GpaWidget *gpaWidget = new GpaWidget();
    SatWidget *satWidget = new SatWidget();
    DollarsWidget *dollarsWidget = new DollarsWidget();
    HobbiesWidget *hobbiesWidget = new HobbiesWidget();
    QPushButton *submitBtn = new QPushButton(tr("Submit"));
    QPushButton *quitBtn = new QPushButton(tr("Exit"));

    // Set widget behavior
    output->addOutput(studentType->getOutput());
    output->addOutput(gpaWidget->getOutput());
    output->addOutput(satWidget->getOutput());
    output->addOutput(dollarsWidget->getOutput());
    output->addOutput(hobbiesWidget->getOutput());
    output->linkResults(studentType);
    connect(
        submitBtn, SIGNAL(clicked()),
        output, SLOT(submitForm()));
    connect(
        quitBtn, SIGNAL(clicked()),
        this, SLOT(close()));

    // Add the widgets in the order of display
    FlowLayout *layout = new FlowLayout;
    layout->addWidget(studentType);
    layout->addWidget(gpaWidget);
    layout->addWidget(satWidget);
    layout->addWidget(dollarsWidget);
    layout->addWidget(hobbiesWidget);
    layout->addWidget(output);
    layout->addWidget(submitBtn);
    layout->addWidget(quitBtn);

    QDockWidget *dock = new QDockWidget(this);
    QWidget *dockWidgets = new QWidget;
    dockWidgets->setLayout(layout);
    dock->setWidget(dockWidgets);
    addDockWidget(Qt::LeftDockWidgetArea, dock);
    viewMenu->addAction(dock->toggleViewAction());
}

void Window::createMenus() {
    fileMenu = menuBar()->addMenu(tr("&File"));
    QAction *openAction = new QAction("&Open", this);
    QAction *saveAction = new QAction("&Save", this);
    QAction *quitAction = new QAction("&Exit", this);
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(quitAction);

    viewMenu = menuBar()->addMenu(tr("&View"));
    helpMenu = menuBar()->addMenu(tr("&Help"));
}