#include <stdio.h>
#include <string.h>
#include "funcoesImpressao.h"
#include "screen.h"

void imprimeForca(int estado) {
    int x = 5, y = 3; // Posição inicial da forca

    screenGotoxy(x, y++);
    printf(" -----------");
    screenGotoxy(x, y++);
    printf("|           |");

    screenGotoxy(x, y++);
    if (estado >= 1)
        printf("|           0");
    else
        printf("|");

    screenGotoxy(x, y++);
    if (estado == 2)
        printf("|           |");
    else if (estado == 3)
        printf("|         --|");
    else if (estado >= 4)
        printf("|         --|--");
    else
        printf("|");

    screenGotoxy(x, y++);
    if (estado == 5)
        printf("|          /");
    else if (estado >= 6)
        printf("|          / \\");
    else
        printf("|");

    screenGotoxy(x, y++);
    printf("|");

    screenGotoxy(x, y++);
    if (estado == 6)
        printf("|     Perdeu o jogo!");
    else
        printf("|");

    screenGotoxy(x, y++);
    printf("-");
}


void imprimeNome(int partida, jogador jogador1, jogador jogador2){
    screenGotoxy(5, 2);
    if(partida % 2 == 0){
        printf("Jogador: %s", jogador1.nome);
    } else {
        printf("Jogador: %s", jogador2.nome);
    }
}


void imprimeLinhas(char palavraTela[], char palavraSecreta[], int partida) {
    int x = 5, y = 12;
    screenGotoxy(x, y);
    printf("Adivinhe: ");

    int quantidade = strlen(palavraSecreta);
    for (int i = 0; i < quantidade; i++) {
        palavraTela[i] = '_';
        printf("%c ", palavraTela[i]);
    }
    palavraTela[quantidade] = '\0'; // Finaliza string
}


void imprimePalavra(char palavraTela[]) {
    int x = 5, y = 12;
    screenGotoxy(x, y);
    printf("Adivinhe: ");

    int quantidade = strlen(palavraTela);
    for (int i = 0; i < quantidade; i++) {
        printf("%c ", palavraTela[i]);
    }
}


void imprimeResultado(char palavraSecreta[], char palavraTela[]) {
    int x = 5, y = 20;
    screenGotoxy(x, y);
    if (strcmp(palavraTela, palavraSecreta) == 0) {
        printf("Parabéns! Você acertou a palavra!");
    } else {
        printf("Você perdeu! A palavra era: %s", palavraSecreta);
    }
}








