#include "stdafx.h"
#include<iostream>
#include<cstdlib>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int N1;
	cout << "Podaj wymiar macierzy: ";
	cin >> N1;
	int **A = new int*[N1];
	for (int i = 0; i < N1; i++)
		A[i] = new int[N1];

	for (int i = 0; i < N1; i++)
		for (int j = 0; j < N1; j++)
			cin >> A[i][j];

				__asm{
					XOR eax, eax;
					MOV ecx, N1;
					MOV esi, A;
				p1: MOV edi, [esi + 4 * ecx - 4];
					PUSH ecx;
					MOV ecx, N1;
				p2: MOV[edi + 4 * ecx - 4], eax;
					DEC ecx;
					JNZ p2;
					POP ecx;
					DEC ecx;
					JNZ p1;
				}
	for (int i = 0; i < N1; i++)
		for (int j = 0; j < N1; j++)
			cout << A[i][j] << " ";
	
	system("PAUSE");
	return 0;
}
