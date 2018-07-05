/* Graphical User Interface Assignment Interface4 (I4)
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
      : QGLWidget(parent), a(1), b(1), c(1), t(1)
  {
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
  void setAValue(int a)
  {
    this->a = a;
    emit repaint();
  }
  void setBValue(int b)
  {
    this->b = b;
    emit repaint();
  }
  void setCValue(int c)
  {
    this->c = c;
    emit repaint();
  }
  void setTValue(int t)
  {
    this->t = t;
    emit repaint();
  }

signals:
  /* repaint:
    *   Signal the data from the widget.
    */
  void repaint();

private:
  /* initCurve:
    *   Create a curve along the specified glVertex(x, y, 0.0) 
    *   coordinates. Fn: A + BX + CX^2 for -t < x < t
    */
  void initCurve();
  int a, b, c, t;
};