//
//  operation.cpp
//  LibrairieMatricielle2014
//


#include "operation.h"

//Definir les opérations


  /*
  ** Division avec 2 matrices en argument, permet de diviser
  ** 2 matrices entre elles si elles sont carrées grace aux fonctions
  ** inversion et multiplication et retourne une matrice en résultat.
  */

  Matrice operation::Division (Matrice A, Matrice B)
  {
    Matrice Resultat;
    Matrice B1;
    
    if ((A.ligne == A.colonne) && (B.ligne == B.colonne))
    {
      B1 = new Matrice (Inversion(B));
      Resultat = new Matrice (Multiplication (A,B1));
      return Resultat;
    }
    else
    {
      cout << "Vos matrices doivent etre carrées" << endl;
    }
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
  
  /*
  ** Fonction d'Inversion, permet d'inverser une matrice pour pouvoir
  ** effectuer la division matricielle entre autres. Retourne une matrice.
  */
  
  Matrice operation::Inversion (Matrice A)
  {
    
  }
  
  
  
  
  
  
  
  
  
  
  
