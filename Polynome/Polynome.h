#ifndef DEF_POLYNOME
#define DEF_POLYNOME

#include <vector>
#include <string>

class Polynome
{
	// voici les methodes
	public:
	
	// le constructeur par defaut. Cela va creer le polynome constant 1
	Polynome();
	
	// constructeur surcharge ou l'utilisateur precise les coefficients
	Polynome(std::vector<long double> v, int d);
	
	// constructeur surcharge ou l'utilisateur precise seulement le degre. On met les coefficients tous a un
	Polynome(int d);
	
	// constructeur de copie
	Polynome(Polynome const& P);
	
	// le destructeur
	~Polynome();
	
	// methode qui fait une multiplication scalaire
	void multScal(long double lambda);
	
	// methode qui affiche le polynome
	void affichage() const;
	
	// methode qui verifie si le polynome est nul
	bool estPolyNul() const;
	
	int getDegre() const;
	
	std::string getAnneau() const;
	
	long double * getPointeur() const;
	
	// voici les attributs
	protected:
	
	int m_degre;
	
	std::string m_anneau;
	
	long double *m_pointeur; // c'est ainsi on stocke les coefficients
};

#endif