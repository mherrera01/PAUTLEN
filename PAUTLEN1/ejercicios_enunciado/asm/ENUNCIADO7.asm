
segment .data
	err_div0 db "Error al dividir entre 0",0
	err_indice_vector db "Indice de vector fuera de rango 0", 0
segment .bss
	__esp resd 1
	_z resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
doble:
	push dword ebp
	mov dword ebp, esp
	sub esp, 4
	lea eax, [ebp + 8]
	push dword eax
	lea eax, [ebp - 4]
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	mov dword [ebx], eax
	push dword 2
	lea eax, [ebp + 8]
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword ebx, [ebx]
	imul ebx
	push dword eax
	pop dword eax
	mov dword esp, ebp
	pop dword ebp
	ret
main:
	mov dword [__esp], esp
	push dword 2
	pop dword eax
	mov dword [_z], eax
	push dword _z
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	call doble
	add esp, 4
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