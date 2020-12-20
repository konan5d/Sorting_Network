#include "connecteurs.h"
#include <QTextStream>

Connecteurs::Connecteurs(int dp, int v, int pos):m_depuis(dp), m_vers(v), m_position(pos)
{

}

int Connecteurs::getDepuis() const
{
    return m_depuis;
}

int Connecteurs::getVers() const
{
    return m_vers;
}

int Connecteurs::getPosition() const
{
    return m_position;
}

QString Connecteurs::toString()
{
    QString res;
    QTextStream flux(&res);
    //flux<<nom<<" : (diam.="<<diametre<<" km; dist.="<<distance<<" millions de km)";
    flux<<"Connecteur : (dp="<<m_depuis<<"; v="<<m_vers<<"; pos="<<m_position<<")";
    return res;
}

void Connecteurs::decrementePosition()
{
    m_position--;
}

bool Connecteurs::lessPositionThan(Connecteurs *c1, Connecteurs *c2)
{

}
