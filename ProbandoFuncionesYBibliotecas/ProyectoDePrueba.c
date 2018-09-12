#include <stdio_ext.h>
#include <stdlib.h>
#include "biblioteca.h"

static int esNumerica(char*cadena);
static int getInt(int*pResultado);
int getNumero(int* pResultado,char*mensaje,char*mensajeError,int min,int max,int reintentos)
{
    int retorno;
    int numero;

    while(reintentos>0)
    {
        printf(mensaje);
        if(getInt(&numero)==1)
        {
            if(numero<=max && numero>=min)
                break;
        }
            __fpurge(stdin);
            reintentos--;
            printf(mensajeError);
    }
    if(reintentos==0)
    {
        retorno=-1;
    }
    else
    {
        retorno=0;
        *pResultado=numero;
    }
    return retorno;
}
static int getInt(int*pResultado)
{
    int retorno=-1;
    char buffer[64];
    scanf("%s",buffer);

    if(esNumerica(buffer))
    {
        *pResultado=atoi(buffer);
        retorno=1;
    }
    return retorno;
}
static int esNumerica(char*cadena)
{
    int retorno=-1;
    int i=0;

    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(cadena[i]<'0' || cadena[i]>'9')
            {
                break;
            }
            i++;
        }
        if(cadena[i]=='0')
        {
            retorno=1;
        }
    }
    return retorno;
}
