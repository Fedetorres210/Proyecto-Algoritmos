


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
Postales * accionDePostales(Postales*lista);
Postales * modificarPostal(Postales * lista);
Postales * eliminarPostal(Postales* lista);