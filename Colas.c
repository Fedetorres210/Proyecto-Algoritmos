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
typedef struct nodoRepe{
	struct Postal postal;
	int repetida;
	struct nodoRepe * siguiente;
}PostalesRepetidas;

struct Coleccionista{
	int cedula;
	char nombreCompleto[99];
	char fechaNacimiento[99];
	char correoElectronico[99];
	char nivel[99];
	Postales * obtenidas;
	PostalesRepetidas * repetidas;
	Postales *faltantes;
};

typedef struct nodoCole{
	struct Coleccionista coleccionista;
	//Postales * listaPostales;
	struct nodoCole * siguiente;
	struct nodoCole *anterior;
}Coleccionistas;


struct Colita {
	char codigoPostal[99];
	char codigoPostalCambio[99];
	int cedula;
	char nivel[99];
	int precio;
	
};

typedef struct cola{
	struct Coleccionista colePendiente;
	struct Coleccionista coleRecibido;
	//struct Colita colaA;
	struct cola * siguiente;
	
}Cola;


Cola * agregarElemento(Cola *cola,struct Coleccionista colePendiente,struct Coleccionista coleRecibido);
Postales * agregarPostal(Postales * lista, struct Postal postal);




int main(){
	
	//creadorColaGeneral(Coleccionistas lista)
	
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
		printf("%d",postal.precioPostal);
		ayudante->siguiente= (Postales*)malloc(sizeof(Postales));
		ayudante->siguiente->postal=postal;
		ayudante->siguiente->siguiente=NULL;
	}
	
	return lista;
	
}

Cola * agregarElemento(Cola *cola,struct Coleccionista colePendiente,struct Coleccionista coleRecibido){
	Cola *ayudante,*temporal;
	if(cola==NULL){
		cola = (Cola*)malloc(sizeof(Cola));
		cola->colePendiente=colePendiente;
		cola->coleRecibido=coleRecibido;
		cola->siguiente=NULL;
	}else{
		ayudante=cola;
		while(ayudante!=NULL){
			ayudante=ayudante->siguiente;
			
		}
		ayudante->siguiente=(Cola*)malloc(sizeof(Cola));
		ayudante->colePendiente=colePendiente;
		ayudante->coleRecibido=coleRecibido;
		ayudante->siguiente->siguiente=NULL;
		
	}
	return cola;
}



Cola * colaDePrioridad(Cola * cola){
	Cola * ayudante,* colaZafiro=NULL, *colaOro=NULL, *colaPlata=NULL,*colaBronce=NULL;
	ayudante=cola;
	while(ayudante!=NULL){
		if(strcmp(ayudante->colaA.nivel,"zafiro")==0){
			colaZafiro=agregarElemento(colaZafiro,ayudante->colaA);
		}
		if(strcmp(ayudante->colaA.nivel,"oro")==0){
			colaOro=agregarElemento(colaOro,ayudante->colaA);
		}
		if(strcmp(ayudante->colaA.nivel,"plata")==0){
			colaPlata=agregarElemento(colaPlata,ayudante->colaA);
			
		}
		if(strcmp(ayudante->colaA.nivel,"bronce")==0){
			colaBronce=agregarElemento(colaBronce,ayudante->colaA);
		}
		ayudante=ayudante->siguiente;
			
	}
	colaPlata->siguiente=colaBronce;
	colaOro->siguiente=colaPlata;
	colaZafiro->siguiente=colaOro;
	return colaZafiro;
	
}

Cola* creadorColaGeneral(Coleccionistas * lista){
	Coleccionistas * ayudante;
	Cola * nuevaCola;
	int cedula;
	printf("\n Ingrese la cedula del coleccionista: \n ");
	scanf("%d",&cedula);
	ayudante=lista;
	while(ayudante!=NULL){
		if(ayudante->coleccionista.cedula==cedula){
			break;
		}
		ayudante=ayudante->siguiente;
	}
	if(ayudante==NULL){
		printf("No se encontro el coleccionista vuelva a intentar :D! \n ");
		return NULL;
	}
	struct Colita cola1;
	cola1.cedula=cedula;
	printf("%s",ayudante->coleccionista.nivel);
//	char * rango[99];
//	rango = ayudante->coleccionista.nivel;
//	cola1.nivel=NULL;
	int numero=0;
	while(numero==0){
		int opcion;
		printf(" \n Bienvenido al menu de reservacion de postales! \n ");
		printf("\nIngrese el codigo de la postal que desea reservar\n ");
		scanf("%s",&cola1.codigoPostal);
		printf("\n Digite 1 si desea realizar un intercambio de postales :D \n ");
		printf("Digite 2 si desea realizar una compra de postal \n ");
		printf("Digite 3 si desea salir del menu");
		scanf("%d",&opcion);
		if(opcion==1){
			cola1.precio=-1;
			char * postalRepetida[99];
			printf("Ingrese la postal que desea dar para intercambio");
			scanf("%s",&cola1.codigoPostalCambio);
			int valor;
			valor = ayudante->coleccionista.repetidas;
			if(verificadorPostalesRepetidas(valor,cola1.codigoPostalCambio)!=1){
				printf("No tienes suficientes postales repetidas para realizar el cambio");
				continue;
			}
			//cola1.codigoPostalCambio=postalRepetida;
			//char  rango[99]= ;
			nuevaCola = agregarElemento(nuevaCola,cola1);
			
		}
		if(opcion==2){
			int precio;
			printf("\n Ingrese el precio por el que desea conseguir la postal\n ");
			scanf("%d",cola1.precio);
			nuevaCola = agregarElemento(nuevaCola,cola1);
			
		}
		if(opcion==3){
			printf("gracias por utilizar el sistema de reserva de postales :D");
			break;
		}
		else{
			printf("Ingrese una opcion valida");
		}
	}
	
	nuevaCola =colaDePrioridad(nuevaCola);
	
	
	return nuevaCola;
	
	
}




int verificadorPostalesRepetidas(PostalesRepetidas *lista,char codigoPostal[]){
	PostalesRepetidas * ayudante;
	ayudante=lista;
	while(ayudante!=NULL){
		if(strcmp(ayudante->postal.codigoPostal,codigoPostal)==0){
			if(ayudante->repetida>=1){
				return 1;
			}
		}
		ayudante=ayudante->siguiente;
	}
	return 0;
}