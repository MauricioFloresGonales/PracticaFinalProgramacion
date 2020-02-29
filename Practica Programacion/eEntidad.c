#include <stdio.h>
#include <stdlib.h>
#include "eEntidad.h"
#include "string.h"

int set_id(eEntidad*entidad,int id)
{
    int retorno=-1;
    if(entidad!=NULL)
    {
        entidad->id=id;
        entidad=0;
    }
    return retorno;
}

int get_id(eEntidad*entidad, int* id)
{
    int retorno=-1;
    if(entidad!=NULL)
    {
        *id = entidad->id;
        retorno=0;
    }
    return retorno;
}

int set_numerico(eEntidad*entidad,int numero)
{
    int retorno=-1;
    if(entidad!=NULL)
    {
        entidad->numerico=numero;
        retorno=0;
    }
    return retorno;
}

int get_numerico(eEntidad*entidad, int* numerico)
{
    int retorno=-1;
    if(entidad!=NULL)
    {
        *numerico = entidad->numerico;
        retorno = 0;
    }
    return retorno;
}

int set_AlphaNumerico(eEntidad*entidad,char*palabra)
{
    int retorno=-1;
    if(entidad!=NULL)
    {
        strcpy(entidad->AlphaNumerico,palabra);
        retorno=0;
    }
    return retorno;
}

int get_AlphaNumerico(eEntidad*entidad, char* palabra)
{
    int retorno=-1;
    if(entidad!=NULL)
    {
        strcpy(palabra, entidad->AlphaNumerico);
        retorno = 0;
    }
    return retorno;
}

eEntidad* constructor(int id,int numero,char*palabra)
{
    eEntidad* retorno=(eEntidad*)malloc(sizeof(eEntidad));

    if(retorno!=NULL)
    {
        set_id(retorno,id);
        set_numerico(retorno,numero);
        set_AlphaNumerico(retorno,palabra);
    }
    return retorno;
}

eEntidad* constructorPorDefecto(){
    eEntidad* retorno = (eEntidad*)calloc(sizeof(eEntidad),1);

    return retorno;
}

/*int resizeEntidad(eEntidad** entidad, int size){

    int retorno = -1;
    eEntidad** auxEntidad =(eEntidad**)realloc(entidad, sizeof(eEntidad*)*size);

    if(auxEntidad != NULL){
        entidad = auxEntidad;
        retorno = 0;
    }

    return retorno;
}*/

int mostrar(eEntidad*entidad)
{
    int retorno=-1;
    int idAux;
    int numerosAux;
    char palabrasAux[21];

    if(entidad!=NULL)
    {
        get_id(entidad,&idAux);
        get_numerico(entidad, &numerosAux);
        get_AlphaNumerico(entidad, palabrasAux);
        printf("%d - %d - %s",idAux,numerosAux,palabrasAux);
        retorno=0;
    }
    return retorno;
}

int guardarEnBinario(char*path,eEntidad*entidad)
{
    FILE*pfile=fopen(path,"wb");
    int retorno=-1;
    int i;

    if(pfile!=NULL && entidad != NULL)
    {
        fwrite(entidad,sizeof(eEntidad),1,pfile);
        retorno=0;
    }

    fclose(pfile);

    return retorno;
}


int leerEnBinario(char*path)
{
    FILE*pfile=fopen(path,"rb");
    int retorno=-1;
    int i=0;

    eEntidad* aux;

    if(pfile!=NULL)
    {
        while(!feof(pfile))
        {
            i++;
            printf("\n%d\n", i);
            aux = constructorPorDefecto();
            fread(aux,sizeof(eEntidad),1,pfile);
            mostrar(aux);
        }
        retorno=0;
    }

    fclose(pfile);

    return retorno;
}


/*
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile = fopen(path,"rb");
    int retorno = -1;
    Employee* empleado;
    int aux;

    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            empleado = employee_new();
            aux = fread(empleado,sizeof(Employee),1,pFile);
            if(aux == 1)
            {
                ll_add(pArrayListEmployee,empleado);
            }
        }
        fclose(pFile);
    }else{
        printf("NO Existe\n");
    }
    return retorno;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile = fopen(path,"wb");
    int len;
    int i;
    int retorno = -1;

    if(pFile!=NULL)
    {
        Employee* empleado;

        len = ll_len(pArrayListEmployee);

        for(i=0;i<len;i++)
        {
            empleado = ll_get(pArrayListEmployee,i);
            fwrite(empleado,sizeof(Employee),1,pFile);
        }

        fclose(pFile);
        retorno = 0;
    }

    return retorno;
}/*

*/
