#ifndef VALUE_H
#define VALUE_H

#include <QList>
#include <QPoint>
#include "fils.h"

class Value
{
private:
    int _value = 0;
    int _position_start = 0;
    int _position = 0; //INUTILE ???
    Fils *_fils_nb;

    QList <QPoint *> _list_point;

public:
    Value(int value, Fils *fils);
    int value() const;
    Fils *fils_nb() const;

    void addPoint(QPoint *point);
    int position() const;
    QList<QPoint *> list_point() const;
};

#endif // VALUE_H
