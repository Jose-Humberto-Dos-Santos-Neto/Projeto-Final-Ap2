int ctt(int adm;){
    int escolha;
    contatos:
    struct cont{
        char nome[150],funcao[45];
        int numero;
    }ct[7];
    
    if (adm==1)
    {
        system("cls");
        printf("\n| Menu |\n");
        printf("|[01] Adicionar contatos|\n");
        printf("|[02] Ver Lista|\n");
        scanf("%d",&escolha);
        if (escolha==2)
        {
            adm=0;
            goto contatos;
        }else if(escolha==1){
            for (int i =0; i<7; i++)
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
                        scanf("%d",&ct[i].numero);
                        fflush(stdin);
            }
        }else{
            printf("\nValor Invalido\n");
            system("cls");
            goto contatos;
        }
    }else{
        printf("\n| Lista de contatos |");
        for (int i = 0; i <7; i++)
        {           
                printf("\n|Nome: %s\t |Numero: %d\t |Funcao: %s",ct[i].nome, ct[i].numero, ct[i].funcao);
        }
    }
    printf("\nDeseja voltar\n[0] Sim [1] Nao\t");
        scanf("%d", &escolha);
        return escolha;
}
