// PROYECTO POSTALES VERSION 1
#include<stdio.h>
#include<stdlib.h>


typedef struct nodo {
	char codigo;
	char seleccion;
	char nombre;
	char tipo;
	struct nodo *siguiente;
}Postales;

void consultarPostal(Postales* lista);
Postales * agregarNuevaPostal(Postales * lista);

int main(){
	Postales * lista =NULL;
	lista=agregarNuevaPostal(lista);
	consultarPostal(lista);
}










Postales * agregarNuevaPostal(Postales * lista){
	Postales * postal;
	postal= (Postales*)malloc(sizeof(Postales));
	printf("Cual es el codigo de su postal? \n");
	scanf(" %s",postal->codigo);
	printf("codigo: %s \n", postal->codigo);
	printf("Ingrese el nombre o seccion proviniente de su postal: \n");
	scanf(" %s",postal->seleccion);
	printf("Ingrese el nombre de su postal: \n");
	scanf(" %s",postal->nombre);
	printf("Ingrese el tipo de postal:");
	scanf("  %s ", postal->tipo);
	postal->siguiente=NULL;
	if(lista==NULL){
		lista=postal;
	}
	return postal;
	
}









void consultarPostal(Postales* lista){
	Postales*ayudante;
	int numero=0;
	ayudante= lista;
	while(ayudante!=NULL){
		printf("El codigo de la postal %d es: %s \n ",numero, ayudante->codigo);
		printf("La seccion o nombre de la postal %d es: %s \n ",numero,ayudante->seleccion);
		printf("El nombre de la postal %d es: %s \n ",numero,ayudante->nombre);
		printf("El tipo de la postal %d es: %s \n ",numero,ayudante->tipo);
		
	}
}
