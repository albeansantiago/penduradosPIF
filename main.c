// main.c
#include <stdio.h>
#include <string.h>
#include "funcoes.h"

int main() {
    int erros = 0;
    char palavraSecreta[100];
    char palavraTela[100] = "\0";
    digitaPalavra(palavraSecreta);
    limpaTela();
    imprimeForca(erros);
    imprimeLinhas(palavraTela, palavraSecreta);

    while (erros < 6 && strcmp(palavraTela, palavraSecreta) != 0) {
        char letra = digitaLetra();
        verificaLetra(&erros, palavraTela, palavraSecreta, letra);
        imprimeForca(erros);
        imprimePalavra(palavraTela);
    }
    
    imprimeResultado(palavraSecreta, palavraTela);
    
    return 0;
}
