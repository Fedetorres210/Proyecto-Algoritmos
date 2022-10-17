//Proyecto Algoritmos 

#include <stdio.h>
#include <stdlib.h>

struct Postal{
	char codigoPostal[6];
	char seccionOEquipo[99];
	char nombrePostal[99];
	int precioPostal;	
};

typedef struct nodo{
	struct Postal postal;
	struct nodo * siguiente;
}Postales;

Postales * agregarPostal(Postales * lista, struct Postal postal);
void consultarCatalogoPostales(Postales* lista);

int main(){
	Postales*lista=NULL;
	struct Postal postal ={ "FW3", "FRANCIA", "JULIAN", 40};
	lista=agregarPostal(lista,postal);
	printf("%s",lista->postal.codigoPostal);
	consultarCatalogoPostales(lista);
	
	
	return 0;

}
Postales * agregarPostal(Postales * lista, struct Postal postal){
	Postales *ayudante;
	
	if(lista==NULL){
		lista= (Postales*)malloc(sizeof(Postales));
		lista->postal=postal;
		lista->siguiente=NULL;
	}else{
		ayudante=lista;
		while(ayudante->siguiente!=NULL){
			ayudante=ayudante->siguiente;
		}
		ayudante->siguiente= (Postales*)malloc(sizeof(Postales));
		ayudante->siguiente->postal=postal;
		ayudante->siguiente->siguiente=NULL;
	}
	
	return lista;
	
}



void consultarCatalogoPostales(Postales* lista){
	Postales * ayudante;
	ayudante=lista;
	while(ayudante!=NULL){
		printf("\n ******************LA POSTAL: %s ************************* \n",ayudante->postal.codigoPostal);
		printf("SECCION O EQUIPO: %s \n",ayudante->postal.seccionOEquipo);
		printf("NOMBRE DE LA POSTAL: %s \n",ayudante->postal.nombrePostal);
		printf("PRECIO POSTAL %d \n",ayudante->postal.precioPostal);
		ayudante=ayudante->siguiente;
	}
}

