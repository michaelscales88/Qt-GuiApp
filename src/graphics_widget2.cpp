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
  //glOrtho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0);
  gluPerspective(90.0, (float)w / (float)h, 5.0, 30.0);
}

void GraphicsWidget2::paintGL()
{
  double distance = 15.0;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
  glMatrixMode(GL_MODELVIEW);                         // Set model view for transformations

  glLoadIdentity();
  glTranslatef(0.0, 0.0, -distance);
  initCurve();
  glFlush();
}

void GraphicsWidget2::gluPerspective(
  GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar
)
{
  GLdouble xmin, xmax, ymin, ymax;

  ymax = zNear * tan(fovy * M_PI / 360.0);
  ymin = -ymax;
  xmin = ymin * aspect;
  xmax = ymax * aspect;

  glFrustum(xmin, xmax, ymin, ymax, zNear, zFar);
}

void GraphicsWidget2::initCurve() {
  int boundary = 1000;
  glBegin(GL_LINE_STRIP);
  for (int x = -boundary; x <= boundary; x++)
      glVertex3f((double)x, (double)(a * 1 + b * (1 * x) + (c * pow(x, 2))), 0.0);
  glEnd();
}