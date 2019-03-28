#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<cmath>
#include<math.h>
enum
{
    FULL_WINDOW,
    ASPECT_1_1,
    lightON,
    lightOFF,
    CHMURA,
    BRAK_CHMURY,
    EXIT
};
int Aspect = FULL_WINDOW;
int pogoda = 4;
int chmura = 0;
int swiatlo = 0;
const int kroki = 78;
const float angle = 3.1415926 * 2.f / kroki;

void Droga()
{
    glBegin(GL_POLYGON); // DROGA
        glColor3f(0.15, 0.15, 0.15);
        glVertex3f(-1.0, -0.3, 0.0);
        glVertex3f(-1.0, -0.6, 0.0);
        glVertex3f(1.0, -0.6, 0.0);
        glVertex3f(1.0, -0.3, 0.0);
    glEnd();
}
void Trawa()
{
    glBegin(GL_POLYGON); // TRAWA
        glColor3f(0.5, 0.9, 0.2);   // GLdouble colorR=1.0, colorG=1.0, colorB=0.0;
        glVertex3f(-1.0, -0.2, 0.0); // LG
        glVertex3f(-1.0, -1.0, 0.0); // LD
        glVertex3f(1.0, -1.0, 0.0);  // PD
        glVertex3f(1.0, -0.2, 0.0);  // PG
    glEnd();
}

void Niebo_Slonce()
{   // glLoadIdentity();
    // glClearColor(0, 0.5, 1.0, 1.0);
glPushMatrix();
glTranslated(-0.8, 0.84, 0);
    glBegin(GL_POLYGON); // KOLO

        float xPos =0; float yPos =0; float radius = 0.1;
        float xPrev = xPos;
        float yPrev = yPos - radius;
        for(int i=0; i<=kroki; i++)
        {
            glBegin(GL_TRIANGLES);
            glColor3f(1.0, 0.95, 0.3);
            float xNew = radius * sin(angle * i);
            float yNew = -radius * cos(angle * i);
            glVertex3f(0.0f, 0.0f, 0.0f);
            glVertex3f(xPrev, yPrev, 0.0f);
            glVertex3f(xNew, yNew, 0.0f);
    glEnd();
        xPrev = xNew;
        yPrev = yNew;
        }
glPopMatrix();
    glEnd();
}
void Garaz()
{
    glBegin(GL_POLYGON); // Garaz
        glColor3f(0.6, 0.6, 0.6);
        glVertex3f(0.6, -0.3, 0);
        glVertex3f(0.6, -0.05, 0);
        glVertex3f(0.95, -0.05, 0);
        glVertex3f(0.95, -0.3, 0);
    glEnd();

    glBegin(GL_POLYGON); // Brama
        glColor3f(0.39, 0.39, 0.39);
        glVertex3f(0.65, -0.09, 0);
        glVertex3f(0.65, -0.3, 0);
        glVertex3f(0.90, -0.3, 0);
        glVertex3f(0.90, -0.09, 0);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
        glColor3f(0.5, 0.5, 0.5);
        glVertex3f(0.7, -0.09, 0);
        glVertex3f(0.7, -0.3, 0);

        glVertex3f(0.75, -0.09, 0);
        glVertex3f(0.75, -0.3, 0);

        glVertex3f(0.8, -0.09, 0);
        glVertex3f(0.8, -0.3, 0);

        glVertex3f(0.85, -0.09, 0);
        glVertex3f(0.85, -0.3, 0);
    glEnd();
}
void Domek()
{
    glBegin(GL_POLYGON); // Dach
        glColor3f(0.7, 0.3, 0.2);
        glVertex3f(-0.2, 0.0, 0.0);
        glVertex3f(0.1, 0.4, 0.0);
        glVertex3f(0.4, 0.4, 0.0);
        glVertex3f(0.7, 0.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON); // Komin
        glColor3f(0.1, 0.1, 0.1);
        glVertex3f(0.30, 0.33, 0.0);
        glVertex3f(0.30, 0.48, 0.0);
        glVertex3f(0.39, 0.48, 0.0);
        glVertex3f(0.39, 0.33, 0.0);
    glEnd();

    glBegin(GL_POLYGON); // Dom
        glColor3f(0.5, 0.3, 0);
        glVertex3f(-0.1, -0.3, 0.0);
        glVertex3f(-0.1, 0.0, 0.0);
        glVertex3f( 0.6, 0.0, 0.0);
        glVertex3f( 0.6, -0.3, 0.0);
    glEnd();

    glBegin(GL_POLYGON); // Drzwi wejsciowe
        glColor3f(0.6, 0.4, 0.0);
        glVertex3f(0.4, -0.3, 0.0);
        glVertex3f(0.4,  -0.04, 0.0);
        glVertex3f(0.55, -0.04, 0.0);
        glVertex3f(0.55,-0.3, 0.0);
    glEnd();

        glPointSize(13);
    glBegin(GL_POINTS); // Klamka od drzwi
        glColor3f(0.9, 0.65, 0.1);
        glVertex3f(0.43, -0.2, 0);
    glEnd();
}

void Wyswietl()
{
        glClearColor(0, 0.5, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
        Niebo_Slonce();
        Trawa();
        Droga();
        Domek();
        Garaz();
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.4, 0.5);
        glVertex3f(0.0, -0.20, 0);
        glVertex3f(0.0, -0.08, 0);
        glVertex3f(0.1, -0.08, 0);
        glVertex3f(0.1, -0.20, 0);
    glEnd();
    glBegin(GL_POLYGON); // Okno 2
        glColor3f(0.0, 0.4, 0.5);
        glVertex3f(0.2, -0.20, 0);
        glVertex3f(0.2, -0.08, 0);
        glVertex3f(0.3, -0.08, 0);
        glVertex3f(0.3, -0.20, 0);
    glEnd();
        glBegin(GL_POLYGON); // Okno 1
        switch(pogoda)
        {
        default: glClearColor(0, 0.5, 1.0, 1.0);
        case 1:
            glClearColor(0, 0.5, 1.0, 1.0);
            glutPostRedisplay();
        case 2:
            glClearColor(0.06, 0.09, 0.25, 1.0);
            glutPostRedisplay();
        }
        switch(swiatlo)
        {
        case 1:
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.4, 0.5);
        glVertex3f(0.0, -0.20, 0);
        glVertex3f(0.0, -0.08, 0);
        glVertex3f(0.1, -0.08, 0);
        glVertex3f(0.1, -0.20, 0);
    glEnd();
    glBegin(GL_POLYGON); // Okno 2
        glColor3f(0.0, 0.4, 0.5);
        glVertex3f(0.2, -0.20, 0);
        glVertex3f(0.2, -0.08, 0);
        glVertex3f(0.3, -0.08, 0);
        glVertex3f(0.3, -0.20, 0);
    glEnd();
        case 2:
    glBegin(GL_POLYGON);
        glColor3f(0.9, 0.92, 0.1);
        glVertex3f(0.0, -0.20, 0);
        glVertex3f(0.0, -0.08, 0);
        glVertex3f(0.1, -0.08, 0);
        glVertex3f(0.1, -0.20, 0);
    glEnd();
    glBegin(GL_POLYGON); // Okno 2
        glColor3f(0.9, 0.92, 0.1);
        glVertex3f(0.2, -0.20, 0);
        glVertex3f(0.2, -0.08, 0);
        glVertex3f(0.3, -0.08, 0);
        glVertex3f(0.3, -0.20, 0);
    glEnd();
        }
    glEnd();

    switch(chmura)
    {
    case 1:
    glBegin(GL_POLYGON); // Chmura
        glColor3f(0, 0.5, 1.0); // nie wiem jak usunac obiekt, nie moglem nic znalezc :(
        glVertex3f(-0.70, 0.79, 0.0);
        glVertex3f(-0.65, 0.65, 0.0);
        glVertex3f(-0.30, 0.49, 0.0);
        glVertex3f(-0.13, 0.67, 0.0);
        glVertex3f(0.14, 0.73, 0.0);
        glVertex3f(0.06, 0.80, 0.0);
        glVertex3f(-0.09, 0.92, 0.0);
        glVertex3f(-0.20, 0.87, 0.0);
        glVertex3f(-0.45, 0.76, 0.0);
        glVertex3f(-0.67, 0.88, 0.0);
    glEnd();
    case 2:
    glBegin(GL_POLYGON); // Chmura
        glColor3f(0.3, 0.3, 0.3);
        glVertex3f(-0.70, 0.79, 0.0);
        glVertex3f(-0.65, 0.65, 0.0);
        glVertex3f(-0.30, 0.49, 0.0);
        glVertex3f(-0.13, 0.67, 0.0);
        glVertex3f(0.14, 0.73, 0.0);
        glVertex3f(0.06, 0.80, 0.0);
        glVertex3f(-0.09, 0.92, 0.0);
        glVertex3f(-0.20, 0.87, 0.0);
        glVertex3f(-0.45, 0.76, 0.0);
        glVertex3f(-0.67, 0.88, 0.0);
    glEnd();
    }
    glEnd();
    glFlush();
    glutSwapBuffers();
}

void Reshape(int width, int height) // Zmiana wielkosci okna
{
     if(Aspect == ASPECT_1_1)   // Obszar renderingu - aspekt 1:1
        {   // Szerokosc okna wieksza od wysokosci okna
            if(width > height)
                glViewport( (width - height) / 2, 0, height, height);
       else
            if(width < height)
                glViewport(0, (height - width) / 2, width, width);
        }
            // Obszar renderingu - cale okno (takze gdy aspect ratio wynosi 1:1)
    else glViewport(0, 0, width, height);
    Wyswietl();
}

void Menu(int value)
{
switch(value)
        {
    case FULL_WINDOW:
        Aspect: FULL_WINDOW;
        Reshape( glutGet (GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT) );
        break;

    case ASPECT_1_1:
        Aspect = ASPECT_1_1;
        Reshape( glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT) );
        break;

    //  Pogoda
/*    case DZIEN:
        pogoda = 4; Wyswietl(); break;
    case NOC:
        pogoda = 5; Wyswietl(); break;
*/
    case BRAK_CHMURY:
        chmura = 0; Wyswietl(); break;
    case CHMURA:
        chmura = 1; Wyswietl(); break;
    //  Swiatlo
    case lightOFF:
        swiatlo = 0; Wyswietl(); break;
    case lightON:
        swiatlo = 1; Wyswietl(); break;
    case EXIT:
        exit(0);
        }
}
int main( int argc, char * argv[] )
{
    glutInit( & argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowSize( 1000, 1000 );
    glutCreateWindow( "Laboratorium 1 GKiW" );
    glutDisplayFunc(Wyswietl);
    glutReshapeFunc(Reshape);
    glutCreateMenu(Menu);
    #ifdef WIN32
//    glutAddMenuEntry("Obszar renderingu - cale okno", FULL_WINDOW);
//    glutAddMenuEntry("Obszar renderingu - aspect ratio 1:1", ASPECT_1_1);
//    glutAddMenuEntry("Dzien", DZIEN);
//    glutAddMenuEntry("Noc", NOC);
    glutAddMenuEntry("Lights ON", lightON);
    glutAddMenuEntry("Lights OFF", lightOFF);
    glutAddMenuEntry("Chmura", CHMURA);
    glutAddMenuEntry("Brak chmury", BRAK_CHMURY);
    glutAddMenuEntry("Wyjscie", EXIT);
    #else
//    glutAddMenuEntry("Obszar renderingu - cale okno", FULL_WINDOW);
//    glutAddMenuEntry("Obszar renderingu - aspect ratio 1:1", ASPECT_1_1);
//    glutAddMenuEntry("Dzien", DZIEN);
//    glutAddMenuEntry("Noc", NOC);
//    glutAddMenuEntry("Dzien", DZIEN);
//    glutAddMenuEntry("Noc", NOC);
    glutAddMenuEntry("Lights ON", lightON);
    glutAddMenuEntry("Lights OFF", lightOFF);
    glutAddMenuEntry("Chmura", CHMURA);
    glutAddMenuEntry("Brak chmury", BRAK_CHMURY);
    glutAddMenuEntry("Wyjscie", EXIT);
    #endif
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}
