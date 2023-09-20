#include "dates.h"
#include <stdio.h>

void initialiseDate(Date *d){
    printf("jour : ");
    scanf("%d", &d->jour);
    printf("mois : ");
    scanf("%d", (int *)&d->mois);
    printf("année : ");
    scanf("%d", &d->annee);
}

void afficheDate(Date *d){
    printf("%n %n %n", &d->jour, (int *)&d->mois, &d->annee);
}
