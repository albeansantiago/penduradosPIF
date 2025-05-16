// funcoes.c
#include <stdio.h>
#include <string.h>
#include "funcoes.h"

void imprimeForca(int estado) {
   if (estado==0){
        printf("\n -----------");
        printf("\n|           |");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
        
    } else if(estado==1){
       
        printf("\n -----------");
        printf("\n|           |");
        printf("\n|           0");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
        
    }else if(estado==2){
        printf("\n -----------");
        printf("\n|           |");
        printf("\n|           0");
        printf("\n|           |");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
        
    }else if(estado==3){
        printf("\n -----------");
        printf("\n|           |");
        printf("\n|           0");
        printf("\n|         --|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
        
    }else if(estado==4){
        
        printf("\n -----------");
        printf("\n|           |");
        printf("\n|           0");
        printf("\n|         --|--");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
        
    }else if(estado==5){
        printf("\n -----------");
        printf("\n|           |");
        printf("\n|           0");
        printf("\n|         --|--");
        printf("\n|          /");
        printf("\n|");
        printf("\n|");
        printf("\n-");
        
    }else if(estado==6){
        printf("\n -----------");
        printf("\n|           |");
        printf("\n|           0");
        printf("\n|         --|--");
        printf("\n|          / \\");
        printf("\n|");
        printf("\n|     Pergeu o jogo!");
        printf("\n-");
        
    }
}

void limpaTela() {
    for (int i = 0; i < 30; i++) {
        printf("\n");
    }
}

void imprimeLinhas(char palavraTela[], char palavraSecreta[]) {
    printf("\nAdivinhe: ");
    
    int quantidade = strlen(palavraSecreta);
    for (int i = 0; i < quantidade; i++) {
        palavraTela[i] = '_';
        printf("%c ", palavraTela[i]);
    }
    palavraTela[quantidade] = '\0'; // Finaliza string
}

void imprimePalavra(char palavraTela[]) {
    printf("\nAdivinhe: ");
    
    int quantidade = strlen(palavraTela);
    for (int i = 0; i < quantidade; i++) {
        printf("%c ", palavraTela[i]);
    }
}

int verificaLetra(int *erros, char palavraTela[], char palavraSecreta[], char letra) {
    int quantidade = strlen(palavraSecreta);
    int acerto = 0;

    for (int i = 0; i < quantidade; i++) {
        if (letra == palavraSecreta[i]) {
            palavraTela[i] = letra;
            acerto++;
        }
    }

    if (acerto == 0) {
        (*erros)++;
    }

    return *erros;
}

void digitaPalavra(char palavraSecreta[]){
    
    printf("JOGADOR 1: \n");
    printf("Informe a palavra secreta: \n");
    scanf("%s", palavraSecreta);
    
}

void imprimeResultado(char palavraSecreta[], char palavraTela[]){
    if (strcmp(palavraTela, palavraSecreta) == 0) {
        printf("\nParabéns! Você acertou a palavra!\n");
    } else {
        printf("\nFim de jogo! A palavra era: %s\n", palavraSecreta);
    }

}

char digitaLetra(){
        char letra;
        printf("\nLetra: ");
        scanf(" %c", &letra);
    
    return letra;
}