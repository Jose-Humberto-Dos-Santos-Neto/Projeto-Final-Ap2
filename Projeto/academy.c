#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "listadetreino.h"
#include "perguntas.h"
#include "clcimc.h"
int opmenu;
void main()
{
    int cadAdm = 0;
    int prosseguir, prosseguir1, opcaologin;
inicio:
    system("cls");
    printf("                                                   Seja Bem Vindo!\n");
    printf("------------------------------------------------------------------------------------------------------------------------");
    printf("\n1) Administrador ");
    printf("\n2) Usuario ");
    printf("\n\nCaso queira prosseguir como administrador digite [1].\nCaso queira prosseguir como usuario digite [2].\n");
    int login;
    scanf("%d", &login);
    int n;
    struct usuario
    {
        char nome[100], senha[20], email[150];
        int idade, numero, sexo;
        float altura, peso, imc;
    }user[3];
    char loginUsuario[100], senhaUsuario[20];
    switch (login)
    {
    case 1:
        system("cls");
    cadastro:
        printf("| Login de usuario|");
        printf("\n\nCaso queira prosseguir, digite [1].\nCaso queira voltar digite [2].\n");
        scanf("%d", &prosseguir);
        switch (prosseguir)
        {
        case 1:
        loginUS:
            system("cls");
            printf("| Email: \n");
            gets(loginUsuario);
            fflush(stdin);
            printf("| Senha: \n");
            gets(senhaUsuario);
            for (int i = 0; i < 3; i++)
            {
                if (loginUsuario == user[i].email)
                {
                    if (senhaUsuario == user[i].senha)
                    {
                        n = i;
                        break;
                    }
                    else
                    {
                        printf("Senha nao encontrado\nTente novamente ");
                        goto loginUS;
                    }
                }
                else
                {
                    printf("Usuario nao encontrado Ou Email Incorreto\nTente novamente [1] ou se cadastre [2]\n");
                    scanf("%d", &opcaologin);
                    if (opcaologin == 1)
                    {
                        goto loginUS;
                    }
                    else if (opcaologin == 2)
                    {
                        goto cadastro1;
                    }
                    else
                    {
                        printf("Valor invalido");
                        goto loginUS;
                    }
                }
            }
            break;

        case 2:
            goto inicio;

        default:
            printf("Informacao invalida, digite de novo\n\n");
            goto cadastro;
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
            printf("\n|Nome De Usuario: ");
            fflush(stdin);
            gets(user[n].nome);
            printf("\n|Senha: ");
            fflush(stdin);
            gets(user[n].senha);
        // Escolhendo Genero
        genero:
            printf("\n|genero: ");
            printf("\n|ESCOLHA|[1] para masculino|\t |[2] para feminino|\t |[3] Prefiro nao informar|\n");
            fflush(stdin);
            scanf("%d", &user[n].sexo);
            if (user[n].sexo == 1 || user[n].sexo == 2 || user[n].sexo == 3)
            {
            }
            else
            {
                system("cls");
                printf("\n|Digite novamente, informacao invalida.");
                goto genero;
            }
            printf("\n|Email: ");
            fflush(stdin);
            gets(user[n].email);
            printf("\n|Numero de Telefone: ");
            scanf("%d", &user[n].numero);
            printf("\n|Idade: ");
            fflush(stdin);
            scanf("%d", &user[n].idade);
            printf("\n|Altura: ");
            fflush(stdin);
            scanf("%f", &user[n].altura);
            printf("\n|Peso: ");
            fflush(stdin);
            scanf("%f", &user[n].peso);
            break;
        case 2:
            goto inicio;
        default:
            printf("\n|Informacao invalida, digite de novo\n\n");
            goto cadastro1;
        }
        break;
    default:
        system("cls");
        printf("Informacao invalida, escolha novamente!\n\n");
        goto inicio;
    }

// Criando Menu
menuprincipal:
    switch (menu())
    {
    case 1:
        system("cls");
    ltdetreino:
        printf("Lista de treino");
        switch (listadetreino())
        {
        case 1:
            break;
        case 2:
            break;
        default:
            break;
        }
        printf("\nDeseja voltar\n[0] Sim [1] Não");
        int opmenu;
        scanf("%d", &opmenu);
        if (opmenu == 1)
        {
            goto ltdetreino;
        }
        else if (opmenu == 0)
        {
            goto menuprincipal;
        }
        break;
    case 2:
        system("cls");
    fcdenutricao:
        printf("Ficha de nutricao");
        printf("\nDeseja voltar\n[0] Sim [1] Não");
        int opmenu;
        scanf("%d", &opmenu);
        if (opmenu == 1)
        {
            goto fcdenutricao;
        }
        else if (opmenu == 0)
        {
            goto menuprincipal;
        }
        break;

    case 3:
        system("cls");
    contatos:
        printf("\n| Lista de contatos |\n");
        printf("\nDeseja voltar\n[0] Sim [1] Não");
        int opmenu;
        scanf("%d", &opmenu);
        if (opmenu == 1)
        {
            goto contatos;
        }
        else if (opmenu == 0)
        {
            goto menuprincipal;
        }
        break;
    case 4:
    informacoes:
        system("cls");
        printf("\nSuas informacoes:\n");
        /*
        printf("\n| Nome: %s\t\t\t| E-mail: %s\n| Idade: %d\t\t\t| Numero: %d\t\t\t", user[n].nome, user[n].email, user[n].idade, user[n].numero);
        if (user[n].sexo == 1)
        {
            printf("| Genero: Masculino\n");
        }
        else if (user[n].sexo)
        {
            printf("| Genero: Feminino\n");
        }
        else
        {
            printf("| Genero: Nao definido\n");
        }*/
        /*CALCULANDO IMC
        //  IMC = Massa (kg) ÷ Altura (m)².
            Menor que 18,5 = abaixo do peso.
            Entre 18,5 e 24,9 = peso normal.
            Entre 25 e 29,9 = sobrepeso.
            Entre 30 e 34,99 = obesidade grau I.
            Entre 35 e 39,99 = obesidade grau II (severa).
            Acima de 40 = obesidade grau III (mórbida).*/
       /* switch (clcimc.h(&user[n].peso,&user[n].altura))
        {
        
        printf("| Altura: %f\t\t\t| Peso: %f\t\t\t", user[n].altura, user[n].peso);
        case 1:
            printf("| IMC: Obesidade grau III\n");
        break;
        case 2:
            printf("| IMC: Obesidade grau II\n");
        break;
        case 3:
            printf("| IMC: Obesidade grau I\n");
        break;
        case 4:
            printf("| IMC: Sobre peso\n");
       break;
        case 5:
            printf("| IMC: Peso normal\n");
        break;
        case 6:
            printf("| IMC: Abaixo do peso\n");
        break;
            default:
                break;

        }
        printf("\nDeseja voltar\n[0] Sim [1] Não");
        int opmenu;
        scanf("%d", &opmenu);
        if (opmenu == 1)
        {
            goto informacoes;
        }
        else if (opmenu == 0)
        {
            system("cls");
            goto menuprincipal;
        }*/
        break;

    case 0:
        // Sair do Sistema
        system("cls");
        break;

    default:
        printf("Este valor é invalido!");
        break;
    }
}
