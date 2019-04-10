.code

SUMA proc uses rbx rsi rdi, A:ptr, B:ptr, N1:qword, N2: qword;

	p1: MOV rdi, [rcx + r8 * 8 - 8];
		MOV rsi, [rdx + r8 * 8 - 8];
		MOV r10, N2;
		MOV rax, [rsi + 8 * r10 - 8];
		ADD rax, [rdi + 8 * r10 - 8];
		MOV [rdi + 8 * r10 - 8]; rax;
		DEC r10;
		JNZ p2;
		DEC r8;
		JNZ p1;
		ret;

SUMA endp
end
