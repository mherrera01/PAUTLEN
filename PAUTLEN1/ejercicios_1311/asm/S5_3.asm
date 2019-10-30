
segment .data
	err_div0 db "Error al dividir entre 0",0
	err_indice_vector db "Indice de vector fuera de rango 0", 0
segment .bss
	__esp resd 1
	_m resd 1
	_x resd 1
	_v resd 4
	_vb resd 4
	_doble_cota resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
factorial:
	push dword ebp
	mov dword ebp, esp
	sub esp, 0
	lea eax, [ebp + 8]
	push dword eax
	push dword 0
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
	je near _fin_condicional_simple_1
	push dword 1
	jmp near _fin_condicional_compuesto_1
_fin_condicional_simple_1:
	lea eax, [ebp + 8]
	push dword eax
	lea eax, [ebp + 8]
	push dword eax
	push dword 1
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	sub eax, ebx
	push dword eax
	call factorial
	add esp, 4
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	imul ebx
	push dword eax
_fin_condicional_compuesto_1:
	pop dword eax
	mov dword esp, ebp
	pop dword ebp
	ret
grande:
	push dword ebp
	mov dword ebp, esp
	sub esp, 4
	lea eax, [ebp + 12]
	push dword eax
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	lea eax, [ebp + 8]
	push dword eax
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	mov dword ebx, [ebx]
	imul ebx
	push dword eax
	lea eax, [ebp - 4]
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword [ebx], eax
	lea eax, [ebp + 12]
	push dword eax
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	lea eax, [ebp - 4]
	push dword eax
	pop dword ecx
	pop dword eax
	mov dword eax, [eax]
	mov dword ecx, [ecx]
	cmp eax,ecx
	jg near true_mayor_1
	mov dword eax, 0
	push dword eax
	jmp near continua_mayor_1
true_mayor_1:
	mov dword eax,1
	push dword eax
continua_mayor_1:
	pop dword eax
	mov dword esp, ebp
	pop dword ebp
	ret
main:
	mov dword [__esp], esp
	push dword 0
	pop dword eax
	mov dword [_m], eax
_inicio_bucle_2:
	push dword _m
	push dword 4
	pop dword ecx
	pop dword eax
	mov dword eax, [eax]
	cmp eax,ecx
	jl near true_menor_2
	mov dword eax, 0
	push dword eax
	jmp near continua_menor_2
true_menor_2:
	mov dword eax,1
	push dword eax
continua_menor_2:
	pop dword eax
	cmp eax, 0
	je near _fin_bucle_2
	push dword _m
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	call factorial
	add esp, 0
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
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	push dword 10
	call grande
	add esp, 4
	push dword eax
	push dword _m
	pop dword eax
	mov dword eax, [eax]
	cmp eax, 0
	jl near fin_indice_fuera_rango
	cmp eax, 3
	jg near fin_indice_fuera_rango
	mov dword edx, _vb
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
	jmp near _inicio_bucle_2
_fin_bucle_2:
	push dword 0
	pop dword eax
	mov dword [_m], eax
_inicio_bucle_3:
	push dword _m
	push dword 4
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
	je near _fin_bucle_3
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
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	push dword _m
	pop dword eax
	mov dword eax, [eax]
	cmp eax, 0
	jl near fin_indice_fuera_rango
	cmp eax, 3
	jg near fin_indice_fuera_rango
	mov dword edx, _vb
	lea eax, [edx + eax*4]
	push dword eax
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	call print_boolean
	add esp, 4
	call print_endofline
	push dword _m
	push dword 1
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	add eax, ebx
	push dword eax
	pop dword eax
	mov dword [_m], eax
	jmp near _inicio_bucle_3
_fin_bucle_3:
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