%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include "y.tab.h"

FILE  *yyin;

int i=0; //Indice para insertar en la tabla de simbolos
void guardarTS_Archivo(); //Lee toda la tabla de simbolos y la guarda en un txt
int guardarLexemas(char *,int); //Guarda el lexema en la tabla de simbolos
int buscar(char *); //Antes de insertar un lexema busca que no exista en la tabla de simbolos



typedef struct {
       		    char lexema[100]; 
                char tipo[100];				
                char valor[100];	
				char longitud[25];
	            } tsimbolos;

tsimbolos ts[20]; 
%}

%option noyywrap  
%option yylineno 

DIGITO [0-9]
LETRA  [a-zA-Z]
ID  {LETRA}({LETRA}|{DIGITO}|"_")*
CTE {DIGITO}+
CTE_S   \"[^\n]+\" 
WRITE "write"|"WRITE"
READ "read"|"READ"
SUMAIMPAR "sumaimpar"|"SUMAIMPAR"
COMA ","
PYC ";"
ASIGNA "="
PARA "("
PARC ")"
CA "["
CC "]"



%%

{WRITE}	    {return WRITE;}
{READ}	    {return READ;}
{SUMAIMPAR} {return SUMAIMPAR;}
{CTE}   {guardarLexemas(yytext,2);return CTE;}
{CTE_S} {return CTE_S;}
{ID}    {guardarLexemas(yytext,0);return ID;}
{COMA}  {return COMA;}
{PYC}   {return PYC;}
{ASIGNA}    {return ASIGNA;}
{PARA}  {return PARA;}
{PARC}  {return PARC;}
{CA}    {return CA;}
{CC}    {return CC;}

"\n"      		
"\t"
" "	
"\r\n" 

%%

void guardarTS_Archivo()
{
	FILE* arch; 
	int x;
 
    arch = fopen("ts.txt", "w+");
	
	if (!arch)
	{
		printf("Error. No se pudo crear el archivo ts.txt");
		exit(1);
	}
	
	fprintf(arch,"%-23s%-15s%-28s%8s\n","lexema","Tipo","Valor","Longitud");
	for(x=0;x<i;x++)
	{
		fprintf(arch,"%-23s%-15s%-20s%8s",ts[x].lexema,ts[x].tipo,ts[x].valor,ts[x].longitud);
		fprintf(arch,"\n");
	}    
	fclose(arch);  
	printf("Archivo TS completado\n");
  
}

int guardarLexemas(char *lexema,int val)
{
	//El lexema es id
    if(val==0)
	{
	   if(buscar(lexema)!=0)
	   {
			strcpy(ts[i].lexema,lexema);
            strcpy(ts[i].tipo,"Integer");
			i++;
	   } 
	}
    //El lexema es constante string
    if(val==1)
	{
		char *s=lexema;
        char *aux;
		/**s++;//adelanto el puntero para que no tome la 1eras comillas
		int n=strlen(lexema)-2;//le resto 2 para que no copie las comillas (iniciales y finales)
		printf("Indice : %s\n",s);
		strncpy(lexema,s,n);
		while(n > 1)//llevo el puntero hasta la posicion que debe finalizar el string 
		{
			n--;
		    s++;
		}
		
	    memset(s, '\0',n);//marco el fin del string*/

	  char auxL[5];
	  sprintf(auxL,"_STR%d",i);
	  if(buscar(auxL)!=0)
	  {
        
		//strcpy(ts[i].lexema,"_");
       	strcat(ts[i].lexema,auxL);
	    strcpy(ts[i].valor,lexema);
        strcpy(ts[i].tipo,"String");
	    itoa(strlen(lexema),ts[i].longitud,10);	
        i++;
		return i-1;	   
      }
	
	}
   //El lexema es constante integer  
   if(val==2)
	{
		char auxLexema[100];
		strcpy(auxLexema,"_");
		strcat(auxLexema,lexema);
		if(buscar(auxLexema)!=0)
		{
			strcpy(ts[i].lexema,"_");
		    strcat(ts[i].lexema,lexema);
		    strcpy(ts[i].valor,lexema);
            strcpy(ts[i].tipo,"CTE_INT");
			i++;
		}		
	}
	
       
}

int buscar(char * lexema)
{
	int x;
	for(x=0;x<i;x++)
	{
		if(strcmp(ts[x].lexema,lexema)==0)  
		return 0;  
	}
	return 1;
}



