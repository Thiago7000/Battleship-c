#include <stdio.h>

void criarcone (int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i < 3 && j >= 2 - i  && j <= 2 + i) 
                matriz [i][j] = 1;
            else 
                matriz [i][j] = 0;
        }
    }
}

void criarcruz (int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2  || j == 2) 
                matriz [i][j] = 1;
            else 
                matriz [i][j] = 0;
        }
    }
}

void criaroctaedro (int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int dist_linha = i <= 2 ? 2 - i : i - 2;
            int dist_coluna = j <= 2 ? 2- j : j - 2;
            if (dist_linha + dist_coluna <= 2) 
                matriz [i][j] = 1;
            else 
                matriz [i][j] = 0;
        }
    }
}

void aplicarhabilidade (int tabuleiro[10][10], int habilidade [5][5], int centro_linha, int centro_coluna) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) { 
            int linhatab = centro_linha - 2 + i;
            int coltab = centro_coluna - 2 + j;
            
            if (linhatab >= 0 && linhatab < 10 && coltab >= 0 && coltab < 10) {
                if (habilidade [i][j] == 1 && tabuleiro[linhatab][coltab] == 0) {
                    tabuleiro [linhatab][coltab] = 5;
                } 
            }
        }    
    }
}

int main(){

    char colunaletra [10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro [10] [10];

    // Inicialização Tabuleiro 
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
        tabuleiro [i][j] = 0; 
        }         
    }

    // Navio Vertical 
    for (int i = 0; i < 3; i++){
        tabuleiro [i][5] = 3;
    }

    // Navio Horizontal
    for (int j = 0; j < 3; j++){
        tabuleiro [9][j] = 3;
    }

    // Navio Diagonal Principal 
    int iniciolinha = 0;
    int iniciocoluna = 0;

    for (int i = 0; i < 3; i++){
        int linha = iniciolinha + i;
        int coluna = iniciocoluna + i;

        if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10 && tabuleiro [linha][coluna] == 0) {
            tabuleiro [linha][coluna] = 3; 
        }
    } 

    // Navio Diagonal Secundária 
    int iniciolinhadiag = 0;
    int iniciocolunadiag = 9;

     for (int i = 0; i < 3; i++){
        int linha = iniciolinhadiag + i;
        int coluna = iniciocolunadiag - i;

        if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10 && tabuleiro [linha][coluna] == 0) {
            tabuleiro [linha][coluna] = 3; 
        }  
    } 
    
    
    int cone[5][5], cruz[5][5], octaedro[5][5];
  
    criarcone(cone);
    criarcruz(cruz);
    criaroctaedro(octaedro);
    
    aplicarhabilidade (tabuleiro, cone, 8, 2);
    aplicarhabilidade (tabuleiro, cruz, 4, 4);
    aplicarhabilidade (tabuleiro, octaedro, 7, 7); 

    // Mostrar cabeçalho
    printf ("  ");
    for (int i = 0; i < 10; i++){
        printf(" %c", colunaletra [i]);
    }
    printf ("\n");

    // Mostrar Tabuleiro 
    for (int t = 0; t < 10; t++){
        printf ("%2d ", t + 1);

        for (int q = 0; q < 10; q++){
        printf ("%d ", tabuleiro[t][q]);
        }
        printf ("\n");
    }

}