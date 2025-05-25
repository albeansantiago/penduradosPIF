// funcoes.h
#ifndef FUNCOES_LEITURA
#define FUNCOES_LEITURA

#include "funcoesImpressao.h"

char digitaLetra();
int quantidadeRodadas();
void digitaPalavra(char palavraSecreta[], int partida, int empate, int quantidade);
void perguntaNome(jogador *jogador1, jogador *jogador2);

char digitaLetraComTempo(int tempoLimiteMS);



#endif
