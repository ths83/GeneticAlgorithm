#include "CGene.h"
#include "CGeneList.h"
#include "CChromosome.h"
#include "CDistance.h"
#include "CParty.h"
#include "CElite.h"
#include "CClientTCP.h"
#include <iostream>

using namespace std;

int main()
{
    //pour 10 villes , 20 chemins , 300 tours de boucle
    //pour 20 villes , 40 chemins , 1000 tours de boucle
    //pour 70 villes , 50 chemins , 6000 tours de boucle

    int nbTown=10;

    CGeneList townList(nbTown); // on crée les villes avec leur initialisation (hauteur , largeur)
    CDistance km(townList); // on crée le singleton qui contiendra les distances entre chaque ville de la liste
    CParty pathList(20,nbTown); // on crée la liste qui contiendra tout les chemins générés aléatoirement
    CElite bestPath(10,pathList,km);  // on crée la classe qui calculera et traitera tout les élites

    for (int z=0;z<1000;z++){
        CElite bestPath(10,pathList,km); // on recalcule les élites a chaque tour de boucle
        bestPath.mute(pathList,km); // on fait muter les élites 
        bestPath.injection(pathList); // on injecte les élites dans une nouvelle population
        bestPath.crossing(pathList,km); // on permute des éléments des élites avec la nouvelle population
    }

    CElite end(10,pathList,km); // on calcule une derniere fois les élites pour avoir le meilleur en premiere position
    // lorsqu'on calcule un élite, ils sont triés du meilleur au moins bon , donc celui a la position 0 est le meilleur

    CClientTCP client("127.0.0.1",1500); // on établit une connection avec le serveur d'affichage 

    int x1,y1,x2,y2,tempx,tempy,townNumber; // x1y1 et x2y2 seront les coordonnées utilisée pour relier les villes
    // tempx et tempy serviront a relier les deux dernieres villes pour fermer la boucle

    CChromosome best; // cette instance de CChromosome sert a contenir le meilleur chemin
    best=pathList.getList(end.getPathElite(0));

    CGene town;
    
    townList.print();
    pathList.print();

    for(int i=0;i<nbTown-1;i++){ // affichage
		
        townNumber=best.getPath(i); // on releve l'indice de la premiere ville
        town=townList.getGene(townNumber);

        x1=town.getCoordx(); // on releve les coordonnées x et y
        y1=town.getCoordy();

        if(i==0){ // on met de coté les coordonnées de la premiere ville
            tempx=x1;
            tempy=y1;
        }

        client.drawPoint(x1,y1,CColor::sGreen); // on dessine le point qui représente une ville

        townNumber=best.getPath(i+1); // on prend l'indice de la ville suivante
        town=townList.getGene(townNumber);
        x2=town.getCoordx(); // on releve les coordonnées de la ville suivante
        y2=town.getCoordy();

        client.drawSegment( x1, y1, x2, y2, CColor::sRed ); // on dessine le segment qui relie 2 villes
    }

    client.drawSegment( x2, y2, tempx, tempy, CColor::sRed ); // on dessine le segment qui relie la premiere a la derniere ville

    return 0;
}
