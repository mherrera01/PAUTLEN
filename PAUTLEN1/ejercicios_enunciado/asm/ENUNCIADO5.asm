
segment .data
	err_div0 db "Error al dividir entre 0",0
	err_indice_vector db "Indice de vector fuera de rango 0", 0
segment .bss
	__esp resd 1
	_m resd 1
	_v resd 4
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
_inicio_bucle_1:
	push dword _m
	push dword 4
	pop dword ecx
	pop dword eax
	mov dword eax, [eax]
	cmp eax,ecx
	jle near true_menor_igual_1
	mov dword eax, 0
	push dword eax
	jmp near continua_menor_igual_1
true_menor_igual_1:
	mov dword eax,1
	push dword eax
continua_menor_igual_1:
	pop dword eax
	cmp eax, 0
	je near _fin_bucle_1
	push dword _m
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	push dword _m
	push dword 10
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	imul ebx
	push dword eax
	push dword _m
	pop dword eax
	mov dword eax, [eax]
	cmp eax, 0
	jl near fin_indice_fuera_rango
	cmp eax, 3
	jg near fin_indice_fuera_rango
	mov dword edx, _v
	lea eax, [edx + eax*4]
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword [ebx], eax
	push dword _m
	push dword 1
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	add eax, ebx
	push dword eax
	pop dword eax
	mov dword [_m], eax
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