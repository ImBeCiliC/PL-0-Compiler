%{

 #include <stdio.h>
 #include "lex.yy.c"
 #include "SymbolTable.h"
 #include "VarEntry.h"
 #include "ConstEntry.h"
 #include "ProcEntry.h"
 #include "AstBlock.h"
 #include "AstStatement.h"
 #include "AstExpression.h"
 #include "AstIdentifier.h"

    int yydebug = 1;
    extern int yylineo;
    AstBlock* root;

%}

%union {
    int number;
    const char* ident;
    AstBlock * astBlock;
    AstStatement * astStatement;
    AstExpression * astExpression;
    AstIdentifier * astIdentifier;
    struct { AstStatement * start; AstStatement * end; } list;
}

%token t_begin
%token t_call
%token t_const
%token t_do
%token t_else
%token t_end
%token t_if
%token t_odd
%token t_procedure
%token t_then
%token t_var
%token t_while
%token t_read
%token t_write
%token t_add
%token t_sub
%token t_mul
%token t_div
%token t_greater
%token t_less
%token t_equal
%token t_assignment
%token t_lesseq
%token t_greatereq
%token t_semic
%token t_dot
%token t_comma
%token t_lbracket
%token t_rbracket
%token t_noteq
%token t_err

%token<num> t_num
%token<ident> t_ident

%type <astBlock> block proc_list procedure
%type <astIdentifier> const_decl constlist const_id varlist var_decl
%type <astExpression> factor expression condition term
%type <astStatement> assignment proc_call read write debug
%type <list> statementlist statement while if

%%
program :
        block t_dot { root = $1; }
    ;


block :
    {
        SymbolTable::getInstance()->level_up();
    }
    const_decl var_decl proc_list statement
    {
        $$ = new AstBlock($2, $3, $4, $5.start);
        SymbolTable::getInstance()->level_down();
    }
    ;


const_decl :
        /**/                                        { $$ = NULL; }
    |   t_const constlist t_semic                   { $$ = $2; }
    ;


input_error :
        t_err                                       { error("Unbekanntes Zeichen."); }
    ;


constlist :
        const_id t_equal t_num                       { $$ = $1; $$->value = $3; }
    |   const_id t_equal t_num t_comma constlist       { $$ = $1; $$->value = $3; $$->next=$5; }
    ;


const_id :
        t_ident
        {
            $$ = new AstIdentifier($1);
            SymbolTable::getInstance()->insert(new ConstEntry($1));
        }
    ;


var_decl :
        /**/                                        { $$ = NULL; }
    |   t_var varlist t_semic                       { $$ = $2; }
    ;


varlist :
        t_ident
        {
            $$ = new AstIdentifier($1);
            SymbolTable::getInstance()->insert(new VarEntry($1));
        }
    |   t_ident t_comma varlist
        {
            $$ = new AstIdentifier($1); $$->next = $3;
            SymbolTable::getInstance()->insert(new VarEntry($1));
        }
    ;


proc_list :
        /**/                                        { $$ = NULL; }
    |   procedure t_semic proc_list               { $$ = $1; $$->next = $3; }
    ;


procedure :
        t_procedure
        t_ident                                  { SymbolTable::getInstance()->insert(new ProcEntry($2)); }
        t_semic
        block                                       { $$ = $5; strcpy($$->ident, $2); }
        ;


statement :
        /**/                                        { $$.start = $$.end = NULL; }
    |   assignment                                  { $$.start = $$.end = $1; }
    |   proc_call                                   { $$.start = $$.end = $1; }
    |   read                                        { $$.start = $$.end = $1; }
    |   write                                       { $$.start = $$.end = $1; }
    |   debug                                       { $$.start = $$.end = $1; }
    |   if                                          { $$ = $1; }
    |   while                                       { $$ = $1; }
    |   t_begin statementlist t_end                   { $$ = $2; }
    ;


assignment :
        t_ident t_assignment expression
        {
            //Check SymbolTable
            if (!SymbolTable::getInstance()->lookup(new VarEntry($1)))
            {
                yyerror("Variable nicht deklariert oder Zuweisung an Methode!");
            }
            $$ = new AstStatement(0);
            $$->expr = $3;
            strcpy($$->ident, $1);
        }
    ;


proc_call :
        t_call t_ident
        {
            //Check SymbolTable
            if (!SymbolTable::getInstance()->lookup(new ProcEntry($2)))
            {
                yyerror("Methode nicht deklariert oder Aufruf einer Variablen!");
            }
            $$ = new AstStatement(1);
            strcpy($$->ident, $2);
        }
    ;


read :
        t_read t_ident
        {
            //Check SymbolTable
            if (!SymbolTable::getInstance()->lookup(new VarEntry($2)))
            {
                yyerror("Variable nicht deklariert!");
            }
            $$ = new AstStatement(2);
            strcpy($$->ident, $2);
        }
    ;


write :
        t_write expression
        {
            $$ = new AstStatement(3);
            $$->expr = $2;
            strcpy($$->ident, $2->ident);
        }
    ;

if :
        t_if condition t_then statement
        {
            $$.start = new AstStatement(9); //If
            $$.start->expr = $2;
            $$.start->next = $4.start;
            $$.end = new AstStatement(6);   //NOP
            $$.start->jump = $$.end;
        }
    ;


while :
        t_while condition t_do statement
        {
            AstStatement* n1 = new AstStatement(6); //Nop
            AstStatement* n2 = new AstStatement(5); //JMPF
            AstStatement* n3 = new AstStatement(6); //Nop


            strcpy(n3->ident, n2->ident);
            n1->next = n2;
            n2->jump = n3;
            n2->next = $4.start;
            n2->expr = $2;

            $$.start = n1;
            $$.end = n3;

            $$.start->token = 8; //While
        }
    ;


statementlist :
        statement                           { $$ = $1; }
    |   statement t_semic statementlist
        {
            $$ = $1;
            if ($3.start != NULL)
            {
                $$.end->next = $3.start;
                $$.end = $3.end;
            }
        }
    ;


condition :
        t_odd expression                      { $$ = new AstExpression("% 2 == 1", $2, NULL); }
    |   expression t_equal expression         { $$ = new AstExpression("==", $1, $3); }
    |   expression t_noteq expression      { $$ = new AstExpression("!=", $1, $3); }
    |   expression t_greater expression       { $$ = new AstExpression(">", $1, $3);  }
    |   expression t_greatereq expression      { $$ = new AstExpression(">=", $1, $3); }
    |   expression t_less expression          { $$ = new AstExpression("<", $1, $3);  }
    |   expression t_lesseq expression         { $$ = new AstExpression("<=", $1, $3); }
    ;


expression :
        term                                { $$ = $1; }
    |   expression t_add term                 { $$ = new AstExpression("+", $1, $3); }
    |   expression t_sub term                 { $$ = new AstExpression("-", $1, $3); }
    ;


term :
        factor                              { $$ = $1; }
    |   term t_mul factor                     { $$ = new AstExpression("*", $1, $3); }
    |   term t_div factor                     { $$ = new AstExpression("/", $1, $3); }
    ;


factor :
        t_ident                          { $$ = new AstExpression($1, NULL, NULL); }
    |   t_num
        {
            // convert int to char via sprintf();
            char str[30];
            sprintf(str, "%d", $1);
            $$ = new AstExpression(str, NULL, NULL);
        }
    |   t_lbracket expression t_rbracket
        {
            $$ = $2;
        }
    |   t_add factor                          { $$ = $2; }
    |   t_sub factor                          { $$ = new AstExpression("-", NULL, $2); }
    ;
%%
