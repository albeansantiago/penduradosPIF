#include <stdio.h>
#include <string.h>
#include "funcoesAvaliacao.h"
#include "screen.h"

void contaPonto(char palavraSecreta[], char palavraTela[], int partida, jogador *jogador1, jogador *jogador2) {
    screenClear();
    screenDrawBorders();
    if (strcmp(palavraTela, palavraSecreta) == 0) {
        if (partida % 2 == 0) {
            jogador1->pontuacao++;
            screenGotoxy(5, 5);
            printf("Parabéns %s! Você acertou a palavra e somou +1 ponto!", jogador1->nome);
        } else {
            jogador2->pontuacao++;
            screenGotoxy(5, 5);
            printf("Parabéns %s! Você acertou a palavra e somou +1 ponto!", jogador2->nome);
        }
    } else {
        screenGotoxy(5, 5);
        printf("Você não acertou a palavra nesta rodada.");
    }

    screenGotoxy(5, 8);
    printf("PLACAR ATUAL:");

    screenGotoxy(5, 9);
    printf("%s: %d ponto(s)", jogador1->nome, jogador1->pontuacao);

    screenGotoxy(5, 10);
    printf("%s: %d ponto(s)", jogador2->nome, jogador2->pontuacao);

    screenGotoxy(5, 12);
    printf("Pressione ENTER para continuar...");
    getchar(); // espera ENTER
    screenClear();
}

int verificaLetra(int *erros, char palavraTela[], char palavraSecreta[], char letra) {
    int quantidade = strlen(palavraSecreta);
    int acerto = 0;

    for (int i = 0; i < quantidade; i++) {
        if (letra == palavraSecreta[i]) {
            palavraTela[i] = letra;
            acerto++;
        }
    }

    if (acerto == 0) {
        (*erros)++;
    }

    return *erros;
}

int verificaEmpate(int *ponto1, int *ponto2) {
    int empate = 0;

    if (*ponto1 == *ponto2) {
        empate = 1;
    }

    return empate;
}
