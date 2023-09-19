typedef short TypeEntier;
#include <stdio.h>

long factorielle(long nombre){
    long fac = 1;
    for(int i = 1; i<=nombre; i++){
        fac*= i;
    }
    return(fac);
}


int main (void){
    for (int k = 1; k < 16; k++){
        printf("%ld\n", factorielle(k));
    }
    
}