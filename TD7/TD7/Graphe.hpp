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

class Graphe
{
private:
    std::set<int,Noeud*> noeudVector;
    std::vector<Arrete*> arreteVector;
    
public:
    Graphe(std::string);
    void LireTXT(std::string);
};

#endif /* Graphe_hpp */
