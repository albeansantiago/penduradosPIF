// funcoes.h
#ifndef FUNCOES_AVALIACAO
#define FUNCOES_AVALIACAO
#include "funcoesImpressao.h"


int verificaLetra(int *erros, char palavraTela[], char palavraSecreta[], char letra);
void contaPonto(char palavraSecreta[], char palavraTela[], int partida, jogador *jogador1, jogador *jogador2);
int verificaEmpate(int *ponto1, int*pont2);

#endif