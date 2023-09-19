#include <stdio.h>
#include <stdbool.h>

bool NbParfait(int N){
    int somme = 0;
    int i;
    for( i=1; i<N; i++ ){
        if(N%i==0){
            somme+=i;
        }
    }
    return (somme == N);
}

int main(void){
    int nombre = 30;
    for(int i = 1; i<=nombre; i++ ){
        if (NbParfait(i)){
            printf("%d\n", i);
        }
    }
    return 0;
}