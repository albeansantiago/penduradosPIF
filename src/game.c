#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <timer.h>
#include <screen.h>
#include <keyboard.h>
#include <score.h>
#include <game.h>

void forca(int erro) {
    if(erro == 0) {
        printf("\n-----------------");
        printf("\n|               |");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n__");
    } else if(erro == 1) {
        printf("\n-----------------");
        printf("\n|               |");
        printf("\n|               O");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n__");
    } else if(erro == 2) {
        printf("\n-----------------");
        printf("\n|               |");
        printf("\n|               O");
        printf("\n|               |");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n__");
    } else if(erro == 3) {
        printf("\n-----------------");
        printf("\n|               |");
        printf("\n|               O");
        printf("\n|              -|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n__");
    } else if(erro == 4) {
        printf("\n-----------------");
        printf("\n|               |");
        printf("\n|               O");
        printf("\n|              -|-");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n__");
    } else if(erro == 5) {
        printf("\n-----------------");
        printf("\n|               |");
        printf("\n|               O");
        printf("\n|              -|-");
        printf("\n|              /");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n__");
    } else if(erro == 6) {
        printf("\n-----------------");
        printf("\n|               |");
        printf("\n|               O");
        printf("\n|              -|-");
        printf("\n|              / \\");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|       PERDEU O JOGO");
        printf("\n__");
    }
}
int main(void) {
    forca(2);

    return 0;
}
