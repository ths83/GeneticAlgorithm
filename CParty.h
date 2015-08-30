#ifndef ____CPARTY____
#define ____CPARTY____

#include "CChromosome.h"

class CParty{
    private:
    
        CChromosome * mListPath;
        int mNbPath;

    public:
    
        // constructeur
        
        CParty(int);
        CParty(int,int); // nombre de listes et nombre de villes par listes
        CParty(const CParty &); // constructeur par recopie

        // destructeur
        
        ~CParty();
        
        // methodes
        
        void print(); // afficheur
        int getNbPath(); // accesseur
        CChromosome& getList(int);
        CParty& operator=(const CParty &); // surchargeur
        void setPathList(int,int,int); // accesseur
        void setNewPath(int); // accesseur
};

#endif
