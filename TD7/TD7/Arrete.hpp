//
//  Arrete.hpp
//  TD7
//
//  Created by Nicolas GHEUNG on 12/11/15.
//  Copyright © 2015 Nicolas GHEUNG. All rights reserved.
//

#ifndef Arrete_hpp
#define Arrete_hpp

#include <stdio.h>
#include "Noeud.hpp"

class Arrete
{
private:
    Noeud* noeudDepart;
    Noeud* noeudDestination;
    int ponderation;
    
public:
    Arrete(Noeud* const &,Noeud* const &,int);
};

#endif /* Arrete_hpp */
