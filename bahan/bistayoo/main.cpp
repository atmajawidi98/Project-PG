#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "math.h"
#define PI 3.14159265
#include <stdlib.h>
float R_Z=0.0f, R_X=0.0f, R_Y=0.0f;
float T_Z=-16.0f, T_X=0.0f, T_Y=0.0f;

float Cx = 0.0f, Cy = 0.0f, Cz = 0.0f;
 float Lx = 0.0f, Ly = 0.0f, Lz = -20.0f;

 float linear[] = {0.0f, 0.3042f, -1.0f}; // Deklarasi awal vektor untuk maju
 float lateral[] = {-1.0f, 0.0f, 0.0f}; // Deklarasi awal vektor untuk gerakan ke kanan
 float vertical[] = {0.0f, 1.0f, 0.0f}; // Deklarasi awal vektor untuk gerakan naik

 void vectorMovement(float toMove[], float magnitude, float direction){
 float speedX = toMove[0]*magnitude*direction;
 float speedY = toMove[1]*magnitude*direction;
 float speedZ = toMove[2]*magnitude*direction;
 Cx += speedX;
 Cy += speedY;
 Cz += speedZ;
 Lx += speedX;
Ly += speedY;
 Lz += speedZ;
}
//end cam
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
void trotoar(){

        glBegin(GL_QUADS);
 //bangun tepi jalan kiri 1
          glColor3f(0.53, 0.207, 0.18);
          //a
          glVertex3f(-5.0f, 0.5f, -1000.0f);

          //b
          glVertex3f(-5.0f, 0.5f, 10.0f);

          //c
          glVertex3f(-5.0f, 0.0f, 10.0f);

          //d
          glVertex3f(-5.0f, 0.0f, -1000.0f);
          //bangun tepi jalan kiri 2
          glColor3f(0.53, 0.207, 0.18);
          //a
          glVertex3f(-6.0f, 0.5f, -1000.0f);

          //b
          glVertex3f(-6.0f, 0.5f, 10.0f);

          //c
          glVertex3f(-6.0f, 0.0f, 10.0f);

          //d
          glVertex3f(-6.0f, 0.0f, -1000.0f);
          //bangun tepi jalan kiri 3
          glColor3f(0.53, 0.207, 0.18);
          //a
          glVertex3f(-6.0f, 0.5f, -1000.0f);

          //b
          glVertex3f(-6.0f, 0.5f, 10.0f);

          //c
          glVertex3f(-5.0f, 0.5f, 10.0f);

          //d
          glVertex3f(-5.0f, 0.5f, -1000.0f);

        glEnd();
}

void garistengah(float km){
glBegin(GL_QUADS);
     //tengah jalan
          glColor3f(1, 1, 1);
          //a
          glVertex3f(0.3f, 0.01f, km-4);

          //b
          glVertex3f(0.3f, 0.01f, km);

          //c
          glVertex3f(-0.3f, 0.01f, km);

          //d
          glVertex3f(-0.3f, 0.01f, km-4);
        glEnd();


}
void tepitrotoar(){
glBegin(GL_QUADS);
        //tepi kiri
          glColor3f(0.125, 0.7, 0.2);
          //a
          glVertex3f(-6.0f, 0.5f, -1000.0f);

          //b
          glVertex3f(-6.0f, 0.5f, 10.0f);

          //c
          glVertex3f(-9.0f, 0.5f, 10.0f);

          //d
          glVertex3f(-9.0f, 0.5f, -1000.0f);
          glEnd();
          }
          void gedung(){
          glBegin(GL_QUADS);
        //gedung kiri
          glColor3f(0, 1, 1);
          //a
          glVertex3f(-9.0f, 10.5f, -1000.0f);

          //b
          glVertex3f(-9.0f, 10.5f, 10.0f);

          //c
          glVertex3f(-9.0f, 0.5f, 10.0f);

          //d
          glVertex3f(-9.0f, 0.5f, -1000.0f);
          glEnd();
          }

float sudut = 0;
float gerak,gerak2,depan = 0.0;
float arah1,arah2 = 1;
void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
    gluLookAt(Cx, Cy, Cz,
     Lx, Ly, Lz,
     0, 1, 0);
  glTranslatef(0.0, 0.0, -12.0);
  glRotated(17,1,0,0);
  glRotated(sudut,0,1,0);
  //glRotated(sudut,0,1,0);
  glColor3f(0.7,0,0);

        glBegin(GL_QUADS);
          glColor3f(0, 0, 1);
          //kiri

          //a
          glVertex3f(-4.0f, 1.75f, -1.85f);

          //b
          glVertex3f(-4.0f, 1.75f, 1.85f);

          //c
          glVertex3f(-4.0f, 0.0f, 1.85f);

          //d
          glVertex3f(-4.0f, 0.0f, -1.85f);

          //kiriserong
          //a
          glVertex3f(-4.0f, 1.75f, -1.85f);

          //b
          glVertex3f(-4.0f, 1.75f, 1.85f);

          //c
          glVertex3f(-3.8f, 2.0f, 1.85f);

          //d
          glVertex3f(-3.8f, 2.0f, -1.85f);

          //kanan

          //a
          glVertex3f(-2.0f, 1.75f, -1.85f);

          //b
          glVertex3f(-2.0f, 1.75f, 1.85f);

          //c
          glVertex3f(-2.0f, 0.0f, 1.85f);

          //d
          glVertex3f(-2.0f, 0.0f, -1.85f);

          //kanan serong
          //a
          glVertex3f(-2.0f, 1.75f, -1.85f);

          //b
          glVertex3f(-2.0f, 1.75f, 1.85f);

          //c
          glVertex3f(-2.2f, 2.0f, 1.85f);

          //d
          glVertex3f(-2.2f, 2.0, -1.85f);

          //tutup
          //a
          glVertex3f(-2.2f, 2.0f, -1.85f);

          //b
          glVertex3f(-2.2f, 2.0f, 1.85f);

          //c
          glVertex3f(-3.8f, 2.0f, 1.85f);

          //d
          glVertex3f(-3.8f, 2.0f, -1.85f);

          //belakang
          //a
          glVertex3f(-2.2f, 1.75f, 2.0f);

          //b
          glVertex3f(-2.2f, 0.0f, 2.0f);

          //c
          glVertex3f(-3.8f, 0.0f, 2.0f);

          //d
          glVertex3f(-3.8f, 1.75f, 2.0f);
          //belakang serong kiri
          //a
          glVertex3f(-4.0f, 1.75f, 1.85f);

          //b
          glVertex3f(-4.0f, 0.0f, 1.85f);

          //c
          glVertex3f(-3.8f, 0.0f, 2.0f);

          //d
          glVertex3f(-3.8f, 1.75f, 2.0f);
          //belakang serong kanan
          //a
          glVertex3f(-2.2f, 1.75f, 2.0f);

          //b
          glVertex3f(-2.2f, 0.0f, 2.0f);

          //c
          glVertex3f(-2.0f, 0.0f, 1.85f);

          //d
          glVertex3f(-2.0f, 1.75f, 1.85f);

          //belakang serong atas
          //a
          glVertex3f(-2.2f, 1.75f, 2.0f);

          //b
          glVertex3f(-2.2f, 2.0f, 1.85f);

          //c
          glVertex3f(-3.8f, 2.0f, 1.85f);

          //d
          glVertex3f(-3.8f, 1.75f, 2.0f);

          //belakang tutup kiri
          //a
          glVertex3f(-2.2f, 1.75f, 2.0f);
          glVertex3f(-2.2f, 1.75f, 2.0f);

          glVertex3f(-2.2f, 2.0f, 1.85f);
          glVertex3f(-2.0f, 1.75f, 1.85f);

          //belakang tutup atas
          //a
          glVertex3f(-3.8f, 1.75f, 2.0f);
          glVertex3f(-3.8f, 1.75f, 2.0f);

          glVertex3f(-3.8f, 2.0f, 1.85f);
          glVertex3f(-4.0f, 1.75f, 1.85f);

          //depan

          //a
          glVertex3f(-2.2f, 1.75f, -2.0f);

          //b
          glVertex3f(-2.2f, 0.0f, -2.0f);

          //c
          glVertex3f(-3.8f, 0.0f, -2.0f);

          //d
          glVertex3f(-3.8f, 1.75f, -2.0f);


          //depan serong kiri
          //a
          glVertex3f(-4.0f, 1.75f, -1.85f);

          //b
          glVertex3f(-4.0f, 0.0f, -1.85f);

          //c
          glVertex3f(-3.8f, 0.0f, -2.0f);

          //d
          glVertex3f(-3.8f, 1.75f, -2.0f);

          //depan SERONG KANAN

          //a
          glVertex3f(-2.2f, 1.75f, -2.0f);

          //b
          glVertex3f(-2.2f, 0.0f, -2.0f);

          //c
          glVertex3f(-2.0f, 0.0f, -1.85f);

          //d
          glVertex3f(-2.0f, 1.75f, -1.85f);

          //depan serong atas

          //a
          glVertex3f(-2.2f, 1.75f, -2.0f);

          //b
          glVertex3f(-2.2f, 2.0f, -1.85f);

          //c
          glVertex3f(-3.8f, 2.0f, -1.85f);

          //d
          glVertex3f(-3.8f, 1.75f, -2.0f);

          //tutup depan kiri

          //a
          glVertex3f(-4.0f, 1.75f, -1.85f);
          glVertex3f(-4.0f, 1.75f, -1.85f);

          glVertex3f(-3.8f, 1.75f, -2.0);

          glVertex3f(-3.8f, 2.0f, -1.85f);

          //tutup depan kanan

          //a
          glVertex3f(-2.2f, 1.75f, -2.0f);
          glVertex3f(-2.2f, 1.75f, -2.0f);


          glVertex3f(-2.2f, 2.0f, -1.85f);
          glVertex3f(-2.0f, 1.75f, -1.85f);


          //kaca kanan
          glColor3f(0, 0, 0);
          //a
          glVertex3f(-1.99f, 1.50f, 0.9f);

          //b
          glVertex3f(-1.99f, 1.50f, 1.70f);

          //c
          glVertex3f(-1.99f, 0.75f, 1.70f);

          //d
          glVertex3f(-1.99f, 0.75f, 0.9f);

          //a
          glVertex3f(-1.99f, 1.50f, -0.1f);

          //b
          glVertex3f(-1.99f, 1.50f, 0.7f);

          //c
          glVertex3f(-1.99f, 0.75f, 0.7f);

          //d
          glVertex3f(-1.99f, 0.75f, -0.1f);

          //a
          glVertex3f(-1.99f, 1.50f, -0.3f);

          //b
          glVertex3f(-1.99f, 1.50f, -1.1f);

          //c
          glVertex3f(-1.99f, 0.75f, -1.1f);

          //d
          glVertex3f(-1.99f, 0.75f, -0.3f);


          //kaca kiri
          glColor3f(0, 0, 0);
          //a
          glVertex3f(-4.01f, 1.50f, 0.9f);

          //b
          glVertex3f(-4.01f, 1.50f, 1.70f);

          //c
          glVertex3f(-4.01f, 0.75f, 1.70f);

          //d
          glVertex3f(-4.01f, 0.75f, 0.9f);

          //a
          glVertex3f(-4.01f, 1.50f, -0.1f);

          //b
          glVertex3f(-4.01f, 1.50f, 0.7f);

          //c
          glVertex3f(-4.01f, 0.75f, 0.7f);

          //d
          glVertex3f(-4.01f, 0.75f, -0.1f);

          //a
          glVertex3f(-4.01f, 1.50f, -0.4f);

          //b
          glVertex3f(-4.01f, 1.50f, -1.3f);

          //c
          glVertex3f(-4.01f, 0.0f, -1.3f);

          //d
          glVertex3f(-4.01f, 0.0f, -0.4f);

          //kaca belakang
          //a
          glVertex3f(-2.2f, 1.50f, 2.01f);

          //b
          glVertex3f(-2.2f, 0.75f, 2.01f);

          //c
          glVertex3f(-3.8f, 0.75f, 2.01f);

          //d
          glVertex3f(-3.8f, 1.50f, 2.01f);

          //kaca depan
          //a
          glVertex3f(-2.2f, 1.50f, -2.01f);

          //b
          glVertex3f(-2.2f, 0.75f, -2.01f);

          //c
          glVertex3f(-3.8f, 0.75f, -2.01f);

          //d
          glVertex3f(-3.8f, 1.50f, -2.01f);
        glEnd();


sudut++;
depan=depan+0.1;
  glFlush();
  glutSwapBuffers();
}


 void keyFunction(unsigned char key, int x, int y){
 // Agar fungsi ini bekerja, pastikan CapsLock menyala
 switch(key){
 case 83: // huruf S
     vectorMovement(linear, 1.0f, -1.0f);
 break;
 case 65: // huruf A
     vectorMovement(lateral, 1.0f, -1.0f);
 break;
 case 87: // W
     vectorMovement(linear, 1.0f, 1.0f);
 break;
 case 68: // D
     vectorMovement(lateral, 1.0f, 1.0f);
 break;
 case 67: // C
     if((Cx == 3.0f)&&(Cy == 10.0f)&&(Cz == -5.0f)&&(Lx == 0.0f)&&(Ly == -80.0f)&&(Lz == 0.0f) ){
         Cx = 5.0f;
         Cy = 0.0f;
         Cz = 5.0f;
         Lx = 0.0f;
         Ly = 0.0f;
         Lz = -20.0f;
     }else{
         Cx = 3.0f;
         Cy = 10.0f;
         Cz = -5.0f;
         Lx = 0.0f;
         Ly = -80.0f;
         Lz = 0.0f;
     }

 break;
     }
 }

void keyControl(int k, int x, int y) {
 switch(k) {
 case GLUT_KEY_UP: // tombol panah atas
 vectorMovement(vertical, 2.0f, -1.0f);
 break;
 case GLUT_KEY_DOWN: // tombol panah atas
 vectorMovement(vertical, 2.0f, 1.0f);
 break;
 }
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
  glutSpecialFunc(keyControl);
 glutKeyboardFunc(keyFunction);
  initGL();
  glutTimerFunc(0, timer, 0);
  glutMainLoop();
   glClearColor(0,1,1,1);


    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
  return 0;
}
