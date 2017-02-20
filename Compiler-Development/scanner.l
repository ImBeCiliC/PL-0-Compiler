%}
/*
    Lexikalische Analyse mit lex für pl/0
    Geschrieben von Tobias Maas
*/

#include "y.tab.h"
#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE * pIF;
int Line;
%}
%%
/* Regeln des Lexers */
/****************************************************************************************/
/** Return beendet die lexikalische Analyse                                                     **/
/****************************************************************************************/

//Schlüsselwörter

"begin"         {return t_begin;}
call              {return t_call;}
const           {return t_const;}
do               {return t_do;}
else             {return t_else;}
end             {return t_end;}
if                 {return t_if;}
odd             {return t_odd;}
procedure    {return t_procedure;}
then            {return t_then;}
"var"           {return t_var;}
while           {return t_while;}

// Leer- und Trennzeichen
[ \t]+

//Zeilenwechsel
[\n] {Line++;}

//Zahlen
[0-9]+      {
                    yylval.num = atol(yytext);
                    return t_num;
                }

// Bezeichner
[A-Za-z]([A-Za-z0-9])* {
                                        ylval.idnt = malloc(strlen(yytext)+1);
                                        strcpy(yylval.idnt, yytext);
                                        printf("<%s>\n",yylval.idnt);
                                        return t_ident;
                                 }

// Sonderzeichen
[?]
[!]
"+"
"-"
"*"
"/"
">"
">"
"="
":="
"<="
">="
";"
"."
","
"("
")"
(\".*\") {yylval.strg = yytext; return t_string;}
%%
