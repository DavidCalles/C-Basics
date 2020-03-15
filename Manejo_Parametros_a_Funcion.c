/**************************************************************************************
*	 				  ____ ___ ____  ____  ____   ___  
*					|  _ \_ _/ ___||  _ \|  _ \ / _ \ 
*					| | | | |\___ \| |_) | |_) | | | |
*					| |_| | | ___) |  __/|  _ <| |_| |
*					|____/___|____/|_|   |_| \_\\___/ 
*
*	Definición: Código para observar diferencia entre paso de variables por valor
*				y por referencia.
*
*	Archivos:	Manejo_Parametros_a_Funcion.c
*
*	Uso:		El archivo se ejecuta solo. La idea es visualizar lo que sucede
*				pasando parámetros por referencia vs por valor.
*	
*	Revisión:	Primera implementación		David Calles	15/03/2020
*
**************************************************************************************/

/*DEFAULT LIBRARIES INCLUSIONS*/
#include <stdlib.h>
#include <stdio.h>

/*FUNCTIONS SIGNATURES*/
int Parametros_por_valor		(int );
int Parametros_por_referencia	(int *);

/*MAIN FUNCTION*/
int main () {
	int a = 5, b = 4, c, d;
	
	/*Functions calls*/
	c = Parametros_por_valor( a );
	d = Parametros_por_referencia( &b );
	
	/*Printing results*/
	printf("%d \t %d \n", c, d);
	printf("Parametros_por_valor: %d \n", a);
	printf("Parametros_por_referencia: %d \n", b);
	
	return 0;
}/*main*/

/*FUNCTIONS DEVELOPMENTS*/

int Parametros_por_valor(int x){
	x = x*100 ;		
	return 1;
}/*Parametros_por_valor*/

int Parametros_por_referencia(int *x){
	(*x) = (*x) * 100;
	return 1;
}/*Parametros_por_referencia*/
