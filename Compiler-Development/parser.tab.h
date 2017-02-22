
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     t_begin = 258,
     t_call = 259,
     t_const = 260,
     t_do = 261,
     t_else = 262,
     t_end = 263,
     t_if = 264,
     t_odd = 265,
     t_procedure = 266,
     t_then = 267,
     t_var = 268,
     t_while = 269,
     t_read = 270,
     t_write = 271,
     t_add = 272,
     t_sub = 273,
     t_mul = 274,
     t_div = 275,
     t_greater = 276,
     t_less = 277,
     t_equal = 278,
     t_assignment = 279,
     t_lesseq = 280,
     t_greatereq = 281,
     t_semic = 282,
     t_dot = 283,
     t_comma = 284,
     t_lbracket = 285,
     t_rbracket = 286,
     t_noteq = 287,
     t_err = 288,
     t_num = 289,
     t_ident = 290
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 24 "parser.y"

    int number;
    const char* ident;
    AstBlock * astBlock;
    AstStatement * astStatement;
    AstExpression * astExpression;
    AstIdentifier * astIdentifier;
    struct { AstStatement * start; AstStatement * end; } list;



/* Line 1676 of yacc.c  */
#line 99 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


