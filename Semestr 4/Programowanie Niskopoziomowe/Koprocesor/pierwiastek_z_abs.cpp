// y = sqrt(|a-b|) / a+b

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	float a;
	float b;
	float y;
	cout << "WPROWADZ A I B: ";
	cin >> a >> b;

	__asm{
		FLD a;				// a
		FLD st(0);			// a, a
		FLD b;				// b, a, a
		FADD st(2), st(0);	// b, a, a+b
		FSUBP st(1), st(0);	// a-b, a+b
		FABS;				// |a-b|, a+b
		FSQRT;				// sqrt(|a-b|), a+b
		FDIVR;				// sqrt(|a-b|) / a+b
		FST y;
	}
	cout << "WYNIK Y = " << y;
	
	system("PAUSE");
	return 0;
}
