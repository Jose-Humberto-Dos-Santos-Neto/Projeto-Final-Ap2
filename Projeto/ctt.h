int ctt(){
    
    int escolha;
    contatos:
    struct cont{
        char nome[150],funcao[45];
        int numero;
    }ct[7];

        printf("\n| Lista de contatos |");
        for(int i = 0; i=='\0'; i++){
        for (int i = 0; i <7; i++)
        {           
                printf("\n|Nome: %s\t |Numero: %d\t |Funcao: %s",ct[i].nome, ct[i].numero, ct[i].funcao);
        }
        }
    printf("\nDeseja voltar\n[0] Sim [1] Nao\t");
        scanf("%d", &escolha);
        return escolha;
}
