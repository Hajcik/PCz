#include "stdafx.h"
#include<iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int N1;
	cin >> N1;
	int N2;
	cin >> N2;
	int* wektor_wej = new int[N2];
	for (int j = 0; j < N2; j++)
	{
		cin >> wektor_wej[j];
	}
	int* wektor_wyj = new int[N1];
	int** macierz = new int*[N1];
	for (int i = 0; i < N1; i++)
		macierz[i] = new int[N2];

	for (int i = 0; i < N1; i++)
		for (int j = 0; j < N2; j++)
			cin >> macierz[i][j];
		
			__asm
			{
				MOV ecx, N1;
			p1: MOV edi, macierz;
				MOV esi, [edi + 4 * ecx - 4];
				PUSH ecx;
				MOV edi, wektor_wej;
				MOV ecx, N2;
				XOR ebx, ebx;
			p2: MOV eax, [esi + 4 * ecx - 4];
				IMUL eax, [edi + 4 * ecx - 4];
				ADD ebx, eax;
				DEC ecx;
				JNZ p2;
				POP ecx;
				MOV edi, wektor_wyj;
				MOV[edi + 4 * ecx - 4], ebx;
				DEC ecx;
				JNZ p1;
			}
	
	for (int i = 0; i < N1; i++)
	{
		cout << wektor_wyj[i]<<" ";
	}
	system("PAUSE");
	return 0;
}

