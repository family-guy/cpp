#ifndef CALCUL_MATRICIEL_H
#define CALCUL_MATRICIEL_H

#include "MatriceCarree.h"
#include "combinatoire.h"
#include "Polynome.h"

// fonction qui calcule la n-ieme puissane d'une matrice carree
MatriceCarree puissance(MatriceCarree A, int n); 

// fonction qui calcule le mineur d'une matrice en supprimant la i-ieme ligne et la j-ieme colonne
long double mineur(MatriceCarree const& A, int i, int j); // on evite de faire une copie inutile en ecrivant MatriceCarree const& A au lieu de MatriceCarree A

// fonction qui calcule la comatrice
MatriceCarree comatrice(MatriceCarree const& A);

// fonction qui calcule l'inverse
MatriceCarree inverse(MatriceCarree const& A);

// fonction qui supprime des lignes et des colonnes d'une matrice carree
MatriceCarree supprimeMultLigCol(MatriceCarree A, int t, int *T, int u); // u demarre tjs a 0, u est un compteur pr les appels recursifs
// t est le nb de lignes et colonnes de supprimer, T le tableau des indices a supprimer. On supprime a chaque fois la meme indice pr la ligne et la colonne car il s'agit de calculer les mineurs principals. On doit avoir T croissant

// fonction qui retourne la somme des mineurs principals ie etant donne un entier k < n ou n est la taille de la matrice, on supprime k lignes et k colonnes de toutes les manieres possibles et a chaque fois on calcule le determinant de la nouvelle matrice. Puis on fait la somme de tous ces determinants
long double sommeMineurs(MatriceCarree const&A, int k);

// fonction qui retourne le polynome caracteristique
Polynome polyCaract(MatriceCarree const&A);

#endif