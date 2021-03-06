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
    if( it==m_histo.end())//si l'iterateur n'est pas superieur a la taille de la map alors c'est que l'effet est repertorié
    {
        m_histo[effet];
    }
}



/********* Permet d'afficher un tout les medicament ayant on effet **********/
void Histogramme::afficher_Un_Effet (string effet)
{
    for (map<string,vector<string> >::iterator it =m_histo.begin();
         it!=m_histo.end();
         it++)
    {
        if(it->first == effet)//On a trouver l'effet
        {
            cout<<effet<< " medicament : ";
            for(vector<string>::iterator iV=it->second.begin();iV!=it->second.end();iV++)       //on parcour le vecteur contenant tout les medicaments
            {
                cout<<*iV<<", ";
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
        for(vector<string>::iterator iV=it->second.begin();iV!=it->second.end();iV++)
        {
            cout<<*iV<<" ";
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
            cout<<"◙";                  //represente une apparition dans un medicament
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
        if(it->first==effet){   // on verifie si l'effet est deja enregistré
            for(vector<string>::iterator iV=it->second.begin();iV!=it->second.end();iV++){ //on verifie si le medicament est deja enregisté
                cout<<*iV<<" ";
                if(*iV==medoc){
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


/********** Rechercher tout les medicaments provoquant les meme effet qu'un autre **********/
void Histogramme::recherche_Par_Medicaments(string medoc)
{
    cout<<"les medicaments partageant les meme effets que "<<medoc<<" sont : "<<endl;
    for(map<string, vector<string> >::iterator it=m_histo.begin();it!=m_histo.end();it++){
        for(vector <string>::iterator iV=it->second.begin();iV!=it->second.end();iV++)// on recherche le medicament dans tout les effet
        {
            if(*iV==medoc && it->second.size()>1) // si on trouve le medicament dans un effet et que ce n'est pas le seul alors on affiche les autre medicaments en precisiant l'effet
            {
                cout<<"pour "<<it->first<<" : ";
                for(iV=it->second.begin();iV!=it->second.end();iV++)
                {
                    if(*iV!=medoc)
                    {
                        cout<<*iV<<" ";
                    }
                }
                cout<<endl;
                break;
            }
        }
    }
}

void Histogramme::recherche_Par_Medicaments(string medoc, int nbEffetPartager)
{
    map<string,vector<string> >listeMedicament;
    
    cout<<"les medicaments ayant "<<nbEffetPartager<<" effets en commun avec "<<medoc<<" sont : "<<endl;
    for(map<string, vector<string> >::iterator it=m_histo.begin();it!=m_histo.end();it++)
    {
        for(vector <string>::iterator iV=it->second.begin();iV!=it->second.end();iV++)// on recherche le medicament dans tout les effet
        {
            if(*iV==medoc && it->second.size()>1) // si on trouve le medicament dans un effet et que ce n'est pas le seul alors on affiche les autre medicaments en precisiant l'effet
            {
                for(iV=it->second.begin();iV!=it->second.end();iV++)
                {
                    if(*iV!=medoc)
                    {
                        listeMedicament[*iV].push_back(it->first);
                    }
                }
                break;
            }
        }
    }

    map<string,vector<string> >::iterator iM;
    for(iM=listeMedicament.begin();iM!=listeMedicament.end();iM++)
    {
        if(iM->second.size()==nbEffetPartager)
        {
            cout<<"Medicament :"<<iM->first<<", effet : ";
            vector<string>::iterator iV;
            for(iV=iM->second.begin();iV!=iM->second.end();iV++){
                cout<<*iV<<" ";
            }
            cout<<endl;
        }
        
    }
    //cout<<endl;
}

/****** Sortir les effets d'un medicament********/


vector<string> Histogramme::effet_Medicament(string medicament){
    vector<string> effet;
    
    map<string, vector<string> >::iterator it;
    for( it=m_histo.begin();it!=m_histo.end();it++)
    {
        vector<string>::iterator iP;
        for(iP=it->second.begin();iP!=it->second.end();iP++){
            if(*iP==medicament)
            {
                effet.push_back(it->first);
                
            }
        }
    }
    
    return effet;
}


/****** Fonction de calcul du rappel *******/

float Histogramme::calcul_Rappel(string med,vector<string> effet)
{
    /*Renvoi les effets d'un medicament*/
    vector<string> effMed(effet_Medicament(med));
    
    /*Nbr d'effets entrés par l'utilisateur*/
    float entree(effet.size());
    
    float nbrSameEffet(0);
    
    /*comparaison nbr effet entre et effet present dans le med */
    for (vector<string>::iterator it_effet = effet.begin(); it_effet != effet.end(); it_effet++)
    {
        for (vector<string>::iterator it_effMed = effMed.begin(); it_effMed != effMed.end(); it_effMed++)
        {
            if (*it_effet == *it_effMed)
            {
                nbrSameEffet++;
            }
            
        }
    }
    
    
    return entree/nbrSameEffet;
}


/******** Fonction de calcul de la precision  *********/

float Histogramme::calcul_Precision(string med,vector<string> effet)
{
    vector<string> effMed(effet_Medicament(med)) ;
    
    /*Nbr d'effets entrés par l'utilisateur*/
    float entree(effet.size());
    
    
    /*On va compter le nombre d'effet d'un medicament*/
    float total(effMed.size());
    
    return entree/total;
}


/********* Affichage du rappel et de la precision *******/

void Histogramme::affiche_Rap_Prec()
{
    string med,temp;
    vector<string> effet;
    float rap, prec;
    bool i = true;
    
    cout<<"entrez un medicament :";
    cin >> med;
    transform(med.begin(), med.begin()+1,med.begin(),::toupper );
    transform(med.begin()+1, med.end(),med.begin()+1,::tolower );
    
    while (i)
    {
        cout << endl;
        cout << "entrez un effet, taper 'fin' pour terminer : ";
        cin>>temp;
        transform(temp.begin(), temp.end(),temp.begin(),::tolower );
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
    
    
    /*Affichage*/
    
    
    cout<<endl;
    cout<< "Pour le medicament : " << med <<endl;
    cout<< "Le Rappel est de : "<< rap <<endl;
    cout<< "La Precision est de : "<< prec<<endl;
    cout<<endl;
    
}

