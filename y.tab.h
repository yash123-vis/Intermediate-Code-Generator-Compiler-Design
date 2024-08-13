
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

/* "%code requires" blocks.  */

/* Line 1676 of yacc.c  */
#line 17 "ast.y"

    #include "ast.h"



/* Line 1676 of yacc.c  */
#line 46 "y.tab.h"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_PACKAGE = 258,
     T_IMPORT = 259,
     T_FUNC = 260,
     T_BREAK = 261,
     T_CONST = 262,
     T_CONTINUE = 263,
     T_PRINT = 264,
     T_ELSE = 265,
     T_FOR = 266,
     T_IF = 267,
     T_RETURN = 268,
     T_VAR = 269,
     T_VAR_TYPE = 270,
     T_BOOL_CONST = 271,
     T_IDENTIFIER = 272,
     T_STRING = 273,
     T_NIL_VAL = 274,
     T_INTEGER = 275,
     T_FLOAT = 276,
     T_INCREMENT = 277,
     T_DECREMENT = 278,
     T_MOD = 279,
     T_DIVIDE = 280,
     T_MULTIPLY = 281,
     T_MINUS = 282,
     T_ADD = 283,
     T_NOT = 284,
     T_ASSIGN = 285,
     T_SEMICOLON = 286,
     T_GEQ = 287,
     T_LEQ = 288,
     T_NEQ = 289,
     T_EQL = 290,
     T_LOR = 291,
     T_LAND = 292,
     T_PERIOD = 293,
     T_COMMA = 294,
     T_RIGHTBRACKET = 295,
     T_LEFTBRACKET = 296,
     T_RIGHTBRACE = 297,
     T_LEFTBRACE = 298,
     T_RIGHTPARANTHESES = 299,
     T_LEFTPARANTHESES = 300,
     T_LSR = 301,
     T_GTR = 302
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 21 "ast.y"

     char *sval;
	 int nval;
     AST* node;



/* Line 1676 of yacc.c  */
#line 118 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;

