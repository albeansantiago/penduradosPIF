// main.c
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "screen.h"
#include "funcoesImpressao.h"
#include "funcoesLeitura.h"
#include "funcoesAvaliacao.h"

int main() {
    screenInit(1);  // Inicializa tela com bordas
    char palavraSecreta[100];
    char palavraTela[100] = "\0";

    jogador jogador1, jogador2;

    jogador1.pontuacao = 0;
    jogador2.pontuacao = 0;

    perguntaNome(&jogador1, &jogador2);
    int quantidade = 2 * quantidadeRodadas();

    int partida = 1;
    int empate = 1;

    while (partida <= quantidade || empate == 1) {
        int erros = 0;    
        empate = verificaEmpate(&jogador1.pontuacao, &jogador2.pontuacao);

        screenClear();
        screenDrawBorders();

        screenGotoxy(2, 2);
        imprimeNome(partida, jogador2, jogador1);

        screenGotoxy(2, 4);
        digitaPalavra(palavraSecreta, partida, empate, quantidade);

        screenGotoxy(2, 6);
        imprimeForca(erros);

        screenGotoxy(2, 14);
        imprimeNome(partida, jogador1, jogador2);

        screenGotoxy(2, 16);
        imprimeLinhas(palavraTela, palavraSecreta, partida);

        while (erros < 6 && strcmp(palavraTela, palavraSecreta) != 0) {
            screenGotoxy(2, 18);
            
            char letra = digitaLetraComTempo(10000); // 10 segundos, por exemplo

                if (letra == '\0') {
                    screenGotoxy(5, 23);
                    printf("Tempo esgotado para digitar a letra! Passando a vez...        ");
                    fflush(stdout);
                    sleep(2);  // opcional: dar tempo para ler a mensagem
                    // aqui trate o que fazer quando tempo esgota, por ex. incrementar erro
                } else {
                    // processar letra normalmente
                }

            verificaLetra(&erros, palavraTela, palavraSecreta, letra);

            screenGotoxy(2, 6);
            imprimeForca(erros);

            screenGotoxy(2, 14);
            imprimeNome(partida, jogador1, jogador2);

            screenGotoxy(2, 16);
            imprimePalavra(palavraTela);
        }

        screenGotoxy(2, 20);
        imprimeResultado(palavraSecreta, palavraTela);

        contaPonto(palavraSecreta, palavraTela, partida, &jogador1, &jogador2);

        partida++;

        if (partida == quantidade + 1) {
            empate = verificaEmpate(&jogador1.pontuacao, &jogador2.pontuacao);
            if (empate == 1) {
                quantidade += 2;
                screenGotoxy(2, 22);
                printf("Empate detectado! Rodada extra para desempate...");
                sleep(2);
            }
        }
    }

    screenClear();
    screenDrawBorders();

    screenGotoxy(2, 16);
    printf("Fim de jogo! Pontuação final:");

    screenGotoxy(2, 18);
    printf("%s: %d pontos | %s: %d pontos", jogador1.nome, jogador1.pontuacao, jogador2.nome, jogador2.pontuacao);

    screenGotoxy(4, 20);
    if (jogador1.pontuacao == jogador2.pontuacao) {
        printf("\nO jogo terminou empatado! Parabéns a ambos os jogadores!");
    } else if (jogador1.pontuacao > jogador2.pontuacao) {
        printf("\nParabéns, %s! Você venceu o jogo!", jogador1.nome);
    } else {
        printf("\nParabéns, %s! Você venceu o jogo!", jogador2.nome);
    }

    screenGotoxy(2, 22);
    printf("Pressione ENTER para sair...");
    getchar();

    screenDestroy();
    return 0;
}