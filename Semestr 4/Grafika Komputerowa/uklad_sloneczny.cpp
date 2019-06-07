#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include "pomoc/glpomoc.h"

using namespace std;

GLPFrame frameCamera; //dla kamery

//zmienne wyliczeniowe menu podrecznego
enum
{
    FULL_WINDOW, // obszar renderingu - całe okno
    ASPECT_1_1,  // obszar renderingu - aspekt 1:1
    EXIT,        // wyjście
    ORTHO,       // rzutowanie ortogonalne
    PERSP        // rzutowanie perspektywiczne
};

// Wielkość obrotów i przesunięcia
GLfloat alfa1 = 0.0f;
GLfloat alfa2 = 0.0f;
GLfloat alfa3 = 0.0f;
float angle1 = 0.0f;
float angle2 = 0.0f;
float angle3 = 0.0f;
float angle4 = 0.0f;
float angle5 = 0.0f;
float angle6 = 0.0f;
float angle7 = 0.0f;
float angle8 = 0.0f;
float angle9 = 0.0f;

// aspekt obrazu
GLint skala = FULL_WINDOW;

// rzutowanie
GLint rzut = PERSP;

// kąt rzutowania
GLdouble fovy = 90;

//Definiowanie ustawien dotyczacych sposobu rusowania obiektow
void Ustawienia ()
{
	// Czarne tło
	glClearColor(0.0f,0.0f,0.0f,1.0f);

	// Model cieniowania kolorów - płaski
	glShadeModel(GL_SMOOTH);

	//Nawinięcie wielokątów
	glFrontFace(GL_CCW);

	//Inicjowanie kamery
	glpInitFrame (&frameCamera);

    // Włączenie lub wyłączenie mechanizmu eliminowania ukrytych powierzchni
	//glEnable(GL_CULL_FACE);

	// Włączenie lub wyłączenie mechanizmu sprawdzania głębi
	glEnable(GL_DEPTH_TEST);

	// Jeżeli ten znacznik będzie ustawiony, to wielokąty zwrócone
	// tyłem do widza będą rysowane tylko w postaci szkieletu
	glPolygonMode(GL_BACK,GL_LINE);
	glPolygonMode(GL_FRONT,GL_FILL);

    glpMoveFrameForward(&frameCamera, -100.0f);
    glpMoveFrameUp(&frameCamera, 10.0f);
}

//Wyjscie z programu
void Wyjscie (void)
{

}

//Rysowanie podloza
void Podloze ()
{
	GLfloat Range = 20.0f;
	GLfloat Tlo_x;
	GLfloat	Tlo_z;
	GLfloat red = 0.1f;
	GLfloat green = 0.1f;
	GLfloat blue = 0.1f;

//	glColor3f (red, green, blue);
	for (Tlo_x = -Range * 5; Tlo_x <=  Range * 5;  Tlo_x += 2.0)
	{
		glColor4f (0.8f, 0.1f, 0.1f, 0.6f);
		for (Tlo_z = -Range * 5; Tlo_z <= Range * 5; Tlo_z += 2.0)
		{
			if (red == 0.1f)
			{
				red = 0.8f;
				green = 0.1f;
				blue = 0.1f;
			}
			else
			{
				red = 0.1f;
				green = 0.1f;
				blue = 0.8f;
			}
			glColor4f (red, green, blue, 0.6f);
			glBegin (GL_QUADS);
				//wektory normalne wskazujace gore
 			    glNormal3f (0.0f, 1.0f, 0.0f);
				glVertex3f (Tlo_x, 0.0f, Tlo_z);
				glVertex3f (Tlo_x, 0.0f, Tlo_z + 2.0f);
				glVertex3f (Tlo_x + 2.0f, 0.0f, Tlo_z + 2.0f);
				glVertex3f (Tlo_x + 2.0f, 0.0f, Tlo_z);
			glEnd ();
        }

	}
}


//Rysowaie aktorow na scenie
void Rys_aktorow (GLint czy_cien)
{
float x1=0;
float y1=0;
float z1=0;
float x2=0;
float y2=0;
float z2=0;


float x3=0;
float y3=0;
float z3=0;
float x4=0;
float y4=0;
float z4=0;
float x5=0;
float y5=0;
float z5=0;
float x6=0;
float y6=0;
float z6=0;
float x7=0;
float y7=0;
float z7=0;
float x8=0;
float y8=0;
float z8=0;
float x9=0;
float y9=0;
float z9=0;
float x10=0;
float y10=0;
float z10=0;

alfa1+=1.0;
alfa2+=1.0;
alfa3+=1.0;

//ziemia
angle1+=0.02f;
if(angle1>=(2.0f*3.14159f)*1.0f)
   angle1=0.0f;

//księżyc
angle2+=0.1f;
if(angle2>=(2.0f*3.14159f)*1.0f)
    angle2=0.0f;


//mars
angle3+=0.01f;
if(angle3>=(2.0f*3.14159f)*1.0f)
    angle3=0.0f;

//merkury
angle4+=0.1f;
if(angle4>=(2.0f*3.14159f)*1.0f)
    angle4=0.0f;

//wenus
angle5+=0.05f;
if(angle5>=(2.0f*3.14159f)*1.0f)
    angle5=0.0f;

//jowisz
angle6+=0.005f;
if(angle6>=(2.0f*3.14159f)*1.0f)
    angle6=0.0f;

//saturn
angle7+=0.002f;
if(angle7>=(2.0f*3.14159f)*1.0f)
    angle7=0.0f;

//uran
angle8+=0.001f;
if(angle8>=(2.0f*3.14159f)*1.0f)
    angle8=0.0f;

//neptun
angle9+=0.0005f;
if(angle9>=(2.0f*3.14159f)*1.0f)
    angle9=0.0f;



glPushMatrix();
    //slonce
    glPushMatrix();
        glRotatef(alfa1,1.0f,0.0f,0.0f);
        // kolor kuli
        glColor3f(1.0f,1.0f,0.0f);
        //glTranslatef(0,10,0);
        glutWireSphere(20.0f,20, 20);
    glPopMatrix();

glPushMatrix();
    //orbita ziemi
    glRotatef(-30,0,1,1);
    glPushMatrix();
        glColor3f(0,0,1);
        for(float angle=0.0f;angle<=((2.0f*3.14159f)*1.0f);angle+=0.001f)
        {
            glBegin(GL_POINTS);
                  x1=50.0f*sin(angle);
                  z1=50.0f*cos(angle);
                  glVertex3f(x1,y1,z1);
            glEnd();
        }
    glPopMatrix();

    //ziemia
    glPushMatrix();
        x1=50.0f*sin(angle1);
        z1=50.0f*cos(angle1);
        glTranslatef(x1,y1,z1);
        glRotatef(alfa2,x1,y1,z1);
        glutWireSphere(3.0f,20,20);
    glPopMatrix();

glColor3f(1,1,1);
   //orbita księżyca
    glPushMatrix();
        glColor3f(1,1,1);
        x1=50.0f*sin(angle1);
        z1=50.0f*cos(angle1);
        glTranslatef(x1,y1,z1);
        for(float angle=0.0f;angle<=((2.0f*3.14159f)*1.0f);angle+=0.01f)
        {
            glBegin(GL_POINTS);
                  y2=5.0f*sin(angle);
                  z2=5.0f*cos(angle);
                  glVertex3f(x2,y2,z2);
            glEnd();
        }
    glPopMatrix();

    //księżyc
    glPushMatrix();
        glTranslatef(x1,y1,z1);
        y2=5.0f*sin(angle2);
        z2=5.0f*cos(angle2);
        glTranslatef(x2,y2,z2);
        glRotatef(alfa3,x2,y2,z2);
        glutWireSphere(0.4f,20,20);
    glPopMatrix();

glPopMatrix();


glPushMatrix();
    //orbita marsa
    glRotatef(-30,0,1,1);
    glPushMatrix();
        glColor3f(1,0,0);
        for(float angle=0.0f;angle<=((2.0f*3.14159f)*1.0f);angle+=0.001f)
        {
            glBegin(GL_POINTS);
                  x3=60.0f*sin(angle);
                  z3=60.0f*cos(angle);
                  glVertex3f(x3,y3,z3);
            glEnd();
        }
    glPopMatrix();

    //mars
    glPushMatrix();
        x3=60.0f*sin(angle3);
        z3=60.0f*cos(angle3);
        glTranslatef(x3,y3,z3);
        glRotatef(alfa2,x3,y3,z3);
        glutWireSphere(2.0f,20,20);
    glPopMatrix();
glPopMatrix();

glPushMatrix();
    //orbita merkurego
    glRotatef(-30,0,1,1);
    glPushMatrix();
        glColor3f(1,0,1);
        for(float angle=0.0f;angle<=((2.0f*3.14159f)*1.0f);angle+=0.001f)
        {
            glBegin(GL_POINTS);
                  x4=30.0f*sin(angle);
                  z4=30.0f*cos(angle);
                  glVertex3f(x4,y4,z4);
            glEnd();
        }
    glPopMatrix();

    //mrkury
    glPushMatrix();
        x4=30.0f*sin(angle4);
        z4=30.0f*cos(angle4);
        glTranslatef(x4,y4,z4);
        glRotatef(alfa2,x4,y4,z4);
        glutWireSphere(1.0f,20,20);
    glPopMatrix();
glPopMatrix();

glPushMatrix();
    //orbita wenus
    glRotatef(-30,0,1,1);
    glPushMatrix();
        glColor3f(0.5,0.7,0);
        for(float angle=0.0f;angle<=((2.0f*3.14159f)*1.0f);angle+=0.001f)
        {
            glBegin(GL_POINTS);
                  x5=40.0f*sin(angle);
                  z5=40.0f*cos(angle);
                  glVertex3f(x5,y5,z5);
            glEnd();
        }
    glPopMatrix();

    //wenus
    glPushMatrix();
        x5=40.0f*sin(angle5);
        z5=40.0f*cos(angle5);
        glTranslatef(x5,y5,z5);
        glRotatef(alfa2,x5,y5,z5);
        glutWireSphere(2.0f,20,20);
    glPopMatrix();
glPopMatrix();

glPushMatrix();
    //orbita jowisz
    glRotatef(-30,0,1,1);
    glPushMatrix();
        glColor3f(0.5,0.7,0.8);
        for(float angle=0.0f;angle<=((2.0f*3.14159f)*1.0f);angle+=0.001f)
        {
            glBegin(GL_POINTS);
                  x6=70.0f*sin(angle);
                  z6=70.0f*cos(angle);
                  glVertex3f(x6,y6,z6);
            glEnd();
        }
    glPopMatrix();

    //jowisz
    glPushMatrix();
        x6=70.0f*sin(angle6);
        z6=70.0f*cos(angle6);
        glTranslatef(x6,y6,z6);
        glRotatef(alfa2,x6,y6,z6);
        glutWireSphere(5.0f,20,20);
    glPopMatrix();
glPopMatrix();

glPushMatrix();
    //orbita saturn
    glRotatef(-30,0,1,1);
    glPushMatrix();
        glColor3f(0.8,0.8,0.8);
        for(float angle=0.0f;angle<=((2.0f*3.14159f)*1.0f);angle+=0.001f)
        {
            glBegin(GL_POINTS);
                  x7=80.0f*sin(angle);
                  z7=80.0f*cos(angle);
                  glVertex3f(x7,y7,z7);
            glEnd();
        }
    glPopMatrix();

    //saturn
    glPushMatrix();
        x7=80.0f*sin(angle7);
        z7=80.0f*cos(angle7);
        glTranslatef(x7,y7,z7);
        glRotatef(alfa2,x7,y7,z7);
        glutWireSphere(3.0f,20,20);
    glPopMatrix();

    glPushMatrix();
    //orbita saturna
    glPushMatrix();
        glColor3f(0.8,0.8,0.8);
        x7=80.0f*sin(angle7);
        z7=80.0f*cos(angle7);
        glTranslatef(x7,y7,z7);
        glRotatef(50,0,1,1);
        for(float angle=0.0f;angle<=((2.0f*3.14159f)*1.0f);angle+=0.01f)
        {
            for(float j=5;j<7;j+=0.3)
            {
                glBegin(GL_POINTS);
                      y8=j*sin(angle);
                      z8=j*cos(angle);
                      glVertex3f(x8,y8,z8);
                glEnd();
            }
        }

    glPopMatrix();

    glPopMatrix();

glPopMatrix();

glPushMatrix();
    //orbita uran
    glRotatef(-30,0,1,1);
    glPushMatrix();
        glColor3f(0.9,0.2,0.1);
        for(float angle=0.0f;angle<=((2.0f*3.14159f)*1.0f);angle+=0.001f)
        {
            glBegin(GL_POINTS);
                  x9=90.0f*sin(angle);
                  z9=90.0f*cos(angle);
                  glVertex3f(x9,y9,z9);
            glEnd();
        }
    glPopMatrix();

    //uran
    glPushMatrix();
        x9=90.0f*sin(angle8);
        z9=90.0f*cos(angle8);
        glTranslatef(x9,y9,z9);
        glRotatef(alfa2,x9,y9,z9);
        glutWireSphere(3.0f,20,20);
    glPopMatrix();
glPopMatrix();

glPushMatrix();
    //orbita neptun
    glRotatef(-30,0,1,1);
    glPushMatrix();
        glColor3f(0.9,0.8,0.1);
        for(float angle=0.0f;angle<=((2.0f*3.14159f)*1.0f);angle+=0.001f)
        {
            glBegin(GL_POINTS);
                  x10=100.0f*sin(angle);
                  z10=100.0f*cos(angle);
                  glVertex3f(x10,y10,z10);
            glEnd();
        }
    glPopMatrix();

    //neptun
    glPushMatrix();
        x10=100.0f*sin(angle9);
        z10=100.0f*cos(angle9);
        glTranslatef(x10,y10,z10);
        glRotatef(alfa2,x10,y10,z10);
        glutWireSphere(2.0f,20,20);
    glPopMatrix();
glPopMatrix();



glPopMatrix();
}

//Rysowanie sceny
void Display ()
{
    // kolor tła - zawartość bufora koloru
    glClearColor (0.0,0.0,0.0,1.0);

    // czyszczenie bufora koloru
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Ustawienie stosu macierzy modelowania
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    //dodanie kamery
    glpApplyCameraTransform (&frameCamera);

	glPushMatrix ();
        glPushMatrix();
            glTranslatef(0,-10,0);
		    Podloze ();
		glPopMatrix();
	    Rys_aktorow (0);
	glPopMatrix ();

    // skierowanie poleceń do wykonania
    glFlush ();

    // zamiana buforów koloru
    glutSwapBuffers();
}

void Reshape (int width, int height)
{
    // obszar renderingu - całe okno
    glViewport (0,0,width,height);

    // wybór macierzy rzutowania
    glMatrixMode (GL_PROJECTION);

    // macierz rzutowania = macierz jednostkowa
    glLoadIdentity ();

    // obliczenie aspektu obrazu z uwzględnieniem
    // przypadku, gdy wysokość obrazu wynosi 0
    GLdouble aspect = 1;
    GLfloat zakres = 250.0f;
    GLfloat blisko = 1.0f;
    GLfloat daleko = 250.0f;

    // rzutowanie ortogonalne
    if (rzut==ORTHO)
    {
        // skala 1:1
        if (skala==ASPECT_1_1)
        {
           if (width < height && width > 0)
              glOrtho (-zakres,zakres,-zakres*height/width,zakres*height/width,-zakres,zakres);
           else
               if (width >= height && height > 0)
                  glOrtho (-zakres*width/height,zakres*width/height,-zakres,zakres,-zakres,zakres);
        }
        else
            glOrtho (-zakres,zakres,-zakres,zakres,-zakres,zakres);
    }

    // rzutowanie perspektywiczne
    if (rzut==PERSP)
    {
        if (height > 0)
           aspect = width/(GLdouble)height;
        gluPerspective (fovy,aspect,blisko,daleko);
    }
    Display ();

}

void Keyboard (unsigned char key, int x, int y)
{
     switch (key)
     {
         /*
            case '1':
                 obrot1=!obrot1;
            break;
            case '2':
                 obrot2=!obrot2;
            break;
            case '3':
                 obrot3=!obrot3;
            break;
            */
     }
     glutPostRedisplay();
}

void SpecialKeys (int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_LEFT:
			glpRotateFrameLocalY(&frameCamera, 0.1);
			break;
		case GLUT_KEY_RIGHT:
		     glpRotateFrameLocalY(&frameCamera, -0.1);
		     break;
		case GLUT_KEY_UP:
		     glpMoveFrameForward(&frameCamera, 0.1f);
		     break;
		case GLUT_KEY_DOWN:
		     glpMoveFrameForward(&frameCamera, -0.1f);
		     break;
        case GLUT_KEY_PAGE_UP:
             glpMoveFrameUp(&frameCamera, 0.1f);
        break;
        case GLUT_KEY_PAGE_DOWN:
             glpMoveFrameUp(&frameCamera, -0.1f);
        break;

	}
	//odswiezenie okna
	glutPostRedisplay ();
}

//Wywolanie w czasie bezczynnosci

void TimerFunction (int value)
{
	glutPostRedisplay ();
	glutTimerFunc(3, TimerFunction, 1);
}

void Menu (int value)
{
    switch (value)
    {
        // obszar renderingu - całe okno
        case FULL_WINDOW:
             skala = FULL_WINDOW;
             Reshape (glutGet (GLUT_WINDOW_WIDTH),glutGet (GLUT_WINDOW_HEIGHT));
        break;

        // obszar renderingu - aspekt 1:1
        case ASPECT_1_1:
             skala = ASPECT_1_1;
             Reshape (glutGet (GLUT_WINDOW_WIDTH),glutGet (GLUT_WINDOW_HEIGHT));
        break;

		// rzutowanie ortogonalne
        case ORTHO:
             rzut=ORTHO;
             Reshape (glutGet (GLUT_WINDOW_WIDTH),glutGet (GLUT_WINDOW_HEIGHT));
        break;

        // rzutowanie perspektywiczne
        case PERSP:
             rzut=PERSP;
             Reshape (glutGet (GLUT_WINDOW_WIDTH),glutGet (GLUT_WINDOW_HEIGHT));
        break;

        // wyjście
        case EXIT:
        exit (0);
    }
    glutPostRedisplay();
}



int main (int argc, char **argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (800, 600);
	glutCreateWindow ("Laboratorium 5");
	glutReshapeFunc (Reshape);
	glutDisplayFunc (Display);
	glutKeyboardFunc (Keyboard);
	glutSpecialFunc (SpecialKeys);

	Ustawienia ();

	// dodanie pozycji do menu podręcznego
   	int MenuSkali = glutCreateMenu (Menu);
		glutAddMenuEntry ("Skalowanie - całe okno", FULL_WINDOW);
		glutAddMenuEntry ("Skalowanie - aspect_1_1", ASPECT_1_1);
	int MenuRzutowania = glutCreateMenu (Menu);
		glutAddMenuEntry ("Rzutowanie ortogonalne", ORTHO);
		glutAddMenuEntry ("Rzutowanie perspective", PERSP);
	// utworzenie menu podręcznego
	glutCreateMenu (Menu);
	glutAddSubMenu ("Skalowanie", MenuSkali);
    glutAddSubMenu ("Rzutowanie", MenuRzutowania);
	glutAddMenuEntry ("Wyjscie", EXIT);

    // określenie przycisku myszki obsługującej menu podręczne
    glutAttachMenu (GLUT_RIGHT_BUTTON);
    glutTimerFunc (3, TimerFunction, 1);
    //glutFullScreen();
	glutMainLoop ();
	Wyjscie ();
	return 0;
}
