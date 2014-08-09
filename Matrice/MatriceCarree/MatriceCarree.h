#ifndef DEF_MATRICECARREE
#define DEF_MATRICECARREE

#include <vector>
#include "Matrice.h"

//il s'agit de l'heritage. La classe MatriceCarree est une classe fille de Matrice
class MatriceCarree : public Matrice // cela cree une classe MatriceCarree qui herite de la classe Matrice. Ainsi elle contient toutes les memes methodes et attributs
{
	public:		
		
	//le constructeur
	MatriceCarree();
	
	//le constructeur surcharge
	MatriceCarree(std::vector<long double> v, int nbLignes, int nbColonnes); //il faut y avoir les memes parametres que dans le constructeur surcharge de la classe Matrice
	// on peut ajouter des parametres de plus
	
	// deuxieme constructeur surcharge comme dans la classe Matrice
	MatriceCarree(int nbLignes, int nbColonnes);
	
	// le constructeur de copie
	MatriceCarree(MatriceCarree const& A);
	
	//on ajoute des methodes qui ne s'appliquent qu'aux objets de type MatriceCarree (il ne faut pas declarer les autres car elles existent deja par heritance)
	// methode qui renvoie le determinant 
	long double det() const;
	
	// methode qui donne la matrice identite
	void identite();
	
	protected:
	// pas de nouvels attributs
};

// puisque les operateurs surcharges sont a l'exterieur de la classe Matrice, il faut les redeclarer pour les utiliser avec des objets de la classe MatricesCarree
	bool operator==(MatriceCarree const& A, MatriceCarree const& B); //pr voir si deux matrices sont egales. Il s'agit de la surchage de l'operateur ==. C'est une fonction normale
	//situee a l'exterieur de toute classe. Les & signifient qu'on a un passage par reference, pas par copie ce qui evite de copier les matrices A et B. Neanmoins, on
	//on ne veut pas modifier les deux objets (matrices) recus en argument d'ou le const.
	
	bool operator!=(MatriceCarree const& A, MatriceCarree const& B); //meme chose mais avec !=
	
	MatriceCarree operator+(MatriceCarree const& A, MatriceCarree const& B); //additionner deux matrices. Il y a un throw donc dans le main il faut mettre un try et catch
	
	MatriceCarree operator*(MatriceCarree const& A, MatriceCarree const& B); //multiplier deux matrices. Il y a un throw donc dans le main il faut mettre un try et catch

	MatriceCarree operator-(MatriceCarree const& A, MatriceCarree const& B); //soustraire deux matrices. Il y a un throw donc dans le main il faut mettre un try et catch
	
#endif