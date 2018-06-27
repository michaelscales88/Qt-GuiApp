#include "graphics_widget.h"

//Initialize the GL settings
void GraphicsWidget::initializeGL()
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}

//Set up the viewport based on the screen dimentions
//Function is called implicitly by initializeGL and when screen is resized
void GraphicsWidget::resizeGL(int w, int h)
{
  //algorithm to keep scene "square" (preserve aspect ratio)
  //even if screen is streached
  if (w > h)
    glViewport((w - h) / 2, 0, h, h);
  else
    glViewport(0, (h - w) / 2, w, w);

  //setup the projection and switch to model view for transformations
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1, 1, -1, 1, -1, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  //implicit call to paintGL after resized
}

//Paints the GL scene
void GraphicsWidget::paintGL()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glClear(GL_DEPTH_BUFFER_BIT);

  initPoint();
  initLine();
  initTriangle();
  initQuad();
  initHexagon();
  //initCube();
  glFlush();
}

void GraphicsWidget::initPoint()
{
  glPointSize(5.0);
  glBegin(GL_POINTS);
  glColor3f(0.0, 255.0, 0.0);
  glVertex3f(0.0f, 0.5f, 0.0f);
  glEnd();
}

void GraphicsWidget::initLine()
{
  glLineWidth(2.0);
  glBegin(GL_LINES);
  glColor3f(0.0, 0.0, 255.0);
  glVertex3f(-1.0f, -1.0f, 0.0f); // origin of the line
  glVertex3f(-1.0f, 1.0f, 0.0f);  // ending point of the line
  glEnd();
}

void GraphicsWidget::initTriangle()
{
  glBegin(GL_TRIANGLES);
  glColor3f(255.0, 0.0, 0.0);
  glVertex3f(-0.2f, 0.0f, 0.0f); // origin of the line
  glVertex3f(0.0f, 0.2f, 0.0f);  // ending point of the line
  glVertex3f(0.2f, 0.0f, 0.0f);
  glEnd();
}

void GraphicsWidget::initQuad()
{
  float radius = 0.5;

  glBegin(GL_QUADS);
  glColor3f(1.0, 0.0, 0.0);
  glVertex3f(-radius, -radius, radius);
  glVertex3f(radius, -radius, radius);
  glVertex3f(radius, radius, radius);
  glVertex3f(-radius, radius, radius);
  glEnd();
}

void GraphicsWidget::initHexagon()
{
  glBegin(GL_POLYGON);
  glColor3f(1.0, 0.0, 0.0);
  for (int i = 0; i < 6; ++i)
  {
    glVertex3f(
      sin(i / 6.0 * 2 * M_PI),
      cos(i / 6.0 * 2 * M_PI),
      0.0f
    );
  }
  glEnd();
}

void GraphicsWidget::initCube() {}