
segment .data
	err_div0 db "Error al dividir entre 0",0
	err_indice_vector db "Indice de vector fuera de rango 0", 0
segment .bss
	__esp resd 1
	_vector resd 3
	_resultado resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
or:
	push dword ebp
	mov dword ebp, esp
	sub esp, 4
	lea eax, [ebp + 16]
	push dword eax
	lea eax, [ebp + 12]
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	mov dword ebx, [ebx]
	or eax, ebx
	push dword eax
	lea eax, [ebp + 8]
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword ebx, [ebx]
	or eax, ebx
	push dword eax
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
peque:
	push dword ebp
	mov dword ebp, esp
	sub esp, 0
	push dword 1
	pop dword eax
	mov dword esp, ebp
	pop dword ebp
	ret
main:
	mov dword [__esp], esp
	push dword 0
	pop dword eax
	cmp eax, 0
	jl near fin_indice_fuera_rango
	cmp eax, 63
	jg near fin_indice_fuera_rango
	mov dword edx, _vector
	lea eax, [edx + eax*4]
	push dword eax
	push dword 0
	pop dword eax
	pop dword ebx
	mov dword [ebx], eax
	push dword 1
	pop dword eax
	cmp eax, 0
	jl near fin_indice_fuera_rango
	cmp eax, 63
	jg near fin_indice_fuera_rango
	mov dword edx, _vector
	lea eax, [edx + eax*4]
	push dword eax
	push dword 1
	pop dword eax
	pop dword ebx
	mov dword [ebx], eax
	push dword 2
	pop dword eax
	cmp eax, 0
	jl near fin_indice_fuera_rango
	cmp eax, 63
	jg near fin_indice_fuera_rango
	mov dword edx, _vector
	lea eax, [edx + eax*4]
	push dword eax
	push dword 0
	pop dword eax
	pop dword ebx
	mov dword [ebx], eax
	push dword 0
	pop dword eax
	cmp eax, 0
	jl near fin_indice_fuera_rango
	cmp eax, 63
	jg near fin_indice_fuera_rango
	mov dword edx, _vector
	lea eax, [edx + eax*4]
	push dword eax
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	push dword 1
	pop dword eax
	cmp eax, 0
	jl near fin_indice_fuera_rango
	cmp eax, 63
	jg near fin_indice_fuera_rango
	mov dword edx, _vector
	lea eax, [edx + eax*4]
	push dword eax
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	push dword 2
	pop dword eax
	cmp eax, 0
	jl near fin_indice_fuera_rango
	cmp eax, 63
	jg near fin_indice_fuera_rango
	mov dword edx, _vector
	lea eax, [edx + eax*4]
	push dword eax
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	call or
	add esp, 12
	push dword eax
	pop dword ecx
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
	pop dword eax
	mov dword [_resultado], eax
	push dword 1
	pop dword eax
	cmp eax, 0
	jl near fin_indice_fuera_rango
	cmp eax, 63
	jg near fin_indice_fuera_rango
	mov dword edx, _vector
	lea eax, [edx + eax*4]
	push dword eax
	call peque
	add esp, 0
	push dword eax
	pop dword eax
	pop dword ebx
	mov dword [ebx], eax
	push dword 1
	pop dword eax
	cmp eax, 0
	jl near fin_indice_fuera_rango
	cmp eax, 63
	jg near fin_indice_fuera_rango
	mov dword edx, _vector
	lea eax, [edx + eax*4]
	push dword eax
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	call print_boolean
	add esp, 4
	call print_endofline
	push dword _resultado
	pop dword eax
	mov dword eax, [eax]
	push dword eax
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