
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
	sub esp, 0