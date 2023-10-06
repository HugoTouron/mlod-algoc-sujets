// Touron Hugo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "vaccins_covid.h"

// =========
// = Types =
// =========

const char NUCLEOTIDES[] = "ATCG";

typedef struct {
	int index;
	int distance;
}Difference;

// =============
// = Fonctions =
// =============


bool isNucleotide(char c) {
    return (c==NUCLEOTIDES[0] || c==NUCLEOTIDES[1] || c==NUCLEOTIDES[2] || c==NUCLEOTIDES[3]);
}

int indexOf(char nucleotide) {
	switch(nucleotide) {
		case 'A': return 0;
		case 'T': return 1;
		case 'C': return 2;
		case 'G': return 3;
		default:
			return -1;
	}
}

int distanceBetweenNucleotides(char n1, char n2) {
    return indexOf(n1)-indexOf(n2);
}

int *statistics(char *sequence){
	int i = 0;
	int Pa = 0;
	int Pt = 0;
	int Pc = 0;
	int Pg = 0;
	while(sequence[i] != '\0'){
		if(sequence[i] == 'A'){
			Pa++;
			i++;
		}
		if(sequence[i] == 'T'){
			Pt++;
			i++;
		}
		if(sequence[i] == 'C'){
			Pc++;
			i++;
		}
		if(sequence[i] == 'G'){
			Pg++;
			i++;
		}
	}
	int *res = malloc(4*sizeof(int));
	res[0] = (Pa*100/i);
	res[1] = (Pt*100/i);
	res[2] = (Pc*100/i);
	res[3] = (Pg*100/i);
	return res;
}

Difference **computeDifferencesBetween(char *sequence1, char *sequence2){
	int i = 0;
	int k = 0;
	Difference *buffer[512];
	while(sequence1[i] != '\0'){
		if(sequence1[i]==sequence2[i]){
			i++;
		}
		else{
			Difference *D = malloc(sizeof(Difference));
			D->distance = distanceBetweenNucleotides(sequence1[i], sequence2[i]);
			D->index = indexOf(sequence1[i]);
			buffer[k] = D;
			k++;
		}
	}
	Difference **res = malloc(k*sizeof(Difference));
	for(int j = 0; j < k; j++){
		res[j*sizeof(Difference)] = buffer[j];
	}
	return res;
}

// ========
// = Main =
// ========

int main(void){

	char sequenceDeNucleotides[]="ATGCATCCATCATGCATGTA";

	int * stats = statistics(sequenceDeNucleotides);

	printf("%d %d %d %d", stats[0], stats[1], stats[2], stats[3]);

	free(stats);
//    printf("%s\n",code_proteine_spike_moderna);

	return EXIT_SUCCESS;
}

