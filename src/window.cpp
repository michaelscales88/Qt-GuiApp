/* Graphical User Interface Assignment Interface3 (I3)
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
    QDockWidget *rightDock = getDock(tr("Text Area"));
    addDockWidget(Qt::RightDockWidgetArea, rightDock);
    textEdit = new QTextEdit;
    rightDock->widget()->layout()->addWidget(textEdit);
    rightDock->hide();
}

void Window::initOpenGl()
{
    // Top dock area
    QDockWidget *topDock = getDock(tr("Graphics Window I"));
    addDockWidget(Qt::TopDockWidgetArea, topDock);
    topDock->setFloating(true);
    topDock->resize(400, 400);

    GraphicsWidget *shapesWidget = new GraphicsWidget(topDock);
    topDock->widget()->layout()->addWidget(shapesWidget);
    shapesWidget->resize(300, 300);

    // Bottom dock area
    QDockWidget *botDock = getDock(tr("Graphics Window II"));
    addDockWidget(Qt::BottomDockWidgetArea, botDock);
    botDock->setFloating(true);
    botDock->resize(400, 400);

    GraphicsWidget2 *curveWidget = new GraphicsWidget2(botDock);
    botDock->widget()->layout()->addWidget(curveWidget);
    curveWidget->resize(300, 300);

    QWidget *sliderWidget = new QWidget();
    QHBoxLayout *sliderPanel = new QHBoxLayout();
    QSlider *aSlider = createSlider();
    QSlider *bSlider = createSlider();
    QSlider *cSlider = createSlider();
    sliderPanel->addWidget(aSlider);
    sliderPanel->addWidget(bSlider);
    sliderPanel->addWidget(cSlider);
    connect(
        aSlider, SIGNAL(valueChanged(int)), curveWidget, SLOT(setAValue(int))
    );
    connect(
        bSlider, SIGNAL(valueChanged(int)), curveWidget, SLOT(setBValue(int))
    );
    connect(
        cSlider, SIGNAL(valueChanged(int)), curveWidget, SLOT(setCValue(int))
    );
    sliderWidget->setLayout(sliderPanel);
    botDock->widget()->layout()->addWidget(sliderWidget);
}

QSlider *Window::createSlider()
{
    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 100);
    slider->setSingleStep(1);
    slider->setPageStep(10);
    slider->setTickInterval(10);
    slider->setTickPosition(QSlider::TicksRight);
    return slider;
}

QDockWidget *Window::getDock(QString dockTitle)
{
    QDockWidget *dock = new QDockWidget(dockTitle, this);
    QWidget *dockWidget = new QWidget(this);
    dockWidget->setLayout(new QVBoxLayout);
    dock->setWidget(dockWidget);
    viewMenu->addAction(dock->toggleViewAction());
    return dock;
}

FlowLayout *Window::initWidgets()
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

    // Bind the widgets to the output area
    output->addOutput(studentType->getOutput());
    output->addOutput(gpaWidget->getOutput());
    output->addOutput(satWidget->getOutput());
    output->addOutput(dollarsWidget->getOutput());
    output->addOutput(hobbiesWidget->getOutput());
    output->addOutput(distanceWidget->getOutput());

    // Set widget behavior
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

    // Group the widgets to keep them organized in the
    // flowlayout
    QVBoxLayout *group1 = new QVBoxLayout;
    group1->addWidget(gpaWidget);
    group1->addWidget(satWidget);
    group1->addWidget(dollarsWidget);
    layout->addItem(group1);

    layout->addWidget(hobbiesWidget);
    layout->addWidget(distanceWidget);

    // Output area + form controls
    QVBoxLayout *group2 = new QVBoxLayout;
    group2->addWidget(output);
    group2->addSpacerItem(
        new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding));
    QHBoxLayout *btnGrp = new QHBoxLayout;
    btnGrp->addWidget(submitBtn);
    btnGrp->addWidget(quitBtn);
    group2->addLayout(btnGrp);
    layout->addItem(group2);

    return layout;
}

void Window::initWidgetsDock()
{
    // Left Dock area
    QDockWidget *leftDock = getDock(tr("Widgets Area"));
    addDockWidget(Qt::LeftDockWidgetArea, leftDock);
    QWidget *dockshapesWidget = new QWidget;
    dockshapesWidget->setLayout(initWidgets());
    leftDock->widget()->layout()->addWidget(dockshapesWidget);
    leftDock->hide();
}

void Window::createMenus()
{
    // File menu
    fileMenu = menuBar()->addMenu(tr("&File"));
    QAction *openAction = new QAction("&Open", this);
    connect(openAction, SIGNAL(triggered()), this, SLOT(openFile()));
    fileMenu->addAction(openAction);
    QAction *saveAction = new QAction("&Save", this);
    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveFile()));
    fileMenu->addAction(saveAction);
    QAction *quitAction = new QAction("&Quit", this);
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));
    fileMenu->addAction(quitAction);

    // Dock widget menu
    viewMenu = menuBar()->addMenu(tr("&View"));

    // Help menu
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
