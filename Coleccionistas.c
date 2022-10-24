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

struct Colita {
	char codigoPostal[99];
	char codigoPostalCambio[99];
	int cedulaSolicitador;
	int cedulaOwner;
	char nivel[99];
	int precio;
	const char* registro;
	const char * tipoTransaccion;
	
};

typedef struct cola{
	struct Colita colaA;
	struct cola * siguiente;
	
}Cola;


struct Registro{
	int precio;
	char codigo[99];
	int cedulaComprador;
};


typedef struct ventas{
	struct Registro registro;
	struct ventas * siguiente;
}Ventas;


struct Coleccionista{
	int cedula;
	char nombreCompleto[99];
	char fechaNacimiento[99];
	char correoElectronico[99];
	const char* rango;
	int transacciones;
	Postales * obtenidas;
	PostalesRepetidas * repetidas;
	Postales *faltantes;
	Cola * reservaciones;
	Ventas * venta;
};

typedef struct nodoCole{
	struct Coleccionista coleccionista;
	//Postales * listaPostales;
	struct nodoCole * siguiente;
	struct nodoCole *anterior;
}Coleccionistas;

void imprimirPilaVenta(Coleccionistas * lista);

Postales * agregarPostal(Postales * lista, struct Postal postal);
void consultarCatalogoPostales(Postales* lista);
Postales * modificarPostal(Postales * lista);
Postales * accionDePostales(Postales*lista);
Coleccionistas * agregarColeccionista(Coleccionistas * lista, struct Coleccionista coleccionista);
void consultarCatalogoColeccionistas(Coleccionistas* lista);
Coleccionistas * modificarColeccionistas(Coleccionistas *lista);
Coleccionistas * albumPanini2022(Coleccionistas *lista, Postales * postales);
Coleccionistas * agregarListaColeccionista(Coleccionistas * lista);
Coleccionistas * opcionesColeccionistas(Coleccionistas *lista,Postales *postales);
Coleccionistas * generadorListaFaltantes(Coleccionistas * lista,Postales * postales);
void postalesRepetidas(Coleccionistas *lista,int cedula);

PostalesRepetidas * agregarListaRepetida(PostalesRepetidas* lista,struct Postal postal ,int repeticion);
int largo(Postales * lista);
int largoRepetidas(PostalesRepetidas * lista);
PostalesRepetidas * crearListaRepetidas(Postales * lista);
Coleccionistas * GeneradorPostalesRepetidas(Coleccionistas *lista,Postales *listaPostales);
void postalesRepetidas(Coleccionistas *lista,int cedula);
Coleccionistas * registrarColaDeColeccionista(Coleccionistas * lista);

Postales * crearListaFaltantes(Postales * lista, PostalesRepetidas * repetidas);
Postales * postalesFaltantes(Postales *listaTotal, Coleccionistas* lista, PostalesRepetidas * listaPostalesRepetidas, int cedula);
Coleccionistas * menuRepetidasyFaltantes(Coleccionistas * lista, Postales *postales);
Coleccionistas * eliminadorinformacion(Coleccionistas *lista);

Cola * agregarElementoCola(Cola *cola,struct Colita cola1);

Cola * agregarElemento(Cola *cola,struct Colita cola1);

Cola* creadorColaGeneral(Coleccionistas * lista,Cola* nuevaCola, int cedula1);

Coleccionistas * menuGeneralCola(Coleccionistas * lista);

Coleccionistas * validadorCedulas(Coleccionistas * lista,int cedula);

void registrarPostalestxt(Postales * lista);
Coleccionistas * validadorCedulas(Coleccionistas * lista,int cedula);

Coleccionistas * intercambiarPostales(Coleccionistas * lista,int cedulaOwner, int cedulaSolicitador, char codigoOwner[],char codigoSolicitador[]);

Postales * encontrarPostal(Postales * lista, char codigo[]);

Coleccionistas * comprarPostal(Coleccionistas * lista, char codigo[],int precio, int cedulaOwner,int cedulaSolicitador);

Postales * eliminarPostalObtenida(Postales * lista,char codigo[],int  cedula);

Coleccionistas * creadorSistema(Cola * sistema, Coleccionistas * lista);

void imprimirCola(Cola * cola);
Cola * creadorColaSistema(Coleccionistas * lista);
Coleccionistas * sistemaDeReservacion(Cola* sistema, Coleccionistas * lista);
Coleccionistas * revisionDeNiveles(Coleccionistas * lista);
char niveladorRangos(char rango[]);
Ventas * agregarVenta(Ventas * pila, struct Registro registro);

int main(){
	Coleccionistas*lista=NULL;
	Postales *postales=NULL;
	struct Coleccionista coleccionista ={ 123456,"JUAN", "2/04/22", "juan@hotmail.com", "BRONZE",0,NULL,NULL,NULL,NULL,NULL};
	lista=agregarColeccionista(lista,coleccionista);
//	lista=modificarColeccionistas(lista);
//	consultarCatalogoColeccionistas(lista);
	lista = albumPanini2022(lista,postales);
	//creadorColaGeneral(lista);
	//lista = opcionesColeccionistas(lista);
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
	//registrarPostalestxt(lista);
	printf("\n Funciona el el registro \n");
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
				printf("El numero de transacciones del coleccionista %d",ayudante->coleccionista.transacciones);
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
						char rango;
						printf("Ingrese el nuevo rango del coleccionista: ");
						scanf("%s",&rango);
						ayudante->coleccionista.rango=rango;
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

Coleccionistas * opcionesColeccionistas(Coleccionistas *lista,Postales *postales){
	int valor=1;
	while(valor==1){
		int opcion;
		printf("\n Digite 1 si desea agregar un coleccionista\n ");
		printf("Digite 2 si desea modificar un coleccionista \n");
		printf("Digite 3 si desea consultar la lista de coleccionistas \n");
		printf("Digite 4 si desea ingresar al sistema de postales de los coleccionistas\n");
		printf("Digite 5 si desea ver la lista de repetidas y faltantes del coleccionista \n");
		printf("Digite 6 si desea hacer una reservacion a otro coleccionista de las postales\n ");
		printf("\n Digite 7 si desea eliminar a un coleccionista\n ");
		printf("Digite 8 si desea salir del sistema de coleccionista \n");
		scanf("%d",&opcion);
		if (opcion==1){
			char nivel;
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
			int opcion;
			printf("\n Ingrese 1 si  el rango que tiene el coleccionista es zafiro, \n ingrese 2 si el rango es oro\n 3 si es el rango es plata \n 4 si el rango es bronce:");
			scanf("%d",&opcion);
			printf("\n La opcion vale %d \n",opcion );
			if(opcion==1){
				coleccionista.rango="zafiro";
			}
			if(opcion==2){
				coleccionista.rango="oro";
			}
			if(opcion==3){
				coleccionista.rango="plata";
			}
			if(opcion==4){
				coleccionista.rango="bronce";
			}
			printf("\n El rango del coleccionista es %s \n",coleccionista.rango);
			coleccionista.transacciones=35;
			
			coleccionista.obtenidas=NULL;
			coleccionista.reservaciones=NULL;
			coleccionista.venta=NULL;
			
			lista = agregarColeccionista(lista, coleccionista);
			
		}
		if(opcion==2){
			lista = modificarColeccionistas(lista);	
		}
		if(opcion==3){
			printf("Consultar las listas de los coleccionistas");
			consultarCatalogoColeccionistas(lista);
		}
		if(opcion==8){
			printf("Gracias por consultar el sistema de coleccionistas");
			break;
		}
		if(opcion==4){
			printf("\n Bienvenido al sistema de ingreso de postales al coleccionista :D\n");
			lista= agregarListaColeccionista(lista);
		}
		if(opcion==5){
			printf("\n Ha escogido revisar la lista de repetidas y las faltantes del coleccionista\n ");
			lista =  menuRepetidasyFaltantes(lista, postales);
			
		}
		if(opcion==6){
			printf("Bienvenido al sistema de reservacion de cola\n ");
			lista= registrarColaDeColeccionista(lista);
			
			
		}
		if(opcion==7){
			printf("Ha elegido Eliminar la informacion de algun coleccionista\n ");
			lista= eliminadorinformacion(lista);
			
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
		printf("Digite 2 desea ingresar al menu general del sistema\n");
		printf("Digite 3 si desea ingresar al menu de postales generales \n");
		printf("Digite 4 si desea salir del sistema");
		scanf("%d",&opcion);
		if(opcion==1){
			printf("***********Ha elegido Ingresar al sistema de coleccionista**************\n ");
			lista=opcionesColeccionistas(lista,postales);
			
		}
		if (opcion==2){
			printf("Ha escogido ingresar al sistema de postales :D \n ");
			Cola * sistema = NULL;
			sistema =creadorColaSistema(lista);
			imprimirCola(sistema);
			lista = sistemaDeReservacion(sistema,lista);
			sistema =creadorColaSistema(lista);
			imprimirCola(sistema);
			imprimirPilaVenta( lista);
			
			
//			lista= creadorSistema(sistema,lista);
		}

		if (opcion==3){
			printf("Ha decidido ingresar al menu de postales Generales\n ");
			postales = accionDePostales(postales);
			
		}
		if(opcion==4){
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
	ayudante = validadorCedulas(lista,cedula);
	ayudante->coleccionista.obtenidas = accionDePostales(ayudante->coleccionista.obtenidas);
	printf("Si sale SUUU");
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

Postales * eliminadorPorIndex( int index, PostalesRepetidas * postales){
	Postales * ayudante,*nuevaLista;
	int indice=0;
	nuevaLista=NULL;
	while(ayudante!=NULL){
		if(indice==index){
			ayudante=ayudante->siguiente;
			continue;
		}
		nuevaLista= agregarPostal(nuevaLista,ayudante->postal);
		ayudante=ayudante->siguiente;
	}
	return nuevaLista;
}

//PostalesRepetidas * crearListaRepetidas(Postales * lista){
//	Postales * ayudante,*ayudante2;
//	ayudante=lista;
//	PostalesRepetidas *nuevaLista;
//	nuevaLista=NULL;
//	int len = largo(lista);
//	int iterador=0;
//	while(iterador<len){
//		ayudante2=ayudante->siguiente;
//		int repeticion=0;
//		int index=1;
//		while(ayudante2!=NULL){
//			if (strcmp(ayudante->postal.codigoPostal,ayudante2->postal.codigoPostal)==0){
//				repeticion++;
//				ayudante= eliminadorPorIndex(index,ayudante);
//			}
//			ayudante2=ayudante2->siguiente;
//			index++;
//		}
//		nuevaLista = agregarListaRepetida(nuevaLista,ayudante,repeticion);
//		iterador++;
//		
//	}
//	
//	
//	
//}
PostalesRepetidas * crearListaRepetidas(Postales * lista){
	PostalesRepetidas  *nuevaLista;
	Postales * ayudantePostal1,*temporal,*ayudantePostal2;
	int len = largo(lista);
	//printf("El largo es %d", len);
	int contador=0;
	nuevaLista=NULL;
	ayudantePostal1=lista;
	while(contador<len){
		if(ayudantePostal1==NULL){
			break;
		}
		int iterador=0;
		//printf("\n Pasa el primer if \n");
		//Temporal Forma parte de tipo Postales
		temporal=NULL;
		ayudantePostal2=ayudantePostal1;
		char *  postal = ayudantePostal2->postal.codigoPostal;
		//printf("\n %s \n",postal);
		struct Postal postalStruct =ayudantePostal2->postal;
		
		temporal=agregarPostal(temporal,ayudantePostal2->postal);
		while(ayudantePostal2->siguiente!=NULL){

			if (strcmp(postal,ayudantePostal2->siguiente->postal.codigoPostal)!=0){
				
				temporal=agregarPostal(temporal,ayudantePostal2->siguiente->postal);
			}else{
				
				iterador++;
			}
			ayudantePostal2=ayudantePostal2->siguiente;
			
		}
		//printf("El iterador es  %d",iterador);
		nuevaLista = agregarListaRepetida(nuevaLista,postalStruct,iterador);
		
		ayudantePostal1=temporal;
		ayudantePostal1=ayudantePostal1->siguiente;
		contador++;
	}
	return nuevaLista;
}


Coleccionistas *generadorPostalesRepetidas(Coleccionistas * lista){
	Coleccionistas * ayudante;
	Postales * ayudante1;
	ayudante=lista;
	printf("Ingresa generador \n ");
	while(ayudante!=NULL){
		printf("Ingresa al while\n ");
		if(ayudante->coleccionista.obtenidas==NULL){
			printf("\n El coleccionista de cedula %d no tiene ninguna postal\n ",ayudante->coleccionista.cedula);
			ayudante=ayudante->siguiente;
			
			continue;
		}
		ayudante->coleccionista.repetidas= crearListaRepetidas(ayudante->coleccionista.obtenidas);

		ayudante=ayudante->siguiente;
		
	}
	return lista;
}





void postalesRepetidas(Coleccionistas *lista,int cedula){
	Coleccionistas *ayudante;
	PostalesRepetidas * ayudante3;
	ayudante= validadorCedulas(lista,cedula);
	if(ayudante->coleccionista.obtenidas==NULL){
		printf("\n El coleccionista no tiene ninguna postal\n ");
		return NULL;
	}
	ayudante3 = ayudante->coleccionista.repetidas;
	while(ayudante3!=NULL){
		printf("\n Postal %s \n", ayudante3->postal.codigoPostal);
	
		printf("Seccion o Equipo %s \n", ayudante3->postal.seccionOEquipo);
	
		printf("Nombre del jugador, estadio o elemento: %s \n", ayudante3->postal.nombrePostal);
					
		printf("Precio : %d \n \n",ayudante3->postal.precioPostal);
		
		printf("Numero de repetidas %d\n ",ayudante3->repetida);
		ayudante3=ayudante3->siguiente;
		
	}
		

	
} 




Postales * crearListaFaltantes(Postales * lista, PostalesRepetidas * repetidas){
	if(repetidas==NULL){
		return lista;
	}
	Postales * ayudantePostales,*faltantes;
	faltantes=NULL;
	//printf("\n ingresa al creador de lista \n ");
	PostalesRepetidas *ayudantePostalesRepetidas;
	ayudantePostales=lista;
	while(ayudantePostales!=NULL){
		int valor=0;
		ayudantePostalesRepetidas=repetidas;
		//printf("\n ingresa al while de creador  \n ");
		while(ayudantePostalesRepetidas!=NULL){
			//printf(" \n %s codigo postal general  ",ayudantePostales->postal.codigoPostal);
			//printf("\n %s codigo propio de postales ",ayudantePostalesRepetidas->postal.codigoPostal);
			if(strcmp(ayudantePostales->postal.codigoPostal,ayudantePostalesRepetidas->postal.codigoPostal)==0){
				valor=1;
			}
			ayudantePostalesRepetidas=ayudantePostalesRepetidas->siguiente;
		}
		if(valor==0){
			faltantes = agregarPostal(faltantes,ayudantePostales->postal);
		}
		ayudantePostales=ayudantePostales->siguiente;
		
	}
	//printf("Codigo de lugar #2 %s",faltantes->siguiente->postal.codigoPostal);
	
	return faltantes;
}

Coleccionistas * generadorListaFaltantes(Coleccionistas * lista,Postales * postales){
	Coleccionistas * ayudante;
	ayudante=lista;
	//printf("\n ingresa al generador \n ");
	while(ayudante!=NULL){
		ayudante->coleccionista.faltantes=crearListaFaltantes(postales,ayudante->coleccionista.repetidas);
		
		ayudante=ayudante->siguiente;
	}
	//printf("\n %s codigo lista  \n ",lista->coleccionista.faltantes->siguiente->postal.codigoPostal);
	return lista;
	
}

void imprimidorListaFaltantes(Coleccionistas *lista, int cedula){
	Coleccionistas * ayudante;
	ayudante= validadorCedulas(lista,cedula);
	if(ayudante->coleccionista.faltantes==NULL){
		printf("\n Las Postales no han salido al mercado espera o agrega postales generales \n");
		
	}else{
		Postales  * ayudantePostales;
		ayudantePostales =ayudante->coleccionista.faltantes;
		while(ayudantePostales!=NULL){
			printf("\n *******************Postal %s******************* \n", ayudantePostales->postal.codigoPostal);
		
			printf("*******************Seccion o Equipo %s******************* \n", ayudantePostales->postal.seccionOEquipo);
		
			printf("*******************Nombre del jugador, estadio o elemento: %s *******************\n", ayudantePostales->postal.nombrePostal);
						
			printf("*******************Precio : %d \n *******************\n", ayudantePostales->postal.precioPostal);
			ayudantePostales=ayudantePostales->siguiente;
			
		}
		
		
	}

		
	
	
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
			lista = generadorPostalesRepetidas(lista);
			printf("Funciona el generador");
			postalesRepetidas(lista,cedula);
			printf("Funciona el imprimidor");
			printf("\n******************LISTA FALTANTES ************************\n");
			lista= generadorListaFaltantes( lista,postales);
			printf("Funciona lista faltantes");
			imprimidorListaFaltantes(lista,cedula);
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
	nuevaLista=NULL;
	printf("\n Porfavor ingrese el numero de cedula del coleccionista que desea eliminar");
	scanf("%d",&cedula);
	
	ayudante=lista;
	while(ayudante!=NULL){
		//printf("La cedula del coleccionista es:%d ",ayudante->coleccionista.cedula);
		if(ayudante->coleccionista.cedula==cedula){
			//printf("La cedula del coleccionista es: %d",ayudante->coleccionista.cedula);
			int valor;
			printf("Coleccionista encontrado");
			if(ayudante->coleccionista.obtenidas==NULL){
				//printf("Funciona el NULL");
				ayudante=ayudante->siguiente;
				continue;
			}else{
				printf("\ n No se puede eliminar ya que tiene postales ingresadas\ n");
				return lista;
			}
			printf("\n Coleccionista eliminado :D \n ");
		
		}
		printf("LLega bien");
		nuevaLista= agregarColeccionista(nuevaLista,ayudante->coleccionista);
		printf("Termina el proceso!");
		ayudante=ayudante->siguiente;

	}
	return nuevaLista;
	
}







Cola * agregarElementoCola(Cola *cola,struct Colita cola1){
	Cola *ayudante,*temporal;
	if(cola==NULL){
		cola = (Cola*)malloc(sizeof(Cola));
		cola->colaA=cola1;
		cola->siguiente=NULL;
	}else{
		ayudante=cola;
		while(ayudante->siguiente!=NULL){
			ayudante=ayudante->siguiente;
			
		}
		ayudante->siguiente=(Cola*)malloc(sizeof(Cola));
		ayudante->siguiente->colaA=cola1;
		ayudante->siguiente->siguiente=NULL;
		
	}
	return cola;
}



Cola * colaDePrioridad(Cola * cola){
	Cola * ayudante,* colaZafiro=NULL, *colaOro=NULL, *colaPlata=NULL,*colaBronce=NULL, *colaSobrante=NULL;
	ayudante=cola;
	while(ayudante!=NULL){
		if(strcmp(ayudante->colaA.nivel,"zafiro")==0){
			colaZafiro=agregarElementoCola(colaZafiro,ayudante->colaA);
		}
		if(strcmp(ayudante->colaA.nivel,"oro")==0){
			colaOro=agregarElementoCola(colaOro,ayudante->colaA);
		}
		if(strcmp(ayudante->colaA.nivel,"plata")==0){
			colaPlata=agregarElementoCola(colaPlata,ayudante->colaA);
			
		}
		if(strcmp(ayudante->colaA.nivel,"bronce")==0){
			colaBronce=agregarElementoCola(colaBronce,ayudante->colaA);
		}
		else{
			printf("\n El nivel del coleccionista de cedula %d esta mal ingresado \n ",ayudante->colaA.cedulaSolicitador);
			printf("Se le ingresara de ultimo en la cola\n ");
			printf(" PORFAVOR CORREGIR EL ERROR SI DESEA TENER MEJORES OFERTAS\n");
			colaSobrante=agregarElementoCola(colaSobrante,ayudante->colaA);
			
			
		}
		ayudante=ayudante->siguiente;
			
	}
	if(colaBronce==NULL){colaBronce=colaSobrante;}else{colaBronce->siguiente=colaSobrante;}
	if(colaPlata==NULL){colaPlata=colaBronce;}else{colaPlata->siguiente=colaBronce;}

	if(colaOro==NULL){colaOro=colaPlata;}else{colaOro->siguiente=colaPlata;}

	if(colaZafiro==NULL){ colaZafiro=colaOro;}else{colaZafiro->siguiente=colaOro;}
	
	printf("colaZafiro tiene de codigo %d ",colaZafiro->colaA.cedulaOwner);
	return colaZafiro;
	
}


Coleccionistas * registrarColaDeColeccionista(Coleccionistas * lista){
	int cedulaSolicitador,cedulaFiador;
	printf("\n Ingrese su cedula:");
	scanf("%d",&cedulaSolicitador);

	printf("Ingrese la cedula del coleccionista con el que va a realizar la transaccion;");
	scanf("%d",&cedulaFiador);
	Coleccionistas * ayudanteFiador, *ayudanteSolicitador;
	ayudanteFiador=validadorCedulas(lista,cedulaFiador);
	ayudanteSolicitador=validadorCedulas(lista,cedulaSolicitador);
	
	int _=0 ,transacciones=0;
	while(_==0){
		int opcion;
		printf("Digite 1 si desea realizar un intercambio de postales \n Digite 2 si desea realizar una compra de postal \n Digite 3 si ya no desea intercambiar con este coleccionista");
		scanf("%d",&opcion);
		struct Colita colita;
		colita.cedulaSolicitador= cedulaSolicitador;
		colita.cedulaOwner= cedulaFiador;
		if (opcion==1){
			printf("\n Has escogido realizar un intercambio de postales ");
			printf("Ingrese el codigo de la  postal que desea reservar:");
			scanf("%s",&colita.codigoPostal);
			printf("Ingrese el codigo de la postal que desea dar a cambio");
			scanf("%s",&colita.codigoPostalCambio);
			colita.precio=-1;
			colita.nivel[7]=ayudanteSolicitador->coleccionista.rango;
			colita.registro="registrada";
			colita.tipoTransaccion= "intercambio";
			ayudanteFiador->coleccionista.reservaciones=agregarElementoCola(ayudanteFiador->coleccionista.reservaciones,colita);
			//ayudanteFiador->coleccionista.reservaciones->colaA.registro[99]="HOLA";
			printf("Cedula owner %d ",ayudanteFiador->coleccionista.reservaciones->colaA.cedulaOwner);
			printf("Se ha ingresado su Transaccion correctamente");
			ayudanteSolicitador->coleccionista.transacciones++;
		}
		if(opcion==2){
			printf("\n Has escogido realizar una compra de postales ");
			printf("Ingrese el codigo de la  postal que desea reservar:");
			scanf("%s",&colita.codigoPostal);
			printf("Ingrese el precio de la postal que desea comprar");
			scanf("%d",&colita.precio);

			colita.nivel[7]=ayudanteSolicitador->coleccionista.rango;
			colita.tipoTransaccion="compra";
			colita.registro="registrada";
			ayudanteFiador->coleccionista.reservaciones=agregarElementoCola(ayudanteFiador->coleccionista.reservaciones,colita);
			printf("\n Se ha ingresado su Transaccion correctamente\n ");
			ayudanteSolicitador->coleccionista.transacciones++;
		}
		if(opcion==3){
			printf("Nos vemos pronto! \n");
			break;
		}
		else{
			printf("Digite una opcion valida");
		}
		
		
	}
	return lista;	
	
}


	
	
	
	
	






















int verificadorPostalesRepetidas(PostalesRepetidas *lista,char codigoPostal[]){
	PostalesRepetidas * ayudante;
	ayudante=lista;
	printf("%d",lista->repetida);
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




Coleccionistas * validadorCedulas(Coleccionistas * lista,int cedula){
	Coleccionistas * ayudante;
	ayudante=lista;
	while(ayudante!=NULL){
		if(ayudante->coleccionista.cedula==cedula){
			break;
		}
		ayudante=ayudante->siguiente;
	}
	return ayudante;
}



//SISTEMA




Cola * asignarValorRegistro(Cola * sistema,int valor){
	//printf("hola");
	Cola * ayudante= sistema;
	//printf(" \n asignar valores %s \n",ayudante->colaA.registro);
	while(ayudante!=NULL){
		printf(" \n asignar valores %s \n",ayudante->colaA.registro);
		if(strcmp("rechazada",ayudante->colaA.registro)==0||strcmp("aprobada",ayudante->colaA.registro)==0){
			printf(" \n asignar valores %s \n",ayudante->colaA.registro);
			ayudante->siguiente;
		}else{
			if(valor==0){
				ayudante->colaA.registro="rechazada";
			}
			if(valor==1){
				ayudante->colaA.registro="aprobada";
			}
			break;
		}
		ayudante=ayudante->siguiente;
	}

	return sistema;
		
}

Cola * verificarRegistro(Cola * cola){
	Cola * ayudante;
	ayudante= cola;
	while(ayudante!=NULL){
		if(strcmp(ayudante->colaA.registro,"rechazada")==0||strcmp(ayudante->colaA.registro,"aprobada")==0){
			ayudante=ayudante->siguiente;
		}else{
			break;
		}
	}
	return ayudante;
}



Coleccionistas * sistemaDeReservacion(Cola* sistema, Coleccionistas * lista){
	Cola * ayudante;
	ayudante=verificarRegistro(sistema);
	int valor=0;
	while(ayudante!=NULL){
		Coleccionistas * ayudanteColeccionistaOwner,*ayudanteColeccionistaSolicitador;
		ayudanteColeccionistaOwner = validadorCedulas(lista,ayudante->colaA.cedulaOwner);
		ayudanteColeccionistaSolicitador = validadorCedulas(lista,ayudante->colaA.cedulaSolicitador);
		if(checarPostales(lista,ayudante->colaA.codigoPostal,ayudante->colaA.cedulaOwner)==0){
			printf("El coleccionista owner tiene la postal disponible \n");
			if(strcmp(ayudante->colaA.tipoTransaccion,"intercambio")==0){
				printf(" \n Tipo de transaccion intercambio \n ");
				
				if(checarPostales(lista,ayudante->colaA.codigoPostalCambio,ayudante->colaA.cedulaSolicitador)==0){
					printf("\n El solicitador si tiene la postal\n ");
					lista = intercambiarPostales(lista,ayudante->colaA.cedulaOwner, ayudante->colaA.cedulaSolicitador,ayudante->colaA.codigoPostal,ayudante->colaA.codigoPostalCambio);
					
				
					ayudanteColeccionistaOwner->coleccionista.reservaciones= asignarValorRegistro(ayudanteColeccionistaOwner->coleccionista.reservaciones,1);
					valor=1;
				}else{
					printf("El coleccionista solicitador  de cedula %d no tiene la postal disponible para el intercambio  \n ",ayudante->colaA.cedulaSolicitador);
					//ordenarCola(ayudanteColeccionista->coleccionista.reservaciones->colaA.registro);
					ayudanteColeccionistaOwner->coleccionista.reservaciones= asignarValorRegistro(ayudanteColeccionistaOwner->coleccionista.reservaciones,0);
					
				}
			}
			
			if(strcmp(ayudante->colaA.tipoTransaccion,"compra")==0){
				lista =comprarPostal(lista, ayudante->colaA.codigoPostal,ayudante->colaA.precio, ayudante->colaA.cedulaOwner, ayudante->colaA.cedulaSolicitador);
				ayudanteColeccionistaOwner->coleccionista.reservaciones= asignarValorRegistro(ayudanteColeccionistaOwner->coleccionista.reservaciones,1);
			}
			
		}else{
			printf("El coleccionista Owner de cedula %d no tiene la postal disponible para el intercambio  \n ",ayudante->colaA.cedulaOwner);
			
			ayudanteColeccionistaOwner->coleccionista.reservaciones= asignarValorRegistro(ayudanteColeccionistaOwner->coleccionista.reservaciones,0);
			printf("Registro %s ",ayudanteColeccionistaOwner->coleccionista.reservaciones->colaA.registro);
	
			
		}
		ayudante=ayudante->siguiente;
		
	}
	
	return lista;
	
	
	
}

int checarPostales(Coleccionistas * lista, char  codigo[], int cedula){
	Coleccionistas * ayudante;
	ayudante= validadorCedulas(lista,cedula);
	Postales * ayudantePostal;
	ayudantePostal = ayudante->coleccionista.obtenidas;
	while(ayudantePostal!=NULL){
		if(strcmp(ayudantePostal->postal.codigoPostal,codigo)==0){
			return 0;
		}
		ayudantePostal=ayudantePostal->siguiente;
	}
	return 1;
	
	
	
	
}




Coleccionistas * intercambiarPostales(Coleccionistas * lista,int cedulaOwner, int cedulaSolicitador, char codigoOwner[],char codigoSolicitador[]){
	
	Coleccionistas * ayudanteSolicitador, * ayudanteOwner;
	ayudanteSolicitador = validadorCedulas(lista,cedulaSolicitador);
	
	ayudanteOwner = validadorCedulas(lista,cedulaOwner);
	Postales * listaPostalOwner,*listaPostalSolicitador;
	
	listaPostalOwner = encontrarPostal(ayudanteOwner->coleccionista.obtenidas,codigoOwner);
	
	listaPostalSolicitador = encontrarPostal(ayudanteSolicitador->coleccionista.obtenidas,codigoSolicitador);
	
	ayudanteOwner->coleccionista.obtenidas = agregarPostal(ayudanteOwner->coleccionista.obtenidas,listaPostalSolicitador->postal);
	
	ayudanteSolicitador->coleccionista.obtenidas= agregarPostal(ayudanteSolicitador->coleccionista.obtenidas,listaPostalOwner->postal);
	
	ayudanteOwner->coleccionista.obtenidas = eliminarPostalObtenida(ayudanteOwner->coleccionista.obtenidas,codigoOwner,0);
	ayudanteSolicitador->coleccionista.obtenidas = eliminarPostalObtenida(ayudanteSolicitador->coleccionista.obtenidas,codigoSolicitador,0);
	
	if(ayudanteSolicitador->coleccionista.transacciones>=30){
		printf("Felicidades subes de nivel!");
		ayudanteSolicitador= revisionDeNiveles(ayudanteSolicitador);
		printf("Sale de la revision de niveles");
		ayudanteSolicitador->coleccionista.transacciones=0;
	}
	
	
	
	return lista;
	
	
	
}








Postales * encontrarPostal(Postales * lista, char codigo[]){
	Postales * ayudante;
	ayudante= lista;
	while(ayudante!=NULL){
		if(strcmp(ayudante->postal.codigoPostal,codigo)==0){
			return ayudante;
		}
		ayudante=ayudante->siguiente;
	}
	return ayudante; 
	
}

Coleccionistas * comprarPostal(Coleccionistas * lista, char codigo[],int precio, int cedulaOwner,int cedulaSolicitador){
	Coleccionistas * ayudanteOwner,*ayudanteSolicitador;
	ayudanteOwner= validadorCedulas(lista,cedulaOwner);
	ayudanteSolicitador=validadorCedulas(lista,cedulaSolicitador);
	Postales * ayudantePostal;
	ayudantePostal=encontrarPostal(ayudanteOwner->coleccionista.obtenidas,codigo);
	int postal = ayudantePostal->postal.precioPostal-5;
	struct Registro registro;
	if(postal<=precio){
		printf("El precio de la postal es %d",postal);
		ayudantePostal->postal.precioPostal= precio;
		ayudanteSolicitador->coleccionista.obtenidas= agregarPostal(ayudanteSolicitador->coleccionista.obtenidas,ayudantePostal->postal);
		printf("Postal obtenida %s", ayudanteSolicitador->coleccionista.obtenidas->postal.codigoPostal);
		ayudanteOwner->coleccionista.obtenidas=eliminarPostalObtenida(ayudanteOwner->coleccionista.obtenidas,codigo,cedulaOwner);
		
		registro.cedulaComprador=cedulaSolicitador;
		registro.precio=precio;
		memcpy(registro.codigo, codigo, 20);
		ayudanteOwner->coleccionista.venta= agregarVenta(ayudanteOwner->coleccionista.venta, registro);
		printf(" venta realizada a precio %d ",ayudanteOwner->coleccionista.venta);
		if(precio>=25000){
			printf("Felicidades subes de nivel de rango");
			ayudanteSolicitador = revisionDeNiveles(ayudanteSolicitador);
			printf("El nuevo rango es %s ",ayudanteSolicitador->coleccionista.rango);
		}
		//ayudanteOwner->coleccionista.reservaciones->colaA.registro="aprobada";
		
		
	}else{
		ayudanteOwner->coleccionista.reservaciones->colaA.registro="rechazada";
	}
	return lista;
}



Postales * eliminarPostalObtenida(Postales * lista,char codigo[],int cedula)
{
	Postales * ayudante,*nuevaLista,*actual;
	ayudante= lista;
	int valor=1;
	nuevaLista=NULL;
	//actual= encontrarPostal(lista,codigo);

	
	while(ayudante!=NULL){
		if(strcmp(ayudante->postal.codigoPostal,codigo)!=0){
			nuevaLista=agregarPostal(nuevaLista,ayudante->postal);
			
		}else{
			
			if (valor==0){
				nuevaLista=agregarPostal(nuevaLista,ayudante->postal);
			}else{
				valor=0;
			}
		}
		
		ayudante=ayudante->siguiente;
	}
//	int result=1;
//	while(result<valor){
//		printf(" el result es %d",result);
//		nuevaLista= agregarPostal(nuevaLista,actual->postal);
//		result++;
//		
//	}
	return nuevaLista;
	
}


void imprimirCola(Cola * cola){
	Cola * ayudante;
	ayudante=cola;
	while(ayudante!=NULL){

			printf("\n El codigo de la postal es: %s",ayudante->colaA.codigoPostal);
			printf("\n El codigo de la postal de intercambio  es:  %s ",ayudante->colaA.codigoPostalCambio);
			printf("\n La cedula del solicitador es: %d ",ayudante->colaA.cedulaSolicitador);
			printf("\n La cedula del Owner es:  %d  ",ayudante->colaA.cedulaOwner);
			printf("\n El precio es:  %d :",ayudante->colaA.precio);
			printf("\n El registro es:   %s",ayudante->colaA.registro);
			printf("\n El tipo de transaccion es:  %s \n ",ayudante->colaA.tipoTransaccion);
			

		ayudante=ayudante->siguiente;
	}
}


//Coleccionistas * creadorSistema(Cola * sistema, Coleccionistas * lista){
//	printf("empieza correctamente\n ");
//	lista = sistemaDeReservacion(sistema, lista);
//	
//	return lista;
//}






Cola * creadorColaSistema(Coleccionistas * lista){
	Coleccionistas * ayudante;
	ayudante = lista;
	Cola * nuevaCola=NULL;
	while(ayudante!=NULL){
		Cola * temporal;
		temporal= ayudante->coleccionista.reservaciones;
		while(temporal!=NULL){
			//printf(" \n Cedula owner coleccionista 1 %d",temporal->colaA.cedulaOwner);
			nuevaCola= agregarElementoCola(nuevaCola,temporal->colaA);
			//printf(" \n Cedula del coleccionista con nuevacOLA 1 %d",nuevaCola->colaA.cedulaSolicitador);
			temporal=temporal->siguiente;
		}
		
		ayudante= ayudante->siguiente;
		
	}
	
	nuevaCola = colaDePrioridad(nuevaCola);
	return nuevaCola;
	
}




Coleccionistas * revisionDeNiveles(Coleccionistas * lista){
	Coleccionistas * ayudante;
	ayudante=lista;
	
			printf("Felicidades coleccionista de cedula %d has ganado un ascenso en las categorias ",ayudante->coleccionista.cedula);
			
			if(strcmp(ayudante->coleccionista.rango,"bronce")==0){
					ayudante->coleccionista.rango="plata";
				}
			if(strcmp(ayudante->coleccionista.rango,"plata")==0){
					ayudante->coleccionista.rango="oro";
				}
				
			if(strcmp(ayudante->coleccionista.rango,"oro")==0){
					ayudante->coleccionista.rango="zafiro";
				}
		
			printf("El nuevo rango es %s",ayudante->coleccionista.rango);
		
		
	
	
	return lista;
}







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

	
	return pila;
	
}

void imprimirPilaVenta(Coleccionistas * lista){
	Coleccionistas *ayudante;
	ayudante=lista;
	Ventas * venta;
	while(ayudante!=NULL){
		venta= ayudante->coleccionista.venta;
		printf("\n Lista de ventas realizada por el coleccionista de cedula %d \n ",ayudante->coleccionista.cedula);
		int contador=0;
		while(venta!=NULL){
			printf("\n Venta #%d",contador);
			printf("\n Cedula comprador : %d ",venta->registro.cedulaComprador);
			printf("\n Precio de venta : %d ",venta->registro.precio);
			printf("\n codigo Postal vendida : %s ",venta->registro.codigo);
			venta=venta->siguiente;
			contador++;
			
		}
		ayudante=ayudante->siguiente;
	}
}



