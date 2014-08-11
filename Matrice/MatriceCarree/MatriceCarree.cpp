#include "MatriceCarree.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

	MatriceCarree::MatriceCarree()	 // le constructeur par defaut. Lorsque l'on l'appelle, ca va creer la matrice I_2 (c'est l'heritage qui le fait)
	{
		
	}
	/*j'imagine que ceci equivaut a
	MatriceCarree::MatriceCarree()
	{
		Matrice();
	}
	*/
	
	//le constructeur surcharge.
	MatriceCarree::MatriceCarree(std::vector<long double> v, int nbLignes, int nbColonnes) : Matrice(v, nbLignes, nbColonnes)
	{
		
	}
	// : Matrice(v, nbLignes, nbColonnes) il faut tjs avoir cette partie 
	
	// deuxieme constructeur surcharge
	MatriceCarree::MatriceCarree(int nbLignes, int nbColonnes) : Matrice(nbLignes, nbColonnes)
	{

	}
	
	// le constructeur de copie
	MatriceCarree::MatriceCarree(MatriceCarree const& A) : Matrice(A)
	{
    	
	}
		
	long double MatriceCarree::det() const
	{
		if (m_nbLignes == 1)
    	{
        	return m_pointer[0][0];
    	}

    	if (m_nbColonnes == 2)
    	{
        	return m_pointer[0][0] * m_pointer[1][1] - m_pointer[0][1] * m_pointer[1][0];
    	}

    	else
    	{
        	int k(0);
        	int j(0);
        	long double somme (0);
        	//on cree une matrice carree de taille n-1 qui va devenir le minuer
        	MatriceCarree sousMatrice(m_nbLignes - 1, m_nbLignes - 1);
        	//il faut modifier les elements de sousMatrice	
        	int i(0);
        	while (i < m_nbLignes)
        	{		
        		while (k < i)
                {
                    while (j < m_nbLignes - 1)
                    {
                        sousMatrice.m_pointer[j][k] = m_pointer[j+1][k];
                    	j++;
                	}
                	j = 0;
                	k++;
            	}
            while ((k > i - 1) && (k < m_nbLignes - 1))
            {
                while (j < m_nbLignes - 1)
                {
                    sousMatrice.m_pointer[j][k] = m_pointer[j+1][k+1];
                    j++;
                }
                j = 0;
                k++;
            }
            k = 0;
            if (i % 2 == 0)
            {
                somme = somme + sousMatrice.det() * m_pointer[0][i];
            }
            if (i % 2 != 0)
            {
                somme = somme - sousMatrice.det() * m_pointer[0][i];
            }
            i++;
        	}
        	return somme;
    	}
	}
	
	void MatriceCarree::identite()
	{
		int i(0);
    	int j(0);
    	while (i < m_nbLignes)
    	{
        	while (j < m_nbLignes)
        	{
            	if (i == j)
            	{
                	m_pointer[i][j] = 1;
            	}
            	else
            	{	
                	m_pointer[i][j] = 0;
            	}
            	j++;
        	}
        	i++;
        	j = 0;
    	}
	}
		
	//fonctions a l'exterieur de la classe
	// la surchage des operateurs
	// pr ==
	bool operator==(MatriceCarree const& A, MatriceCarree const& B) //! on est a l'exterier de la classe a cause de l'operateur !=. Donc ce n'est pas une methode
    {
        if (A.getNbLignes() != B.getNbLignes() || A.getNbColonnes() != B.getNbColonnes())
        {
            return false;
        }
        else
        {
            int i(0); int j(0);
            while (i < A.getNbLignes()) // il faut utiliser getNbLignes car on ne peut pas lire m_nbLignes
            {
                while (j < A.getNbColonnes())
                {
                    if (A.getPointer()[i][j] != B.getPointer()[i][j])
                    {
                        return false;
                    }
                    else
                    {
                        j++;
                    }
                }
                j = 0; i++;
            }
        }
        return true;
    }
    
    bool operator!=(MatriceCarree const& A, MatriceCarree const& B) //! on est a l'exterier de la classe a cause de l'operateur !=. Donc ce n'est pas une methode
    {
        if (A.getNbLignes() != B.getNbLignes() || A.getNbColonnes() != B.getNbColonnes())
        {
            return true;
        }
        else
        {
            int i(0); int j(0);
            while (i < A.getNbLignes()) // il faut utiliser getNbLignes car on ne peut pas lire m_nbLignes
            {
                while (j < A.getNbColonnes())
                {
                    if (A.getPointer()[i][j] != B.getPointer()[i][j])
                    {
                        return true;
                    }
                    else
                    {
                        j++;
                    }
                }
                j = 0; i++;
            }
        }
        return false;
    }
    
    MatriceCarree operator+(MatriceCarree const& A, MatriceCarree const& B)
    {
    	if (A.getNbLignes() != B.getNbLignes() || A.getNbColonnes() != B.getNbColonnes())
    	{
    		throw string("Erreur. Matrices à sommer n'ont pas les mêmes dimensions");
    	}
    	else
    	{
    		//on construit la matrice a retourner en utilisant un constructeur surcharge
    		MatriceCarree Somme(A.getNbLignes(), A.getNbColonnes());
    		// on la remplit
	    	int i(0); int j(0);
    		while (i < A.getNbLignes()) // ici on remplit la matrice
    		{
        		while (j < A.getNbColonnes())
        		{
            		Somme.getPointer()[i][j] = A.getPointer()[i][j] + B.getPointer()[i][j]; // on fait la somme element par element
	            	j++;
    	    	}
        		i++;
        		j = 0;
    		}
	    	return Somme;
    	}
    }
    
    MatriceCarree operator*(MatriceCarree const& A, MatriceCarree const& B)
    {
    	if (A.getNbColonnes() != B.getNbLignes())
    	{
    		throw string("Erreur. Le produit de ces deux matrices n'est pas defini");
    	}
    	else
    	{
    		//on construit la matrice a retourner en utilisant un constructeur surcharge
	    	MatriceCarree Produit(A.getNbLignes(), B.getNbColonnes());
	    	//on la remplit
	    	int i(0); int j(0); int z(0);
    		long double somme(0);
			while (i < A.getNbLignes())
    		{
        		while (j < B.getNbColonnes())
        		{
            		while (z < A.getNbColonnes())
            		{
                		somme = somme + A.getPointer()[i][z] * B.getPointer()[z][j];
                		z++;
            		}
            		z = 0;
            		Produit.getPointer()[i][j] = somme;
            		somme = 0;
            		j++;
        		}
        		i++;
        		j = 0;
    		}
    		return Produit;
    	}
    }
	
	MatriceCarree operator-(MatriceCarree const& A, MatriceCarree const& B)
    {
    	if (A.getNbLignes() != B.getNbLignes() || A.getNbColonnes() != B.getNbColonnes())
    	{
    		throw string("Erreur. Matrices à soustraire n'ont pas les mêmes dimensions");
    	}
    	else
    	{
    		//on construit la matrice a retourner en utilisant un constructeur surcharge
    		MatriceCarree Soustraction(A.getNbLignes(), A.getNbColonnes());
    		// on la remplit
	    	int i(0); int j(0);
    		while (i < A.getNbLignes()) // ici on remplit la matrice
    		{
        		while (j < A.getNbColonnes())
        		{
            		Soustraction.getPointer()[i][j] = A.getPointer()[i][j] - B.getPointer()[i][j]; // on fait la soustraction element par element
	            	j++;
    	    	}
        		i++;
        		j = 0;
    		}
	    	return Soustraction;
    	}
    }
