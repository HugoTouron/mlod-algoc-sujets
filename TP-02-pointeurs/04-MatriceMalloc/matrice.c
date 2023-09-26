#include "matrice.h"
#include <stdint.h>
#include <stdlib.h>


Matrice* creer (int init, uint16_t nombreLignes, uint16_t nombreColonnes){
    
    Matrice *M=NULL;
    M->nbColonnes = nombreColonnes;
    M->nbLignes = nombreLignes;
    M->valeurs = (int**)malloc();
}