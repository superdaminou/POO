//
//  Histogramme.hpp
//  ProjetPoo
//
//  Created by Damien Le Garrec on 11/04/2016.
//  Copyright © 2016 MMD. All rights reserved.
//

#ifndef Histogramme_hpp
#define Histogramme_hpp

#include <stdio.h>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include "Pharmacie.hpp"
#include <locale>

using namespace std;


class Histogramme{
protected:
    map<string, vector<string> > histo;
    
public:
    //Constructeur et Destructeur
    Histogramme();
    Histogramme(Pharmacie med);
    void ajoutFichier(Pharmacie med);
    ~Histogramme();
    void ajouterEffet(string effet);
    void afficherHisto();
    void afficherEffet();
    void associerMedicament(string effet, string medoc);
    void rechercheParEffet(string effet);
    void rechercheParMedicaments(string medoc);
    void ajouterMedicament(string medoc,vector<string>listEffet);
    
};

#endif /* Histogramme_hpp */
