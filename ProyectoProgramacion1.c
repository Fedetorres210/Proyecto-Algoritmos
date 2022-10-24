//Proyecto Algoritmos 

#include <stdio.h>
#include <stdlib.h>

struct Registro{
	int precio;
	char codigo[99];
	int cedulaComprador;
};


typedef struct ventas{
	struct Registro registro;
	struct ventas * siguiente;
}Ventas;






Ventas * agregarVenta(Ventas * pila, struct Registro registro){
	Ventas * ayudante;
	ayudante= pila;
	if(pila==NULL){
		pila = (Ventas*)malloc(sizeof(Ventas));
		pila->registro=registro;
		pila->siguiente=NULL;
		
	}else{
		while(ayudante->siguiente!=NULL){
			ayudante=ayudante->siguiente;
		}
		ayudante->siguiente= (Ventas*)malloc(sizeof(Ventas));
		ayudante->siguiente->registro=registro;
		ayudante->siguiente->siguiente=NULL;
	}

	
	return lista;
	
}