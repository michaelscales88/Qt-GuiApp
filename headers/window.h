/* Graphical User Interface Assignment Interface1 (I1)
 * Developer: Michael Scales
 */
#pragma once
#include <QtGui>

#include "flowlayout.h"
#include "distance_widget.h"
#include "output_widget.h"
#include "dollars_widget.h"
#include "gpa_widget.h"
#include "hobbies_widget.h"
#include "output_widget.h"
#include "sat_widget.h"
#include "student_selector.h"
#include "graphics_widget.h"
#include "base.h"

using namespace std;

class Window : public QMainWindow
{
    Q_OBJECT

  public:
    Window();
    ~Window() {}

  private slots:
    /* getOutput:
    *   Return a QHBoxLayout with a output label and output
    *   display for the widget.
    */
    void openFile();
    /* getOutput:
    *   Return a QHBoxLayout with a output label and output
    *   display for the widget.
    */
    void saveFile();
    /* getOutput:
    *   Return a QHBoxLayout with a output label and output
    *   display for the widget.
    */
    void aboutDialog();

  private:
    QMenu *fileMenu;
    QMenu *viewMenu;
    QMenu *helpMenu;
    QTextEdit *textEdit;

    /* getOutput:
    *   Return a QHBoxLayout with a output label and output
    *   display for the widget.
    */
    void initWidgetsDock();
    /* getOutput:
    *   Return a QHBoxLayout with a output label and output
    *   display for the widget.
    */
    void initTextEditDock();
    /* getOutput:
    *   Return a QHBoxLayout with a output label and output
    *   display for the widget.
    */
    void createMenus();
    void initOpenGl();
};
