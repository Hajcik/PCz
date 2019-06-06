// glpomoc.h
// Pomocne narzedzia, ktorych zabraklo w bibliotece glut.h

#ifndef __GLPOMOC
#define __GLPOMOC

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <sys/time.h>
//#endif

#include <math.h>

// Uzyteczne stale
#define GLP_PI	3.14159265358979323846
#define GLP_PI_DIV_180 0.017453292519943296
#define GLP_INV_PI_DIV_180 57.2957795130823229

// Uzyteczne przeliczniki
#define glpDegToRad(x)	((x)*GLP_PI_DIV_180)
#define glpRadToDeg(x)	((x)*GLP_INV_PI_DIV_180)

// Typy danych
typedef GLfloat GLPVector2[2];
typedef GLfloat GLPVector3[3];
typedef GLfloat GLPVector4[4];
typedef GLfloat GLPMatrix[16];

typedef struct{
    GLPVector3 vLocation;
    GLPVector3 vUp;
    GLPVector3 vForward;
    } GLPFrame;

// Funkcje dla wektorw z glvector.cpp
void glpAddVectors(const GLPVector3 vFirst, const GLPVector3 vSecond, GLPVector3 vResult);
void glpSubtractVectors(const GLPVector3 vFirst, const GLPVector3 vSecond, GLPVector3 vResult);
void glpScaleVector(GLPVector3 vVector, const GLfloat fScale);
GLfloat glpGetVectorLengthSqrd(const GLPVector3 vVector);
GLfloat glpGetVectorLength(const GLPVector3 vVector);
void glpNormalizeVector(GLPVector3 vNormal);
void glpGetNormalVector(const GLPVector3 vP1, const GLPVector3 vP2, const GLPVector3 vP3, GLPVector3 vNormal);
void glpCopyVector(const GLPVector3 vSource, GLPVector3 vDest);
GLfloat glpVectorDotProduct(const GLPVector3 u, const GLPVector3 v);
void glpVectorCrossProduct(const GLPVector3 vU, const GLPVector3 vV, GLPVector3 vResult);
void glpTransformPoint(const GLPVector3 vSrcPoint, const GLPMatrix mMatrix, GLPVector3 vPointOut);
void glpRotateVector(const GLPVector3 vSrcVector, const GLPMatrix mMatrix, GLPVector3 vPointOut);
void glpGetPlaneEquation(GLPVector3 vPoint1, GLPVector3 vPoint2, GLPVector3 vPoint3, GLPVector3 vPlane);
GLfloat glpDistanceToPlane(GLPVector3 vPoint, GLPVector4 vPlane);

// Funkcje dla macierzy z glmatrix.cpp
void glpLoadIdentityMatrix(GLPMatrix m);
void glpMultiplyMatrix(const GLPMatrix m1, const GLPMatrix m2, GLPMatrix mProduct );
void glpRotationMatrix(float angle, float x, float y, float z, GLPMatrix mMatrix);
void glpTranslationMatrix(GLfloat x, GLfloat y, GLfloat z, GLPMatrix mTranslate);
void glpScalingMatrix(GLfloat x, GLfloat y, GLfloat z, GLPMatrix mScale);
void glpMakeShadowMatrix(GLPVector3 vPoints[3], GLPVector4 vLightPos, GLPMatrix destMat);
void glpTransposeMatrix(GLPMatrix mTranspose);
void glpInvertMatrix(const GLPMatrix m, GLPMatrix mInverse);

// Funkcje dla kamery z glframe.cpp
void glpInitFrame(GLPFrame *pFrame);
void glpGetMatrixFromFrame(GLPFrame *pFrame, GLPMatrix mMatrix);
void glpApplyActorTransform(GLPFrame *pFrame);
void glpApplyCameraTransform(GLPFrame *pCamera);
void glpMoveFrameForward(GLPFrame *pFrame, GLfloat fStep);
void glpMoveFrameUp(GLPFrame *pFrame, GLfloat fStep);
void glpMoveFrameRight(GLPFrame *pFrame, GLfloat fStep);
void glpTranslateFrameWorld(GLPFrame *pFrame, GLfloat x, GLfloat y, GLfloat z);
void glpTranslateFrameLocal(GLPFrame *pFrame, GLfloat x, GLfloat y, GLfloat z);
void glpRotateFrameLocalY(GLPFrame *pFrame, GLfloat fAngle);

// Funkcja do ladoania pliku graficznego
GLubyte *glploadtga(const char *pFileName, GLint *pWidth, GLint *pHeight, GLint *pComponents, GLenum *pFormat);

#endif
