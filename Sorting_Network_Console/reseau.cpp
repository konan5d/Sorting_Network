#include "reseau.h"
#include "../shared/qstd.h"
using namespace qstd;

int Reseau::getNombre_fils() const
{
    return nombre_fils;
}

Reseau::Reseau(int nb_fils):nombre_fils(nb_fils)
{
    
}

void Reseau::ajouteConnecteur(int dp, int v, int pos)
{
    //Intanciation d'un connecteur
    Connecteurs *c = new Connecteurs(dp, v, pos);
    //On ajoute le connecteur à notre liste
    m_list_conn.append(c);
}

Connecteurs Reseau::getConnecteur(int pos)
{
    Connecteurs *res = m_list_conn.at(pos);

    return *res;
}

int Reseau::getPosMax()
{
    int pos_max = 0;

    for(int i=0; i <= m_list_conn.size()- 1; i++)
    {
       if(getConnecteur(i).getPosition() > pos_max)
       {
           pos_max = getConnecteur(i).getPosition();
       }
    }

    return pos_max;
}

bool Reseau::testZeroUn()
{
    int n=0;
    //Génération du nombre en binaire
    QList<int> binary;
    for(int number=0; number <= 15; number++)
    {
        for(int i=0; i <= 3; i++)
        {
           binary.append(0);
        }

        n = number;

        for(int i=0; n>0; i++)
        {
            cout<<"binary "<<n%2<<endl;
            binary.replace(i, n%2);
            n = n/2;
        }

        QList<int> sortie=this->tri(binary);
        cout<<"Sortie :"<<endl;
        foreach (int v, sortie) {
            cout<<v<<endl;
        }

        binary.clear();
    }

}

QList<int> Reseau::tri(QList<int> valeurs)
{
    int buf;
    int val_depuis;
    int val_vers;
    int val_pos=0;

    //cout<<"getPosMax ="<<getPosMax()<<endl;

    while(val_pos <= m_list_conn.size()-1) //On parcours tous les connecteurs de notre réseau
    {
        //cout<<"val_pos ="<<val_pos<<endl;

        val_depuis = getConnecteur(val_pos).getDepuis();
        val_vers = getConnecteur(val_pos).getVers();

        /*cout<<"val_depuis ="<<val_depuis<<endl;
        cout<<"val_vers ="<<val_vers<<endl;

        cout<<"valeurs.at(val_depuis) ="<<valeurs.at(val_depuis)<<endl;
        cout<<"valeurs.at(val_vers) ="<<valeurs.at(val_vers)<<endl;*/

        if(valeurs.at(val_depuis) > valeurs.at(val_vers)) //Comparaison des 2 valeurs : si val > val2, on interchange les val
        {
            buf=valeurs.at(val_depuis);
            valeurs.replace(val_depuis, valeurs.at(val_vers));
            valeurs.replace(val_vers, buf);

            //cout<<"INVERSION"<<endl;
        }

        /*foreach (int v, valeurs) {
            cout<<v<<endl;
        }*/

        val_pos++;
        /*if(getConnecteur(val_pos + 1).getPosition() < val_pos) //Permet de détecter plusieurs connecteurs à la même position
        {
            val_pos++;
        }*/
    }


    return valeurs;
}

