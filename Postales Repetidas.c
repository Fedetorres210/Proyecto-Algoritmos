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
		//printf("%d",postal.precioPostal);
		ayudante->siguiente= (Postales*)malloc(sizeof(Postales));
		ayudante->siguiente->postal=postal;
		ayudante->siguiente->siguiente=NULL;
	}
	
	return lista;
	
}

PostalesRepetidas * agregarListaRepetida(PostalesRepetidas* lista,struct Postal postal ,int repeticion){
	PostalesRepetidas*ayudante;
	if(lista==NULL){
		lista= (PostalesRepetidas*)malloc(sizeof(PostalesRepetidas));
		lista->postal=postal;
		lista->repetida=repeticion;
		lista->siguiente=NULL;
	}else{
		ayudante=lista;
		while(ayudante->siguiente!=NULL){
			ayudante=ayudante->siguiente;
		}
		ayudante->siguiente=(PostalesRepetidas*)malloc(sizeof(PostalesRepetidas));
		ayudante->siguiente->siguiente=NULL;
		ayudante->siguiente->postal=postal;
		printf("repetida es %d",repeticion);
		ayudante->siguiente->repetida=repeticion;
	}
	return lista;
}

//Postales * eliminarElemento(Postales * lista, char * codigo){
//	Postales * ayudante,*nuevaPostal;
//	ayudante=lista;
//	nuevaPostal=NULL;
//	while(ayudante!=NULL){
//		if(strcmp(ayudante->postal.codigoPostal,codigo)!=0){
//			nuevaPostal=agregarPostal(ayudante,ayudante->postal);
//	}
//		ayudante=ayudante->siguiente;
//		
//	}
//
//			
//	return nuevaPostal;
//}


int largo(Postales * lista){
	Postales * ayudante;
	ayudante=lista;
	int largo=0;
	while(ayudante!=NULL){
		largo++;
		ayudante=ayudante->siguiente;
	}
	return largo;
}
PostalesRepetidas * crearListaRepetidas(Postales * lista){
	PostalesRepetidas * ayudante, *nuevaLista;
	Postales * ayudante1,*temporal,*ayudante2;
	int len = largo(lista);
	printf("El largo es %d\n ",len);
	int contador=0;
	nuevaLista=NULL;
	ayudante2=lista;
	while(contador<len){
		if(ayudante2==NULL){
			break;
		}
		int iterador=0;
		printf("El contador es %d", contador);
		temporal=NULL;
		ayudante1=ayudante2;
		//printf("\n Entra al ayudante1");
		char * postal = ayudante1->postal.codigoPostal;
		printf("\n la postal es %s", postal);
		struct Postal postalStruct =ayudante1->postal;
		printf("\n El precio de la postal es %d", postalStruct.precioPostal);
		temporal=agregarPostal(temporal,ayudante1->postal);
		printf("\n El temporal es: %s",temporal->postal.codigoPostal);
		while(ayudante1->siguiente!=NULL){
			printf("Funciona el while de ayudante1");
			printf("\n El temporal es: %s",temporal->postal.codigoPostal);
//			int valor =strcmp(postal,ayudante1->siguiente->postal.codigoPostal);
//			printf("El valor es %d",valor);
			if (strcmp(postal,ayudante1->siguiente->postal.codigoPostal)!=0){
				//printf("\n No se encontro el codigo de la postal %s",ayudante1->siguiente->postal.codigoPostal);
				temporal=agregarPostal(temporal,ayudante1->siguiente->postal);
			}else{
				//printf(" \n EL iterador es  %d",iterador);
				iterador++;
			}
			//printf("Falla ?");
			ayudante1=ayudante1->siguiente;
			
		}
		printf(" \n EL iterador es  %d",iterador);
		nuevaLista = agregarListaRepetida(nuevaLista,postalStruct,iterador);
		printf("\n Datos nueva Lista\n ");
		printf("Repeticiones de %s , %d", nuevaLista->postal.codigoPostal,nuevaLista->repetida);
		ayudante2=temporal;
		ayudante2=ayudante2->siguiente;
		contador++;
	}
	return nuevaLista;
}
//		int repeticion=0;
//		temporal=ayudante1->siguiente;
//		while(temporal!=NULL){
//			if(ayudante1->postal.codigoPostal==temporal->postal.codigoPostal){
//				repeticion++;
//				}            
//			temporal=temporal->siguiente;                                                  
//		}
//		nuevaLista= agregarListaRepetida(nuevaLista, ayudante->postal,repeticion);
//		//ayudante= eliminarElemento(ayudante1,ayudante1->postal.codigoPostal);
//		ayudante=ayudante->siguiente;
//	}








int main(){
	Postales*lista=NULL;
	struct Postal postal ={ "FW3", "FRANCIA", "JULIAN", 40};
	lista=agregarPostal(lista,postal);
	struct Postal postal1 ={ "FW5", "FRANCIA", "JULIAN1", 40};
	lista=agregarPostal(lista,postal1);
	struct Postal postal2 ={ "FW5", "FRANCIA", "JULIAN1", 40};
	lista=agregarPostal(lista,postal2);
	struct Postal postal3 ={ "FW3", "FRANCIA", "JULIAN1", 40};
	lista=agregarPostal(lista,postal3);
	struct Postal postal4 ={ "FW6", "FRANCIA", "JULIAN1", 40};
	lista=agregarPostal(lista,postal4);
	PostalesRepetidas * lista1=NULL;
	lista1 =crearListaRepetidas(lista);
	PostalesRepetidas * ayudante;
	printf("Funciona");
	ayudante =lista1;
	while(ayudante!=NULL){
		//printf("********** POSTAL #%d***************** \n",numeroPostal);
	
		printf("\n Postal %s \n", ayudante->postal.codigoPostal);
	
		printf("Seccion o Equipo %s \n", ayudante->postal.seccionOEquipo);
	
		printf("Nombre del jugador, estadio o elemento: %s \n", ayudante->postal.nombrePostal);
					
		printf("Precio : %d \n \n", ayudante->postal.precioPostal);
		
		printf(" \n Numero de repetidas %d\n ",ayudante->repetida);
		ayudante=ayudante->siguiente;
		
	}
}

