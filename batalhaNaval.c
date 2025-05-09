#include <stdio.h>

int main() {
    //criando a matriz do tabuleiro
    int tabuleiro[10][10];
    

    //inicializando tabuleiro
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }

    //Posisionando navios
    tabuleiro[5][4] = 3;
    tabuleiro[5][5] = 3;
    tabuleiro[5][6] = 3;

    tabuleiro[2][8] = 3;
    tabuleiro[3][8] = 3;
    tabuleiro[4][8] = 3;
    

    //printando o tabuleiro
    printf("   A B C D E F G H I J\n");
    for(int i = 0; i < 10; i++){
        if(i != 9){
            printf("%d  ", i+1);
        }else{
            printf("%d ", i+1);
        }
        for(int j = 0; j < 10; j++){
            if(j != 9){
                printf("%d ", tabuleiro[i][j]);
            } else {
                printf("%d\n", tabuleiro[i][j]);
            }
        }
    }

    return 0;
}
