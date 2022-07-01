#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "listadetreino.h"
#include "perguntas.h"

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
    int n;
    char opcaologin;
    struct usuario
    {
        char nome[100], senha[20], email[150];
        int idade, numero, sexo;
        float altura, peso, imc;
    } user[3];
    char loginUsuario[100], senhaUsuario[20];
    switch (login)
    {
    case 1:
        system("cls");
    cadastro:
        printf("Login de usuario");
        printf("\n\nCaso queira prosseguir, digite [1].\nCaso queira voltar digite [2].\n");
        scanf("%d", &prosseguir);
        switch (prosseguir)
        {
        case 1:
        loginUS:
            system("cls");
            printf("Email: ");
            gets(loginUsuario);
            fflush(stdin);
            printf("Senha: ");
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
                        printf("Senha io nao encontrado\nTente novamente ");
                        goto loginUS;
                    }
                }
                else
                {
                    printf("Usuario nao encontrado\nTente novamente [1] ou se cadastre [2]\n");
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
            printf("Nome De Usuario: ");
            fflush(stdin);
            gets(user[n].nome);
            printf("Senha: ");
            fflush(stdin);
            gets(user[n].senha);
        // Escolhendo Genero
        genero:
            printf("genero: ");
            printf("Digite [1] para masculino, digite [2] para feminino ou [3] para outro.");
            fflush(stdin);
            scanf("%d", &user[n].sexo);
            if (user[n].sexo == 1 || user[n].sexo == 2 || user[n].sexo == 3)
            {
            }
            else
            {
                system("cls");
                printf("Digite novamente, informacao invalida.");
                goto genero;
            }
            printf("email: ");
            fflush(stdin);
            gets(user[n].email);
            printf("Numero de Telefone: ");
            scanf("%d", &user[n].numero);
            printf("Idade: ");
            fflush(stdin);
            scanf("%d", &user[n].idade);
            printf("Altura: ");
            fflush(stdin);
            scanf("%f", &user[n].altura);
            printf("Peso: ");
            fflush(stdin);
            scanf("%f", &user[n].peso);
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

// Criando Menu
menuprincipal:
    switch (menu())
    {
    case 1:
        system("cls");
    ltdetreino:
        printf("Lista de treino");
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
        // Inserir Aqui
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
            goto contatos;
        }
        else if (opmenu == 0)
        {
            goto menuprincipal;
        }
        break;
    case 4:
    /*   FALTA INSERIR QUEM VAI SER o user.[n]!!!!!!!!!!!!
         FALTA INSERIR QUEM VAI SER o user.[n]!!!!!!!!!!!!
         FALTA INSERIR QUEM VAI SER o user.[n]!!!!!!!!!!!!
         FALTA INSERIR QUEM VAI SER o user.[n]!!!!!!!!!!!!  */
    informacoes:
        system("cls");
        printf("\nSuas informacoes:\n");
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
        }
        /*CALCULANDO IMC
        //  IMC = Massa (kg) ÷ Altura (m)².
            Menor que 18,5 = abaixo do peso.
            Entre 18,5 e 24,9 = peso normal.
            Entre 25 e 29,9 = sobrepeso.
            Entre 30 e 34,99 = obesidade grau I.
            Entre 35 e 39,99 = obesidade grau II (severa).
            Acima de 40 = obesidade grau III (mórbida).*/
        user[n].imc = user[n].peso / (user[n].peso * user[n].peso);
        printf("| Altura: %f\t\t\t| Peso: %f\t\t\t", user[n].altura, user[n].peso);
        if (user[n].imc = > 40)
        {
            printf("| IMC: Obesidade grau III\n");
        }
        else if (35 <= user[n].imc <= 39.99)
        {
            printf("| IMC: Obesidade grau II\n");
        }
        else if (30 <= user[n].imc <= 34.99)
        {
            printf("| IMC: Obesidade grau I\n");
        }
        else if (25 <= user[n].imc <= 29.99)
        {
            printf("| IMC: Sobre peso\n");
        }
        else if (18.5 <= user[n].imc <= 24.9)
        {
            printf("| IMC: Peso normal\n");
        }
        else
        {
            printf("| IMC: Abaixo do peso\n");
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
        }
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
