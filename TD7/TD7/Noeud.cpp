//
//  Noeud.cpp
//  TD7
//
//  Created by Nicolas GHEUNG on 12/11/15.
//  Copyright © 2015 Nicolas GHEUNG. All rights reserved.
//

#include "Noeud.hpp"

Noeud::Noeud(int _valeur)
:valeur(_valeur)
{
    
};

int Noeud::GETValue()
{
    return this->valeur;
}
