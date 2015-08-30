#ifndef ____CCHROMOSOME____
#define ____CCHROMOSOME____
#include <cstdlib>
#include <ctime>

class CChromosome
{
    private :
    
        int* mPath;
        int mlength;
        
    public :
    
        //constructeur
        
        CChromosome();
        CChromosome(int);
        CChromosome(const CChromosome &); // constructeur par recopie
        
        //destructeur
        
        ~CChromosome();
        
        //methodes
        
        void print(); // afficheur
        CChromosome& operator=(const CChromosome &); // surchargeur
        int getLength(); // accesseur
        int getPath(int); // accesseur
        int* getmPath(); // accesseur
        void setPath(int,int); // accesseur
        void setNewChromosome(); // accesseur
};

#endif
