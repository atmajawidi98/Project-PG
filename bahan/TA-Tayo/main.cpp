/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#include "math.h"
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
void initGL()
{
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glShadeModel(GL_SMOOTH);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void timer(int value)
{
  glutPostRedisplay();
  glutTimerFunc(15, timer, 0);
}


void reshape(GLsizei width, GLsizei height)
{
  if (height == 0)
    height = 1;
  GLfloat aspect = (GLfloat)width / (GLfloat)height;
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}


float deg2Rad (float sudut) {
	return sudut * (22.0/7.0) / 180.0;
}
void Tabung(int panjang,int lebar){
 float BODY_LENGTH=panjang;
 float BODY_RADIUS=lebar;
 int SLICES=30;
 int STACKS=30;
 GLUquadric *q = gluNewQuadric();
 gluCylinder(q, BODY_RADIUS, BODY_RADIUS, BODY_LENGTH, SLICES, STACKS);
 gluDisk(q, 0, BODY_RADIUS, SLICES, STACKS); //lingkaran untuk tutup atas
 glTranslatef(0, 0, BODY_LENGTH);
 gluDisk(q, 0, BODY_RADIUS, SLICES, STACKS); //lingkaran untuk tutup bawah
}

int a = 0;
void Roda(){
  glColor3f(0,0,0); // black
  glutSolidTorus(1,3,24,24);
  glColor3f(0.191,0.164,0.164); // silver
  glTranslatef(0.0, 0.0, -0.5);
  Tabung(1,2);
  glTranslatef(0.0, 0.0, 0.1);
  glColor3f(1,1,1); // white
     glBegin(GL_POLYGON);
     glVertex3f(0.5,-0.5,0);
     glVertex3f(0,-2,0);
     glVertex3f(-0.5,-0.5,0);
     glVertex3f(-2,0,0);
     glVertex3f(-0.5,0.5,0);
     glVertex3f(0,2,0);
     glVertex3f(0.5,0.5,0);
     glVertex3f(2,0,0);
     glEnd();
}
void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glPushMatrix();
      glTranslatef(-10.0, 0.0, -45.0);
      glColor3f(1,1,0); // black
      glRotated(a,0,0,1);
      Roda();
  glPopMatrix();
  glPushMatrix();
      glTranslatef(15.0, 0.0, -45.0);
      glColor3f(1,1,0); // black
      glRotated(a,0,0,1);
      Roda();
  glPopMatrix();
  //KANAN
  glPushMatrix();
      glTranslatef(-10.0, 0.0, -55.0);
      glColor3f(1,1,0); // black
      glRotated(a,0,0,1);
      Roda();
  glPopMatrix();
  glPushMatrix();
      glTranslatef(15.0, 0.0, -55.0);
      glColor3f(1,1,0); // black
      glRotated(a,0,0,1);
      Roda();
  glPopMatrix();


  glutSwapBuffers();
  a++;
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("praktikum 1");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  initGL();
  glutTimerFunc(0, timer, 0);
  glutMainLoop();
  return 0;
}
