// funcoes.c
// main.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "funcoes.h"

#define MAX_PALAVRA 50
#define MAX_ROUNDS 3
#define TEMPO_LIMITE 10

typedef struct {
    int pontos;
    int vitorias;
} Jogador;

void inicializaJogadores(Jogador *j1, Jogador *j2) {
    j1->pontos = 0;
    j1->vitorias = 0;
    j2->pontos = 0;
    j2->vitorias = 0;
}

void imprimePlacar(Jogador j1, Jogador j2) {
    printf("\n=== PLACAR ===\n");
    printf("Jogador 1: %d pontos (%d vitorias)\n", j1.pontos, j1.vitorias);
    printf("Jogador 2: %d pontos (%d vitorias)\n", j2.pontos, j2.vitorias);
    printf("==============\n\n");
}

int timer(int segundos) {
    time_t start_time = time(NULL);
    while (1) {
        time_t current_time = time(NULL);
        if (difftime(current_time, start_time) >= segundos) {
            return 0; // Tempo esgotado
        }
    }
    return 1;
}

void modoInsano() {
    printf("\n=== MODO INSANO ATIVADO ===\n");
    printf("- Tempo limite por jogada: %d segundos\n", TEMPO_LIMITE);
    printf("- Palavras com no mínimo 8 letras\n");
    printf("- Penalidade por letra repetida\n");
    printf("===========================\n\n");
}

int main() {
    char palavraSecreta[MAX_PALAVRA];
    char palavraTela[MAX_PALAVRA];
    char letrasTentadas[26] = {0};
    int erros, rodada, totalRounds, turno = 0;
    Jogador jogador1, jogador2;
    
    inicializaJogadores(&jogador1, &jogador2);
    totalRounds = MAX_ROUNDS * 2; // 3 rounds para cada jogador
    
    printf("=== NOME - PENDURADOS ===\n");
    printf("=== MODO INSANO ===\n\n");
    
    modoInsano();
    
    for (rodada = 1; rodada <= totalRounds; rodada++) {
        int jogadorAtual = (rodada % 2) + 1; // Alterna entre 1 e 2
        erros = 0;
        memset(letrasTentadas, 0, sizeof(letrasTentadas));
        
        limpaTela();
        printf("=== RODADA %d ===\n", (rodada + 1) / 2);
        imprimePlacar(jogador1, jogador2);
        
        // Jogador atual escolhe a palavra
        printf("\nJOGADOR %d: Digite a palavra secreta: ", jogadorAtual);
        digitaPalavra(palavraSecreta);
        
        // Verifica se a palavra tem pelo menos 8 letras no modo insano
        while (strlen(palavraSecreta) < 8) {
            printf("Palavra muito curta! Modo insano exige no mínimo 8 letras.\n");
            printf("Digite novamente: ");
            digitaPalavra(palavraSecreta);
        }
        
        limpaTela();
        printf("JOGADOR %d: Tente adivinhar a palavra!\n", (jogadorAtual % 2) + 1);
        imprimeLinhas(palavraTela, palavraSecreta);
        imprimeForca(erros);
        
        // Loop principal do jogo
        while (erros < 6 && strcmp(palavraTela, palavraSecreta) != 0) {
            char letra;
            int letraRepetida = 0;
            
            printf("\nTempo restante: %d segundos\n", TEMPO_LIMITE);
            printf("Letras tentadas: ");
            for (int i = 0; i < 26; i++) {
                if (letrasTentadas[i]) {
                    printf("%c ", 'a' + i);
                }
            }
            
            // Timer
            printf("\nDigite uma letra: ");
            if (!timer(TEMPO_LIMITE)) {
                printf("\nTempo esgotado! Penalidade aplicada.\n");
                erros++;
                imprimeForca(erros);
                continue;
            }
            
            letra = digitaLetra();
            
            // Verifica se a letra já foi tentada
            if (letrasTentadas[letra - 'a']) {
                printf("Letra repetida! Penalidade aplicada.\n");
                erros++;
                letraRepetida = 1;
            } else {
                letrasTentadas[letra - 'a'] = 1;
            }
            
            if (!letraRepetida) {
                verificaLetra(&erros, palavraTela, palavraSecreta, letra);
            }
            
            imprimePalavra(palavraTela);
            imprimeForca(erros);
        }
        
        // Atualiza pontuação
        if (strcmp(palavraTela, palavraSecreta) == 0) {
            printf("\nParabéns! Jogador %d acertou a palavra!\n", (jogadorAtual % 2) + 1);
            if (jogadorAtual == 1) {
                jogador2.pontos++;
            } else {
                jogador1.pontos++;
            }
        } else {
            printf("\nForca completa! Jogador %d perdeu esta rodada.\n", (jogadorAtual % 2) + 1);
            printf("A palavra era: %s\n", palavraSecreta);
        }
        
        // Verifica se alguém ganhou o round
        if ((rodada % 2) == 0) {
            if (jogador1.pontos > jogador2.pontos) {
                jogador1.vitorias++;
                printf("\nJogador 1 venceu o round %d!\n", rodada / 2);
            } else if (jogador2.pontos > jogador1.pontos) {
                jogador2.vitorias++;
                printf("\nJogador 2 venceu o round %d!\n", rodada / 2);
            } else {
                printf("\nRound %d empatado!\n", rodada / 2);
            }
        }
        
        // Espera um pouco antes da próxima rodada
        sleep(2);
    }
    
    // Resultado final
    limpaTela();
    printf("=== FIM DE JOGO ===\n");
    imprimePlacar(jogador1, jogador2);
    
    if (jogador1.vitorias > jogador2.vitorias) {
        printf("Jogador 1 venceu o jogo!\n");
    } else if (jogador2.vitorias > jogador1.vitorias) {
        printf("Jogador 2 venceu o jogo!\n");
    } else {
        printf("EMPATE! Rodada de morte súbita...\n");
        // Implementar morte súbita aqui
    }
    
    return 0;
}
