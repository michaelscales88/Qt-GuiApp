/* Graphical User Interface Assignment Interface3 (I3)
 * Developer: Michael Scales
 */
#pragma once

using namespace std;

#include <QtOpenGL>
#include <math.h>
#include <iostream>

class GraphicsWidget2 : public QGLWidget
{
  Q_OBJECT

public:
  GraphicsWidget2(QWidget *parent = 0)
    :QGLWidget(parent), a(1), b(1), c(1) {
      connect(this, SIGNAL(repaint()), SLOT(update()));
    }
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
  void gluPerspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar);

private slots:
  void setAValue(int a) {
    this->a = a;
    emit repaint();
  }
  void setBValue(int b) { 
    this->b = b;
    emit repaint();
  }
  void setCValue(int c) {
    this->c = c;
    emit repaint();
  }

signals:
  /* transmitData:
    *   Signal the data from the widget.
    */
  void repaint();

private:
  /* initPoint:
    *   Create a point at the specified glVertex(x, y, z) 
    *   coordinate.
    */
  void initCurve();
  int a, b, c;
};