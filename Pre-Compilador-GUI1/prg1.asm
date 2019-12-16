
segment .data
	err_div0 db "Error al dividir entre 0",0
	err_indice_vector db "Indice de vector fuera de rango 0", 0
segment .bss
	__esp resd 1
	_y1 resd 1
	_x2 resd 1
	_x1 resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float;R21:	<funciones> ::=

main:
	mov dword [__esp], esp
	push dword _x1
	call scan_int
	add esp, 4
	push dword _x2
	call scan_int
	add esp, 4
	push dword _y1
	call scan_boolean
	add esp, 4
	push dword _x1
	push dword _x2
	pop dword ecx
	pop dword eax
	mov dword eax, [eax]
	mov dword ecx, [ecx]
	cmp eax,ecx
	jz near true_igual_0
	mov dword eax, 0
	push dword eax
	jmp near continua_igual_0
true_igual_0:
	mov dword eax,1
	push dword eax
continua_igual_0:
	pop dword eax
	cmp eax, 0
	je near _fin_condicional_simple_1
	push dword _y1
	pop dword eax
	mov dword eax, [eax]
	cmp eax, 0
	je near _fin_condicional_simple_2
	push dword 110
	call print_int
	add esp, 4
	call print_endofline
	jmp near _fin_condicional_compuesto_2
_fin_condicional_simple_2:
	push dword 111
	call print_int
	add esp, 4
	call print_endofline
_fin_condicional_compuesto_2:
	jmp near _fin_condicional_compuesto_1
_fin_condicional_simple_1:
	push dword _y1
	pop dword eax
	mov dword eax, [eax]
	cmp eax, 0
	je near _fin_condicional_simple_3
	push dword 10
	call print_int
	add esp, 4
	call print_endofline
	jmp near _fin_condicional_compuesto_3
_fin_condicional_simple_3:
	push dword 11
	call print_int
	add esp, 4
	call print_endofline
_fin_condicional_compuesto_3:
_fin_condicional_compuesto_1:
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