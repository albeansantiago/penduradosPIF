#include <stdio.h>
#include <string.h>
#include <unistd.h> // Para STDIN_FILENO e sleep
#include <sys/select.h>
#include <ctype.h>
#include "funcoesLeitura.h"
#include "screen.h"
#include "timer.h"

char digitaLetraComTempo(int tempoLimiteMS) {
    char buffer[100];
    char letra = 0;

    timerInit(tempoLimiteMS);

    while (1) {
        // Imprime o prompt "Letra: _"
        screenGotoxy(5, 22);
        printf("Letra: _");
        screenGotoxy(12, 22);  // posiciona cursor onde vem a letra (posição do '_')
        fflush(stdout);

        fd_set set;
        FD_ZERO(&set);
        FD_SET(STDIN_FILENO, &set);

        int timeRestante = tempoLimiteMS - getTimeDiff();
        if (timeRestante <= 0) {
            // Tempo esgotado
            return '\0';
        }

        // Converte o tempo restante para timeval
        struct timeval timeout;
        timeout.tv_sec = timeRestante / 1000;
        timeout.tv_usec = (timeRestante % 1000) * 1000;

        int rv = select(STDIN_FILENO + 1, &set, NULL, NULL, &timeout);
        if (rv == -1) {
            perror("select");
            return '\0';
        } else if (rv == 0) {
            // Timeout
            return '\0';
        } else {
            // Tecla digitada no stdin
            if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                size_t len = strlen(buffer);
                if (len > 0 && buffer[len - 1] == '\n') {
                    buffer[len - 1] = '\0';
                } else {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) {}
                }

                // Só aceita se for exatamente 1 caractere e letra
                if (strlen(buffer) == 1 && isalpha((unsigned char)buffer[0])) {
                    letra = tolower((unsigned char)buffer[0]);

                    // Mostra a letra digitada na tela
                    screenGotoxy(12, 22);
                    printf("%c", letra);
                    fflush(stdout);

                    // Apaga a letra substituindo por underscore
                    screenGotoxy(12, 22);
                    printf("_");
                    fflush(stdout);

                    // Limpa mensagem de erro (se houver)
                    screenGotoxy(5, 23);
                    for (int i = 0; i < 40; i++) printf(" ");

                    return letra;
                }
            }

            // Se inválido, mostra erro na linha abaixo
            screenGotoxy(5, 23);
            printf("Por favor, digite apenas uma letra valida (A-Z).   ");
            fflush(stdout);
        }
    }
}
    

int quantidadeRodadas() {
    int quantidade;
    screenGotoxy(5, 18);
    printf("Quantidade de rodadas por jogador: ");
    scanf("%d", &quantidade);
    return quantidade;
}

void perguntaNome(jogador *jogador1, jogador *jogador2) {
    screenGotoxy(5, 5);
    printf("Digite o nome do jogador 1: ");
    scanf("%19s", jogador1->nome); 

    screenGotoxy(5, 7);
    printf("Digite o nome do jogador 2: ");
    scanf("%19s", jogador2->nome);
}

void digitaPalavra(char palavraSecreta[], int partida, int empate, int quantidade) {
    if (empate == 1 && partida > quantidade) {
        screenGotoxy(5, 16);
        printf("-------------------------------");

        screenGotoxy(5, 17);
        printf("Vocês estão empatados!");

        screenGotoxy(5, 18);
        printf("Vamos para a partida de desempate!");
    }

    // Mensagem para informar a palavra secreta
    const char* instrucao = "Informe a palavra secreta: ";
    screenGotoxy(5, 20);
    printf("%s", instrucao);
    
    // Lê a palavra com visibilidade
    scanf("%s", palavraSecreta);

    // Apaga a palavra digitada
    screenGotoxy(5 + (int)strlen(instrucao), 20);
    for (int i = 0; i < (int)strlen(palavraSecreta); i++) {
        printf(" ");
    }

    // Mensagem de confirmação
    const char* msgConfirma = "Palavra registrada. Pressione ENTER para continuar...";
    screenGotoxy(5, 21);
    printf("%s", msgConfirma);

    getchar(); // Consome '\n' do scanf
    getchar(); // Aguarda ENTER real

    // Apaga a linha da instrução completa
    screenGotoxy(5, 20);
    for (int i = 0; i < (int)(strlen(instrucao) + strlen(palavraSecreta)); i++) {
        printf(" ");
    }

    // Apaga a linha da mensagem de confirmação
    screenGotoxy(5, 21);
    for (int i = 0; i < (int)strlen(msgConfirma); i++) {
        printf(" ");
    }

    // Posiciona o cursor para a próxima entrada
    screenGotoxy(5, 22);
}
