#include "CChromosome.h"
#include <iostream>

using namespace std;

int static u=5000;

//constructeur

CChromosome::CChromosome(){
    mlength=0;
    mPath=NULL;
}

CChromosome::CChromosome(int pNbTowns){ // constructeur le plus utilisé

	// ce constructeur prend en parametre juste un nombre de ville
	// qui correspond au nombre de villes utilisées pour le test
	// et un chemin est calculé aléatoirement	
	
    mlength=pNbTowns;
    mPath = new int[pNbTowns];
    
    for (int i=0;i<pNbTowns;i++)
        mPath[i]=i;
    
    int lx,ltmp,lrnd;
    
    lx = rand()%pNbTowns;
    lrnd=lx;
    
    srand(time(NULL)*u);
    
    for (int i=0;i<pNbTowns;i++)
    {
        while(lx==lrnd)
            lrnd=rand()%pNbTowns;
        
        lx=lrnd;
        ltmp=mPath[lx];
        mPath[lx]=mPath[i];
        mPath[i]=ltmp;
    }
    u++;
}

CChromosome::CChromosome(const CChromosome &pCChromosome){ // recopie

    mlength=pCChromosome.mlength;
    
    mPath = new int[mlength];
    
    for(int i=0;i<mlength;i++)
        mPath[i]=pCChromosome.mPath[i];
}

//destructeur

CChromosome::~CChromosome(){
    delete [] mPath;
}
    
//methodes

void CChromosome::print(){ // afficheur
    
    for(int i=0;i<mlength;i++)
            cout<<mPath[i]<<" ";
            
    cout<<endl;
}

CChromosome& CChromosome::operator=(const CChromosome &pPath){ // surchargeur

    if(this!=&pPath){
    
        delete[] mPath;
        mlength=pPath.mlength;
        mPath=new int[mlength];
        
        for(int i=0;i<mlength;i++)
            mPath[i]=pPath.mPath[i];
    }
    
    return *this;
}

int CChromosome::getLength(){ // accesseur
    return mlength;
}

int CChromosome::getPath(int i){ // accesseur
    return mPath[i];
}

int* CChromosome::getmPath(){ // accesseur
    return mPath;
}

void CChromosome::setPath(int pPos,int pObj){ // accesseur
    mPath[pPos]=pObj;
}

void CChromosome::setNewChromosome(){ // accesseur

	// cet accesseur permet de changer au complet un chromosome

    CChromosome lp(mlength);
    for (int i=0;i<mlength;i++)
        mPath[i]=lp.mPath[i];
}


























