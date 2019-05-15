#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
// #include "colors.h"
enum
{
    FULLSCREEN, ASPECT_1_1,
    ORTHO, PERSPECTIVE, FRUSTUM,
    LOCAL, GLOBAL,
    TESTING,
    EXIT
};

static void display(void);
static void resize(int width, int height);
static void keyboard(unsigned char key, int x, int y);
static void Special_key(int key, int x, int y);
static void MouseButton(int button, int state, int x, int y);
static void MouseMotion(int x, int y);
static void TESTINGfunc();   // Funkcja posiadajaca zwyklego druciaka cube, na testy podstawowe

void _SCALEMENU(int value);
void _PROJECTIONMENU(int value);
void _MAINMENU(int value);

int layout = GLOBAL;
int projection = PERSPECTIVE;
int scale = FULLSCREEN;
int angle = 120;
int button_state = GLUT_UP;
int button_x;
int button_y;
int object = TESTING;

GLfloat rotateX = 0.0f;
GLfloat rotateY = 0.0f;
GLfloat rotateX_LOCALandGLOBAL = 0.0f;
GLfloat rotateY_LOCALandGLOBAL = 0.0f;
GLfloat translateX = 0.0f;
GLfloat translateY = 0.0f;
GLfloat zakres = 4.0f;
GLfloat blisko = 1.0f;
GLfloat daleko = 25.0f;
GLdouble zoomk = 3.0;
GLdouble aspect = 1.0;
GLdouble plane_eq0[4] = {    1.0, 0.0, 0.0, 0.0  };
GLdouble plane_eq1[4] = {   -1.0, 0.0, 0.0, 0.0  };
GLenum glebia = GL_LESS;

static void keyboard(unsigned char key, int x, int y)
{
    switch(key)
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
    resize( glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT) ); // albo display();
}

static void Special_key(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_LEFT:
        rotateY-= 5;
        break;
    case GLUT_KEY_RIGHT:
        rotateY+= 5;
        break;
    case GLUT_KEY_UP:
        rotateX-= 5;
        break;
    case GLUT_KEY_DOWN:
        rotateX+= 5;
        break;
    }
    resize( glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT) );
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

void _SCALEMENU(int value)
{
    switch(value)
    {
    case FULLSCREEN:
        scale = FULLSCREEN;
        resize( glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT) );
        break;
    case ASPECT_1_1:
        scale = ASPECT_1_1;
        resize( glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT) );
        break;
    }
}

void _PROJECTIONMENU(int value)
{
    switch(value)
    {
    case ORTHO:
        projection = ORTHO;
        resize( glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT) );
        break;
    case PERSPECTIVE:
        projection = PERSPECTIVE;
        resize( glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT) );
        break;
    case FRUSTUM:
        projection = FRUSTUM;
        resize( glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT) );
        break;
    }
}

void _LAYOUTMENU(int value) // os obrotu
{
    switch(value)
    {
    case LOCAL:
        layout = LOCAL;
        break;
    case GLOBAL:
        layout = GLOBAL;
        break;
    }
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
    switch(value)
    {
 case TESTING:
    object = TESTING;
    display();
    break;
    }
}

void _DEPTHMENU(int value)
{
    switch(value)
    {
case GL_NEVER:
    glebia = GL_NEVER;
    display();
    break;
case GL_LESS:
    glebia = GL_LESS;
    display();
    break;
case GL_ALWAYS:
    glebia = GL_ALWAYS;
    display();
    break;
    }
}
static void display(void)
{
    glDepthMask(GL_TRUE);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    int width  = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);
    glScissor( 50, 50, width - 100, height - 100);
    glEnable(GL_SCISSOR_TEST);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef( 0, 0, -(blisko + daleko) / 2 );
    glTranslatef( translateX, translateY, 0.0 );
    glScalef( zoomk, zoomk, zoomk );
    glRotatef( rotateX, 1.0, 0.0, 0.0 );
    glRotatef( rotateY, 0.0, 1.0, 0.0 );
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(glebia);

    glClipPlane( GL_CLIP_PLANE0, plane_eq0 ); //  plaszczyzny obcinania
    glClipPlane( GL_CLIP_PLANE1, plane_eq1 );
        glColor3f(0.5, 0.3, 0.8);
     //   glBegin(GL_LINES);
     if(GLOBAL)
     {
        glRotatef(rotateX_LOCALandGLOBAL, 1.0, 0.0, 0.0);
        glRotatef(rotateY_LOCALandGLOBAL, 0.0, 1.0, 0.0);
        switch(object)
        {
        case TESTING:
            TESTINGfunc();
            break;
        }
     }
         glEnd();
        glFlush();
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1280,720);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GKiW Laboratorium 7");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(Special_key);
    glutMouseFunc(MouseButton);
    glutMotionFunc(MouseMotion);
        int przedmiot = glutCreateMenu(_ITEMMENU);
        #ifdef WIN32
            glutAddMenuEntry("TESTING", TESTING);
        #else
            glutAddMenuEntry("TESTING", TESTING);
        #endif // WIN32
        int glebia = glutCreateMenu(_DEPTHMENU);
        #ifdef WIN32
            glutAddMenuEntry("GL_NEVER", GL_NEVER);
            glutAddMenuEntry("GL_LESS", GL_LESS);
            glutAddMenuEntry("GL_ALWAYS", GL_ALWAYS);
        #else
            glutAddMenuEntry("GL_NEVER", GL_NEVER);
            glutAddMenuEntry("GL_LESS", GL_LESS);
            glutAddMenuEntry("GL_ALWAYS", GL_ALWAYS);
        #endif // WIN32
        int skalowanie = glutCreateMenu(_SCALEMENU);
        #ifdef WIN32
            glutAddMenuEntry("SCALING: FULLSCREEN", FULLSCREEN);
            glutAddMenuEntry("SCALING: 1:1", ASPECT_1_1);
        #else
            glutAddMenuEntry("SCALING: FULLSCREEN", FULLSCREEN);
            glutAddMenuEntry("SCALING: 1:1", ASPECT_1_1);
        #endif // WIN32
        int rzutowanie = glutCreateMenu(_PROJECTIONMENU);
        #ifdef WIN32
            glutAddMenuEntry("PROJECTION: ORTHO", ORTHO);
            glutAddMenuEntry("PROJECTION: PERSPECTIVE", PERSPECTIVE);
            glutAddMenuEntry("PROJECTION: FRUSTUM", FRUSTUM);
        #else
            glutAddMenuEntry("PROJECTION: ORTHO", ORTHO);
            glutAddMenuEntry("PROJECTION: PERSPECTIVE", PERSPECTIVE);
            glutAddMenuEntry("PROJECTION: FRUSTUM", FRUSTUM);
        #endif // WIN32
        int uklad = glutCreateMenu(_LAYOUTMENU);
        #ifdef WIN32
            glutAddMenuEntry("LAYOUT: LOCAL", LOCAL);
            glutAddMenuEntry("LAYOUT: GLOBAL", GLOBAL);
        #else
            glutAddMenuEntry("LAYOUT: LOCAL", LOCAL);
            glutAddMenuEntry("LAYOUT: GLOBAL", GLOBAL);
        #endif // WIN32
        glutCreateMenu(_MAINMENU);
        #ifdef WIN32
            glutAddSubMenu("CHOOSE AN OBJECT", przedmiot);
            glutAddSubMenu("CHOOSE SCALING", skalowanie);
            glutAddSubMenu("CHOOSE PROJECTION", rzutowanie);
            glutAddSubMenu("CHOOSE DEPTH", glebia);
            glutAddSubMenu("CHOOSE AXIS OF ROTATION", uklad);
        #else
            glutAddSubMenu("CHOOSE AN OBJECT", przedmiot);
            glutAddSubMenu("CHOOSE SCALING", skalowanie);
            glutAddSubMenu("CHOOSE PROJECTION", rzutowanie);
            glutAddSubMenu("CHOOSE DEPTH", glebia);
            glutAddSubMenu("CHOOSE AXIS OF ROTATION", uklad);
        #endif // WIN32
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return EXIT_SUCCESS;
}

void TESTINGfunc()
{
    // Obiekt nr 1
glPushMatrix();
    if(LOCAL)
    {
        glRotatef(rotateY_LOCALandGLOBAL, 1.0, 0.0, 0.0);
        glRotatef(rotateY_LOCALandGLOBAL, 0.0, 1.0, 0.0);

    glTranslated(3.0, 0.5, 0);
    glutWireCube(2.0);
    glEnd();
    }
glPopMatrix();
    // Obiekt nr 2
glPushMatrix();
    {
        glRotatef(rotateY_LOCALandGLOBAL, 1.0, 0.0, 0.0);
        glRotatef(rotateY_LOCALandGLOBAL, 0.0, 1.0, 0.0);

    glColor3f(0.7, 0.4, 1.0);
    glTranslated(-0.8, 0.8, 0);
    glutSolidTeapot(1);
    glEnd();
    }
glPopMatrix();
    // Obiekt nr 3
glPushMatrix();
    if(LOCAL)
    {
        glRotatef(rotateY_LOCALandGLOBAL, 1.0, 0.0, 0.0);
        glRotatef(rotateY_LOCALandGLOBAL, 0.0, 1.0, 0.0);

    glColor3f(1.0, 0.3, 0.3);
    glTranslated(-1.5, -0.8, 0);
    glutWireSphere(0.7, 15, 15);
    glEnd();
    }
glPopMatrix();
glFlush();
}
