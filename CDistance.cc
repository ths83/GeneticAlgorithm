#include "CDistance.h"
#include <iostream>
#include <cmath>

using namespace std;

// cette classe est un singleton

//constructeurs

CDistance::CDistance(CGeneList &pList){
	
	// cette classe est un singleton qui sert juste a etre interrogé
	// lors de la définition , les distances sont directement calculées
	// et sont disposées de facon matricielle

    mNb=pList.getNbGene();
    mMat=new int*[mNb];
    
    CGene * lListV=pList.getList();
    
    
    for(int i=0;i<mNb;i++){
        mMat[i]=new int[mNb];
        for(int j=0;j<mNb;j++){
            mMat[i][j]=calcDist(lListV[i],lListV[j]);
        }
    }            
}

CDistance::CDistance(const CDistance &pDist){ // recopie

    mNb=pDist.mNb;
    mMat=new int*[mNb];
    
    for(int i=0;i<mNb;i++){
        for(int j=0;j<mNb;j++){
            mMat[i][j]=pDist.mMat[i][j];
        }
    }
}

//destructeur

CDistance::~CDistance(){

	// ce destructeur un peu étrange est la seule solution
	// trouvée face a unprobleme de double free or corruption

    int * lTab = new int[500];
    
    for(int i=0;i<mNb;i++)
        delete [] mMat[i];
        
    delete [] mMat;
    delete [] lTab;
}

//methode

int CDistance::calcDist(CGene &v1,CGene &v2){

	// ici on calcule la distance entre 2 ville avec le theoreme de pythagore

    int lx,ly;
    
    lx=abs(v1.getCoordx()-v2.getCoordx());
    ly=abs(v1.getCoordy()-v2.getCoordy());
    
    int lDist=sqrt((lx*lx)+(ly*ly));
    
    return lDist;
}

void CDistance::print(){ // afficheur

    for(int i=0;i<mNb;i++){
    
        for(int j=0;j<mNb;j++)
            cout<<mMat[i][j]<<" ";
            
        cout<<endl;
    }
}

int CDistance::getDist(int i,int j){ // accesseur
	
	// vu que les distances sont enregistrées de facon matricielle
	// il suffit de donner deux villes en parametre pour retourner la distance qui les séparent

    return mMat[i][j];
    
}

CDistance& CDistance::operator=(const CDistance &pDist){ // surchargeur
    
    if(this!=&pDist){
        mNb=pDist.mNb;
        
        delete [] mMat;
        mMat=new int*[mNb];
    
        for(int i=0;i<mNb;i++){
            for(int j=0;j<mNb;j++){
                mMat[i][j]=pDist.mMat[i][j];
            }
        }
    }
    
    return *this;
}





























