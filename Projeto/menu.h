int menu(){
    int escolha;
    system("cls");
    printf("\n | Escolha uma das opcoes |\n");
    printf("\n | (01) Lista de Treino   |\n");
    printf("\n | (02) Ficha de nutricao |\n");
    printf("\n | (03) Lista de Contatos |\n");
    printf("\n | (04) Suas informacoes  |\n");
    printf("\n | (0) Sair do menu       |\n");
    scanf("%d", &escolha);
    return escolha;
}