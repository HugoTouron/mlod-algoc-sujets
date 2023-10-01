/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring

 Tests
 diff out.csv turingWinners.csv

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <inttypes.h>
#include "prixTuring.h"

// Ma fonction readWinners ne fonctionne pas, je suis beaucoup reste bloqué mais j'ai tout de meme essayer d'écrire les dernieres fonctions
int main(int argc, char** argv)
{
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";

	FILE *fichier = fopen(filename, "r");
	FILE *output = fopen(outputFilename, "w");	

	Gagnant *winners = readWinners(fichier);
	printWinners(fichier, output, winners);

 	fclose(output);
	fclose(fichier);


	return EXIT_SUCCESS;
}

