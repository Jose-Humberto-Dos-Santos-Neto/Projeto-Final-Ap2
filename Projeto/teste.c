#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void main()
{
    /*int sexo;
    while (sexo > 3 || sexo < 1)
    {
        printf("Genero");
        printf("\nDigite [1] para masculino\nDigite [2] para feminino\nDigite[3] para outro.");
        scanf("\n%d", &sexo);
    }*/
    struct test
    {
        char *str1;

    } struct teste[2];
    teste[0].str1 = "admin";
    teste[1].str1 = "adm";
    int ret;

    ret = strncmp(str1, str2, 6);

    if (ret > 0)
    {
        printf("str1 e maior");
    }
    else if (ret < 0)
    {
        printf("str2 e maior");
    }
    else
    {
        printf("As duas palavras sao iguais");
    }
}