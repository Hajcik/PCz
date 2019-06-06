#include <windows.h>
#include <iostream>
#include "biblioteka.h"
#include "biblioteka.cpp"
#include "glext.h"
#include "glpomoc.h"
#include "colors.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

using namespace std;

enum Wybor
{   SWIATLOOGOLNE,
    REFLEKTOR,
    BEZ_SWIATLA,
    ASPECT_1_1,
    FULL_WINDOW,
    FRUST,
    PRZYWROC,
    EXIT
};


GLPFrame frameCamera;

// macierze cieni typu matrix
GLPMatrix Macierz_cieni;
GLPMatrix Macierz_cieni2;
// kolor cienia
GLfloat fKolor_cienia[] = {0.0f,0.0f,0.0f,0.0f};
// cien powinien znajdowac sie troszke nad podloga
GLPVector3 vPoints[3] = { {0.0f, -1.9f,  0.0f},
                         {10.0f, -1.9f,  0.0f},
                          {5.0f, -1.9f, -5.0f}};
GLPVector3 vPoints2[3] = { {0.0f, -1.5f,  0.0f},
                          {10.0f, -1.5f,  0.0f},
                           {5.0f, -1.5f, -5.0f}};
GLPVector3 bezCienia[3] = { {0.0f, -50.5f,  0.0f},
                           {10.0f, -50.5f,  0.0f},
                           { 5.0f, -50.5f, -5.0f}};

GLdouble aspect = 1;
GLfloat zakres = 1.0f;
GLfloat blisko = 2.0f;
GLfloat daleko=100.0f;
GLdouble przybliz = 0.2;
GLfloat yyy=0;

static void display(void);
//static void display2(void);
int rzut=FRUST, skala=ASPECT_1_1;
int fovy=90;
int xx,yy,zz,xz,xy,yx,yz,zx,zy,obrot_y,obrot_x;


GLfloat fPozycja_swiatla_pod[] = { 2.0f, -2.0f, 0.0f, 1.0f };
GLfloat fPozycja_swiatla[] = {2.0f, 2.0f, 0.0f, 1.0f};
//kierunkowe
GLfloat fKierunek_reflektora[] = {0.0f, 1.0f, -12.0f, 1.0f};
GLfloat fKierunek_reflektora_pod[] = {0.0f, -1.5f, -12.0f, 1.0f};
GLfloat fPozycja_reflektora[] = {0.0f, 0.0f, 0.0f, 1.0f};
GLfloat fPozycja_reflektora_pod[] = {0.0f, 0.0f, 0.0f, 1.0f};

double a=0.0f;
GLfloat rozwarcie = 25.0f;
GLfloat skupienie = 2.0f;



GLfloat przesunX = 0.0;
GLfloat przesunZ = 0.0;

static int slices = 16;
static int stacks = 16;

static void pomoc()
{   cout<<" q - koniec"<<endl;
    cout<<" l - obrot piramidy w lewo"<<endl;
    cout<<" p - obrot piramidy w prawo"<<endl;
    cout<<" g - obrot piramidy w gore"<<endl;
    cout<<" d - obrot piramidy w dol"<<endl;       
	    
    cout<<" 4 - przesuwa swiatlo ogolne w lewo"<<endl;
    cout<<" 6 - przesuwa swiatlo ogolne w prawo"<<endl;
    cout<<" 8 - podwyzsza pozycje swiatla ogolnego"<<endl;
    cout<<" 2 - obniza pozycje swiatla ogolnego"<<endl;
    
    cout<<" h - przesuwa swiatlo reflektora w lewo"<<endl;
    cout<<" k - przesuwa swiatlo reflektora w prawo"<<endl;
    cout<<" u - podwyzsza pozycje reflektora"<<endl;
    cout<<" j - obniza pozycje reflektora"<<endl;
    
    cout<<" + - zwieksza rozwarcie reflektora"<<endl;
    cout<<" - - zmniejsza rozwarcie reflektora"<<endl;
    cout<<" * - zwieksza skupienie reflektora"<<endl;
    cout<<" / - zmniejsza skupienie reflektora"<<endl;
        
    cout<<"Ruchy kamery  "<<endl;
    cout<<"Kazde kolejne klikniecie przyspiesza ruch, hamowanie poprzez dzialania odwrotne (lewo-prawo; gora-dol )"<<endl;
    cout<<" strzalka w lewo - ruch kamery w prawo"<<endl;
    cout<<" stzralka w prawo - ruch kamery w lewo"<<endl;
    cout<<" strzaka w gore - ruch kamery w przod"<<endl;
    cout<<" strzaka w dol - ruch kamery w tyl"<<endl;
    cout<<" PageUp - ruch kamery w gore"<<endl;
    cout<<" PageDown - ruch kamery w dol"<<endl;
}

void podloze2()
{   glBegin( GL_QUADS );
    glNormal3f( 0.0, 1.0, 0.0 );
    // przy ka¿dej iteracji pêtli rysowane s¹ cztery prostok¹ty szachownicy

    for( GLfloat z = - 100.0; z < 100.0; z += 1 )
    { for( GLfloat x = - 100.0; x < 100.0; x += 1 )
      { glColor4f( Green[ 0 ], Green[ 1 ], Green[ 2 ], 0.75 );
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
	  
}


void podloze2o()
{  glBegin( GL_QUADS );
   glNormal3f( 0.0, 1.0, 0.0 );

    for( GLfloat z = - 100.0; z < 100.0; z += 1 )
    { for( GLfloat x = - 100.0; x < 100.0; x += 1 )
      { glColor4f( Green[ 0 ], Green[ 1 ], Green[ 2 ], 0.0 );
        glVertex3f( x + 0.0, 0.0, z + 0.0 );
        glVertex3f( x + 0.0, 0.0, z + 0.5 );
        glVertex3f( x + 0.5, 0.0, z + 0.5 );
        glVertex3f( x + 0.5, 0.0, z + 0.0 );
        glColor4f( Silver[ 0 ], Silver[ 1 ], Silver[ 2 ], 0.0 );
        glVertex3f( x + 0.5, 0.0, z + 0.0 );
        glVertex3f( x + 0.5, 0.0, z + 0.5 );
        glVertex3f( x + 1.0, 0.0, z + 0.5 );
        glVertex3f( x + 1.0, 0.0, z + 0.0 );
        glColor4f( Blue[ 0 ], Blue[ 1 ], Blue[ 2 ], 0.0 );
        glVertex3f( x + 0.5, 0.0, z + 0.5 );
        glVertex3f( x + 0.5, 0.0, z + 1.0 );
        glVertex3f( x + 1.0, 0.0, z + 1.0 );
        glVertex3f( x + 1.0, 0.0, z + 0.5 );
        glColor4f( Silver[ 0 ], Silver[ 1 ], Silver[ 2 ], 0.0 );
        glVertex3f( x + 0.0, 0.0, z + 0.5 );
        glVertex3f( x + 0.0, 0.0, z + 1.0 );
        glVertex3f( x + 0.5, 0.0, z + 1.0 );
        glVertex3f( x + 0.5, 0.0, z + 0.5 );
      }
    }

    glEnd();
}


static void Piramida(bool ktora, bool cien)
{       glPushMatrix();
        glColor4f(0.3f,0.0f,0.0f,0.6f);
        if(ktora)
            glTranslated(0+przesunX,1,-13+przesunZ);
        else
            glTranslated(0+przesunX,6,-13+przesunZ);
        glRotated(0,a,0,1);
        glRotatef(obrot_x,0.0f,1.0f,0.0f);
        glRotatef(obrot_y,xy,yy,zy);

        glDisable(GL_LIGHTING);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
        
	    //glColor3fv(Red);  
	    if(cien)
	      glColor4f(Black[0],Black[1], Black[2], 0.2f);     
	    else  
		  glColor4f(Red[0],Red[1], Red[2], 1.0f);    
	    glNormal3f( 0.0, 0.0, 1.0 );
	    glBegin(GL_QUADS);
	      glVertex3f(-2.0f, -2.0f+yyy, -2.0f); 
	      glVertex3f(2.0f, -2.0f+yyy, -2.0f); 
	      glVertex3f(2.0f, -2.0f+yyy, 2.0f);     
	      glVertex3f(-2.0f, -2.0f+yyy, 2.0f);      
	    glEnd();  
	    
	    //glColor3fv(Orange);   
	    if(cien)
	      glColor4f(Black[0],Black[1], Black[2], 0.2f);    
	    else  
		  glColor4f(Orange[0],Orange[1], Orange[2], 1.0f);  
	    glNormal3f( 0.0, 0.0, 1.0 );
	    glBegin(GL_TRIANGLES);
	      glVertex3f(-2.0f, -2.0f+yyy, 2.0f); 
	      glVertex3f(2.0f, -2.0f+yyy, 2.0f); 
	      glVertex3f(0.0f, 2.0f+yyy, 0.0f); 
	    glEnd(); 
	    
	    // glColor3fv(Yellow);   
	    if(cien)
	      glColor4f(Black[0],Black[1], Black[2], 0.2f);   
	    else  
		  glColor4f(Yellow[0],Yellow[1], Yellow[2], 1.0f);  
	    glNormal3f( 0.0, 0.0, 1.0 );
	    glBegin(GL_TRIANGLES);
	      glVertex3f(-2.0f, -2.0f+yyy, -2.0f); 
	      glVertex3f(2.0f, -2.0f+yyy, -2.0f); 
	      glVertex3f(0.0f, 2.0f+yyy, 0.0f); 
	    glEnd(); 
	    
	    //glColor3fv(Blue); 		   
	    if(cien)
	      glColor4f(Black[0],Black[1], Black[2], 0.2f);     
	    else  
		  glColor4f(Blue[0], Blue[1], Blue[2], 1.0f);    
	    glNormal3f( 0.0, 0.0, 1.0 );
	    glBegin(GL_TRIANGLES);
	      glVertex3f(-2.0f, -2.0f+yyy, -2.0f); 
	      glVertex3f(-2.0f, -2.0f+yyy, 2.0f); 
	      glVertex3f(0.0f, 2.0f+yyy, 0.0f); 
	    glEnd(); 
	    
	    //glColor3fv(Green);   
	    if(cien)
	      glColor4f(Black[0],Black[1], Black[2], 0.2f);      
	    else  
		  glColor4f(Green[0], Green[1], Green[2], 1.0f);    
	    glNormal3f( 0.0, 0.0, 1.0 );	 
	    glBegin(GL_TRIANGLES);
	      glVertex3f(2.0f, -2.0f+yyy, -2.0f); 
	      glVertex3f(2.0f, -2.0f+yyy, 2.0f); 
	      glVertex3f(0.0f, 2.0f+yyy, 0.0f); 
	    glEnd();     
	    
        glDisable(GL_BLEND);
        glEnable(GL_LIGHTING);
        glPopMatrix();
    
     
}

static void resize(int width, int height)
{   const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

void Reshape(int width,int height)
{   glViewport(0,0,width,height);   
    glMatrixMode(GL_PROJECTION);   
    glLoadIdentity();

    if(rzut==FRUST)
    {
        if (skala==ASPECT_1_1)
        {
        if (width < height && width > 0)
            glFrustum (-zakres,zakres,-zakres*height/width,zakres*height/width,blisko,daleko);
        else
            if (width >= height && height > 0)
            glFrustum (-zakres*width/height,zakres*width/height,-zakres,zakres,blisko,daleko);
        }
    else
        glFrustum (-zakres,zakres,-zakres,zakres,blisko,daleko);
    }

//******************************************************************************************************
    display();
}

static void przywracanie()
{  aspect = 1;
   zakres = 1.0f;
   blisko = 2.0f;
   daleko=100.0f;
   przybliz = 0.2;
}

void Menu(int value)
{   switch(value)
    { case EXIT:
        exit(0);
      case SWIATLOOGOLNE:
        glDisable(GL_LIGHT1);
        glEnable(GL_LIGHT0);
        glDisable(GL_LIGHT3);
        glEnable(GL_LIGHT2);
        
        glpMakeShadowMatrix(vPoints,fPozycja_swiatla,Macierz_cieni);
        glpMakeShadowMatrix(vPoints2,fPozycja_swiatla_pod,Macierz_cieni2);
        
        break;
      case REFLEKTOR:
        glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
        glEnable(GL_LIGHT3);
        glpMakeShadowMatrix(vPoints,fPozycja_reflektora,Macierz_cieni);
        glpMakeShadowMatrix(vPoints2,fPozycja_reflektora_pod,Macierz_cieni2);
        break;
      case BEZ_SWIATLA:
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
        glDisable(GL_LIGHT3);
        glpMakeShadowMatrix(bezCienia,fPozycja_swiatla,Macierz_cieni);
        break;
      case FULL_WINDOW:
        skala=FULL_WINDOW;
        przywracanie();
        Reshape(glutGet (GLUT_WINDOW_WIDTH),glutGet (GLUT_WINDOW_HEIGHT));
        break;
      case ASPECT_1_1:
        skala=ASPECT_1_1;
        przywracanie();
        Reshape (glutGet(GLUT_WINDOW_WIDTH),glutGet (GLUT_WINDOW_HEIGHT));
        break;    
      case FRUST:
        rzut=FRUST;
        przywracanie();
        Reshape (glutGet(GLUT_WINDOW_WIDTH),glutGet (GLUT_WINDOW_HEIGHT));
        break;    
      case PRZYWROC:
        rzut=FRUST;
        skala=ASPECT_1_1;
        przywracanie();
        resize(glutGet(GLUT_WINDOW_WIDTH),glutGet (GLUT_WINDOW_HEIGHT));
        break;
    }
    display();
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glpApplyCameraTransform (&frameCamera);

//********************************************************************
    //cien2
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glPushMatrix();
    glTranslated(0,-3,0);
    glMultMatrixf(Macierz_cieni);
    glColor4f(0,0,0,1);
    Piramida(false,false);
    glPopMatrix();
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glLightfv(GL_LIGHT2,GL_POSITION,fPozycja_swiatla_pod);
    glLightfv(GL_LIGHT3,GL_POSITION,fPozycja_reflektora_pod);
    glDisable(GL_BLEND);
    glEnable(GL_LIGHTING);

//odbicie:
    glDisable(GL_BLEND);
    glEnable(GL_LIGHTING);
    glPushMatrix();
    glFrontFace(GL_CW);
    glTranslated(0,0.85,0);
    glScalef(1.0f,-1.0f,1.0f);
    glTranslated(0,0.85,0);
    Piramida(false,false);
    glTranslated(0,-0.85,0);

    glFrontFace(GL_CCW);
    glPopMatrix();
    glDisable(GL_LIGHTING);
    glEnable(GL_BLEND);

  //********************************************************************
//podloga
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1,1,1,0.75);
    glPushMatrix();
    glTranslated(0,-2,0);
    podloze2();
    glPopMatrix();
//********************************************************************
//cien
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glPushMatrix();
    glMultMatrixf(Macierz_cieni);
    glColor4f(0,0,0,1);
    Piramida(true,true);
    glPopMatrix();
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glLightfv(GL_LIGHT0,GL_POSITION,fPozycja_swiatla);
    glLightfv(GL_LIGHT1,GL_POSITION,fPozycja_reflektora);
    glDisable(GL_BLEND);
    glEnable(GL_LIGHTING);

    //*********************************************************************
//prawdziwa
    glLightfv(GL_LIGHT0,GL_POSITION,fPozycja_swiatla);
    glLightfv(GL_LIGHT1,GL_POSITION,fPozycja_reflektora);
    Piramida(true,false);
    glutSwapBuffers();
}

//oba
GLfloat fSlabe_swiatlo[] = {0.25f, 0.25f, 0.25f, 1.0f};
GLfloat fMocne_swiatlo[] = {1.0f, 1.0f, 1.0f, 1.0f};

GLfloat fSlabe_swiatloR[] = {0.15f, 0.15f, 0.15f, 1.0f};
GLfloat fMocne_swiatloR[] = {1.0f, 1.0f, 1.0f, 1.0f};

//materialy
const GLfloat ambient[] = {0.0f, 0.0f, 0.0f, 0.0f};
const GLfloat diffuse[] = {0.0f, 0.0f, 0.0f, 0.0f};
const GLfloat specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat shininess[] = {0.5f, 0.5f, 0.5f, 1.0f};

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {   case 27:
        case 'q':
            exit(0);
            break;
        case '4':
            {  fPozycja_swiatla[0]-=1.0f;
               fPozycja_swiatla_pod[0]-=1.0f;
               glLightfv(GL_LIGHT0, GL_POSITION, fPozycja_swiatla);
               glLightfv(GL_LIGHT2, GL_POSITION, fPozycja_swiatla_pod);
               glpMakeShadowMatrix(vPoints,fPozycja_swiatla,Macierz_cieni);
               display();               
            }
            break;
        case '6':
            {  fPozycja_swiatla[0]+=1.0f;
               fPozycja_swiatla_pod[0]+=1.0f;
               glLightfv(GL_LIGHT0, GL_POSITION, fPozycja_swiatla);
               glLightfv(GL_LIGHT2, GL_POSITION, fPozycja_swiatla_pod);
               glpMakeShadowMatrix(vPoints,fPozycja_swiatla,Macierz_cieni);
               display();               
            }
            break;
        case '8':
            {  fPozycja_swiatla[1]+=1.0f;
               fPozycja_swiatla_pod[1]-=1.0f;
               glLightfv(GL_LIGHT0, GL_POSITION, fPozycja_swiatla);
               glLightfv(GL_LIGHT2, GL_POSITION, fPozycja_swiatla_pod);
               glpMakeShadowMatrix(vPoints,fPozycja_swiatla,Macierz_cieni);
               display();               
            }
            break;
        case '2':
            {  fPozycja_swiatla[1]-=1.0f;
               fPozycja_swiatla_pod[1]+=1.0f;
               glLightfv(GL_LIGHT0, GL_POSITION, fPozycja_swiatla);
               glLightfv(GL_LIGHT2, GL_POSITION, fPozycja_swiatla_pod);
               glpMakeShadowMatrix(vPoints,fPozycja_swiatla,Macierz_cieni);
               display();               
            }
            break;
         case 'h':
            {  fPozycja_reflektora[0]-=0.1f;
               fPozycja_reflektora_pod[0]+=0.1f;
               glLightfv (GL_LIGHT1, GL_POSITION, fPozycja_reflektora);
               glLightfv (GL_LIGHT3, GL_POSITION, fPozycja_reflektora_pod);
               display();
               glpMakeShadowMatrix(vPoints,fPozycja_reflektora,Macierz_cieni);               
            }
            break;
        case 'k':
            { fPozycja_reflektora[0]+=0.1f;
              fPozycja_reflektora_pod[0]-=0.1f;
              glLightfv (GL_LIGHT1, GL_POSITION, fPozycja_reflektora);
              glLightfv (GL_LIGHT3, GL_POSITION, fPozycja_reflektora_pod);
              display();
              glpMakeShadowMatrix(vPoints,fPozycja_reflektora,Macierz_cieni);               
            }
            break;
        case 'u':
            {
               fPozycja_reflektora[1]+=0.1f;
               fPozycja_reflektora_pod[1]-=0.1f;
               glLightfv (GL_LIGHT1, GL_POSITION, fPozycja_reflektora);
               glLightfv (GL_LIGHT3, GL_POSITION, fPozycja_reflektora_pod);
               display();
               glpMakeShadowMatrix(vPoints,fPozycja_reflektora,Macierz_cieni);               
            }
            break;
        case 'j':
            {  fPozycja_reflektora[1]-=0.1f;
               fPozycja_reflektora_pod[1]+=0.1f;
               glLightfv (GL_LIGHT1, GL_POSITION, fPozycja_reflektora);
               glLightfv (GL_LIGHT3, GL_POSITION, fPozycja_reflektora_pod);
               display();
               glpMakeShadowMatrix(vPoints,fPozycja_reflektora,Macierz_cieni);               
            }
            break;
               
       case '+':
        {   rozwarcie++;
            glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, rozwarcie);
            glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, rozwarcie);
            display();
        }
            break;
       case '*':
        {   skupienie++;
            glLightf(GL_LIGHT1,GL_SPOT_EXPONENT,skupienie);
            glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, skupienie);
            display();
        }
            break;
        case '-':
        {   rozwarcie--;
            glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, rozwarcie);
            glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, rozwarcie);
            display();
        }
            break;
       case '/':
        {
            skupienie--;            
            glLightf(GL_LIGHT1,GL_SPOT_EXPONENT,skupienie);
            glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, skupienie);
            display();
        }
            break;
        case 'l':    //lewo
        {
            xx=0;
            yx=1;
            zx=0;
            obrot_x=obrot_x+5;
        }
            break;
        case 'p':        //prawo
        {
            xx=0;
            yx=1;
            zx=0;
            obrot_x=obrot_x-5;
        }
            break;
        case 'g':        //gora
        {
            xy=1;
            yy=0;
            zy=0;
            obrot_y=obrot_y+5;
        }
            break;
        case 'd':       //dol
        {
            xy=1;
            yy=0;
            zy=0;
            obrot_y=obrot_y-5;
        }
            break;   
    }
    glutPostRedisplay();

}


void Sterowanie_kamera (int key, int x, int y)
{   switch (key)
    {   case GLUT_KEY_LEFT:
            glpRotateFrameLocalY(&frameCamera, 0.001f);
            break;
        case GLUT_KEY_RIGHT:
            glpRotateFrameLocalY(&frameCamera, -0.001f);
            break;
        case GLUT_KEY_UP:
            glpMoveFrameForward(&frameCamera, 0.001f);    
            break;
        case GLUT_KEY_DOWN:
            glpMoveFrameForward(&frameCamera, -0.001f);          
            break;
        case GLUT_KEY_PAGE_UP:
            glpMoveFrameUp(&frameCamera, 0.001f);
            break;
        case GLUT_KEY_PAGE_DOWN:
            glpMoveFrameUp(&frameCamera, -0.001f);
            break;
         case GLUT_KEY_END:
         	/* zatrzymanie niekontrolowanego ruchu kamery
         	glpRotateFrameLocalY(&frameCamera, cos1);
            glpMoveFrameUp(&frameCamera, cos2);
            glpMoveFrameForward(&frameCamera, cos3);  
            */
            break;    
    }
    display();
    
}

static void idle(void)
{
    glutPostRedisplay();
}

/* Program entry point */

int main(int argc, char *argv[])
{   glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GKiW Lab12 - cien");
    pomoc();


    glpInitFrame (&frameCamera);
    glutReshapeFunc(Reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);
    glutSpecialFunc (Sterowanie_kamera);

    glClearColor(1,0.8,0.95,0);
    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    //glDepthFunc(GL_EQUAL);

    glEnable(GL_LIGHTING);
    glDisable(GL_LIGHT0);   //ogolne gora
    glDisable(GL_LIGHT1);   //reflektor gora
    glDisable(GL_LIGHT2);   //ogolne dol
    glDisable(GL_LIGHT3);   //reflektor dol
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  fSlabe_swiatlo);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  fMocne_swiatlo);
    glLightfv(GL_LIGHT0, GL_SPECULAR, fMocne_swiatlo);
    glLightfv(GL_LIGHT0, GL_POSITION, fPozycja_swiatla);

    glLightfv(GL_LIGHT2, GL_AMBIENT,  fSlabe_swiatlo);
    glLightfv(GL_LIGHT2, GL_DIFFUSE,  fMocne_swiatlo);
    glLightfv(GL_LIGHT2, GL_SPECULAR, fMocne_swiatlo);
    glLightfv(GL_LIGHT2, GL_POSITION, fPozycja_swiatla_pod);

    glLightfv (GL_LIGHT1, GL_AMBIENT, fSlabe_swiatloR);
    glLightfv (GL_LIGHT1, GL_DIFFUSE, fMocne_swiatloR);
    glLightfv (GL_LIGHT1, GL_SPECULAR, fMocne_swiatloR);
    glLightfv (GL_LIGHT1, GL_POSITION, fPozycja_reflektora);
    glLightfv (GL_LIGHT1, GL_SPOT_DIRECTION, fKierunek_reflektora);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, rozwarcie);
    glLightf(GL_LIGHT1,GL_SPOT_EXPONENT,skupienie);

    glLightfv (GL_LIGHT3, GL_AMBIENT, fSlabe_swiatloR);
    glLightfv (GL_LIGHT3, GL_DIFFUSE, fMocne_swiatloR);
    glLightfv (GL_LIGHT3, GL_SPECULAR, fMocne_swiatloR);
    glLightfv (GL_LIGHT3, GL_POSITION, fPozycja_reflektora_pod);
    glLightfv (GL_LIGHT3, GL_SPOT_DIRECTION, fKierunek_reflektora_pod);
    glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, rozwarcie);
    glLightf(GL_LIGHT3,GL_SPOT_EXPONENT,skupienie);

    glMaterialfv(GL_FRONT, GL_AMBIENT,  ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,  diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

    glutCreateMenu(Menu);
    glutAddMenuEntry("Swiatlo ogolne",SWIATLOOGOLNE);
    glutAddMenuEntry("Reflektor",REFLEKTOR);
    glutAddMenuEntry("Wylacz wszystkie swiatla",BEZ_SWIATLA);
    glutAddMenuEntry ("Rodzaj skalowania - cale okno",FULL_WINDOW);
    glutAddMenuEntry ("Rodzaj skalowania - skala 1:1",ASPECT_1_1);
    glutAddMenuEntry("Wyjscie",EXIT);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();

    return EXIT_SUCCESS;
}

