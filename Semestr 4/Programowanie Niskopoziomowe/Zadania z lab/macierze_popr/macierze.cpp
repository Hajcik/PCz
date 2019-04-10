#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<Windows.h>
using namespace std;
					// rcx      rdx		r8 (N1) r9 (N2)
extern "C" INT64 SUMA(INT64**, INT64**, INT64, INT64);
int _tmain(int argc, _TCHAR* argv[])
{
	INT64 N1;
	INT64 N2;
	cout << "Podaj wymiar macierzy: ";
	cin >> N1;
	cin >> N2;
	INT64 **A = new INT64*[N1];
	for (int i = 0; i < N1; i++)
		A[i] = new INT64[N2];

	for (int i = 0; i < N1; i++)
		for (int j = 0; j < N2; j++)
			cin >> A[i][j];

	INT64 **B = new INT64*[N1];
	for (int i = 0; i < N1; i++)
		B[i] = new INT64[N2];

	for (int i = 0; i < N1; i++)
		for (int j = 0; j < N2; j++)
			cin >> B[i][j];
	
	SUMA(A, B, N1, N2);
	for (int i = 0; i < N1; i++)
		for (int j = 0; j < N2; j++)
		{
		cout << A[i][j] << " ";
		}
	cout << "\n";

	system("PAUSE");
	return 0;
}
