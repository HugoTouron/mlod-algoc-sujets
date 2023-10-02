#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste l;
	l = (Cellule*)malloc(sizeof(Cellule));
	l->val = v;
	l->suiv = NULL;
	return l;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Cellule *cell = creer(v);
	cell->suiv = l;
	return cell;
}


void afficheElement(Element e) {
	printf("%i ",e);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	Cellule *cell = l;
	while(cell->suiv != NULL){
		afficheElement(cell->val);
		cell = cell->suiv;
	}
	afficheElement(cell->val);
}

// version recursive
void afficheListe_r(Liste l) {
	if(l==NULL){
		printf('\n');
	}
	else{
		afficheElement(l->val);
		afficheListe_r(l->suiv);
	}
}

void detruireElement(Element e) {
}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Cellule *cell;
	while (l != NULL){
		cell = l->suiv;
		detruireElement(l->val);
		free(l);
		l = cell;
	}
}

// version récursive
void detruire_r(Liste l) {
	Cellule *cell;
	if(l != NULL){
		cell = l->suiv;
		free(l);
		detruire_r(cell);
	}
}


// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	if(estVide(l)){
		return creer(v);
	}
	Cellule *cell = l;
	while(cell->suiv != NULL){
		cell = cell->suiv;
	}
	cell->suiv = creer(v);
	return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if(estVide(l)){
		return creer(v);
	}
	else{
		l->suiv = ajoutFin_r(v, l->suiv);
		return l;
	}
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	while(!estVide(l) && !equalsElement(v, l->val)){
		l = l->suiv;
	}
	return(l);
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if(!estVide(l) && !equalsElement(v, l->val)){
		cherche_r(v, l->suiv);
	}
	return l;
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Cellule *elem = cherche_i(v, l);
	
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	return TODO;
}


void afficheEnvers_r(Liste l) {
	TODO;
}



