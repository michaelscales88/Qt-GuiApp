/* Graphical User Interface Assignment Interface3 (I3)
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
#include "graphics_widget2.h"
#include "base.h"

using namespace std;

class Window : public QMainWindow
{
  Q_OBJECT

public:
  Window();
  ~Window() {}

private slots:
  /* openFile:
    *   Open a OpenFileDialig and open the file to the Text Area.
    */
  void openFile();

  /* saveFile:
    *  Open a SaveFileDialog and save the contents to the Text Area.
    */
  void saveFile();
  /* aboutDialog:
    *   Open some basic information about the application.
    */
  void aboutDialog();

private:
  QMenu *fileMenu;
  QMenu *viewMenu;
  QMenu *helpMenu;
  QTextEdit *textEdit;

  /* initWidgets:
    *   Create the widgets that we will add to the dock area.
    */
  FlowLayout *initWidgets();

  /* initWidgetsDock:
    *   Initialize all the widgets in the left dock area.
    */
  void initWidgetsDock();

  /* initTextEditDock:
    *   Initialie the Text Area for the open and save file options.
    */
  void initTextEditDock();

  /* createMenus:
    *   Create the menus based on the actions registered in the 
    *   application.
    */
  void createMenus();

  /* intOpenGL:
    *   Create the widget that will display the graphics for the 
    *   application.
    */
  void initOpenGl();
};
