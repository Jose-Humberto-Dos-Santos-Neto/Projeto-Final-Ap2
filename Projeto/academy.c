#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main()
{
    int cadAdm = 0;
    int prosseguir, prosseguir1;
inicio:
    system("cls");
    printf("                                                   Seja Bem Vindo!\n");
    printf("------------------------------------------------------------------------------------------------------------------------");
    printf("\n1) Administrador ");
    printf("\n2) Usuario ");
    printf("\n\nCaso queira prosseguir como administrador digite [1].\nCaso queira prosseguir como usuario digite [2].\n");
    int login;
    scanf("%d", &login);
    char senhaAdm;
    int n = 0;
    struct usuario
    {
        char nome[100], sexo[50], senha[20];
        int idade;
        float altura, peso;
    } user[n];
    switch (login)
    {
    case 1:
        if (cadAdm == 0)
        {
            system("cls");
        cadastro:
            printf("Cadastro de Administrador");
            printf("\n\nCaso queira prosseguir, digite [1].\nCaso queira voltar digite [2].\n");
            scanf("%d", &prosseguir);
            switch (prosseguir)
            {
            case 1:
                system("cls");
                printf("ID: admin\n");
                printf("Senha: ");
                scanf("%s", &senhaAdm);
                cadAdm = 1;
                break;
            case 2:
                goto inicio;
            default:
                printf("Informacao invalida, digite de novo\n\n");
                goto cadastro;
            }
            if (cadAdm == 1)
            {
                printf("deu certo");
            }
        }
        break;
    case 2:
    cadastro1:
        system("cls");
        printf("Cadastro de Usuario");
        printf("\n\nCaso queira prosseguir, digite [1].\nCaso queira voltar digite [2].\n");
        scanf("%d", &prosseguir1);
        switch (prosseguir1)
        {
        case 1:
            system("cls");
            printf("ID: ");
            fflush(stdin);
            gets(user[n].nome);
            printf("Senha: ");
            fflush(stdin);
            gets(user[n].senha);
            n++;
            break;
        case 2:
            goto inicio;
        default:
            printf("Informacao invalida, digite de novo\n\n");
            goto cadastro1;
        }
    default:
        system("cls");
        printf("Informacao invalida, escolha novamente!\n\n");
        goto inicio;
    }
}
