segment .data ;Variables inicializadas
  _b3 dd 0 ;false
segment .bss ;Variables sin inicializar
  __esp resd 1
  __b1 resd 1
  __b2 resd 1
  
segment .text ;SEGMENTO DE CODIGO
  global main ;SIMBOLO GLOBAL USADO DESDE EL EXTERIOR
  extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean ;SIMBOLOS EXTERNOS, FUNCIONES DE LA LIBRERIA
  extern print_endofline, print_blank, print_string ;SIMBOLOS EXTERNOS, FUNCIONES DE LA LIBRERIA
  extern alfa_malloc, alfa_free, ld_float ;SIMBOLOS EXTERNOS, FUNCIONES DE LA LIBRERIA

main:
  mov dword [__esp], esp ;GUARDAMOS EN VARIBLE EL VALOR DEL PUNTERO A PILA
  
  push dword __b1 ;INTRODUCIMOS EN LA PILA LA DIRECCION DE b1
  
  call scan_int ;LLAMAMOS A LA FUNCION QUE ESCANEA UN VALOR POR PANTALLA Y LO ALMACENA EN b1
  
  add esp, 4 ;RESTAURAMOS EL PUNTERO A PILA
  
  
  push dword __b2 ;INTRODUCIMOS EN LA PILA LA DIRECCION DE b2
  
  call scan_int ;LLAMAMOS A LA FUNCION QUE ESCANEA UN VALOR POR PANTALLA Y LO ALMACENA EN b2
  
  add esp, 4 ;RESTAURAMOS EL PUNTERO A PILA
  
  push dword [_b3] ;INSERTAMOS EL ULTIMO OPERANDO DE LA OPERACION 
  
  push dword [__b2] ;INSERTAMOS EL SEGUNDO OPERANDO
  
  push dword [__b1] ;INSERTAMOS EL PRIMER OPERANDO
  
  pop dword eax ;EXTRAEMOS b1
  
  por dword ebx ;EXTRAEMOS b2
  
  and eax, ebx ;OPERAMOS b1 Y b2 MEDIANTE AND
  
  push dword eax ;INSERTAMOS EL RESULTADO EN LA PILA
  
  pop dword eax ;EXTRAEMOS EL RESULTADO Y LO ALMACENAMOS EN EAX
  
  neg eax ;OPERAMOS EAX HACIENDO QUE SE INVIERTA EL VALOR OBTENIDO PREVIAMENTE
  
  push dword eax ;INSERTAMOS EL VALOR FINAL DE LA OPERACION
  
  pop dword eax ;EXTRAEMOS DE NUEVO EL VALOR not (b1 and b2) PARA AHORA IGUALARLO A b3
  
  pop dword ebx ;EXTRAEMOS b3 Y LO ALMACENAMOS EN EBX
  
  mov ebx, eax ;IGUALAMOS EBX A EAX CON LO CUAL CUMPLIMOS b3 <= not (b1 and b2)
  
  push dword ebx ;INSERTAMOS EL VALOR FINAL EN LA PILA
  
  call print_int ;LLAMAMOS A LA FUNCION PARA IMPRIMIR EL VALOR POR PANTALLA
  
  add esp, 4 ;RESTAURAMOS EL PUNTERO A PILA
  
  call print_endofline ;TERMINAMOS LA IMPRESION CON UN PRINTEO DE ESPACIO
  
  mov dword esp, [__esp] ;RESTAURAMOS EL VALOR DEL PUNTERO ALMACENADO CONLA VARIABLE ESP
  
  ret
  