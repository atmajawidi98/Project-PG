#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "math.h"
#define PI 3.14159265
float R_Z=0.0f, R_X=0.0f, R_Y=0.0f;
float T_Z=-16.0f, T_X=0.0f, T_Y=0.0f;
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

float degreeToRadian(float degree) {
  // 360 degree = 2 pi radian
  //   1 degree = 2 pi / 360 radian
  //   1 degree = pi / 180 radian
  return (degree * PI) / 180.0;
}

void mobil(){
    glBegin(GL_QUADS);
          //alas
          glColor3f(1, 1, 0);
          //a
          glVertex3f(-2.0f, 0.0f, -2.0f);

          //b
          glVertex3f(-2.0f, 0.0f, 2.0f);

          //c
          glVertex3f(-4.0f, 0.0f, 2.0f);

          //d
          glVertex3f(-4.0f, 0.0f, -2.0f);
          //kiri
          //a
          glVertex3f(-4.0f, 2.0f, -2.0f);

          //b
          glVertex3f(-4.0f, 2.0f, 2.0f);

          //c
          glVertex3f(-4.0f, 0.0f, 2.0f);

          //d
          glVertex3f(-4.0f, 0.0f, -2.0f);
          //kanan
          //a
          glVertex3f(-2.0f, 2.0f, -2.0f);

          //b
          glVertex3f(-2.0f, 2.0f, 2.0f);

          //c
          glVertex3f(-2.0f, 0.0f, 2.0f);

          //d
          glVertex3f(-2.0f, 0.0f, -2.0f);
          //tutup
          //a
          glVertex3f(-2.0f, 2.0f, -2.0f);

          //b
          glVertex3f(-2.0f, 2.0f, 2.0f);

          //c
          glVertex3f(-4.0f, 2.0f, 2.0f);

          //d
          glVertex3f(-4.0f, 2.0f, -2.0f);

          //belakang
          //a
          glVertex3f(-2.0f, 2.0f, 2.0f);

          //b
          glVertex3f(-2.0f, 0.0f, 2.0f);

          //c
          glVertex3f(-4.0f, 0.0f, 2.0f);

          //d
          glVertex3f(-4.0f, 2.0f, 2.0f);

          //depan
          //a
          glVertex3f(-2.0f, 2.0f, -2.0f);

          //b
          glVertex3f(-2.0f, 0.0f, -2.0f);

          //c
          glVertex3f(-4.0f, 0.0f, -2.0f);

          //d
          glVertex3f(-4.0f, 2.0f, -2.0f);

        glEnd();
}



float sudut = 0;
float gerak = 0.0;
float arah1 = 1;
void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glTranslatef(0.0, 0.0, -12.0);
  glRotated(20,1,0,0);
  //glRotated(sudut,0,1,0);
  glColor3f(0.7,0,0);

        glBegin(GL_QUADS);
          //bangun 1
          glColor3f(1, 0, 0);
          //a
          glVertex3f(5.0f, 0.0f, -10.0f);

          //b
          glVertex3f(5.0f, 0.0f, 10.0f);

          //c
          glVertex3f(-5.0f, 0.0f, 10.0f);

          //d
          glVertex3f(-5.0f, 0.0f, -10.0f);

        glEnd();
            if(arah1 < 279 ){
                    if(arah1 < 141){
                        gerak = gerak +0.04;
                    }
                    else if(arah1 > 140){
                        gerak = gerak -0.04;
                    }
            }
            else if(arah1 == 280){
                arah1 = 0;
            }
        glTranslatef(gerak, 0, 0);
        //mobil
        mobil();

sudut++;
arah1++;
  glFlush();
  glutSwapBuffers();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("coba");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  initGL();
  glutTimerFunc(0, timer, 0);
  glutMainLoop();
   glClearColor(0,1,1,1);


    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
  return 0;
}
