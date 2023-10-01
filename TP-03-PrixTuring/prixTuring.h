#include <stdio.h>
#include <inttypes.h>

typedef struct {
    int annee;
    char *nom;
    char *invention;
}Gagnant;

int numberOfWinners (FILE *fichier);

char *readStringFromFileUntil(FILE *f, char delim);

void readWinner(Gagnant *winner, FILE *f);

Gagnant *readWinners(FILE *f);

void printWinners (FILE *input, FILE *output, Gagnant *Winners);

void infoAnnee(Gagnant *winners, int annee);

void sortTuringWinnersByYear(FILE *file);
