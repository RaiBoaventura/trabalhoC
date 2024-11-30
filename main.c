#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PALAVRA 100

int main() {
    char palavra[MAX_PALAVRA], letra, dificuldade;
    const char *lista[] = {"experimento", "antena", "pescoço", "telhado", "torneira", "macaco"};
    int lista_tamanho = sizeof(lista) / sizeof(lista[0]);
    int controle[MAX_PALAVRA], chances = 0, tamanho, erros = 0, acertos = 0;
    int i, nlinha;

    srand(time(NULL));
    nlinha = rand() % lista_tamanho;
    strcpy(palavra, lista[nlinha]);

    printf("Bem-vindo ao Jogo da Forca!\n");
    printf("Escolha a dificuldade (1 - Fácil / 2 - Médio / 3 - Difícil): ");
    scanf(" %c", &dificuldade);

    tamanho = strlen(palavra);
    switch (dificuldade) {
        case '1': chances = tamanho * 0.7; break;
        case '2': chances = tamanho * 0.5; break;
        case '3': chances = tamanho * 0.3; break;
        default:
            printf("Dificuldade inválida. Encerrando o jogo.\n");
            return 0;
    }

    for (i = 0; i < tamanho; i++) {
        controle[i] = 0;
    }

    printf("A palavra tem %d letras.\n", tamanho);

    while (acertos < tamanho && erros < chances) {
        int letra_correta = 0;

        printf("\nDigite uma letra: ");
        scanf(" %c", &letra);
        letra = tolower(letra);

        for (i = 0; i < tamanho; i++) {
            if (letra == palavra[i] && controle[i] == 0) {
                controle[i] = 1;
                acertos++;
                letra_correta = 1;
            }
        }

        if (!letra_correta) {
            erros++;
        }

        printf("Palavra: ");
        for (i = 0; i < tamanho; i++) {
            if (controle[i]) {
                printf("%c", palavra[i]);
            } else {
                printf("_ ");
            }
        }
        printf("\nChances restantes: %d\n", chances - erros);
    }

    if (acertos == tamanho) {
        printf("\nParabéns! Você descobriu a palavra: %s\n", palavra);
    } else {
        printf("\nVocê perdeu! A palavra era: %s\n", palavra);
    }

    return 0;
}
