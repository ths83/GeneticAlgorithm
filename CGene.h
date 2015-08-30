#ifndef GENE
#define GENE

class CGene
{
    private:

        int mNum;
        int mCoordx;
        int mCoordy;

    public:

        // Constructeurs
        
        CGene();
        CGene(int); // constructeur le plus utilisé
        
        // destructeur
        
        ~CGene();

        // Methodes

        int getNum(); // accesseur
        int getCoordx(); // accesseur
        int getCoordy(); // accesseur
        void print(); // afficheur
};

#endif
