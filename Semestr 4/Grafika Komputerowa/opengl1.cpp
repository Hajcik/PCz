// Codeblocks -> GLUT Project
// Linker settings - glut32

#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

#include <GL/glut.h>
#include <stdlib.h>

GLdouble ColorR=1.0, ColorB=0.0, ColorG=1.0;
int figura=6;
// aspekt obrazu

// stale do obslugi menu podrecznego
enum
{  Color_1,
   Color_2,
   Color_3,
   szeciobok,
   czworobok,
   trojkat,
   EXIT
};

// funkcja generujaca scene 3D
void Display()
{  // ustala kolor tla czyli zawartoœæ bufora koloru
   glClearColor( 0.5, 0.8, 1.0, 1.0 );
   // funkcja czyszczaca bufor koloru
   glClear( GL_COLOR_BUFFER_BIT );
   // ustalenie aktywnego koloru np. rysownia krawedzi, wypelniania obszaru
   glColor3f(ColorR, ColorB, ColorG);
   // pocz¹tek definicji wielok¹ta
   glBegin( GL_POLYGON );
    switch(figura)
    {  case 3:
         // kolejne wierzcholki trojkata
         glVertex3f( -0.6, -0.2, 0.0 );
         glVertex3f( 0.4, 0.7, 0.0 );
         glVertex3f( 0.1, -0.3, 0.0 );
         // koniec definicji trojkata
       break;
       case 4:
         glVertex3f( -0.5, 0.5, 0.0 );
         glVertex3f( 0.5, 0.4, 0.0 );
         glVertex3f( 0.5, -0.4, 0.0 );
         glVertex3f( -0.5, -0.5, 0.0 );
       break;
       case 6:
         glVertex3f( -0.5, 0.5, 0.0 );
         glVertex3f( 0.0, 0.9, 0.0 );
         glVertex3f( 0.5, 0.5, 0.0 );
         glVertex3f( 0.5, -0.5, 0.0 );
         glVertex3f( 0.0, -0.9, 0.0 );
         glVertex3f( -0.5, -0.5, 0.0 );
       break;
    }
   glEnd();

   // skierowanie poleceñ do wykonania
   glFlush();
   // zamiana buforow koloru
   glutSwapBuffers();
}

// zmiana wielkości okna -
void Reshape( int width, int height )
{  Display();
}


// obsluga menu podrecznego
void Menu( int value )
{  switch( value )
   {  case Color_1:
        ColorR=1.0, ColorB=1.0, ColorG=1.0; Display(); break;
      case Color_2:
        ColorR=0.6, ColorB=0.6, ColorG=0.6; Display(); break;
      case Color_3:
        ColorR=0.0, ColorB=1.0, ColorG=1.0; Display(); break;
      case szeciobok:
        figura=6;  Display(); break;
      case czworobok:
        figura=4;  Display(); break;
      case trojkat:
        figura=3;  Display(); break;
      case EXIT:
        exit( 0 );
    }
}

int main( int argc, char * argv[] )
{   // inicjalizacja biblioteki GLUT
    glutInit( & argc, argv );
    // inicjalizacja bufora ramki
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
    // rozmiary glownego okna programu
    glutInitWindowSize( 600, 400 );
    // utworzenie glownego okna programu
    #ifdef WIN32
      glutCreateWindow( "Moj pierwszy program w OpenGL" );
    #else
      glutCreateWindow( "Moj pierwszy program w OpenGL" );
    #endif
    // dolaczenie funkcji generujacej scene 3D
    glutDisplayFunc( Display );
    // dolaczenie funkcji wywolywanej przy zmianie rozmiaru okna
    glutReshapeFunc( Reshape );
    // utworzenie menu podrecznego
    glutCreateMenu( Menu );
    // dodatnie pozycji do menu podrecznego
    #ifdef WIN32
      glutAddMenuEntry( "Color_1", Color_1  );
      glutAddMenuEntry( "Color_2", Color_2 );
      glutAddMenuEntry( "Color_3", Color_3 );
      glutAddMenuEntry( "Trojkat", trojkat  );
      glutAddMenuEntry( "czworobok", czworobok);
      glutAddMenuEntry( "szczesciobok", szeciobok);
      glutAddMenuEntry( "Wyjscie", EXIT );
    #else
      glutAddMenuEntry( "Color_1", Color_1 );
      glutAddMenuEntry( "Color_2", Color_2 );
      glutAddMenuEntry( "Color_3", Color_2 );
      glutAddMenuEntry( "Trojkat", trojkat );
      glutAddMenuEntry( "czworobok", czworobok);
      glutAddMenuEntry( "szczesciobok", szeciobok);
      glutAddMenuEntry( "Wyjscie", EXIT );
    #endif

    // określenie przycisku myszki obslugujacej menu podreczne
    glutAttachMenu( GLUT_RIGHT_BUTTON );
    // wprowadzenie programu do obslugi petli komunikatow
    glutMainLoop();
    return 0;
}
