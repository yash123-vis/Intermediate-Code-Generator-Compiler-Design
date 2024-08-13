%{
  #include <bits/stdc++.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <ctype.h>
  using namespace std;


 int yylex();
 extern int yylineno;

void yyerror (const char *s) {fprintf (stderr, "\033[0;31mLine:%d | %s\n\033[0m\n",yylineno, s);} 
  extern FILE *yyin;


  typedef struct quadruples
  {
    char *op;
    char *arg1;
    char *arg2;
    char *res;
  }quad;
  int quadlen = 0;
  
  quad q[100];

  int top=-1;


void push();
void pushi(char * i);
void pusha();
void pushx();
void pushab();
void codegen();
void codegen_assign();
void codegen_incdec(int o);
void for1();
void for2();
void for3();
void for4();
void printStack();
void printQuadraples();
void constantPropagation(int index, quad arr[100]);
int checkForDigits(char *ch);
char* compute(char *x, char *y, char *op);
void constantFolding(quad arr[100]);
void copyPropagation(quad arr[100]);
void DCE(quad arr[100]);
%}

%start StartFile

%union {
     char *sval;
	 int nval;
}

//To access yyloc
%locations

%token <sval> T_PACKAGE T_IMPORT T_FUNC T_BREAK T_CONST T_CONTINUE T_PRINT
%token <sval> T_ELSE T_FOR T_IF T_RETURN T_VAR T_VAR_TYPE
%token <sval> T_BOOL_CONST T_IDENTIFIER T_STRING T_NIL_VAL
%token <sval> T_INTEGER 
%token <sval> T_FLOAT
%token <sval>  T_INCREMENT T_DECREMENT

%left <sval> T_ADD T_MINUS T_MULTIPLY T_DIVIDE T_MOD
%right <sval> T_ASSIGN T_NOT
%left <sval> T_LAND T_LOR T_EQL T_NEQ T_LEQ T_GEQ T_SEMICOLON
%left <sval> T_GTR T_LSR T_LEFTPARANTHESES T_RIGHTPARANTHESES T_LEFTBRACE T_RIGHTBRACE T_LEFTBRACKET T_RIGHTBRACKET T_COMMA T_PERIOD

%type <sval> unary_op bin_op math_op assign_op rel_op
%type <sval> Expression Operand BasicLit ExpressionList Declaration

%% 

StartFile:
    T_PACKAGE PackageName ImportDeclList TopLevelDeclList {
	};

Block:
	T_LEFTBRACE StatementList T_RIGHTBRACE {}
	| /*empty*/ {}; 

StatementList:
    StatementList Statement T_SEMICOLON {}
    | Statement T_SEMICOLON {}
	| StatementList Statement {}
    | Statement{};

Statement:
	Declaration {}
	| SimpleStmt {}
	| Block {}
	| IfStmt {}
	| ForStmt {} 
	| PrintStmt {};

SimpleStmt:
	Expression assign_op Expression {codegen_assign();} 
	| Expression T_INCREMENT {codegen_incdec(1);}
	| Expression T_DECREMENT {codegen_incdec(0);} 
	| ExpressionList assign_op ExpressionList {
		// b,c = 2,3
	}
	| /*empty*/{};
	
Declaration:
	T_VAR Expression Type assign_op ExpressionList {codegen_assign();}
    | T_VAR Expression Type {};
    | T_CONST Expression Type assign_op ExpressionList {codegen_assign();}
    | T_CONST Expression Type {};
    ;

PrintStmt:
	T_PRINT T_LEFTPARANTHESES T_STRING T_RIGHTPARANTHESES {};

FunctionDecl:
	T_FUNC T_IDENTIFIER T_LEFTPARANTHESES T_RIGHTPARANTHESES Block {};

TopLevelDeclList:
    TopLevelDeclList TopLevelDecl  {}
	| TopLevelDeclList T_SEMICOLON TopLevelDecl  {}
    | TopLevelDecl  {};

TopLevelDecl:
	Declaration {}	
	| FunctionDecl {};

Type:
	T_VAR_TYPE {
	};

Operand:
	BasicLit {}
	| T_IDENTIFIER {pushi($1);}
	| T_LEFTPARANTHESES Expression T_RIGHTPARANTHESES {};


IfStmt:
	T_IF Expression Block
    | T_IF Expression Block T_ELSE  Block
	| T_IF Expression Block T_ELSE IfStmt
	;

ForStmt: 
  T_FOR SimpleStmt{for1();} T_SEMICOLON Expression{for2();} T_SEMICOLON SimpleStmt{for3();} Block{for4();} {
  };

ExpressionList:
	Expression {};

BasicLit:
	T_INTEGER {push();}
	| T_FLOAT {push();}
	| T_STRING {push();}
	| T_BOOL_CONST {push();
	};

Expression:
	Expression math_op Expression{codegen();} 
	{
	}
	| Expression rel_op Expression{codegen();}{
	}
	| Expression bin_op Expression {
		// For logical operators
	}
	| unary_op Operand {
		}
	| Operand {};

bin_op:
	T_LOR {push();}
	| T_LAND {push();};

rel_op:
	T_EQL {push();}
	| T_NEQ {push();}
	| T_LSR {push();}
	| T_LEQ {push();}
	| T_GTR {push();}
	| T_GEQ {push();};

math_op:
	T_ADD {push();}
	| T_MINUS {push();}
	| T_MULTIPLY {push();}
	| T_DIVIDE {push();}
	| T_MOD {push();};

unary_op:
	T_ADD {}
	| T_MINUS {}
	| T_NOT {};

assign_op:
	T_ASSIGN {push();};

PackageName:
	T_IDENTIFIER {}
	| T_STRING {}
	| T_STRING T_SEMICOLON {};
	
//Can be list of imports, single import or no imports. Imports from local paths not accounted for.

ImportDeclList:
      ImportDeclList ImportDecl {}
    | ImportDecl {}
    | /*empty*/ {};

ImportDecl:
	T_IMPORT PackageName {}
	| T_IMPORT T_LEFTPARANTHESES ImportSpecList T_RIGHTPARANTHESES {};

ImportSpecList:
	ImportSpecList PackageName {}
	| PackageName {};

%%

#include "lex.yy.c"
#include<ctype.h>
#include<fstream>
char st[100][100];
char i_[2]="0";
int temp_i=0;
char tmp_i[3];
char temp[2]="t";
int label[20];
int lnum=0;
int ltop=0;
int l_for=0;
ofstream fo;

int main (int argc, char** argv) {	
	printf("Inside main\n");
	FILE * fp= fopen(argv[1], "r");
	yyin = fp;
    fo.open("tac.txt");
	printf("Read the input file, continue with Lexing and Parsing\n");
	printf("Performing Lexical analysis......\n\n");
	yyparse ( );
	printf("\n\033[0;32mParsing completed.\033[0m\n\n");
	printf("---------------------ICG in the Three addres code in form of Quadruples-------------------------\n\n");
    printQuadraples();
    fo.close();
	return 0;
}

void printQuadraples()
{
    for(int i=0;i<62;i++)
        printf("-");
    cout << endl;
    printf("Operator \t | Arg1 \t | Arg2 \t | Result \n");
    for(int i=0;i<62;i++)
        printf("-");
    cout << endl;
    int i;
    for(i=0;i<quadlen;i++)
    {
        printf("%-8s \t | %-8s \t | %-8s \t | %-6s \n",q[i].op,q[i].arg1,q[i].arg2,q[i].res);
    }
	for(int i=0;i<62;i++)
        printf("-");
    cout << endl;
}

void printStack()
{
    cout << "Stack Top " << st[top] <<" "<<st[top-1]<<" "<<st[top-2]<<" "<<st[top-3]<<endl;
}

void push()
{
    cout << "Pushed to stack : "<<yytext<<endl;
    strcpy(st[++top],yytext);
    printStack();
}
void pusha()
{
    strcpy(st[++top],"  ");
}

void pushi(char * i)
{
    cout << "Pushed to stack : "<<i<<endl;
    strcpy(st[++top],i);
}
void pushx()
{
    strcpy(st[++top],"x ");
}
void pushab()
{
    strcpy(st[++top],"  ");
    strcpy(st[++top],"  ");
    strcpy(st[++top],"  ");
}

void codegen()
{   
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("%s = %s %s %s\n",temp,st[top-2],st[top-1],st[top]);
    
    fo << temp <<" = "<<st[top-2]<<" "<<st[top-1]<<" "<<st[top]<<endl;
    q[quadlen].op = (char*)malloc(sizeof(char)*strlen(st[top-1]));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top-2]));
    q[quadlen].arg2 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,st[top-1]);
    strcpy(q[quadlen].arg1,st[top-2]);
    strcpy(q[quadlen].arg2,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    top-=2;
    strcpy(st[top],temp);
    temp_i++;
}

void codegen_assign()
{  
    fo << st[top-2] <<" = "<<st[top]<<endl;
    printf("%s = %s\n",st[top-2],st[top]);
    q[quadlen].op = (char*)malloc(sizeof(char));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(st[top-2]));
    strcpy(q[quadlen].op,"=");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,st[top-2]);
    quadlen++;

    top-=2;
}

void codegen_incdec(int o){
    if(o)
        pushi("+");
    else
        pushi("-");
    pushi("1");
    char tempi[31];
    strcpy(tempi,st[top-2]);
    codegen();
    pushi("=");
    cout<<"hello "<<st[top]<<" "<<st[top-1]<<" "<<st[top-2]<<endl;
    pushi(st[top-1]);
    cout<<"hello "<<st[top]<<" "<<st[top-1]<<" "<<st[top-2]<<endl;
    strcpy(st[top-2],tempi);
    codegen_assign();
}

void for1()
{   
    l_for = lnum;
    fo << "L"<<lnum<<": "<<endl;
    printf("L%d: \n",lnum++);
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"Label");
    char x[10];
    sprintf(x,"%d",lnum-1);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
}
void for2()
{ 
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    fo << temp <<" = not "<<st[top]<<endl;
    printf("%s = not %s\n",temp,st[top]);
    q[quadlen].op = (char*)malloc(sizeof(char)*4);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"not");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    fo <<"if "<<temp<<" goto L"<<lnum<<endl;
    printf("if %s goto L%d\n",temp,lnum);
    q[quadlen].op = (char*)malloc(sizeof(char)*3);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"if");
    strcpy(q[quadlen].arg1,temp);
    char x[10];
    sprintf(x,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
    temp_i++;
    label[++ltop]=lnum;
    lnum++;
    fo <<"goto L"<<lnum<<endl;
    printf("goto L%d\n",lnum);
    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"goto");
    char x1[10];
    sprintf(x1,"%d",lnum);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,x1));
    quadlen++;
    label[++ltop]=lnum;
    printf("L%d: \n",++lnum);
    fo <<"L"<<lnum<<": "<<endl;
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"Label");
    char x2[10];
    sprintf(x2,"%d",lnum);
    char l2[]="L";
    strcpy(q[quadlen].res,strcat(l2,x2));
    quadlen++;
 }
void for3()
{   
    int x;
    x=label[ltop--];
    fo <<"goto L"<<l_for<<" "<<endl;
    printf("goto L%d \n",l_for);
    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"goto");
    char jug[10];
    sprintf(jug,"%d",l_for);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,jug));
    quadlen++;
    fo <<"L"<<x<<": "<<endl;
    printf("L%d: \n",x);
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(x+2));
    strcpy(q[quadlen].op,"Label");
    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,jug1));
    quadlen++;

}
void for4()
{   
    int x;
    x=label[ltop--];
    fo <<"goto L"<<lnum<<" "<<endl;
    printf("goto L%d \n",lnum);
    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"goto");
    char jug[10];
    sprintf(jug,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,jug));
    quadlen++;
    fo <<"L"<<x<<": "<<endl;
    printf("L%d: \n",x);
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(x+2));
    strcpy(q[quadlen].op,"Label");
    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,jug1));
    quadlen++;
}

char* compute(char *x, char *y, char *op)
{
    char* res;
    int xx=atoi(x);
    int yy=atoi(y);
    int result = 0;
    switch(*op)
    {
      case '+':
        result = xx+yy;
        break;
      case '-':
        result = xx-yy;
        break;
      case '*':
        result = xx*yy;
        break;
      case '/':
        result = xx/yy;
        break;
      case '%':
        result = xx%yy;
        break;
      case '>':
        res= strdup((xx>yy)?"true":"false");
        return res;
      case '<':
        res= strdup((xx<yy)?"true":"false");
        return res;
      default:
        if(strcmp(op,"==")) return (xx==yy)?(char *)"true":(char *)"false";
        else if(strcmp(op,">=")) return (xx>=yy)?(char *)"true":(char *)"false";
        else if(strcmp(op,"!=")) return (xx!=yy)?(char *)"true":(char *)"false";
        else if(strcmp(op,"<=")) return (xx<=yy)?(char *)"true":(char *)"false";
    }
    return (char*)to_string(result).c_str();
}
void copyPropagation(quad arr[100])
{
    char val[50], var[50];
    int i=0;
    for(; i<quadlen; i++)
    {     
        if(!arr[i].arg2){
            strcpy(var, arr[i].res);
            strcpy(val, arr[i].arg1);
            
            int flag = 0; 
            for(int j = i + 1; j<quadlen; j++)
            {
                    
                    if(strcmp(arr[j].res, var)==0){
                        break;
                    }
                    
                    if (strcmp(arr[j].arg1, var)==0){
                        strcpy(arr[j].arg1, val);
                        flag = 1;
                    }
                    
                    if (arr[j].arg2 && strcmp(arr[j].arg2, var)==0){
                        strcpy(arr[j].arg2, val);
                        flag = 1;
                    }
            }
            
            if(flag){
                int del = i;
                for (int k = del-1; k < quadlen; k++)
                {
                    arr[del]=arr[del+1];
                    del++;
                }
                
                quadlen=quadlen-1;
            }
        }
    }
}
void constantPropagation(int index, quad arr[100])
{
    char val[50], var[50];
    int i=index;
    strcpy(var, arr[i].res);
    strcpy(val, arr[i].arg1);
    i=index+1;
    for(; i<quadlen; i++)
    {   
        if (strcmp(arr[i].op, "if")!=0 && strcmp(arr[i].op, "goto")!=0 && strcmp(arr[i].op, "call")!=0 && strcmp(arr[i].op, "proc")!=0 && arr[i].op[0]!='L'&&strcmp(arr[i].res, "stack top")!=0){    
            if(strcmp(arr[i].res, var)==0)
            {
                return;
            }
            else if(arr[i].arg2 && strcmp(arr[i].arg2, var)==0)
            {
                strcpy(arr[i].arg2, val);
            }
            else if(arr[i].arg1 && strcmp(arr[i].arg1, var)==0)
            {
                strcpy(arr[i].arg1, val);
            }
        }
    }
}
int checkForDigits(char *ch)
{
    if(!ch) return 0;
    while(*ch)
    {
        if(isdigit(*ch++)==0)
        {
          return 0;
        }
        return 1;
    }
}

void constantFolding(quad arr[100])
{
  int i=0, flag=0;
  char* res=0;

  while(i<quadlen)
  {
    
    if(!arr[i].arg2)
    {
      flag=1;
      constantPropagation(i, arr);
    }
    int ch1=checkForDigits(arr[i].arg1);
    int ch2=checkForDigits(arr[i].arg2);

    char stringres[50];
    if(ch1==1 && ch2==1) 
    {
      
      res=compute(arr[i].arg1, arr[i].arg2, arr[i].op);
    
      strcpy(arr[i].op, "=");
      strcpy(arr[i].arg1, res);
      strcpy(arr[i].arg2, " ");

      constantPropagation(i, arr); 
    }
    i++;
  }
}
void DCE(quad arr[100])
{   
    char val[50], var[50];
    int i=0;
    for(; i<quadlen-1; i++)
    {       
            strcpy(var, arr[i].res);
            int flag = 1; 
            for(int j = i + 1; j<quadlen; j++)
            {
                    if (strcmp(arr[j].arg1, var)==0 || (arr[j].arg2 && strcmp(arr[j].arg2, var)==0) || (strcmp(arr[j].res,var)==0)){
                        flag = 0;
                        break;
                    }
            }
            if(flag){
                int del = i;
                for (int k = del-1; k < quadlen; k++)
                {
                    arr[del]=arr[del+1];
                    del++;
                }
                quadlen=quadlen-1;
            }

    }
}