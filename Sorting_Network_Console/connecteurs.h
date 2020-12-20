#ifndef CONNECTEURS_H
#define CONNECTEURS_H

#include <QString>

class Connecteurs
{
private:
    int m_depuis;
    int m_vers;
    int m_position;
public:
    Connecteurs(int dp, int v, int pos);
    int getDepuis() const;
    int getVers() const;
    int getPosition() const;
    QString toString();
    void decrementePosition();
    bool lessPositionThan(Connecteurs *c1, Connecteurs *c2);
    bool lessDepuisThan(Connecteurs *c1, Connecteurs *c2);
};

#endif // CONNECTEURS_H
