#include <cassert>
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <map>

#include "Pharmacie.hpp"
using namespace std;

/************************************
 *************************************
 **** Constructeur et Destructeur ****
 *************************************
 ************************************/

Pharmacie::Pharmacie(string s){
    
    //vérification que le fichier est valide
    ifstream input(s.c_str());
    if(input.good()) {//vérifie que le fichier est valide
        parse_Pharma(input);
    }
    else
        throw runtime_error("file not good");
    //retourne une exception
}

Pharmacie::~Pharmacie()
{
}


/***********************
 ************************
 **** Getter & Setter ***
 ************************
 ************************/

map<string, vector<string> > Pharmacie::getMeds()
{
    return meds;
    
}


/***************
 ****************
 *** Methodes ***
 ****************
 ****************/

void Pharmacie::parse_Pharma(ifstream& in){
    string s;
    while(in.good()){ // tant que le fichier n'est pas vide
        s = '\0';
        getline(in,s,'\n');//récupère la ligne jusqu'à \n
        parse_Med(s);
    }
}

void Pharmacie::parse_Med(string s){
    size_t z = s.find(':');
    size_t t = 0;
    size_t j=0;
    
    string nam = s.substr(0, z-1); // nom du médicament (de la position 0 dans le string à z-1, vu qu'il y a un espace avant ':')
    vector<string> effects;  // liste d'effets secondaires
    int i = s.find_last_of(':')+2; // position du premier caractère après les ':'
    
    
    while(i < s.length()){ // boucle jusqu'à la fin de la ligne
        t = s.find(',', i);
        if( t >= s.length()){ // pas de vigule trouvée, on en est donc au dernier effet secondaire
            j = s.find(" et ",i);
            if(j>s.length()){
                if(s[i+s.length()-2-i-1]!='s')
                {
                    effects.push_back(s.substr(i,s.length()-2-i));
                }
                else
                {
                    effects.push_back(s.substr(i,s.length()-2-i-1));
                }
            }
            else{
                if(s[i+j-i-1]!='s')
                {
                    effects.push_back(s.substr(i,j-i));
                }
                else{
                    effects.push_back(s.substr(i,j-i-1));
                }
                
                size_t k=s.find_last_of('.');
                
                if(s[j+4+k-j-4-1]!='s'){
                    effects.push_back(s.substr(j+4,k-j-4));
                }
                else{
                    effects.push_back(s.substr(j+4,k-j-4-1));
                }
            }
            break;
        }
        else{ // il y a plusieurs effets secondaires à traiter encore
            
            if(s[i+t-i-1]!='s'){
                effects.push_back(s.substr(i, t-i));
            }
            else{
                effects.push_back(s.substr(i, t-i-1));
            }
            i = t+2;	// on fait avancer i de la taille de la chaine + l'espace et la virgule
        }
    }
    
    meds.insert(pair<string, vector<string> >(nam, effects)); //insertion de la paire représentant le médicament dans la map
    
}


void Pharmacie::afficher_Map(){
    map<string,vector<string> >::iterator p;  //creation d'un iterateur p sur map
    for(p = meds.begin(); p != meds.end(); p++)  //parcour de p
    {
        cout << p->first;   //affichage du nom de medoc
        for (std::vector<string>::iterator it = p->second.begin() ; it != p->second.end(); ++it)  //creation terateur pour vecteur d'effet
            std::cout << ' ' << *it;  //affichages des effets
        cout<<endl;
    }
}

