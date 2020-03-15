/**************************************************************************************
*	 				  ____ ___ ____  ____  ____   ___  
*					|  _ \_ _/ ___||  _ \|  _ \ / _ \ 
*					| | | | |\___ \| |_) | |_) | | | |
*					| |_| | | ___) |  __/|  _ <| |_| |
*					|____/___|____/|_|   |_| \_\\___/ 
*
*	Definición: Código de lectura de un "netlist" con formato PSPICE desde un 
*				archivo .txt con separación por espacios y guardado de componentes 
*				en estructuras  para fines didácticos del primer proyecto de DISPRO.
*
*	Archivos:	Manejo_Archivos.c, prueba.txt
*
*	Uso:		El archivo "prueba.txt" debe estar en la misma carpeta que 
*				este documento. Y el número de componentes a leer debe ser 
*				indicado manualmente en la definición "NUM_COMPONENTES" para este
*				código
*	
*	A mejorar:	Todo el proceso se encuentra explícito en el main.
*
*	Revisión:	Primera implementación		David Calles	15/03/2020
*
**************************************************************************************/

/*LIBRARIES INCLUDED*/
#include <stdlib.h>
#include <stdio.h>

/*GENERAL PURPOSE DEFINITIONS*/
#define NUM_COMPONENTES 6
#define MAX_NAME_SIZE 5

/*FUNCTIONS SIGNATURES*/


/*--------------------------------MAIN FUNCTION*/
int main () {
	
	FILE *text = NULL;					// APUNTADOR AL ARCHIVO		
	
	text = fopen("prueba.txt", "r");	// APERTURA DEL ARCHIVO COMO DE LECTURA
	
	if(text == NULL ) {					// REVISION DE APERTURA DEL ARCHIVO
     printf("No fue posible abrir el archivo\n");
     return 0;
   }
	
	/*---------------------------VARIABLES INDIVIDUALES PARA DATOS A OBTENER*/
	int i=0;
	char letra;
	char nombre[MAX_NAME_SIZE] = "";
	int nodo1, nodo2;
	double valor;
	char tipo_buff[15];
	
	/*---------------------------DEFINICION DE NUEVOS TIPOS DE DATOS */
	
	typedef enum { /*TIPOS DE COMPONENTES ADMITIDOS*/
		RESISTENCIA, INDUCTOR, CAPACITOR, FUENTE_I, V_FUENTE
	}TYPE;
	TYPE tipo;
	
	typedef struct { /*ESTRUCTURA POR CADA COMPONENTE*/
		char name[MAX_NAME_SIZE];
		int nodo_p, nodo_n;
		double value;
		TYPE type;
	}COMPONENT;
	
	COMPONENT netlist1[NUM_COMPONENTES]; /*CIRCUITO A ANALIZAR*/
	
	/*----------------------------RECORRITO POR COMPONENTE INDIVIDUAL (FILA)*/
	int fila;
	for(fila = 0 ; fila < (int)NUM_COMPONENTES; fila++){
	
		/*PASO 1: OBTENER 1 NOMBRE*/
		fscanf(text, "%s", &nombre);		
		printf("%s \t", nombre); // Imprimir nombre

		/*PASO 2: OBTENER 1er NODO*/
		fscanf(text, "%d", &nodo1);
		printf("%d \t", nodo1);
		
		/*PASO 3: OBTENER 2do NODO*/
		fscanf(text, "%d", &nodo2);
		printf("%d \t", nodo2);
		
		/*PASO 4: OBTENER VALOR*/
		fscanf(text, "%lf", &valor);
		printf("%e \t", valor);
		
		/*PASO 5: OBTENER TIPO ELEMENTO*/
		fscanf(text, "%s", &tipo_buff);
		printf("%s", tipo_buff);
		
		fscanf(text, "\n", &letra); // Cambio de línea del cursor
		
		switch(tipo_buff[0]){		// Paso de texto "RESISTENCIA" a valor en enum
									// a partir de la primera letra
			case 'R':
				tipo = RESISTENCIA;
			break;
			case 'I':
				tipo = INDUCTOR;
			break;
			case 'C':
				tipo = CAPACITOR;
			break;
			case 'F':
				tipo = FUENTE_I;
			break;
			case 'V':
				tipo = V_FUENTE;
			break;		
		}/*SWITCH CASE ENUM*/
		printf("%d \n", tipo);
		
		/*PASO 6: GUARDADO EN ESTRUCTURAS*/
		int k=0;	
		for(k=0; k<MAX_NAME_SIZE; k++)				//GUARDADO DE NOMBRE
			netlist1[fila].name[k] = nombre[k];					
		netlist1[fila].nodo_p 	= nodo1;			//GUARDADO DE NODOS
		netlist1[fila].nodo_n 	= nodo2;	
		netlist1[fila].value 	= valor;			//GUARDADO DE VALOR
		netlist1[fila].type		= tipo;				//GUARDADO DE TIPO DE COMPONENTE
		
	}/*FOR COMPONENTES*/
	
		
	fclose(text); // Cerrar archivo
	
	return 0;
}/*main*/

