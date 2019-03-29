#include<windows.h>
#include <cmath>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

static int slices = 16;
static int stacks = 16;

static void display(void);
int rzut,skala;
int kat=120;
float wspX,wspY;
GLdouble ColorR=0,ColorG=0,ColorB=0;

enum {
ORTO,
SKALA_1_1,
PERSP,
FULL_WINDOW,
EXIT,
FRUST,
CZERWONY,
ZIELONY,
NIEBIESKI
};


/* GLUT callback Handlers */

/*static void resize(int width, int height)  	// kod odpowiedzialny za skalowanie zawartości
{                                            // okna w przypadku zmiany jego rozmiaru
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION); //Pozwala określić, który stos macierzy będzie stosowany w czasie manipulacji na macierzach, GL_PROJECTION – stos macierzy rzutowania (do definiowania przestrzeni ograniczającej)
    glLoadIdentity();   //Nadaje aktualnej macierzy wartości macierzy jednostkowej. W ten sposób aktualny układ współrzędnych staje się zgodny z układem współrzędnych okna.
   // glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);  //Tworzy macierz perspektywy, dzięki której mo¿na uzyskaæ rzutowanie perspektywiczne
    glOrtho(-5*ar,5*ar,-5,5,-10,10);
    glMatrixMode(GL_MODELVIEW);  // GL_MODELVIEW – stos macierzy model-widok (do przemieszczania obiektów na scenie)
    glLoadIdentity() ;
}*/

static void Reshape (int width, int height)
{
    wspX=1./width;
    wspY=1./height;

    glViewport (0,0,width,height); // obszar renderingu - cale okno
    glMatrixMode (GL_PROJECTION); // wybór macierzy rzutowania
    glLoadIdentity (); // macierz rzutowania = macierz jednostkowa
    // ustawienie parametrów zakresu rzutni
    GLdouble aspect = 1;
    GLfloat zakres = 4.0f;
    GLfloat blisko = 1.0f;
    GLfloat daleko = 25.0f;


    if (rzut==ORTO)
    {
        if (skala==SKALA_1_1)
        {
            if (width < height && width > 0)
                glOrtho (-zakres,zakres,-zakres*height/width,zakres*height/width,-4*zakres,4*zakres);
            else if (width >= height && height > 0)
                glOrtho (-zakres*width/height,zakres*width/height,-zakres,zakres,-4*zakres,4*zakres);
        }
        else
            glOrtho (-zakres,zakres,-zakres,zakres,-4*zakres,4*zakres);
    }

    if (rzut==FRUST)
    {
        if (skala==SKALA_1_1)
        {
            if (width < height && width > 0)
                glFrustum (-zakres,zakres,-zakres*height/width,zakres*height/width,blisko,daleko);
            else if (width >= height && height > 0)
                glFrustum (-zakres*width/height,zakres*width/height,-zakres,zakres,blisko,daleko);
        }
        else
            glFrustum (-zakres,zakres,-zakres,zakres,blisko,daleko);
    }

    if (rzut==PERSP)
    {
        aspect = width/(GLdouble)height;
        if(skala==SKALA_1_1)
        {
            if(width <height && width > 0)
                gluPerspective(-kat,aspect,blisko*width/height,daleko*width/height);
            else if (width>= height && height > 0)
                gluPerspective(-kat * width /height, aspect * width / height, blisko, daleko);
        }
        else
            gluPerspective(kat,aspect,blisko,daleko);

    }


    display ();

}

static void display(void)   // funkcja generująca scenę 3D, tworzenie zawartoœci okna
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // czyszczenie bufora dotyczącego koloru
    glColor3d(ColorR,ColorG,ColorB); // ustalenie koloru rysowania obiektu (czerwony, zielony, niebieski)

   /*glPointSize(10);
    glShadeModel(GL_FLAT);
   // glShadeModel(GL_FLAT);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);*/ //sposob wyswietlania wielokatow (przod albo tyl) oraz wypelnienie

   /* glBegin(GL_POINTS);
       glColor3d(1,1,0.2);
        glVertex2d(-1,1);
        glVertex2d(0,-1);
        glVertex2d(1,1);

        glColor3d(0.3,0.6,0.2);
        glVertex2d(2,-1);

        glColor3d(0,0.3,0.9);
        glVertex2d(3,1);

        glColor3d(1,0.5,0.3);
        glVertex2d(4,-1);
    glEnd();
*/

   /* glBegin(GL_LINES);
        glColor3d(0.7,1,0);
        glVertex2d(-1,-1);
         glColor3d(1,0,0);
        glVertex2d(1,-1);
         glColor3d(0,0,1);
        glVertex2d(0,1);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3d(0.7,1,0);
        glVertex2d(-1,-1);
         glColor3d(1,0,0);
        glVertex2d(1,-1);
         glColor3d(0,0,1);
        glVertex2d(0,1);
    glEnd();*/


    /*glBegin(GL_TRIANGLE_FAN);
        glColor3d(0.7,1,0);
        glVertex2d(0,0);
        glVertex2d(sin(M_PI/3),0);
        glVertex2d(cos(M_PI/3),sin(M_PI/3));

        glColor3d(0,0,0);
        glVertex2d(-cos(M_PI/3),sin(M_PI/3));

        glColor3d(0.7,1,0);
        glVertex2d(-sin(M_PI/3),0);

        glColor3d(0,0,0);
        glVertex2d(-cos(M_PI/3),-sin(M_PI/3));

        glColor3d(0.7,1,0);
        glVertex2d(cos(M_PI/3),-sin(M_PI/3));

        glColor3d(0,0,0);
        glVertex2d(sin(M_PI/3),0);
    glEnd();*/


  /*  glBegin(GL_TRIANGLE_STRIP);
        glColor3d(1,1,0.2);
        glVertex2d(-1,1);
        glVertex2d(0,-1);
        glVertex2d(1,1);

        glColor3d(0.3,0.6,0.2);
        glVertex2d(2,-1);

        glColor3d(0,0.3,0.9);
        glVertex2d(3,1);

        glColor3d(1,0.5,0.3);
        glVertex2d(4,-1);
    glEnd(); */

   /* glBegin(GL_QUADS);
    glColor3d(1,1,0.2);
    glVertex2d(-1,1);
    glVertex2d(-1,-1);
    glVertex2d(1,-1);
    glVertex2d(1,1);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3d(1,1,0.2);
    glVertex2d(-1,1);
    glVertex2d(-1,-1);
    glVertex2d(1,1);
    glVertex2d(1,-1);
    glColor3d(1,0.7,1);
    glVertex2d(3,1);
    glVertex2d(3,-1);
    glEnd();*/

    /*glBegin(GL_POLYGON);
    glColor3d(1,1,0.2);
    glVertex2d(-2,0);
    glVertex2d(-1,-2);

    glVertex2d(1,-2);
    glVertex2d(2,0);

    glVertex2d(1,2);
    glVertex2d(-1,2);
    glEnd(); */

    glPushMatrix();
    glTranslatef(0.0f,0.0f,-3.0f);
    glTranslatef(-2,-1,0.0f);
    glutSolidSphere(1,20,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f,0.0f,-3.0f);
    glTranslatef(2,1,0.0f);
    glutSolidTeapot(1);
    glPopMatrix();

    glutSwapBuffers();  // podmiana buforów
}

void MainMenu(int value)
{
    switch (value)
    {
    case EXIT:
        exit(0);
    }
}

void MenuS(int value)
{
    switch (value)
    {
    case FULL_WINDOW:
    skala=FULL_WINDOW;
    Reshape (glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
    break;
    case SKALA_1_1:
    skala=SKALA_1_1;
    Reshape (glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
    break;
    }
}

void MenuC(int value)
{
    switch (value)
    {
        case CZERWONY:
        ColorR=1.0;ColorG=0.0;ColorB=0;
        display();
        break;
        case NIEBIESKI:
            ColorR=0;ColorG=0;ColorB=1;
            display();
            break;
        case ZIELONY:
            ColorR=0;ColorG=1;ColorB=0;
            display();
            break;
    }
}

void MenuR(int value)
{
    switch (value)
    {
    case ORTO:
    rzut=ORTO;
    Reshape (glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
    break;
    case PERSP:
    rzut=PERSP;
    Reshape (glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
    break;
    case FRUST:
    rzut=FRUST;
    Reshape (glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
    break;
    }
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

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);  // inicjacja biblioteki GLUT
    glutInitWindowSize(640,480);    // ustalenie rozmiaru okna programu

    glutInitWindowPosition(10,10);  // początkowe położenie okna
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);   // inicjalizacja bufora ramki z podwójnym buforowaniem

    glutCreateWindow("GLUT Shapes");    // utworzenie głównego okna programu o podanej nazwie

    //rejestracja obs³ugi zdarzeñ
   // glutReshapeFunc(resize);    // przyłączenie funkcji wywoływanej przy zmianie rozmiaru okna
    glutReshapeFunc(Reshape);
    glutDisplayFunc(display);   // przyłączenie funkcji opisującej scenę 3D
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    int skalowanie = glutCreateMenu(MenuS);
    glutAddMenuEntry("Skalowanie - cale okno",FULL_WINDOW);
    glutAddMenuEntry("Skalowanie - skala 1:1",SKALA_1_1);

    int kolor=glutCreateMenu(MenuC);
    glutAddMenuEntry("Czerwony",CZERWONY);
    glutAddMenuEntry("Niebieski",NIEBIESKI);
    glutAddMenuEntry("Zielony",ZIELONY);

    int rzut=glutCreateMenu(MenuR);
    glutAddMenuEntry("Rzutowanie- Orto",ORTO);
    glutAddMenuEntry("Rzutowanie- Persp",PERSP);
    glutAddMenuEntry("Rzutowanie- Frust",FRUST);

    int mainMenu=glutCreateMenu(MainMenu);
    glutAddSubMenu("Kolory",kolor);
    glutAddSubMenu("Skalowanie",skalowanie);
    glutAddSubMenu("Rzutowanie",rzut);
    glutAddMenuEntry ("Wyjscie",EXIT);
    glutAttachMenu (GLUT_RIGHT_BUTTON);

    glClearColor(1,1,1,1);  // ustalenie koloru tła
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

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

    glutMainLoop(); // wprowadzenie programu do obsługi pętli komunikatów

    return EXIT_SUCCESS;
}
