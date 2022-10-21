//Ingreso de los files

 #include <stdio.h>
 typedef struct postal Postales;
  typedef struct cole Coleccionistas;
// int numeroDeColeccionistas(Coleccionistas * lista){
// 	Coleccionistas * ayudante;
// 	ayudante =lista;
// 	int numero=0;
// 	while(ayudante!=NULL){
// 		numero++;
// 		ayudante=ayudante->siguiente;
// 		
//	 }
//	 return numero;
// }
 
 
 int main(){
 	FILE * archivoColeccionistas;
 	
 }
 
 
 void registrarPostalestxt(Postales * lista){
 	Postales * ayudante;
 	FILE *archivo;
 	archivo = fopen("Postales.txt","w");
 	while(ayudante!=NULL)
 	if (archivo){
 		fwrite(lista,sizeof(Postales),1,archivo);
 		fclose(archivo);
	 }
 	
 }