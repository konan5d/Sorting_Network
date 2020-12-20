#include "../shared/qstd.h"
using namespace qstd;

#include "reseau.h"
#include <QList>

int main()
{
    cout<<"Projet Reseau de Tri :"<<endl;
    //cout<<"Allocation : "<<endl;
    Reseau fils(4);
    // initialisation
    //cout<<"Initialisation : "<<endl;
    fils.ajouteConnecteur(0, 2, 0);
    fils.ajouteConnecteur(1, 3, 1);
    fils.ajouteConnecteur(0, 1, 2);
    fils.ajouteConnecteur(2, 3, 2);
    fils.ajouteConnecteur(1, 2, 3);

    cout<<"Affichage : "<<endl;
    cout<<fils.getConnecteur(0).toString()<<endl;
    cout<<fils.getConnecteur(1).toString()<<endl;
    cout<<fils.getConnecteur(2).toString()<<endl;
    cout<<fils.getConnecteur(3).toString()<<endl;
    cout<<fils.getConnecteur(4).toString()<<endl;

    // test d'injection unitaire
    //int iFilVers=fils.croisement(0);
    //cout<<"Fil final de "<< 3<<" : "<<iFilVers<<endl;
    // test d'injection d'une liste
    QList<int> entree;
    entree << 3<< 2<< 4<< 1 ;
    QList<int> sortie=fils.tri(entree);

    cout<<"Sortie :"<<endl;
    foreach (int v, sortie) {
        cout<<v<<endl;
    }

    cout<<"Test zero un"<<endl;
    fils.testZeroUn();
}
