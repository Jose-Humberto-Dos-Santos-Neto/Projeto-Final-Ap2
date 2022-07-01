void listadetreino(){
    struct treinos
    {
        struct dias
        {
           char exe[100];
           int qtd,rep;
        }tt[8];      
    }treino[5];
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            treino[i].tt[j].exe="Exercicio";
            treino[i].tt[j].qtd=4;
            treino[i].tt[j].rep=15;
        }
    }
}