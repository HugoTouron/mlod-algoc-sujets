#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <inttypes.h>
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



char *readStringFromFileUntil(FILE *f, char delim){
    char buffer[1024];
    char c;
    int i = 0;
    memset(buffer, 0, sizeof(buffer));
    while((c = fgetc(f)) != delim){
        buffer[i] = c;
        i++;
    }
    char *resultat = (char*)malloc(i+2);
    for(int k = 0; k < i; k++){
        resultat[k]=buffer[k];
    }
    return resultat;
}

void readWinner(Gagnant *winner, FILE *f){
    fscanf(f, "%d" SCNd16 ";", &winner->annee);
    winner->nom = readStringFromFileUntil(f,';');
    winner->invention = readStringFromFileUntil(f,'\n');
}


Gagnant *readWinners(FILE *f){
    int N = numberOfWinners(f);
    Gagnant *Winners = (Gagnant*)malloc(N * sizeof(Gagnant));
    for (int i = 0; i<N; i++){
        readWinner(&Winners[i], f);
    }
    return Winners;
}

void printWinners (FILE *input, FILE *output, Gagnant *Winners){
    int N = numberOfWinners(input);
    for (int i = 0; i < N; i++){
        fprintf(output,"%d;%s;%s\n", &Winners[i].annee, &Winners[i].nom, &Winners[i].invention);
    }
}

void infoAnnee(Gagnant *winners, int annee){
	int i = 0;
	while (winners[i].annee != 0){
		if (winners[i].annee == annee){
			printf("L'annee %d, le(s) gagnant(s) ont ete : %s\n", winners[i].annee, winners[i].nom);
			printf("Nature des travaux : %s", winners[i].invention);
			break;
		}
		i++;
	}
}

void sortTuringWinnersByYear(FILE *file){
    int N = numberOfWinners(file);
    Gagnant *winners = readWinners(file);
    Gagnant temp;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (winners[j].annee > winners[j + 1].annee) {
                temp = winners[j];
                winners[j] = winners[j + 1];
                winners[j + 1] = temp;
            }
        }
    }
}
