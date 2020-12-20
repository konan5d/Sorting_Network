#include "value.h"

int Value::value() const
{
    return _value;
}

Fils *Value::fils_nb() const
{
    return _fils_nb;
}

void Value::addPoint(QPoint *point)
{
    _list_point.append(point);
}

int Value::position() const
{
    return _position;
}

QList<QPoint *> Value::list_point() const
{
    return _list_point;
}

Value::Value(int value, Fils *fils):_value(value),_fils_nb(fils)
{
    //On attribue une valeur à un fils
    _position = fils->position();

    _position_start = _position;

    //On enregistre la première position
    _list_point.append(fils->line_start_pos());
}

