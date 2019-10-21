
segment .data
	err_div0 db "Error al dividir entre 0",0
segment .bss
	__esp resd 1
	_b1 resd 1
	_x resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
main:
	mov dword [__esp], esp
	push dword _b1
	call scan_boolean
	add esp, 4
	push dword _x
	call scan_int
	add esp, 4
	push dword _x
	push dword 3
	pop dword ecx
	pop dword eax
	mov dword eax, [eax]
	cmp eax,ecx
	jg near true_0
	mov dword eax, 0
	push dword eax
	jmp near continua_0
true_0:
	mov dword eax,1
	push dword eax
	continua_0:
	call print_boolean
	add esp, 4
	call print_endofline
	push dword _x
	push dword 3
	pop dword ecx
	pop dword eax
	mov dword eax, [eax]
	cmp eax,ecx
	jge near true_1
	mov dword eax, 0
	push dword eax
	jmp near continua_1
true_1:
	mov dword eax,1
	push dword eax
	continua_1:
	call print_boolean
	add esp, 4
	call print_endofline
	push dword _x
	push dword 3
	pop dword ecx
	pop dword eax
	mov dword eax, [eax]
	cmp eax,ecx
	jl near true_2
	mov dword eax, 0
	push dword eax
	jmp near continua_2
true_2:
	mov dword eax,1
	push dword eax
	continua_2:
	call print_boolean
	add esp, 4
	call print_endofline
	push dword _x
	push dword 3
	pop dword ecx
	pop dword eax
	mov dword eax, [eax]
	cmp eax,ecx
	jle near true_3
	mov dword eax, 0
	push dword eax
	jmp near continua_3
true_3:
	mov dword eax,1
	push dword eax
	continua_3:
	call print_boolean
	add esp, 4
	call print_endofline
	push dword _x
	push dword 3
	pop dword ecx
	pop dword eax
	mov dword eax, [eax]
	cmp eax,ecx
	jz near true_4
	mov dword eax, 0
	push dword eax
	jmp near continua_4
true_4:
	mov dword eax,1
	push dword eax
	continua_4:
	call print_boolean
	add esp, 4
	call print_endofline
	push dword _x
	push dword 3
	pop dword ecx
	pop dword eax
	mov dword eax, [eax]
	cmp eax,ecx
	jnz near true_5
	mov dword eax, 0
	push dword eax
	jmp near continua_5
true_5:
	mov dword eax,1
	push dword eax
	continua_5:
	call print_boolean
	add esp, 4
	call print_endofline
	push dword _b1
	push dword 0
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	and eax, ebx
	push dword eax
	call print_boolean
	add esp, 4
	call print_endofline
	push dword _b1
	push dword 1
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	or eax, ebx
	push dword eax
	call print_boolean
	add esp, 4
	call print_endofline
	jmp near fin
division_cero:
	push dword err_div0
	call print_string
	add esp, 4
	call print_endofline
jmp near fin
fin:
	mov dword esp, [__esp]
	ret
