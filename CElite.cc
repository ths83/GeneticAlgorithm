#include "CElite.h"
#include <iostream>

using namespace std;

int u=5000;

//constructeur

CElite::CElite(int pPerCent,CParty &pList,CDistance &pDist){

	// c'est le seul constructeur de la classe elite et le seul qui est utile
	// ce constructeur prend en parametre une classe d'individus. ce constructeur
	// a pour role de trouver les meilleurs genes et d'enregistrer leur position
	// on en garde seulement un pourcentage

    float lLong=pList.getNbPath(); // on calcule le nombre de genes élites on diot garder
    lLong=lLong/100;
    lLong=lLong*pPerCent;
    mlength=lLong;

    mChromosomeElite=new int[mlength]; // liste d'indices des meilleurs chemins

    int lLong2=pList.getNbPath();

    int *lx; // liste contenant les totaux des élites
    lx=new int [lLong2];

    int *lIndex; // on crée une liste d'indices des meilleurs chemins destinés a un tri (plus tard)
    lIndex=new int [lLong2];

    for(int i=0;i<lLong2;i++)    
        lIndex[i]=i;

    for(int i=0;i<lLong2;i++) // on enregistre les totaux des élites
        lx[i]=fitness(pList.getList(i),pDist);
    
    int lTemp;
    int lCpt=0;
    
    while(lCpt<lLong2){ //tri à bulles pour mettre en premier le meilleur elite
    
        for(int i=0;i<lLong2-1;i++){
        
            if(lx[i]>lx[i+1]){
            
                lTemp=lx[i];
                lx[i]=lx[i+1];
                lx[i+1]=lTemp;
                
                lTemp=lIndex[i];
                lIndex[i]=lIndex[i+1];
                lIndex[i+1]=lTemp;
            }
        }
        lCpt++;
    }
    
    for(int i=0;i<mlength;i++){
        mChromosomeElite[i]=lIndex[i];
    }
}

//destructeur

CElite::~CElite(){    
    delete [] mChromosomeElite;
}

//fonctions

int CElite::fitness(CChromosome &pPath,CDistance &pDist){

	// cette fonction calcule la fitness des genes
	// elle utilise le singleton de la classe CDistance pour calculer cette fitness
	
    int lTot=0;

    for(int i=1;i<pPath.getLength();i++){
        lTot+=pDist.getDist(pPath.getPath(i-1),pPath.getPath(i));
    }
    
    lTot+=pDist.getDist(pPath.getPath(0),pPath.getPath(pPath.getLength()-1));
    
    return lTot;
}

void CElite::mute(CParty &pCpl,CDistance &pDist){

	// cette fonction a pour role de faire muter les meilleur genes
	// dans cette fonction on fait egalement attention a ve que la mutation
	// soit positive, si le gene muté est moins bon que l'ancien, on annule la mutation

    int lTemp1,lTemp2;
    int posA;
    int posB;
    int lTot1,lTot2;
    
    for(int i=0;i<mlength;i++){ // on fait la mutation que sur les genes élites
        
        srand(time(NULL)*u); // sers a avoir un random a coup sur
        u++;
        
        posA=rand()%pCpl.getList(0).getLength();
        srand(time(NULL)*u);
        u++;
        
        posB=rand()%pCpl.getList(0).getLength();
        srand(time(NULL)*u);
        u++;
        
        while(posA==posB) // sers a avoir un random a coup sur
            posB=rand()%pCpl.getList(0).getLength();
        
        lTemp1=pCpl.getList(mChromosomeElite[i]).getPath(posA);
        lTemp2=pCpl.getList(mChromosomeElite[i]).getPath(posB);
        
        lTot1=fitness(pCpl.getList(i),pDist); // ce total verifie la taille avant mutation
        
        
        
        pCpl.setPathList(mChromosomeElite[i],posA,lTemp2);
        pCpl.setPathList(mChromosomeElite[i],posB,lTemp1);
        
        lTot2=fitness(pCpl.getList(i),pDist); // ce total verifie la taille apres mutation
        
        if(lTot2>lTot1){ 
        	// si apres mutation le genes est moins bon, on annule la mutation
        
            lTemp1=pCpl.getList(mChromosomeElite[i]).getPath(posA);
            lTemp2=pCpl.getList(mChromosomeElite[i]).getPath(posB);
        
            pCpl.setPathList(mChromosomeElite[i],posA,lTemp2);
            pCpl.setPathList(mChromosomeElite[i],posB,lTemp1);
        
        }
    }
}

void CElite::injection(CParty &pCpl){ 
	
	// cette fonction sert a injecter les genes élites dans un nouveau individu
	// le reste des nouveaux individus seront calculés aléatoirement

    int lx=0;
    
    for(int i=0;i<pCpl.getNbPath();i++){
        lx=0;
        
        for(int j=0;j<mlength;j++){
        
            if(i==mChromosomeElite[j])
                lx=1;
        }
        
        if (lx==0)
            pCpl.setNewPath(i);
    }
}

void CElite::crossing(CParty &pCpl,CDistance &pDist){

	// cette fonction permet de permuter des éléments entre deux genes
	// de la nouvelle instance, pour que la nouvelle instance profite des bienfaits
	// des élites, on aura des problemes de doublons, et on les traitera de la maniere suivante :
	// on supprime les doublons, on vérifie si apres suppression le gene est meilleur
	// s'il n'est pas meilleur, on annule la permutation et on passe au second couple a traiter
    
    int lnbTown=pCpl.getList(0).getLength();
    
    srand(time(NULL)*u);
    u++;
    
    // on choisi aléatoirement combien de genes a permuter
    
    int lnbCross=(rand()%(lnbTown/2))+lnbTown-1;
    
    int lTemp1,lTemp2;
    int lTot1,lTot2,lTot3,lTot4;
    
    // on declare 2 instances pour sauvegarder le couple que l'on va traiter
    
    CChromosome tempPath1,tempPath2;
    
    int lLength=pCpl.getList(0).getLength();
    
    int *lList;
    lList=new int[lLength];
    for(int i=0;i<lLength;i++)
        lList[i]=0;

    int lTemp,lStock=-1,lStock2=-1,lindex;
    
    for(int i=0;i<pCpl.getNbPath()-2;i+=2){ // debut de la permutation
    
        tempPath1=pCpl.getList(i); // sauvegarde
        tempPath2=pCpl.getList(i+1);
        
        lTot1=fitness(pCpl.getList(i),pDist); // évaluation du couple
        lTot3=fitness(pCpl.getList(i+1),pDist);
    
        for(int j=lnbCross;j<lnbTown;j++){ // permutation
        	
            lTemp1=pCpl.getList(i).getPath(j);
            lTemp2=pCpl.getList(i+1).getPath(j);
            pCpl.setPathList(i,j,lTemp2);
            pCpl.setPathList(i+1,j,lTemp1);
        }
    
        for(int l=0;l<pCpl.getNbPath();l++){ // traitement des doublons
    
            for(int j=0;j<lLength;j++){
                lTemp=pCpl.getList(l).getPath(j);
                lList[lTemp]+=1;
            }

            for(int j=0;j<lLength;j++){
        
                if(lList[j]==0 && lStock==-1){
                    lStock=j;
                    j=0;
                }
            
                else if(lList[j]>1 && lStock2 ==-1){
                    lStock2=j;
                    j=0;
                }
                if (lStock2 != -1 && lStock != -1){
                
                    for (int k=0;k<lLength;k++)
                        if (pCpl.getList(l).getPath(k)==lStock2)
                            lindex=k;
                            
                    pCpl.setPathList(l,lindex,lStock);
                    lList[lStock2]-=1;
                    j=0;
                    lList[lStock]+=1;
                    lStock=-1;
                    lStock2=-1;
                }
            }    

            for(int j=0;j<lLength;j++)
                lList[j]=0;
        }

        lTot2=fitness(pCpl.getList(i),pDist); // évaluation apres traitement des doublons
        lTot4=fitness(pCpl.getList(i+1),pDist);
        
        if(lTot2>lTot1){ // si il y a régression dans le premier gene, on annule les changements
        
            for(int k=0;k<lnbCross;k++){
            
                lTemp1=tempPath1.getPath(k);
                pCpl.setPathList(i,k,lTemp1);    
            }
        }
        
        if(lTot4>lTot3){ // si il y a régression dans le second gene, on annule les changements
        	// en effet il pourrait y avoir un meilleur chemin dans ce second gene
        
            for(int k=0;k<lnbCross;k++){
            
                lTemp1=tempPath2.getPath(k);
                pCpl.setPathList(i+1,k,lTemp1);    
            }
        }
    }
}

int CElite::getPathElite(int i){ // accesseur

return mChromosomeElite[i];

}

int CElite::getLength(){ // accesseur

return mlength;

}

















