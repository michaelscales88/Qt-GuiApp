/* Graphical User Interface Assignment Interface1 (I2)
 * Developer: Michael Scales
 */
#include "window.h"

Window::Window()
{
    createMenus();
    initWidgetsDock();
    initTextEditDock();
    initOpenGl();
    setWindowTitle(tr("Informed Decision"));
    show();
}

void Window::initTextEditDock()
{
    // Right dock area
    QDockWidget *dock = new QDockWidget(this);
    textEdit = new QTextEdit;
    dock->setWidget(textEdit);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    viewMenu->addAction(dock->toggleViewAction());
}

void Window::initOpenGl()
{
    // Top dock area
    QDockWidget *dock = new QDockWidget(this);
    GraphicsWidget *wig = new GraphicsWidget();
    wig->resize(800, 800);
    dock->setWidget(wig);
    addDockWidget(Qt::TopDockWidgetArea, dock);
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
    DistanceWidget *distanceWidget = new DistanceWidget();
    QPushButton *submitBtn = new QPushButton(tr("Submit"));
    QPushButton *quitBtn = new QPushButton(tr("Exit"));

    // Set widget behavior
    output->addOutput(studentType->getOutput());
    output->addOutput(gpaWidget->getOutput());
    output->addOutput(satWidget->getOutput());
    output->addOutput(dollarsWidget->getOutput());
    output->addOutput(hobbiesWidget->getOutput());
    output->addOutput(distanceWidget->getOutput());
    output->linkResults(studentType);
    connect(
        submitBtn, SIGNAL(clicked()),
        output, SLOT(submitForm()));
    connect(
        quitBtn, SIGNAL(clicked()),
        SLOT(close()));

    // Add the widgets in the order of display
    FlowLayout *layout = new FlowLayout(1, 1, 1);
    layout->addWidget(studentType);
    QVBoxLayout *group1 = new QVBoxLayout;
    group1->addWidget(gpaWidget);
    group1->addWidget(satWidget);
    group1->addWidget(dollarsWidget);
    layout->addItem(group1);

    layout->addWidget(hobbiesWidget);
    layout->addWidget(distanceWidget);

    QVBoxLayout *group2 = new QVBoxLayout;
    group2->addWidget(output);
    group2->addSpacerItem(
        new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding));
    QHBoxLayout *btnGrp = new QHBoxLayout;
    btnGrp->addWidget(submitBtn);
    btnGrp->addWidget(quitBtn);
    group2->addLayout(btnGrp);
    layout->addItem(group2);

    // Left Dock area
    QDockWidget *dock = new QDockWidget(this);
    QWidget *dockWidgets = new QWidget;
    dockWidgets->setLayout(layout);
    dock->setWidget(dockWidgets);
    addDockWidget(Qt::LeftDockWidgetArea, dock);
    viewMenu->addAction(dock->toggleViewAction());
}

void Window::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    QAction *openAction = new QAction("&Open", this);
    connect(openAction, SIGNAL(triggered()), this, SLOT(openFile()));
    QAction *saveAction = new QAction("&Save", this);
    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveFile()));
    QAction *quitAction = new QAction("&Quit", this);
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(quitAction);

    viewMenu = menuBar()->addMenu(tr("&View"));
    helpMenu = menuBar()->addMenu(tr("&Help"));
    QAction *aboutAction = new QAction("&About", this);
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(aboutDialog()));
    helpMenu->addAction(aboutAction);
}

void Window::openFile()
{
    QString fname = QFileDialog::getOpenFileName(this);
    QFile file(fname);

    file.open(QFile::ReadOnly | QFile::Text);

    QTextStream ReadFile(&file);
    textEdit->setText(ReadFile.readAll());
}

void Window::saveFile()
{
    QString fname = QFileDialog::getSaveFileName(this);
    QFile outfile;
    outfile.setFileName(fname);
    outfile.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&outfile);
    out << textEdit->toPlainText() << endl;
}

void Window::aboutDialog()
{
    QMessageBox msgBox;
    msgBox.setText(
        "This progam was designed by Michael Scales for the Summer 2018 GUI class.\n"
        "More information to follow...");
    msgBox.exec();
}
