#include "CGeneList.h"
#include <iostream>

using namespace std;

//Constructeur

CGeneList::CGeneList(){
    mList=NULL;
    mNbGene=0;
}

CGeneList::CGeneList(const int pNbGene){
    
    mNbGene=pNbGene;
    mList = new CGene[pNbGene];
    
    for(int i=0;i<pNbGene;i++){
        mList[i]=CGene(i);
    }
}

CGeneList::CGeneList(const CGeneList &pTW){
    mNbGene=pTW.mNbGene;
    
    mList=new CGene[mNbGene];
    
    for(int i=0;i<mNbGene;i++)
        mList[i]=pTW.mList[i];
}

//Destructeur

CGeneList::~CGeneList(){
    delete [] mList;
}

//Methodes

void CGeneList::print(){ // afficheur
    
    for(int i=0;i<mNbGene;i++){
        cout<<"Ville n°"<<mList[i].getNum()<<"; x="<<mList[i].getCoordx()<<"    y="<<mList[i].getCoordy()<<endl;
    }
}

int CGeneList::getNbGene(){
    return mNbGene;
}

CGene* CGeneList::getList(){
    return mList;
}

CGene CGeneList::getGene(int i){
    return mList[i];
}

CGeneList& CGeneList::operator=(const CGeneList &pTW){
    if(this!=&pTW){
        mNbGene=pTW.mNbGene;
        
        delete [] mList;
        mList=new CGene[mNbGene];
        
        for(int i=0;i<mNbGene;i++)
            mList[i]=pTW.mList[i];
    }
    
    return *this;
}














