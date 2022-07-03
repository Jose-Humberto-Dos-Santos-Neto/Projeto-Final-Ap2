#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "listadetreino.h"
#include "fichadent.h"
#include "ctt.h"
#include "clcimc.h"
#include "criptografia.h"

int main(void)
{
    int opmenu;
    int prosseguir, prosseguir1, opcaologin;
    int login,calcIMC;//, imcIA;
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
        char nome[100], senha[20], email[150], numero[30];
        int idade, sexo;
        float altura, peso;
    } user[3];

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
                        printf("\n|Senha nao encontrado!\t\t|Tente novamente");
                        goto loginUS;
                    }
                }
                else
                {
                    printf("\n|Senha nao encontrado\n|Tente novamente");
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
            // Escolher genero
            while (user[n].sexo > 3 || user[n].sexo < 1)
            {
                printf("Genero");
                printf("\n|Digite [1] para masculino\t|Digite [2] para feminino\t|Digite [3] para prefiro nao informa.");
                scanf("\n%d", &user[n].sexo);
            }
            printf("\n|Email: ");
            fflush(stdin);
            gets(user[n].email);
            printf("\n|Numero de Telefone: ");
            fflush(stdin);
            gets(user[n].numero);
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
        printf("Informacao invalida novamente!\n\n");
        goto inicio;
    }
    /////Criando Arquivo com os dados dos usuarios
    FILE *file;
    file = fopen("ListaDeUsuario.txt", "a+");
    cript(user[n].senha);
    fprintf(file, "| Nome: %s\t\t\t| E-mail: %s\t\t\t|Senha: %s\n| Idade: %d\t\t\t| Numero: %s\t\t\t\n", user[n].nome, user[n].email, user[n].senha, user[n].idade, user[n].numero);
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
    fprintf(file, "| Altura: %.2f\t\t\t| Peso: %.2f\t\t\t ", user[n].altura, user[n].peso);
    calcIMC = clcimc(user[n].peso, user[n].altura);
    switch (calcIMC)
    {
    case 1:
        fprintf(file, "| IMC: Obesidade grau III\n");
        break;
    case 2:
        fprintf(file, "| IMC: Obesidade grau II\n");
        //imcIA = 2;
        break;
    case 3:
        fprintf(file, "| IMC: Obesidade grau I\n");
        //imcIA = 3;
        break;
    case 4:
        fprintf(file, "| IMC: Sobre peso\n");
        //imcIA = 4;
        break;
    case 5:
        fprintf(file, "| IMC: Peso normal\n");
        //imcIA = 5;
        break;
    case 6:
        fprintf(file, "| IMC: Abaixo do peso\n");
        //imcIA = 6;
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
        printf("\n|Qual Treino quer realizar? \n|A - Peitoral|\n|B - Costas|\n|C - Pernas|\n|D - Ombros|\n");
        fflush(stdin);
        scanf("%c", &menutreino);
        listadetreino(&menutreino);
        printf("\n\nDeseja voltar\n[1] Sim [2] Nao\t");
        scanf("%d", &opmenu);
        if (opmenu == 2)
        {
            goto ltdetreino;
        }
        else if (opmenu == 1)
        {
            goto menuprincipal;
        }
        break;
    case 2:
        system("cls");
    fcdenutricao:
        fichadent();
        printf("\n\nDeseja voltar\n[1] Sim [2] Nao\t");
        scanf("%d", &opmenu);
        if (opmenu == 2)
        {
            goto fcdenutricao;
        }
        else if (opmenu == 1)
        {
            goto menuprincipal;
        }
        break;

    case 3:
        system("cls");
        //FILE CONTATOS.h
        system("cls");
        printf("\n uma opcao|\n|[1] Contato de Fisioterapeuta\n|[2] Contato de Nutricionista\n|[3] Contato de Personal Trainer\n|[4] Contato de Psicologo\n|[5] Contato de todos profissionais");
        scanf("%d",&opmenu);
        ctt(opmenu);    
        break;

    case 4:
    informacoes:
        system("cls");
        printf("\n|Suas informacoes: |\n");
        printf("\n| Nome: %s\t\t\t| E-mail: %s\n| Idade: %d\t\t\t| Numero: %s\t\t\t", user[n].nome, user[n].email, user[n].idade, user[n].numero);
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
        switch (calcIMC)
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
        int editInf;
        printf("\nDeseja editar suas informacoes\n[1] Sim [2] Nao");
        scanf("%d", &editInf);
        if (editInf = 1)
        {
        editarinformacao:
            system("cls");
            printf("Qual informacao deseja editar");
            printf("\n|1- Nome\n|2- Email\n|3- Idade\n|4- Numero\n|5- Genero\n|6- Altura\n|7- Peso");
            scanf("%d", &opmenu);
            switch (opmenu)
            {
            case 1:
                printf("\n\n| Alterar seu nome: \n|Antigo: %s \t|Novo: ",user[n].nome);
                fflush(stdin);
                gets(user[n].nome);
                break;
            case 2:
                printf("\n\n| Alterar seu Email: \n|Antigo: %s \t|Novo: ",user[n].email);
                fflush(stdin);
                gets(user[n].email);
                break;
            case 3:
                printf("\n\n| Alterar sua Idade: \n|Antiga: %d \t|Nova: ",user[n].idade);
                fflush(stdin);
                scanf("%d", &user[n].idade);
                break;
            case 4:
                printf("\n\n| Alterar seu Numero: \n|Antigo: %s \t|Novo: ",user[n].numero);
                fflush(stdin);
                gets(user[n].numero);
                break;
            case 5:
                printf("\n\n| Alterar seu Genero: \n|[1] Masculino\t[2] Feminino [3] Nao informado \t ");
                fflush(stdin);
                scanf("%d", &user[n].sexo);
                break;
            case 6:
                printf("\n\n| Alterar sua Altura: \n|Antiga: %.2f \t|Nova: ",user[n].altura);
                fflush(stdin);
                scanf("%f", &user[n].altura);
                break;
            case 7:
                printf("\n\n| Alterar seu peso: \n|Antigo: %.2f \t|Novo: ",user[n].peso);
                fflush(stdin);
                scanf("%f", &user[n].peso);
                break;
            default:
                printf("\n\n|Valor Invalido!");
                goto editarinformacao;
                break;
            }
        }
        else
        {
            printf("| Este valor e invalido");
        }

        printf("\n\nDeseja voltar\n[1] Sim [2] Nao\t");
        scanf("%d", &opmenu);
        if (opmenu == 2)
        {
            goto informacoes;
        }
        else if (opmenu == 1)
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
        break;
    }
}