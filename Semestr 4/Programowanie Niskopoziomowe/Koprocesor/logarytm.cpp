// a = log_b x = log_2 x / log_2 b
// Program ten pozwala na policzenie dowolnego logarytmu o podstawie
// wprowadzonej przez użytkownika oraz liczbie którą chce logarytmować

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	float x;
	float a;
	float b;

	cout << "Wprowadz podstawe logarytmu (b) oraz liczbe logarytmowana (x): ";
	cin >> b >> x;

	__asm {
		FLD1;		// 1
		FLD x;		// x, 1
		FYL2X;		// log_2 x
		FLD1;		// 1, log_2 x
		FLD b;		// b, 1, log_2 x
		FYL2X;		// log_2 b, log_2 x
		FDIV;		// a
		FST a;

	}
	cout << "a = log_b x = log_2 x / log_2 b: \n";
	cout << "a = log_" << b << " " << x << " = " << "log_2 " << x << " / " << " log_2 " << b << " = " << a;

	system("PAUSE");
	return 0;
}
