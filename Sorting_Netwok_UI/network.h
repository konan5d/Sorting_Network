#ifndef NETWORK_H
#define NETWORK_H

#include <QList>
#include "fils.h"
#include "connector.h"
#include "value.h"

class Network
{
private:
    int _fils_number = 0;

    QList <Fils *> _list_fils;
    QList <Connector *> _list_connectors;
    QList <Value *> _list_values;

    int _sorting_index = 0;
public:
    Network(int fils_nb);
    int fils_number() const;
    QList<Fils *> list_fils() const;
    Fils *get_fils_at(int pos) const;

    void addConnector(int pos, int from, int at);
    QList<Connector *> list_connectors() const;

    void addValue(int value, int pos);
    QList<Value *> getList_values() const;

    bool sortingValues(void);
    void setSorting_index(int sorting_index);

    void addLastPoint(void);
};

#endif // NETWORK_H
