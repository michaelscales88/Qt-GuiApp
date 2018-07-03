/* Graphical User Interface Assignment Interface3 (I3)
 * Developer: Michael Scales
 */
#include "graphics_widget2.h"

QSize GraphicsWidget2::minimumSizeHint() const
{
  return QSize(200, 200);
}

QSize GraphicsWidget2::sizeHint() const
{
  return QSize(800, 800);
}

//Initialize the GL settings
void GraphicsWidget2::initializeGL()
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glShadeModel(GL_SMOOTH);                           // Enable smooth shading
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Nice perspective corrections
}

void GraphicsWidget2::resizeGL(int w, int h)
{
  // Manage aspect ratio when resizing
  int side = qMin(w, h);
  glViewport((w - side) / 2, (h - side) / 2, side, side);

  // Configure display area
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // Set the view area for the parallel projection
  glOrtho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0);
}

void GraphicsWidget2::paintGL()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
  glMatrixMode(GL_MODELVIEW);                         // Set model view for transformations

  glLoadIdentity();
  initCurve();
  glFlush();
}

void GraphicsWidget2::initCurve() {
  
}