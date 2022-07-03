void listadetreino(char *x){
    if(*x=='A' || *x=='a'){
        system("cls");
        printf("\n|Peitorais / triceps|\n|Supino inclinado com barra: 4 series de 10 a 12 repeticoes|\n|Crucifixo reto: 3 series de 10 a 12 repeticoes|\n|Supino reto com barra: 3 series de 10 a 12 repeticoes|\n|Voador no banco com halteres: 3 series de 10 a 12 repeticoes|\n|Triceps Francês deitado com halteres: 3 series de 10 a 12 repeticoes|\n|Tríceps no pulley com corda: 3 series de 10 a 12 repeticoes|\n|Triceps no pulley com barra: 3 series de 10 a 12 repeticoes|\n|Triceps testa: 4 series de 10 a 12 repeticoes|");
    }else if(*x=='B' || *x=='b'){
        system("cls");
        printf("\n|Costas / biceps / antebracos|\n|Levantamento terra: 3 series de 10 a 12 repeticoes|\n|Pulley frontal: 3 series de 10 a 12 repeticoes|\n|Pulley atras: 4 series de 10 a 12 repeticoes|\n|Remada baixa: 4 series de 10 a 12 repeticoes|\n|Serrote com halter: 4 series de 10 a 12 repeticoes|\n|Rosca alternada com banco inclinado: 4 series de 10 a 12 repeticoes|\n|Rosca Scott com barra W: 4 series de 10 a 12 repeticoes|\n|Rosca direta na barra reta: 3 series de 10 a 12 repeticoes|\n|Rosca martelo em pe: 4 series de 10 a 12 repeticoes|\n|Rosca punho: 4 series de 10 a 12 repeticoes|");
    }else if(*x=='C' || *x=='c'){
        system("cls");
        printf("\n|Pernas|\n|Leg press 45graus: 4 series de 10 a 12 repeticoes|\n|Extensor de pernas: 4 series de 10 a 12 repeticoes|\n|Cadeira flexora: 4 series de 10 a 12 repeticoes|\n|Cadeira adutora: 4 series de 10 a 12 repeticoes|\n|Cadeira abdutora: 4 series de 10 a 12 repeticoes|\n|Stiff: 4 series de 10 a 12 repeticoes|");
    }else if(*x=='D'||*x=='d'){
        system("cls");
        printf("\n|Ombros / trapezio|\n|Desenvolvimento por tras da nuca com barra: 4 series de 8 a 12 repeticoes|\n|Desenvolvimento no Smith machine: 3 series de 8 a 12 repeticoes;\n|Elevacao frontal com halteres em pe : 3 series de 8 a 12 repeticoes|\n|Elevacao lateral com halteres sentado: 4 series de 8 a 12 repeticoes|\n|Encolhimento de ombros com halteres: 4 series de 8 a 12 repeticoes|\n|Encolhimento de ombros com barra: 4 series de 8 a 12 repeticoes|");
    }else{
        printf("\n|Treino Invalido");
    }
}