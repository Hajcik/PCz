#include <GL/glut.h>
#include <GL/glext.h>
#include <stdlib.h>
#include "colors.h"
#include "biblioteka.h"
#include "biblioteka.cpp"
#include "glext.h"
#include "glpomoc.h"

#define LICZBA_OB_TEXTUR 2      //liczba tesktur
GLuint obiektyTextur [LICZBA_OB_TEXTUR];
char *plikiTextur[LICZBA_OB_TEXTUR] = {".//pustynia.tga", ".//niebo.tga" };

enum
{  EXIT // wyjœcie
};

const GLdouble left = - 2.0;
const GLdouble right = 2.0;
const GLdouble bottom = - 2.0;
const GLdouble top = 2.0;
const GLdouble blisko = 2.0;
const GLdouble daleko = 7.0;

GLfloat rotatex = 0.0;
GLfloat rotatey = 0.0;
int button_state = GLUT_UP;
int button_x, button_y;


void Obrazek()
{   glBindTexture (GL_TEXTURE_2D, obiektyTextur[0]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_BORDER);

    
    glColor3fv( White);
    glPushMatrix();
    
    glEnable(GL_TEXTURE_2D);        
    //kwadrat
    glBegin(GL_QUADS);
      glNormal3f(0.0f, 0.0f, 1.0f);    
      glTexCoord2f(0.0f, 0.0f); // okreœlenie pierwszej wspó³rzêdnej tekstury
     glVertex3f(-1.0f, -1.0f, 1.0f); 
      glTexCoord2f(1.0f, 0.0f); 
     glVertex3f(1.0f, -1.0f, 1.0f); 
      glTexCoord2f(1.0f, 1.0f); 
     glVertex3f(1.0f, 1.0f, 1.0f);     
      glTexCoord2f(0.0f, 1.0f); 
     glVertex3f(-1.0f, 1.0f, 1.0f);      
    glEnd();    
    glDisable(GL_TEXTURE_2D);
    
    glBindTexture (GL_TEXTURE_2D, obiektyTextur[1]);
    glEnable(GL_TEXTURE_2D);        
    //przednia sciana
    glBegin(GL_TRIANGLES);
      glNormal3f(0.0f, 0.0f, 1.0f);    
      glTexCoord2f(0.0f, 0.0f); // okreœlenie pierwszej wspó³rzêdnej tekstury
     glVertex3f(-1.2f, 1.0f, 1.0f); 
      glTexCoord2f(1.0f, 0.0f); 
     glVertex3f(1.2f, 1.0f, 1.0f); 
      glTexCoord2f(0.5f, 1.0f); 
     glVertex3f(0.0f, 2.5f, 1.0f);     
    glEnd();    
    glDisable(GL_TEXTURE_2D);
    
    glPopMatrix();
    
}


void DisplayScene()
{  glClearColor( 1.0, 1.0, 1.0, 1.0 );
   glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
   glMatrixMode( GL_MODELVIEW );
   glLoadIdentity();
   glTranslatef( 0.0, 0.0, -( blisko + daleko ) / 2 );
    
   glRotatef( rotatex, 1.0, 0.0, 0.0 );
   glRotatef( rotatey, 0.0, 1.0, 0.0 );

   glScalef( 1.2, 1.2, 1.2 );
    
   glEnable( GL_DEPTH_TEST );
   Obrazek();
   glFlush();
   glutSwapBuffers();
}


void Reshape( int width, int height )
{   glViewport( 0, 0, width, height );    
    glMatrixMode( GL_PROJECTION );    
    glLoadIdentity();
    glFrustum( left, right, bottom, top, blisko, daleko );
    DisplayScene();
}


void MouseButton( int button, int state, int x, int y )
{   if( button == GLUT_LEFT_BUTTON )
    {  button_state = state;
       if( state == GLUT_DOWN )
       {   button_x = x;
           button_y = y;
       }
    }
}


void MouseMotion( int x, int y )
{   if( button_state == GLUT_DOWN )
    {   rotatey += 30 *( right - left ) / glutGet( GLUT_WINDOW_WIDTH ) *( x - button_x );
        button_x = x;
        rotatex -= 30 *( top - bottom ) / glutGet( GLUT_WINDOW_HEIGHT ) *( button_y - y );
        button_y = y;
        glutPostRedisplay();
    }
}


void Menu( int value )
{ switch( value )
  {  case EXIT:
       glDeleteTextures (LICZBA_OB_TEXTUR, obiektyTextur);
       exit( 0 );
  }
}


int main( int argc, char * argv[] )
{   glutInit( & argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize( 600, 600 );
    #ifdef WIN32    
      glutCreateWindow( "GKiW Lab 13 Teksturowanie - przyklad" );
    #else    
      glutCreateWindow( "GKiW Lab 13 Teksturowanie - przyklad" );
    #endif
    
    glEnable(GL_TEXTURE_2D);  
    glGenTextures(LICZBA_OB_TEXTUR,obiektyTextur);  
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); 
    
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        
    for(int i=0;i<LICZBA_OB_TEXTUR;i++)
    {   GLubyte *pBytes;
        GLint iWidth,iHeight,iComponents;
        GLenum eFormat;
        glBindTexture(GL_TEXTURE_2D,obiektyTextur[i]);   
        pBytes = glploadtga(plikiTextur[i],&iWidth,&iHeight,&iComponents,&eFormat);  
        gluBuild2DMipmaps(GL_TEXTURE_2D,iComponents,iWidth,iHeight,eFormat,GL_UNSIGNED_BYTE,pBytes);
        free(pBytes); 
    }
        
    glutDisplayFunc( DisplayScene );    
    glutReshapeFunc( Reshape );
    glutMouseFunc( MouseButton );
    glutMotionFunc( MouseMotion );

    glutCreateMenu( Menu );
    #ifdef WIN32
      glutAddMenuEntry( "Wyjscie", EXIT );
    #else
      glutAddMenuEntry( "Wyjscie", EXIT );
    #endif

    glutAttachMenu( GLUT_RIGHT_BUTTON );
    glutMainLoop();
    return 0;
}









