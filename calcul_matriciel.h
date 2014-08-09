#ifndef CALCUL_MATRICIEL_H
#define CALCUL_MATRICIEL_H

#include "MatriceCarree.h"
#include "Matrice.h"

// fonction qui calcule la n-ieme puissane d'une matrice carree
MatriceCarree puissance(MatriceCarree A, int n); 

// fonction qui calcule le mineur d'une matrice en supprimant la i-ieme ligne et la j-ieme colonne
long double mineur(MatriceCarree const& A, int i, int j); // on evite de faire une copie inutile en ecrivant MatriceCarree const& A au lieu de MatriceCarree A

// fonction qui calcule la comatrice
MatriceCarree comatrice(MatriceCarree const& A);

// fonction qui calcule l'inverse
MatriceCarree inverse(MatriceCarree const& A);

#endif