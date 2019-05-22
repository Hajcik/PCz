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
		FLD [esi + 4 * ecx - 4];
		DEC ecx;
	petla1:
		FLD [esi + 4 * ecx - 4];
		FCOM st(1); // zawsze porownuje z st(0) // (fcmp nie dziala)
		FSTSW ax; // z flagami cos
		SAHF;	  // tez
		JC  pomin;
		FXCH;
	petla2:
		FLD[esi + 4 * ecx - 4];
		FCOM st(1);
		JC pomin;
		FSTSW ax;
		SAHF;
		FXCH;
	pomin:
		FSTP [esi + 4 * ecx]; // bo to juz jest mniejsze o 1, czy cos lol
		DEC ecx;
		JNZ petla2; // na petla2
		FSTP [esi]; 
		
		
		
		// do poprawienia by sortowalo cala tablice!!!!
		
	}
	for (int i = 0; i < N; i++)
		cout << A[i] << " ";
	system("PAUSE");
	return 0;
}

