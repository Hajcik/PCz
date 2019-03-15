//wyjscie zawsze w rax
//RET - powrot z procedury
asembler.asm:
.code
Test64 proc
	CMP rcx, rdx;
	JNL abc;
	MOV rcx, rdx;
	abc:
	MOV rax, rcx;
	RET 
	Test64 endp
	end
pnlab.cpp:
#include "stdafx.h"
#include<iostream>
#include<Windows.h>
using namespace std;
extern "C" INT64 Test64(INT64, INT64);
int _tmain(int argc, _TCHAR* argv[])
{
	INT64 a = 30;
	INT64 b = 20;
	cout << Test64(a, b) << endl;
	system("PAUSE");
	return 0;
}
