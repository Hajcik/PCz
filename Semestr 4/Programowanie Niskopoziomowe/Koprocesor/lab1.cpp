#include "stdafx.h"
#include<iostream>
#include<cmath>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// y = a^x
	// log_2 y = x * log_2 a
	// y = 2^x*log_2 a
	//         ^ - to wyrazenie musi sie zawierac w przedziale -1 < < 1
	float y;
	float x;
	float a;
	cin >> x >> a;
	__asm{
		FLD x;		//    x
		FLD a;		//	  x*log_2 a - round(x*log_2 a)
		FYL2X;		//    round(x*log_2 a)
		FLD st;
		FRNDint;
		FSUB st(1), st; // jakbysmy nie dali nic to byloby p, st(1) i st
		FXCH;
		F2XM1;	// koprocesor usuwa tu tez jeden, wiec trzeba zaladowac to 1, just because
		FLD1;
		FADD;
		FSCALE;
		FSTP y;
	}
	y = pow(x, a);
	cout << y;
	system("PAUSE");
	return 0;
}

