#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	float a;
	float b;
	cin >> a >> b;
	float c = 0;
	__asm{
		FLD a;
		FLD st(0);
		FMUL;
		FLD b;
		FLD st(0);
		FMUL;
		FADD;
		FSQRT;
		FSTP c;

	}
	cout << a << " " << b << " " << c;
	
	system("PAUSE");
	return 0;
}
