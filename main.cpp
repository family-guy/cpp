#include <iostream>
#include "Matrice.h"
#include "MatriceCarree.h"
#include <string>
#include "calcul_matriciel.h"
#include "combinatoire.h"
#include "Polynome.h"

using namespace std;

int main()
{	
	cout << "================================================================================================================================================================";
	cout << endl;
	cout << "                              Welcome to linear algebra" << endl;
	cout << "================================================================================================================================================================";
	cout << endl << "The following general matrix operations are supported" << endl << "1. Addition" << endl << "2. Subtraction" << endl << "3. Scalar multiplication" << 	endl << "4. Multiplication" << endl << "5. Transposition" << endl << "6. Gauss-Jordan algorithm" << endl << endl << "And for square matrices" << endl << "7. Determinant" << endl << "8. Adjugate" << endl << 	"9. Inverse" << endl << "10. n-th power" << endl << "11. Characteristic polynomial" << endl << endl << "*** Elements of a matrix to be entered by line when prompted e.g. for the matrix Id_2 enter 1 0 0 1 ***" << endl << endl << "Please select one of the following types of matrix" << endl << 	"1. General matrix" << endl << "2. Square matrix" << endl;
	int r(0);
	do 
	{
		cin >> r;
	}
	while (r != 1 && r != 2);
	if (r == 1)
	{
		cout << "You have selected general matrix. Please select your operation" << endl;
		int s(0);
		cin >> s;
		// declaration of variables to be used in the switch
		int nbLinesA(0); int nbColA(0); int nbLinesB(0); int nbColB(0);
		switch (s)
		{
			case 1:
			{
				cout << "You have selected addition. Please enter the number of lines and columns of each matrix" << endl;
				cin >> nbLinesA >> nbColA;
				cout << "Please enter the " << nbLinesA * nbColA << " elements of matrix A" << endl;
				long double *T = new long double[nbLinesA * nbColA]; // we create an array that will store the values entered by the user
				int i(0); // counter
				while (i < nbLinesA * nbColA)
				{
				cin >> T[i];
				i++;
				}
				Matrice A(T, nbLinesA, nbColA);
				cout << "A = " << endl; A.affichage();
				cout << "Please enter the " << nbLinesA * nbColA << " elements of matrix B" << endl;
				// we overwrite the values in T
				i = 0; 
				while (i < nbLinesA * nbColA)
				{
				cin >> T[i];
				i++;
				}
				Matrice B(T, nbLinesA, nbColA);
				cout << "B = " << endl; B.affichage();
				cout << "A + B = " << endl; (A + B).affichage();						
				break;
			}
			
			case 2:
			{
				cout << "You have selected subtraction. Please enter the number of lines and columns of each matrix" << endl;
				cin >> nbLinesA >> nbColA;
				cout << "Please enter the " << nbLinesA * nbColA << " elements of matrix A" << endl;
				long double *T = new long double[nbLinesA * nbColA]; // we create an array that will store the values entered by the user
				int i(0); // counter
				while (i < nbLinesA * nbColA)
				{
				cin >> T[i];
				i++;
				}
				Matrice A(T, nbLinesA, nbColA);
				cout << "A = " << endl; A.affichage();
				cout << "Please enter the " << nbLinesA * nbColA << " elements of matrix B" << endl;
				// we overwrite the values in T
				i = 0; 
				while (i < nbLinesA * nbColA)
				{
				cin >> T[i];
				i++;
				}
				Matrice B(T, nbLinesA, nbColA);
				cout << "B = " << endl; B.affichage();
				cout << "A - B = " << endl; (A - B).affichage();
				break;
			}
			
			case 3:
			{
				cout << "You have selected scalar multiplication. Please enter the number of lines and columns of the matrix" << endl;
				cin >> nbLinesA >> nbColA;
				cout << "Please enter the " << nbLinesA * nbColA << " elements of matrix A" << endl;
				long double *T = new long double[nbLinesA * nbColA]; // we create an array that will store the values entered by the user
				int i(0); // counter
				while (i < nbLinesA * nbColA)
				{
				cin >> T[i];
				i++;
				}
				Matrice A(T, nbLinesA, nbColA);
				cout << "A = " << endl; A.affichage();
				cout << "Please enter the scalar" << endl;
				long double lambda(0);
				cin >> lambda;
				A.multScal(lambda);
				cout << "lambda * A = " << endl;
				A.affichage();
				break;
			}
			
			case 4:
			{
				do
				{
					cout << "You have selected multiplication. Please enter the number of lines and columns of matrix A" << endl;
					cin >> nbLinesA >> nbColA;
					cout << "Please enter the number of lines and columns of matrix B" << endl;
					cin >> nbLinesB >> nbColB;
				}
				while (nbColA != nbLinesB);
				cout << "Please enter the " << nbLinesA * nbColA << " elements of matrix A" << endl;
				long double *T = new long double[nbLinesA * nbColA]; // we create an array that will store the values entered by the user for matrix A
				int i(0); // counter
				while (i < nbLinesA * nbColA)
				{
				cin >> T[i];
				i++;
				}
				Matrice A(T, nbLinesA, nbColA);
				cout << "A = " << endl; A.affichage();
				cout << "Please enter the " << nbLinesB * nbColB << " elements of matrix B" << endl;
				long double *U = new long double[nbLinesB * nbColB]; // we create an array that will store the values entered by the user for matrix B
				i = 0;
				while (i < nbLinesB * nbColB)
				{
				cin >> U[i];
				i++;
				}
				Matrice B(U, nbLinesB, nbColB);
				cout << "B = " << endl; B.affichage();
				cout << "A * B = " << endl; (A * B).affichage();
				break;
			}
			
			case 5:
			{
				cout << "You have selected transposition. Please enter the number of lines and columns of matrix A" << endl;
				cin >> nbLinesA >> nbColA;
				cout << "Please enter the " << nbLinesA * nbColA << " elements of matrix A" << endl;
				long double *T = new long double[nbLinesA * nbColA]; // we create an array that will store the values entered by the user
				int i(0); // counter
				while (i < nbLinesA * nbColA)
				{
				cin >> T[i];
				i++;
				}
				Matrice A(T, nbLinesA, nbColA);
				cout << "A = " << endl; A.affichage();
				cout << "A^T = " << endl;
				A.transposee(); A.affichage();
				break;
			}
			
			case 6:
			{
				cout << "You have selected Gauss-Jordan algorithm. Please enter the number of lines and columns of matrix A" << endl;
				cin >> nbLinesA >> nbColA;
				cout << "Please enter the " << nbLinesA * nbColA << " elements of matrix A" << endl;
				long double *T = new long double[nbLinesA * nbColA]; // we create an array that will store the values entered by the user
				int i(0); // counter
				while (i < nbLinesA * nbColA)
				{
				cin >> T[i];
				i++;
				}
				Matrice A(T, nbLinesA, nbColA);
				cout << "A = " << endl; A.affichage();
				cout << "A after application of the Gauss-Jordan algorithm = " << endl;
				Matrice B = algoGaussJordan(A, A);
				B.affichage();
				break;
			}
					
			default:
			{
				cout << "ERROR. Please choose from one of the available options" << endl;
				break;
			}
		}	
	}
	else
	{
		cout << "You have selected square matrix. Please select your operation" << endl;
		int s(0);
		cin >> s;
		// declaration of variables to be used in the switch
		int dim(0); // dimension of the matrix
		switch (s)
		{
			case 7:
			{
				cout << "You have selected determinant. Please enter the dimension of matrix A" << endl;
				cin >> dim;
				cout << "Please enter the " << dim * dim << " elements of matrix A" << endl;
				long double *T = new long double[dim * dim]; // we create an array that will store the values entered by the user
				int i(0); // counter
				while (i < dim * dim)
				{
				cin >> T[i];
				i++;
				}
				MatriceCarree A(T, dim, dim);
				cout << "A = " << endl; A.affichage();
				cout << "det A = " << A.det() << endl;
				break;
			}
			case 8:
			{
				cout << "You have selected adjugate. Please enter the dimension of matrix A" << endl;
				cin >> dim;
				cout << "Please enter the " << dim * dim << " elements of matrix A" << endl;
				long double *T = new long double[dim * dim]; // we create an array that will store the values entered by the user
				int i(0); // counter
				while (i < dim * dim)
				{
				cin >> T[i];
				i++;
				}
				MatriceCarree A(T, dim, dim);
				cout << "A = " << endl; A.affichage();
				MatriceCarree B = comatrice(A);
				cout << "adj A = " << endl;
				B.transposee(); B.affichage();
				break;
			}
			case 9:
			{
				cout << "You have selected inverse. Please enter the dimension of matrix A" << endl;
				cin >> dim;
				cout << "Please enter the " << dim * dim << " elements of matrix A" << endl;
				long double *T = new long double[dim * dim]; // we create an array that will store the values entered by the user
				int i(0); // counter
				while (i < dim * dim)
				{
				cin >> T[i];
				i++;
				}
				MatriceCarree A(T, dim, dim);
				cout << "A = " << endl; A.affichage();
				cout << "A^-1 = " << endl;
				inverse(A).affichage();
				cout << "For your information, A * A^-1 = " << endl;
				(inverse(A) * A).affichage();
				break;
			}
			case 10:
			{
				cout << "You have selected n-th power. Please enter the dimension of matrix A" << endl;
				cin >> dim;
				cout << "Please enter the " << dim * dim << " elements of matrix A" << endl;
				long double *T = new long double[dim * dim]; // we create an array that will store the values entered by the user
				int i(0); // counter
				while (i < dim * dim)
				{
				cin >> T[i];
				i++;
				}
				cout << "Please enter a non negative integer n" << endl;
				int n(0);
				cin >> n;
				MatriceCarree A(T, dim, dim);
				cout << "A = " << endl; A.affichage();
				cout << "A^n = " << endl;
				puissance(A, n).affichage();
				break;
			}
			case 11:
			{
				cout << "You have selected characteristic polynomial. Please enter the dimension of matrix A" << endl;
				cin >> dim;
				cout << "Please enter the " << dim * dim << " elements of matrix A" << endl;
				long double *T = new long double[dim * dim]; // we create an array that will store the values entered by the user
				int i(0); // counter
				while (i < dim * dim)
				{
				cin >> T[i];
				i++;
				}
				MatriceCarree A(T, dim, dim);
				cout << "A = " << endl; A.affichage();
				cout << "P_A(X) = ";
				polyCaract(A).affichage(); cout << endl;
				break;
			}
			default:
			{
				cout << "ERROR. Please choose from one of the available options" << endl;
				break;
			}	
		}
	}	
	return 0;
}
/* 
g++ ./Documents/projet_personnel/informatique/Cpp/main.cpp -I ./Documents/projet_personnel/informatique/Cpp/Matrice -I ./Documents/projet_personnel/informatique/Cpp -I ./Documents/projet_personnel/informatique/Cpp/Matrice/MatriceCarree -I ./Documents/projet_personnel/informatique/Cpp/Polynome ./Matrice.o ./calcul_matriciel.o ./MatriceCarree.o ./combinatoire.o ./Polynome.o
*/