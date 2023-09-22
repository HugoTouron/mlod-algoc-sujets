#include "dates.h"
#include <stdio.h>

void initialiseDate(Date *d){
    printf("jour : ");
    scanf("%d", &d->jour);
    printf("mois : ");
    scanf("%d", (int *)&d->mois);
    printf("annee : ");
    scanf("%d", &d->annee);
}

void afficheDate(Date *d){
    printf("la date est %d/%d/%d", d->jour, (int)d->mois, d->annee);
}


Date creerDateParCopie(){
    Date date;
    printf("jour : ");
    scanf("%d", &date.jour);
    printf("mois : ");
    scanf("%d", (int *)&date.mois);
    printf("annee : ");
    scanf("%d", &date.annee);
    return date;
}

Date* newDate(){
    Date* d = (Date*)malloc(sizeof(Date));
    initialiseDate(d);
    return d;
}
