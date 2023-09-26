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
#include "prixTuring.h"


int main(int argc, char** argv)
{
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";

    FILE *fichier = fopen(filename, "r");
	FILE *output = fopen(outputFilename, "w");

	printf("%d", numberOfWinners(fichier));

	fclose(output);
	fclose(fichier);

	return EXIT_SUCCESS;
}
