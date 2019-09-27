segment .data ;Variables inicializadas
  _y dd 10
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
  
  push dword __x ;INTRODUCIMOS EN LA PILA LA DIRECCION DE X
  
  call scan_int ;LLAMAMOS A LA FUNCION QUE ESCANEA UN VALOR POR PANTALLA Y LO ALMACENA EN X
  
  add esp, 4 ;RESTAURAMOS EL PUNTERO A PILA
  
  push dword [_y] ;INSERTAMOS EL ULTIMO OPERANDO DE LA OPERACION x*2-y
  
  push dword 2 ;INSERTAMOS EL SEGUNDO OPERANDO
  
  push dword [__x] ;INSERTAMOS EL PRIMER OPERANDO
  
  pop dword eax ;EXTRAEMOS EL VALOR DE LA X
  
  pop dword ebx ;EXTRAEMOS EL VALOR 2
  
  imul eax, exb ;MULTIMPLICAMOS X*2
  
  push dword eax ;INSERTAMOS DE NUEVO EN LA PILA
  
  pop dword eax ;EXTRAEMOS AHORA EL NUEVO VALOR
  
  pop dword ebx ;EXTRAEMOS EL VALOR DE Y
  
  sub eax, ebx ;RESTAMOS EL VALOR X*2 MENOS Y
  
  push dword eax ;INSERTAMOS EN LA PILA PARA REALIZAR LA LLAMADA DE PRINTEO
  
  call print_int ;LLAMAMOS A LA FUNCION
  
  add esp, 4 ;RESTAURAMOS EL PUNTERO A PILA
  
  call print_endofline

  mov dword esp, [__esp] ;RESTAURAMOS EL VALOR DEL PUNTERO ALMACENADO CONLA VARIABLE ESP
  
  ret
  