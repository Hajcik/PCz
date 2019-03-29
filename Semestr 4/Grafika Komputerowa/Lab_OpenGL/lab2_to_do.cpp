#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

enum
{
 //   ASPECT_RATIO,
    FULLSCREEN,
    PROPORTIONAL,
    PROJECTION,
    SCALE,
    FRUSTUM,
    RECTANGULAR,
    PERSPECTIVE,
    MENU_OBJECT,
    MENU_OBJECT_COLOR,
    EXIT
};
int ASPECT_RATIO = FULLSCREEN;
int SCALE = PROPORTIONAL;

static void DISPLAY(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSwapBuffers();
}

static void resize(int width, int height)
{
glViewport(0, 0, width, height);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();

    // SKALOWANIE OKNA
    if(ASPECT_RATIO == PROPORTIONAL)
    { if(width > height) { glViewport( ( width - height) / 2, 0, height, height ); }
        else
        {
        if(width < height) glViewport( 0, (height - width) / 2, width, width);
        }
    } else
    { glViewport(0, 0, width, height); }

    // PERSPEKTYWICZNE RZUTOWANIE glFrustum
    if(SCALE == PROPORTIONAL && PROJECTION == FRUSTUM)
    {
        if(width < height && width > 0)
            glFrustum(- 2.0, 2.0, -2.0 * height / width, 2.0 * height / width, 1.0, 5.0);
        else
        if(width >= height && height > 0)
            glFrustum(-2.0 * width / height, 2.0 * width / height, -2.0, 2.0, 1.0, 5.0);
    }

    // PERSPEKTEKTYWICZNIE RZUTOWNIE gluPerspective
    if(SCALE == PROPORTIONAL && PROJECTION == PERSPECTIVE)
    {
        if(width < height && width > 0)
            {gluPerspective(-2.0, 2.0, -2.0 * height / width, 2.0 * height / width); }
        else
        if(width >= height && height > 0)
            gluPerspective(-2.0 * width / height, 2.0 * width / height, -2.0, 2.0);
    }

    if(SCALE == FULLSCREEN && PROJECTION == FRUSTUM)
    {
        glFrustum(-2.0, 2.0, -2.0, 2.0, 1.0, 5.0);
    }
    if(SCALE == FULLSCREEN && PROJECTION == PERSPECTIVE)
    {
        gluPerspective(-2.0, 2.0, -2.0, 2.0);
    }

    // RZUTOWANIE PROSTOKĄTNE glOrtho
    if(PROJECTION == RECTANGULAR)
    {
        if(width < height && width > 0)
        {
            glOrtho(-2.0, 2.0, -2.0 * height / width, 2.0 * height / width, -2.0, 2.0);
        }
        else
        if(width >= height && height > 0)
        {
            glOrtho(-2.0 * width / height, 2.0 * width / height, -2.0, 2.0, -2.0, 2.0);
        }
        else
            glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
    }
    DISPLAY();
}

static void KEYBOARD_FUNC(unsigned char key, int x, int y)
{
    if(key == 27)
        { exit(0); }
    glutPostRedisplay();
}

static void KEYBOARD_SPECIAL_FUNC(int key, int x, int y)
{


}

void MENU(int value)
{
    switch(value)
    {
case FULLSCREEN:
    ASPECT_RATIO = FULLSCREEN;
    resize( glutGet (GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT) );
    break;
case PROPORTIONAL:
    ASPECT_RATIO = PROPORTIONAL;
    resize( glutGet (GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT) );
    break;
case PROJECTION:

    break;
case SCALE:
    break;
case FRUSTUM:
    break;
case RECTANGULAR:
    break;
case PERSPECTIVE:
    break;
case MENU_OBJECT:
    break;
case MENU_OBJECT_COLOR:
    break;
case EXIT:
    exit(0);
    }
}

static void idle(void)
{
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GKiW Laboratorium 5");

    glutReshapeFunc(resize);
    glutDisplayFunc(DISPLAY);
    glutKeyboardFunc(KEYBOARD_FUNC);
    glutSpecialFunc(KEYBOARD_SPECIAL_FUNC);
    glutIdleFunc(idle);
int MENU_SCALE = glutCreateMenu(MENU);
            #ifdef WIN32
            glutAddMenuEntry("RENDER AREA - FULLSCREEN", FULLSCREEN);
            glutAddMenuEntry("RENDER AREA - PROPORTIONAL", PROPORTIONAL);
            #else
            glutAddMenuEntry("RENDER AREA - FULLSCREEN", FULLSCREEN);
            glutAddMenuEntry("RENDER AREA - PROPORTIONAL", PROPORTIONAL);
            #endif
int MENU_PROJECTION = glutCreateMenu(MENU);
            #ifdef WIN32
            glutAddMenuEntry("RECTANGULAR", RECTANGULAR);
            glutAddMenuEntry("FRUSTUM", FRUSTUM);
            glutAddMenuEntry("PERSPECTIVE", PERSPECTIVE);
            #else
            glutAddMenuEntry("RECTANGULAR", RECTANGULAR);
            glutAddMenuEntry("FRUSTUM", FRUSTUM);
            glutAddMenuEntry("PERSPECTIVE", PERSPECTIVE);
            #endif // WIN32
        glutCreateMenu(MENU);
            glutAddSubMenu("IMAGE SCALING", MENU_SCALE);
            glutAddSubMenu("IMAGE PROJECTION", MENU_PROJECTION);
            glutAddSubMenu("OBJECT", MENU_OBJECT);
            glutAddSubMenu("OBJECT COLOR", MENU_OBJECT_COLOR);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glutMainLoop();
    return EXIT_SUCCESS;
}
