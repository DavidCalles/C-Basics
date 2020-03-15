/**************************************************************************************
*	 				  ____ ___ ____  ____  ____   ___  
*					|  _ \_ _/ ___||  _ \|  _ \ / _ \ 
*					| | | | |\___ \| |_) | |_) | | | |
*					| |_| | | ___) |  __/|  _ <| |_| |
*					|____/___|____/|_|   |_| \_\\___/ 
*
*	Definición: Código de manejo básico/intermedio de arreglos de 1D y 2D con paso
*				de parámetros por referencia. Se realizan acciones varias
*				a los arreglos con fines didácticos.
*
*	Archivos:	Manejo_Arreglos.c
*
*	Uso:		El archivo se ejecuta solo, se pueden cambiar los tamaños de
*				los vectores y matrices con "SIZE", "ROWS" y "COLS".
*	
*	Revisión:	Primera implementación		David Calles	15/03/2020
*
**************************************************************************************/

/*DEFAULT LIBRARIES INCLUSIONS*/
#include <stdlib.h>
#include <stdio.h>

/*GENERAL USE DEFINES*/
#define SIZE 5			// TAMAÑO DE VECTOR
#define ROWS 3			// FILAS DE MATRIZ
#define COLS 3			// COLUMNAS DE MATRIZ

/*FUNCTIONS SIGNATURES*/
int Manejo_arreglo1		(int *);		// MANEJO DE VECTOR CON SUBÍNDICES
int Manejo_arreglo2		(int *);		// MANEJO DE VECTOR CON APUNTADORES
int Manejo_matriz		(int [][COLS]); // MANEJO DE MATRIZ 2D CON SUBÍNDICES
int Manejo_matriz_apunt	(int [][COLS]);	// MANEJO DE MATRIZ 2D CON APUNTADORES

void Print_array_1D	(int *, int);				// IMPRESIÓN BÁSICA DE VECTOR
void Print_array_2D (int [][COLS], int, int);	// IMPRESIÓN BÁSICA DE MATRIZ 2D

/*MAIN FUNCTION*/
int main () {
	
	/*------------1D ARRAY TESTS------------------------------*/
	
	/*VARIABLES DEFINITIONS*/
	int array1[SIZE], array2[SIZE];
	int OK1, OK2;
	/*FUNCION CALLS*/
	OK1 = Manejo_arreglo1 (array1);
	OK2 = Manejo_arreglo2 (&array2[0]);
	/*1D ARRAY PRINTS*/
	printf ("%d \t %d \n", OK1, OK2);
	printf ("ARRAY1: \t");
	Print_array_1D	(array1, (int)SIZE);
	printf ("ARRAY2: \t");
	Print_array_1D	(array2, (int)SIZE);
	
	/*------------2D ARRAY TESTS------------------------------*/
	
	/*VARIABLES DEFINITIONS*/
	int array3[ROWS][COLS], array4[ROWS][COLS];
	int OK3, OK4;
	/*FUNCION CALLS*/
	OK3 = Manejo_matriz (array3);
	OK4 = Manejo_matriz_apunt (array4);
	/*2D ARRAY PRINTS*/
	printf ("\n %d \t %d \n", OK3, OK4);
	printf ("\n ARRAY3:");
	Print_array_2D	(array3, (int)ROWS, (int)COLS);
	printf ("\n ARRAY4:");
	Print_array_2D	(array4, (int)ROWS, (int)COLS);
	
	return 0;
	
}/*main*/

/*FUNCTIONS DEVELOPMENTS*/

/*--------------------------------------------------------------------*/
/* ----------------------------VECTORS -------------------------------*/
/*--------------------------------------------------------------------*/

int Manejo_arreglo1 (int *vect){
	int i;
	for(i=0; i<SIZE; i++){
		vect[i] = rand() % 10; // Número aleatorio entre 0-9
	}	
	return 1;
}/*Manejo_arreglo1*/

int Manejo_arreglo2 (int *vect){
	int *i;
	for(i=&vect[0]; i<= &vect[SIZE-1]; i++){
		(*i) = ((rand() % 100) + 100); // Número aleatorio entre 10-19
	}	
	return 1;
}/*Manejo_arreglo2*/

void Print_array_1D (int *vect, int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d \t", vect[i]);
	}
	printf("\n");
}/*Print_array_1D*/

/*--------------------------------------------------------------------*/
/* ----------------------------MATRIXES ------------------------------*/
/*--------------------------------------------------------------------*/

int Manejo_matriz (int mtx[][COLS]){
	int i,j;
	for (i=0 ; i<ROWS ; i++){
		for(j=0 ; j<COLS ; j++){
			mtx[i][j] = (i*10)+j;
		}
	}	
	return 1;
}/*Manejo_matriz*/

int Manejo_matriz_apunt (int mtx[][COLS]){
	int *i;
	for (i=&mtx[0][0] ; i<= &mtx[ROWS-1][COLS-1]; i++){
		(*i) = (long long)i;
	}	
	return 1;
}/*Manejo_matriz_apunt*/

void Print_array_2D (int mtx[][COLS], int n, int m){
	int i,j;
	for (i=0 ; i<n ; i++){
		printf("\n");
		for(j=0 ; j<m ; j++){
			printf("%d \t", mtx[i][j]);
		}
	}
	printf("\n");
}/*Print_array_2D*/

