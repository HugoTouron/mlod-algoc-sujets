#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include "prixTuring.h"

int numberOfWinners (FILE *fichier){

    int compte = 0;
    char ch;

    while((ch = fgetc(fichier)) != EOF){
        if(ch == '\n'){
            compte++;
        }
    }
    return compte;
}

char buffer[512];

char *readStringFromFileUntil(FILE *f, char delim){
    char ch;
    int i = 0;
    memset(buffer, 0, sizeof(buffer));
    while((ch = fgetc(f)) != delim){
        buffer[i] = ch;
        i++;
    }
    char* result = (char *)malloc(i + 2);
    for(int k = 0; k < i; k++){
        result[k] = buffer[k];
    }
    return result;
}

void readWinner(Gagnant *winner, FILE *f){
    fscanf(f, "%" SCNd16 ";", &winner->annee);
    winner->nom = readStringFromFileUntil(f,";");
    winner->invention = readStringFromFileUntil(f,'\n');
    
}


//cette fonction doit creer un gros malloc de tous les winners
void readWinners(FILE *f){
    for (int i = 0; i<numberOfWinners(f); i++){
        Gagnant *winner;
        readWinner(&winner, fgets(i, 1024, f));
    }
}

