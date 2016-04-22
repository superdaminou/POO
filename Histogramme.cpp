#include "Histogramme.hpp"


/************************************
 *************************************
 **** Constructeur et Destructeur ****
 *************************************
 ************************************/

Histogramme::Histogramme(){
    m_histo=*new map<string,vector<string> >;
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
            
            //Pour chaque effet on compare avec m_histo pour savoir si il est deja présent
            map<string,vector<string> >::iterator iF = m_histo.find(*iPv);
            if(iF == m_histo.end())
            {
                //l'effet n'a pas été trouvé il est donc absent de l histo
                m_histo[*iPv];
                
                m_histo[*iPv].push_back(iP->first);
                
            }
            else{
                m_histo[*iPv].push_back(iP->first);
            }
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



/**********Permet de rajouter une nouvelle pharmacie dans l'histogramme**********/
void Histogramme::ajout_Fichier(Pharmacie med){
    map<string,vector<string> > pharma = med.getMeds();
    
    
    //iterator pour l'hitogramme
    
    for (map<string,vector<string> >::iterator iP=pharma.begin();iP != pharma.end();iP++)
    {
        
        for (vector <string>::iterator iPv = iP->second.begin();iPv != iP->second.end();iPv++)
        {
            
            //Pour chaque effet on compare avec histo pour savoir si il est deja présent
            map<string,vector<string> >::iterator iF = m_histo.find(*iPv);
            if(iF == m_histo.end())
            {
                //l'effet n'a pas été trouvé il est donc absent de l histo
                m_histo[*iPv];
                
                m_histo[*iPv].push_back(iP->first);
                
            }
            else{
                m_histo[*iPv].push_back(iP->first);
            }
            //cout<<iP->first<<endl;
        }
        
    }
    
    
}


/********** Permet de rajouter de nouveau effet manuellement **********/
void Histogramme::ajouter_Effet(string effet){
    
    map<string,vector<string> >::iterator it=m_histo.find(effet);
    if( it==m_histo.end()){
        m_histo[effet];
    }
}



/********* Permet d'afficher un Effet **********/
void Histogramme::afficher_Un_Effet (string effet)
{
    for (map<string,vector<string> >::iterator it =m_histo.begin();
         it!=m_histo.end();
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
void Histogramme::afficher_Effet(){
    for(map<string,vector<string> >::iterator it=m_histo.begin(); it!=m_histo.end();it++)
    {
        cout<<it->first<<endl;
    }
}

/********** Affichage de toute la Pharma**********/
void Histogramme::afficher_Pharma(){
    for(map<string,vector<string> >::iterator it=m_histo.begin();it!=m_histo.end();it++)
    {
        cout<<"     effet : "<<it->first<<", ";
        for(int i=0;i<=25-it->first.size();i++)
        {
            cout<<".";
        }
        cout<<"medicaments associé : ";
        for(vector<string>::iterator ip=it->second.begin();ip!=it->second.end();ip++)
        {
            cout<<*ip<<" ";
        }
        cout<<endl;
    }
}

/********** Affichage de l'Histograme **********/

void Histogramme::afficher_Histo(){
    cout<<"nb apparition";
    for(int i=0;i<=8;i++)
    {
        cout<<".";
    }
    
    cout<<"effet"<<endl;
    for(map<string,vector<string> >::iterator it=m_histo.begin();it!=m_histo.end();it++)
    {
        for(int i=0;i<=it->second.size();i++)
        {
            cout<<"◙";
        }
        for(int i=0;i<=20-it->second.size();i++)
        {
            cout<<".";
        }
        cout<<it->first<<" ";
        
                cout<<endl;
    }
}


/********** Associer un effet a un medicament **********/
void Histogramme::associer_Medicament(string effet,string medoc){
    for(map<string,vector<string> >::iterator it=m_histo.begin();it!=m_histo.end();it++)
    {
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
    m_histo[effet];
    m_histo[effet].push_back(medoc);
}



/********** Permet d'ajouter un Medicament et la liste de ses effets a l'histogramme **********/
void Histogramme::ajouter_Medicament(string medoc, vector<string> listeEffet){
    for(vector<string>::iterator it=listeEffet.begin();it!=listeEffet.end();it++)
    {
        this->associer_Medicament(*it,medoc);
    }
}

/********* Liste tout les medicaments provoquant un effet **********/
void Histogramme::recherche_Par_Effet(string effet)
{
    map<string, vector<string> >::iterator iF=m_histo.find(effet);
    if(iF!=m_histo.end()){
        cout<<"Les medicaments provoquants des "<<effet<<" sont :";
        for(vector<string>::iterator it=m_histo[effet].begin();it!=m_histo[effet].end();it++)
        {
            cout<<*it<<" ";
        }
    }
    else
    {
        cout<<"effet non trouvé"<<endl;
    }
    cout<<endl;
}


/********** Rechercher tout les medicaments provoquant les effet qu'un autre **********/
void Histogramme::recherche_Par_Medicaments(string medoc)
{
    cout<<"les medicaments partageant les meme effets que "<<medoc<<" sont : "<<endl;
    for(map<string, vector<string> >::iterator it=m_histo.begin();it!=m_histo.end();it++){
        for(vector <string>::iterator iP=it->second.begin();iP!=it->second.end();iP++)
        {
            if(*iP==medoc && it->second.size()>1)
            {
                cout<<"pour "<<it->first<<" : ";
                for(iP=it->second.begin();iP!=it->second.end();iP++)
                {
                    if(*iP!=medoc)
                    {
                        cout<<*iP<<" ";
                    }
                }
                cout<<endl;
                break;
            }
        }
    }
}

vector<string> Histogramme::effet_Medicament(string medicament){
    vector<string> effet;
    for(map<string, vector<string> >::iterator it=m_histo.begin();it!=m_histo.end();it++)
    {
        for(vector<string>::iterator iF=it->second.begin();iF!=it->second.end();iF++){
            if(*iF==medicament)
            {
                effet.push_back(it->first);
            }
        }
        
        
    }
    
    return effet;
}


float calcul_Rappel(string med,vector<string> effet)
{
    float res;
    int taille(effet.size());
    
    
    
    
    return res;
}
float calcul_Precision(string med,vector<string> effet)
{
    float res;
    
    return res;
}
void affiche_Rap_Prec()
{
    string med,temp;
    vector<string> effet;
    float rap, prec;
    bool i = true;
    
    cout<<"entrez un medicament :";
    cin >> med;
    
    while (i)
    {
        cout << endl;
        cout << "entrez un effet, taper 'fin' pour terminer : ";
        cin>>temp;
        if (temp == "fin")
        {
            break;
        }
        
        
        effet.push_back(temp);
        cin.clear();
        cin.ignore( numeric_limits<streamsize>::max(), '\n' );
        
    }
    rap = calcul_Rappel(med,effet);
    prec = calcul_Precision(med,effet);
    
}

