#include<iostream>
#include "stdafx.h"
#include<Windows.h>
using namespace std;
//Instrukcja 5b			 tab    N1  N2
extern "C" INT64 suma32(int**, int, int);
extern "C" INT64 suma64(INT64**, INT64, INT64);

int _tmain(int argc, _TCHAR* argv[])
{
	//asm 32 bit
	int N1; // wiersze
	int N2; // kolumny
	cin >> N1 >> N2;
	int **tab = new int*[N1]; // <- tabela wskaznikow, tworzymy
	for (int i = 0; i < N1; i++)
		tab[i] = new int[N2];

	cout << "Wypelnij tabele\n";
		for (int i = 0; i < N1; i++)
			for (int j = 0; j < N2; j++)
				cin>>tab[i][j];
		cout <<"ASM 32 BIT: "<< suma32(tab, N1, N2) << endl << endl;

	// asm 64 bit
	INT64 N1_64; // wiersze
	INT64 N2_64; // kolumny
	cin >> N1_64 >> N2_64;
	INT64 **tab64 = new INT64*[N1_64]; // <- tabela wskaznikow, tworzymy
	for (int i = 0; i < N1_64; i++)
		tab64[i] = new INT64[N2_64];

	cout << "Wypelnij tabele\n";
		for (int i = 0; i < N1_64; i++)
			for (int j = 0; j < N2_64; j++)
				cin>>tab64[i][j];
		
		cout <<"ASM 64 BIT: "<< suma64(tab64, N1_64, N2_64) << endl;
	system("PAUSE");
	return 0;
}
// r10 pomocniczny rejestr, a r8 jest N2??? cos takiego xD
// MOVSXD - S: signed XD: uzupelnienie znakow, zer by utrzymac wartosc
// uses rsi rdi - automatycznie wrzuca na stos, nie trzeba push/pop
