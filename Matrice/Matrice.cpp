#include "Matrice.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
	
	//methodes a l'interieur de la classe
	//voici le constructeur. Il est sans parametre. C'est le constructeur par defaut
	Matrice::Matrice() // on ecrit ceci au lieu de Matrice() comme d'habitude car on utilise la Matrice namespace qui vient du fait que Matrice est une classe		
	{
		m_nbLignes = 2;
		m_nbColonnes = 2;
		m_pointer = new long double *[2]; //m_pointer est du type int **. On lui alloue de l'espace pour 2 long double *
		m_pointer[0] = new long double[2]; //on alloue de l'espace pour 2 int ie 2 entiers
		m_pointer[1] = new long double[2]; //de meme ici
		//on a cree une matrice carree de dimension 2. On va maintenant la remplir
		m_pointer[0][0] = 1;
        m_pointer[0][1] = 0;
        m_pointer[1][0] = 0;
        m_pointer[1][1] = 1;		
	} //ie on cree par defaut la matrice identite I_2 ie si on tape Matrice A, on a A = I_2
	
	//le constructeur qui est surcharge. Cela permet l'utilisateur de renseigner les elements de la matrice et le nombre de lignes et de colonnes
	Matrice::Matrice(vector<long double> v, int nbLignes, int nbColonnes)
	{
		m_nbLignes = nbLignes;
		m_nbColonnes = nbColonnes;
		m_pointer = 0; // l'adresse 0 n'existe pas donc le pointeur ne pointe a aucune case memoire
		int a(nbLignes * nbColonnes);
		//ceci permet de recuperer la taille du vector entree en parametre
		int b(v.size()); //b est ainsi la taille du vector. D'ailleurs c'est pourquoi on ne fait pas entrer directement un tableau car il n'y a pas de fonction 
		// deja faite pour retourner la taille d'un tableau
		if (a != b) //on verifie que le tableau est la bonne taille
		{
			throw string("erreur avec la taille du tableau saisi"); //throw fait partie de try, throw et catch (le try et catch sont dans le main. 
			//ca peut sembler long mais c'est la bonne facon de faire les choses
		}
		else
		{
			//on cree la matrice
			m_pointer = new long double * [m_nbLignes];
			int i(0); //indice de lignes
			int j(0); //indice de colonnes
    		while (i < m_nbLignes)
    		{
        		m_pointer[i] = new long double [m_nbColonnes];
        		i++;
    		}
    		i = 0;
			//on la remplit
   	 		while (i < m_nbLignes)
    		{
        		while (j < m_nbColonnes)
        		{
            		m_pointer[i][j] = v[i * m_nbColonnes + j];
            		j++;
        		}
        		i++;
        		j = 0;
    		}
		}
	}
	
	// deuxieme constructeur surcharge
    Matrice::Matrice(int nbLignes, int nbColonnes)
    {
        // on cree une matrice de la bonne taille sans preciser ses valeurs
        m_pointer = new long double * [nbLignes];
        int i(0);
        while (i < nbLignes)
        {
            m_pointer[i] = new long double [nbColonnes];
            i++;
        }
        m_nbLignes = nbLignes;
        m_nbColonnes = nbColonnes;
    }
    // ie si on tape Matrice A(3, 7), cela cree une matrice 3x7 appelee A
	
	// le constructeur de copie. On va tout simplement
	Matrice::Matrice(Matrice const& A)
    {
		m_nbLignes = A.m_nbLignes;
    	m_nbColonnes = A.m_nbColonnes;
    	//on cree la matrice
    	m_pointer = new long double * [A.m_nbLignes];
    	int i(0); //indice de lignes
		while (i < A.m_nbLignes)
    	{
        	m_pointer[i] = new long double [A.m_nbColonnes];
        	i++;
    	}
    	//on la remplit
    	i = 0; int j(0);
    	while (i < A.m_nbLignes)
    	{
        	while (j < A.m_nbColonnes)
        	{
            	m_pointer[i][j] = A.m_pointer[i][j];
            	j++;
        	}
        	i++;
        	j = 0;
    	}
    }
    // ie si on tape Matrice A(B) ou B est une autre matrice, cela cree une matrice A = B	
	
	//le destructeur
	Matrice::~Matrice()
	{
		delete m_pointer; //on libere la case memoire
		m_pointer = 0; //on indique que le pointeur ne pointe plus
	}
	
	void Matrice::transposee()
	{
		long double ** dummy; //on cree un pointeur dummy pr copier la matrice actuelle
        dummy = new long double * [m_nbLignes];
        int i(0); //indice lignes
        while (i < m_nbLignes)
        {
            dummy[i] = new long double [m_nbColonnes];
            i++;
        }
        i = 0;
        int j(0); //indice colonnes
        while (i < m_nbLignes) // ici on remplit la matrice
        {
        	while (j < m_nbColonnes)
            {
            	dummy[i][j] = m_pointer[i][j];
                j++;
            }
            i++;
            j = 0;
        }
        i = 0;//on a cree une matrice dummy

        int a(0); //on echange le nombre de lignes et de colonnes
        a = m_nbLignes;
        m_nbLignes = m_nbColonnes;
        m_nbColonnes = a;

        delete m_pointer; //on libere la case memoire
        m_pointer = new long double * [m_nbLignes];
        while (i < m_nbLignes)
        {
        	m_pointer[i] = new long double [m_nbColonnes];	
        	i++;
        }
        i = 0; //voici la nouvelle matrice avec les bonnes dimensions
		while (i < m_nbLignes) // ici on remplit la matrice pour faire la transposition
        {
        	while (j < m_nbColonnes)
            {
            	m_pointer[i][j] = dummy[j][i]; 
                j++;
            }
            i++;
            j = 0;
        }
        //on n'a plus besoin du dummy
        delete dummy;
        dummy = 0;
	}
	
	void Matrice::multScal(long double lambda)
	{
    	int i(0);
	    int j(0);
    	while (i < m_nbLignes)
    	{
        	while (j < m_nbColonnes)
        	{
            	m_pointer[i][j] *= lambda;
            	j++;
        	}
        	i++;
        	j = 0;
    	}
	}
	
	void Matrice::affichage() const
	{
		int i(0); int j(0); //les lignes et les colonnes
        while (i < m_nbLignes)
        {
            while (j < m_nbColonnes)
            {
                cout << m_pointer[i][j] << " ";
                j++;
            }
            i++; j = 0; cout << endl;
        }
	}
	
	void Matrice::changerUnElement(int i, int j, long double x)
	{
		m_pointer[i-1][j-1] = x;// il faut decaler une case
	}
	
	//les accesseurs
	int Matrice::getNbLignes() const
	{
		return m_nbLignes;
	}
	
	int Matrice::getNbColonnes() const
	{
		return m_nbColonnes;
	}
	
	long double ** Matrice::getPointer() const
    {
        return m_pointer;
    }
    
    //d'autres methodes
    void Matrice::echangeLignes(int p, int q)
    {
    	// attention au decalage des indices
    	// on copie ligne p dans un tableau 
    	long double * t(0);
    	t = new long double[m_nbColonnes];
    	int j(0);
    	while (j < m_nbColonnes)
    	{
    		t[j] = m_pointer[p-1][j]; //on decale l'indice d'ou p-1
    		j++;
    	}
    	// on remplace ligne p par ligne q
    	j = 0;
    	while (j < m_nbColonnes)
    	{
    		m_pointer[p-1][j] = m_pointer[q-1][j];
    		j++;
    	}
    	// on remplace ligne q par ligne p
    	j = 0;
    	while (j < m_nbColonnes)
    	{
    		m_pointer[q-1][j] = t[j];
    		j++;
    	}
    }
    
    bool Matrice::estPremiereColonneNulle() const
    {
    	int i(0);
    	long double somme(0);
    	while (i < m_nbLignes)
    	{
        	somme = somme + fabs(m_pointer[i][0]);
        i++;
    	}
    	if (somme == 0)
    	{
        	return true;
    	}
    	else
    	{
        	return false;
    	}
    }
    
    bool Matrice::estLigneNulle(int q) const
    {
    	int j(0);
    	long double somme (0);
    	while (j < m_nbColonnes)
    	{
        	somme = somme + fabs(m_pointer[ (q-1) ][j]); // decaler l'indice
        j++;
    	}
    	if (somme == 0)
    	{
        	return true;
    	}
    	else
    	{
        	return false;
    	}
    }
    
    void Matrice::supprimeLigne(int k)
    {
    	m_nbLignes += -1;
    	int i(k - 1); // pr les lignes
    	int j(0); // pr les colonnes
    	while (i < m_nbLignes)
    	{
    		while(j < m_nbColonnes)
    		{
    			m_pointer[i][j] = m_pointer[i + 1][j];
    			j++;
    		}
    		j = 0; 
    		i++;
    	}
    }
    
    void Matrice::supprimeColonne(int k)
    {
    	m_nbColonnes += -1;
    	int j(k - 1);
    	int i(0);
    	while (j < m_nbColonnes)
    	{
    		while (i < m_nbLignes)
    		{
    			m_pointer[i][j] = m_pointer[i][j + 1];
    			i++;
    		}
    		i = 0; 
    		j++;
    	}
    }
    
    void Matrice::supprimeLigCol(int k, int l)
    {
    	this->supprimeLigne(k);
    	this->supprimeColonne(l);
    }
		
	//fonctions a l'exterieur de la classe
	// la surchage des operateurs
	// pr ==
	bool operator==(Matrice const& A, Matrice const& B) //! on est a l'exterier de la classe a cause de l'operateur !=. Donc ce n'est pas une methode
    {
        if (A.getNbLignes() != B.getNbLignes() || A.getNbColonnes() != B.getNbColonnes()) // on a besoin des accesseurs
        {
            return false;
        }
        else
        {
            int i(0); int j(0);
            while (i < A.getNbLignes()) 
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
    
    bool operator!=(Matrice const& A, Matrice const& B) //! on est a l'exterier de la classe a cause de l'operateur !=. Donc ce n'est pas une methode
    {
        if (A.getNbLignes() != B.getNbLignes() || A.getNbColonnes() != B.getNbColonnes())
        {
            return true;
        }
        else
        {
            int i(0); int j(0);
            while (i < A.getNbLignes()) 
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
    
    Matrice operator+(Matrice const& A, Matrice const& B)
    {
    	if (A.getNbLignes() != B.getNbLignes() || A.getNbColonnes() != B.getNbColonnes())
    	{
    		throw string("Erreur. Matrices à sommer n'ont pas les mêmes dimensions");
    	}
    	else
    	{
    		//on construit la matrice a retourner en utilisant un constructeur surcharge
    		//on va creer une matrice de la bonne taille quelconque
    		Matrice Somme(A.getNbLignes(), A.getNbColonnes());
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
    
    Matrice operator*(Matrice const& A, Matrice const& B)
    {
    	if (A.getNbColonnes() != B.getNbLignes())
    	{
    		throw string("Erreur. Le produit de ces deux matrices n'est pas defini");
    	}
    	else
    	{
    		//on construit la matrice a retourner en utilisant un constructeur surcharge
	    	Matrice Produit(A.getNbLignes(), B.getNbColonnes());
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
	    	
    Matrice operator-(Matrice const& A, Matrice const& B)
    {
    	if (A.getNbLignes() != B.getNbLignes() || A.getNbColonnes() != B.getNbColonnes())
    	{
    		throw string("Erreur. Matrices à soustraire n'ont pas les mêmes dimensions");
    	}
    	else
    	{
    		//on construit la matrice a retourner en utilisant un constructeur surcharge
    		Matrice Soustraction(A.getNbLignes(), A.getNbColonnes());
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
	
