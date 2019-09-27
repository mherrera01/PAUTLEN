segment .data ;Variables inicializadas
  
segment .bss ;Variables sin inicializar
  __esp resd 1
  __x resd 1
  
segment .text ;SEGMENTO DE CODIGO
  global main ;SIMBOLO GLOBAL USADO DESDE EL EXTERIOR
  extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean ;SIMBOLOS EXTERNOS, FUNCIONES DE LA LIBRERIA
  extern print_endofline, print_blank, print_string ;SIMBOLOS EXTERNOS, FUNCIONES DE LA LIBRERIA
  extern alfa_malloc, alfa_free, ld_float ;SIMBOLOS EXTERNOS, FUNCIONES DE LA LIBRERIA

main:
  mov dword [__esp], esp ;GUARDAMOS EN VARIBLE EL VALOR DEL PUNTERO A PILA
  
  mov dword [__x], 8
  
  push dword [__x] ;INTRODUCIMOS EN LA PILA EL VALOR DE X
  
  call print_int ;LLAMAMOS A LA FUNCION QUE SACARA DE LA PILA EL VALOR DE X
  
  add esp, 4 ;RESTAURAMOS EL PUNTERO A PILA
  
  call print_endofline ;INVOCAMOS LA FUNCION DE PRINTEO DE ESPACIO PARA FINALIZAR
  
  mov dword esp, [__esp] ;RESTAURAMOS EL VALOR DEL PUNTERO ALMACENADO CONLA VARIABLE ESP
  
  ret
  