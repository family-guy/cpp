#ifndef DEF_MATRICE
#define DEF_MATRICE

#include <vector>

class Matrice				
{
	//methodes. Elles seront publiques cad accesibles depuis l'exterieur
	public:
	
	Matrice(); //le constructeur. Il s'agit d'une methode un peu particuliere. Il faut qu'il ait le meme nom que la classe et il ne faut rien envoyer, pas meme void.
	// Lorsque l'on tape simplement Matrice A pr creer une nouvelle matrice A, le constructeur par defaut ie celui-ci va etre appele
	
	Matrice(std::vector<long double> v, int nbLignes, int nbColonnes); //on surchage le constructeur. Comme ca on peut donner des parametres au constructeur
	//si on a un tableau par ex. fourni par l'utilisateur comme long double T[] = {1, 2, 3, 4, 5, 6}, il faut faire vector<long double> w (T, T + sizeof(T) / sizeof(long double) );
	//on a mis un throw. Donc dans le main il faut faire
	/* try //c'est dans la partie qui suit qu'il y a une possibilite d'une erreur
    {
		Matrice C(w, 3, 2);  	
    }
    catch(string const& chaine) //dans Matrice.cpp on avait un throw type avec type = string d'ou catch string. On l'appelle chaine
    {
    	cerr << chaine << endl; //on affiche chaine
    }*/
    
    Matrice(int nbLignes, int nbColonnes); // deuxieme constructeur surcharge. Ca va construire une matrice quelconque de la taille voulue
    
    Matrice(Matrice const& A); // constructeur de copie. On le declare explicitement. Sinon, le constructeur de copie par defaut donne le comportement suivant : Supposons qu'il existe une matrice A. On ecrit Matrice B = A; si maintenant on change A, B change aussi
	
	~Matrice(); //le destructeur, il n'a pas de type a renvoyer ni de parametre. Il est tjs comme ca
	
	void transposee(); // void car on ne retourne rien. Il n'y a pas de parametres. On ecrit A.transposee et ceci va modifier A t.q A = t^A
	
	void multScal(long double lambda);
	
	void affichage() const; //c'est une methode constante car elle ne modifie aucun attribut
	
	void changerUnElement(int i, int j, long double x); //on met la valeur x pour l'element dans la i-eme ligne et la j-ieme colonne
	
	int getNbLignes() const; // lorsque l'on est a l'exterieur de la classe par ex. dans un programme main, on ne peut pas lire les attributs. Donc on ne peut pas savoir
	// le nombre de lignes de la matrice. Cependant on peut utiliser les methodes (on a mis le mot cle public en haut) et dans la definition d'une methode, comme on est a
	// l'interier de la classe, on peut lire l'attribut m_nbLignes. Il s'agit d'un accesseur. Pourquoi faire tout cela? C'est justement l'un des interets de creer une 	classe et faire de la POO : le createur controle ce qu'il peut faire l'utilisateur
	
	int getNbColonnes() const;
	
	long double ** getPointer() const;
	
	void echangeLignes(int p, int q); // on echange lignes p et q
	
	bool estPremiereColonneNulle() const; //on teste si la premiere colonne est nulle
	
	bool estLigneNulle(int q) const; // on teste si la q-ieme ligne est nulle
	
	void supprimeLigne(int k); // on supprime la k-ieme ligne
	
	void supprimeColonne(int k); // on supprime la k-ieme colonne
	
	void supprimeLigCol(int k, int l); // on supprime la k-ieme ligne et la l-ieme colonne

	//attributs. Ils seront prives ie inaccesibles depuis l'exterieur
	protected: //ENCAPSULATION : TOUS LES ATTRIBUTS D'UNE CLASSE DOIVENT TJS ETRE PRIVES
	//on a change a "protected" pour donner acces aux attributs pour les classes filles de Matrice	
	
	int m_nbLignes; //le m montre qu'il s'agit d'un attribut (car attribut se dit aussi variable membre)
	
	int m_nbColonnes;
	
	long double ** m_pointer; //on met les elements de la matrice dans un tableau 2D en utilisant un pointeur d'un pointeur
	// nos attributs sont ainsi declares mais ils ne sont pas initialises! Pourquoi? Car on n'a pas le droit de le faire ici.
	// c'est dans le constructeur qu'il faut le faire
	// neanmoins si les attributs ci-dessus etaient des objets (au lieu des variables de type classique), ils seraient initialises automatiquement avec une valeur par 		defaut
}; /* FIN DE LA DEFINITION DE LA CLASSE MATRICE */

	// surcharge des operateurs ie +, -, *, /, ==, !=, <, >, etc.
	bool operator==(Matrice const& A, Matrice const& B); //pr voir si deux matrices sont egales. Il s'agit de la surchage de l'operateur ==. C'est une fonction normale
	//situee a l'exterieur de toute classe. Les & signifient qu'on a un passage par reference, pas par copie ce qui evite de copier les matrices A et B. Neanmoins, on
	//on ne veut pas modifier les deux objets (matrices) recus en argument d'ou le const.
	
	bool operator!=(Matrice const& A, Matrice const& B); //meme chose mais avec !=
	
	Matrice operator+(Matrice const& A, Matrice const& B); //additionner deux matrices. Il y a un throw donc dans le main il faut mettre un try et catch
	
	Matrice operator*(Matrice const& A, Matrice const& B); //multiplier deux matrices. Il y a un throw donc dans le main il faut mettre un try et catch
	
	Matrice operator-(Matrice const& A, Matrice const& B); //soustraire deux matrices. Il y a un throw donc dans le main il faut mettre un try et catch

#endif