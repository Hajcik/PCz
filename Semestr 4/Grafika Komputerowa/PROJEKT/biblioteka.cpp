
#include <string.h>
#include <math.h>
#include "biblioteka.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Dodawanie dwoch wektorow
void glpAddVectors(const GLPVector3 vFirst, const GLPVector3 vSecond, GLPVector3 vResult) {
    vResult[0] = vFirst[0] + vSecond[0];
    vResult[1] = vFirst[1] + vSecond[1];
    vResult[2] = vFirst[2] + vSecond[2];
    }

// Odejmowanie dwoch wektorow
void glpSubtractVectors(const GLPVector3 vFirst, const GLPVector3 vSecond, GLPVector3 vResult)
    {
    vResult[0] = vFirst[0] - vSecond[0];
    vResult[1] = vFirst[1] - vSecond[1];
    vResult[2] = vFirst[2] - vSecond[2];
    }

// Vektor skalarny
void glpScaleVector(GLPVector3 vVector, const GLfloat fScale)
    {
    vVector[0] *= fScale; vVector[1] *= fScale; vVector[2] *= fScale;
    }

// Dlugosc wektora kw
GLfloat glpGetVectorLengthSqrd(const GLPVector3 vVector)
    {
    return (vVector[0]*vVector[0]) + (vVector[1]*vVector[1]) + (vVector[2]*vVector[2]);
    }

// Dlugosc wektora
GLfloat glpGetVectorLength(const GLPVector3 vVector)
    {
    return (GLfloat)sqrt(glpGetVectorLengthSqrd(vVector));
    }

// Skalowanie wektora do jedynki
void glpNormalizeVector(GLPVector3 vNormal)
    {
    GLfloat fLength = 1.0f / glpGetVectorLength(vNormal);
    glpScaleVector(vNormal, fLength);
    }

// Kopiowanie wektora
void glpCopyVector(const GLPVector3 vSource, GLPVector3 vDest)
    {
    memcpy(vDest, vSource, sizeof(GLPVector3));
    }

// Iloczyn dwoch skalarny wektorow
GLfloat glpVectorDotProduct(const GLPVector3 vU, const GLPVector3 vV)
    {
    return vU[0]*vV[0] + vU[1]*vV[1] + vU[2]*vV[2];
    }

// Iloczyn wektorowy dwoch wektorow
void glpVectorCrossProduct(const GLPVector3 vU, const GLPVector3 vV, GLPVector3 vResult)
	{
	vResult[0] = vU[1]*vV[2] - vV[1]*vU[2];
	vResult[1] = -vU[0]*vV[2] + vV[0]*vU[2];
	vResult[2] = vU[0]*vV[1] - vV[0]*vU[1];
	}

// Wyznaczenie plaszczyzny normalnej
void glpGetNormalVector(const GLPVector3 vP1, const GLPVector3 vP2, const GLPVector3 vP3, GLPVector3 vNormal)
    {
    GLPVector3 vV1, vV2;

    glpSubtractVectors(vP2, vP1, vV1);
    glpSubtractVectors(vP3, vP1, vV2);

    glpVectorCrossProduct(vV1, vV2, vNormal);
    glpNormalizeVector(vNormal);
    }

// Przeksztalcenie punktu w macierz
void glpTransformPoint(const GLPVector3 vSrcVector, const GLPMatrix mMatrix, GLPVector3 vOut)
    {
    vOut[0] = mMatrix[0] * vSrcVector[0] + mMatrix[4] * vSrcVector[1] + mMatrix[8] *  vSrcVector[2] + mMatrix[12];
    vOut[1] = mMatrix[1] * vSrcVector[0] + mMatrix[5] * vSrcVector[1] + mMatrix[9] *  vSrcVector[2] + mMatrix[13];
    vOut[2] = mMatrix[2] * vSrcVector[0] + mMatrix[6] * vSrcVector[1] + mMatrix[10] * vSrcVector[2] + mMatrix[14];
    }

// Obrot wektora poprzez macierz obrotu
void glpRotateVector(const GLPVector3 vSrcVector, const GLPMatrix mMatrix, GLPVector3 vOut)
    {
    vOut[0] = mMatrix[0] * vSrcVector[0] + mMatrix[4] * vSrcVector[1] + mMatrix[8] *  vSrcVector[2];
    vOut[1] = mMatrix[1] * vSrcVector[0] + mMatrix[5] * vSrcVector[1] + mMatrix[9] *  vSrcVector[2];
    vOut[2] = mMatrix[2] * vSrcVector[0] + mMatrix[6] * vSrcVector[1] + mMatrix[10] * vSrcVector[2];
    }

// Wyznaczenie wspolczynnikow plaszczyzny
void glpGetPlaneEquation(GLPVector3 vPoint1, GLPVector3 vPoint2, GLPVector3 vPoint3, GLPVector3 vPlane)
    {
    glpGetNormalVector(vPoint1, vPoint2, vPoint3, vPlane);

    vPlane[3] = -(vPlane[0] * vPoint3[0] + vPlane[1] * vPoint3[1] + vPlane[2] * vPoint3[2]);
    }

// Odleglosz punktu od plaszczyzny
GLfloat glpDistanceToPlane(GLPVector3 vPoint, GLPVector4 vPlane)
    {
    return vPoint[0]*vPlane[0] + vPoint[1]*vPlane[1] + vPoint[2]*vPlane[2] + vPlane[3];
    }



// Ladowanie macierzy jednostkowej
void glpLoadIdentityMatrix(GLPMatrix m)
	{
	static GLPMatrix identity = { 1.0f, 0.0f, 0.0f, 0.0f,
                                     0.0f, 1.0f, 0.0f, 0.0f,
                                     0.0f, 0.0f, 1.0f, 0.0f,
                                     0.0f, 0.0f, 0.0f, 1.0f };

	memcpy(m, identity, sizeof(GLPMatrix));
	}

// Mnozenie dwoch macierzy 4x4
void glpMultiplyMatrix(const GLPMatrix m1, const GLPMatrix m2, GLPMatrix mProduct )
    {
    mProduct[0]     = m1[0] * m2[0] + m1[4] * m2[1] + m1[8] * m2[2] + m1[12] * m2[3];
    mProduct[4]     = m1[0] * m2[4] + m1[4] * m2[5] + m1[8] * m2[6] + m1[12] * m2[7];
    mProduct[8]     = m1[0] * m2[8] + m1[4] * m2[9] + m1[8] * m2[10] + m1[12] * m2[11];
    mProduct[12]    = m1[0] * m2[12] + m1[4] * m2[13] + m1[8] * m2[14] + m1[12] * m2[15];

    mProduct[1]     = m1[1] * m2[0] + m1[5] * m2[1] + m1[9] * m2[2] + m1[13] * m2[3];
    mProduct[5]     = m1[1] * m2[4] + m1[5] * m2[5] + m1[9] * m2[6] + m1[13] * m2[7];
    mProduct[9]     = m1[1] * m2[8] + m1[5] * m2[9] + m1[9] * m2[10] + m1[13] * m2[11];
    mProduct[13]    = m1[1] * m2[12] + m1[5] * m2[13] + m1[9] * m2[14] + m1[13] * m2[15];

    mProduct[2]     = m1[2] * m2[0] + m1[6] * m2[1] + m1[10] * m2[2] + m1[14] * m2[3];
    mProduct[6]     = m1[2] * m2[4] + m1[6] * m2[5] + m1[10] * m2[6] + m1[14] * m2[7];
    mProduct[10]    = m1[2] * m2[8] + m1[6] * m2[9] + m1[10] * m2[10] + m1[14] * m2[11];
    mProduct[14]    = m1[2] * m2[12] + m1[6] * m2[13] + m1[10] * m2[14] + m1[14] * m2[15];

    mProduct[3]     = m1[3] * m2[0] + m1[7] * m2[1] + m1[11] * m2[2] + m1[15] * m2[3];
    mProduct[7]     = m1[3] * m2[4] + m1[7] * m2[5] + m1[11] * m2[6] + m1[15] * m2[7];
    mProduct[11]    = m1[3] * m2[8] + m1[7] * m2[9] + m1[11] * m2[10] + m1[15] * m2[11];
    mProduct[15]    = m1[3] * m2[12] + m1[7] * m2[13] + m1[11] * m2[14] + m1[15] * m2[15];
    }

// Macierz przesuniecia
void glpTranslationMatrix(GLfloat x, GLfloat y, GLfloat z, GLPMatrix mTranslate)
    {
    glpLoadIdentityMatrix(mTranslate);
    mTranslate[12] = x;
    mTranslate[13] = y;
    mTranslate[14] = z;
    }

// Macierz skalowania
void glpScalingMatrix(GLfloat x, GLfloat y, GLfloat z, GLPMatrix mScale)
    {
    glpLoadIdentityMatrix(mScale);
    mScale[0] = x;
    mScale[5] = y;
    mScale[11] = z;
    }

// Macierz obrotu
void glpRotationMatrix(float angle, float x, float y, float z, GLPMatrix mMatrix)
    {
    float vecLength, sinSave, cosSave, oneMinusCos;
    float xx, yy, zz, xy, yz, zx, xs, ys, zs;

    if(x == 0.0f && y == 0.0f && z == 0.0f)
        {
        glpLoadIdentityMatrix(mMatrix);
        return;
        }

    vecLength = (float)sqrt( x*x + y*y + z*z );

    x /= vecLength;
    y /= vecLength;
    z /= vecLength;

    sinSave = (float)sin(angle);
    cosSave = (float)cos(angle);
    oneMinusCos = 1.0f - cosSave;

    xx = x * x;
    yy = y * y;
    zz = z * z;
    xy = x * y;
    yz = y * z;
    zx = z * x;
    xs = x * sinSave;
    ys = y * sinSave;
    zs = z * sinSave;

    mMatrix[0] = (oneMinusCos * xx) + cosSave;
    mMatrix[4] = (oneMinusCos * xy) - zs;
    mMatrix[8] = (oneMinusCos * zx) + ys;
    mMatrix[12] = 0.0f;

    mMatrix[1] = (oneMinusCos * xy) + zs;
    mMatrix[5] = (oneMinusCos * yy) + cosSave;
    mMatrix[9] = (oneMinusCos * yz) - xs;
    mMatrix[13] = 0.0f;

    mMatrix[2] = (oneMinusCos * zx) - ys;
    mMatrix[6] = (oneMinusCos * yz) + xs;
    mMatrix[10] = (oneMinusCos * zz) + cosSave;
    mMatrix[14] = 0.0f;

    mMatrix[3] = 0.0f;
    mMatrix[7] = 0.0f;
    mMatrix[11] = 0.0f;
    mMatrix[15] = 1.0f;
    }

// Macierz cieni
void glpMakeShadowMatrix(GLPVector3 vPoints[3], GLPVector4 vLightPos, GLPMatrix destMat)
    {
    GLPVector4 vPlaneEquation;
    GLfloat dot;

    glpGetPlaneEquation(vPoints[0], vPoints[1], vPoints[2], vPlaneEquation);

    dot =   vPlaneEquation[0]*vLightPos[0] +
            vPlaneEquation[1]*vLightPos[1] +
            vPlaneEquation[2]*vLightPos[2] +
            vPlaneEquation[3]*vLightPos[3];

    destMat[0] = dot - vLightPos[0] * vPlaneEquation[0];
    destMat[4] = 0.0f - vLightPos[0] * vPlaneEquation[1];
    destMat[8] = 0.0f - vLightPos[0] * vPlaneEquation[2];
    destMat[12] = 0.0f - vLightPos[0] * vPlaneEquation[3];

    destMat[1] = 0.0f - vLightPos[1] * vPlaneEquation[0];
    destMat[5] = dot - vLightPos[1] * vPlaneEquation[1];
    destMat[9] = 0.0f - vLightPos[1] * vPlaneEquation[2];
    destMat[13] = 0.0f - vLightPos[1] * vPlaneEquation[3];

    destMat[2] = 0.0f - vLightPos[2] * vPlaneEquation[0];
    destMat[6] = 0.0f - vLightPos[2] * vPlaneEquation[1];
    destMat[10] = dot - vLightPos[2] * vPlaneEquation[2];
    destMat[14] = 0.0f - vLightPos[2] * vPlaneEquation[3];

    destMat[3] = 0.0f - vLightPos[3] * vPlaneEquation[0];
    destMat[7] = 0.0f - vLightPos[3] * vPlaneEquation[1];
    destMat[11] = 0.0f - vLightPos[3] * vPlaneEquation[2];
    destMat[15] = dot - vLightPos[3] * vPlaneEquation[3];
    }

// Transpozycja macierzy
void glpTransposeMatrix(GLPMatrix mTranspose)
    {
    GLfloat temp;

    temp           = mTranspose[ 1];
    mTranspose[ 1] = mTranspose[ 4];
    mTranspose[ 4] = temp;

    temp           = mTranspose[ 2];
    mTranspose[ 2] = mTranspose[ 8];
    mTranspose[ 8] = temp;

    temp           = mTranspose[ 3];
    mTranspose[ 3] = mTranspose[12];
    mTranspose[12] = temp;

    temp           = mTranspose[ 6];
    mTranspose[ 6] = mTranspose[ 9];
    mTranspose[ 9] = temp;

    temp           = mTranspose[ 7];
    mTranspose[ 7] = mTranspose[13];
    mTranspose[13] = temp;

    temp           = mTranspose[11];
    mTranspose[11] = mTranspose[14];
    mTranspose[14] = temp;
    }

static float DetIJ(const GLPMatrix m, int i, int j)
    {
    int x, y, ii, jj;
    float ret, mat[3][3];

    x = 0;
    for (ii = 0; ii < 4; ii++)
        {
        if (ii == i) continue;
        y = 0;
        for (jj = 0; jj < 4; jj++)
            {
            if (jj == j) continue;
            mat[x][y] = m[(ii*4)+jj];
            y++;
            }
        x++;
        }

    ret =  mat[0][0]*(mat[1][1]*mat[2][2]-mat[2][1]*mat[1][2]);
    ret -= mat[0][1]*(mat[1][0]*mat[2][2]-mat[2][0]*mat[1][2]);
    ret += mat[0][2]*(mat[1][0]*mat[2][1]-mat[2][0]*mat[1][1]);

    return ret;
    }

// Odwracanie macierzy
void glpInvertMatrix(const GLPMatrix m, GLPMatrix mInverse)
    {
    int i, j;
    float det, detij;

    det = 0.0f;
    for (i = 0; i < 4; i++)
        {
        det += (i & 0x1) ? (-m[i] * DetIJ(m, 0, i)) : (m[i] * DetIJ(m, 0,i));
        }
    det = 1.0f / det;

    for (i = 0; i < 4; i++)
        {
        for (j = 0; j < 4; j++)
            {
            detij = DetIJ(m, j, i);
            mInverse[(i*4)+j] = ((i+j) & 0x1) ? (-detij * det) : (detij *det);
            }
        }
    }


// Inicjacja kamery
void glpInitFrame(GLPFrame *pFrame)
    {
    pFrame->vLocation[0] = 0.0f;
    pFrame->vLocation[1] = 0.0f;
    pFrame->vLocation[2] = 0.0f;

    pFrame->vUp[0] = 0.0f;
    pFrame->vUp[1] = 1.0f;
    pFrame->vUp[2] = 0.0f;

    pFrame->vForward[0] = 0.0f;
    pFrame->vForward[1] = 0.0f;
    pFrame->vForward[2] = -1.0f;
    }

// Wyznaczenie macierzy z ramki
void glpGetMatrixFromFrame(GLPFrame *pFrame, GLPMatrix mMatrix)
    {
    GLPVector3 vXAxis;

    glpVectorCrossProduct(pFrame->vUp, pFrame->vForward, vXAxis);

    memcpy(mMatrix, vXAxis, sizeof(GLPVector3));
    mMatrix[3] = 0.0f;

    memcpy(mMatrix+4, pFrame->vUp, sizeof(GLPVector3));
    mMatrix[7] = 0.0f;

    memcpy(mMatrix+8, pFrame->vForward, sizeof(GLPVector3));
    mMatrix[11] = 0.0f;

    memcpy(mMatrix+12, pFrame->vLocation, sizeof(GLPVector3));
    mMatrix[15] = 1.0f;
    }

// Dodanie aktora
void glpApplyActorTransform(GLPFrame *pFrame)
    {
    GLPMatrix mTransform;
    glpGetMatrixFromFrame(pFrame, mTransform);
    glMultMatrixf(mTransform);
    }

// Dodanie kamery
void glpApplyCameraTransform(GLPFrame *pCamera)
    {
    GLPMatrix mMatrix;
    GLPVector3 vAxisX;
    GLPVector3 zFlipped;

    zFlipped[0] = -pCamera->vForward[0];
    zFlipped[1] = -pCamera->vForward[1];
    zFlipped[2] = -pCamera->vForward[2];

    glpVectorCrossProduct(pCamera->vUp, zFlipped, vAxisX);

    mMatrix[0] = vAxisX[0];
    mMatrix[4] = vAxisX[1];
    mMatrix[8] = vAxisX[2];
    mMatrix[12] = 0.0f;

    mMatrix[1] = pCamera->vUp[0];
    mMatrix[5] = pCamera->vUp[1];
    mMatrix[9] = pCamera->vUp[2];
    mMatrix[13] = 0.0f;

    mMatrix[2] = zFlipped[0];
    mMatrix[6] = zFlipped[1];
    mMatrix[10] = zFlipped[2];
    mMatrix[14] = 0.0f;

    mMatrix[3] = 0.0f;
    mMatrix[7] = 0.0f;
    mMatrix[11] = 0.0f;
    mMatrix[15] = 1.0f;

    glMultMatrixf(mMatrix);

    glTranslatef(-pCamera->vLocation[0], -pCamera->vLocation[1], -pCamera->vLocation[2]);
    }

// Ruch kamery do przodu
void glpMoveFrameForward(GLPFrame *pFrame, GLfloat fStep)
    {
    pFrame->vLocation[0] += pFrame->vForward[0] * fStep;
    pFrame->vLocation[1] += pFrame->vForward[1] * fStep;
    pFrame->vLocation[2] += pFrame->vForward[2] * fStep;
    }

// Ruch kamery do gory
void glpMoveFrameUp(GLPFrame *pFrame, GLfloat fStep)
    {
    pFrame->vLocation[0] += pFrame->vUp[0] * fStep;
    pFrame->vLocation[1] += pFrame->vUp[1] * fStep;
    pFrame->vLocation[2] += pFrame->vUp[2] * fStep;
    }

// Ruch kamery w prawo
void glpMoveFrameRight(GLPFrame *pFrame, GLfloat fStep)
    {
    GLPVector3 vCross;

    glpVectorCrossProduct(pFrame->vUp, pFrame->vForward, vCross);
    pFrame->vLocation[0] += vCross[0] * fStep;
    pFrame->vLocation[1] += vCross[1] * fStep;
    pFrame->vLocation[2] += vCross[2] * fStep;
    }

// Przesuniecie swiata
void glpTranslateFrameWorld(GLPFrame *pFrame, GLfloat x, GLfloat y, GLfloat z)
    { pFrame->vLocation[0] += x; pFrame->vLocation[1] += y; pFrame->vLocation[2] += z; }

// Przesuniecie kamery
void glpTranslateFrameLocal(GLPFrame *pFrame, GLfloat x, GLfloat y, GLfloat z)
    {
    glpMoveFrameRight(pFrame, x);
    glpMoveFrameUp(pFrame, y);
    glpMoveFrameForward(pFrame, z);
    }

// Obrot kamery
void glpRotateFrameLocalY(GLPFrame *pFrame, GLfloat fAngle)
    {
    GLPMatrix mRotation;
    GLPVector3 vNewForward;

    glpRotationMatrix((float)glpDegToRad(fAngle), 0.0f, 1.0f, 0.0f, mRotation);
    glpRotationMatrix(fAngle, pFrame->vUp[0], pFrame->vUp[1], pFrame->vUp[2], mRotation);

    glpRotateVector(pFrame->vForward, mRotation, vNewForward);
    memcpy(pFrame->vForward, vNewForward, sizeof(GLPVector3));
    }

//  Obrot kamery
void glpRotateFrameLocalX(GLPFrame *pFrame, GLfloat fAngle)
    {
    GLPMatrix mRotation;
    GLPVector3 vCross;

    glpVectorCrossProduct(vCross, pFrame->vUp, pFrame->vForward);
    glpRotationMatrix(fAngle, vCross[0], vCross[1], vCross[2], mRotation);

    GLPVector3 vNewVect;
    vNewVect[0] = mRotation[0] * pFrame->vForward[0] + mRotation[4] * pFrame->vForward[1] + mRotation[8] *  pFrame->vForward[2];
    vNewVect[1] = mRotation[1] * pFrame->vForward[0] + mRotation[5] * pFrame->vForward[1] + mRotation[9] *  pFrame->vForward[2];
    vNewVect[2] = mRotation[2] * pFrame->vForward[0] + mRotation[6] * pFrame->vForward[1] + mRotation[10] * pFrame->vForward[2];
    memcpy(pFrame->vForward, vNewVect, sizeof(GLfloat)*3);

    vNewVect[0] = mRotation[0] * pFrame->vUp[0] + mRotation[4] * pFrame->vUp[1] + mRotation[8] *  pFrame->vUp[2];
    vNewVect[1] = mRotation[1] * pFrame->vUp[0] + mRotation[5] * pFrame->vUp[1] + mRotation[9] *  pFrame->vUp[2];
    vNewVect[2] = mRotation[2] * pFrame->vUp[0] + mRotation[6] * pFrame->vUp[1] + mRotation[10] * pFrame->vUp[2];
    memcpy(pFrame->vUp, vNewVect, sizeof(GLfloat) * 3);
    }

// Obrot kamery
void glpRotateFrameLocalZ(GLPFrame *pFrame, GLfloat fAngle)
    {
    GLPMatrix mRotation;

    glpRotationMatrix(fAngle, pFrame->vForward[0], pFrame->vForward[1], pFrame->vForward[2], mRotation);

    GLPVector3 vNewVect;
    vNewVect[0] = mRotation[0] * pFrame->vUp[0] + mRotation[4] * pFrame->vUp[1] + mRotation[8] *  pFrame->vUp[2];
    vNewVect[1] = mRotation[1] * pFrame->vUp[0] + mRotation[5] * pFrame->vUp[1] + mRotation[9] *  pFrame->vUp[2];
    vNewVect[2] = mRotation[2] * pFrame->vUp[0] + mRotation[6] * pFrame->vUp[1] + mRotation[10] * pFrame->vUp[2];
    memcpy(pFrame->vUp, vNewVect, sizeof(GLfloat) * 3);
    }
#pragma pack(1)
typedef struct
    {
    GLbyte	identsize;              // Size of ID field that follows header (0)
    GLbyte	colorMapType;           // 0 = None, 1 = paletted
    GLbyte	imageType;              // 0 = none, 1 = indexed, 2 = rgb, 3 = grey, +8=rle
    unsigned short	colorMapStart;          // First colour map entry
    unsigned short	colorMapLength;         // Number of colors
    unsigned char 	colorMapBits;   // bits per palette entry
    unsigned short	xstart;                 // image x origin
    unsigned short	ystart;                 // image y origin
    unsigned short	width;                  // width in pixels
    unsigned short	height;                 // height in pixels
    GLbyte	bits;                   // bits per pixel (8 16, 24, 32)
    GLbyte	descriptor;             // image descriptor
    } TGAHEADER;
#pragma pack(8)

GLubyte *glploadtga(const char *pFileName, GLint *pWidth, GLint *pHeight, GLint *pComponents, GLenum *pFormat)
    {
    FILE *pFile;			// File pointer
    TGAHEADER tgaHeader;		// TGA file header
    unsigned long ImageSize;		// Size in bytes of image
    short sDepth;			// Pixel depth;
    GLubyte	*pBits = NULL;          // Pointer to bits

    // Default/Failed values
    *pWidth = 0;
    *pHeight = 0;
    *pFormat = GL_RGB;
    *pComponents = GL_RGB8;

    // Attempt to open the fil
    pFile = fopen(pFileName, "rb");
    if(pFile == NULL)
        return NULL;

    // Read in header (binary)
    fread(&tgaHeader, 18/* sizeof(TGAHEADER)*/, 1, pFile);

    // Get width, height, and depth of texture
    *pWidth = tgaHeader.width;
    *pHeight = tgaHeader.height;
    sDepth = tgaHeader.bits / 8;

    // Put some validity checks here. Very simply, I only understand
    // or care about 8, 24, or 32 bit targa's.
    if(tgaHeader.bits != 8 && tgaHeader.bits != 24 && tgaHeader.bits != 32)
        return NULL;

    // Calculate size of image buffer
    ImageSize = tgaHeader.width * tgaHeader.height * sDepth;

    // Allocate memory and check for success
    pBits = (GLubyte *) malloc(ImageSize * sizeof(GLubyte));
    //pBits=NULL;
    if(pBits == NULL)
        return NULL;

    // Read in the bits
    // Check for read error. This should catch RLE or other
    // weird formats that I don't want to recognize
    if(fread(pBits, ImageSize, 1, pFile) != 1)
        {
        free(pBits);
        return NULL;
        }

    // Set OpenGL format expected
    switch(sDepth)
        {
        case 3:     // Most likely case
            *pFormat = GL_BGR_EXT;
            *pComponents = GL_RGB8;
            break;
        case 4:
            *pFormat = GL_BGRA_EXT;
            *pComponents = GL_RGBA8;
            break;
        case 1:
            *pFormat = GL_LUMINANCE;
            *pComponents = GL_LUMINANCE8;
            break;
        };


    // Done with File
    fclose(pFile);

    // Return pointer to image data
    return pBits;
    }


