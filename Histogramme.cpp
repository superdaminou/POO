#include "Histogramme.hpp"


/************************************
 *************************************
 **** Constructeur et Destructeur ****
 *************************************
 ************************************/

Histogramme::Histogramme(){
    histo=*new map<string,vector<string> >;
}

Histogramme::Histogramme(Pharmacie med)
{
    //On recup la pharmacie
    map<string,vector<string> > pharma = med.getMeds();
    
    
    //iterator pour l'hitogramme
    
    for (map<string,vector<string> >::iterator iP=pharma.begin();iP != pharma.end();iP++)
    {
        
        for (vector <string>::iterator iPv = iP->second.begin();iPv != iP->second.end();iPv++)
        {
            
            //Pour chaque effet on compare avec histo pour savoir si il est deja présent
            map<string,vector<string> >::iterator iF = histo.find(*iPv);
            if(iF == histo.end())
            {
                //l'effet n'a pas été trouvé il est donc absent de l histo
                histo[*iPv];
                
                histo[*iPv].push_back(iP->first);
                
            }
            else{
                histo[*iPv].push_back(iP->first);
            }
            //cout<<iP->first<<endl;
        }
        
    }
    
}




Histogramme::~Histogramme(){
    
}


/***************
 ****************
 *** Methodes ***
 ****************
 ****************/



/**********Permet de rajouter une nouvelle pharmacie dans l'histogramme afin**********/
void Histogramme::ajoutFichier(Pharmacie med){
    map<string,vector<string> > pharma = med.getMeds();
    
    
    //iterator pour l'hitogramme
    
    for (map<string,vector<string> >::iterator iP=pharma.begin();iP != pharma.end();iP++)
    {
        
        for (vector <string>::iterator iPv = iP->second.begin();iPv != iP->second.end();iPv++)
        {
            
            //Pour chaque effet on compare avec histo pour savoir si il est deja présent
            map<string,vector<string> >::iterator iF = histo.find(*iPv);
            if(iF == histo.end())
            {
                //l'effet n'a pas été trouvé il est donc absent de l histo
                histo[*iPv];
                
                histo[*iPv].push_back(iP->first);
                
            }
            else{
                histo[*iPv].push_back(iP->first);
            }
            //cout<<iP->first<<endl;
        }
        
    }
    
    
}


/********** Permet de rajouter de nouveau effet manuellement **********/
void Histogramme::ajouterEffet(string effet){
    map<string,vector<string> >::iterator it;
    it =histo.find(effet);
    if( it==histo.end()){
        histo[effet];
    }
}


void Histogramme::afficherUnEffet (string effet)
{
    map<string,vector<string> >::iterator it;
    for (map<string,vector<string> >::iterator it =histo.begin();
         it!=histo.end();
         it++)
    {
        if(it->first == effet)
        {
            cout<<effet<< " medicament : ";
            for(vector<string>::iterator ip=it->second.begin();ip!=it->second.end();ip++)
            {
                cout<<*ip<<", ";
            }
        }
        
    }
    
}

/********** Affichage de tout les effets de la base de données *********/
void Histogramme::afficherEffet(){
    map<string,vector<string> >::iterator it;
    for(it=histo.begin(); it!=histo.end();it++){
        cout<<it->first<<endl;
    }
}

/********** Affichage de tout l'histogramme **********/
void Histogramme::afficherHisto(){
    map<string,vector<string> >::iterator it;
    for(it=histo.begin();it!=histo.end();it++){
        cout<<"effet :  "<<it->first<<", medicaments associé :        ";
        for(vector<string>::iterator ip=it->second.begin();ip!=it->second.end();ip++){
            cout<<*ip<<" ";
        }
        cout<<endl;
    }
}
/********** Associer un effet a un medicament **********/
void Histogramme::associerMedicament(string effet,string medoc){
    map<string,vector<string> >::iterator it;
    for(it=histo.begin();it!=histo.end();it++){
        //cout<<it->first<<" "<<endl;
        if(it->first==effet){
            cout<<"effet trouver"<<endl;
            for(vector<string>::iterator ip=it->second.begin();ip!=it->second.end();ip++){
                cout<<*ip<<" ";
                if(*ip==medoc){
                    cout<<" effet et medicaments deja associé"<<endl;
                    return;
                }
                
            }
            it->second.push_back(medoc);
            cout<<"association ajouté"<<endl;
            return;
            
        }
    }
    histo[effet];
    histo[effet].push_back(medoc);
}

/********** Permet d'ajouter un Medicament et la liste de ses effets a l'histogramme **********/
void Histogramme::ajouterMedicament(string medoc, vector<string> listeEffet){
    for(vector<string>::iterator it=listeEffet.begin();it!=listeEffet.end();it++){
        this->associerMedicament(*it,medoc);
    }
}

/********* Liste tout les medicaments provoquant un effet **********/
void Histogramme::rechercheParEffet(string effet){
    map<string, vector<string> >::iterator iF=histo.find(effet);
    if(iF!=histo.end()){
        cout<<"Les medicaments provoquants des "<<effet<<" sont :";
        for(vector<string>::iterator it=histo[effet].begin();it!=histo[effet].end();it++){
            cout<<*it<<" ";
        }
    }
    else{
        cout<<"effet non trouvé"<<endl;
    }
    cout<<endl;
}


/********** Rechercher tout les medicaments provoquant les effet qu'un autre **********/
void Histogramme::rechercheParMedicaments(string medoc){
    map<string, vector<string> >::iterator it;
    cout<<"les medicaments partageant les meme effets que "<<medoc<<" sont : "<<endl;
    for(it=histo.begin();it!=histo.end();it++){
        vector <string>::iterator iP;
        for(iP=it->second.begin();iP!=it->second.end();iP++){
            if(*iP==medoc && it->second.size()>1){
                cout<<"pour "<<it->first<<" : ";
                for(iP=it->second.begin();iP!=it->second.end();iP++){
                    if(*iP!=medoc){
                        cout<<*iP<<" ";
                    }
                }
                cout<<endl;
                break;
                
            }
        }
    }
    
}