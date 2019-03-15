asembler.asm:
.code
Test64 proc
	XOR rax, rax;
skok:
	ADD rax, rcx;
	DEC rcx;
	JNZ skok;
	RET
	Test64 endp
	end
pnlab.cpp:
#include "stdafx.h"
#include<iostream>
#include<Windows.h>
using namespace std;
extern "C" INT64 Test64(INT64);
int _tmain(int argc, _TCHAR* argv[])
{
	INT64 a = 3;
	cout << Test64(a) << endl;
	system("PAUSE");
	return 0;
}
