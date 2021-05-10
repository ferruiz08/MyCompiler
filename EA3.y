%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <errno.h>
#include "y.tab.h"

typedef struct {
       		    char lexema[100]; // lexema
                char tipo[100];				
                char valor[100];	
				char longitud[25];
	            }tsimbolos;
tsimbolos ts[50];

char * yytext;
int yystopparser=0;
int yylineno;
FILE  *yyin;
char *yyltext;


char idAux[100];
char idAsig[100];
char bufferaux1[100];
char bufferaux2[100];
char pivot[50];

int yylex();                
FILE  *yyin;

/*****************TERCETOS**********************/
int L_ind = 0;
int cant_tercetos = 0;
typedef struct terceto {
		int nroTerceto;
		char ope[30];
		char te1[99];
		char te2[30];
		char resultado_aux[10];
        int esEtiqueta;
	} terceto;
terceto vector_tercetos[100];
int indice_terceto = 0;	
int tercetosSaltos[100];
int tercetosEtiquetas[100];
int indiceSaltos = 0;
int cantConstantesImpar = 0;
int cantConstantesTotal = 0;
int saltoError1 = 0;
int saltoError2 = 0;
int saltoError3 = 0;
int saltoError4 = 0;
int saltoError5 = 0;

void insertarEtiqueta(char *indiceTerceto);
/* crea un terceto y lo agrega a la coleccion */
int crear_terceto(char*, char*, char*);
/* escribe los tercetos en un archivo */
void escribir_tercetos();
void escribirEtiquetas();
void preparar_assembler();
void convertirSalto(int);
int listaVacia = 0;

/***************ASSEMBLER******************/


void generarAsm();
void imprimirHeader(FILE*);
void imprimirVariables(FILE*);
void imprimirCodigo(FILE*);
int esSalto(int);
int esOperacion(int);
char* validaTipo(char*);
char* buscarValor(char *);


%}

%union {
	int int_val;
	double float_val;
	char *str_val;
}

%token WRITE
%token READ
%token SUMAIMPAR
%token CTE
%token CTE_S
%token ID
%token COMA
%token PYC
%token ASIGNA
%token PARA
%token PARC
%token CA
%token CC



%%
s: prog {printf("\nCOMPILACION EXITOSA\n");};

prog: sent 
    | prog sent;

sent: read | write | asig;

read: READ ID
    {
        strcpy(idAux,yytext);
        crear_terceto("READ",idAux,"_");

    };

asig: ID {strcpy(idAsig,yytext);} ASIGNA sumaimpar
    {
        int j;
        int saltoFinSumaImpar;
        saltoFinSumaImpar = crear_terceto("=",idAsig,"@auxResultado");

        for (j = 0; j < indiceSaltos; j++)
        {
            char auxSalto[5];
            itoa(saltoFinSumaImpar,auxSalto,10);
            strcpy(vector_tercetos[tercetosSaltos[j]].te1,auxSalto);
            insertarEtiqueta(auxSalto);
        }
    }   

sumaimpar: SUMAIMPAR PARA ID 
            {
                strcpy(pivot,yytext);
                char auxSalto[5];
                char auxTe1[5];
                char auxLexema[100];
                int nroLexema = 0;

                //Creo el terceto que va a comparar si el pivot es mayor o igual a 1
                saltoError1 = crear_terceto("CMP",pivot,"_1");
                guardarLexemas("1",2);
                itoa(saltoError1+4,auxSalto,10);
                crear_terceto("BGE",auxSalto,"_");
                insertarEtiqueta(auxSalto);
                strcpy(auxLexema,"\"El valor de pivot debe ser >= 1\"");
                nroLexema = guardarLexemas(auxLexema,1);
                sprintf(auxTe1,"_STR%d",nroLexema);
                crear_terceto("PRINT",auxTe1,"_");
                crear_terceto("BI","END","_");

                
                //Creo el terceto que va a comparar si la lista esta vacia
                saltoError4 = crear_terceto("CMP","_1","_");
                guardarLexemas("1",2);
                itoa(saltoError4+4,auxSalto,10);
                crear_terceto("BLE",auxSalto,"_");
                insertarEtiqueta(auxSalto);
                strcpy(auxLexema,"\"La lista está vacía\"");
                nroLexema = guardarLexemas(auxLexema,1);
                sprintf(auxTe1,"_STR%d",nroLexema);
                crear_terceto("PRINT",auxTe1,"_");
                crear_terceto("BI","END","_");

                
                //Creo el terceto que va a comparar si el pivot es mayor a la cantidad de constantes totales
                saltoError3 = crear_terceto("CMP",pivot,"_");
                itoa(saltoError3+4,auxSalto,10);
                crear_terceto("BLE",auxSalto,"_");
                insertarEtiqueta(auxSalto);
                strcpy(auxLexema,"\"La lista tiene menos elementos que el indicado\"");
                nroLexema = guardarLexemas(auxLexema,1);
                sprintf(auxTe1,"_STR%d",nroLexema);
                crear_terceto("PRINT",auxTe1,"_");
                crear_terceto("BI","END","_");
                    

                //Creo el terceto que va a comparar si hay impares
                saltoError5 = crear_terceto("CMP","_1","_");
                guardarLexemas("1",2);
                itoa(saltoError5+4,auxSalto,10);
                crear_terceto("BLE",auxSalto,"_");
                insertarEtiqueta(auxSalto);
                strcpy(auxLexema,"\"Elementos impares no encontrados\"");
                nroLexema = guardarLexemas(auxLexema,1);
                sprintf(auxTe1,"_STR%d",nroLexema);
                crear_terceto("PRINT",auxTe1,"_");
                crear_terceto("BI","END","_");
                    

                //Creo el terceto que va a comparar si el pivot es mayor a la cantidad de constantes a sumar
                saltoError2 = crear_terceto("CMP",pivot,"_");
                itoa(saltoError2+4,auxSalto,10);
                crear_terceto("BLE",auxSalto,"_");
                insertarEtiqueta(auxSalto);
                strcpy(auxLexema,"\"No existen suficientes elementos impares para el cálculo\"");
                nroLexema = guardarLexemas(auxLexema,1);
                sprintf(auxTe1,"_STR%d",nroLexema);
                crear_terceto("PRINT",auxTe1,"_");
                crear_terceto("BI","END","_");
                

                

               }


            
            sumaimpar2 
            {
                char auxCantConstantesImpar[5];
                char auxCantConstantesTotal[5];
                //Agrego en el terceto del salto por constantes impares la cantidad de constantes a comparar
                strcpy(bufferaux1,"_");
                itoa(cantConstantesImpar,auxCantConstantesImpar,10);
                guardarLexemas(auxCantConstantesImpar,2);
                strcat(bufferaux1,auxCantConstantesImpar);
                strcpy(vector_tercetos[saltoError2].te2,bufferaux1);
                strcpy(vector_tercetos[saltoError5].te2,bufferaux1);
                

                //Agrego en el terceto del salto por constantes totales la cantidad de constantes a comparar
                strcpy(bufferaux1,"_");
                itoa(cantConstantesTotal,auxCantConstantesTotal,10);
                guardarLexemas(auxCantConstantesTotal,2);
                strcat(bufferaux1,auxCantConstantesTotal);
                strcpy(vector_tercetos[saltoError3].te2,bufferaux1);
                strcpy(vector_tercetos[saltoError4].te2,bufferaux1);
                

            }

sumaimpar2: PYC CA lista CC PARC

            | PYC CA CC PARC
            {
                char auxCantConstantesTotal[5];
                //Agrego en el terceto del salto por lista vacia
                strcpy(bufferaux1,"_");
                itoa(cantConstantesTotal,auxCantConstantesTotal,10);
                guardarLexemas(auxCantConstantesTotal,2);
                strcat(bufferaux1,auxCantConstantesTotal);
                strcpy(vector_tercetos[saltoError4].te2,bufferaux1);

            };

lista: CTE
        {
            //si la CTE es impar creo el terceto constante
            int valor;
            char auxResultado[5];
            strcpy(idAux,yytext);
            valor = atoi(idAux);
            printf("Nro:%d\n",valor);
            //Incremento la cantidad de constantes totales
            cantConstantesTotal++;
            if(valor%2!=0)
            {
                strcpy(bufferaux1,"_");
	            strcat(bufferaux1,idAux);
                L_ind = crear_terceto(bufferaux1,"_","_");
                

                
                strcpy(bufferaux1,"@aux");							// copio @aux
                itoa(L_ind,bufferaux2,10);									// transformo el nro de terceto
                strcat(bufferaux1,bufferaux2);								// creo la variable aux de assembler
                strcpy(vector_tercetos[L_ind].resultado_aux,bufferaux1);	// guardo junto al terceto
                guardarLexemas(bufferaux1,0);

                sprintf(auxResultado,"%d",L_ind);
                crear_terceto("=","@auxResultado",auxResultado);
                
                //Creo el terceto que incrementa la cantidad de constantes sumadas
                L_ind = crear_terceto("+","@auxSumas","_1");
                strcpy(bufferaux1,"@aux");							// copio @aux
                itoa(L_ind,bufferaux2,10);									// transformo el nro de terceto
                strcat(bufferaux1,bufferaux2);								// creo la variable aux de assembler
                strcpy(vector_tercetos[L_ind].resultado_aux,bufferaux1);	// guardo junto al terceto
                guardarLexemas(bufferaux1,0);

                sprintf(auxResultado,"%d",L_ind);
                crear_terceto("=","@auxSumas",auxResultado);



                //Incremento la cantidad de constantes para sumar
                cantConstantesImpar++;
            }
            else
            {
                L_ind = -1; //Si la primer constante es par no se creo el terceto 
            }
            
        }
        | lista COMA CTE
        {
            //Si la CTE es impar creo el terceto suma, lista, constante
            char aux[5];
            char auxResultado[5];
            int valor;
            strcpy(idAux,yytext);
            valor = atoi(idAux);
            printf("Nro:%d\n",valor);
            //Incremento la cantidad de constantes totales
            cantConstantesTotal++;
            strcpy(bufferaux1,"_");
	        strcat(bufferaux1,idAux);
            if(valor%2!=0)
            {
                if( L_ind == -1) //Si la primer constante que se recibio fue par y no pudo crear el terceto)
                {
                    
                    L_ind = crear_terceto(bufferaux1,"_","_");

                    strcpy(bufferaux1,"@aux");							// copio @aux
                    itoa(L_ind,bufferaux2,10);									// transformo el nro de terceto
                    strcat(bufferaux1,bufferaux2);								// creo la variable aux de assembler
                    strcpy(vector_tercetos[L_ind].resultado_aux,bufferaux1);	// guardo junto al terceto
                    guardarLexemas(bufferaux1,0);

                    sprintf(auxResultado,"%d",L_ind);
                    crear_terceto("=","@auxResultado",auxResultado);
                    
                }
                else //Si la primer constante que se recibio fue impar y pudo crear el terceto
                {
                    //creo el terceto para comparar el pivot con la cantidad de constantes que ya sume
                    crear_terceto("CMP",pivot,"@auxSumas");

                    //Creo el terceto del salto y lo guardo para luego escribirle el terceto a donde saltar
                    tercetosSaltos[indiceSaltos] = crear_terceto("BLE","_","_");
                    indiceSaltos++;
                    
                    
                    
                    //sprintf(aux,"%d",L_ind);
                    L_ind = crear_terceto("+","@auxResultado",bufferaux1);

                    strcpy(bufferaux1,"@aux");							// copio @aux
                    itoa(L_ind,bufferaux2,10);									// transformo el nro de terceto
                    strcat(bufferaux1,bufferaux2);								// creo la variable aux de assembler
                    strcpy(vector_tercetos[L_ind].resultado_aux,bufferaux1);	// guardo junto al terceto
                    guardarLexemas(bufferaux1,0);


                    sprintf(auxResultado,"%d",L_ind);
                    crear_terceto("=","@auxResultado",auxResultado);
                    
                }

                //Creo el terceto que incrementa la cantidad de constantes sumadas
                L_ind = crear_terceto("+","@auxSumas","_1");

                strcpy(bufferaux1,"@aux");							// copio @aux
                itoa(L_ind,bufferaux2,10);									// transformo el nro de terceto
                strcat(bufferaux1,bufferaux2);								// creo la variable aux de assembler
                strcpy(vector_tercetos[L_ind].resultado_aux,bufferaux1);	// guardo junto al terceto
                guardarLexemas(bufferaux1,0);

                sprintf(auxResultado,"%d",L_ind);
                crear_terceto("=","@auxSumas",auxResultado);




                //Incremento la cantidad de constantes para sumar
                cantConstantesImpar++;
            }
        };

write: WRITE CTE_S
        {
            char auxTe1[5];
            char auxLexema[100];
            int nroLexema = 0;
            
            strcpy(auxLexema,yytext);
            nroLexema = guardarLexemas(auxLexema,1);
            sprintf(auxTe1,"_STR%d",nroLexema);
            crear_terceto("PRINT",auxTe1,"_");

        }
        | WRITE ID
        {
            strcpy(idAux,yytext);
            crear_terceto("PRINT",idAux,"_");
        };



%%


int main(int argc,char *argv[])
{
  if ((yyin = fopen(argv[1], "rt")) == NULL)
  {
	printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
  }
  else
  {

	yyparse();
    guardarLexemas("@auxResultado",0);
    guardarLexemas("@auxSumas",0);
	guardarTS_Archivo();
	escribir_tercetos();
    escribirEtiquetas();
    generarAsm();
  }
  fclose(yyin);
  return 0;
}

int yyerror(void)
{
     printf("Syntax Error\n");
	 system ("Pause");
	 exit (1);
}







/*****************TERCETOS**********************/

int  crear_terceto(char* p_ope, char* p_te1, char* p_te2)
{
	terceto res;
	res.nroTerceto = indice_terceto;
	strcpy(res.ope, p_ope);
	strcpy(res.te1, p_te1);
	strcpy(res.te2, p_te2);
	strcpy(res.resultado_aux,"_");
	vector_tercetos[indice_terceto] = res;
	indice_terceto++;
	return indice_terceto-1;
}

void escribir_tercetos()
{
	FILE* arch;
	int i;
	terceto aux;
	arch = fopen("intermedia.txt", "w+");

	for(i = 0; i < indice_terceto; i++)
	{	
		aux =  vector_tercetos[i];
		fprintf(arch, "[%d] (%s,%s,%s)\n", aux.nroTerceto, aux.ope,aux.te1, aux.te2 );
		
	}
	fclose(arch);
}

void insertarEtiqueta(char *indiceTerceto)
{
    int indice = atoi(indiceTerceto);
    tercetosEtiquetas[indice] = 1;
}

void escribirEtiquetas()
{
    int i = 0;
    for(i=0 ;i<100;i++)
    {
        if(tercetosEtiquetas[i]==1)
            vector_tercetos[i].esEtiqueta = 1;
        else
            vector_tercetos[i].esEtiqueta = 0;
    }

}

/***************ASSEMBLER******************/


void generarAsm()
{
	FILE *final = fopen("Final.asm","wt");
	if (final == NULL){
		printf("\r\nNo se pudo abrir el archivo Final\r\n");
		return;
	}
	char linea[50];
	char cmp[10]="FCOMP";

    preparar_assembler();

	imprimirHeader(final);

	imprimirVariables(final);

    imprimirCodigo(final);

    fprintf(final,"\nEtiqueta_END:\n");

    fprintf(final, "\nMOV AH, 1\nINT 21h\nMOV AX, 4C00h\nINT 21h\n\nEND START\n");
    
    fclose(final);
}


void imprimirHeader(FILE *p)
{
	
/*
    fprintf(p,"include macros2.asm\ninclude number.asm\n ");

    fprintf(p,".MODEL LARGE\n.386\n.STACK 200h\nMAXTEXTSIZE equ 50\n \n.DATA\n\n.DATA\n");*/
    
}

 void imprimirVariables(FILE * p)
{ 
int s,r,y;
   char aux[100];
   

	fprintf(p, "\ninclude macros2.asm\t\t ;incluye macros2");
    fprintf(p, "\ninclude number.asm\t\t ;incluye el asm para impresion de numeros");
	fprintf(p, "\n\n.model large");
	fprintf(p, "\n.386");
	fprintf(p, "\n.stack 200h");
	fprintf(p, "\n.LEN_LEXEMA equ 32");
	fprintf(p, "\n");
	fprintf(p, "\n.DATA\n");
	
	fprintf(p, "\n;Declaracion de variables y constantes.\n\n");
	
    fprintf(p, "@msg_int db \"Ingrese un entero:\", '$'\n");
	for(s=0;s<100;s++)
    {
        if(!strcmp(ts[s].tipo,"String"))
        {
        
            strcpy(aux,ts[s].lexema);
            for(y=0;y<strlen(aux);y++)
            {       
                if( aux[y]==' ' )
                    aux[y]='_';		
                if( aux[y]==':' )
                    aux[y]='_';
            }
            
            fprintf(p, "%s  DB  %s,'$'\n",aux,ts[s].valor);
        }
        
        
        if(!strcmp(ts[s].tipo,"CTE_INT"))
        {
            fprintf(p, "%s  DD  %.2f\n",ts[s].lexema,atof(ts[s].valor));
        }

        if(!strcmp(ts[s].tipo,"Integer"))
        {
            fprintf(p, "%s  DD ?\n",ts[s].lexema);
        }
   }

   fprintf(p, "\naux1 dd ?; auxiliar para realizar operaciones.");
 
   
    fprintf(p, "\n");
	fprintf(p, "\n.CODE");
	fprintf(p, "\nSTART:");
	
	fprintf(p, "\nmov AX,@DATA ;Copiar en AX (Registro Acumulador) la Direccion del Segmento de Datos");
	fprintf(p, "\nmov DS,AX ;Copiar en DS (Segmento de Datos) el registro AX");   
	fprintf(p, "\nMOV  ES,AX   ;Copiar en ES (Segmento Extra) el registro AX\n\n");  
 }

void preparar_assembler()
{
	char etiqueta[20] = "etiqueta_";
	int entero_aux;
    int i;
    int j;
	
/*	printf("ANTES: \n\n");
	for(i=0;i<indice_terceto;i++)
	{
		printf("    %s  %s  %s  %s  %d\n",vector_tercetos[i].ope,vector_tercetos[i].te1,vector_tercetos[i].te2,vector_tercetos[i].resultado_aux,vector_tercetos[i].esEtiqueta);
	}*/

	for(i=0;i<indice_terceto;i++)
	{

		if(strcmp(vector_tercetos[i].te1,"_")==0 && strcmp(vector_tercetos[i].te2,"_")==0 && vector_tercetos[i].esEtiqueta!=1 )
		{
			
			for(j=i+1;j< indice_terceto;j++)
			{
				itoa(i,bufferaux1,10);
				if(strcmp(vector_tercetos[j].te1,bufferaux1)==0)
				{
					strcpy(vector_tercetos[j].te1,vector_tercetos[i].ope);
				}
				if(strcmp(vector_tercetos[j].te2,bufferaux1)==0)
				{
					strcpy(vector_tercetos[j].te2,vector_tercetos[i].ope);
				}
			}
		}

		
		
		if(strcmp(vector_tercetos[i].te1,"_")==0 && strcmp(vector_tercetos[i].te2,"_")==0 && vector_tercetos[i].esEtiqueta==1 )
		{
			//printf("ETIQUETA + TERCETO _ _\n");
			j=i+1;
			itoa(i,bufferaux1,10);
			while(strcmp(vector_tercetos[j].te1,bufferaux1)!=0 && strcmp(vector_tercetos[j].te2,bufferaux1)!=0)
			j++;
			if(strcmp(vector_tercetos[j].te1,bufferaux1)==0)
			strcpy(vector_tercetos[j].te1,vector_tercetos[i].ope);
			else
			strcpy(vector_tercetos[j].te2,vector_tercetos[i].ope);
			
		}
		
        convertirSalto(i);

		if(esOperacion(i))
		{
            for(j=i+1;j< indice_terceto;j++)
			{	
				itoa(i,bufferaux1,10);
				if(strcmp(vector_tercetos[j].te1,bufferaux1)==0)
				{
					strcpy(vector_tercetos[j].te1,vector_tercetos[i].resultado_aux);
				}
				
				if(strcmp(vector_tercetos[j].te2,bufferaux1)==0)
				{
                    strcpy(vector_tercetos[j].te2,vector_tercetos[i].resultado_aux);
				}
				
			}
			
		}
		
		if(esSalto(i))
		{	
			//printf("OPE: %s - TE1: %s - TE2: %s\n",vector_tercetos[i].ope,vector_tercetos[i].te1,vector_tercetos[i].te2);
			entero_aux = atoi(vector_tercetos[i].te1);
			// printf("\nentero_aux: %d",entero_aux);
			vector_tercetos[entero_aux].esEtiqueta = 1;
			strcat(etiqueta,vector_tercetos[i].te1);
			// printf("\nETIQUETA: %s",etiqueta);
			strcpy(vector_tercetos[i].te1,etiqueta);
			// printf("\nvector_tercetos[%d].te1: %s",i,vector_tercetos[i].te1);
			strcpy(etiqueta,"etiqueta_");
		}
		
	}
	
	/*printf("DESPUES: \n\n");
	for(i=0;i<indice_terceto;i++)
	{
		printf("    %s  %s  %s  %s  %d\n",vector_tercetos[i].ope,vector_tercetos[i].te1,vector_tercetos[i].te2,vector_tercetos[i].resultado_aux,vector_tercetos[i].esEtiqueta);
	}*/
}


 void imprimirCodigo(FILE *p)
 {
    int i;

	for(i=0;i <= indice_terceto;i++)
	{		        

		if(vector_tercetos[i].esEtiqueta == 1)
		{
            // printf("\nVALOR i: %d", i);
            // printf("\nES ETIQUETA[%s, %s, %s]", vector_tercetos[i].te1, vector_tercetos[i].te2, vector_tercetos[i].resultado_aux);
			fprintf(p,"etiqueta_%d:\n",i);
		}

         //printf("ES OPERACION %d", esOperacion(i));
        // printf("\n[%s, %s, %s]\n", vector_tercetos[i].te1, vector_tercetos[i].te2, vector_tercetos[i].resultado_aux);
		
		switch(esOperacion(i))
		{
		case 1:
			fprintf(p,"fld %s\nfld %s\nfadd\nfstp %s\n",vector_tercetos[i].te1,vector_tercetos[i].te2, vector_tercetos[i].resultado_aux);
			break;
			
		case 2:
			fprintf(p,"fld %s\nfld %s\nfsub\nfstp %s\n", vector_tercetos[i].te1,vector_tercetos[i].te2, vector_tercetos[i].resultado_aux);
			break;
			
		case 3:
			fprintf(p,"fld %s\nfld %s\nfmul\nfstp %s\n", vector_tercetos[i].te1,vector_tercetos[i].te2, vector_tercetos[i].resultado_aux);
			break;
			
		case 4:
			fprintf(p,"fld %s\nfld %s\nfdiv\nfstp %s\n", vector_tercetos[i].te1,vector_tercetos[i].te2, vector_tercetos[i].resultado_aux);
			break;
			
		case 5:
			fprintf(p,"fld %s\nfstp %s\n", vector_tercetos[i].te2, vector_tercetos[i].te1);
			break;
			
		case 6:
			fprintf(p,"DisplayFloat %s,1\nnewLine\n\n", vector_tercetos[i].te1);
			break;
			
		case 7:
			fprintf(p,"DisplayString %s,1\nnewLine\n\n", vector_tercetos[i].te1);
			break;
			
		case 8: //Read enteros
			fprintf(p,"DisplayString @msg_int \n");
			fprintf(p,"int 21h \n");
			fprintf(p,"newLine 1\n");
			fprintf(p,"GetFloat %s \n",vector_tercetos[i].te1);
			break;
			
		case 9: //Read Real
			fprintf(p,"DisplayString @msg_float \n");
			fprintf(p,"int 21h \n");
			fprintf(p,"newLine 1\n");
			fprintf(p,"GetFloat %s \n",vector_tercetos[i].te1);
			break;
			
		case 10:
			fprintf(p,"LEA EAX, %s\n MOV %s , EAX\n", vector_tercetos[i].te2, vector_tercetos[i].te1);
			break;
			
		case 11:
			fprintf(p,"DisplayFloat %s,3\nnewLine\n\n", vector_tercetos[i].te1);
			break;
			
		}
		
		
		if(strcmp(vector_tercetos[i].ope,"CMP")==0)						// terceto de COMPARACION
		fprintf(p,"fld %s\nfld %s\nfxch\nfcomp\nfstsw ax\nsahf\n", vector_tercetos[i].te1,vector_tercetos[i].te2);
		
		
		switch(esSalto(i))
		{		
		case 1:
			fprintf(p,"JNA %s\n\n", vector_tercetos[i].te1);			// condicion >
			break;
			
		case 2:
			fprintf(p,"JAE %s\n\n", vector_tercetos[i].te1);			// condicion <
			break;
			
		case 3:
			fprintf(p,"JNAE %s\n\n", vector_tercetos[i].te1);			// condicion >=
			break;
			
		case 4:
			fprintf(p,"JA %s\n\n", vector_tercetos[i].te1);			// condicion <=
			break;
			
		case 5:
			fprintf(p,"JNE %s\n\n", vector_tercetos[i].te1);			// condicion ==
			break;
			
		case 6:
			fprintf(p,"JE %s\n\n", vector_tercetos[i].te1);			// condicion !=
			break;
			
		case 7:
			fprintf(p,"JMP %s\n\n", vector_tercetos[i].te1);			// salto incondicional
			break;
		}
		
		
	}
}


int esOperacion(int indice)
{

	char auxTipo[100];
    strcpy(auxTipo,validaTipo(vector_tercetos[indice].te1));
    if(strcmp(vector_tercetos[indice].ope,"+")==0)
	return 1;	
	if(strcmp(vector_tercetos[indice].ope,"=")==0)
    return 5;
	
  

	if(strcmp(vector_tercetos[indice].ope,"PRINT")==0)
    {
        if (strstr(vector_tercetos[indice].te1,"_STR"))
        return 7;
		else
		return 6;										
	}
	if(strcmp(vector_tercetos[indice].ope,"READ")==0)
        return 8;
	
	return 0;
}


void convertirSalto(int indice)
{
    if(!strcmp(vector_tercetos[indice].ope,"BLT"))
        strcpy(vector_tercetos[indice].ope,"JNAE");
    if(!strcmp(vector_tercetos[indice].ope,"BLE"))
        strcpy(vector_tercetos[indice].ope,"JNA");   
    if(!strcmp(vector_tercetos[indice].ope,"BGT"))
        strcpy(vector_tercetos[indice].ope,"JA");
    if(!strcmp(vector_tercetos[indice].ope,"BGE"))
        strcpy(vector_tercetos[indice].ope,"JAE");
    if(!strcmp(vector_tercetos[indice].ope,"BEQ"))
        strcpy(vector_tercetos[indice].ope,"JE");
    if(!strcmp(vector_tercetos[indice].ope,"BNE"))
        strcpy(vector_tercetos[indice].ope,"JNE");
    if(!strcmp(vector_tercetos[indice].ope,"BI"))
        strcpy(vector_tercetos[indice].ope,"JMP");
}

int esSalto(int indice)
{	
	if(strcmp(vector_tercetos[indice].ope,"JNA")==0)		// >
	return 1;
	
	if(strcmp(vector_tercetos[indice].ope,"JAE")==0)		// <
	return 2;
	
	if(strcmp(vector_tercetos[indice].ope,"JNAE")==0)		// >=
	return 3;
	
	if(strcmp(vector_tercetos[indice].ope,"JA")==0)			// <=
	return 4;
	
	if(strcmp(vector_tercetos[indice].ope,"JNE")==0)		// ==
	return 5;
	
	if(strcmp(vector_tercetos[indice].ope,"JE")==0)			// !=
	return 6;
	
	if(strcmp(vector_tercetos[indice].ope,"JMP")==0)		// salto incondicional
	return 7;
	
	return 0;
}

char* validaTipo(char* id)
{
	int i;
	for(i=0;i<100;i++)
	{		
		if(strcmp(id,ts[i].lexema)==0)
		{	
			return ts[i].tipo;
		}
	}

	return id;
}

char* buscarValor(char * valor)
{
	int x;
	for(x=0;x<100;x++)
	{
		if(strcmp(ts[x].valor,valor)==0)  
		    return ts[x].lexema;  
	}
	return valor;
}