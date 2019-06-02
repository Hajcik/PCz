

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	float a;
	float b;
	float c;
	float Re1, Re2, Im1, Im2;
	cin >> a >> b >> c;
	__asm
	{
		FLD b;
		FLD st(0);
		FMUL;
		FLD a;
		FLD c;
		FMUL;
		FADD st, st(0);
		FADD st, st(0);
		FSUB;
		FTST;
		FSTSW ax;
		SAHF;
		JZ rowne;
		JC mniejsze;
		FSQRT;
		FLD st(0);
		FLD b;
		FSUB;
		FLD a;
		FADD st, st(0);
		FDIV;
		FSTP Re1;
		FCHS;
		FLD b;
		FSUB;
		FLD a;
		FADD st, st(0);
		FDIV;
		FSTP Re2;
		FLDZ;
		FSTP Im1;
		FLDZ;
		FSTP Im2;
		JMP koniec;
	rowne:
		FLD b;
		FLD a;
		FADD st, st(0);
		FDIV;
		FCHS;
		FLD st(0);
		FSTP Re1;
		FSTP Re2;
		FLDZ;
		FSTP Im1;
		FLDZ;
		FSTP Im2;
		JMP koniec;
	mniejsze:
		FABS;
		FSQRT;
		FLD a;
		FADD st, st(0);
		FDIV;
		FLD st(0);
		FSTP Im1;
		FCHS;
		FSTP Im2;
		FLD b;
		FLD a;
		FADD st, st(0);
		FDIV;
		FCHS;
		FLD st(0);
		FSTP Re1;
		FSTP Re2;
		JMP koniec;
	koniec:
   }
	cout << "Re1 " << Re1 << endl;
	cout << "Re2 " << Re2 << endl;
	cout << "Im1 " << Im1 << endl;
	cout << "Im2 " << Im2 << endl;

}
