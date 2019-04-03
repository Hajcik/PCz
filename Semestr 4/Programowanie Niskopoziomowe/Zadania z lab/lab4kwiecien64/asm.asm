.code

mnoz proc uses rbx rsi, macierz: ptr, wektor_wej: ptr, wektor_wyj: ptr, N1: qword, N2: qword; 
		
		MOV r11, N2;
	p1: MOV rsi, [rcx + r9 * 8 - 8];
		MOV rbx, r11;
		XOR r10, r10;
	p2: MOV rax, [rsi + rbx * 8 - 8];
		IMUL rax, [rdx + rbx * 8 - 8];
		ADD r10, rax;
		DEC rbx;
		JNZ p2;
		MOV [r8 + r9 * 8 - 8], r10;
		DEC r9;
		JNZ p1;
		ret;
mnoz endp
end
