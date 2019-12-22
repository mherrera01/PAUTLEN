
segment .data
	err_div0 db "Error al dividir entre 0",0
	err_indice_vector db "Indice de vector fuera de rango 0", 0
segment .bss
	__esp resd 1
	_c1 resd 1
	_b1 resd 1
	_a1 resd 1
	_z1 resd 1
	_y1 resd 1
	_x1 resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
pela:
	push dword ebp
	mov dword ebp, esp
	sub esp, 4
	push dword 10101
	lea eax, [ebp - 4]
	push dword eax
	pop dword eax
	pop dword ebx
	push dword eax
	push dword ebx
	pop dword eax
	pop dword ebx
	mov dword [ebx], eax
	lea eax, [ebp - 4]
	push dword eax
	pop dword eax
	mov dword eax, [eax]
	mov dword esp, ebp
	pop dword ebp
	ret
main:
	mov dword [__esp], esp
	push dword _x1
	call scan_int
	add esp, 4
	push dword _x1
	pop dword eax
	mov dword eax, [eax]
	neg eax
	push dword eax
	pop dword eax
	mov dword [_y1], eax
	push dword _y1
	pop dword eax
	mov dword eax, [eax]
	neg eax
	push dword eax
	push dword 10
	pop dword ebx
	pop dword eax
	imul ebx
	push dword eax
	pop dword eax
	mov dword [_z1], eax
	push dword _x1
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	push dword _y1
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	push dword _z1
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	push dword _x1
	push dword _y1
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
	push dword 1
	call print_int
	add esp, 4
	call print_endofline
_fin_condicional_simple_1:
	push dword _x1
	push dword _y1
	push dword _x1
	pop dword eax
	mov dword eax, [eax]
	neg eax
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	imul ebx
	push dword eax
	pop dword ecx
	pop dword eax
	mov dword eax, [eax]
	cmp eax,ecx
	jz near true_igual_1
	mov dword eax, 0
	push dword eax
	jmp near continua_igual_1
true_igual_1:
	mov dword eax,1
	push dword eax
continua_igual_1:
	pop dword eax
	cmp eax, 0
	je near _fin_condicional_simple_2
	push dword 0
	call print_int
	add esp, 4
	call print_endofline
	jmp near _fin_condicional_compuesto_2
_fin_condicional_simple_2:
	push dword 1000
	call print_int
	add esp, 4
	call print_endofline
_fin_condicional_compuesto_2:
	call pela
	add esp, 0
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
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