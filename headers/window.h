/* Graphical User Interface Assignment Interface1 (I1)
 * Developer: Michael Scales
 */
#pragma once
#include <QtGui>

#include "flowlayout.h"
#include "output_widget.h"
#include "dollars_widget.h"
#include "gpa_widget.h"
#include "hobbies_widget.h"
#include "output_widget.h"
#include "sat_widget.h"
#include "student_selector.h"
#include "base.h"

using namespace std;

class Window: public QMainWindow
{
   Q_OBJECT

public:
   Window();
   ~Window() {}

private:
    void initWidgetsDock();
    void initTextEditDock();
    void createMenus();

    QMenu *fileMenu;
    QMenu *viewMenu;
    QMenu *helpMenu;
};
