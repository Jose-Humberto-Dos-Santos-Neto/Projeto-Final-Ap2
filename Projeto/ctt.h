int ctt(int imcIA)
{
    int i;
    if (imcIA == 1)
    {
        FILE *arq;
        arq = fopen("Fisioterapeuta.txt", "rt");
        char Linha[100];
        char *result;
        if (arq == NULL)
        {
            printf("Nao foi possivel abrir o arquivo.\n");
            getchar();
            exit(0);
        }
        i = 1;
        printf("Contato Fisioterapia: ");
        while (!feof(arq))
        {
            result = fgets(Linha, 100, arq);
            if (result)
            {
                printf("%s", Linha);
            }
        }

        fclose(arq);
    }

    if (imcIA == 2)
    {
        FILE *arq1;
        arq1 = fopen("nutricionista.txt", "rt");
        char Linha[100];
        char *result;
        if (arq1 == NULL)
        {
            printf("Nao foi possivel abrir o arquivo.\n");
            getchar();
            exit(0);
        }
        i = 1;
        printf("Contato nutricionista: ");
        while (!feof(arq1))
        {
            result = fgets(Linha, 100, arq1);
            if (result)
            {
                printf("%s", Linha);
            }
        }

        fclose(arq1);
    }

    if (imcIA == 3)
    {
        FILE *arq2;
        arq2 = fopen("personais.txt", "rt");
        char Linha[100];
        char *result;
        if (arq2 == NULL)
        {
            printf("Nao foi possivel abrir o arquivo.\n");
            getchar();
            exit(0);
        }
        i = 1;
        printf("Contato Personais: ");
        while (!feof(arq2))
        {
            result = fgets(Linha, 100, arq2);
            if (result)
            {
                printf("%s", Linha);
            }
        }

        fclose(arq2);
    }

    if (imcIA == 4)
    {
        FILE *arq3;
        arq3 = fopen("psicologos.txt", "rt");
        char Linha[100];
        char *result;
        if (arq3 == NULL)
        {
            printf("Nao foi possivel abrir o arquivo.\n");
            getchar();
            exit(0);
        }
        i = 1;
        printf("Contato psicologo: ");
        while (!feof(arq3))
        {
            result = fgets(Linha, 100, arq3);
            if (result)
            {
                printf("%s", Linha);
            }
        }

        fclose(arq3);
    }

    if (imcIA == 5)
    {
        FILE *arq, *arq1, *arq2, *arq3;
        arq = fopen("Fisioterapeuta.txt", "rt");
        arq1 = fopen("nutricionista.txt", "rt");
        arq2 = fopen("personais.txt", "rt");
        arq3 = fopen("psicologos.txt", "rt");
        char Linha[100];
        char *result;
        if (arq == NULL || arq1 == NULL)
        {
            if (arq2 == NULL || arq3 == NULL)
            {
                printf("Nao foi possivel abrir o arquivo.\n");
                getchar();
                exit(0);
            }
        }
        printf("Contato Fisioterapia: ");
        while (!feof(arq))
        {
            result = fgets(Linha, 100, arq);
            if (result)
            {
                printf("\n%s", Linha);
            }
        }
        printf("\nContato Nutricionista: ");
        while (!feof(arq1))
        {
            result = fgets(Linha, 100, arq1);
            if (result)
            {
                printf("\n%s", Linha);
            }
        }
        printf("\nContato Personais: ");
        while (!feof(arq2))
        {
            result = fgets(Linha, 100, arq2);
            if (result)
            {
                printf("\n%s", Linha);
            }
        }
        printf("\nContato Psicologo: ");
        while (!feof(arq3))
        {
            result = fgets(Linha, 100, arq3);
            if (result)
            {
                printf("\n%s", Linha);
            }
        }
        fclose(arq3);
        fclose(arq2);
        fclose(arq1);
        fclose(arq);
    }
}

