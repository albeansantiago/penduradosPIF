// funcoes.h
#ifndef FUNCOES_H
#define FUNCOES_H

#include <time.h>

// Definições de constantes
#define MAX_PALAVRA 50
#define MAX_ROUNDS 3
#define TEMPO_LIMITE 10

// Estrutura para armazenar dados do jogador
typedef struct {
    int pontos;
    int vitorias;
} Jogador;

// Protótipos das funções existentes
void imprimeForca(int estado);
void limpaTela();
void imprimeLinhas(char palavraTela[], char palavraSecreta[]);
void imprimePalavra(char palavraTela[]);
int verificaLetra(int *erros, char palavraTela[], char palavraSecreta[], char letra);
void digitaPalavra(char palavraSecreta[]);
void imprimeResultado(char palavraSecreta[], char palavraTela[]);
char digitaLetra();

// Protótipos das novas funções
void inicializaJogadores(Jogador *j1, Jogador *j2);
void imprimePlacar(Jogador j1, Jogador j2);
int timer(int segundos);
void modoInsano();

#endif
