segment .data

segment .bss
	_x resd 1
	_y resd 1
	__esp resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
; -----------------------
; PROCEDIMIENTO PRINCIPAL
; -----------------------
main:
	mov dword [__esp] , esp

; x = 9;
	mov dword [_x], 9 ;COPIANDO EL VALOR 9 A LA VARIABLE _x
; ebx = 10;
	mov dword ebx, 10 ; COPIANDO EL VALOR 10 AL REGISTRO EBX
; y = ebx;
	mov dword [_y], ebx ;COPIANDO EL VALOR DEL REGISTRO A LA VARIABLE

; IMPRESIÓN DE TODOS LOS ELEMENTOS
	push dword [_x]
	call print_int
	add esp, 4
	call print_endofline


	push dword ebx
	call print_int
	add esp, 4
	call print_endofline


	push dword [_y]
	call print_int
	add esp, 4
	call print_endofline


; INTRODUCIR CTE EN PILA Y EXTRAER DE LA PILA A UN REGISTRO

	push dword 4 ;INTRODUCCION DE CONSTANTE
	pop eax

	push eax  ;INTRODUCCION REGISTRO EN PILA
	call print_int
	add esp, 4
	call print_endofline

; INTRODUCIR VARIABLE EN PILA 

	push dword [_y] ;INTRODUCCION DE VARIABLE A PILA
	call print_int
	add esp, 4
	call print_endofline


; INTRODUCIR REGISTRO EN PILA Y EXTRAER LA PILA A UNA VARIABLE 

	mov dword eax, 11
	push dword eax
	pop dword [_x] ;EXTRAER VALOR DE LA PILA
	push dword [_x]
 
	call print_int
	add esp, 4
	call print_endofline


	mov dword esp, [__esp]
	ret
