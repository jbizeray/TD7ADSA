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
            std::vector<std::string> linevector = split(line, ';');
            ajouterNoeud( string2real(*(linevector.begin())) );
            ajouterNoeud( string2real(*(linevector.begin()+1)) );
            linevector.begin()+2;
        }
        file.close();
    }
    else
        std::cout<<"Erreur lors de l'ouverture du fichier";
}

Noeud* Graphe::ajouterNoeud(int valeurAAjoute)
{
    Noeud* n;
    for(std::vector<Noeud*>::const_iterator ite = noeudVector.begin(); ite!=noeudVector.end();ite++)
    {
        if ((*ite)->GETValue()==valeurAAjoute)
            return nullptr;
    }
    noeudVector.push_back(new Noeud(valeurAAjoute));
    return n;
}

void Graphe::ajouterArrete(int valeurAAjouteNoeud1,int valeurAAjouteNoeud2, int poidArrete)
{
    Noeud* n1 = ajouterNoeud(valeurAAjouteNoeud1);
    Noeud* n2 = ajouterNoeud(valeurAAjouteNoeud2);
    arreteVector.push_back(new Arrete(n1,n2,poidArrete));
}


std::vector<std::string> split(std::string string, char delimiter)
{
    std::vector<std::string> internal;
    std::stringstream ss(string); // Turn the string into a stream.
    std::string tok;
    
    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }
    
    return internal;
}