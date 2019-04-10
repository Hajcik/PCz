#include "stdafx.h"
#include<iostream>
#include<cstdlib>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	int N1;
	cout << "Podaj wymiar macierzy: ";
	cin >> N1;
	int N2;
	cin >> N2;

	int **A = new int*[N1];
	for (int i = 0; i < N1; i++)
		A[i] = new int[N1];

	for (int i = 0; i < N1; i++)
		for (int j = 0; j < N2; j++)
			cin >> A[i][j];

	int **B = new int*[N1];
	for (int i = 0; i < N1; i++)
		B[i] = new int[N1];

	for (int i = 0; i < N1; i++)
		for (int j = 0; j < N2; j++)
			cin >> B[i][j];

				__asm{		// zewnetrzna petla o ile mozna to po wierwszach
					MOV ecx, N1;
				p1: MOV esi, A;
					MOV esi, [esi + 4 * ecx - 4];
					MOV edi, B;
					MOV edi, [edi + 4 * ecx - 4];
					PUSH ecx;
					MOV ecx, N2;
				p2:	MOV eax, [esi + 4 * ecx - 4];
					ADD eax, [edi + 4 * ecx - 4];
					MOV [esi + 4 * ecx - 4], eax;
					DEC ecx;
					JNZ p2;
					POP ecx;
					DEC ecx;
					JNZ p1;
				}

	for (int i = 0; i < N1; i++)
		for (int j = 0; j < N2; j++)
		{
		cout << A[i][j] << " ";
		}
	cout << "\n";

	system("PAUSE");
	return 0;
}
