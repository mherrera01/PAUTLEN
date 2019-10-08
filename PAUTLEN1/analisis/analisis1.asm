segment .data ;Variables inicializadas
	_x dd 10 ;Variable tamaño 4 bytes con valor inicial 10
segment .bss ;Variables sin inicializar
	__esp resd 1
	_y resd 1
segment .text ;SEGMENTO DE CODIGO
	global main ;SIMBOLO GLOBAL USADO DESDE EL EXTERIOR
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean ;SIMBOLOS EXTERNOS FUNCIONES DE LA LIBRERIA
	extern print_endofline, print_blank, print_string ;SIMBOLOS EXTERNOS FUNCIONES DE LA LIBRERIA
	extern alfa_malloc, alfa_free, ld_float ;SIMBOLOS EXTERNOS FUNCIONES DE LA LIBRERIA

main:
	mov dword [__esp] , esp


	mov dword [_y], 9

	push dword [_x]
	call print_int
	add esp, 4
	call print_endofline


	push dword 100
	call print_int
	add esp, 4
	call print_endofline

	push dword [_y]
	call print_int
	add esp, 4
	call print_endofline

	mov dword esp, [__esp]
	ret