#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


void matrix_mult(int64_t matriceResultat[][5], int64_t matrice1[][5], int64_t matrice2[][5]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            matriceResultat[i][j] = 0;
            for(int k = 0; k < 5; k++){
                matriceResultat[i][j] += matrice1[i][k] * matrice2[k][j];
            }
        }
    }
}

void matrix_print (int64_t matriceResultat[][5]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%lld  ", matriceResultat[i][j]);
        }
        printf("\n");
    }
}