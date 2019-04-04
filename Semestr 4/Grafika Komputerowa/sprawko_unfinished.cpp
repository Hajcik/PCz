#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<cmath>
GLdouble _COLORRED = 0.0;
GLdouble _COLORBLU = 0.0;
GLdouble _COLORGRE = 0.0;

enum
{
    RED,
    GREEN,
    BLUE,
    FULLSCREEN,
    ASPECT_1_1,
    DEFAULT,
    ORTHO,
    PERSPECTIVE,
    FRUSTUM,
    ZOOMin,
    ZOOMout,
    EXIT
};
int projection;
int scale;
int angle = 120;
int kat = 120;
static void display(void);

double okoX = 35.0;
double okoY = 35.0;
double okoZ = 35.0;

double centerX = 0;
double centerY = 1;
double centerZ = 0;

GLdouble z = -3.0;
GLdouble zoomk = 1.0;
static void resize(int width, int height)
{
    GLdouble aspect = 1.0;
    GLfloat zakres = 4.0f;
    GLfloat blisko = 1.0f;
    GLfloat daleko = 25.0f;

//    glMatrixMode(GL_MODELVIEW);
//    gluLookAt( okoX, okoY, okoZ, centerX, centerY, centerZ, 0, 0, -1);

    glTranslatef(0, 0, z);

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);    // wybor macierzy rzutowania
    glLoadIdentity();               // macierz rzutowania

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

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27:
            exit(0);
            break;
        case 43:
            zoomk += 0.05;
        //    display();
            break;
        case 45:
            zoomk -= 0.05;
         //   display();
            break;
    }
    glutPostRedisplay();
    resize( glutGet (GLUT_WINDOW_WIDTH), glutGet (GLUT_WINDOW_HEIGHT) );
}

static void Special_key(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_LEFT:
        kat-= 5;
        break;
    case GLUT_KEY_RIGHT:
        kat+= 5;
        break;
    }
    glutPostRedisplay();

}
void MouseMotion(int x, int y)
{

}

void _COLORMENU(int value)
{
    switch(value)
    {
    case RED:
        _COLORRED = 1.0;
        _COLORBLU = 0.0;
        _COLORGRE = 0.0;
            display();
            break;
    case GREEN:
        _COLORRED = 0.0;
        _COLORBLU = 0.0;
        _COLORGRE = 1.0;
            display();
            break;
    case BLUE:
        _COLORRED = 0.0;
        _COLORBLU = 1.0;
        _COLORGRE = 0.0;
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
void _MAINMENU(int value)
{
    switch(value)
    {
    case EXIT:
        exit(0);
    }
}

double radian;
double speed = 10;
double rot;

typedef struct _Vector{
double x, y, z;
} Vector;
Vector pos;
Vector vel;
Vector dir;
Vector dis;
Vector mouseCoords;

void MouseButton(int button, int state, int x, int y)
{
    mouseCoords.x = x - 1024/2;
    mouseCoords.y = -y + 768/2;
}

void _Move()
{
    dis.x = mouseCoords.x - pos.x;
    dis.y = mouseCoords.y - pos.y;
    if(sqrt(dis.y * dis.y + dis.x * dis.x) < speed)
    {
        pos.x = mouseCoords.x;
        pos.y = mouseCoords.y;
    }
    else
    {
        radian = atan2(dis.y, dis.x);
        pos.x += cos(radian) * speed;
        pos.y += sin(radian) * speed;
        rot = radian * 100 / 3.14;
    }
}

static void display(void)
{

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //  glMatrixMode(GL_MODELVIEW);
    glTranslated(pos.x, pos.y, 0);
    glRotatef(rot, 0, 0, 1);
    glScalef(zoomk, zoomk, 1.0f);

        glColor3f(_COLORRED, _COLORGRE, _COLORBLU);
        glBegin(GL_LINES);

            glVertex3f( 1.0, 1.0, 1.0 );
            glVertex3f( 1.0, - 1.0, 1.0 );

            glVertex3f( 1.0, - 1.0, 1.0 );
            glVertex3f( 1.0, - 1.0, - 1.0 );

            glVertex3f( 1.0, - 1.0, - 1.0 );
            glVertex3f( 1.0, 1.0, - 1.0 );

            glVertex3f( 1.0, 1.0, - 1.0 );
            glVertex3f( 1.0, 1.0, 1.0 );

            glVertex3f( - 1.0, 1.0, 1.0 );
            glVertex3f( - 1.0, - 1.0, 1.0 );

            glVertex3f( - 1.0, - 1.0, 1.0 );
            glVertex3f( - 1.0, - 1.0, - 1.0 );

            glVertex3f( - 1.0, - 1.0, - 1.0 );
            glVertex3f( - 1.0, 1.0, - 1.0 );

            glVertex3f( - 1.0, 1.0, - 1.0 );
            glVertex3f( - 1.0, 1.0, 1.0 );

            glVertex3f( 1.0, 1.0, 1.0 );
            glVertex3f( - 1.0, 1.0, 1.0 );

            glVertex3f( 1.0, - 1.0, 1.0 );
            glVertex3f( - 1.0, - 1.0, 1.0 );

            glVertex3f( 1.0, - 1.0, - 1.0 );
            glVertex3f( - 1.0, - 1.0, - 1.0 );

            glVertex3f( 1.0, 1.0, - 1.0 );
            glVertex3f( - 1.0, 1.0, - 1.0 );
        glEnd();
    glFlush();
    glutSwapBuffers();
}

static void idle(void)
{
    glutPostRedisplay();
}

static void update(int value)
{
    _Move();
    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1024,768);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GKiW Laboratorium 5");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutSpecialFunc(Special_key);
    glutIdleFunc(idle);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glDepthFunc(GL_LESS);
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
            glutAddMenuEntry("COLOR: RED", RED);
            glutAddMenuEntry("COLOR: GREEN", GREEN);
            glutAddMenuEntry("COLOR: BLUE", BLUE);
        #else
            glutAddMenuEntry("COLOR: RED", RED);
            glutAddMenuEntry("COLOR: GREEN", GREEN);
            glutAddMenuEntry("COLOR: BLUE", BLUE);
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
        glutCreateMenu(_MAINMENU); // int mainMenu
        #ifdef WIN32
            glutAddSubMenu("CHOOSE COLOR", kolor);
            glutAddSubMenu("CHOOSE SCALING", skalowanie);
            glutAddSubMenu("CHOOSE PROJECTION", rzutowanie);
            glutAddMenuEntry("EXIT", EXIT);
        #else
            glutAddSubMenu("CHOOSE COLOR", kolor);
            glutAddSubMenu("CHOOSE SCALING", skalowanie);
            glutAddSubMenu("CHOOSE PROJECTION", rzutowanie);
            glutAddMenuEntry("EXIT", EXIT);
        #endif // WIN32
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();

    return EXIT_SUCCESS;
}
