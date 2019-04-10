#include "stdafx.h"
#include<iostream>
#include<cstdlib>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	int N1;
	int N2;
	int N3;
	cout << "Podaj wymiar macierzy: ";
	cin >> N1;
	cin >> N2;
	cin >> N3;
	int **A = new int*[N1];
	for (int i = 0; i < N1; i++)
		A[i] = new int[N1];

	for (int i = 0; i < N1; i++)
		for (int j = 0; j < N2; j++)
			cin >> A[i][j];

	int **B = new int*[N2];
	for (int i = 0; i < N1; i++)
		B[i] = new int[N1];

	for (int i = 0; i < N2; i++)
		for (int j = 0; j < N3; j++)
			cin >> B[i][j];

	int **C = new int*[N1];
	for (int i = 0; i < N1; i++)
		C[i] = new int[N1];

	for (int i = 0; i < N1; i++)
		for (int j = 0; j < N3; j++)
			cin >> C[i][j];


				__asm{		
					MOV ecx, N1;
				p1: PUSH ecx;
					MOV ecx, N3;
				p2: XOR ebx, ebx;
					MOV esi, A;
					MOV eax, [esp];
					MOV esi, [esi + 4 * eax - 4];
					PUSH ecx;
					MOV ecx, N2;
				p3: MOV edi, B;
					MOV eax, [esp];
					MOV edi, [edi + 4 * eax - 4];
					MOV eax, [edi + 4 * ecx - 4];
					MUL [esi + 4 * ecx - 4];
					ADD ebx, eax;
						LOOP p3;
					POP ecx;
					MOV esi, C;
					MOV eax, [esp];
					MOV esi, [esi + 4 * eax - 4];
					MOV [esi + 4 * ecx - 4], ebx;
					LOOP p2;
					POP ecx;
					LOOP p1;
				}

	for (int i = 0; i < N1; i++)
		for (int j = 0; j < N2; j++)
		{
		cout << C[i][j] << " ";
		}
	cout << "\n";

	system("PAUSE");
	return 0;
}
