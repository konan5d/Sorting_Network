#include "connector.h"
#include "fils.h"

QPoint *Connector::line_start_pos() const
{
    return _line_start_pos;
}

QPoint *Connector::line_end_pos() const
{
    return _line_end_pos;
}

int Connector::from() const
{
    return _from;
}

int Connector::at() const
{
    return _at;
}

Connector::Connector(int pos, int from, int at):_position(pos), _from(from), _at(at)
{

}

void Connector::calculateCoordinates(int conn_nb, QList<Fils *> f)
{
    int start_pos_x = (f.at(_from)->lenght())/conn_nb;

    _line_start_pos = new QPoint();
    _line_end_pos = new QPoint();

    _line_start_pos->setX(20+(start_pos_x/2)+start_pos_x*_position);
    _line_end_pos->setX(_line_start_pos->x());

    _line_start_pos->setY(f.at(_from)->line_start_pos()->y());
    _line_end_pos->setY(f.at(_at)->line_start_pos()->y());

}
