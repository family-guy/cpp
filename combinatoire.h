#ifndef COMBINATOIRE_H
#define COMBINATOIRE_H

#include "Matrice.h"

// fonction qui calcule le factoriel d'un entier x, 0 <= x <= 22
unsigned long long factoriel (int x);

// fonction qui calcule k parmi n (n < 21)
int combinaisons (int k, int n);

/*
===========================================================================================================================================================================
                                                    LISTER LES ELEMENTS DE K PARMI N
===========================================================================================================================================================================
*/
// d'abord deux fonctions preliminaires
// fonction qui ajoute une ligne a une matrice d'une facon particuliere selon un parametre n
Matrice ajouteLigne(Matrice const& A, int n);

// fonction qui prend n et k et renvoie un entier, celui qui te dit ou est la premiere case du tableau ou on voit n - k
int compteur(int k, int n, long double * T); // T est un tableau de longeur k

// la fonction cle. On va se servir des deux fonctions precedentes. C'est une fonction recursive ou le nombre de lignes de la matrice A est le compteur de recursivite
Matrice listeCombinaisonsAux(Matrice A, int n); // n est un parametre

// fonction qui cree une matrice ou chaque ligne est 1, 2, ..., q   	
Matrice listeCombinaisonsAux1(int k, int n); // k et n sont deux parametres qui determinent la taille de la matrice retournee

// enfin la fonction principale. On fait la somme de listeCombinaisonsAux et listeCombinaisonsAux1 pour trouver le resultat recherche
Matrice listeCombinaisons(int k, int n);
// il faut juste ecrire par ex listeCombinaisons(2, 6).affichage(); pr afficher les elements de 2 parmi 6

#endif