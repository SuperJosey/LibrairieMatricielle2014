//
//  operation.h
//  LibrairieMatricielle2014
//


#ifndef __LibrairieMatricielle2014__operation__
#define __LibrairieMatricielle2014__operation__

#include <iostream>

//Déclarer les opérations
class Matrice {
    
private:
    int **Table;
    int ligne;
    int colonne;
    
    int _nbLigneA; //Nb de ligne dans le fichier A
    int _nbLigneB; //Nb de ligne dans le fichier B
    
    //Matrice A:
    int *ligneA;
    int *coloneA;
    int *valeurA;
    
    //Matrice B:
    int *ligneB;
    int *coloneB;
    int *valeurB;
    
public:
    Matrice();
    ~Matrice();
    int setLigne();
    int setColone();
    int genererMatrice();

    
    
    //Matrice A:
    void setNbLigneA();
    void initLigneA();
    void initColoneA();
    void initValeurA();
    void chargerMatriceA();
    
    //Matrice B:
    void setNbLigneB();
    void initLigneB();
    void initColoneB();
    void initValeurB();
    void chargerMatriceB();
    
    //Creer un fichier resultat:
    void matriceVierge();

    
};


#endif /* defined(__LibrairieMatricielle2014__operation__) */
