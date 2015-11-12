//
//  Graphe.cpp
//  TD7
//
//  Created by Nicolas GHEUNG on 12/11/15.
//  Copyright © 2015 Nicolas GHEUNG. All rights reserved.
//

#include "Graphe.hpp"

Graphe::Graphe(std::string _nomFichier)
:noeudVector(NULL),arreteVector(NULL)
{
    LireTXT(_nomFichier);
}

void Graphe::LireTXT(std::string _nomFichier)
{
    std::ifstream file(_nomFichier);
    std::string line;
    if (file.is_open())
    {
        while (getline(file,line))
        {
            
        }
        file.close();
    }
    else
        std::cout<<"Erreur lors de l'ouverture du fichier";
    
}