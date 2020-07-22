//Juan Dedrick Toding Rundupadang 672018353
//Indra Yunanto 672018019
//Glorivan Tandiarang 672018415
#include <windows.h>
#include <gl/glut.h>
#include <stdlib.h>
#include <math.h>
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

    glClearColor(1.0,1.0,1.0,1.0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(3.0);

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


    glPushMatrix();//bola
    glColor3f(0,0,0);
    glTranslatef(4, -1.9, 11.1);
    glScalef(1, 1, 1);
    glutSolidSphere(1.01,200,200);
    glPopMatrix();

    lingkaran();

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
void ukuran (int lebar,int tinggi)
{
    if (tinggi ==0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 50.0, 500.0);
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
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}


