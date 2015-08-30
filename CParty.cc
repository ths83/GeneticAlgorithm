#include "CParty.h"
#include <iostream>

using namespace std;

//constructeur

CParty::CParty(int pNb){

    mNbPath=pNb;
    
    mListPath=new CChromosome[mNbPath];
}

CParty::CParty(int pNb,int pNbVilles){

	// ce constructeur est celui que l'on utilise dans le projet, il sert a créer
	// une liste de chemins (individus), ces chemins sont eux meme construits
	// aléatoirement lors de leur affectation (chromosome)
	
    mNbPath=pNb;
    
    mListPath=new CChromosome[mNbPath];
    
    for(int i=0;i<mNbPath;i++)
        mListPath[i]=CChromosome(pNbVilles);
}

CParty::CParty(const CParty &pCChromosome){ // recopie
    mNbPath=pCChromosome.mNbPath;
    
    for(int i=0;i<mNbPath;i++)
        mListPath[i]=pCChromosome.mListPath[i];
}

//destructeur

CParty::~CParty(){ // destructeur

    delete [] mListPath;
    
}

//methode

void CParty::print(){ // afficheur
    
    for(int i=0;i<mNbPath;i++)
        mListPath[i].print();
}

int CParty::getNbPath(){ // accesseur

    return mNbPath;
    
}

CChromosome& CParty::getList(int i){ // accesseur

    return mListPath[i];
    
}

CParty& CParty::operator=(const CParty &pPL){ // surchargeur
    if(this!=&pPL){
    
        mNbPath=pPL.mNbPath;
        
        delete [] mListPath;
        mListPath=new CChromosome[mNbPath];
        
        for(int i=0;i<mNbPath;i++)
            mListPath[i]=pPL.mListPath[i];
    }
    
    return *this;
}

void CParty::setPathList(int pPath,int pPos,int pObj){ // accesseur

    mListPath[pPath].setPath(pPos,pObj);
    
}

void CParty::setNewPath(int pNumPath){ // accesseur

    mListPath[pNumPath].setNewChromosome();
    
}






















