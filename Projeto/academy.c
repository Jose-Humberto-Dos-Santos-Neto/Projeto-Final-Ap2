#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "listadetreino.h" 
#include "fichadent.h" 
#include "clcimc.h"
#include "perguntas.h"

int main(void)
{
    int opmenu, escolha, adm = 0;
    int prosseguir, prosseguir1, opcaologin;
    int login;
    int n = 0;
    char loginUsuario[100], senhaUsuario[20];
inicio:
    system("cls");
    printf("                                                   Seja Bem Vindo!\n");
    printf("------------------------------------------------------------------------------------------------------------------------");
    printf("\n1) Login ");
    printf("\n2) Cadastre-se ");
    printf("\n\nCaso queira prosseguir como administrador digite [1].\nCaso queira prosseguir como usuario digite [2].\n");
    scanf("%d", &login);
    struct usuario
    {
        char nome[100], senha[20], email[150];
        int idade, numero, sexo;
        float altura, peso, imc;
    } user[3];
    struct cont
    {
        char nome[150], funcao[45];
        int numero;
    } ct[7];
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
        // LOGIN ADM: EMAIL: ADM ou adm Senha 123
        loginUS:
            system("cls");
            printf("| Email: \n");
            fflush(stdin);
            gets(loginUsuario);
            printf("| Senha: \n");
            fflush(stdin);
            gets(senhaUsuario);
            for (int i = 0; i < 3; i++)
            {
                if (loginUsuario == user[i].email)
                {
                    if (senhaUsuario == user[i].senha)
                    {
                        n = i;
                        goto menuprincipal;
                    }
                    else
                    {
                        system("cls");
                        printf("\nSenha nao encontrado!\t\tTente novamente");
                        goto loginUS;
                    }
                }
                else
                {
                    printf("\nSenha nao encontrado\nTente novamente");
                    system("cls");
                    goto loginUS;
                }
            }
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
        printf("\n\nDigite [1] para prosseguir.\t\t\tDigite [2] para voltar.\n");
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
            // Escolhen
            while (user[n].sexo > 3 |do Genero| user[n].sexo < 1)
            {
                printf("Genero");
                printf("\n|Digite [1] para masculino\t|Digite [2] para feminino\t|Digite [3] para prefiro nao informa.");
                scanf("\n%d", &user[n].sexo);
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
    FILE *file;
    file = fopen("ListaDeUsuario.txt", "a+");
    fprintf(file, "| Nome: %s\t\t\t| E-mail: %s\n| Idade: %d\t\t\t| Numero: %d\t\t\t\n", user[0].nome, user[0].email, user[0].idade, user[0].numero);
    if (user[n].sexo == 1)
    {
        fprintf(file, "| Genero: Masculino\t\t\t");
    }
    else if (user[n].sexo == 2)
    {
        fprintf(file, "| Genero: Feminino\t\t\t");
    }
    else
    {
        fprintf(file, "| Genero: Nao definido\t\t\t");
    }
    fprintf(file, "| Altura: %.2f\t\t\t| Peso: %.2f\t\t\t ", user[0].altura, user[0].peso);
    int clcIMC = clcimc(user[n].peso, user[n].altura);
    switch (clcIMC)
    {
    case 1:
        fprintf(file, "| IMC: Obesidade grau III\n");
        break;
    case 2:
        fprintf(file, "| IMC: Obesidade grau II\n");
        break;
    case 3:
        fprintf(file, "| IMC: Obesidade grau I\n");
        break;
    case 4:
        fprintf(file, "| IMC: Sobre peso\n");
        break;
    case 5:
        fprintf(file, "| IMC: Peso normal\n");
        break;
    case 6:
        fprintf(file, "| IMC: Abaixo do peso\n");
        break;
    default:
        break;
    }
    fprintf(file, "\n-----------------------------------------------------------------------------------------\n");
    fclose(file);
    // Criando Menu
    char menutreino;
menuprincipal:
    switch (menu())
    {
    case 1:
        system("cls");
    ltdetreino:
        printf("\n|Qual Treino quer realizar? \n|A - Peitoral\n|B - Costas\n|C - Pernas\n|D - Ombros\n");
        fflush(stdin);
        scanf("%c", &menutreino);
        listadetreino(&menutreino);
        printf("\nDeseja voltar\n[0] Sim [1] Nao\t");
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
        fichadent();
        printf("\nDeseja voltar\n[0] Sim [1] Nao\t");
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
        if (adm == 1)
        {
            system("cls");
            printf("\n| Menu |\n");
            printf("|[01] Adicionar contatos|\n");
            printf("|[02] Ver Lista|\n");
            scanf("%d", &escolha);
            if (escolha == 2)
            {
                adm = 0;
                goto contatos;
            }
            else if (escolha == 1)
            {
                for (int i = 0; i < 7; i++)
                {
                    system("cls");
                    fflush(stdin);
                    printf("\t\t|Nome: ");
                    gets(ct[i].nome);
                    fflush(stdin);
                    printf("\t\t|Funcao: ");
                    gets(ct[i].funcao);
                    fflush(stdin);
                    printf("\t\t|Numero: ");
                    scanf("%d", &ct[i].numero);
                    fflush(stdin);
                }
            }
            else
            {
                printf("\nValor Invalido\n");
                system("cls");
                goto contatos;
            }
        }
        else
        {
            printf("\n| Lista de contatos |");
            for (int i = 0; i < 7; i++)
            {
                printf("\n|Nome: %s\t |Numero: %d\t |Funcao: %s", ct[i].nome, ct[i].numero, ct[i].funcao);
            }
        }
        printf("\nDeseja voltar\n[0] Sim [1] Nao\t");
        scanf("%d", &opmenu);
        if (opmenu == 1)
        {
            goto contatos;
        }
        else if (opmenu == 0)
        {
            system("cls");
            goto menuprincipal;
        }
        break;
    case 4:
    informacoes:
        system("cls");
        printf("\nSuas informacoes:\n");
        printf("\n| Nome: %s\t\t\t| E-mail: %s\n| Idade: %d\t\t\t| Numero: %d\t\t\t", user[n].nome, user[n].email, user[n].idade, user[n].numero);
        if (user[n].sexo == 1)
        {
            printf("| Genero: Masculino\n");
        }
        else if (user[n].sexo == 2)
        {
            printf("| Genero: Feminino\n");
        }
        else
        {
            printf("| Genero: Nao definido\n");
        }

        printf("| Altura: %.2f\t\t\t| Peso: %.2f\t\t\t", user[n].altura, user[n].peso);
        switch (clcIMC)
        {
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
        printf("\nDeseja voltar\n[0] Sim [1] Nao\t");
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