#include "stdafx.h"
#include<iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int x;
//	int a; 
//	int b; 
//	cout << "Podaj wartosc a: \n";
//	cin >> a; // >> b;
	int i; cout << "Podaj wartosc i: ";
	cin >> i; cout << "\n";

	__asm{
		MOV ecx, i;
		MOV eax, 1;
	petla:	MUL ecx;
		// dekrementacja
		//		DEC ecx;
		//		petla
		LOOP petla;
		mov x, eax;
	}

/*	__asm
	{
		mov edx, i;
		xor ecx, ecx;
		inc ecx;
		cmp ecx, edx;
		jne l1;
//		mov eax, ecx;
		mov eax, a;
		mov ebx, b;
		add eax, ebx;

		jmp koniec;
l1:		inc ecx;
		cmp ecx, edx;
		jne l2;
//		mov eax, ecx;
		mov eax, a;
		cmp eax, b;	//<- optymalniej	//mov ebx, b;
		jl l3;
		sub eax, b;
		jmp koniec;
l3:		mov eax, b;
		sub eax, a;
/*		jc IAE;
		sub eax, ebx;
IAE:	sub ebx, eax;
		neg ebx;
	
		
		jmp koniec;
l2:  // xor eax, eax;
		mov eax, a;
		mul eax;
		mov ebx, eax; // zeby przetrzymac wartosc, by jej nie zamazac
		mov eax, b;
		mul eax;
		add eax, ebx;
koniec: mov x, eax;
	} */
	cout << "Wynik danego dzialania: "<<x;
	system("PAUSE");
	return 0;
}
