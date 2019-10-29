
segment .data
	err_div0 db "Error al dividir entre 0",0
	err_indice_vector db "Indice de vector fuera de rango 0", 0
segment .bss
	__esp resd 1
	_b1 resd 1
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
	push dword _b1
	pop dword ecx
	mov dword ecx, [ecx]
	mov dword eax, 0
	cmp eax, ecx
	je near positivo_negativo0
	mov dword eax, 0
	push dword eax
	jmp near continua_0
positivo_negativo0:
	mov dword eax, 1
	push dword eax
continua_0:
	call print_boolean
	add esp, 4
	call print_endofline
	push dword _b1
	pop dword ecx
	mov dword ecx, [ecx]
	mov dword eax, 0
	cmp eax, ecx
	je near positivo_negativo1
	mov dword eax, 0
	push dword eax
	jmp near continua_1
positivo_negativo1:
	mov dword eax, 1
	push dword eax
continua_1:
	pop dword ecx
	mov dword eax, 0
	cmp eax, ecx
	je near positivo_negativo2
	mov dword eax, 0
	push dword eax
	jmp near continua_2
positivo_negativo2:
	mov dword eax, 1
	push dword eax
continua_2:
	call print_boolean
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