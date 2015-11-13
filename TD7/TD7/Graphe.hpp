//
//  Graphe.hpp
//  TD7
//
//  Created by Nicolas GHEUNG on 12/11/15.
//  Copyright © 2015 Nicolas GHEUNG. All rights reserved.
//

#ifndef Graphe_hpp
#define Graphe_hpp

#include <stdio.h>
#include "Arrete.hpp"
#include <set>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "outils.h"

std::vector<std::string> split(std::string , char );

class Graphe
{
private:
    std::vector<Noeud*> noeudVector;
    std::vector<Arrete*> arreteVector;
    
public:
    Graphe(std::string);
    void LireTXT(std::string);
    Noeud* ajouterNoeud(int);
    void ajouterArrete(int,int,int);
};

#endif /* Graphe_hpp */
