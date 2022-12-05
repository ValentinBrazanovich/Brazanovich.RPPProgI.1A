#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char marca[20];
    int tipo;
    float peso;
}eVehiculo;

eVehiculo* newVehiculo();
eVehiculo* newVehiculoParam(int id, char marca[], int tipo, float peso);

int vehiculoSetId(eVehiculo* p, int id);
int vehiculoSetMarca(eVehiculo* p, char* marca);
int vechiculoSetTipo(eVehiculo* p, int tipo);
int vehiculoSetPeso(eVehiculo* p, float peso);

int guardarModoTexto(char* path , eVehiculo* pVehiculo);
int guardarModoBinario(char* path , eVehiculo* pVehiculo);


int main(){
     eVehiculo* p = newVehiculoParam(21000, "Mercedes", 2, 500.0);

     if(p != NULL){

        guardarModoTexto("vehiculoTexto.txt", p);
        guardarModoBinario("vehiculo.bin", p);
     }

    return 0;
}


eVehiculo* newVehiculo(){
    eVehiculo* pNuevoVehiculo = (eVehiculo*) malloc(sizeof(eVehiculo));

    if(pNuevoVehiculo != NULL){
        pNuevoVehiculo->id = 0;
        *(pNuevoVehiculo->marca) = '\0';
        pNuevoVehiculo->tipo = 0;
        pNuevoVehiculo->peso = 0.0;
    }

    return pNuevoVehiculo;
}


eVehiculo* newVehiculoParam(int id, char marca[], int tipo, float peso){
    eVehiculo* pNuevoVehiculo = newVehiculo();

    if(!(vehiculoSetId(pNuevoVehiculo, id)
            && vehiculoSetMarca(pNuevoVehiculo, marca)
            && vechiculoSetTipo(pNuevoVehiculo, tipo)
            && vehiculoSetPeso(pNuevoVehiculo, peso)))
    {
        free(pNuevoVehiculo);
        pNuevoVehiculo = NULL;
    }

    return pNuevoVehiculo;
}

int vehiculoSetId(eVehiculo* p, int id){
    int todoOk = 0;
    if(p != NULL && id >= 20000 && id <= 30000)
    {
        p->id = id;
        todoOk = 1;
    }

    return todoOk;
}

int vehiculoSetMarca(eVehiculo* p, char* marca){
    int todoOk = 0;
    if(p != NULL && marca != NULL && strlen(marca) < 20){
        strcpy(p->marca, marca);
        p->marca[0] = toupper(p->marca[0]);
        todoOk = 1;
    }
    return todoOk;
}

int vechiculoSetTipo(eVehiculo* p, int tipo){
    int todoOk = 0;

    if(p != NULL && tipo > 0){
        p->tipo = tipo;
        todoOk = 1;
    }
}

int vehiculoSetPeso(eVehiculo* p, float peso){
    int todoOk = 0;

    if(p != NULL && peso > 0){
        p->peso = peso;
        todoOk = 1;
    }

    return todoOk;
}


int guardarModoTexto(char* path , eVehiculo* pVehiculo){
	int todoOk = 1;
	int i;
	int longitud;

	int id;
	char marca[20];
	int tipo;
	float peso;


	FILE* pArchivo;
	eVehiculo* vehiculo = NULL;

	if(path != NULL && pVehiculo != NULL){
		pArchivo = fopen(path, "w");
		longitud = sizeof(pVehiculo);

		if(pArchivo != NULL && longitud > 0){
			fprintf(pArchivo,"ID, Nombre completo, Edad, Posicion, Nacionalidad, Id seleccion\n");
			for(i = 0; i < longitud; i++){
                    fprintf(pArchivo,"%d,%s,%d,%f\n",id, marca, tipo, peso);
                    //fwrite(vehiculo, sizeof(eVehiculo), 1, pArchivo);
                    todoOk = 1;
				}
			}
		}

		fclose(pArchivo);

	return todoOk;
}


int guardarModoBinario(char* path , eVehiculo* pVehiculo){
	int todoOk = 0;
	int longitud;

	FILE* pArchivo;
	eVehiculo* vehiculo = NULL;

	if(path != NULL && pVehiculo != NULL){
		pArchivo = fopen(path, "wb");
		longitud = sizeof(pVehiculo);
		if(pArchivo != NULL && longitud > 0){
			for(int i = 0; i < longitud; i++){
				if(vehiculo != NULL){
					fwrite(vehiculo, sizeof(eVehiculo), 1, pArchivo);
					todoOk = 1;
				}
			}
		}

		fclose(pArchivo);
	}

	return todoOk;
}
