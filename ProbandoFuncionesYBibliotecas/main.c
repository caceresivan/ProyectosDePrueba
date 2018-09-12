#include <stdio_ext.h>
#include <stdlib.h>
#include "biblioteca.h"

int main()
{
    int numero;

    getNumero(&numero,"\n Ingrese un numero.","Error, ingrese un numero entre 1 y 9.",1,9,3);
    printf("El numero ingresado es: %d",numero);

    return 0;
}
