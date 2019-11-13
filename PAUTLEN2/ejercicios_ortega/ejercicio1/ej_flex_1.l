%{
#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"
%}
%option noyywrap

%%
main { return TOK_MAIN; }
array { return TOK_ARRAY; }
int { return TOK_INT; }
if { return TOK_IF; }
else { return TOK_ELSE; }
while { return TOK_WHILE; }
%%

