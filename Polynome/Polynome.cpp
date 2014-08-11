#include "Polynome.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Polynome::Polynome()
{
	m_degre = 0;
	m_anneau = "reels";
	m_pointeur = new long double[m_degre + 1];
	m_pointeur[0] = 1;
}

Polynome::Polynome(vector<long double> v, int d)
{
	m_degre = d;
	m_anneau = "reels";
	m_pointeur = new long double[m_degre + 1];
	if (v.size() != d + 1)
	{
		throw string ("Erreur. Le degré ne correspond pas au nombre de coefficients saisi");
	}
	else
	{
		int i(0);
		while (i < v.size())
		{
			m_pointeur[i] = v[i];
			i++;
		}
	}
}

Polynome::Polynome(int d)
{
	m_degre = d;
	m_anneau = "reels";
	m_pointeur = new long double[m_degre + 1];
	int i(0);
	while (i < m_degre + 1)
	{
		m_pointeur[i] = 1;
		i++;
	}
}

Polynome::Polynome(Polynome const& P)
{
	m_degre = P.m_degre;
	m_anneau = P.m_anneau;
	m_pointeur = new long double[P.m_degre + 1];
	int i(0);
	while (i < P.m_degre + 1)
	{
		m_pointeur[i] = P.m_pointeur[i];
		i++;
	}
}

Polynome::~Polynome()
{
	delete m_pointeur; //on libere la case memoire
	m_pointeur = 0; //on indique que le pointeur ne pointe plus
}

void Polynome::multScal(long double lambda)
{
	int i(0);
	while (i < m_degre + 1)
	{
		m_pointeur[i] *= lambda;
		i++;
	}
}

void Polynome::affichage() const
{
	if (estPolyNul())
	{
		cout << "0";
	}
	else
	{
		int i;
		for (i = 0; i < m_degre + 1; i++)
		{
			if (m_pointeur[i] != 0)
			{
				if (i == 0)
				{
					cout << m_pointeur[i];
				}
				if (i == 1)
				{
					if (m_pointeur[i] == 1)
					{
						cout << " +X";
					}
					if (m_pointeur[i] == -1)
					{
						cout << " -X";
					}
					if (m_pointeur[i] != 1 && m_pointeur[i] > 0)
					{
						cout << " +" << m_pointeur[i] << "X";
					}
					if (m_pointeur[i] != -1 && m_pointeur[i] < 0)
					{
						cout << " " << m_pointeur[i] << "X";
					}
				}
				if (i > 1)
				{
					if (m_pointeur[i] == 1)
					{
						cout << " +X^" << i;
					}
					if (m_pointeur[i] == -1)
					{
						cout << " -X^" << i;
					}
					if (m_pointeur[i] != 1 && m_pointeur[i] > 0)
					{
						cout << " +" << m_pointeur[i] << "X^" << i;
					}
					if (m_pointeur[i] != -1 && m_pointeur[i] < 0)
					{
						cout << " " << m_pointeur[i] << "X^" << i;
					}
				}
			}
			else
			{
			}
		}
	}
} 

bool Polynome::estPolyNul() const
{
	int i(0);
	while (i < m_degre + 1)
	{
		if (m_pointeur[i] != 0)
		{
			return false;
		}
		else
		{
			i++;
		}
	}
	return true;
}

int Polynome::getDegre() const
{
	return m_degre;
}

string Polynome::getAnneau() const
{
	return m_anneau;
}

long double * Polynome::getPointeur() const
{
	return m_pointeur;
}
