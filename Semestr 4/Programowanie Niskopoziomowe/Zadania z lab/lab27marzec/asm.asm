.code

suma32 proc
	PUSH rsi;
	PUSH rdi;
	XOR rax, rax;
petla1: MOV rsi, [rcx + 8 * rdx - 8];
		MOV r10, r8;
petla2: MOVSXD r11, dword ptr[rsi + 4 * r10 - 4];
		ADD rax, r11;
		DEC r10;
		JNZ petla2;
		DEC rdx;
		JNZ petla1;
		POP rdi;
		POP rsi;
		ret;			 
suma32 endp

suma64 proc uses rsi rdi
	XOR rax, rax;
petla1:	MOV rsi, [rcx + 8 * rdx - 8];
		MOV r10, r8;
petla2:	ADD rax, [rsi + 8 * r10 - 8];
		DEC r10;
		JNZ petla2;
		DEC rdx;
		JNZ petla1;
		ret;
suma64 endp

end
