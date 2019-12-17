
segment .data
	err_div0 db "Error al dividir entre 0",0
	err_indice_vector db "Indice de vector fuera de rango 0", 0
segment .bss
	__esp resd 1
	_z resd 1
	_y1 resd 1
	_x3 resd 1
	_x2 resd 1
	_x1 resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float;R21:	<funciones> ::=

main:
	mov dword [__esp], esp
	push dword _y1
	call scan_boolean
	add esp, 4
	push dword _y1
_inicio_bucle_1:
	push dword _y1
	call scan_boolean
	add esp, 4
	push dword 3
	call print_int
	add esp, 4
	call print_endofline
	pop dword eax
	mov eax, [eax]
	cmp eax, 0
	je near _fin_bucle_1
	jmp near _inicio_bucle_1
_fin_bucle_1:
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