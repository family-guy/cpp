#include "calcul_matriciel.h"
#include "MatriceCarree.h"
#include "Matrice.h"
#include <vector>
#include <cassert>

using namespace std;

MatriceCarree puissance(MatriceCarree A, int n) //n la puissance
{
    if (n == 0)
    {
    	A.identite();
        return A;
    }
    if (n == 1)
    {
        return A;
    }
	else
    {
        return A * puissance(A, n - 1);
    }
}

long double mineur(MatriceCarree const& A, int i, int j)
{
    int m(A.getNbLignes() - 1); // pr eviter de repeter A.getNbLignes() - 1
    vector<long double> v(m * m, 0); // on cree un vecteur nul de taille m^2 
    MatriceCarree M(v, m, m); // on cree une instance de MatriceCarree appelee M qui est la matrice nulle
    int p(i - 1); // le compteur pr les lignes est decale car on supprime la i-ieme ligne
    int q(j - 1); // le compteur pr les colonnes est decale car on supprime la j-ieme colonne
    if (m + 1 == 1) // A est un scalaire donc c'est fini et quelles que soient les valeurs de i et j
    {
        return A.det();
    }
    else // A n'est pas un scalaire donc il faut trouver la bonne sous matrice selon les valerus de i et j
    {
        int k(0); // noveaux compteurs
        int l(0);
        while (k < m)
        {
        	while (l < m)
            {
            	if ((k < p) && (l < q))
                {
                	M.getPointer()[k][l] = A.getPointer()[k][l];
                }
				if ((k < p) && (l >= q))
                {
                	M.getPointer()[k][l] = A.getPointer()[k][l+1];
                }
				if ((k >= p) && (l < q))
                {
                	M.getPointer()[k][l] = A.getPointer()[k+1][l];
                }
				if ((k >= p) && (l >= q))
                {
                    M.getPointer()[k][l] = A.getPointer()[k+1][l+1];
                }
				l++;
            }
			l = 0;
            k++;
        }
    }
    return M.det(); //par defn le mineur est le determinant de la sous matrice
}

MatriceCarree comatrice(MatriceCarree const& A)
{
	MatriceCarree B(A.getNbLignes(), A.getNbColonnes());
    int i(0); int j(0);
    int n(A.getNbLignes());
    while (i < n)
    {
    	while (j < n)
        {
        	if ((i+j)%2 == 0)
            {
            	B.getPointer()[i][j] = mineur(A, i + 1, j + 1);
            }
			else
			{
				B.getPointer()[i][j] = -1 * mineur(A, i + 1, j + 1);
			}
			j++;
		}
		j = 0;
		i++;
	}
    return B;
}

MatriceCarree inverse(MatriceCarree const& A)
{
    assert(A.det() != 0);
    MatriceCarree B = comatrice(A);
    B.transposee();
    B.multScal(1 / A.det());
    return B;
}