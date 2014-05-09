//
//  operation.cpp
//  LibrairieMatricielle2014
//


#include "operation.h"
#include <fstream>

using namespace std;

Matrice::Matrice(){
    
}

Matrice::~Matrice(){
    
}

int Matrice::genererMatrice(){
    
    this->Table=new int *[1000];
    for(int lign=0; lign<1000; lign++)
    {
        this->Table[lign]=new int[1000];
        for(int col=0; col<1000; col++)
        {
            
        }
    }
    
    return 0;
}


void Matrice::setNbLigneA(){
    
    int cmpt = 1;
    string s;
    ifstream fichier("matrice2.txt", ios::in);
    
    if(fichier){
        
        while(getline(fichier,s))
        {
            cmpt++;
        }
        
        fichier.close();
    }
    
    _nbLigneA=cmpt;
}


void Matrice::initLigneA(){
    
    this->ligneA = new int [_nbLigneA];
    
}

void Matrice::initColoneA(){
    
    this->coloneA = new int [_nbLigneA];
    
}

void Matrice::initValeurA(){
    
    this->valeurA = new int [_nbLigneA];
    
}


/*
 * Charge la matrice A et place Ligne Colone et Valeur
 * dans 3 tableaux
 *
 */

void Matrice::chargerMatriceA(){
    
    setNbLigneA();
    initValeurA();
    initColoneA();
    initLigneA();

    ifstream fichier("matriceA.txt", ios::in);  // on ouvre en lecture
    
    if(fichier)
    {
        string contenu;
        fichier.ignore(0, '\n'); // Saute la premiere ligne
        
        getline(fichier, contenu);

        cout << contenu << endl;
        
        int var;
        
        int i=0;
        
        while (fichier){
            
            /*fichier >> var;
            ligne[i]=var;
            fichier >> var;
            col[i]=var;
            fichier >> var;
            val[i]=var;
            i++;*/
            
            fichier >> var;
            this->ligneA[i]=var;
            fichier >> var;
            this->coloneA[i]=var;
            fichier >> var;
            this->valeurA[i]=var;
            i++;
            
        }
                
        cout << "valeur 2: " << valeurA[1] <<endl;
        cout << "valeur 1: " << valeurA[0] <<endl;
        
        fichier.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;

}

//Matrice B:

void Matrice::setNbLigneB(){
    
    int cmpt = 1;
    string s;
    ifstream fichier("matriceB.txt", ios::in);
    
    if(fichier){
        
        while(getline(fichier,s))
        {
            cmpt++;
        }
        
        fichier.close();
    }
    
    _nbLigneA=cmpt;
}


void Matrice::initLigneB(){
    
    this->ligneB = new int [_nbLigneB];
    
}

void Matrice::initColoneB(){
    
    this->coloneB = new int [_nbLigneB];
    
}

void Matrice::initValeurB(){
    
    this->valeurB = new int [_nbLigneB];
    
}


/*
 * Charge la matrice B et place Ligne Colone et Valeur
 * dans 3 tableaux
 *
 */

void Matrice::chargerMatriceB(){
    
    setNbLigneB();
    initValeurB();
    initColoneB();
    initLigneB();
    
    ifstream fichier("matriceB.txt", ios::in);  // on ouvre en lecture
    
    if(fichier)
    {
        string contenu;
        fichier.ignore(0, '\n'); // Saute la premiere ligne
        
        getline(fichier, contenu);
        
        cout << contenu << endl;
        
        int var;
        
        int i=0;
        
        while (fichier){
            
            fichier >> var;
            this->ligneB[i]=var;
            fichier >> var;
            this->coloneB[i]=var;
            fichier >> var;
            this->valeurB[i]=var;
            i++;
            
        }
        
        cout << "valeur 2: " << valeurB[1] <<endl;
        cout << "valeur 1: " << valeurB[0] <<endl;
        
        fichier.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    
}



//Definir les opérations:

/*
 * Additions de deux matrice:
 */

void Matrice::matriceVierge(){
    
    ofstream fichier;
    
    fichier.open("matriceTest.txt", ios::out);
    if (fichier.bad())
    {
        cerr << "Erreur dans la création de la matrice resultat" <<endl;
    }
        
    //fichier <<"contenu du fichier" << endl;
    
    
    
    fichier.close();
   
    
}

