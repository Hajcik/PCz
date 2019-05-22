// ConsoleApplication6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int N;
	cout << "Wprowadz n: ";
	cin >> N;
	
	float *A = new float[N];	// komórki po 4 bajty
	cout << "Podaj tablice: ";
	for (int i = 0; i < N; i++)
		cin >> A[i];

	// Sortowanie bąbelkowe
__asm{
		MOV ecx, N;
		MOV esi, A;
		FLD[esi + 4 * ecx - 4];
		DEC ecx;
petla1: 
		FLD [esi + 4 * ecx - 4];
		FCMP st(1); // zawsze porownuje z st(0) // (lub fcom, jak nie zadziala)
			
}
	system("PAUSE");
	return 0;
}

