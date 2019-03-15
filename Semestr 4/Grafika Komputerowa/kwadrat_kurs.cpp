#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <GL/glut.h>
#include <stdlib.h>

enum
{ EXIT };

void Wyswietl()
{
    glClearColor(1.0, 1., 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);   // GLdouble colorR=1.0, colorB=0.0, colorG=1.0;
    glBegin(GL_POLYGON);

    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, 0.0, 0.0);
    glEnd();
    glFlush();
    glutSwapBuffers();
}

void Reshape(int width, int height)
{
    Wyswietl();
}

void Menu(int value)
{
    switch(value){
        case EXIT: exit(0);
        }
}
int main( int argc, char * argv[] )
{
    glutInit( & argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowSize( 400, 400 );
    glutCreateWindow( "Moj pierwszy program w OpenGL" );
    glutDisplayFunc(Wyswietl);
    glutReshapeFunc(Reshape);
    glutCreateMenu(Menu);
    #ifdef WIN32
    glutAddMenuEntry("Wyjscie", EXIT);
    #else
    glutAddMenuEntry("Wyjscie", EXIT);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    #endif // WIN32
    glutMainLoop();
    return 0;
}
