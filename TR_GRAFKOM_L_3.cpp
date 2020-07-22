//Juan Dedrick Toding Rundupadang 672018353
//Indra Yunanto 672018019
//Glorivan Tandiarang 672018415
#include <windows.h>
#include <gl/glut.h>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <cmath>
#include <iostream>


#define RATIO 1.200
#define WW 100
#define WH (WW/RATIO)
#define HALFX ((int)(WW/2))
#define HALFY ((int)(WH/2))
#define deltat .001
int WindowWidth;
int WindowHeight;
void init(void);
void tampil(void);
void keyboard(unsigned,char,int,int);
void ukuran(int,int);
void mouse(int button,int state,int x,int y);
void mouseMotion(int x,int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
double rx = 1.0;
double ry = 1.0;
GLUquadricObj *qobj;
int is_depth;


void myinit()
{

    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(3.0);
    glLineWidth(4.0);
}
void InitGT(){
    glPushMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-HALFX, HALFX, -HALFY, HALFY);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0, 0, 0, 0);

    glEnableClientState(GL_VERTEX_ARRAY);

    glEnableClientState(GL_COLOR_ARRAY);
    glShadeModel(GL_SMOOTH);
    glViewport(0, 0, WindowWidth, WindowHeight);
    glPopMatrix();

    myinit();
}
void skor(void){

    //depan
    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(-14,-5,2);
    glVertex3f(-14,15,2);
    glVertex3f(14,15,2);
    glVertex3f(14,-5,2);
    glEnd();
    //layar
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-13,-4,2.1);
    glVertex3f(-13,14,2.1);
    glVertex3f(13,14,2.1);
    glVertex3f(13,-4,2.1);
    glEnd();
    //titik
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-0.5,0,2.2);
    glVertex3f(-0.5,3,2.2);
    glVertex3f(1,3,2.2);
    glVertex3f(1,0,2.2);
    glEnd();
    //titik
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-0.5,8,2.2);
    glVertex3f(-0.5,11,2.2);
    glVertex3f(1,11,2.2);
    glVertex3f(1,8,2.2);
    glEnd();
    // angka1
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(6.5,2,2.2);
    glVertex3f(6.5,8,2.2);
    glVertex3f(4.6,8,2.2);
    glVertex3f(6.5,9.7,2.2);
    glVertex3f(8.1,9.7,2.2);
    glVertex3f(8.1,2,2.2);
    glVertex3f(6.5,2,2.2);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(-14,-5,-1);
    glVertex3f(-14,15,-1);
    glVertex3f(14,15,-1);
    glVertex3f(14,-5,-1);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(14,15,2);
    glVertex3f(14,-5,2);
    glVertex3f(14,-5,-1);
    glVertex3f(14,15,-1);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(-14,15,2);
    glVertex3f(-14,-5,2);
    glVertex3f(-14,-5,-1);
    glVertex3f(-14,15,-1);
    glEnd();
    //atas
        glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(-14,15,2);
    glVertex3f(14,15,2);
    glVertex3f(14,15,-1);
    glVertex3f(-14,15,-1);
    glEnd();
    //bawah
    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(-14,-5,2);
    glVertex3f(14,-5,2);
    glVertex3f(14,-5,-1);
    glVertex3f(-14,-5,-1);
    glEnd();
    //kaki kiri
    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(-10.0, -15.0, 1.0);
    glRotatef(-90.0,1.0,0.0,0.0);
    gluCylinder(qobj, 1, 0, 30, 45, 15);
    glPopMatrix();
    glEnd();
    //kaki kanan
    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(10.0, -15.0, 1.0);
    glRotatef(-90.0,1.0,0.0,0.0);
    gluCylinder(qobj, 1, 0, 30, 45, 15);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glTranslatef(-7.0, 3.0, 2.2);
    glRotatef(0.0,0.0,0.0,0.0);
    glLineWidth(4.0);
    float StartShape[24][2] = {
            {-1,7},{0,7},{0.8,7},{0.8,6},{0.8,5.2},{0.8,4.4},{0.8,3.4},{0.8,2.2},{0.8,1},
            {0.8,-0.2},{0.8,-1},{0,-1},{-0.8,-1},{-0.8,-0.2},{-0.8,1},{-0.8,2.2},
            {-0.8,3.4},{-0.8,4.4},{-0.8,5},{-1.8,5},{-2.8,5},{-2.3,5.6},{-1.7,6.2},{-1,7},
            };
    float EndShape[24][2] = {
            {-2.65,5.75},{-0.93,6.78},{1.22,6.78},{2.64,5.8},{3.1,4.08},{2.42,2.47},{0.85,1.5},{-1.06,1.1},
            {-1.06,0.3},{2.7,0.3},{2.7,-0.96},{0.04,-0.96},{-2.32,-0.9},{-2.3,2.04},{-0.42,2.3},{1.2,2.95},
            {1.84,3.97},{1.47,5.1},{0.3,5.65},{-1,5.43},{-1.73,4.22},{-3,4.26},{-2.65,5.75}};

    float IntermediateShape[24][2];
    float VertexColors[24][3]={
            {0,0,0}};
    static float Tween = 0.0 - deltat;



    if (Tween<1)
    {
        Tween += deltat;
    }

    for (int Vtx = 0; Vtx<24; Vtx++)
    {
        IntermediateShape[Vtx][0] = (1.0 - Tween)*StartShape[Vtx][0]
        + Tween*EndShape[Vtx][0];
        IntermediateShape[Vtx][1] = (1.0 - Tween)*StartShape[Vtx][1]
        + Tween*EndShape[Vtx][1];
    }

    glVertexPointer(2, GL_FLOAT, 0, IntermediateShape);
    glColorPointer(3, GL_FLOAT, 0, VertexColors);


    for (int i = 0; i < 1000000; i++);
    glDrawArrays(GL_LINE_LOOP, 0, 21);
    glutPostRedisplay();
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glPopMatrix();
}
void corner(void)
{
    //dinding depan
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(10,5,1);
    glVertex3f(10,15,1);
    glVertex3f(0,15,1);
    glVertex3f(0,5,1);
    glEnd();
    //tiang korner
    glPushMatrix();
    glColor3f(1.0,1.0,0.9);
    glTranslatef(0.0, -15.0, 1.0);
    glRotatef(-90.0,1.0,0.0,0.0);
    gluCylinder(qobj, 0.50, 0.50, 30, 45, 15);
    glPopMatrix();
    glEnd();
    //tiang korner
    glPushMatrix();
    glColor3f(0.8,0.0,0.2);
    glTranslatef(0.0, 5.0, 1.0);
    glRotatef(-90.0,1.0,0.0,0.0);
    gluCylinder(qobj, 0.51, 0.51, 10, 45, 15);
    glPopMatrix();
    glEnd();
    //tiang korner
    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(0.0, 2.0, 1.0);
    glRotatef(-90.0,1.0,0.0,0.0);
    gluCylinder(qobj, 0.52, 0.52, 3, 45, 15);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glPopMatrix();

}
void tv(void){
    //depan
    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(-14,-10,2);
    glVertex3f(-14,10,2);
    glVertex3f(14,10,2);
    glVertex3f(14,-10,2);
    glEnd();
    //layar
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-12,-8,2.1);
    glVertex3f(-12,9,2.1);
    glVertex3f(12,9,2.1);
    glVertex3f(12,-8,2.1);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(-14,-10,-2);
    glVertex3f(-14,10,-2);
    glVertex3f(14,10,-2);
    glVertex3f(14,-10,-2);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(14,10,2);
    glVertex3f(14,-10,2);
    glVertex3f(14,-10,-2);
    glVertex3f(14,10,-2);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(-14,10,2);
    glVertex3f(-14,-10,2);
    glVertex3f(-14,-10,-2);
    glVertex3f(-14,10,-2);
    glEnd();
    //atas
        glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(-14,10,2);
    glVertex3f(14,10,2);
    glVertex3f(14,10,-2);
    glVertex3f(-14,10,-2);
    glEnd();
    //bawah
    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(-14,-10,2);
    glVertex3f(14,-10,2);
    glVertex3f(14,-10,-2);
    glVertex3f(-14,-10,-2);
    glEnd();

    glPushMatrix();
    glPopMatrix();


}
void gawang(void)
{
    //dinding belakang
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-40,25,-13);
    glVertex3f(40,25,-13);
    glEnd();
    //dinding belakang
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-40,20,-14);
    glVertex3f(40,20,-14);
    glEnd();
    //dinding belakang
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-40,15,-15);
    glVertex3f(40,15,-15);
    glEnd();
    //dinding belakang
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-40,10,-16);
    glVertex3f(40,10,-16);
    glEnd();
    //dinding belakang
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-40,5,-17);
    glVertex3f(40,5,-17);
    glEnd();
    //dinding belakang
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-40,0,-18);
    glVertex3f(40,0,-18);
    glEnd();
    //dinding belakang
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-40,-5,-19);
    glVertex3f(40,-5,-19);
    glEnd();
    //dinding belakang
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-40,-10,-20);
    glVertex3f(40,-10,-20);
    glEnd();
    //dinding belakang
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-40,-15,-21);
    glVertex3f(40,-15,-21);
    glEnd();
    //dinding belakang
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(35,29,-13);
    glVertex3f(35,-20,-22);
    glEnd();
    //dinding belakang
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(30,29,-13);
    glVertex3f(30,-20,-22);
    glEnd();
    //dinding belakang
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(25,29,-13);
    glVertex3f(25,-20,-22);
    glEnd();
    //dinding belakang
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(20,29,-13);
    glVertex3f(20,-20,-22);
    glEnd();
    //dinding belakang
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(15,29,-13);
    glVertex3f(15,-20,-22);
    glEnd();
    //dinding belakang
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(10,29,-13);
    glVertex3f(10,-20,-22);
    glEnd();
    //dinding belakang
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(5,29,-13);
    glVertex3f(5,-20,-22);
    glEnd();
    //dinding belakang
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(0,29,-13);
    glVertex3f(0,-20,-22);
    glEnd();
    //dinding belakang
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-5,29,-13);
    glVertex3f(-5,-20,-22);
    glEnd();
    //dinding belakang
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-10,29,-13);
    glVertex3f(-10,-20,-22);
    glEnd();
    //dinding belakang
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-15,29,-13);
    glVertex3f(-15,-20,-22);
    glEnd();
    //dinding belakang
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-20,29,-13);
    glVertex3f(-20,-20,-22);
    glEnd();
    //dinding belakang
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-25,29,-13);
    glVertex3f(-25,-20,-22);
    glEnd();
    //dinding belakang
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-30,29,-13);
    glVertex3f(-30,-20,-22);
    glEnd();
    //dinding belakang
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-35,29,-13);
    glVertex3f(-35,-20,-22);
    glEnd();
    //dingding kanan
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(40,29,-5);
    glVertex3f(40,-20,-5);
    glEnd();
    //dingding kanan
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(40,29,-10);
    glVertex3f(40,-20,-10);
    glEnd();
    //dingding kanan
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(40,24,-15);
    glVertex3f(40,-20,-15);
    glEnd();
    //dingding kanan
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(40,-10,-20);
    glVertex3f(40,-20,-20);
    glEnd();
    //dingding kanan
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(40,25,-14);
    glVertex3f(40,25,0);
    glEnd();
    //dingding kanan
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(40,20,-15);
    glVertex3f(40,20,0);
    glEnd();
    //dingding kanan
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(40,15,-16);
    glVertex3f(40,15,0);
    glEnd();
    //dingding kanan
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(40,10,-17);
    glVertex3f(40,10,0);
    glEnd();
    //dingding kanan
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(40,5,-18);
    glVertex3f(40,5,0);
    glEnd();
    //dingding kanan
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(40,0,-19);
    glVertex3f(40,0,0);
    glEnd();
    //dingding kanan
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(40,-5,-20);
    glVertex3f(40,-5,0);
    glEnd();
    //dingding kanan
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(40,-15,-20);
    glVertex3f(40,-15,0);
    glEnd();
    //dingding kanan
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(40,-10,-21);
    glVertex3f(40,-10,0);
    glEnd();
    //dingding kiri
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-40,29,-5);
    glVertex3f(-40,-20,-5);
    glEnd();
    //dingding kiri
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-40,29,-10);
    glVertex3f(-40,-20,-10);
    glEnd();
    //dingding kiri
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-40,24,-15);
    glVertex3f(-40,-20,-15);
    glEnd();
    //dingding kiri
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-40,-10,-20);
    glVertex3f(-40,-20,-20);
    glEnd();
    //dingding kiri
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-40,25,-14);
    glVertex3f(-40,25,0);
    glEnd();
    //dingding kiri
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-40,20,-15);
    glVertex3f(-40,20,0);
    glEnd();
    //dingding kiri
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-40,15,-16);
    glVertex3f(-40,15,0);
    glEnd();
    //dingding kiri
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-40,10,-17);
    glVertex3f(-40,10,0);
    glEnd();
    //dingding kiri
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-40,5,-18);
    glVertex3f(-40,5,0);
    glEnd();
    //dingding kiri
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-40,0,-19);
    glVertex3f(-40,0,0);
    glEnd();
    //dingding kiri
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-40,-5,-20);
    glVertex3f(-40,-5,0);
    glEnd();
    //dingding kiri
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-40,-15,-20);
    glVertex3f(-40,-15,0);
    glEnd();
    //dingding kiri
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-40,-10,-21);
    glVertex3f(-40,-10,0);
    glEnd();
    //jaring atas
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(35,29,-13);
    glVertex3f(35,29,0);
    glEnd();
    //jaring atas
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(30,29,-13);
    glVertex3f(30,29,0);
    glEnd();
    //jaring atas
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(25,29,-13);
    glVertex3f(25,29,0);
    glEnd();
    //jaring atas
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(20,29,-13);
    glVertex3f(20,29,0);
    glEnd();
    //jaring atas
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(15,29,-13);
    glVertex3f(15,29,0);
    glEnd();
    //jaring atas
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(10,29,-13);
    glVertex3f(10,29,0);
    glEnd();
    //jaring atas
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(5,29,-13);
    glVertex3f(5,29,0);
    glEnd();
    //jaring atas
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(0,29,-13);
    glVertex3f(0,29,0);
    glEnd();
    //jaring atas
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-5,29,-13);
    glVertex3f(-5,29,0);
    glEnd();
    //jaring atas
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-10,29,-13);
    glVertex3f(-10,29,0);
    glEnd();
    //jaring atas
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-15,29,-13);
    glVertex3f(-15,29,0);
    glEnd();
    //jaring atas
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-20,29,-13);
    glVertex3f(-20,29,0);
    glEnd();
    //jaring atas
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-25,29,-13);
    glVertex3f(-25,29,0);
    glEnd();
    //jaring atas
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-30,29,-13);
    glVertex3f(-30,29,0);
    glEnd();
    //jaring atas
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-35,29,-13);
    glVertex3f(-35,29,0);
    glEnd();
    //jaring atas
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(40,29,-5);
    glVertex3f(-40,29,-5);
    glEnd();
    //jaring atas
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(40,29,-10);
    glVertex3f(-40,29,-10);
    glEnd();

    //tiang gawang atas
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-40.0, 29.0, 0.0);
    glRotatef(120,90,90,90);
    gluCylinder(qobj, 1, 1, 80, 45, 15);
    glPopMatrix();
    glEnd();
    //tiang gawang atas
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-40.0, 29.0, -13.0);
    glRotatef(120,90,90,90);
    gluCylinder(qobj, 1, 1, 80, 45, 15);
    glPopMatrix();
    glEnd();
    //tiang gawang bawah
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-40.0, -20.0, -22.0);
    glRotatef(120,90,90,90);
    gluCylinder(qobj, 1, 1, 80, 45, 15);
    glPopMatrix();
    glEnd();
    //tiang gawang kiri
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-40.0, -20.0, 0.0);
    glRotatef(-90.0,1.0,0.0,0.0);
    gluCylinder(qobj, 1, 1, 50, 45, 15);
    glPopMatrix();
    glEnd();
    //tiang gawang kiri 1
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-40.0, 29.0, -14);
    glRotatef(0.0,0.0,0.0,0.0);
    gluCylinder(qobj, 1, 1, 15, 45, 15);
    glPopMatrix();
    glEnd();
    //tiang gawang kiri 2
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-40.0, -20.0, -22.0);
    glRotatef(-80.0,1.0,0.0,0.0);
    gluCylinder(qobj, 1, 1, 50, 45, 15);
    glPopMatrix();
    glEnd();
    //tiang gawang kiri 3
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-40.0, -20.0, -22);
    glRotatef(0.0,0.0,0.0,0.0);
    gluCylinder(qobj, 1, 1, 23, 45, 15);
    glPopMatrix();
    glEnd();
    //tiang gawang kanan
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(40.0, -20.0, 0.0);
    glRotatef(-90.0,1.0,0.0,0.0);
    gluCylinder(qobj, 1, 1, 50, 45, 15);
    glPopMatrix();
    glEnd();
    //tiang gawang kanan 1
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(40.0, 29.0, -14);
    glRotatef(0.0,0.0,0.0,0.0);
    gluCylinder(qobj, 1, 1, 15, 45, 15);
    glPopMatrix();
    glEnd();
    //tiang gawang kanan 2
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(40.0, -20.0, -22.0);
    glRotatef(-80.0,1.0,0.0,0.0);
    gluCylinder(qobj, 1, 1, 50, 45, 15);
    glPopMatrix();
    glEnd();
    //tiang gawang kanan 1
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(40.0, -20.0, -22);
    glRotatef(0.0,0.0,0.0,0.0);
    gluCylinder(qobj, 1, 1, 23, 45, 15);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glPopMatrix();

}
void potongan (void)
{
    float a1x=50, a1y=50, a2x=50, a2y=200, a3x=100, a3y=50, a4x=100, a4y=200, b1x=150, b1y=200, b2x=150, b2y=50, b3x=200, b3y=200, b4x=200, b4y=50,
    Ma1b1, Ma2b2, Ma3b3, Ma4b4, Ca1b1, Ca2b2, Ca3b3, Ca4b4, pa, pb, pc, pd, pe, pf, pg, ph;
    glClear(GL_COLOR_BUFFER_BIT);


    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(a1x, a1y);
    glVertex2f(b1x, b1y);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(a2x, a2y);
    glVertex2f(b2x, b2y);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(a3x, a3y);
    glVertex2f(b3x, b3y);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(a4x, a4y);
    glVertex2f(b4x, b4y);
    glEnd();


//Rumus perpotongang
    Ma1b1=(b1y-a1y)/(b1x-a1x);
    Ma2b2=(b2y-a2y)/(b2x-a2x);
    Ma3b3=(b3y-a3y)/(b3x-a3x);
    Ma4b4=(b4y-a4y)/(b4x-a4x);
    Ca1b1=a1y-(a1x*Ma1b1);
    Ca2b2=a2y-(a2x*Ma2b2);
    Ca3b3=a3y-(a3x*Ma3b3);
    Ca4b4=a4y-(a4x*Ma4b4);

//Titik potong
    pa=(Ca2b2-Ca1b1)/(Ma1b1-Ma2b2);
    pb=(Ma1b1*pa)+Ca1b1;
    pc=(Ca4b4-Ca1b1)/(Ma1b1-Ma4b4);
    pd=(Ma1b1*pc)+Ca1b1;
    pe=(Ca3b3-Ca2b2)/(Ma2b2-Ma3b3);
    pf=(Ma2b2*pe)+Ca2b2;
    pg=(Ca4b4-Ca3b3)/(Ma3b3-Ma4b4);
    ph=(Ma3b3*pg)+Ca3b3;

//hasil
    glBegin(GL_POINTS);
    glColor3f(0,0,0);
    glVertex2f(pa,pb);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(0,0,0);
    glVertex2f(pc,pd);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(0,0,0);
    glVertex2f(pe,pf);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(0,0,0);
    glVertex2f(pg,ph);
    glEnd();


    glFlush();
}

void segitiga()
{
    glPushMatrix();
    glTranslatef(-0.5,0,0);
    //segitiga atas1........................
    glPushMatrix();
    glTranslatef(17,16,-3.5);
    glRotatef(45,0,0,45);
    glScalef(0.05,3.9,0.05);
    //depan
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-10,-10,10);
    glVertex3f(-10,10,10);
    glVertex3f(10,10,10);
    glVertex3f(10,-10,10);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.1,0.5,0.9);
    glVertex3f(-10,-10,-10);
    glVertex3f(-10,10,-10);
    glVertex3f(10,10,-10);
    glVertex3f(10,-10,-10);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(1.3,1.3,1.3);
    glVertex3f(10,10,10);
    glVertex3f(10,-10,10);
    glVertex3f(10,-10,-10);
    glVertex3f(10,10,-10);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-10,10,10);
    glVertex3f(-10,-10,10);
    glVertex3f(-10,-10,-10);
    glVertex3f(-10,10,-10);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(1.3,1.3,1.3);
    glVertex3f(-10,10,10);
    glVertex3f(10,10,10);
    glVertex3f(10,10,-10);
    glVertex3f(-10,10,-10);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(1.3,1.3,1.3);
    glVertex3f(-10,-10,10);
    glVertex3f(10,-10,10);
    glVertex3f(10,-10,-10);
    glVertex3f(-10,-10,-10);
    glEnd();
    glPopMatrix();

//segitiga atas1.2........................
    glPushMatrix();
    glTranslatef(18.1,17,-3.5);
    glRotatef(45,0,0,45);
    glScalef(0.05,3.9,0.05);
    //depan
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-10,-10,10);
    glVertex3f(-10,10,10);
    glVertex3f(10,10,10);
    glVertex3f(10,-10,10);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.1,0.5,0.9);
    glVertex3f(-10,-10,-10);
    glVertex3f(-10,10,-10);
    glVertex3f(10,10,-10);
    glVertex3f(10,-10,-10);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(1.3,1.3,1.3);
    glVertex3f(10,10,10);
    glVertex3f(10,-10,10);
    glVertex3f(10,-10,-10);
    glVertex3f(10,10,-10);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-10,10,10);
    glVertex3f(-10,-10,10);
    glVertex3f(-10,-10,-10);
    glVertex3f(-10,10,-10);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(1.3,1.3,1.3);
    glVertex3f(-10,10,10);
    glVertex3f(10,10,10);
    glVertex3f(10,10,-10);
    glVertex3f(-10,10,-10);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(1.3,1.3,1.3);
    glVertex3f(-10,-10,10);
    glVertex3f(10,-10,10);
    glVertex3f(10,-10,-10);
    glVertex3f(-10,-10,-10);
    glEnd();
    glPopMatrix();

//segitiga atas1.3........................
    glPushMatrix();
    glTranslatef(17.5,16.5,-4.9);
    glRotatef(45,0,0,45);
    glScalef(0.05,3.9,0.05);
    //depan
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-10,-10,10);
    glVertex3f(-10,10,10);
    glVertex3f(10,10,10);
    glVertex3f(10,-10,10);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.1,0.5,0.9);
    glVertex3f(-10,-10,-10);
    glVertex3f(-10,10,-10);
    glVertex3f(10,10,-10);
    glVertex3f(10,-10,-10);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(1.3,1.3,1.3);
    glVertex3f(10,10,10);
    glVertex3f(10,-10,10);
    glVertex3f(10,-10,-10);
    glVertex3f(10,10,-10);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-10,10,10);
    glVertex3f(-10,-10,10);
    glVertex3f(-10,-10,-10);
    glVertex3f(-10,10,-10);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(1.3,1.3,1.3);
    glVertex3f(-10,10,10);
    glVertex3f(10,10,10);
    glVertex3f(10,10,-10);
    glVertex3f(-10,10,-10);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(1.3,1.3,1.3);
    glVertex3f(-10,-10,10);
    glVertex3f(10,-10,10);
    glVertex3f(10,-10,-10);
    glVertex3f(-10,-10,-10);
    glEnd();
    glPopMatrix();
    glPopMatrix();


}
void kotak()
{
//kubus1........................
    glPushMatrix();
    glTranslatef(48.5,0,9.5);
    glRotatef(0,0,0,0);
    glScalef(0.15,1.5,0.35);
    //depan
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-10,-10,10);
    glVertex3f(-10,10,10);
    glVertex3f(10,10,10);
    glVertex3f(10,-10,10);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.1,0.5,0.9);
    glVertex3f(-10,-10,-10);
    glVertex3f(-10,10,-10);
    glVertex3f(10,10,-10);
    glVertex3f(10,-10,-10);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(1.3,1.3,1.3);
    glVertex3f(10,10,10);
    glVertex3f(10,-10,10);
    glVertex3f(10,-10,-10);
    glVertex3f(10,10,-10);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-10,10,10);
    glVertex3f(-10,-10,10);
    glVertex3f(-10,-10,-10);
    glVertex3f(-10,10,-10);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(1.3,1.3,1.3);
    glVertex3f(-10,10,10);
    glVertex3f(10,10,10);
    glVertex3f(10,10,-10);
    glVertex3f(-10,10,-10);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(1.3,1.3,1.3);
    glVertex3f(-10,-10,10);
    glVertex3f(10,-10,10);
    glVertex3f(10,-10,-10);
    glVertex3f(-10,-10,-10);
    glEnd();
    glPopMatrix();

//kubus1 entrance........................
    glPushMatrix();
    glTranslatef(49,0,9.5);
    glRotatef(0,0,0,0);
    glScalef(0.15,0.5,0.35);
    //depan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-10,-10,10);
    glVertex3f(-10,10,10);
    glVertex3f(10,10,10);
    glVertex3f(10,-10,10);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-10,-10,-10);
    glVertex3f(-10,10,-10);
    glVertex3f(10,10,-10);
    glVertex3f(10,-10,-10);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(10,10,10);
    glVertex3f(10,-10,10);
    glVertex3f(10,-10,-10);
    glVertex3f(10,10,-10);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-10,10,10);
    glVertex3f(-10,-10,10);
    glVertex3f(-10,-10,-10);
    glVertex3f(-10,10,-10);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-10,10,10);
    glVertex3f(10,10,10);
    glVertex3f(10,10,-10);
    glVertex3f(-10,10,-10);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-10,-10,10);
    glVertex3f(10,-10,10);
    glVertex3f(10,-10,-10);
    glVertex3f(-10,-10,-10);
    glEnd();
    glPopMatrix();


//kubus2........................
    glPushMatrix();
    glTranslatef(-48.5,0,9.5);
    glScalef(0.15,1.5,0.35);
    //depan
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-10,-10,10);
    glVertex3f(-10,10,10);
    glVertex3f(10,10,10);
    glVertex3f(10,-10,10);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.1,0.5,0.9);
    glVertex3f(-10,-10,-10);
    glVertex3f(-10,10,-10);
    glVertex3f(10,10,-10);
    glVertex3f(10,-10,-10);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(1.3,1.3,1.3);
    glVertex3f(10,10,10);
    glVertex3f(10,-10,10);
    glVertex3f(10,-10,-10);
    glVertex3f(10,10,-10);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(1.3,1.3,1.3);
    glVertex3f(-10,10,10);
    glVertex3f(-10,-10,10);
    glVertex3f(-10,-10,-10);
    glVertex3f(-10,10,-10);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(1.3,1.3,1.3);
    glVertex3f(-10,10,10);
    glVertex3f(10,10,10);
    glVertex3f(10,10,-10);
    glVertex3f(-10,10,-10);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(1.3,1.3,1.3);
    glVertex3f(-10,-10,10);
    glVertex3f(10,-10,10);
    glVertex3f(10,-10,-10);
    glVertex3f(-10,-10,-10);
    glEnd();
    glPopMatrix();

//kubus2 entrance........................
    glPushMatrix();
    glTranslatef(-49,0,9.5);
    glRotatef(0,0,0,0);
    glScalef(0.15,0.5,0.35);
    //depan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-10,-10,10);
    glVertex3f(-10,10,10);
    glVertex3f(10,10,10);
    glVertex3f(10,-10,10);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-10,-10,-10);
    glVertex3f(-10,10,-10);
    glVertex3f(10,10,-10);
    glVertex3f(10,-10,-10);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(10,10,10);
    glVertex3f(10,-10,10);
    glVertex3f(10,-10,-10);
    glVertex3f(10,10,-10);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-10,10,10);
    glVertex3f(-10,-10,10);
    glVertex3f(-10,-10,-10);
    glVertex3f(-10,10,-10);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-10,10,10);
    glVertex3f(10,10,10);
    glVertex3f(10,10,-10);
    glVertex3f(-10,10,-10);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-10,-10,10);
    glVertex3f(10,-10,10);
    glVertex3f(10,-10,-10);
    glVertex3f(-10,-10,-10);
    glEnd();
    glPopMatrix();

//kubus3........................
    glPushMatrix();
    glTranslatef(0,48.5,9.5);
    glScalef(1.5,0.15,0.35);
    //depan
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-10,-10,10);
    glVertex3f(-10,10,10);
    glVertex3f(10,10,10);
    glVertex3f(10,-10,10);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.1,0.5,0.9);
    glVertex3f(-10,-10,-10);
    glVertex3f(-10,10,-10);
    glVertex3f(10,10,-10);
    glVertex3f(10,-10,-10);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(1.3,1.3,1.3);
    glVertex3f(10,10,10);
    glVertex3f(10,-10,10);
    glVertex3f(10,-10,-10);
    glVertex3f(10,10,-10);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(1.3,1.3,1.3);
    glVertex3f(-10,10,10);
    glVertex3f(-10,-10,10);
    glVertex3f(-10,-10,-10);
    glVertex3f(-10,10,-10);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(1.3,1.3,1.3);
    glVertex3f(-10,10,10);
    glVertex3f(10,10,10);
    glVertex3f(10,10,-10);
    glVertex3f(-10,10,-10);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(1.3,1.3,1.3);
    glVertex3f(-10,-10,10);
    glVertex3f(10,-10,10);
    glVertex3f(10,-10,-10);
    glVertex3f(-10,-10,-10);
    glEnd();
    glPopMatrix();

//kubus3 entrance........................
    glPushMatrix();
    glTranslatef(0,49,9.5);
    glScalef(0.5,0.15,0.35);
    //depan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-10,-10,10);
    glVertex3f(-10,10,10);
    glVertex3f(10,10,10);
    glVertex3f(10,-10,10);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-10,-10,-10);
    glVertex3f(-10,10,-10);
    glVertex3f(10,10,-10);
    glVertex3f(10,-10,-10);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(10,10,10);
    glVertex3f(10,-10,10);
    glVertex3f(10,-10,-10);
    glVertex3f(10,10,-10);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-10,10,10);
    glVertex3f(-10,-10,10);
    glVertex3f(-10,-10,-10);
    glVertex3f(-10,10,-10);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-10,10,10);
    glVertex3f(10,10,10);
    glVertex3f(10,10,-10);
    glVertex3f(-10,10,-10);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-10,-10,10);
    glVertex3f(10,-10,10);
    glVertex3f(10,-10,-10);
    glVertex3f(-10,-10,-10);
    glEnd();
    glPopMatrix();

//kubus4........................
    glPushMatrix();
    glTranslatef(0,-48.5,9.5);
    glScalef(1.5,0.15,0.35);
    //depan
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-10,-10,10);
    glVertex3f(-10,10,10);
    glVertex3f(10,10,10);
    glVertex3f(10,-10,10);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.1,0.5,0.9);
    glVertex3f(-10,-10,-10);
    glVertex3f(-10,10,-10);
    glVertex3f(10,10,-10);
    glVertex3f(10,-10,-10);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(1.3,1.3,1.3);
    glVertex3f(10,10,10);
    glVertex3f(10,-10,10);
    glVertex3f(10,-10,-10);
    glVertex3f(10,10,-10);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(1.3,1.3,1.3);
    glVertex3f(-10,10,10);
    glVertex3f(-10,-10,10);
    glVertex3f(-10,-10,-10);
    glVertex3f(-10,10,-10);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(1.3,1.3,1.3);
    glVertex3f(-10,10,10);
    glVertex3f(10,10,10);
    glVertex3f(10,10,-10);
    glVertex3f(-10,10,-10);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(1.3,1.3,1.3);
    glVertex3f(-10,-10,10);
    glVertex3f(10,-10,10);
    glVertex3f(10,-10,-10);
    glVertex3f(-10,-10,-10);
    glEnd();
    glPopMatrix();

//kubus4 entrance........................
    glPushMatrix();
    glTranslatef(0,-49,9.5);
    glScalef(0.5,0.15,0.35);
    //depan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-10,-10,10);
    glVertex3f(-10,10,10);
    glVertex3f(10,10,10);
    glVertex3f(10,-10,10);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-10,-10,-10);
    glVertex3f(-10,10,-10);
    glVertex3f(10,10,-10);
    glVertex3f(10,-10,-10);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(10,10,10);
    glVertex3f(10,-10,10);
    glVertex3f(10,-10,-10);
    glVertex3f(10,10,-10);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-10,10,10);
    glVertex3f(-10,-10,10);
    glVertex3f(-10,-10,-10);
    glVertex3f(-10,10,-10);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-10,10,10);
    glVertex3f(10,10,10);
    glVertex3f(10,10,-10);
    glVertex3f(-10,10,-10);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-10,-10,10);
    glVertex3f(10,-10,10);
    glVertex3f(10,-10,-10);
    glVertex3f(-10,-10,-10);
    glEnd();
    glPopMatrix();

}
void lingkaran()
{
    glPushMatrix();
    glTranslatef(-4,-4,12.5);
    int i;
	int r = 5;
	int n = 30;
	glBegin(GL_LINE_LOOP);
	glColor3d(1, 1, 1);
		for (int i = 1; i < n; i++) {
                glVertex2f(5+r * cos (2*3.14*i/n),5+r * sin(2*3.14*i/n));
		}
		glEnd();
    glPopMatrix();
}
void garis()
{
    glBegin(GL_LINE_LOOP);//garis lapangan
    glColor3f(1,1,1);
    glVertex3f(0,-30,12.3);
    glVertex3f(-30,0,12.3);
    glVertex3f(0,30,12.3);
    glVertex3f(30,0,12.3);
    glEnd();

}
void garis2()
{
    glBegin(GL_LINE_LOOP);//garis lapangan
    glColor3f(1,1,1);
    glVertex3f(0,-30,12.3);
    glVertex3f(-30,0,12.3);
    glVertex3f(10,40,12.3);
    glVertex3f(40,10,12.3);
    glEnd();
}
void draw()
{
    qobj = gluNewQuadric();
    gluQuadricDrawStyle(qobj, GLU_FILL);

    glPushMatrix();// potongan 1
    glTranslatef(-4.0, 50.1, 0.0);
    glScalef(0.03, 0.03, 0.03);
    glRotatef(90, 90, 0, 0);
    potongan();
    glPopMatrix();

    glPushMatrix();//bola
    glColor3f(0.3,0.3,0.3);
    glTranslatef(4, -1.9, 11.1);
    glScalef(1, 1, 1);
    glutSolidSphere(1.01,200,200);
    glPopMatrix();

    lingkaran();

    glPushMatrix();//bendera 1
    glTranslatef(0,30,10);
    glRotatef(270,270,0,0);
    glScalef(0.2,0.2,0.2);
    corner();
    glPopMatrix();

    glPushMatrix();//bendera 2
    glTranslatef(0,-30,10);
    glRotatef(270,270,0,0);
    glScalef(0.2,0.2,0.2);
    corner();
    glPopMatrix();

    glPushMatrix();//bendera 3
    glTranslatef(30,0,10);
    glRotatef(270,270,0,0);
    glScalef(0.2,0.2,0.2);
    corner();
    glPopMatrix();

    glPushMatrix();//bendera 4
    glTranslatef(-30,0,10);
    glRotatef(270,270,0,0);
    glScalef(0.2,0.2,0.2);
    corner();
    glPopMatrix();

    segitiga();
    glPushMatrix();
    glTranslatef(-33.5,-33.5,0);
    segitiga();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,-10,0);
    glTranslatef(10,10,0);
    glRotatef(90,0,0,90);
    segitiga();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(33.5,-33.5,0);
    glRotatef(90,0,0,90);
    segitiga();
    glPopMatrix();

    glPushMatrix();//gawang 1
    glTranslatef(15.5,-13.5,10);
    glScalef(0.1,0.1,0.1);
    glRotatef(45,0,0,45);
    glRotatef(270,270,0,0);
    gawang();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-35.5,35.5,1);
    glScalef(0.6,0.6,0.6);
    glRotatef(45,0,0,45);
    glRotatef(270,270,0,0);
    tv();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(35.5,-35.5,1);
    glScalef(0.6,0.6,0.6);
    glRotatef(225,0,0,225);
    glRotatef(270,270,0,0);
    tv();
    glPopMatrix();

    glPushMatrix();//gawang 2
    glTranslatef(-12.5,14.5,10);
    glScalef(0.1,0.1,0.1);
    glRotatef(225,0,0,225);
    glRotatef(270,270,0,0);
    gawang();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15,15,7);
    glScalef(0.4,0.4,0.4);
    glRotatef(135,0,0,135);
    glRotatef(270,270,0,0);
    skor();
    glPopMatrix();

    kotak();
    garis();
    glPushMatrix();//garis lapangan kecil1
    glTranslatef(-12.3,12.3,0);
    glScalef(0.2,0.2,1);
    garis2();
    glPopMatrix();

    glPushMatrix();//garis lapangan kecil2
    glTranslatef(12.3,-12.3,0);
    glScalef(0.2,0.2,1);
    garis2();
    glPopMatrix();

    glPushMatrix();//garis lapangan kecil3
    glTranslatef(14.5,-13.5,0);
    glScalef(0.1,0.1,1);
    garis2();
    glPopMatrix();

    glPushMatrix();//garis lapangan kecil4
    glTranslatef(-13.5,14.5,0);
    glScalef(0.1,0.1,1);
    garis2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15,-15,0);
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(-30,0,12.3);
    glVertex3f(0,30,12.3);
    glEnd();
    glPopMatrix();

    glPushMatrix();//dasar stadiun
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.0, 0.0, -3);
    glBegin(GL_QUADS);
    glVertex3f(-60,-60,16.1);
    glVertex3f(-60,60,16.1);
    glVertex3f(60,60,16.1);
    glVertex3f(60,-60,16.1);
    glPopMatrix();

    glPushMatrix();//lapangan
    glColor3f(0,1,0);
    glTranslatef(0.0, 0.0, -3);
    glBegin(GL_QUADS);
    glVertex3f(0,-30,16);
    glVertex3f(-30,0,16);
    glVertex3f(0,30,16);
    glVertex3f(30,0,16);
    glPopMatrix();

    glPushMatrix();// biru
    glTranslatef(0.0, 0.0, -3);
    glColor3f(0.1,0.5,1);
    gluCylinder(qobj, 45, 50, 4, 45, 50);
    glPopMatrix();

    glPushMatrix();// abu abu
    glColor3f(0.9,0.9,0.9);
    glTranslatef(0.0, 0.0, -3);
    gluCylinder(qobj, 30, 45, 0.2, 45, 50);
    glPopMatrix();

    glPushMatrix();// biru dalam
    glColor3f(0.1,0,0.8);
    glTranslatef(0.0, 0.0, 0);
    gluCylinder(qobj, 45, 30, 10, 45, 50);
    glPopMatrix();

    glPushMatrix();// kotak dasar
    glColor3f(0,1,1);
    glTranslatef(0.0, 0.0, 10);
    gluCylinder(qobj, 45, 30, 3, 4, 1);
    glPopMatrix();

    glPushMatrix();// kotak
    glColor3f(0.8,0.8,0.8);
    glTranslatef(0.0, 0.0, -3);
    gluCylinder(qobj, 30, 45, 0.2, 4, 1);
    glPopMatrix();

    glPushMatrix();// tabung biru muda
    glColor3f(0.1,0.5,0.9);
    glTranslatef(0.0, 0.0, 1);
    gluCylinder(qobj, 50, 50, 12, 45, 50);
    glPopMatrix();

    glPushMatrix();// tabung jendela hitam
    glColor3f(1,1,1);
    glTranslatef(0.0, 0, 6);
    gluCylinder(qobj, 50.1, 50.1, 7, 45, 50);
    glPopMatrix();

    glPushMatrix();// tangga
    glColor3f(0.3,0.3,0.3);
    glTranslatef(0, 0, 11);
    gluCylinder(qobj, 50, 55, 2, 45, 50);
    glPopMatrix();

}

void display(void)
{
    glViewport(0,0,800,600);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  glPushMatrix();
  glTranslatef(1.0, 0.0, 1.0);
  glRotatef(45, 45, 0, 0);
  glRotatef(45, 45, 0, 0);

  draw();
  glPopMatrix();

  glutSwapBuffers();
}


void idle()
{
    if(!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button,int state,int x,int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
    mouseDown = false;
}

void mouseMotion(int x, int y)
{
    glLoadIdentity();
    gluLookAt(0,0,3,0,0,0,0,1,0);
    glRotatef(xrot,1,0,0);
    glRotatef(yrot,0,1,0);
    glPushMatrix;
   if(mouseDown)
   {
       yrot = x - xdiff;
       xrot = y + ydiff;

       glutPostRedisplay();
   }
}

void keyboard(unsigned char key,int x,int y)
{
    switch(key)
    {

    case'w'://maju (zoom in)
    case'W':
        glTranslatef(0.0,0.0,3.0);
        break;

    case 'a'://ke-kiri
    case 'A':
        glTranslatef(3.0,0.0,0.0);
        break;

    case 's': //mundur (zoom out)
    case 'S':
        glTranslatef(0.0,0.0,-3.0);
        break;

    case 'd'://kanan
    case 'D':
        glTranslatef(-3.0,0.0,0.0);
        break;

    case '7'://ke-atas
        glTranslatef(0.0,3.0,0.0);
        break;

    case '9'://ke-bawah
        glTranslatef(0.0,-3.0,0.0);
        break;

    case '2'://miring ke-bawah
        glRotatef(2.0,1.0,0.0,0.0);
        break;

    case '8'://miring ke-atas
        glRotatef(-2.0,1.0,0.0,0.0);
        break;
    case '6'://putar ke-kanan
        glRotatef(2.0,0.0,1.0,0.0);
        break;
    case '4'://putar ke-kiri
        glRotatef(-2.0,0.0,1.0,0.0);
        break;
    case '1'://miring ke-kiri
        glRotatef(2.0,0.0,0.0,1.0);
        break;
    case '3'://miring ke-kanan
        glRotatef(-2.0,0.0,0.0,1.0);
        break;
    case '5'://membuat onjek yang terlihat di bagian depan layar tak terlihat (melihat isi dari objek 3d)
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    display();


}
void ukuran (int width,int height)
{
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, width / height, 50.0, 500.0);
    glTranslatef(0.0,-5.0,-150.0);
    glMatrixMode(GL_MODELVIEW);
}
int main (int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(150,0);
    glutCreateWindow("Juan Dedrick Toding Rundupadang 672018353, Indra Yunanto 672018019, Glorivan Tandiarang 672018415");
    myinit();
    InitGT();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}
