
segment .data
	err_div0 db "Error al dividir entre 0",0
segment .bss
	__esp resd 1
	_m resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
main:
	mov dword [__esp], esp
	push dword 0
	pop dword eax
	mov dword [_m], eax
	push dword _m
	push dword 5
	pop dword ecx
	pop dword eax
	mov dword eax, [eax]
	cmp eax,ecx
	jg near true_1
	mov dword eax, 0
	push dword eax
	jmp near continua_1
true_1:
	mov dword eax,1
	push dword eax
	continua_1:
	pop dword eax
	cmp eax, 0
	je near _fin_condicional_simple_1
	push dword 2
	call print_int
	add esp, 4
	call print_endofline
	jmp near _fin_condicional_compuesto_1
_fin_condicional_simple_1:
	push dword 3
	call print_int
	add esp, 4
	call print_endofline
_fin_condicional_compuesto_1:
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
