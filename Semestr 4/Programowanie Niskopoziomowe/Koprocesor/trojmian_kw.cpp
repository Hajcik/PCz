// Do dokonczenia
// Trójmian kwadratowy

#include "stdafx.h"
#include<iostream>
#include<cstdlib>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	float a; float Re1; float Re2;
	float b; float Im1; float Im2;
	float c;
	float y; // wynik
	cin >> a >> b >> c;
	__asm{
		FLD b;
		FLD st(0);
		FMUL;
		FLD a;
		FLD c;
		FMUL;
		FADD st, st(0); // ten sam do tego samego (st to tez st(0) )
		FADD st, st(0);
		FSUB;
//		FSTP y;  - test dzialania gdy są dwa pierwiastki
		FTST;		// musimy przerzucic standard flag ???
		FSTSW ax;  // rejestr ax (ta i ponizej instrukcja)
		SAHF;		// te dwie instrukcje to pakiet przerzucenia jeden do drugiego
		JZ rowne;
		JC mniejsze;
			FSQRT;			//	Re1 = -b + sqrt(delta) / 2a
			FLD st(0);		//  Im1 = 0
			FLD b;			//  Re2 = -b - sqrt(delta) / 2a
			FSUB;			//  Im2 = 0
			FLD a;
			FADD st, st(0);
			FDIV; // st(1) / st(0), zdejmie st(0), zaladowany pierwiastek
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
			FLD b;				// Re1 = -b/2a
			FCHS;				// Im1 = 0
			FLD a;				// Re2 = -b/2a
			FADD st, st(0);		// Im2 = 0
			FDIV;
			FSTP Re1;
			FLD b;
			FCHS;
			FLD a;
			FADD st, st(0);
			FDIV;
			FSTP Re2;
			FLDZ;
			FSTP Im1;
			FLDZ;
			FSTP Im2;
		JMP koniec;
	mniejsze:
			FSQRT;
			FLD st(0);
			FLD b;				// Re1 = -b/2a
			FCHS;				// Im1 = sqrt( |delta| ) / 2a
			FLD a;				// Re2 = -b/2a
			FADD st, st(0);		// Im2 = -sqrt( |delta| ) / 2a
			FDIV;
			FSTP Re1;
			FLD b;
			FCHS;
			FLD a;
			FADD st, st(0);
			FDIV;
			FSTP Re2;					
				
		
		JMP koniec;
	koniec:

		}
//	cout << "Delta: " << y << endl;
	cout << "Pierwiastek Re1: " << Re1 << "\nPierwiastek Re2: " << Re2 << endl;
	cout << "Pierwiastek Im1: " << Im1 << "\nPierwiastek Im2: " << Im2 << endl;
	
	system("PAUSE");
	return 0;
}

