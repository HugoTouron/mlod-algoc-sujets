#include <stdio.h>
#include <math.h>

int Diff (int N){
    int SommeDesCarres = 0;
    int Somme = 0;
    for(int i = 0; i <= N; i++){
        SommeDesCarres += pow(i, 2);
        Somme += i;
    }
    int CarreDeLaSomme = pow(Somme, 2);
    return(CarreDeLaSomme - SommeDesCarres);
}




int main(void){
    int n;
    printf("Saisir l'entier naturel : ");
    scanf("%d", &n);
    printf("la difference entre le carre de la somme et la somme des carres est %d", Diff(n));
    return 0;
}