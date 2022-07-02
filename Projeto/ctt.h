void ctt(int adm){
    contatos:
    int op;
    char contatos[7][3];
    if (adm==1)
    {
        printf("\n| Menu |\n");
        printf("|[01] Adicionar contatos|\n");
        printf("|[02] Ver Lista|\n");
        scanf("%d",&op);
        if (op==2)
        {
            adm=0;
            goto contatos;
        }else if(op==1){
            for (int i = 0; i <7; i++)
            {
                for (int j=0 ; j<3; j++)
                {
                    if (j==0)
                    {
                        printf("\n|Nome: ");
                        gets(contatos[i][0]);
                        fflush(stdin);
                    }else if(j==1){
                        printf("\n|Numero: ");
                        gets(contatos[i][0]);
                        fflush(stdin);  
                    }else{
                        printf("\n|Funcao: ");
                        gets(contatos[i][0]);
                        fflush(stdin);
                    }
                    
                }
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
                printf("\n|Nome: %s\t |Numero: %c\t |Funcao: %c",contatos[i][0],contatos[i][1],contatos[i][2]);
            
        }
    }
    
    
}