#pragma once

using namespace std;

#include <QtOpenGL>

class GraphicsWidget : public QGLWidget
{
  Q_OBJECT

public:
  GraphicsWidget(QWidget *parent = 0):QGLWidget(parent) {};
  ~GraphicsWidget() {}

protected:
  void initializeGL();
  void resizeGL(int w, int h);
  void paintGL();
  void ngon(int n);
};