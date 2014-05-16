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
    ifstream fichier("matriceA.txt", ios::in);
    
    if(fichier){
        
        while(getline(fichier,s))
        {
            cmpt++;
        }
        
        fichier.close();
    }
    
    this->_nbLigneA=cmpt;
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
        //string contenu;
        //fichier.ignore(0, '\n'); // Saute la premiere ligne
        //getline(fichier, contenu);
        //cout << contenu << endl;
        
        char p;
        int tmpLigne;
        int tmpCol;
        
        fichier >> p; //Caracetere pour identifier que l'on recupere bien la taille
        fichier >> tmpLigne;
        fichier >> tmpCol;
        
        this->nbLigneA = tmpLigne;
        this->nbColoneA = tmpCol;
        
        
        cout << "valeur de si1: " << tmpLigne << "valeur de si2: " << tmpCol <<endl;
        cout << "valeur de p: " << p << endl;
        
        int var;
        
        int i=0;
        
        while (fichier){

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
    
    this->_nbLigneB=cmpt;
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
        //string contenu;
        //fichier.ignore(0, '\n'); // Saute la premiere ligne
        //getline(fichier, contenu);
        //cout << contenu << endl;
        
        char p;
        int tmpLigne;
        int tmpCol;
        
        fichier >> p; //Caracetere pour identifier que l'on recupere bien la taille
        fichier >> tmpLigne;
        fichier >> tmpCol;
        
        this->nbLigneB = tmpLigne; 
        this->nbColoneB = tmpCol;
        

        cout << "valeur de si1: " << tmpLigne << "valeur de si2: " << tmpCol <<endl;
        cout << "valeur de p: " << p << endl;

        
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
        
        cout << "valeur 3: " << valeurB[2] <<endl;
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
    
    //cout << "test nbA: " << this->_nbLigneA << "test nbB: " << this->_nbLigneB <<endl;
    
    ofstream fichier;
    
    fichier.open("matriceTest.txt", ios::out);
    if (fichier.bad())
    {
        cerr << "Erreur dans la création de la matrice resultat" <<endl;
    }
        
    
    // Si la matrice A est de la meme taille que la matrice B:
    if((nbLigneA == nbLigneB) && (nbColoneA == nbColoneB)){
        
        fichier << "s " << this->nbLigneA << " " << this->nbColoneA <<endl;
        
        //On recupere le nb de ligne maximum que contiendra notre matrice resultat:
        int tmpMax = getMaxNbLigne();
        
        if(tmpMax!=0){
            for(int i=0; i<=(nbLigneA*nbColoneA); i++ ){
              
                if(valeurA[i] !=0 && valeurB[i] !=0){
                    
                    if(ligneA[i] == ligneB[i]){
                        if(coloneA[i]<coloneB[i]){
                            fichier << ligneA[i] << " " << coloneA[i] << " " << valeurA[i]<<endl;
                        }
                        else if(coloneB[i]<coloneA[i]){
                            fichier << ligneB[i] << " " << coloneB[i] << " " << valeurB[i]<<endl;
                        }
                        else if(coloneA[i] == coloneB[i]){
                            fichier << ligneA[i] << "_" << coloneA[i] << "_" << (valeurA[i]+valeurB[i])<<endl;
                        }

                    }
                
                    if(ligneA[i] < ligneB[i]){
                    
                        fichier << ligneA[i] << " " << coloneA[i] << " " << valeurA[i]<<endl;
                    }
                    

                }
            }
                
        }
        else{
            cerr << "erreur: Matrices vides" <<endl;
        }
        
    }
    else{
        cerr << "erreur: Matrices de tailles differentes" <<endl;
    }
    
    fichier.close();
   
    
}

/*
 * getMaxNbLigne(): compare le nombre de ligne dans les deux fichier LCV correspondant
 * aux matrice A et B puis retourne le nombre maximal de ligne contenu dans le fichier
 * (la matrice comportant le moins de Valeur nulle)
 */

int Matrice::getMaxNbLigne(){
    
    //Si il existe des lignes dans le fichier A et B
    if((this->_nbLigneA != -1) && (this->_nbLigneB != -1)){
       
        if(this->_nbLigneA > this->_nbLigneB){
            return this->_nbLigneA;
        }
        else if (this->_nbLigneA == this->_nbLigneB){
            return this->_nbLigneA;
        }
        else if (this->_nbLigneA < this->_nbLigneB){
            return this->_nbLigneB;
        }
    }
    else{
        cerr <<"erreur: Aucune valeur contenu dans _nbLigneA et _nbLigneB"<<endl;
    }
    
    return 0;
}






