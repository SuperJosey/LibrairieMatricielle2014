//
//  main.cpp
//  LibrairieMatricielle2014
//


#include <iostream>
#include "operation.h"

int main(int argc, const char * argv[])
{

    //Ici effectuer les test
    std::cout << "Hello test" << std::endl;
    Matrice m1;
    m1.chargerMatriceA();
    m1.chargerMatriceB();
    m1.matriceVierge();
    
    return 0;
}

