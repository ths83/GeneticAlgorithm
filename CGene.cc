#include "CGene.h"
#include <cstdlib>
#include <iostream>

#define HAUTEUR 800
#define LARGEUR 800

using namespace std;

int static u=5000;

// Constructeur

CGene::CGene(){
    mNum=0;
    mCoordx=0;
    mCoordy=0;
}

CGene::CGene(int pNum){

	// ce constructeur est celui le plus utilisé car c'est celui qui donne une
	// position aléatoire aux villes

    mNum=pNum;
    srand(time(NULL)*u);
    mCoordx=rand()%LARGEUR;
    u++;
    srand(time(NULL)*u);
    mCoordy=rand()%HAUTEUR;
    u++;
}

//destructeur

CGene::~CGene(){
}

// Methodes

int CGene::getNum() //accesseur
{
    return mNum;
}

int CGene::getCoordx() //accesseur
{
    return mCoordx;
}

int CGene::getCoordy() //accesseur
{
    return mCoordy;
}

void CGene::print() // afficheur
{
    cout<<"Ville n°"<<mNum<<endl;
    cout<<"x:"<<mCoordx<<"    y:"<<mCoordy<<endl;
}
































