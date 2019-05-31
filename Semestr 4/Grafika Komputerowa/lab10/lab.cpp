#include <windows.h>
#include <iostream>
#include "biblioteka.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

using namespace std;

#define LICZBA_OB_TEXTUR 4
GLuint obiektyTextur [LICZBA_OB_TEXTUR];
char *plikTextur[LICZBA_OB_TEXTUR] =  {"E:/Tekstury/Ziemia.tga","E:/Tekstury/sandsmooth.tga","E:/Tekstury/wood.tga","E:/Tekstury/ocean.tga"};

static int slices = 16;
static int stacks = 16;


static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,1,1);

    glDisable(GL_TEXTURE_2D);

    for(int j=0;j<10;j++)
    for(int i=0;i<10;i++)
    {
        glPushMatrix();
        if((i+j)%2==0)
            glColor4f(1,1,1,0.1);
        else
            glColor4f(0,0,0,0.8);

        glTranslatef(-4+i,-1,-10+j);
        glBegin(GL_QUADS);
        glVertex3f(-0.5,-1,-0.5);
        glVertex3f(-0.5,-1,0.5);
        glVertex3f(0.5,-1,0.5);
        glVertex3f(0.5,-1,-0.5);
        glEnd();
        glPopMatrix();
    }

    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslated(0,-0.5,-6);
    glRotated(a,0.2,1,0);
    glTranslated(-1,0,-1);

    glBindTexture(GL_TEXTURE_2D, obiektyTextur[0]);

    glBegin(GL_QUADS);
        glNormal3f(0.0f,1.0f,0.0f);
        //wierzcholek tekstury pierwszy
        glTexCoord2f(0.0f,0.0f);
        //wierzcholek kwadratu pierwszy i kolejne
        glVertex3f(0.0f,0.0f,2.0f);

        glTexCoord2f(1.0f,0.0f);
        glVertex3f(2.0f,0.0f,2.0f);

        glTexCoord2f(1.0f,1.0f);
        glVertex3f(2.0f,2.0f,2.0f);

        glTexCoord2f(0.0f,1.0f);
        glVertex3f(0.0f,2.0f,2.0f);

    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslated(0,-0.5,-6);
    glRotated(a,0.2,1,0);
    glTranslated(-1,0,-1);

    glBindTexture(GL_TEXTURE_2D, obiektyTextur[1]);

    glBegin(GL_QUADS);
        glNormal3f(0.0f,1.0f,0.0f);
        //wierzcholek tekstury pierwszy
        glTexCoord2f(0.0f,0.0f);
        //wierzcholek kwadratu pierwszy i kolejne
        glVertex3f(0.0f,0.0f,0.0f);

        glTexCoord2f(1.0f,0.0f);
        glVertex3f(2.0f,0.0f,0.0f);

        glTexCoord2f(1.0f,1.0f);
        glVertex3f(2.0f,2.0f,0.0f);

        glTexCoord2f(0.0f,1.0f);
        glVertex3f(0.0f,2.0f,0.0f);

    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslated(0,-0.5,-6);
    glRotated(a,0.2,1,0);
    glTranslated(-1,0,-1);

    glBindTexture(GL_TEXTURE_2D, obiektyTextur[2]);

    glBegin(GL_QUADS);
        glNormal3f(0.0f,1.0f,0.0f);
        //wierzcholek tekstury pierwszy
        glTexCoord2f(0.0f,0.0f);
        //wierzcholek kwadratu pierwszy i kolejne
        glVertex3f(0.0f,0.0f,0.0f);

        glTexCoord2f(1.0f,0.0f);
        glVertex3f(0.0f,0.0f,2.0f);

        glTexCoord2f(1.0f,1.0f);
        glVertex3f(0.0f,2.0f,2.0f);

        glTexCoord2f(0.0f,1.0f);
        glVertex3f(0.0f,2.0f,0.0f);

    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslated(0,-0.5,-6);
    glRotated(a,0.2,1,0);
    glTranslated(-1,0,-1);

    glBindTexture(GL_TEXTURE_2D, obiektyTextur[3]);

    glBegin(GL_QUADS);
        glNormal3f(0.0f,1.0f,0.0f);
        //wierzcholek tekstury pierwszy
        glTexCoord2f(0.0f,0.0f);
        //wierzcholek kwadratu pierwszy i kolejne
        glVertex3f(2.0f,0.0f,2.0f);

        glTexCoord2f(1.0f,0.0f);
        glVertex3f(2.0f,0.0f,0.0f);

        glTexCoord2f(1.0f,1.0f);
        glVertex3f(2.0f,2.0f,0.0f);

        glTexCoord2f(0.0f,1.0f);
        glVertex3f(2.0f,2.0f,2.0f);

    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslated(-2.4,1.2,-6);
        glRotated(60,1,0,0);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, obiektyTextur[0]);
        glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
        glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
        glutSolidSphere(1,20,20);
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case '+':
            slices++;
            stacks++;
            break;

        case '-':
            if (slices>3 && stacks>3)
            {
                slices--;
                stacks--;
            }
            break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1800,1000);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glEnable(GL_TEXTURE_2D);   //wlaczenie textury
    glGenTextures(LICZBA_OB_TEXTUR, obiektyTextur);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    for (int i=0;i<LICZBA_OB_TEXTUR;i++)
    {
        GLubyte *pBytes;
        GLint iWidth, iHeight, iComponents;
        GLenum eFormat;
        glBindTexture(GL_TEXTURE_2D, obiektyTextur[i]);
        pBytes = glploadtga(plikTextur[i], &iWidth, &iHeight, &iComponents, &eFormat);
        cout<<iWidth<<"\t"<<obiektyTextur[i]<<endl;

        gluBuild2DMipmaps(GL_TEXTURE_2D, iComponents, iWidth, iHeight, eFormat, GL_UNSIGNED_BYTE, pBytes);
        free(pBytes);
    }

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
  //  glEnable(GL_CULL_FACE);
  //  glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}
