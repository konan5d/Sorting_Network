#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QList>
#include <QPoint>
#include "fils.h"

class Connector
{
private:
    int _position = 0;
    QPoint *_line_start_pos;
    QPoint *_line_end_pos;

    int _from = 0; //depuis
    int _at = 0;

public:
    Connector(int pos, int from, int at);

    void calculateCoordinates(int conn_nb, QList <Fils *> f);
    QPoint *line_start_pos() const;
    QPoint *line_end_pos() const;

    int from() const;
    int at() const;
};

#endif // CONNECTOR_H
