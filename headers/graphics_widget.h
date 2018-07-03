/* Graphical User Interface Assignment Interface3 (I3)
 * Developer: Michael Scales
 */
#pragma once

using namespace std;

#include <QtOpenGL>

class GraphicsWidget : public QGLWidget
{
  Q_OBJECT

public:
  GraphicsWidget(QWidget *parent = 0) : QGLWidget(parent){};
  ~GraphicsWidget() {}

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
  void initPoint();

  /* initLine:
    *   Create a line between the first and second glVertex(x, y, z) 
    *   coordinates.
    */
  void initLine();

  /* initTriangle:
    *   Create a triangle with vertices at the three glVertex(x, y, z) 
    *   coordinates.
    */
  void initTriangle();

  /* initQuad:
    *   Create a quad with vertices at the four glVertex(x, y, z) 
    *   coordinates.
    */
  void initQuad();

  /* initHexagon:
    *   Create a hexagon by first creating a circle with 6 points. 
    *   Using GL_POLYGON to connect the 6 points gives us a hexagon.
    */
  void initHexagon();

  /* initCube:
    *   Create quads with vertices at each group of four glVertex(x, y, z) 
    *   coordinates. Each quad connects to form a cube.
    */
  void initCube();
};