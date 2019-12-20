
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
	sub esp, 4
	lea eax, [ebp + 16]
	push dword eax
	lea eax, [ebp + 12]
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	mov dword ebx, [ebx]
	imul ebx
	push dword eax
	lea eax, [ebp + 8]
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword ebx, [ebx]
	mov dword edx, 0
	cmp ebx, edx
	je near fin_error_division
	idiv ebx
	push dword eax
	pop dword eax
	neg eax
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
	push dword 12
	lea eax, [ebp + 16]
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
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	push dword 10
	push dword _x2
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	push dword _x3
	pop dword eax
	mov dword eax, [eax]
	push dword eax