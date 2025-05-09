#include <stdio.h>

int main() {
    //criando a matriz do tabuleiro
    int tabuleiro[10][10];
    int linha, coluna;

    

    //inicializando tabuleiro
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }

    //Posisionando navio horizontal
    linha = 4;
    coluna = 7;
    if(linha <= 9 && coluna <= 7){
        for(int i = 0; i < 3; i++){
            tabuleiro[linha][coluna + i] = 3;
        }
    }

    //Posisionando navio vertical
    linha = 2;
    coluna = 5;
    if(linha <= 7 && coluna <= 9 && tabuleiro[linha][coluna] == 0 && tabuleiro[linha+1][coluna] == 0 && tabuleiro[linha+2][coluna] == 0){
        for(int i = 0; i < 3; i++){
            tabuleiro[linha + i][coluna] = 3;
        }
    }
    
    


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
