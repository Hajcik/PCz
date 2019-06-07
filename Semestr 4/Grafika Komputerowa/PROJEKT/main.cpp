#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<cmath>
#include "biblioteka.cpp"
#include "biblioteka.h"
#include "glext.h"
#include "glpomoc.h"
#include "colors.h"
using namespace std;

enum
{
    BLACK, WHITE, RED, GREEN, BLUE, PINK, CYAN,
    FULLSCREEN, ASPECT_1_1,
    PERSPECTIVE, FRUSTUM, ORTHO,
    LIGHT_on, LIGHT_off,
    PRZYWROC, EXIT
};
static void przywracanie();
static void display(void);
static void idle(void);
static void resize(int width, int height);
static void keyboard(unsigned char key, int x, int y);
static void Special_key(int key, int x, int y);
static void MouseButton(int button, int state, int x, int y);
static void MouseMotion(int x, int y);
void Reshape(int width, int height);
void _COLORMENU(int value);
void _BACKGROUNDCOLORMENU(int value);
void _LIGHTINGMENU(int value);
void _PROJECTIONMENU(int value);
void _MAINMENU(int value);
void _FLOOR();
int projection = FRUSTUM;
int scale = ASPECT_1_1;
int angle = 120;
int button_state = GLUT_UP;
int button_x;
int button_y;
int FOV=90;

GLdouble _COLORRED = 0.0;   // color
GLdouble _COLORGRE = 0.0;
GLdouble _COLORBLU = 0.0;
GLdouble _COLORREDb = 0.01;  // background color
GLdouble _COLORGREb = 0.01;
GLdouble _COLORBLUb = 0.01;
GLdouble zoomk = 2.0;
GLdouble aspect = 1.0;
GLfloat rotateX = 0.0;
GLfloat rotateY = 0.0;
GLfloat translateX = 0.0;
GLfloat translateY = 0.0;
GLfloat zakres = 1.0f;
GLfloat blisko = 2.0f;
GLfloat daleko = 100.0f;
GLdouble przybliz = 0.2;
GLfloat yyy=0;

GLPFrame frameCamera;
GLPVector3 vPoints[3] = { {0.0f,  -1.9f,  0.0f},
                          {10.0f, -1.9f,  0.0f},
                          {5.0f,  -1.9f, -5.0f}};
GLPVector3 vPoints2[3] ={ {0.0f,  -1.5f,  0.0f},
                          {10.0f, -1.5f,  0.0f},
                          {5.0f,  -1.5f, -5.0f}};
GLPVector3 bezCienia[3] = { {0.0f, -50.5f,  0.0f},
                           {10.0f, -50.5f,  0.0f},
                           { 5.0f, -50.5f, -5.0f}};

GLfloat fPozycja_swiatla_pod[] = { 2.0f, -2.0f, 0.0f, 1.0f };
GLfloat fPozycja_swiatla[] = { 2.0f, 2.0f, 0.0f, 1.0f };
GLfloat fKierunek_reflektora[] = {0.0f, 1.0f, -12.0f, 1.0f};
GLfloat fKierunek_reflektora_pod[] = {0.0f, -1.5f, -12.0f, 1.0f};
GLfloat fPozycja_reflektora[] = {0.0f, 0.0f, 0.0f, 1.0f};
GLfloat fPozycja_reflektora_pod[] = {0.0f, 0.0f, 0.0f, 1.0f};
void _FLOOR(int HALF_GRID_SIZE)
{
 /*   glBegin( GL_LINE_LOOP );
    glLineWidth(4);
    glNormal3f( 0.0, 1.0, 0.0);

    for( GLfloat z = -100.0; z < 100.0; z+= 1 )
    {
        for(GLfloat x = -100.0; x < 100.0; x+= 1 )
        {
            glColor4f( Green[ 0 ], Green[ 1 ], Green[ 2 ], 0.75 );
            glVertex3f( x + 0.0, 0.0, z + 0.0 );
            glVertex3f( x + 0.0, 0.0, z + 0.5 );
            glVertex3f( x + 0.5, 0.0, z + 0.5 );
            glVertex3f( x + 0.5, 0.0, z + 0.0 );
            glColor4f( Silver[ 0 ], Silver[ 1 ], Silver[ 2 ], 0.75 );
            glVertex3f( x + 0.5, 0.0, z + 0.0 );
            glVertex3f( x + 0.5, 0.0, z + 0.5 );
            glVertex3f( x + 1.0, 0.0, z + 0.5 );
            glVertex3f( x + 1.0, 0.0, z + 0.0 );
            glColor4f( Blue[ 0 ], Blue[ 1 ], Blue[ 2 ], 0.75 );
            glVertex3f( x + 0.5, 0.0, z + 0.5 );
            glVertex3f( x + 0.5, 0.0, z + 1.0 );
            glVertex3f( x + 1.0, 0.0, z + 1.0 );
            glVertex3f( x + 1.0, 0.0, z + 0.5 );
            glColor4f( Silver[ 0 ], Silver[ 1 ], Silver[ 2 ], 0.75 );
            glVertex3f( x + 0.0, 0.0, z + 0.5 );
            glVertex3f( x + 0.0, 0.0, z + 1.0 );
            glVertex3f( x + 0.5, 0.0, z + 1.0 );
            glVertex3f( x + 0.5, 0.0, z + 0.5 );
        }
    }
    glEnd();
*/
glLineWidth(1.5);
glBegin(GL_LINES);
glColor3f(0.91f, 0.10f, 0.86f);
for(int i = -HALF_GRID_SIZE; i<=HALF_GRID_SIZE; i++)
{
    glVertex3f((float)i,0,(float)-HALF_GRID_SIZE);
    glVertex3f((float)i,0,(float)HALF_GRID_SIZE);

    glVertex3f((float)-HALF_GRID_SIZE,0,(float)i);
    glVertex3f((float)HALF_GRID_SIZE,0,(float)i);
}
glEnd();
//_FLOOR(10);
}

static void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27:
            exit(0);
            break;
        case 43:
            zoomk+= 0.15;
            break;
        case 45:
            zoomk-= 0.15;
            break;
    }
    display();
}

static void Special_key(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_LEFT:
        glpRotateFrameLocalY(&frameCamera,  0.001f);
        break;
    case GLUT_KEY_RIGHT:
        glpRotateFrameLocalY(&frameCamera, -0.001f);
        break;
    case GLUT_KEY_UP:
        glpMoveFrameForward(&frameCamera,  0.001f);
        break;
    case GLUT_KEY_DOWN:
        glpMoveFrameForward(&frameCamera, -0.001f);
        break;
    case GLUT_KEY_PAGE_UP:
        glpMoveFrameUp(&frameCamera,  0.001f);
        break;
    case GLUT_KEY_PAGE_DOWN:
        glpMoveFrameUp(&frameCamera, -0.001f);
        break;
    case GLUT_KEY_END:
        break;
    }
    glutPostRedisplay();
}

static void MouseButton(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON)
    {
        button_state = state;
        if(state == GLUT_DOWN)
        {
            button_x = x;
            button_y = y;
        }
    }
}

static void MouseMotion(int x, int y)
{
    if(button_state == GLUT_DOWN)
    {
        translateX += 1.1 *( zakres - (-zakres)) / glutGet(GLUT_WINDOW_WIDTH) * (x - button_x);
        button_x = x;
        translateY += 1.1 * (zakres - (-zakres)) / glutGet(GLUT_WINDOW_WIDTH) * (button_y - y);
        button_y = y;
        glutPostRedisplay();
    }
}

static void resize(int width, int height)
{
    const float ar = (float)width / (float)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
        if(projection==FRUSTUM)
        {
            if(scale==ASPECT_1_1)
            {
            if(width<height && width>0)
            glFrustum(-zakres, zakres, -zakres*height/width, zakres*height/width, blisko, daleko);
            else if(width>=height && height>0)
            glFrustum(-zakres*width/height, zakres*width/height, -zakres, zakres, blisko, daleko);
            }
            else
            glFrustum(-zakres, zakres, -zakres, zakres, blisko, daleko);
        }

        if(projection==PERSPECTIVE)
        {
            if(height > 0) aspect = width/(GLdouble)height;
            gluPerspective(FOV, aspect, blisko, daleko);
        }
    display();
}
void _MAINMENU(int value)
{
    switch(value)
    {
    case EXIT:
        exit(0);
    case FULLSCREEN:
        scale=FULLSCREEN;
        przywracanie();
        Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
        break;
    case ASPECT_1_1:
        scale=ASPECT_1_1;
        przywracanie();
        Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
        break;
    case PRZYWROC:
        projection=FRUSTUM;
        scale=ASPECT_1_1;
        przywracanie();
        Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
        break;
    }
    display();
}


void _LIGHTINGMENU(int value)
{
    switch(value)
    {
    case LIGHT_on:
        glEnable( GL_LIGHTING );
        break;
    case LIGHT_off:
        glDisable( GL_LIGHTING );
        break;
    }
    display();
}

void _PROJECTIONMENU(int value)
{
    switch(value)
    {
    case ORTHO:
        projection = ORTHO;
        Reshape( glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT) );
        break;
    case PERSPECTIVE:
        projection = PERSPECTIVE;
        Reshape( glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT) );
        break;
    case FRUSTUM:
        projection = FRUSTUM;
        przywracanie();
        Reshape( glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT) );
        break;
    }
}

static void przywracanie()
{
    aspect = 1;
    zakres = 1.0f;
    blisko = 2.0f;
    daleko = 100.0f;
    przybliz = 0.2;
}

static void idle(void)
{
    glutPostRedisplay();
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glpApplyCameraTransform(&frameCamera);
    glShadeModel(GL_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.75);
    glPushMatrix();
    glTranslated(0, -2, 0);
    _FLOOR(1000);
    glPopMatrix();
//    glFlush();
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1024,768);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("GKiW Projekt Zaliczeniowy");
    glpInitFrame(&frameCamera);
    glutDisplayFunc(display);
    glutReshapeFunc(Reshape);
    glClearColor(_COLORREDb, _COLORGREb, _COLORBLUb, 1.0f);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(Special_key);
    glutMouseFunc(MouseButton);
    glutMotionFunc(MouseMotion);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glutIdleFunc(idle);
        int oswietlenie_wlacznik = glutCreateMenu(_LIGHTINGMENU);
        #ifdef WIN32
            glutAddMenuEntry("LIGHTNING: ON", LIGHT_on);
            glutAddMenuEntry("LIGHTNING: OFF", LIGHT_off);
        #else
            glutAddMenuEntry("AMBIENT LIGHTNING: ON", AMBIENT_LIGHT_on);
            glutAddMenuEntry("AMBIENT LIGHTNING: OFF", AMBIENT_LIGHT_off);
        #endif // WIN32
        int rzutowanie = glutCreateMenu(_PROJECTIONMENU);
        #ifdef WIN32
            glutAddMenuEntry("PROJECTION: PERSPECTIVE", PERSPECTIVE);
            glutAddMenuEntry("PROJECTION: FRUSTUM", FRUSTUM);
        #else
            glutAddMenuEntry("PROJECTION: PERSPECTIVE", PERSPECTIVE);
            glutAddMenuEntry("PROJECTION: FRUSTUM", FRUSTUM);
        #endif // WIN32
        glutCreateMenu(_MAINMENU); // int mainMenu
        #ifdef WIN32
            glutAddSubMenu("WYBIERZ RZUTOWANIE", rzutowanie);
            glutAddSubMenu("WLACZNIK SWIATLA", oswietlenie_wlacznik);
            glutAddSubMenu("PRZYWROC USTAWIENIA DOMYSLNE", PRZYWROC);
            glutAddMenuEntry("EXIT", EXIT);
        #else
            glutAddSubMenu("WYBIERZ RZUTOWANIE", rzutowanie);
            glutAddSubMenu("WLACZNIK SWIATLA", oswietlenie_wlacznik);
            glutAddSubMenu("PRZYWROC USTAWIENIA DOMYSLNE", PRZYWROC);
            glutAddMenuEntry("EXIT", EXIT);
        #endif // WIN32
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return EXIT_SUCCESS;
}
