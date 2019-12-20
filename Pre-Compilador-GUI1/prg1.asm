
segment .data
	err_div0 db "Error al dividir entre 0",0
	err_indice_vector db "Indice de vector fuera de rango 0", 0
segment .bss
	__esp resd 1
	_z resd 10
	_y2 resd 1
	_y1 resd 1
	_x resd 1
	_x3 resd 1
	_x2 resd 1
	_x1 resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
pepe:
	push dword ebp
	mov dword ebp, esp
	sub esp, 8
	lea eax, [ebp - 4]
	push dword eax
	call scan_int
	add esp, 4
	lea eax, [ebp - 8]
	push dword eax
	call scan_int
	add esp, 4
	lea eax, [ebp - 4]
	push dword eax
	lea eax, [ebp - 8]
	push dword eax
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
	push dword 10101010
	call print_int
	add esp, 4
	call print_endofline
	jmp near _fin_condicional_compuesto_1
_fin_condicional_simple_1:
_fin_condicional_compuesto_1:
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
	push dword 1
	pop dword eax
	mov dword [_x1], eax
	push dword 0
	pop dword eax
	mov dword [_x2], eax
_inicio_bucle_2:
	push dword _x1
	push dword 1
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
	je near _fin_bucle_2
	push dword _x2
	pop dword eax
	mov dword eax, [eax]
	cmp eax, 0
	jl near fin_indice_fuera_rango
	cmp eax, 63
	jg near fin_indice_fuera_rango
	mov dword edx, _z
	lea eax, [edx + eax*4]
	push dword eax
	push dword _x2
	pop dword eax
	mov dword eax, [eax]
	pop dword ebx
	mov dword [ebx], eax
	push dword _x2
	push dword 1
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	add eax, ebx
	push dword eax
	pop dword eax
	mov dword [_x2], eax
	push dword _x2
	push dword 10
	pop dword ecx
	pop dword eax
	mov dword eax, [eax]
	cmp eax,ecx
	jz near true_igual_2
	mov dword eax, 0
	push dword eax
	jmp near continua_igual_2
true_igual_2:
	mov dword eax,1
	push dword eax
continua_igual_2:
	pop dword eax
	cmp eax, 0
	je near _fin_condicional_simple_3
	push dword 0
	pop dword eax
	mov dword [_x1], eax
	jmp near _fin_condicional_compuesto_3
_fin_condicional_simple_3:
_fin_condicional_compuesto_3:
	jmp near _inicio_bucle_2
_fin_bucle_2:
	push dword 0
	pop dword eax
	mov dword [_x2], eax
_inicio_bucle_4:
	push dword _x2
	push dword 10
	pop dword ecx
	pop dword eax
	mov dword eax, [eax]
	cmp eax,ecx
	jl near true_menor_3
	mov dword eax, 0
	push dword eax
	jmp near continua_menor_3
true_menor_3:
	mov dword eax,1
	push dword eax
continua_menor_3:
	pop dword eax
	cmp eax, 0
	je near _fin_bucle_4
	push dword _x2
	pop dword eax
	mov dword eax, [eax]
	cmp eax, 0
	jl near fin_indice_fuera_rango
	cmp eax, 63
	jg near fin_indice_fuera_rango
	mov dword edx, _z
	lea eax, [edx + eax*4]
	push dword eax
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	push dword _x2
	push dword 1
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	add eax, ebx
	push dword eax
	pop dword eax
	mov dword [_x2], eax
	jmp near _inicio_bucle_4
_fin_bucle_4:
	push dword 100
	call pepe
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