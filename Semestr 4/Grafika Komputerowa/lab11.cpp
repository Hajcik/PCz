#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<fstream>
#include<iostream>
// #include "colors.h"
using namespace std;

enum
{
    FULLSCREEN, ASPECT_1_1,
    ORTHO, PERSPECTIVE, FRUSTUM,
    EXIT
};
/*int rozmiar1;
int rozmiar2;
int* lw = new int[rozmiar1];
int* lk = new int[rozmiar2];
*/
static void display(void);
static void resize(int width, int height);
static void keyboard(unsigned char key, int x, int y);
static void Special_key(int key, int x, int y);
static void MouseButton(int button, int state, int x, int y);
static void MouseMotion(int x, int y);


void _SCALEMENU(int value);
void _PROJECTIONMENU(int value);
void _MAINMENU(int value);


int projection = PERSPECTIVE;
int scale = FULLSCREEN;
int angle = 120;
int button_state = GLUT_UP;
int button_x;
int button_y;

int point_size;
int lw;
int lk;
int** Red1;
int** Red2;
int** Red3;
int** Green1;
int** Green2;
int** Green3;
int** Blue1;
int** Blue2;
int** Blue3;

GLfloat rotateX = 0.0f;
GLfloat rotateY = 0.0f;
GLfloat translateX = 0.0f;
GLfloat translateY = 0.0f;
GLfloat zakres = 4.0f;
GLfloat blisko = 1.0f;
GLfloat daleko = 25.0f;

GLdouble aspect = 1.0;


bool wczytaj_obraz_plik()
{
    ifstream plik;

    plik.open(".\\foto2.txt");
    if(!plik)
    {
        cout<<"Wystapil blad\n";
        return false;
    }

    plik>>lw>>lk;

    // dynamicznych przydział pamięci tablicom RED, GREEN, BLUE

    Red1=   new int*[lw];
    Red2=   new int*[lw];
    Red3=   new int*[lw];
    Green1= new int*[lw];
    Green2= new int*[lw];
    Green3= new int*[lw];
    Blue1=  new int*[lw];
    Blue2=  new int*[lw];
    Blue3=  new int*[lw];
    for(int i=0; i<lw; i++)
    {
        Red1[i]=    new int[lk];
        Red2[i]=    new int[lk];
        Red3[i]=    new int[lk];
        Green1[i]=  new int[lk];
        Green2[i]=  new int[lk];
        Green3[i]=  new int[lk];
        Blue1[i]=   new int[lk];
        Blue2[i]=   new int[lk];
        Blue3[i]=   new int[lk];
    }
    for(int i=0; i<lw; ++i)
        for(int j=0; j<lk; ++j)
           {
            plik >> Red1[i][j] >> Green1[i][j] >> Blue1[i][j];
            plik >> Red2[i][j] >> Green2[i][j] >> Blue2[i][j];
            plik >> Red3[i][j] >> Green3[i][j] >> Blue3[i][j];
           }
}
void wyczysc_pamiec()
{
    delete [] Red1;
    delete [] Red2;
    delete [] Red3;
    delete [] Green1;
    delete [] Green2;
    delete [] Green3;
    delete [] Blue1;
    delete [] Blue2;
    delete [] Blue3;
}
static void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 27:
            exit(0);
            break;
    }
    resize( glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT) ); // albo display();
}

static void Special_key(int key, int x, int y)
{
    resize( glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT) );
}

static void MouseButton(int button, int state, int x, int y)
{

}

static void MouseMotion(int x, int y)
{

}

void _SCALEMENU(int value)
{

}

void _PROJECTIONMENU(int value)
{

}

void _LAYOUTMENU(int value) // os obrotu
{

}

void _MAINMENU(int value)
{
    switch(value)
    {
    case EXIT:
        exit(0);
    }
}

static void resize(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(scale == ASPECT_1_1)
    {
        if( width > height )
            glViewport( (width - height) / 2, 0, height, height);
        else
        if( width < height )
            glViewport(0, (height - width) / 2, width, width);
    } else glViewport(0, 0, width, height);

    if(projection == ORTHO)
    {
        if(scale == ASPECT_1_1)
        {
            if( width < height && width > 0 )
                glOrtho( -zakres, zakres, -zakres * height / width, zakres * height / width, -4 * zakres, 4 * zakres );
            else
            if( width >= height && height > 0 )
                glOrtho( -zakres*width/height, zakres*width/height, -zakres, zakres, -4*zakres,4*zakres );
        }
        else glOrtho( -zakres, zakres, -zakres, zakres, -4*zakres, 4*zakres );
    }

    if(projection == FRUSTUM)
    {
        if(scale == ASPECT_1_1)
        {
            if( width < height && width > 0 )
                glFrustum( -zakres, zakres, -zakres * height / width, zakres * height / width, blisko, daleko );
            else
            if( width >= height && height > 0 )
                glFrustum( -zakres * width / height, zakres * width / height, -zakres, zakres, blisko, daleko );
        }
        else glFrustum( -zakres, zakres, -zakres, zakres, blisko, daleko );
    }

    if(projection == PERSPECTIVE)
    {
        if(scale == ASPECT_1_1)
        {
            if( width < height && width > 0 )
                gluPerspective( -angle, aspect, blisko * width / height, daleko * width / height );
            else
            if( width >= height && height > 0 )
                gluPerspective( -angle * width / height, aspect * width / height, blisko, daleko );
        }
        else gluPerspective( angle, aspect, blisko, daleko );
    }
    display();
}

void _ITEMMENU(int value)
{

}

void _DEPTHMENU(int value)
{

}
static void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPointSize(point_size);
    glBegin(GL_POINTS);
        for(int i=0; i<lw; i++)
        {
            for(int j=0; j<lk; j++)
            {
                glColor3f(Red1[i][j]/255.0 , Green1[i][j]/255.0 , Blue1[i][j]/255.0 );
                glVertex3f(j, i, 0);
            }
        }
    glEnd();
    glutSwapBuffers();
 //   int width  = glutGet(GLUT_WINDOW_WIDTH);
 //   int height = glutGet(GLUT_WINDOW_HEIGHT);
}

int main(int argc, char *argv[])
{
wczytaj_obraz_plik();
    glutInit(&argc, argv);
    glutInitWindowSize(1280,720);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GKiW Laboratorium 7");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(Special_key);

        glutCreateMenu(_MAINMENU);
        #ifdef WIN32

        #else

        #endif // WIN32
    glutAttachMenu(GLUT_RIGHT_BUTTON);
//wyczysc_pamiec();
    glutMainLoop();
    return EXIT_SUCCESS;
}
