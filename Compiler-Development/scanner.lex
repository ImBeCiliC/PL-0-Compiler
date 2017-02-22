%{
/*
    Lexical Analysis with lex for pl/0
    written by Tobias Maas
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser.tab.h"


%}

%start COMMENT

 /* Rules of Lexer */
 /****************************************************************************************/
 /** Return ends the  lexical Analysis                                                                **/
 /****************************************************************************************/

%%
<COMMENT>"*)"               BEGIN 0; /* End of comment, switch to normal Rules*/
<COMMENT>[^*()]*            ;   /* ignore all tokens except *( and )* for the PL/0 which defines the PL/0 Comment*/
<COMMENT>("*"|"("|")")      ;  /* Ignore ( ) when its in a comment*/
"(*"                                    BEGIN COMMENT; /*Begin of comment, use comment rules*/

 /* Keywords */

"BEGIN"       return t_begin;
"CALL"                  {return t_call;}
"CONST"              {return t_const;}
"DO"                    {return t_do;}
"ELSE"                  {return t_else;}
"END"                   {return t_end;}
"IF"                        {return t_if;}
"ODD"                   {return t_odd;}
"PROCEDURE"      {return t_procedure;}
"THEN"                  {return t_then;}
"VAR"                   {return t_var;}
"WHILE"                {return t_while;}
"DEBUG;"              {; /* ignore debug*/}

 /* Ignore empty spaces */
[\t \f \r \n]           ;

 /* Numbers */
[0-9]+      {
                    yylval.number = atoi(yytext);
                    return t_num;
                }

 /* Bezeichner */
[A-Za-z]([A-Za-z0-9])* {
                                        yylval.ident = strdup(yytext);
                                        return t_ident;
                                 }

 /* Special characters */
"?"            {return t_read;}
"!"            {return t_write;}
"+"             {return t_add;}
"-"             {return t_sub;}
"*"             {return t_mul;}
"/"             {return t_div;}
">"             {return t_greater;}
"<"             {return t_less;}
"="             {return t_equal;}
":="            {return t_assignment;}
"<="            {return t_lesseq;}
">="            {return t_greatereq;}
";"               {return t_semic;}
"."               {return t_dot;}
","               {return t_comma;}
"("               {return t_lbracket;}
")"               {return t_rbracket;}
"#"               {return t_noteq;}
 .                 {return t_err;}
%%

int yywrap()
{
    printf("Ende der Eingabe\n");
    return 1;
}