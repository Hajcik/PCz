
#include "stdafx.h"
#include<iostream>
#include<Windows.h>
using namespace std;
//	  macierz  w_wej   w_wyj    N1      N2
extern "C" INT64 mnoz(INT64**, INT64*, INT64*, INT64, INT64);
//    rcx	   rdx      r8      r9     r10
int _tmain(int argc, _TCHAR* argv[])
{
	INT64 N1;
	cin >> N1;
	INT64 N2;
	cin >> N2;
	INT64* wektor_wej = new INT64[N2];
	for (int j = 0; j < N2; j++)
	{
		cin >> wektor_wej[j];
	}
	INT64* wektor_wyj = new INT64[N1];
	INT64** macierz = new INT64*[N1];
	for (int i = 0; i < N1; i++)
		macierz[i] = new INT64[N2];

	for (int i = 0; i < N1; i++)
		for (int j = 0; j < N2; j++)
			cin >> macierz[i][j];
	mnoz(macierz, wektor_wej, wektor_wyj, N1, N2);
	for (int i = 0; i < N1; i++)
	{
		cout << wektor_wyj[i] << " ";
	}
	system("PAUSE");
	return 0;
}

