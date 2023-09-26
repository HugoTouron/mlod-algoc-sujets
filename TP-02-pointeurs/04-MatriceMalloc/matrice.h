#include <stdint.h>

typedef struct{
    uint16_t nbLignes;
    uint16_t nbColonnes;
    int **valeurs;
}Matrice;