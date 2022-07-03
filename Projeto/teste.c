#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{
    /*int sexo;
    while (sexo > 3 || sexo < 1)
    {
        printf("Genero");
        printf("\nDigite [1] para masculino\nDigite [2] para feminino\nDigite[3] para outro.");
        scanf("\n%d", &sexo);
    }*/
    // char txt = "Um Dois Tres";  da errado
    // char dxd[100] = "Um Dois Tres Quatro"; deu certo
    char vetor[50];
    printf("Digite uma frase:\n");
    scanf("%s", vetor);
    cifra(vetor, '%');
    printf("A frase sera:%s", vetor);
    return 0;
}
char cifra(char *a, char b)
{
    int i;
    for (i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
        {
            a[i] = b;
        }
    }
}