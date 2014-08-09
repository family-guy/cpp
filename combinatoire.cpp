#include "combinatoire.h"
#include "Matrice.h"

using namespace std;

unsigned long long factoriel(int x) // ca marche jusqu'a 22!
{
    if (x == 0 || x == 1)
    {
        return 1;
    }
    if (x > 1)
    {
        return x * factoriel(x - 1);
    }
}

int combinaisons(int k, int n) 
{
    return factoriel(n) / (factoriel(n - k) * factoriel(k));
}

Matrice ajouteLigne(Matrice const& A, int n)
{
	int p(A.getNbLignes()); int q(A.getNbColonnes());
	Matrice B(p + 1, q); // on cree une matrice de la taille voulue en utilisant l'un des constructeurs surcharges
	// on va la remplir comme il faut. Seulement la derniere ligne change
	int i(0); int j(0);
	while (i < p)
	{
		while (j < q)
		{
			B.getPointer()[i][j] = A.getPointer()[i][j];
			j++;
		}
		i++; j = 0;
	}
	// on change la derniere ligne et c'est la qu'on utilise le parametre n
	while (j < (n - 1)) 
    {
        B.getPointer()[i][j] = A.getPointer()[i - 1][j];
        j++;
    }
    while (j < q)
    {
        B.getPointer()[i][j] = A.getPointer()[i - 1][n - 1] + 1;
        j++;
    }
    return B;
}
	
int compteur(int k, int n, long double * T) 
{
    int i(0);
    while (i < k)
    {
        if (T[i] == (n - k))        
        {
            return i;
        }
        i++;
    }
    return i;
}	

Matrice listeCombinaisonsAux(Matrice A, int n)	// comme on retourne A, il faut faire une copie de A donc on ne peut pas declarer Matrice const& A comme parametre
												// c'est la meme situation qu'avec la fonction puissance
{
	int p(A.getNbLignes()); int q(A.getNbColonnes());
	if (p == combinaisons(q, n))	// q et n sont fixes alors que p augmente 1 chaque appel recursif
	{
		return A;
	}	
	else
	{
		return listeCombinaisonsAux(ajouteLigne(A, compteur(q, n, A.getPointer()[p - 1])), n);
	}
}

Matrice listeCombinaisonsAux1(int k, int n)
{
    Matrice B(combinaisons(k, n), k); // on cree la matrice a remplir
	int i(0); int j(0); 
    while (i < combinaisons(k, n))
    {
        while (j < k)
        {
            B.getPointer()[i][j] = j+1;
            j++;
        }
        i++; j = 0;
    }
    return B;
}

Matrice listeCombinaisons(int k, int n) 
{
    Matrice A(1, k); // on demarre avec cette matrice qui va etre nulle
    int j(0);
    while (j < k)
    {
        A.getPointer()[0][j] = 0;
        j++;
    }
    return listeCombinaisonsAux(A, n) + listeCombinaisonsAux1(k, n); // on fait la somme  
}