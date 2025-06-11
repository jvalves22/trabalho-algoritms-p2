#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void entradaNomes(char nomes[10][40]){
    int i;
    for (i = 0; i < 10; i++){
        printf("Insira %2do. nome: ", i+1);
        fflush(stdin);
        fgets(nomes[i], 40, stdin);
        nomes[i][strcspn(nomes[i], "\n")] = '\0';
    }
}

void organizarNomes(char nomes[10][40]){
    int i, j;
    char temp[40];
    for (i = 0; i < 9; i++){
        for (j = i + 1; j < 10; j++){
            if (strcmp(nomes[i], nomes[j]) > 0) {
                strcpy(temp, nomes[i]);
                strcpy(nomes[i], nomes[j]);
                strcpy(nomes[j], temp);
            }
        }
    }
}

void apresentaNomes(char nomes[10][40]){
    int i;
    printf("\n");
    for (i = 0; i < 10; i++){
        printf("Nome: %2d --> %s\n", i+1, nomes[i]);
    }
}

char ordenacao(){
    char op;
    printf("Organizar os nomes em ordem alfabetica? \nSim[S] Nao[N]: ");
    fflush(stdin);
    op = getchar();
    while (getchar() != '\n' && !feof(stdin));
    return op;
}

char continuar(){
    char resp;
    printf("Quer continuar? \nSim[S] Nao[N]: ");
    fflush(stdin);
    resp = getchar();
    while (getchar() != '\n' && !feof(stdin));
    return resp;
}

int pesquisaNome(char nomes[10][40], char pesquisa[40]){
    int i;
    for (i = 0; i < 10; i++){
        if (strcmp(pesquisa, nomes[i]) == 0){
            return i;
        }
    }
    return -1;
}

int main(){
    char nomes[10][40], pesquisa[40], resp, opcao;
    int pos;
    printf("\nPesquisa e Lista de Nomes\n");

    entradaNomes(nomes);

    opcao = perguntaOrdenacao();

    if (opcao == 'S' || opcao == 's') {
        organizarNomes(nomes);
        printf("\nNomes organizados por ordem alfabetica:\n");
        apresentaNomes(nomes);
        system("pause");
    } else{
        printf("\nO sistema utilizara os nomes organizados na ordem de lancamento original.\n");
    }

    resp = 'S';
    while (resp == 'S' || resp == 's'){
        printf("\nDigite o nome que deseja ser pesquisado: ");
        fflush(stdin);
        fgets(pesquisa, 40, stdin);
        pesquisa[strcspn(pesquisa, "\n")] = '\0';

        pos = pesquisaNome(nomes, pesquisa);

        if (pos != -1){
            printf("\n%s foi localizado na posicao %d\n", pesquisa, pos+1);
        }else{
            printf("%s nao foi localizado\n", pesquisa);
        }

        resp = continuar();
    }
    return 0;
}
