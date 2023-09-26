#include "matrice.h"


int main(){
    Matrice *A, *B, *C;
    Matrice *AmultB;
    A = creer(1, 2, 3);
    B = creer(1, 3, 3);
    initialiserLigne(2, 1, A);
    initialiserLigne(2, 2, B);
    C = multiplier(A, B);

    return 1;
}