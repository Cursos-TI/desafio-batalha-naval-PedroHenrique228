#include <stdio.h>

void printarTabuleiro(int tabuleiro[10][10]){
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
    printf("\n\n");
}

int main() {
    //criando matrizes e variáveis
    int tabuleiro[10][10];
    int cone[3][5], cruz[3][5], octaedro[5][5];
    int linha, coluna;

    

    //inicializando tabuleiro
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }
                                                //Posicionando navios
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
    
    //Posicionando navio na diagonal 1
    linha = 6;
    coluna = 3;
    if(linha <= 7 && coluna <= 7 && tabuleiro[linha][coluna] == 0 && tabuleiro[linha+1][coluna+1] == 0 && tabuleiro[linha+2][coluna+2] == 0){
        for(int i = 0; i < 3; i++){
            tabuleiro[linha + i][coluna + i] = 3;
        }
    }

    //Posicionando navio na diagonal 2
    linha = 1;
    coluna = 3;
    if(linha <= 7 && coluna >= 2 && tabuleiro[linha][coluna] == 0 && tabuleiro[linha+1][coluna-1] == 0 && tabuleiro[linha+2][coluna-2] == 0){
        for(int i = 0; i < 3; i++){
            tabuleiro[linha + i][coluna - i] = 3;
        }
    }

    //Printando o posicionamento dos navios
    printf("--Posicionamento dos navios--\n\n");
    printarTabuleiro(tabuleiro);


                                                       //Habilidade cone
    //Inicializando habilidade em cone
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            cone[i][j] = 0;
        }
    }
    //Posicionando habilidade na matriz de cone
    linha = 0;
    coluna = 2;
    for(int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            if(j <= i){
                cone[linha + i][coluna + j] = 1;
                cone[linha + i][coluna - j] = 1;
            }
        }
     }
    //Posicionando habilidade cone no tabuleiro
    linha = 3;
    coluna = 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            if(cone[i][j] == 1 && tabuleiro[linha + i][coluna + j] == 3){
                tabuleiro[linha + i][coluna + j] = 5;
            }else if(cone[i][j] == 1){
                tabuleiro[linha + i][coluna + j] = 1;
            }
        }
    }



                                                        //Habilidade cruz
    //Inicializando habilidade em cruz
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            cruz[i][j] = 0;
        }
    }

    ////Posicionando habilidade na matriz de cruz
    linha = 1;
    coluna = 2;
    cruz[linha + 1][coluna] = 1;
    cruz[linha - 1][coluna] = 1;
    for(int i=0; i<3; i++){
        cruz[linha][coluna + i] = 1;
        cruz[linha][coluna - i] = 1;
    }

    //Posicionando habilidade cruz no tabuleiro
    linha = 7;
    coluna = 4;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            if(cruz[i][j] == 1 && tabuleiro[linha + i][coluna + j] == 3){
                tabuleiro[linha + i][coluna + j] = 5;
            }else if(cruz[i][j] == 1){
                tabuleiro[linha + i][coluna + j] = 1;
            }
        }
    }


                                                        //Habilidade octaedro
    //Inicializando habilidade em octaedro
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            octaedro[i][j] = 0;
        }
    }

    //Posicionando habilidade na matriz de octaedro
    linha = 2;
    coluna = 2;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if((i == 0 || j == 0) || (i == j && i < 2)){
                octaedro[linha+i][coluna+j] = 1;
                octaedro[linha-i][coluna-j] = 1;
                octaedro[linha+i][coluna-j] = 1;
                octaedro[linha-i][coluna+j] = 1;
            }

        }
    }

    //Posicionando habilidade octaedro no tabuleiro
    linha = 0;
    coluna = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(octaedro[i][j] == 1 && tabuleiro[linha + i][coluna + j] == 3){
                tabuleiro[linha + i][coluna + j] = 5;
            }else if(octaedro[i][j] == 1){
                tabuleiro[linha + i][coluna + j] = 1;
            }
        }
    }

    //Printando o tabuleiro com habilidades
    printf("--Tabuleiro com habilidades--\n\n");
    printarTabuleiro(tabuleiro);

    //Retirando habiliades que erraram
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(tabuleiro[i][j] == 1){
                tabuleiro[i][j] = 0;
            }
        }
    }

    //Printando tabuleiro com as areas afetadas
    printf("--Tabuleiro com areas afetadas--\n\n");
    printarTabuleiro(tabuleiro);

    return 0;
}
