#include <cassert>
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <deque>

#include "Pharmacie.hpp"
#include "Histogramme.hpp"

using namespace std;
// Définition de macro pour les tests d'ouverture de fichiers

#define USAGE usage(argv[0])

#define ARG_TEST_BEGIN(argstr,nbarg) \
    if(std::string(argv[i]) == std::string(argstr)) { \
        i += nbarg; \
    if(argc <= i) \
        USAGE;

#define ARG_TEST_END } else



void usage(char* progname) {
    std::cerr << "Usage:\n";
    std::cerr << "  " << progname << " [filename]\n";
    std::cerr << "If filename is not specified, error.\n";
    std::cerr << "Options:\n";
    std::cerr << "  -h --help\tShow this message.\n";
    std::cerr << std::flush;
    std::exit(EXIT_FAILURE);
}




/********Fonction qui permet de verifier l'entrée utilisateur********/

bool read_choice( int & N,int bas, int haut )
{
    cout << "Entrez un chiffre entre "<<bas<<" et "<<haut<<" : " ;
    while ( ! ( cin >> N ) || N < bas || N > haut )
    {
        if ( cin.eof() )
        {
            // ^D  (^Z sous windows); Fin du flux d'entree !
            return false;
        }
        else if ( cin.fail() )
        {
            cout << "Saisie incorrecte, recommencez : ";
            cin.clear();
            cin.ignore( numeric_limits<streamsize>::max(), '\n' );
        }
        else
        {
            cout << "Le chiffre n'est pas entre "<<bas<<" et "<< haut<<" , recommencez : ";
        }
    }
    return true; // succès
}


void afficheMenuPPl()
{
    cout<< "**********************************************************************"<<endl;
    cout<< "*                                                                    *"<<endl;
    cout<< "*                     Bienvenu dans la Pharmacie                     *"<<endl;
    cout<< "*                                                                    *"<<endl;
    cout<< "**********************************************************************"<<endl;
    
    cout<<endl;
    
    cout<< "**********************************************************************"<<endl;
    cout<< "*               Que souhaitez vous faire ?                           *"<<endl;
    cout<< "*                                                                    *"<<endl;
    cout<< "*                   1) Afficher                                      *"<<endl;
    cout<< "*                                                                    *"<<endl;
    cout<< "*                   2) Faire une recherche                           *"<<endl;
    cout<< "*                                                                    *"<<endl;
    cout<< "*                   3) Ajouter un medicament                         *"<<endl;
    cout<< "*                                                                    *"<<endl;
    cout<< "*                   4) Sortir                                        *"<<endl;
    cout<< "*                                                                    *"<<endl;
    cout<< "**********************************************************************"<<endl;
    cout<<endl;
}


void afficher()
{
    
    cout<< "**********************************************************************"<<endl;
    cout<< "*               Que souhaitez vous faire ?                           *"<<endl;
    cout<< "*                                                                    *"<<endl;
    cout<< "*                   1) Afficher la pharmacie                         *"<<endl;
    cout<< "*                                                                    *"<<endl;
    cout<< "*                   2) Afficher l'histogramme                        *"<<endl;
    cout<< "*                                                                    *"<<endl;
    cout<< "*                   3) Afficher les effets                           *"<<endl;
    cout<< "*                                                                    *"<<endl;
    cout<< "*                   4) Sortir                                        *"<<endl;
    cout<< "*                                                                    *"<<endl;
    cout<< "**********************************************************************"<<endl;
    cout<<endl;
    
    
    
    
}

void rechercher()
{
    cout<< "**********************************************************************"<<endl;
    cout<< "*               Que souhaitez vous faire ?                           *"<<endl;
    cout<< "*                                                                    *"<<endl;
    cout<< "*                   1) Rechercher par medicament                     *"<<endl;
    cout<< "*                                                                    *"<<endl;
    cout<< "*                   2) Rechercher par effet                          *"<<endl;
    cout<< "*                                                                    *"<<endl;
    cout<< "*                   3) Calcul du Rappel et de la Precision           *"<<endl;
    cout<< "*                                                                    *"<<endl;
    cout<< "*                   4) Sortir                                        *"<<endl;
    cout<< "*                                                                    *"<<endl;
    cout<< "**********************************************************************"<<endl;
    cout<<endl;
    
}

/*****Fonction qui vas faire tourner le programme******/

void play(Histogramme histo)
{
    bool boucle = true;
    int choix;
    string medicament;
    
    afficheMenuPPl();
    
    if ( read_choice( choix,1,4 ) )
    {
        cout << "Vous avez choisi : " << choix << '\n';
    }
    
    
    /*********************************/
    /*                               */
    /*          Debut Switch         */
    /*                               */
    /*********************************/
    
    switch (choix)
    {
            
            /*********************************/
            /*                               */
            /*          Affichage            */
            /*                               */
            /*********************************/
        case 1: {
            
            afficher();
            if ( read_choice( choix,1,4 ) )
            {
                cout << "Vous avez choisi : " << choix << '\n';
            }
            while (boucle)
            {

            
            
                switch (choix)
                {
                        
                        /******************************************/
                        /********** Afficher la pharmacie *********/
                        /******************************************/
                    case 1:
                    {
                        
                        histo.afficher_Pharma();
                        cin.clear();
                        cin.ignore( numeric_limits<streamsize>::max(), '\n' );
                        

                        afficher();
                        if ( read_choice( choix,1,4 ) )
                        {
                            cout << "Vous avez choisi : " << choix << '\n';
                        }
                        break;
                    
                    }
                        
                        /******************************************/
                        /********* Afficher l'histogramme *********/
                        /******************************************/
                    case 2:
                    {
                        histo.afficher_Histo();
                        
                        cin.clear();
                        cin.ignore( numeric_limits<streamsize>::max(), '\n' );
                        
                        afficher();
                        if ( read_choice( choix,1,4 ) )
                        {
                            cout << "Vous avez choisi : " << choix << '\n';
                        }
                        break;
                        
                    }
                        
                        /******************************************/
                        /********** Afficher les effets  **********/
                        /******************************************/
                    case 3:
                    {
                        
                        histo.afficher_Effet();
                        
                        cin.clear();
                        cin.ignore( numeric_limits<streamsize>::max(), '\n' );
                        afficher();
                        if ( read_choice( choix,1,4 ) )
                        {
                            cout << "Vous avez choisi : " << choix << '\n';
                        }

                        break;
                    
                    }
                        /******************************************/
                        /***************** Sortir *****************/
                        /******************************************/
                    case 4:
                    {
                        boucle=false;
                        play(histo);
                        break;
                    
                    }
                }
            }
            break;
        }
            
            
            
            
            /*********************************/
            /*                               */
            /*       Faire une recherhce     */
            /*                               */
            /*********************************/
            
        case 2:
        {
            rechercher();
            if ( read_choice( choix,1,4 ) )
            {
                cout << "Vous avez choisi : " << choix << '\n';
            }
            while (boucle)
            {
                
                switch (choix)
                {
                    case 1:
                    {
                        /******************************************/
                        /******** Recherche par Medicament ********/
                        /******************************************/
                        
                        cout<<"entrez votre medicament"<<endl;
                        cin>>medicament;
                        
                        
                        transform(medicament.begin(), medicament.begin()+1,medicament.begin(),::toupper );
                        transform(medicament.begin()+1, medicament.end(),medicament.begin()+1,::tolower );
                        cout<<"voulez vous un nombre d'effet en commun ? 1:Oui 2:Non"<<endl;
                        //cin>>choix;
                        if ( read_choice( choix,1,2 ) )
                        {
                            cout << "Vous avez choisi : " << choix << '\n';
                        }
                        
                        
                        if(choix==1)
                        {
                            cin.clear();
                            cin.ignore( numeric_limits<streamsize>::max(), '\n' );
                            int nbEffet;
                            cout<<"nombre d'effet en commun:";
                            cin>>nbEffet;
                            
                            histo.recherche_Par_Medicaments(medicament,nbEffet);
                            
                        }
                        else{
                            histo.recherche_Par_Medicaments(medicament);
                        }
                        
                        
                        
                        
                        cin.clear();
                        cin.ignore( numeric_limits<streamsize>::max(), '\n' );
    
                        rechercher();
                        
                        if ( read_choice( choix,1,4 ) )
                        {
                            cout << "Vous avez choisi : " << choix << '\n';
                        }
                        break;
                        
                    }
                    case 2:
                    {
                        /******************************************/
                        /********** Recherche par effet ***********/
                        /******************************************/
                        histo.afficher_Effet();
                        string effet;
                        cout<<endl;
                        
                        cout<<"entrez votre effet"<<endl;
                        cin>>effet;
                        
                        transform(effet.begin(), effet.end(),effet.begin(),::tolower );
                        histo.recherche_Par_Effet(effet);
                        
                        cin.clear();
                        cin.ignore( numeric_limits<streamsize>::max(), '\n' );
                        
                        rechercher();
                        if ( read_choice( choix,1,4 ) )
                        {
                            cout << "Vous avez choisi : " << choix << '\n';
                        }
                        break;
                        
                    }
                        
                        /******************************************/
                        /******* Calcul Rappel et Precision *******/
                        /******************************************/
                    case 3:
                    {
                        histo.affiche_Rap_Prec();
                        
                        cin.clear();
                        cin.ignore( numeric_limits<streamsize>::max(), '\n' );
                        rechercher();
                        if ( read_choice( choix,1,4 ) )
                        {
                            cout << "Vous avez choisi : " << choix << '\n';
                        }
                        
                        break;
                        
                    }
                        
                        /******************************************/
                        /***************** Sortir *****************/
                        /******************************************/
                    case 4:
                    {
                        boucle=false;
                        play(histo);
                        break;
                        
                    }
                }
            }
            break;
            
        }
            
            
            
            
            
            /*********************************/
            /*                               */
            /*      Ajouter medicament       */
            /*                               */
            /*********************************/
            
        case 3:
        {
            string medicament;
            vector<string> effetMedicament;
            string effet;
            int choix;
            bool loop=true;
            
            cout << "tapez le nom de votre medicament :"<<endl;
            cin>>medicament;
            
            transform(medicament.begin(), medicament.begin()+1,medicament.begin(),::toupper );
            transform(medicament.begin()+1, medicament.end(),medicament.begin()+1,::tolower );
            
            cin.clear();
            cin.ignore( numeric_limits<streamsize>::max(), '\n' );
            cout<<"ajouter un effet :"<<endl;
            getline(cin,effet);
            transform(effet.begin(), effet.end(),effet.begin(),::tolower );
            effetMedicament.push_back(effet);
            
            while(loop==true){
                cout<<"voulez vous rajouter un effet ?"<<endl<<"1)Oui"<<endl<<"2)Non"<<endl;
                
                cin>>choix;
                
                switch (choix) {
                    case 1:
                        
                        cin.clear();
                        cin.ignore( numeric_limits<streamsize>::max(), '\n' );
                        cout<<"rentrez l'effet a ajouter:"<<endl;
                        getline(cin,effet);
                        transform(effet.begin(), effet.end(),effet.begin(),::tolower );
                        effetMedicament.push_back(effet);
                        break;
                        
                    case 2:
                        histo.ajouter_Medicament(medicament, effetMedicament);
                        loop=false;
                        play(histo);
                        break;
                        
                    default:
                        break;
                    
            }
            
            
            
        }
            break;
        }
            
            
            
            
            
            /*********************************/
            /*                               */
            /*            Sortir             */
            /*                               */
            /*********************************/
            
            
        case 4:
        {
            break;
        }
    }
    
    
    
}




int main(int argc, char** argv){
    std::string inFilename; // le nom du fichier de médicaments
    
    //On ne rentre dans la boucle que si le nombre d'argument est sup à 1
     
    for(int i=1; i<=argc; i++)
    {
        ARG_TEST_BEGIN("-h", 0)
        USAGE;
        ARG_TEST_END
        
        ARG_TEST_BEGIN("--help", 0)
        USAGE;
        ARG_TEST_END
        {
            if(argv[i][0] == '-' || !inFilename.empty())
                USAGE;
            inFilename = argv[i];
        }
        
        try
        { // renvoi d'une exception s'il y a un soucis
            Pharmacie pharma(inFilename); // crée la pharmacie en faisant le parsing en même temps
            
            //insérez vous méthodes ici
            
            Histogramme histo(pharma);
            play(histo);
            
        }
        catch(const runtime_error& err)
        {
            std::cerr << err.what() << "\n";
            std::cerr << "Error while loading data file. Aborting." << std::endl;
            return EXIT_FAILURE;
        }
        
        cout<<"Success "<<endl;
        return EXIT_SUCCESS;
        
    }
}
