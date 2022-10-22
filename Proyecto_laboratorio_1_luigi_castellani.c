#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct nodo{
	int dato;
	struct nodo* siguiente;
}nodo;
nodo* primero = NULL;
nodo* ultimo = NULL;

void insertarnodo();
void mostrarlista();
void recorrerlista();
void borrarlista();

int main(){
	
	int opcionMenu = 0;
	do{
	printf("\n ---LISTA CIRCULAR---");
	printf("\n 1. Insertar ---- 2. Mostrar Lista");
	printf("\n 3. Borrar ---- 4. Recorrer la lista");
	printf("\n Seleccione una opcion: ");
	scanf("\n %d", &opcionMenu);
	switch(opcionMenu){
		case 1:
			printf("\n Insertar nodo en la lista");
			insertarnodo();
			break;
		case 2:
			printf("\n Mostrar listaa");
			mostrarlista();
			break;
		case 3:
			printf("\n borrar nodo de la lista");
			borrarlista();
			
			break;
		case 4:
			printf("\n Recorrer nodo en la lista");
			recorrerlista();
			break;
		default:
			printf("\n Opcion invalida\n");
	}
}while(opcionMenu != 4);
	return 0;
}
void insertarnodo(){
	nodo* nuevo = (nodo*) malloc(sizeof(nodo));
	printf("Ingrese el dato del nuevo Nodo:  ");
	scanf("%d",&nuevo->dato);
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = primero;
		ultimo = primero;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = primero;
		ultimo = nuevo;
	}
	printf("\n Nodo ingresado con exito\n\n");
}
void mostrarlista(){
	
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	if(primero!=NULL){
		do{
			printf("\n %d", actual->dato);
			actual = actual->siguiente;			
		}while(actual!= primero);
	}else{
		printf("\n la Lista se encuentra vacia\n");
		
	}
}
void recorrerlista(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	int nodorecorrido = 0, encontrado = 0;
	printf("Ingrese el valor de nodo a buscar: ");
	scanf("%d", &nodorecorrido);
	if(primero!=NULL){
		do{
	if(actual->dato == nodorecorrido){
			printf("\n Nodo con el dato (%d) encontrado\n",nodorecorrido);
			encontrado = 1;
		}
			actual = actual->siguiente;			
		}while(actual!= primero && encontrado != 1);
		
		if(encontrado==0){
			printf("Nodo no encontrado\n");
		}
	}else{
		printf("\n la Lista se encuentra vacia\n");
		
	}
}
void borrarlista(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	nodo * anterior = (nodo*)malloc(sizeof(nodo));
	anterior = NULL;
	int nodorecorrido = 0, encontrado = 0;
	printf("Ingrese el valor de nodo a eliminar: ");
	scanf("%d", &nodorecorrido);
	if(primero!=NULL){
		do{
	if(actual->dato == nodorecorrido){
			printf("\n Nodo con el dato (%d) encontrado\n", nodorecorrido);
			if(actual == primero){
					primero = primero->siguiente;
					ultimo->siguiente = primero;
				}else if(actual==ultimo){
					anterior->siguiente = primero;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
				}
					printf("\n El nodo fue eliminado\n");
					encontrado = 1;
				}
			anterior = actual;
			actual = actual->siguiente;			
		}while(actual!= primero && encontrado != 1);
		
		if(encontrado==0){
			printf("No se encontro el nodo\n");
		}
	}else{
		free(anterior);
	}
}
