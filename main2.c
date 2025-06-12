#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int i, j, acha;
    char nome[10][40], pesq[40], resp, temp[40];

    printf("\nPesquisa e Listagem sequencial de nomes\n\n");

    for (i = 0; i < 10; i++)
    {
        printf("Digite o %2do. nome: ", i + 1);
        fgets(nome[i], sizeof(nome[i]), stdin);
        nome[i][strcspn(nome[i], "\n")] = '\0'; // Remove o '\n'
    }

    for (i = 0; i < 9; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (strcmp(nome[i], nome[j]) > 0)
            {
                strcpy(temp, nome[i]);
                strcpy(nome[i], nome[j]);
                strcpy(nome[j], temp);
            }
        }
    }

    printf("\nLista de nomes ordenados:\n");
    for (i = 0; i < 10; i++)
    {
        printf("Nome %2d: %s\n", i + 1, nome[i]);
    }

    resp = 'S';
    while (resp == 'S' || resp == 's')
    {
        printf("\nEntre o nome a ser pesquisado: ");
        fgets(pesq, sizeof(pesq), stdin);
        pesq[strcspn(pesq, "\n")] = '\0'; // Remove o '\n'

        acha = 0;
        for (i = 0; i < 10 && !acha; i++)
        {
            if (strcmp(pesq, nome[i]) == 0)
            {
                acha = 1;
                break;
            }
        }

        if (acha)
            printf("%s foi localizado na posição %d.\n", pesq, i + 1);
        else
            printf("%s não foi localizado.\n", pesq);

        printf("\nContinua? [S]IM/[N]AO + <Enter>: ");
        resp = getchar();
        while (getchar() != '\n'); // Limpa o buffer
    }
    
    return 0;
}
