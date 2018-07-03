/* Graphical User Interface Assignment Interface3 (I3)
 * Developer: Michael Scales
 */
#pragma once

using namespace std;

#include <QtOpenGL>

class GraphicsWidget2 : public QGLWidget
{
  Q_OBJECT

public:
  GraphicsWidget2(QWidget *parent = 0) : QGLWidget(parent){};
  ~GraphicsWidget2() {}

  /*  Size hints:
    *   Size hints are used to give the containing widget information
    *   about the preferred/minimum graphic area.
    */
  QSize minimumSizeHint() const;
  QSize sizeHint() const;

protected:
  /* OpenGL protected functions:
    *   Required functions for creating and maintaining the graphic
    *   area.
    */
  void initializeGL();
  void resizeGL(int w, int h);
  void paintGL();

private:
  /* initPoint:
    *   Create a point at the specified glVertex(x, y, z) 
    *   coordinate.
    */
  void initCurve();
};