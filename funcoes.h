// funcoes.h
#ifndef FUNCOES_H
#define FUNCOES_H

void imprimeForca(int estado);
void limpaTela();
void recebeLetra(char palavraSecreta[], char palavraTela[]);
void imprimeLinhas(char palavraTela[], char palavraSecreta[]);
void imprimePalavra(char palavraTela[]);
int verificaLetra(int *erros, char palavraTela[], char palavraSecreta[], char letra);
void digitaPalavra(char palavraSecreta[]);
void imprimeResultado(char palavraSecreta[], char palavraTela[]);
char digitaLetra();

#endif
