
segment .data
	err_div0 db "Error al dividir entre 0",0
segment .bss
	__esp resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
dos:
	push dword ebp
	mov dword ebp, esp
	sub esp, 0
	push dword 2
	call print_int
	add esp, 4
	call print_endofline
	push dword 2
	pop dword eax
	mov dword esp, ebp
	pop dword ebp
	ret
main:
	mov dword [__esp], esp
	call dos
	add esp, 0
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	jmp near fin
division_cero:
	push dword err_div0
	call print_string
	add esp, 4
	call print_endofline
jmp near fin
fin:
	mov dword esp, [__esp]
	ret
