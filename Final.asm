
include macros2.asm		 ;incluye macros2
include number.asm		 ;incluye el asm para impresion de numeros

.model large
.386
.stack 200h
.LEN_LEXEMA equ 32

.DATA

;Declaracion de variables y constantes.

@msg_int db "Ingrese un entero:", '$'
_STR0  DB  "Ingrese un valor pivot mayor o igual a 1: ",'$'
pivot  DD ?
resul  DD ?
_1  DD  1.00
_STR4  DB  "El valor de pivot debe ser >= 1",'$'
_STR5  DB  "La lista está vacía",'$'
_STR6  DB  "La lista tiene menos elementos que el indicado",'$'
_STR7  DB  "Elementos impares no encontrados",'$'
_STR8  DB  "No existen suficientes elementos impares para el cálculo",'$'
_2  DD  2.00
_21  DD  21.00
@aux22  DD ?
@aux24  DD ?
_7  DD  7.00
@aux28  DD ?
@aux30  DD ?
_44  DD  44.00
_40  DD  40.00
_33  DD  33.00
@aux34  DD ?
@aux36  DD ?
_5  DD  5.00
@aux40  DD ?
@aux42  DD ?
_4  DD  4.00
_STR25  DB  "El resultado es: ",'$'
@auxResultado  DD ?
@auxSumas  DD ?

aux1 dd ?; auxiliar para realizar operaciones.

.CODE
START:
mov AX,@DATA ;Copiar en AX (Registro Acumulador) la Direccion del Segmento de Datos
mov DS,AX ;Copiar en DS (Segmento de Datos) el registro AX
MOV  ES,AX   ;Copiar en ES (Segmento Extra) el registro AX

etiqueta_0:
DisplayString _STR0,1
newLine

DisplayString @msg_int 
int 21h 
newLine 1
GetFloat pivot 
fld pivot
fld _1
fxch
fcomp
fstsw ax
sahf
JAE etiqueta_6

DisplayString _STR4,1
newLine

JMP etiqueta_END

etiqueta_6:
fld _1
fld _7
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_10

DisplayString _STR5,1
newLine

JMP etiqueta_END

etiqueta_10:
fld pivot
fld _7
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_14

DisplayString _STR6,1
newLine

JMP etiqueta_END

etiqueta_14:
fld _1
fld _4
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_18

DisplayString _STR7,1
newLine

JMP etiqueta_END

etiqueta_18:
fld pivot
fld _4
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_22

DisplayString _STR8,1
newLine

JMP etiqueta_END

etiqueta_22:
fld _21
fstp @auxResultado
fld @auxSumas
fld _1
fadd
fstp @aux24
fld @aux24
fstp @auxSumas
fld pivot
fld @auxSumas
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_44

fld @auxResultado
fld _7
fadd
fstp @aux28
fld @aux28
fstp @auxResultado
fld @auxSumas
fld _1
fadd
fstp @aux30
fld @aux30
fstp @auxSumas
fld pivot
fld @auxSumas
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_44

fld @auxResultado
fld _33
fadd
fstp @aux34
fld @aux34
fstp @auxResultado
fld @auxSumas
fld _1
fadd
fstp @aux36
fld @aux36
fstp @auxSumas
fld pivot
fld @auxSumas
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_44

fld @auxResultado
fld _5
fadd
fstp @aux40
fld @aux40
fstp @auxResultado
fld @auxSumas
fld _1
fadd
fstp @aux42
fld @aux42
fstp @auxSumas
etiqueta_44:
fld @auxResultado
fstp resul
DisplayString _STR25,1
newLine

DisplayFloat resul,1
newLine


Etiqueta_END:

MOV AH, 1
INT 21h
MOV AX, 4C00h
INT 21h

END START
