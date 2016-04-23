#ifndef __PHARMACIE_HPP
#define __PHARMACIE_HPP

#include <cassert>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Pharmacie{
private:
    map<string, vector<string> > meds;  
	
public:
    //Constructeur & Destructeur
    Pharmacie(string);
    ~Pharmacie();
    
    //Getter & Setter
    map<string, vector<string> > getMeds();

    
    //Methode
    void parse_Pharma(ifstream&); // parse le fichier d'entrée
    void parse_Med(string); // parse un médicament
    void afficher_Map();
    void creation_Histogramme();
};

#endif
