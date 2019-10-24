
segment .data
	err_div0 db "Error al dividir entre 0",0
	err_indice_vector db "Indice de vector fuera de rango 0", 0
segment .bss
	__esp resd 1
	_m resd 1
	_b1 resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
main:
	mov dword [__esp], esp
	push dword _m
	call scan_int
	add esp, 4
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
	push dword _b1
	pop dword ebx
	pop dword eax
	mov dword [ebx], eax
	push dword _b1
	push dword 0
	pop dword ecx
	pop dword eax
	mov dword eax, [eax]
	cmp eax,ecx
	jnz near true_2
	mov dword eax, 0
	push dword eax
	jmp near continua_2
true_2:
	mov dword eax,1
	push dword eax
continua_2:
	pop dword eax
	cmp eax, 0
	je near _fin_condicional_simple_2
	push dword 2
	call print_int
	add esp, 4
	call print_endofline
	jmp near _fin_condicional_compuesto_2
_fin_condicional_simple_2:
	push dword 3
	call print_int
	add esp, 4
	call print_endofline
_fin_condicional_compuesto_2:
	jmp near fin
fin_error_division:
	push dword err_div0
	call print_string
	add esp, 4
	call print_endofline
	jmp near fin
fin_indice_fuera_rango:
	push dword err_indice_vector
	call print_string
	add esp, 4
	call print_endofline
	jmp near fin
fin:
	mov esp, [__esp]
	ret