#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<cmath>

enum
{
    BLACK, WHITE, RED, GREEN, BLUE, PINK, CYAN,
    FULLSCREEN, ASPECT_1_1,
    ORTHO, PERSPECTIVE, FRUSTUM,
    CUBE, CONE, DODECAHEDRON, TEAPOT, SPHERE, TORUS, OCTAHEDRON, TETRAHEDRON, ICOSAHEDRON,
    EXIT
};

static void display(void);
static void resize(int width, int height);
static void keyboard(unsigned char key, int x, int y);
static void Special_key(int key, int x, int y);
static void MouseButton(int button, int state, int x, int y);
static void MouseMotion(int x, int y);
void _COLORMENU(int value);
void _BACKGROUNDCOLORMENU(int value);
void _SCALEMENU(int value);
void _PROJECTIONMENU(int value);
void _ITEMMENU(int value);
void _MAINMENU(int value);

int projection = PERSPECTIVE;
int scale = FULLSCREEN;
int angle = 120;
int obiekt = CUBE;
int button_state = GLUT_UP;
int button_x;
int button_y;
int wire_w = 1;
GLdouble _COLORRED = 0.0;
GLdouble _COLORGRE = 0.0;
GLdouble _COLORBLU = 0.0;
GLdouble _COLORREDb = 1.0;
GLdouble _COLORGREb = 1.0;
GLdouble _COLORBLUb = 1.0;
GLdouble zoomk = 1.0;
GLdouble aspect = 1.0;
GLfloat rotateX = 0.0;
GLfloat rotateY = 0.0;
GLfloat translateX = 0.0;
GLfloat translateY = 0.0;
GLfloat zakres = 4.0f;
GLfloat blisko = 1.0f;
GLfloat daleko = 25.0f;

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
    case GLUT_KEY_HOME:
        wire_w += 1;
        break;
    case GLUT_KEY_END:
        wire_w -= 1;
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

void _COLORMENU(int value)
{
    switch(value)
    {
    case BLACK:
        _COLORRED = 0.0;
        _COLORGRE = 0.0;
        _COLORBLU = 0.0;
            display();
            break;
    case WHITE:
        _COLORRED = 1.0;
        _COLORGRE = 1.0;
        _COLORBLU = 1.0;
            display();
            break;
    case RED:
        _COLORRED = 1.0;
        _COLORGRE = 0.0;
        _COLORBLU = 0.0;
            display();
            break;
    case GREEN:
        _COLORRED = 0.0;
        _COLORGRE = 1.0;
        _COLORBLU = 0.0;
            display();
            break;
    case BLUE:
        _COLORRED = 0.0;
        _COLORGRE = 0.0;
        _COLORBLU = 1.0;
            display();
            break;
    case PINK:
        _COLORRED = 0.8;
        _COLORGRE = 0.05;
        _COLORBLU = 1.0;
            display();
            break;
    case CYAN:
        _COLORRED = 0.0;
        _COLORGRE = 1.0;
        _COLORBLU = 1.0;
            display();
            break;
    }
}

void _BACKGROUNDCOLORMENU(int value)
{
    switch(value)
    {
    case BLACK:
        _COLORREDb = 0.0;
        _COLORGREb = 0.0;
        _COLORBLUb = 0.0;
            display();
            break;
    case WHITE:
        _COLORREDb = 1.0;
        _COLORGREb = 1.0;
        _COLORBLUb = 1.0;
            display();
            break;
    case RED:
        _COLORREDb = 1.0;
        _COLORGREb = 0.0;
        _COLORBLUb = 0.0;
            display();
            break;
    case GREEN:
        _COLORREDb = 0.0;
        _COLORGREb = 1.0;
        _COLORBLUb = 0.0;
            display();
            break;
    case BLUE:
        _COLORREDb = 0.0;
        _COLORGREb = 0.0;
        _COLORBLUb = 1.0;
            display();
            break;
    case PINK:
        _COLORREDb = 0.8;
        _COLORGREb = 0.05;
        _COLORBLUb = 1.0;
            display();
            break;
    case CYAN:
        _COLORREDb = 0.0;
        _COLORGREb = 1.0;
        _COLORBLUb = 1.0;
            display();
            break;
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

void _ITEMMENU(int value)
{
    switch(value)
    {
    case CUBE:
        obiekt = CUBE;
        display();
        break;
    case CONE:
        obiekt = CONE;
        display();
        break;
    case DODECAHEDRON:
        obiekt = DODECAHEDRON;
        display();
        break;
    case SPHERE:
        obiekt = SPHERE;
        display();
        break;
    case TORUS:
        obiekt = TORUS;
        display();
        break;
    case OCTAHEDRON:
        obiekt = OCTAHEDRON;
        display();
        break;
    case TETRAHEDRON:
        obiekt = TETRAHEDRON;
        display();
        break;
    case ICOSAHEDRON:
        obiekt = ICOSAHEDRON;
        display();
        break;
    case TEAPOT:
        obiekt = TEAPOT;
        display();
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

static void display(void)
{
    glClearColor(_COLORREDb, _COLORGREb, _COLORBLUb, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -(blisko + daleko) / 2 );
    glTranslatef(translateX, translateY, 0.0);
    glScalef(zoomk, zoomk, zoomk);
    glRotatef(rotateX, 1.0, 0, 0);
    glRotatef(rotateY, 0, 1.0, 0);
        glColor3f(_COLORRED, _COLORGRE, _COLORBLU);
        glLineWidth(wire_w);
        switch(obiekt)
        {
        case CUBE:
        glBegin(GL_LINES);
            glutWireCube(1.0);
            break;
        case CONE:
            glutWireCone(1.0, 2.0, 20, 10);
            break;
        case DODECAHEDRON:
            glutWireDodecahedron();
            break;
        case TORUS:
            glutWireTorus(0.2, 1, 10, 20);
            break;
        case SPHERE:
            glutWireSphere(1.0, 20, 10);
            break;
        case OCTAHEDRON:
            glutWireOctahedron();
            break;
        case TETRAHEDRON:
            glutWireTetrahedron();
            break;
        case ICOSAHEDRON:
            glutWireIcosahedron();
            break;
        case TEAPOT:
            glutWireTeapot(1.0);
            break;
        }
        glEnd();
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1024,768);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GKiW Laboratorium 5");
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(Special_key);
    glutMouseFunc(MouseButton);
    glutMotionFunc(MouseMotion);
        int skalowanie = glutCreateMenu(_SCALEMENU);
        #ifdef WIN32
            glutAddMenuEntry("SCALING: FULLSCREEN", FULLSCREEN);
            glutAddMenuEntry("SCALING: 1:1", ASPECT_1_1);
        #else
            glutAddMenuEntry("SCALING: FULLSCREEN", FULLSCREEN);
            glutAddMenuEntry("SCALING: 1:1", ASPECT_1_1);
        #endif // WIN32
        int kolor = glutCreateMenu(_COLORMENU);
        #ifdef WIN32
            glutAddMenuEntry("COLOR: BLACK", BLACK);
            glutAddMenuEntry("COLOR: WHITE", WHITE);
            glutAddMenuEntry("COLOR: RED", RED);
            glutAddMenuEntry("COLOR: GREEN", GREEN);
            glutAddMenuEntry("COLOR: BLUE", BLUE);
            glutAddMenuEntry("COLOR: PINK", PINK);
            glutAddMenuEntry("COLOR: CYAN", CYAN);
        #else
            glutAddMenuEntry("COLOR: BLACK", BLACK);
            glutAddMenuEntry("COLOR: WHITE", WHITE);
            glutAddMenuEntry("COLOR: RED", RED);
            glutAddMenuEntry("COLOR: GREEN", GREEN);
            glutAddMenuEntry("COLOR: BLUE", BLUE);
            glutAddMenuEntry("COLOR: PINK", PINK);
            glutAddMenuEntry("COLOR: CYAN", CYAN);
        #endif // WIN32
        int tlo = glutCreateMenu(_BACKGROUNDCOLORMENU);
        #ifdef WIN32
            glutAddMenuEntry("COLOR: BLACK", BLACK);
            glutAddMenuEntry("COLOR: WHITE", WHITE);
            glutAddMenuEntry("COLOR: RED", RED);
            glutAddMenuEntry("COLOR: GREEN", GREEN);
            glutAddMenuEntry("COLOR: BLUE", BLUE);
            glutAddMenuEntry("COLOR: PINK", PINK);
            glutAddMenuEntry("COLOR: CYAN", CYAN);
        #else
            glutAddMenuEntry("COLOR: BLACK", BLACK);
            glutAddMenuEntry("COLOR: WHITE", WHITE);
            glutAddMenuEntry("COLOR: RED", RED);
            glutAddMenuEntry("COLOR: GREEN", GREEN);
            glutAddMenuEntry("COLOR: BLUE", BLUE);
            glutAddMenuEntry("COLOR: PINK", PINK);
            glutAddMenuEntry("COLOR: CYAN", CYAN);
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
        int obiekt = glutCreateMenu(_ITEMMENU);
        #ifdef WIN32
            glutAddMenuEntry("OBJECT: CUBE", CUBE);
            glutAddMenuEntry("OBJECT: CONE", CONE);
            glutAddMenuEntry("OBJECT: DODECAHEDRON", DODECAHEDRON);
            glutAddMenuEntry("OBJECT: SPHERE", SPHERE);
            glutAddMenuEntry("OBJECT: TORUS", TORUS);
            glutAddMenuEntry("OBJECT: OCTAHEDRON", OCTAHEDRON);
            glutAddMenuEntry("OBJECT: TETRAHEDRON", TETRAHEDRON);
            glutAddMenuEntry("OBJECT: ICOSAHEDRON", ICOSAHEDRON);
            glutAddMenuEntry("OBJECT: TEAPOT", TEAPOT);
        #else
            glutAddMenuEntry("OBJECT: CUBE", CUBE);
            glutAddMenuEntry("OBJECT: CONE", CONE);
            glutAddMenuEntry("OBJECT: DODECAHEDRON", DODECAHEDRON);
            glutAddMenuEntry("OBJECT: SPHERE", SPHERE);
            glutAddMenuEntry("OBJECT: TORUS", TORUS);
            glutAddMenuEntry("OBJECT: OCTAHEDRON", OCTAHEDRON);
            glutAddMenuEntry("OBJECT: TETRAHEDRON", TETRAHEDRON);
            glutAddMenuEntry("OBJECT: ICOSAHEDRON", ICOSAHEDRON);
            glutAddMenuEntry("OBJECT: TEAPOT", TEAPOT);
        #endif // WIN32
        glutCreateMenu(_MAINMENU); // int mainMenu
        #ifdef WIN32
            glutAddSubMenu("CHOOSE BACKGROUND COLOR", tlo);
            glutAddSubMenu("CHOOSE OBJECT COLOR", kolor);
            glutAddSubMenu("CHOOSE AN OBJECT", obiekt);
            glutAddSubMenu("CHOOSE SCALING", skalowanie);
            glutAddSubMenu("CHOOSE PROJECTION", rzutowanie);
            glutAddMenuEntry("EXIT", EXIT);
        #else
            glutAddSubMenu("CHOOSE BACKGROUND COLOR", tlo);
            glutAddSubMenu("CHOOSE OBJECT COLOR", kolor);
            glutAddSubMenu("CHOOSE AN OBJECT", obiekt);
            glutAddSubMenu("CHOOSE SCALING", skalowanie);
            glutAddSubMenu("CHOOSE PROJECTION", rzutowanie);
            glutAddMenuEntry("EXIT", EXIT);
        #endif // WIN32
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return EXIT_SUCCESS;
}
