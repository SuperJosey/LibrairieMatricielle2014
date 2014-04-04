#include "Matrice.h"
#include "operation.h"


//Definir les opérations


  /*
  ** Division avec 2 matrices en argument, permet de diviser
  ** 2 matrices entre elles si elles sont carrées grace aux fonctions
  ** inversion et multiplication et retourne une matrice en résultat.
  */

  bool operation::VerifCarre (Matrice A)
  {
	if (A.ligne == B.colonne)
		return true;
	std::cout << "La matrice n'est pas carré ..." << std::endl;
	return false;
  }
  
  
  Matrice operation::Division (Matrice A, Matrice B)
  {
    Matrice Resultat;
    Matrice B1;
	
	if (!(A.VerifCarre && B.VerifCarre))
		return NULL;
	
      B1 = new Matrice (B.Inversion());
      Resultat = new Matrice (Multiplication (A,B1));
      return Resultat;
  }
  
  /*
  ** Division avec 1 matrice et un int en argument, permet de diviser
  ** 1 matrices par un coefficient et retourne une matrice en résultat.
  */
  
    Matrice operation::Division (Matrice A, int coefficient)
  {
    Matrice Resultat;
    
    for (int i =0; i<A.ligne; i++)
    {
      for (int j=0; j<A.colonne; j++)
      {
        Resultat [i][j] = A[i][j]/coefficient;
      }
    }
    return Resultat;
  }
  
  Matrice operation::Multiplication (Matrice A, Matrice B)
  {
	if (A.Creuse ())
		return MultiplicationCreuse (A,B);
	else if (B.Creuse ())
		return MultiplicationCreuse (B,A);
	else
		return MultiplicationSimple (A,B);
  }
  
  Matrice operation::Multiplication (int coefficient)
  {
	Matrice A (getLigne(), getColonne);
	A.miseZero ();
	
	for (int i=0; i<A.getLigne(); i++)
	{
		for (int j=0; j<A.getColonne(); j++)
		{
			A = [i][j]*coefficient;
		}
	}
	return A;
  }
  
  
  Matrice operation::MultiplicationSimple (Matrice A, Matrice B)
  {
	if (A.colonne != B.ligne)
	{
		std::cout << "L'opération n'est pas possible car le nombre de colonnes";
		std::cout << "de A n'est pas égal au nombre de lignes de B" << std::enl;
		return 0;
	}
	else
	{
	Matrice R (A.getLigne(),B.getColonne);
	R.miseZero ();
	
		for (int i=0; i<A.ligne; i++)
		{
			for (int j=0; j<B.colonne; j++)
			{
				for (int k=0; k<A.colonne; k++)
				{
					R[i][j] += A[i][k]*B[k][i];
				}
			}
		}
		return R;
	}
  }
  
  Matrice & operation::miseZero ()
  {
	for (int i=0; i<ligne; i++)
		for (int j=0; j<colonne; j++)
			Table[i][j] = 0;
	return this;
  }
  
  /*
  ** Fonction d'Inversion, permet d'inverser une matrice pour pouvoir
  ** effectuer la division matricielle entre autres. Retourne une matrice.
  */
  
  Matrice operation::Inversion ()
  {
	Matrice R(getLigne(), getColonne);
	R.miseZero();
	
	for (int i=0; i<getLigne(); i++)
		for (int j=0; j<getColonne(); j++)
			R[i][i] = 1/(this->[i][i]);
	return R;
  }
  
 int main ()
 {
	
	return 0;
 }
