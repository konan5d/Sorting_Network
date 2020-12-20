#ifndef RESEAU_H
#define RESEAU_H

#include <QList>
#include <QString>
#include "connecteurs.h"

class Reseau
{
private:
    int nombre_fils;
    QList <Connecteurs *> m_list_conn;
public:
    Reseau(int nb_fils);
    void ajouteConnecteur(int dp, int v, int pos);
    void ajouteConnecteur(int dp, int v);
    void ajouteConnecteur(Connecteurs *c);
    Connecteurs getConnecteur(int pos);
    int getPosMax();

    bool testZeroUn();
    QList<int> tri(QList<int> valeurs);
    int getNombre_fils() const;
};

#endif // RESEAU_H
