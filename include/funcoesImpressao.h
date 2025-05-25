// funcoes.h
#ifndef FUNCOES_IMPRESSAO
#define FUNCOES_IMPRESSAO

typedef struct {
    char nome[20];
    int pontuacao;
} jogador;

void imprimeForca(int estado);
void imprimeLinhas(char palavraTela[], char palavraSecreta[], int partida);
void imprimePalavra(char palavraTela[]);
void imprimeResultado(char palavraSecreta[], char palavraTela[]);
void imprimeNome(int partida, jogador jogador1, jogador jogador2);
#endif
