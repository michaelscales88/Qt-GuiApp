#pragma once

using namespace std;

#include <QtOpenGL>

class GraphicsWidget : public QGLWidget
{
  Q_OBJECT

public:
  GraphicsWidget(QWidget *parent = 0) : QGLWidget(parent) {};
  ~GraphicsWidget() {}

  QSize minimumSizeHint() const;
  QSize sizeHint() const;

protected:
  void initializeGL();
  void resizeGL(int w, int h);
  void paintGL();

private:
  /*
   *
   */
  void initPoint();

  /*
   *
   */
  void initLine();

  /*
   *
   */
  void initTriangle();

  /*
   *
   */
  void initQuad();

  /*
   *
   */
  void initHexagon();

  /*
   *
   */
  void initCube();
};