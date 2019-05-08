#include "stdafx.h"
#include<iostream>
#include<cmath>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	float alfa;
	float y;
	float b = 180;
	cin >> alfa;
	__asm{
		FLD alfa;
		FLD PI;
		FMULp st(1),st;	// st(1) o jeden wstecz na stosie, st to szczyt, chyba :/
		FLD b;	// wartosc 180*
		fxch;
		fdivp st(1), st;
		
		Fsin;
		
		FSTP y;
	}
	cout << y;
	system("PAUSE");
	return 0;
}

