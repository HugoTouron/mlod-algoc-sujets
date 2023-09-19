typedef short TypeEntier;
#include <stdio.h>

TypeEntier factorielle(TypeEntier nombre){
    TypeEntier fact = 1;
    for(int i = 1; i<=nombre; i++){
        fact*= i;
    }
    return(fact);
}


int main (void){
    int NbTest = 5;
    printf("%d", factorielle(NbTest));
}