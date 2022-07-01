#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void main()
{
    int sexo;
    do
    {
        printf("Genero");
        printf("\nDigite [1] para masculino\n digite [2] para feminino\n [3] para outro.");
        fflush(stdin);
        scanf("\n%d", &sexo);
    } while (sexo == 1 || sexo == 2 || sexo == 3);
}