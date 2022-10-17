//COLECCIONISTAS PARTE

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
	char rango[99];
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
	//Juanito tiene tantas postales :D
//	PostalesRepetidas * listaDePostales;
//	Coleccionistas * lista;
	struct Colita colaA;
	struct cola * siguiente;
	
}Cola;

Postales * agregarPostal(Postales * lista, struct Postal postal);
void consultarCatalogoPostales(Postales* lista);
Postales * modificarPostal(Postales * lista);
Postales * accionDePostales(Postales*lista);
Coleccionistas * agregarColeccionista(Coleccionistas * lista, struct Coleccionista coleccionista);
void consultarCatalogoColeccionistas(Coleccionistas* lista);
Coleccionistas * modificarColeccionistas(Coleccionistas *lista);
Coleccionistas * albumPanini2022(Coleccionistas *lista, Postales * postales);
Coleccionistas * agregarListaColeccionista(Coleccionistas * lista);
Coleccionistas * opcionesColeccionistas(Coleccionistas *lista);

PostalesRepetidas * agregarListaRepetida(PostalesRepetidas* lista,struct Postal postal ,int repeticion);
int largo(Postales * lista);
int largoRepetidas(PostalesRepetidas * lista);
PostalesRepetidas * crearListaRepetidas(Postales * lista);
PostalesRepetidas * postalesRepetidas(Coleccionistas *lista,int cedula,Postales *listaPostales);

Postales * crearListaFaltantes(Postales * lista,PostalesRepetidas * lista1);
Postales * postalesFaltantes(Postales *listaTotal, Coleccionistas* lista, PostalesRepetidas * listaPostalesRepetidas, int cedula);
Coleccionistas * menuRepetidasyFaltantes(Coleccionistas * lista, Postales *postales);
Coleccionistas * eliminadorinformacion(Coleccionistas *lista);

Cola * agregarElemento(Cola *cola,struct Colita cola1);

Cola * agregarElemento(Cola *cola,struct Colita cola1);

Cola* creadorColaGeneral(Coleccionistas * lista);


int main(){
	Coleccionistas*lista=NULL;
	Postales *postales=NULL;
	struct Coleccionista coleccionista ={ 123456,"JUAN", "2/04/22", "juan@hotmail.com", "BRONZE"};
	lista=agregarColeccionista(lista,coleccionista);
//	lista=modificarColeccionistas(lista);
//	consultarCatalogoColeccionistas(lista);
	lista = albumPanini2022(lista,postales);
	creadorColaGeneral(lista);
	//lista = opcionesColeccionistas(lista);
	consultarCatalogoColeccionistas(lista);
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
		printf("%d",postal.precioPostal);
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
	return lista;

}
Coleccionistas * agregarColeccionista(Coleccionistas * lista, struct Coleccionista coleccionista){
	Coleccionistas *ayudante,*nuevo;
	
	if(lista==NULL){
		lista =(Coleccionistas*)malloc(sizeof(Coleccionistas));
		lista->coleccionista=coleccionista;
		lista->siguiente=NULL;
		lista->anterior=NULL;
	}else{
		ayudante=lista;
		while(ayudante->siguiente!=NULL){
			ayudante=ayudante->siguiente;
		}
		ayudante->siguiente=(Coleccionistas*)malloc(sizeof(Coleccionistas));
		ayudante->siguiente->coleccionista=coleccionista;
		ayudante->siguiente->siguiente=NULL;
		ayudante->siguiente->anterior=ayudante;
	}
	
	return lista;
	
}


void consultarCatalogoColeccionistas(Coleccionistas* lista){
//	if(lista==NULL){
//		printf("La lista esta vacia porfavor ingrese datos");
//		return lista;
//	}
	Coleccionistas * ayudante;
	int consulta,cedula;
	ayudante=lista;
	printf("Si desea hacer una consulta general digite 1 en caso de hacer una consulta especifica digite 0: ");
	scanf("%d",&consulta);
	if (consulta==0){
		printf("Digite el numero de cedula del coleccionista a verificar");
		scanf("%d",&cedula);
		while(ayudante!=NULL){
			if(ayudante->coleccionista.cedula == cedula){
				printf("\n ******************EL COLECCIONISTA ENCONTRADO *************** \n");
				printf("La cedula del coleccionista es: %d \n",ayudante->coleccionista.cedula);
				printf("NOMBRE DEL COLECCIONISTA: %s \n",ayudante->coleccionista.nombreCompleto);
				printf("FECHA DE NACIMIENTO DEL COLECCIONISTA: %s \n",ayudante->coleccionista.fechaNacimiento);
				printf("El correo electronico del coleccionista: %s \n",ayudante->coleccionista.correoElectronico);
				printf("El rango del coleccionista: %s \n",ayudante->coleccionista.rango);
				break;
			}
			ayudante=ayudante->siguiente;
		}
		
	}if(consulta==1){
		int numero=1;
		while(ayudante!=NULL){
			printf("\n ******************EL COLECCIONISTA  #%d *************** \n",numero);
			printf("La cedula del coleccionista es: %d \n",ayudante->coleccionista.cedula);
			printf("NOMBRE DEL COLECCIONISTA: %s \n",ayudante->coleccionista.nombreCompleto);
			printf("FECHA DE NACIMIENTO DEL COLECCIONISTA: %s \n",ayudante->coleccionista.fechaNacimiento);
			printf("El correo electronico del coleccionista: %s \n",ayudante->coleccionista.correoElectronico);
			printf("El rango del coleccionista: %s \n",ayudante->coleccionista.rango);
			numero++;
			ayudante=ayudante->siguiente;
	
		}
	}else{
		printf("El valor ingresado no es correcto");
	}
	
}



Coleccionistas * modificarColeccionistas(Coleccionistas *lista){
	Coleccionistas *ayudante;
	int cedula;
	if(lista==NULL){
		printf("La lista esta vacia, agregue elementos para editarlos :D");
		return lista;
	}else{
		printf("Indique el numero de cedula del coleccionista que desea modificar");
		scanf("%d",&cedula);
		ayudante=lista;
		while(ayudante!=NULL){
			
			if(ayudante->coleccionista.cedula==cedula){
				int item=0;
				
				while(item==0){
					int opcion;
					char valor[99];
					printf(" \n Digite 1 si quiere modificar el nombre del coleccionista \n Digite 2 si desea modificar la fecha de nacimiento del coleccionista");
					printf("\n Digite 3 si quiere modificar el correo electronico del coleccionista \n digite 4 si desea modificar el rango del coleccionista\n");
					printf("\n Digite 5 si desea salir del menu de cambios de coleccionista :D");
					printf("\n Ingrese la opcion que desea: ");
					scanf("%d",&opcion);
					if(opcion==1){
						
						printf("Ingrese el nuevo nombre del coleccionista: ");
						scanf("%s",&ayudante->coleccionista.nombreCompleto);
						//printf("%s",ayudante->coleccionista.nombreCompleto);
					}                                       
					if(opcion==2){
						printf("Ingrese la nueva fecha de nacimiento del coleccionista: ");
						scanf("%s",&ayudante->coleccionista.fechaNacimiento);
						
					}
					if(opcion==3){
						printf("Ingrese el nuevo correo electronico del coleccionista: ");
						scanf("%s",&ayudante->coleccionista.correoElectronico);
					}
					if(opcion==4){
						printf("Ingrese el nuevo rango del coleccionista: ");
						scanf("%s",&ayudante->coleccionista.rango);
					}
					if(opcion==5){
						printf("Nos vemos pronto! ");
						break;
						
					}
					
		
				}
			}
			
			ayudante=ayudante->siguiente;
		}
		
	}
	return lista;
	
	
	
}

Coleccionistas * opcionesColeccionistas(Coleccionistas *lista){
	int valor=1;
	while(valor==1){
		int opcion;
		printf("\n Digite 1 si desea agregar un coleccionista\n ");
		printf("Digite 2 si desea modificar un coleccionista \n");
		printf("Digite 3 si desea consultar la lista de coleccionistas \n");
		scanf("%d",&opcion);
		if (opcion==1){
			struct Coleccionista coleccionista;
			printf("\n Ingrese el numero de  cedula del coleccionista");
			scanf("%d",&coleccionista.cedula);
			printf("%d",coleccionista.cedula);
			printf("\n Ingrese el nombre completo del coleccionista:");
			scanf(" %s",&coleccionista.nombreCompleto);
			printf("\n Ingrese el correo electronico del coleccionista");
			scanf(" %s",&coleccionista.correoElectronico);
			printf("Ingrese la fecha de nacimiento del coleccionista");
			scanf(" %s",&coleccionista.fechaNacimiento);
			printf("\n Ingrese el rango que tiene el coleccionista:");
			scanf(" %s",&coleccionista.rango);
			coleccionista.obtenidas=NULL;
			
			lista = agregarColeccionista(lista, coleccionista);
			
		}
		if(opcion==2){
			lista = modificarColeccionistas(lista);	
		}
		if(opcion==3){
			printf("Consultar las listas de los coleccionistas");
			consultarCatalogoColeccionistas(lista);
		}
		if(opcion==4){
			printf("Gracias por consultar el sistema de coleccionistas");
			break;
		}
		else{
			printf("Digite un numero valido");
		}
	}
	return lista;
}

Coleccionistas * albumPanini2022(Coleccionistas *lista,Postales * postales){
	int valor=1;
	while(valor==1){
		int opcion;
		printf("\n Digite 1 si desea ingresar al sistema de coleccionista\n");
//		printf("Digite 2 si desea modificar la informacion del coleccionista\n ");
		printf("Digite 2 si desea elminar la informacion de algun coleccionista\n");
//		printf("Digite 4 si desea ver la informacion de los coleccionistas\n");
		printf("Digite 3 si desea agregar una lista de postales a un coleccionista\n");
		printf("Digite 4 si desea ver la lista de repetidas y faltantes del coleccionista\n ");
		printf("Digite 5 si desea ingresar al menu de postales generales \n");
		printf("Digite 6 si desea salir del sistema");
		scanf("%d",&opcion);
		if(opcion==1){
			printf("***********Ha elegido Ingresar al sistema de coleccionista**************\n ");
			lista=opcionesColeccionistas(lista);
			
		}
		if (opcion==2){
			printf("Ha elegido Eliminar la informacion de algun coleccionista\n ");
			lista= eliminadorinformacion(lista);
		}
		if (opcion==3){
			printf("Ha escogido agregar una lista de postales a un coleccionista\n ");
			lista = agregarListaColeccionista(lista);
		}
		if(opcion==4){
			printf("\n Ha escogido revisar la lista de repetidas y las faltantes del coleccionista\n ");
			lista =  menuRepetidasyFaltantes(lista, postales);
		
		}
		if (opcion==5){
			printf("Ha decidido ingresar al menu de postales Generales\n ");
			postales = accionDePostales(postales);
			
		}
		if(opcion==6){
			printf("Gracias por utilizar el sistema de Album de Panini 2022! \n");
			break;
		}
		else{
			printf("Porfavor digite una opcion valida");
		}
	}
	return lista;
	
	
	
}


Coleccionistas * agregarListaColeccionista(Coleccionistas * lista){
	Coleccionistas * ayudante,*actual;
	Postales * colaborador,* ayudante1;
	int cedula;
	printf("Ingrese el numero de cedula del coleccionista al que desea ingresar las postales");
	scanf("%d",&cedula);
	ayudante=lista;
	while(ayudante!=NULL){
		if(ayudante->coleccionista.cedula==cedula){
			actual=ayudante;
			printf("El coleccionista ha sido encontrado");
		}
		ayudante=ayudante->siguiente;
	}
	actual->coleccionista.obtenidas=NULL;
	ayudante1 = accionDePostales(actual->coleccionista.obtenidas);
	printf("Si sale SUUU");
	actual->coleccionista.obtenidas=ayudante1;
	return lista;
//	int numeroPostales,iterador;
//	printf("Cuantas postales desea agregar:");
//	scanf("%d",&numeroPostales);
//	while(iterador<numeroPostales){
//		struct Postal postal;
//		printf(" \n Ingrese el codigo de la postal: ");
//		scanf("%s",&postal.codigoPostal);
//			//printf("%s",postal.codigoPostal);
//			
//		printf("\n Ingrese el nombre de la postal: ");
//		scanf(" %s", &postal.nombrePostal);
//			//printf("%s",nombrePostal);
//			
//		printf("\n Ingrese la seccion o equipo de la postal:  ");
//		scanf(" %s",&postal.seccionOEquipo);
//			//printf("%s",seccionPostal);
//			
//		printf("\n Ingrese el precio de la postal");
//		scanf("%d",&postal.precioPostal);
//		actual->coleccionista.obtenidas =agregarPostal(actual->coleccionista.obtenidas,postal);
//			
//		iterador++;
//	}
//	//actual->coleccionista.obtenidas=colaborador;
//	printf("\n Se han ingresado las postales que deseaba al coleccionista nos vemos :D\n ");
//	
//	consultarCatalogoPostales(actual->coleccionista.obtenidas);
	
	
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


int largoRepetidas(PostalesRepetidas * lista){
	PostalesRepetidas * ayudante;
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
	//printf("El largo es %d\n ",len);
	int contador=0;
	nuevaLista=NULL;
	ayudante2=lista;
	while(contador<len){
		if(ayudante2==NULL){
			break;
		}
		int iterador=0;
		//printf("El contador es %d", contador);
		temporal=NULL;
		ayudante1=ayudante2;
		//printf("\n Entra al ayudante1");
		char * postal = ayudante1->postal.codigoPostal;
		//printf("\n la postal es %s", postal);
		struct Postal postalStruct =ayudante1->postal;
		//printf("\n El precio de la postal es %d", postalStruct.precioPostal);
		temporal=agregarPostal(temporal,ayudante1->postal);
		//printf("\n El temporal es: %s",temporal->postal.codigoPostal);
		while(ayudante1->siguiente!=NULL){
			//printf("Funciona el while de ayudante1");
			//printf("\n El temporal es: %s",temporal->postal.codigoPostal);
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
		//printf(" \n EL iterador es  %d",iterador);
		nuevaLista = agregarListaRepetida(nuevaLista,postalStruct,iterador);
		//printf("\n Datos nueva Lista\n ");
		//printf("Repeticiones de %s , %d", nuevaLista->postal.codigoPostal,nuevaLista->repetida);
		ayudante2=temporal;
		ayudante2=ayudante2->siguiente;
		contador++;
	}
	return nuevaLista;
}


PostalesRepetidas * postalesRepetidas(Coleccionistas *lista,int cedula,Postales *listaPostales){
	Coleccionistas *ayudante;
	Postales * ayudante3;
	//printf("%d",cedula1);
	ayudante=lista;
	while(ayudante!=NULL){
		//printf("Funciona el while");
		//printf("\n %d",ayudante->coleccionista.cedula);
		if(ayudante->coleccionista.cedula==cedula){
			//printf("Cedula encontrada!");
			break;
		}
		ayudante=ayudante->siguiente;
	}
	if(ayudante->coleccionista.obtenidas==NULL){
		printf("\n El coleccionista no tiene ninguna postal\n ");
		return NULL;
	}
	PostalesRepetidas *ayudante1,*ayudante2;
	ayudante1 = crearListaRepetidas(ayudante->coleccionista.obtenidas);
	ayudante2=ayudante1;
	while(ayudante2!=NULL){
		printf("\n Postal %s \n", ayudante2->postal.codigoPostal);
	
		printf("Seccion o Equipo %s \n", ayudante2->postal.seccionOEquipo);
	
		printf("Nombre del jugador, estadio o elemento: %s \n", ayudante2->postal.nombrePostal);
					
		printf("Precio : %d \n \n", ayudante2->postal.precioPostal);
		
		printf("Numero de repetidas %d\n ",ayudante2->repetida);
		ayudante2=ayudante2->siguiente;
	}
	return ayudante1;
	
} 


Postales * crearListaFaltantes(Postales * lista,PostalesRepetidas * lista1){
	Postales * ayudante, *ayudante3,*nuevaLista;
	PostalesRepetidas * ayudante1,*ayudante2;
	if(lista1==NULL){
		//printf("\n El coleccionista no tiene ninguna postal todavia, deberia comprar algunos sobres :D\n ");
		printf("\n SU LISTA DE FALTANTES ES:\n  ");
		ayudante3=lista;
		while(ayudante3!=NULL){
			printf("Postal %s \n", ayudante3->postal.codigoPostal);
	
			printf("Seccion o Equipo %s \n", ayudante3->postal.seccionOEquipo);
	
			printf("Nombre del jugador, estadio o elemento: %s \n", ayudante3->postal.nombrePostal);
					
			printf("Precio : %d \n \n", ayudante3->postal.precioPostal);
			printf("Repeticion");
			ayudante3=ayudante3->siguiente;
			printf("Repeticion");
		}
		printf("Sale de la funcion");
		return lista;
	}
	printf("HELLO");
	int len= largoRepetidas(lista1);
	printf("El largo funciona :D");
	nuevaLista=NULL;
	ayudante=lista;
	while(ayudante!=NULL){
		int valor=0;
		ayudante1=lista1;
		while(ayudante1!=NULL){
			if(strcmp(ayudante1->postal.codigoPostal,ayudante->postal.codigoPostal)==0){
				printf("\n El valor de las repetidas  es %s\n ",ayudante1->postal.codigoPostal);
				printf("\n El valor de las repetidas  es %s\n ",ayudante->postal.codigoPostal);
				valor=1;
			}
			printf("\n La repeticion si funciona el valor es %d\n ",valor);
			ayudante1=ayudante1->siguiente;
		}
		if(valor==0){
			nuevaLista= agregarPostal(nuevaLista,ayudante->postal);
		}
		ayudante=ayudante->siguiente;
	}
	
	
		printf("\n SU LISTA DE FALTANTES ES:\n  ");
		ayudante3=nuevaLista;
		while(ayudante3!=NULL){
			printf("Postal %s \n", ayudante3->postal.codigoPostal);

			printf("Seccion o Equipo %s \n", ayudante3->postal.seccionOEquipo);

			printf("Nombre del jugador, estadio o elemento: %s \n", ayudante3->postal.nombrePostal);
				
			printf("Precio : %d \n \n", ayudante3->postal.precioPostal);
			printf("Repeticion");
			ayudante3=ayudante3->siguiente;
			//printf("Repeticion");
			
		}
	
	
	
	return nuevaLista;
	
}

Postales * postalesFaltantes(Postales *listaTotal, Coleccionistas* lista, PostalesRepetidas * listaPostalesRepetidas, int cedula){
	Postales * ayudante1;
	Coleccionistas *ayudante;
	ayudante=lista;
	if(listaTotal==NULL){
		printf("Las postales no han salido al mercado");
		return NULL;
	}
	while(ayudante!=NULL){
		//printf("Funciona el while");
		//printf("\n %d",ayudante->coleccionista.cedula);
		if(ayudante->coleccionista.cedula==cedula){
			//printf("Cedula encontrada!");
			break;
		}
		ayudante=ayudante->siguiente;
	}
	printf("No funciona");
	ayudante1 = crearListaFaltantes(listaTotal,listaPostalesRepetidas);
	printf("%d",ayudante1->postal.precioPostal);
	printf("No funciona");
	return ayudante1;
	
}



Coleccionistas * menuRepetidasyFaltantes(Coleccionistas * lista, Postales * postales){
	int valor=0;
	int opcion;
	while(valor==0){
		printf("\n Ingrese 1 si desea  a ver la lista repetidas y faltantes \n");
		printf("\n Ingrese 0 si desea salir del menu\n ");
		scanf("%d",&opcion);
		if(opcion==1){
			int cedula;
			PostalesRepetidas * repetidas;
			Postales * faltantes;
			
			printf("\n Ingrese el numero de cedula del coleccionista\n ");
			scanf("%d",&cedula);
			printf("\n******************LISTA REPETIDAS ************************\n");
			repetidas = postalesRepetidas(lista,cedula,postales);
			printf("\n******************LISTA FALTANTES ************************\n");
			faltantes = postalesFaltantes(postales,lista,repetidas,cedula);
			Coleccionistas* ayudante;
			ayudante=lista;
			while(ayudante!=NULL){
				if(ayudante->coleccionista.cedula==cedula){
					break;
				}
				ayudante=ayudante->siguiente;
			}
			ayudante->coleccionista.repetidas=repetidas;
			ayudante->coleccionista.faltantes =faltantes;
		}
		if(opcion==0){
			printf("\nGracias por utilizar el menu de postales repetidas y faltantes\n ");
			break;
		}
		else{
			printf("Ingrese una opcion valida");
		}
	}
	return lista;
}


Coleccionistas * eliminadorinformacion(Coleccionistas *lista){
	int cedula;
	Coleccionistas * ayudante, *nuevaLista;
	printf("\n Porfavor ingrese el numero de cedula del coleccionista que desea eliminar");
	scanf("%d",&cedula);
	ayudante=lista;
	while(ayudante!=NULL){
		printf("Funciona");
		if(ayudante->siguiente->coleccionista.cedula==cedula){
			//printf("La cedula del coleccionista es: %d",ayudante->coleccionista.cedula);
			int valor;
			printf("Coleccionista encontrado");
			if(ayudante->coleccionista.obtenidas=!NULL){
				printf("\ n No se puede eliminar ya que tiene postales ingresadas\ n");
				break;
			}
			ayudante->siguiente=ayudante->siguiente->siguiente;
			printf("\n Coleccionista eliminado :D \n ");
		}
		ayudante=ayudante->siguiente;
		printf("Funciona");
//			printf("Esta seguro que desea eliminar el coleccionista por completo?\n Digite 1 si desea eliminar \n Digite 0 si desea cancelar ");
//			scanf("%d",&valor);
//			if (valor==0){
//				printf("Accion de cancelar cancelada!");
//				return lista;
//			}
//			if (valor==1){
//				if(ayudante->coleccionista.obtenidas!=NULL){
//					printf("No se puede eliminar este coleccionista debido a que tiene postales ingresadas :D");
//					return lista;
//				}
//				printf("El coleccionista ha sido eliminado :c");
//			}
//		}
		//nuevaLista= agregarColeccionista(ayudante,ayudante->coleccionista);
	}
	return lista;
	
}







Cola * agregarElemento(Cola *cola,struct Colita cola1){
	Cola *ayudante,*temporal;
	if(cola==NULL){
		cola = (Cola*)malloc(sizeof(Cola));
		cola->colaA=cola1;
		cola->siguiente=NULL;
	}else{
		ayudante=cola;
		while(ayudante!=NULL){
			ayudante=ayudante->siguiente;
			
		}
		ayudante->siguiente=(Cola*)malloc(sizeof(Cola));
		ayudante->siguiente->colaA=cola1;
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
	printf(" \n El rango del coleccionista es : %s\n ",ayudante->coleccionista.rango);
	//cola1.nivel;
	printf("\n Porfavor Ingrese su rango de coleccionista en minuscula y bien escrito: (bronce),(plata),(oro),(zafiro)\n");
	scanf("%s",&cola1.nivel);
	//cola1.nivel= ayudante->coleccionista.rango;
	
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
			int valor= verificadorPostalesRepetidas(ayudante->coleccionista.repetidas,cola1.codigoPostalCambio) ;
			//valor = ayudante->coleccionista.repetidas;
			printf("el valor de repetidas de esa postal es: %d",valor);
			if(verificadorPostalesRepetidas(ayudante->coleccionista.repetidas,cola1.codigoPostalCambio)!=1){
				
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
	printf("\n SI ENTRA \n");
	while(ayudante!=NULL){
		printf("El codigo de la postal es %s",ayudante->postal.codigoPostal);
		if(strcmp(ayudante->postal.codigoPostal,codigoPostal)==0){
			int valor= ayudante->repetida;
			printf("\n El coleccionista tiene %d repetidas \n ",valor);
			if(valor>=1){
				return 1;
			}
		}
		ayudante=ayudante->siguiente;
	}
	return 0;
}