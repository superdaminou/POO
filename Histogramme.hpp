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
#include <cstring>

using namespace std;


class Histogramme{
protected:
    map<string, vector<string> > m_histo;
    
public:
    //Constructeur et Destructeur
    Histogramme();
    Histogramme(Pharmacie med);
    ~Histogramme();
    
    
    //Methodes
    void ajout_Fichier(Pharmacie med);
    void ajouter_Effet(string effet);
    
    void afficher_Un_Effet (string effet);
    void afficher_Histo();
    void afficher_Pharma();
    void afficher_Effet();
    
    void associer_Medicament(string effet, string medoc);
    void recherche_Par_Effet(string effet);
    void recherche_Par_Medicaments(string medoc);
    void recherche_Par_Medicaments(string medoc, int nbEffetPartager);
    void ajouter_Medicament(string medoc,vector<string>listEffet);
    
    vector<string> effet_Medicament(string medicament);
    
    float calcul_Rappel(string med,vector<string> effet);
    float calcul_Precision(string med,vector<string> effet);
    
   
    void affiche_Rap_Prec();
    
};

#endif /* Histogramme_hpp */
