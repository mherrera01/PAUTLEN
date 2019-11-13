%{
#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"
extern FILE * salida;
%}
%option noyywrap

%%
main { return TOK_MAIN; }
array { return TOK_ARRAY; }
int { return TOK_INT; }
if { return TOK_IF; }
else { return TOK_ELSE; }
while { return TOK_WHILE; }
";" { return TOK_PUNTOYCOMA; }
"(" { return TOK_PARENTESISIZQUIERDO; }
")" { return TOK_PARENTESISDERECHO; }
"*" { return TOK_ASTERISCO; }
"+" { return TOK_MAS; }
"<=" { return TOK_MENORIGUAL; }
"{" { return TOK_LLAVEIZQUIERDA; }
"}" { return TOK_LLAVEDERECHA; }
[a-zA-Z][a-zA-Z0-9]* { return TOK_IDENTIFICADOR; }
%%
