#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "menu.h"

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
        char nome[100], senha[20],email[150];
        int idade,numero, sexo;
        float altura, peso, imc;
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
            printf("Nome De Usuario: ");
            fflush(stdin);
            gets(user[n].nome);
            printf("Senha: ");
            fflush(stdin);
            gets(user[n].senha);
            genero:
            printf("genero: ");
            printf("Digite [1] para masculino, digite [2] para feminino ou [3] para outro.");
            fflush(stdin);
            scanf("%d",user[n].sexo);
            if (user[n].sexo == "1" || user[n].sexo == "2" ||user[n].sexo == "3")
            {
                break;
            }else{
                goto genero;
            }
            printf("email: ");
            fflush(stdin);
            gets(user[n].email);
            printf("Numero de Telefone: ");
            scanf("%d",user[n].numero);
            printf("Idade: ");
            fflush(stdin);
            scanf("%d",user[n].idade);
            printf("Altura: ");
            fflush(stdin);
            scanf("%f",user[n].altura);
            printf("Peso: ");
            fflush(stdin);
            scanf("%f",user[n].peso);
            n++;
            break;
        case 2:
            goto inicio;
        default:
            printf("Informacao invalida, digite de novo\n\n");
            goto cadastro1;
        }
        break;
    default:
        system("cls");
        printf("Informacao invalida, escolha novamente!\n\n");
        goto inicio;
    }

    //Criando Menu
    switch (menu())
    {
    case 1:
        system("cls");
        printf("Lista de treino");
        break;
            case 2:
            system("cls");
            printf("Lista de treino");
            break;
                case 3:
                system("cls");
                printf("Lista de treino");
                break;    
                    case 4:
                    system("cls"); 
                    printf("Lista de treino");
                    break;
                        case 0: 
                        system("cls");
                        break;
    default:
        printf("Este valor é invalido!");
        break;
    }
}
