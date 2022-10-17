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
Postales * modificarPostal(Postales * lista);
Postales * accionDePostales(Postales*lista);

int main(){
	Postales*lista=NULL;
	struct Postal postal ={ "FW3", "FRANCIA", "JULIAN", 40};
	lista=agregarPostal(lista,postal);
	struct Postal postal1 ={ "FW5", "FRANCIA", "JULIAN1", 40};
	lista=agregarPostal(lista,postal1);
//	printf("%s",lista->postal.codigoPostal);
//	consultarCatalogoPostales(lista);
	accionDePostales(lista);
	
	
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



//void consultarCatalogoPostales(Postales* lista){
//	Postales * ayudante;
//	ayudante=lista;
//	while(ayudante!=NULL){
//		printf("\n ******************LA POSTAL: %s ************************* \n",ayudante->postal.codigoPostal);
//		printf("SECCION O EQUIPO: %s \n",ayudante->postal.seccionOEquipo);
//		printf("NOMBRE DE LA POSTAL: %s \n",ayudante->postal.nombrePostal);
//		printf("PRECIO POSTAL %d \n",ayudante->postal.precioPostal);
//		ayudante=ayudante->siguiente;
//	}
//}


Postales * modificarPostal(Postales * lista)
{
	Postales * ayudante;
	char codigo[4];
	char nombreEquipo[30];
	char nombreTipoPostal[30];
	// (nombre del jugador, estadio o otro)
	char clase[6];
	 //(Base, Bronce, Plata, Oro)
	int precio;
	
	printf("Ingrese el código de la postal que desea modificar: \n");
	scanf(" %s", &codigo);
	
	for(ayudante =  lista; ayudante != NULL; ayudante = ayudante -> siguiente)

	{
		if ( strcmp(ayudante->postal.codigoPostal, codigo) == 0)
		{
			printf("\n Ingrese el nombre de la postal: ");
			scanf("%s", &ayudante->postal.nombrePostal);
			
			printf("\n Ingrese el nuevo nombre del equipo o seccion de la postal: ");
			scanf("%s", &ayudante->postal.seccionOEquipo);
			
			printf("\n Ingrese el nuevo precio(si es que se va a vender): ");
			scanf("%d", &ayudante->postal.precioPostal);
			
			printf("Se  modificó correctamente la información de la postal %s \n", codigo);
			
			break;
		}
	}
	if (ayudante == NULL)
	{
		printf("postal no encontrada %s", codigo);
	}
	return lista;
}


//2. eliminar postal

Postales * eliminarPostal(Postales* lista)
{
	Postales * nuevaPostal;
	Postales * ayudante;
	
	char codigo[7];

	printf("\n Ingrese el codigo de la postal que desea eliminar : \n");
	scanf("%s", &codigo);
	printf("%s",codigo);
	
	ayudante=lista;
	printf("\n %s",ayudante->postal.codigoPostal);
	nuevaPostal==NULL;
	while(ayudante!=NULL){
		printf("Funciona el while");
		if(strcmp(ayudante->postal.codigoPostal, codigo) == 0)
		{
			ayudante=ayudante->siguiente;
			continue;
		}
		nuevaPostal= agregarPostal(nuevaPostal,ayudante->postal);
		printf("Funciona el while");
		ayudante=ayudante->siguiente;
	}
	return nuevaPostal;
	
}


//3. consultar cátalogo

void consultarCatalogoPostales(Postales* lista){
	char codigo[4];
	int accion = 0;
	if (lista==NULL){
		printf("La lista esta vacia agregue elementos porfavor!");
		return lista;
	}
	
	while (accion != 3){
			int consulta;
			printf("\n Ingrese:");
			printf("\n 1.Para mostrar el catalogo completo de postales");
			printf("\n 2.Para consultar la informacion especifica de una postal");
			printf("\n 3.Para Terminar \n ");
			scanf("%d", &consulta);
		if (consulta==1){
			Postales *ayudante;
			ayudante=lista;
			int postal=1;

			while(ayudante!=NULL){
				printf("********** POSTAL #%d***************** \n",postal);

				printf("Postal %s \n", ayudante->postal.codigoPostal);

				printf("Seccion o Equipo %s \n", ayudante->postal.seccionOEquipo);

				printf("Nombre del jugador, estadio o elemento: %s \n", ayudante->postal.nombrePostal);
				
				printf("Precio : %d \n \n", ayudante->postal.precioPostal);
				ayudante=ayudante->siguiente;
				postal++;
			}
		}
		if (consulta==2){
			char postal[99];
			printf("\n Ingrese el codigo de la postal que desea consultar: ");
			scanf("%s",postal);
			//printf("%s",postal);
			Postales * ayudante;
			
			for (ayudante = lista; ayudante != NULL; ayudante = ayudante ->siguiente)
			{
				int numeroPostal=1;
				if (strcmp(ayudante->postal.codigoPostal, postal) == 0)
				{
					printf("********** POSTAL #%d***************** \n",numeroPostal);
	
					printf("Postal %s \n", ayudante->postal.codigoPostal);
	
					printf("Seccion o Equipo %s \n", ayudante->postal.seccionOEquipo);
	
					printf("Nombre del jugador, estadio o elemento: %s \n", ayudante->postal.nombrePostal);
					
					printf("Precio : %d \n \n", ayudante->postal.precioPostal);

					break;
				}
				numeroPostal++;
			}	
			if (ayudante == NULL)
			{
				printf("Postal no encontrada %s", postal);
			}
		}
		if (consulta==3){
			printf("Gracias por revisar el catalogod de postales!");
			break;
		}
	}
	
}

Postales * accionDePostales(Postales*lista){
	int verdadero=1;
	while(verdadero==1){
		int opcion;
		printf(" \n Digite 1 si desea agregar postales");
		printf("\n Digite 2 si desea consultar postales");
		printf("\n Digite 3 si desea modificar una postal");
		printf("\n Digite 4 si desea eliminar una postal");
		printf("\n Digite 5 si desea salir del sistema de postales"); 
		scanf("%d",&opcion);
		printf("%d", opcion);
		if (opcion==1){
			char codigo[6];
			char nombrePostal[99];
			char seccionPostal[99];
			int precio;
			struct Postal postal;
			printf(" \n Ingrese el codigo de la postal: ");
			scanf("%s",&postal.codigoPostal);
			//printf("%s",postal.codigoPostal);
			
			printf("\n Ingrese el nombre de la postal: ");
			scanf(" %s", &postal.nombrePostal);
			//printf("%s",nombrePostal);
			
			printf("\n Ingrese la seccion o equipo de la postal:  ");
			scanf(" %s",&postal.seccionOEquipo);
			//printf("%s",seccionPostal);
			
			printf("\n Ingrese el precio de la postal");
			scanf("%d",&postal.precioPostal);
			//printf("%d",precio);
			
//			printf(" \n El codigo es %s \n la seccion es  %s", postal.codigoPostal,postal.seccionOEquipo);
			
			lista =agregarPostal(lista,postal);
		}
		
		if(opcion==2){
			printf("\n ********** SISTEMA DE CONSULTA DE CATALOGO DE POSTALES*********************\n ");
			consultarCatalogoPostales(lista);
			
		}
		if (opcion==3){
			printf("\n ********** SISTEMA DE MODIFICACION DE POSTALES *********************\n ");
			lista = modificarPostal(lista);
		}
		if(opcion==4){
			printf("\n ********** SISTEMA DE CONSULTA DE ELIMINACION DE POSTALES *********************\n ");
			lista = eliminarPostal(lista);
		}
		if(opcion==5){
			printf("GRACIAS POR UTILIZAR EL SISTEMA DE POSTALES!");
			break;
		}
		else{
			printf("PORFAVOR INGRESE UN VALOR VALIDO");
		}
		
	}

}


