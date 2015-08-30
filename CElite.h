#ifndef ____CELITE____
#define ____CELITE____

#include "CChromosome.h"
#include "CParty.h"
#include "CDistance.h"

class CElite{
    private:
    
        int * mChromosomeElite;
        int mlength;
        
    public:
    
        // constructeur
        
        CElite(int,CParty &,CDistance &);
        
        // destructeur
        
        ~CElite();
        
        // methode
        
        int fitness(CChromosome &,CDistance &); // calcul du meilleur
        void mute(CParty &,CDistance &); // mutation
        void injection(CParty &); // injection des meilleur élites dans une nouvelle pop
        void crossing(CParty &,CDistance &); // croisement
        int getPathElite(int); // accesseur
        int getLength(); // accesseur
};

#endif
