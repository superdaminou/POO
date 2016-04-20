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
            //histo.afficherHisto();
            histo.afficherHisto();
            histo.rechercheParMedicaments("Loratadine");
            
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
