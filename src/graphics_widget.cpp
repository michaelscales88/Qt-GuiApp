/* Graphical User Interface Assignment Interface4 (I4)
 * Developer: Michael Scales
 */
#include "graphics_widget.h"

QSize GraphicsWidget::minimumSizeHint() const
{
  return QSize(200, 200);
}

QSize GraphicsWidget::sizeHint() const
{
  return QSize(800, 800);
}

//Initialize the GL settings
void GraphicsWidget::initializeGL()
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glShadeModel(GL_SMOOTH);                           // Enable smooth shading
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Nice perspective corrections
}

void GraphicsWidget::resizeGL(int w, int h)
{
  // Manage aspect ratio when resizing
  int side = qMin(w, h);
  glViewport((w - side) / 2, (h - side) / 2, side, side);

  // Configure display area
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  
  // Set the view area for the perspective projection
  gluPerspective(90.0, (float)w / (float)h, 5.0, 30.0);
}

void GraphicsWidget::paintGL()
{
  double distance = 15.0;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
  glMatrixMode(GL_MODELVIEW);                         // Set model view for transformations

  glLoadIdentity();
  glPointSize(4.0);
  glTranslatef(-8.0, 0.0, -distance);
  glColor3f(0.0, 255.0, 0.0);
  initPoint();

  glLoadIdentity();
  glLineWidth(2.0);
  glTranslatef(-2.0, 3.0, -distance);
  glColor3f(1.0f, 0.3f, 1.0f);
  initLine();

  glLoadIdentity();
  glLineWidth(2.0);
  glTranslatef(0.0, 5.0, -distance);
  glColor3f(0.0, 0.0, 255.0);
  initTriangle();

  glLoadIdentity();
  glLineWidth(2.0);
  glTranslatef(2.0, -1.0, -distance);
  glColor3f(255.0, 255.0, 0.0);
  initQuad();

  glLoadIdentity();
  glLineWidth(2.0);
  glTranslatef(0.0, 2.0, -distance);
  glColor3f(0.0, 255.0, 255.0);
  initHexagon();

  glLoadIdentity();
  glLineWidth(2.0);
  glTranslatef(3.0, 4.0, -distance);
  initCube();

  glFlush();
}

void GraphicsWidget::gluPerspective(
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

void GraphicsWidget::initPoint()
{
  glBegin(GL_POINTS);
  glVertex3f(0.0f, 0.5f, 0.0f);
  glEnd();
}

void GraphicsWidget::initLine()
{
  glBegin(GL_LINES);
  glVertex3f(-3.0f, -4.0f, 0.0f); // start
  glVertex3f(-2.0f, 4.0f, 0.0f);  // end
  glEnd();
}

void GraphicsWidget::initTriangle()
{
  glBegin(GL_TRIANGLES);
  glVertex3f(-2.2f, 0.0f, 0.0f); // left vertex
  glVertex3f(0.0f, 2.2f, 0.0f);  // top vertex
  glVertex3f(2.2f, 0.0f, 0.0f);  // right vertex
  glEnd();
}

void GraphicsWidget::initQuad()
{
  float radius = 1.2;

  glBegin(GL_QUADS);
  glVertex3f(-radius, -radius, 0.0f); // bottom left
  glVertex3f(radius, -radius, 0.0f);  // bottom right
  glVertex3f(radius, radius, 0.0f);   // top right
  glVertex3f(-radius, radius, 0.0f);  // top left
  glEnd();
}

void GraphicsWidget::initHexagon()
{
  glBegin(GL_POLYGON);
  for (int i = 0; i < 6; ++i)
  {
    glVertex3f(
        sin(i / 6.0 * 2 * M_PI),
        cos(i / 6.0 * 2 * M_PI),
        0.0f);
  }
  glEnd();
}

void GraphicsWidget::initCube()
{
  int segLength = 1.0f;
  glBegin(GL_QUADS);

  // Top face
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex3f(segLength, segLength, -segLength);  // top right
  glVertex3f(-segLength, segLength, -segLength); // top left
  glVertex3f(-segLength, segLength, segLength);  // bottom left
  glVertex3f(segLength, segLength, segLength);   // bottom right

  // Bottom face
  glColor3f(1.0f, 0.8f, 0.0f);
  glVertex3f(segLength, -segLength, segLength);   // top right
  glVertex3f(-segLength, -segLength, segLength);  // top left
  glVertex3f(-segLength, -segLength, -segLength); // bottom left
  glVertex3f(segLength, -segLength, -segLength);  // bottom right

  // Front face
  glColor3f(0.9f, 0.0f, 0.0f);
  glVertex3f(segLength, segLength, segLength);   // top right
  glVertex3f(-segLength, segLength, segLength);  // top left
  glVertex3f(-segLength, -segLength, segLength); // bottom left
  glVertex3f(segLength, -segLength, segLength);  // bottom right

  // Back face
  glColor3f(1.0f, 1.0f, 0.0f);
  glVertex3f(segLength, -segLength, -segLength);  // top right
  glVertex3f(-segLength, -segLength, -segLength); // top left
  glVertex3f(-segLength, segLength, -segLength);  // bottom left
  glVertex3f(segLength, segLength, -segLength);   // bottom right

  // Left face
  glColor3f(0.4f, 0.0f, 1.0f);
  glVertex3f(-segLength, segLength, segLength);   // top right
  glVertex3f(-segLength, segLength, -segLength);  // top left
  glVertex3f(-segLength, -segLength, -segLength); // bottom left
  glVertex3f(-segLength, -segLength, segLength);  // bottom right

  // Right face
  glColor3f(1.0f, 0.0f, 1.0f);
  glVertex3f(segLength, segLength, -segLength);  // top right
  glVertex3f(segLength, segLength, segLength);   // top left
  glVertex3f(segLength, -segLength, segLength);  // bottom left
  glVertex3f(segLength, -segLength, -segLength); // bottom right

  glEnd();
}
