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
	char registro[99];
	char tipoTransaccion[99];
	
};

typedef struct cola{
	struct Colita colaA;
	struct cola * siguiente;
	
}Cola;
struct Coleccionista{
	int cedula;
	char nombreCompleto[99];
	char fechaNacimiento[99];
	char correoElectronico[99];
	char rango[99];
	int transacciones;
	Postales * obtenidas;
	PostalesRepetidas * repetidas;
	Postales *faltantes;
	Cola * reservaciones;
};

typedef struct nodoCole{
	struct Coleccionista coleccionista;
	//Postales * listaPostales;
	struct nodoCole * siguiente;
	struct nodoCole *anterior;
}Coleccionistas;



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

Postales * eliminarPostalObtenida(Coleccionistas * lista,char codigo[],int  cedula);

int main(){
	Coleccionistas*lista=NULL;
	Postales *postales=NULL;
	struct Coleccionista coleccionista ={ 123456,"JUAN", "2/04/22", "juan@hotmail.com", "BRONZE",0,NULL};
	lista=agregarColeccionista(lista,coleccionista);
//	lista=modificarColeccionistas(lista);
//	consultarCatalogoColeccionistas(lista);
	lista = albumPanini2022(lista,postales);
	//creadorColaGeneral(lista);
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

Coleccionistas * opcionesColeccionistas(Coleccionistas *lista,Postales *postales){
	int valor=1;
	while(valor==1){
		int opcion;
		printf("\n Digite 1 si desea agregar un coleccionista\n ");
		printf("Digite 2 si desea modificar un coleccionista \n");
		printf("Digite 3 si desea consultar la lista de coleccionistas \n");
		printf("Digite 4 si desea ingresar al sistema de postales de los coleccionistas\n");
		printf("Digite 5 si desea ver la lista de repetidas y faltantes del coleccionista \n");
		printf("Digite 6 si desea hacer una reservacion a otro coleccionista de las postales");
		printf("Digite 7 si desea eliminar a un coleccionista");
		printf("Digite 8 si desea salir del sistema de coleccionista \n");
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
		printf("Digite 2 si desea elminar la informacion de algun coleccionista\n");
//		printf("Digite 4 si desea ver la informacion de los coleccionistas\n");
		printf("Digite 3 si desea agregar una lista de postales a un coleccionista\n");
		printf("Digite 4 si desea ver la lista de repetidas y faltantes del coleccionista\n ");
		printf("Digite 5 si desea ingresar al menu de postales generales \n");
		printf("Digite 6 si desea salir del sistema");
		scanf("%d",&opcion);
		if(opcion==1){
			printf("***********Ha elegido Ingresar al sistema de coleccionista**************\n ");
			lista=opcionesColeccionistas(lista,postales);
			
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
	int contador=0;
	nuevaLista=NULL;
	ayudantePostal1=lista;
	while(contador<len){
		if(ayudantePostal1==NULL){
			break;
		}
		int iterador=0;
		//Temporal Forma parte de tipo Postales
		temporal=NULL;
		ayudantePostal2=ayudantePostal1;
		char * postal = ayudantePostal2->postal.codigoPostal;
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
		printf("El iterador es  %d",iterador);
		nuevaLista = agregarListaRepetida(nuevaLista,postalStruct,iterador);
		
		ayudantePostal1=temporal;
		ayudantePostal1=ayudantePostal1->siguiente;
		contador++;
	}
	return nuevaLista;
}


Coleccionistas *generadorPostalesRepetidas(Coleccionistas * lista, Postales * listaPostales){
	Coleccionistas * ayudante;
	Postales * ayudante1;
	ayudante=lista;
	while(ayudante!=NULL){
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
	Postales * ayudante3;
	ayudante= validadorCedulas(lista,cedula);
	if(ayudante->coleccionista.obtenidas==NULL){
		printf("\n El coleccionista no tiene ninguna postal\n ");
		return NULL;
	}
		printf("\n Postal %s \n", ayudante->coleccionista.repetidas->postal.codigoPostal);
	
		printf("Seccion o Equipo %s \n", ayudante->coleccionista.repetidas->postal.seccionOEquipo);
	
		printf("Nombre del jugador, estadio o elemento: %s \n", ayudante->coleccionista.repetidas->postal.nombrePostal);
					
		printf("Precio : %d \n \n", ayudante->coleccionista.repetidas->postal.precioPostal);
		
		printf("Numero de repetidas %d\n ",ayudante->coleccionista.repetidas->repetida);

	
} 




Postales * crearListaFaltantes(Postales * lista, PostalesRepetidas * repetidas){
	if(repetidas==NULL){
		return lista;
	}
	Postales * ayudantePostales,*faltantes;
	faltantes=NULL;
	PostalesRepetidas *ayudantePostalesRepetidas;
	ayudantePostales=lista;
	while(ayudantePostales!=NULL){
		int valor=0;
		ayudantePostalesRepetidas=repetidas;
		
		while(ayudantePostalesRepetidas!=NULL){
			if(strcmp(ayudantePostales->postal.codigoPostal,ayudantePostalesRepetidas->postal.codigoPostal)==0){
				valor=1;
			}
			ayudantePostales=ayudantePostales->siguiente;
		}
		if(valor==0){
			faltantes = agregarPostal(faltantes,ayudantePostales->postal);
		}
		ayudantePostalesRepetidas=ayudantePostalesRepetidas->siguiente;
		
	}
	
	return faltantes;
}

Coleccionistas * generadorListaFaltantes(Coleccionistas * lista,Postales * postales){
	Coleccionistas * ayudante;
	ayudante=lista;
	while(ayudante!=NULL){
		ayudante->coleccionista.faltantes=crearListaFaltantes(postales,ayudante->coleccionista.repetidas);

		ayudante=ayudante->siguiente;
	}
	return lista;
	
}

void imprimidorListaFaltantes(Coleccionistas *lista, int cedula){
	Coleccionistas * ayudante;
	ayudante= validadorCedulas(lista,cedula);
	if(ayudante->coleccionista.faltantes==NULL){
		printf("\n Las Postales no han salido al mercado espera o agrega postales generales \n");
		
	}else{
		printf("\n Postal %s \n", ayudante->coleccionista.faltantes->postal.codigoPostal);
		
		printf("Seccion o Equipo %s \n", ayudante->coleccionista.faltantes->postal.seccionOEquipo);
		
		printf("Nombre del jugador, estadio o elemento: %s \n", ayudante->coleccionista.faltantes->postal.nombrePostal);
						
		printf("Precio : %d \n \n", ayudante->coleccionista.faltantes->postal.precioPostal);
		
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
			lista = generadorPostalesRepetidas(lista,postales);
			postalesRepetidas(lista,cedula);
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
			printf("\n El nivel del coleccionista de cedula %d esta mal ingresado \n ");
			printf("Se le ingresara de ultimo en la cola\n ");
			printf(" PORFAVOR CORREGIR EL ERROR SI DESEA TENER MEJORES OFERTAS\n");
			colaSobrante=agregarElementoCola(colaSobrante,ayudante->colaA);
			
			
		}
		ayudante=ayudante->siguiente;
			
	}
	colaBronce->siguiente=colaSobrante;
	colaPlata->siguiente=colaBronce;
	colaOro->siguiente=colaPlata;
	colaZafiro->siguiente=colaOro;
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
		colita.cedulaSolicitador= ayudanteSolicitador->coleccionista.cedula;
		colita.cedulaOwner= ayudanteFiador->coleccionista.cedula;
		if (opcion==1){
			printf("\n Has escogido realizar un intercambio de postales ");
			printf("Ingrese el codigo de la  postal que desea reservar:");
			scanf("%s",&colita.codigoPostal);
			printf("Ingrese el codigo de la postal que desea dar a cambio");
			scanf("%s",&colita.codigoPostalCambio);
			colita.precio=-1;
			colita.nivel[7]=ayudanteSolicitador->coleccionista.rango;
			colita.tipoTransaccion[10]="intercambio";
			colita.registro[10]="registrada";
			ayudanteFiador->coleccionista.reservaciones=agregarElementoCola(ayudanteFiador->coleccionista.reservaciones,colita);
			printf("Se ha ingresado su Transaccion correctamente");
			ayudanteSolicitador->coleccionista.transacciones++;
		}
		if(opcion==2){
			printf("\n Has escogido realizar una compra de postales ");
			printf("Ingrese el codigo de la  postal que desea reservar:");
			scanf("%s",&colita.codigoPostal);
			printf("Ingrese el precio de la postal que desea comprar");
			scanf("%d",&colita.precio);
			colita.codigoPostalCambio[10]="compra";

			colita.nivel[7]=ayudanteSolicitador->coleccionista.rango;
			colita.tipoTransaccion[10]="compra";
			colita.registro[10]="registrada";
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



//Cola* creadorColaGeneral(Coleccionistas * lista,Cola* nuevaCola, int cedula1){
//	Coleccionistas * ayudante;
//	int cedula;
//	printf("\n Ingrese su cedula \n ");
//	scanf("%d",&cedula);
////	if(cedula1==cedula){
////		printf("\n No puede intercambiar consigo mismo las postales\n ");
////		return NULL;
////	}
//	ayudante= validadorCedulas(lista,cedula);
//	if(ayudante==NULL){
//		printf("La cedula que ingreso no es correcta \n ");
//		return NULL;
//	}
//	struct Colita cola1;
//	cola1.cedula=cedula;
//	cola1.nivel[99]=ayudante->coleccionista.rango;
//	int numero=0;
//	while(numero==0){
//
//		int opcion;
//		printf(" \n Bienvenido al menu de reservacion de postales! \n ");
//		printf("\n Digite 1 si desea realizar un intercambio de postales :D \n ");
//		printf("Digite 2 si desea realizar una compra de postal \n ");
//		printf("Digite 3 si desea salir del menu");
//		scanf("%d",&opcion);
//
//		if(opcion==1){
//			printf("\nIngrese el codigo de la postal que desea reservar\n ");
//			scanf("%s",&cola1.codigoPostal);
//			char * postalRepetida[99];
//			printf("Ingrese la postal que desea dar para intercambio");
//			scanf("%s",&cola1.codigoPostalCambio);	
//			printf("%s",cola1.codigoPostalCambio);		
//			cola1.registro[99]= "registrada";
//			cola1.tipoTransaccion[99]="intercambio";
//			nuevaCola = agregarElemento(nuevaCola,cola1);	
//		}
//		if(opcion==2){
//			printf("\nIngrese el codigo de la postal que desea reservar\n ");
//			scanf("%s",&cola1.codigoPostal);
//			int precio;
//			printf("\n Ingrese el precio por el que desea conseguir la postal\n ");
//			scanf("%d",&cola1.precio);
//			printf("%d",cola1.precio);
//			cola1.registro[99] = "registrada";
//			cola1.tipoTransaccion[99]="compra";
//			//cola1.codigoPostalCambio[99]="";
//			printf("Funciona el ingreso");
//			nuevaCola = agregarElemento(nuevaCola,cola1);
//			printf("Falla el ingreso");
//			
//		}
//		if(opcion==3){
//			printf("gracias por utilizar el sistema de reserva de postales :D");
//			break;
//		}
//		else{
//			printf("Ingrese una opcion valida");
//		}
//	}
//	
//	nuevaCola =colaDePrioridad(nuevaCola);
//	printf("Termina el ciclo");
//	
//	return nuevaCola;
//	
//	
//}




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

//Coleccionistas * menuGeneralCola(Coleccionistas * lista){
//	int numero=0;
//	while(numero==0){
//		int opcion;
//		printf("Bienvenido al sistema de reservacion de postales\n ");
//		printf("Digite 1 si desea realizar el proceso para reservar una postal\n ");
//		printf("Digite 2 si desea salir del sistema de reservacion de postales");
//		scanf("%d",&opcion);
//		if(opcion==1){
//			int cedulaColeccionista;
//			Coleccionistas * ayudante;
//			printf("Ingrese la cedula del coleccionista con el que desea realizar el intercambio");
//			scanf("%d",&cedulaColeccionista);
//			ayudante=validadorCedulas(lista,cedulaColeccionista);
//			ayudante->coleccionista.reservaciones=creadorColaGeneral(lista,ayudante->coleccionista.reservaciones,cedulaColeccionista);
//			//imprimirCola(ayudante);
//		}
//			
//		if(opcion==2){
//			printf("\n Gracias por usar el sistema de reservacion de postales");
//			break;
//		}
//		else{
//			printf("Ingrese una opcion valida");
//		}
//		
//		
//	}
//	return lista;
//
//}


//void imprimirCola(Coleccionistas * lista){
//	printf("Estado: %s ", lista->coleccionista.reservaciones->colaA.registro);
//	printf("Tipo de transaccion %s",lista->coleccionista.reservaciones->colaA.tipoTransaccion);
//	
//}



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

//Cola * creadorSistema(Coleccionistas * lista,Cola * sistema){
//	Coleccionistas * ayudante;
//	ayudante=lista;
//	while(ayudante!=NULL){
//		if(ayudante->coleccionista.reservaciones!=NULL){
//			agregarElementoCola(sistema,ayudante->coleccionista.reservaciones->colaA);
//		}
//		ayudante=ayudante->siguiente;
//	}
//	return sistema;
//	
//}



Cola * ordenarCola(Cola * sistema){
	
	sistema = colaDePrioridad(sistema);
	Cola * ayudante= sistema;
	while(ayudante!=NULL){
		if(strcmp("rechazada",ayudante->colaA.registro)==0||strcmp("aprobada",ayudante->colaA.registro)==0){
			ayudante->siguiente;
		}else{
			break;
		}
	}
	if(ayudante==NULL){
		printf("No hay reservaciones en la cola pendientes");
		return sistema;
	}
	return ayudante;
		
}


Cola * validarCodigoPostal(Cola* sistema, Coleccionistas * lista){
	Cola * ayudante;
	ayudante=sistema;
	int valor=0;
	while(ayudante!=NULL){
		Coleccionistas * ayudanteColeccionista;
		ayudanteColeccionista = validadorCedulas(lista,ayudante->colaA.cedulaOwner);
		if(checarPostales(lista,ayudante->colaA.codigoPostal,ayudante->colaA.cedulaOwner)==0){
			printf("El coleccionista owner tiene la postal disponible \n");
			if(strcmp(ayudante->colaA.tipoTransaccion,"intercambio")==0){
				if(checarPostales(lista,ayudante->colaA.codigoPostalCambio,ayudante->colaA.cedulaSolicitador)==0){
					
					lista = intercambiarPostales(lista,ayudante->colaA.cedulaOwner, ayudante->colaA.cedulaSolicitador,ayudante->colaA.codigoPostal,ayudante->colaA.codigoPostalCambio);
					
					lista= eliminarPostalObtenida(lista,ayudante->colaA.codigoPostal,ayudante->colaA.cedulaOwner);
					lista= eliminarPostalObtenida(lista,ayudante->colaA.codigoPostalCambio,ayudante->colaA.cedulaSolicitador);
					ayudanteColeccionista->coleccionista.reservaciones->colaA.registro[12]= "aprobada";
					valor=1;
				}else{
					printf("El coleccionista solicitador  de cedula %d no tiene la postal disponible para el intercambio  \n ",ayudante->colaA.cedulaSolicitador);
					
					ayudanteColeccionista->coleccionista.reservaciones->colaA.registro[12]= "rechazada";
					
				}
			}
			
			if(strcmp(ayudante->colaA.tipoTransaccion,"compra")==0){
				lista =comprarPostal(lista, ayudante->colaA.codigoPostal,ayudante->colaA.precio, ayudante->colaA.cedulaOwner, ayudante->colaA.cedulaSolicitador);
				
			}
			
		}else{
			printf("El coleccionista Owner de cedula %d no tiene la postal disponible para el intercambio  \n ",ayudante->colaA.cedulaOwner);

			ayudanteColeccionista->coleccionista.reservaciones->colaA.registro[12]= "rechazada";
			
		}
		ayudante=ayudante->siguiente;
		
	}
	
	
	
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
//Coleccionistas * restarNumeroPostal(Coleccionistas * lista, char  codigo[],int cedula){
//	Coleccionistas * ayudante= lista;
//	ayudante= validadorCedulas(lista,cedula);
//	PostalesRepetidas * ayudantePostales;
//	ayudantePostales= ayudante->coleccionista.repetidas;
//	while(ayudantePostales!=NULL){
//		if(strcmp(ayudante->postal.codigoPostal,codigo)==0){
//			ayudantePostales->repetida-=1;
//			break;
//		}
//		ayudantePostales=ayudantePostales->siguiente;
//	}
//	
//	return lista;
//}

Coleccionistas * intercambiarPostales(Coleccionistas * lista,int cedulaOwner, int cedulaSolicitador, char codigoOwner[],char codigoSolicitador[]){
	Coleccionistas *ayudanteOwner, * ayudanteSolicitador;
	Postales * postalOwner, *postalSolicitador;
	ayudanteOwner= validadorCedulas(lista,cedulaOwner);
	ayudanteSolicitador = validadorCedulas(lista,cedulaSolicitador);
	postalOwner =  encontrarPostal(ayudanteOwner->coleccionista.obtenidas, codigoOwner);
	postalSolicitador=encontrarPostal(ayudanteSolicitador->coleccionista.obtenidas, codigoSolicitador);
	ayudanteSolicitador->coleccionista.obtenidas= agregarPostal(ayudanteSolicitador->coleccionista.obtenidas,postalOwner->postal);
	ayudanteOwner->coleccionista.obtenidas= agregarPostal(ayudanteOwner->coleccionista.obtenidas,postalSolicitador->postal);
	
	return lista;

}


Postales * encontrarPostal(Postales * lista, char codigo[]){
	Postales * ayudante;
	ayudante = lista;
	while(ayudante!=NULL){
		if(strcmp(ayudante->postal.codigoPostal,codigo)==0){
			return ayudante;
		}
		ayudante=ayudante->siguiente;
	}
	
}

Coleccionistas * comprarPostal(Coleccionistas * lista, char codigo[],int precio, int cedulaOwner,int cedulaSolicitador){
	Coleccionistas * ayudanteOwner,*ayudanteSolicitador;
	ayudanteOwner= validadorCedulas(lista,cedulaOwner);
	ayudanteSolicitador=validadorCedulas(lista,cedulaSolicitador);
	Postales * ayudantePostal;
	ayudantePostal=encontrarPostal(ayudanteOwner->coleccionista.obtenidas,codigo);
	if(ayudantePostal->postal.precioPostal-5<=precio){
		ayudantePostal->postal.precioPostal= precio;
		ayudanteSolicitador->coleccionista.obtenidas= agregarPostal(ayudanteSolicitador->coleccionista.obtenidas,ayudantePostal->postal);
		ayudanteOwner->coleccionista.obtenidas=eliminarPostalObtenida(ayudanteOwner->coleccionista.obtenidas,codigo,cedulaOwner);
		ayudanteOwner->coleccionista.reservaciones->colaA.registro[12]="aprobada";
		
	}else{
		ayudanteOwner->coleccionista.reservaciones->colaA.registro[12]="rechazada";
	}
	return lista;
}



Postales * eliminarPostalObtenida(Coleccionistas * lista,char codigo[],int  cedula)
{
	Coleccionistas * ayudante;
	ayudante=validadorCedulas(lista,cedula);
	Postales * ayudantePostales,*nuevaLista;
	ayudantePostales =  ayudante->coleccionista.obtenidas;
	nuevaLista=NULL;
	int valor =0;
	while(ayudantePostales!=NULL){
		if(strcmp(ayudantePostales->postal.codigoPostal,codigo)!=0){
			nuevaLista = agregarPostal(nuevaLista,ayudantePostales->postal);
			valor++;
			
		}
		if(valor>0){
			nuevaLista = agregarPostal(nuevaLista,ayudantePostales->postal);
		}
		ayudantePostales=ayudantePostales->siguiente;
	}
	ayudante->coleccionista.obtenidas= nuevaLista;
	return lista;
	
}

