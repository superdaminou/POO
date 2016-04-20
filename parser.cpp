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
    cout<< "*                   3) Afficher les effets                           *"<<endl;
    cout<< "*                                                                    *"<<endl;
    cout<< "*                   4) Sortir                                        *"<<endl;
    cout<< "*                                                                    *"<<endl;
    cout<< "**********************************************************************"<<endl;
    cout<<endl;
    
}



void play(Pharmacie pharma)
{
    bool i = true;
    int choix;
    string medicament;
    Histogramme histo(pharma);
    
    afficheMenuPPl();
    
    if ( read_choice( choix,1,4 ) )
    {
        cout << "Vous avez choisi : " << choix << '\n';
    }
    
    
    switch (choix)
    {
        case 1: {
            afficher();
            if ( read_choice( choix,1,4 ) )
            {
                cout << "Vous avez choisi : " << choix << '\n';
            }
            while (i)
            {

            
            
                switch (choix)
                {
                    case 1:
                    {
                        
                        afficher();
                        if ( read_choice( choix,1,4 ) )
                        {
                            cout << "Vous avez choisi : " << choix << '\n';
                        }
                        break;
                    
                    }
                    case 2:
                    {
                        histo.afficherHisto();
                        cin.clear();
                        cin.ignore( numeric_limits<streamsize>::max(), '\n' );
                        
                        afficher();
                        if ( read_choice( choix,1,4 ) )
                        {
                            cout << "Vous avez choisi : " << choix << '\n';
                        }
                        break;
                        
                    }
                    case 3:
                    {
                        
                        histo.afficherEffet();
                        cin.clear();
                        cin.ignore( numeric_limits<streamsize>::max(), '\n' );
                        
                        if ( read_choice( choix,1,4 ) )
                        {
                            cout << "Vous avez choisi : " << choix << '\n';
                        }

                        break;
                    
                    }
                    case 4:
                    {
                        i=false;
                        play(pharma);
                        break;
                    
                    }
                }
            }
            break;
        }
        case 2:
        {
            rechercher();
            if ( read_choice( choix,1,4 ) )
            {
                cout << "Vous avez choisi : " << choix << '\n';
            }
            while (i)
            {
                
                switch (choix)
                {
                    case 1:
                    {
                     
                        /******** Recherche par Medicament *******/
                        
                        cout<<"entrez votre medicament"<<endl;
                        cin>>medicament;
                        histo.rechercheParMedicaments(medicament);
                        
                        
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
                       
                        /******** Recherche par effet *******/
                        
                        cout<<"entrez votre effet"<<endl;
                        cin>>medicament;
                        histo.rechercheParEffet(medicament);
                        
                        cin.clear();
                        cin.ignore( numeric_limits<streamsize>::max(), '\n' );
                        
                        rechercher();
                        if ( read_choice( choix,1,4 ) )
                        {
                            cout << "Vous avez choisi : " << choix << '\n';
                        }
                        break;
                        
                    }
                    case 3:
                    {
                        cout << "3";
                        if ( read_choice( choix,1,4 ) )
                        {
                            cout << "Vous avez choisi : " << choix << '\n';
                        }
                        
                        break;
                        
                    }
                    case 4:
                    {
                        i=false;
                        play(pharma);
                        break;
                        
                    }
                }
            }
            break;
            
        }
        case 3:
        {
            cout << "3";
            break;
            
        }
        case 4:
        {
            cout << "4";
            break;
            // ici, ce n'est pas nécessaire, c'est la dernière instruction
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
           
            //histo.rechercheParMedicaments("Loratadine");
            play(pharma);
            
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
    cout<<"dehors la boucle"<<endl;
}
