#include "network.h"

void Network::setSorting_index(int sorting_index)
{
    _sorting_index = sorting_index;
}

void Network::addLastPoint()
{
    QPoint *temp_point;

    for(int index = 0; index < 4 ; index++)
    {
        temp_point = _list_fils.at(index)->line_end_pos();

        _list_values.at(index)->addPoint(temp_point);
    }
}

Network::Network(int fils_nb):_fils_number(fils_nb)
{
    //Create fils
    for(int fils_index = 0; fils_index < fils_nb ; fils_index++)
    {
        _list_fils.append(new Fils(fils_index));
    }

    //Create Connectors
    addConnector(0, 0, 2);
    addConnector(1, 1, 3);
    addConnector(2, 0, 1);
    addConnector(3, 2, 3);
    addConnector(4, 1, 2);

    //Init _list_values
    for(int value_index = 0; value_index < 4; value_index++)
    {
        _list_values.append(new Value(0, this->get_fils_at(value_index)));
    }
}

void Network::addConnector(int pos, int from, int at)
{
    _list_connectors.append(new Connector(pos, from, at));
}

void Network::addValue(int value, int pos)
{
    _list_values.replace(pos, new Value(value, this->get_fils_at(pos)));
}

bool Network::sortingValues()
{
    Connector *connector;
    Value *value_at;
    Value *value_from;

    //On parcours tous les fils du réseau
    while(_sorting_index < _list_connectors.size())
    {
       //On récupère le 1er connecteur
        connector = _list_connectors.at(_sorting_index);

        //On récupère la position du connecteur
        value_at = _list_values.at(connector->at());
        value_from = _list_values.at(connector->from());

        //On compare les valeurs
        if(value_from->value() > value_at->value())
        {
             //Todo : Save point
            value_from->addPoint(connector->line_start_pos());
            value_from->addPoint(connector->line_end_pos());

            value_at->addPoint(connector->line_end_pos());
            value_at->addPoint(connector->line_start_pos());

            _list_values.replace(connector->from(), value_at);
            _list_values.replace(connector->at(), value_from);

        }
        else
        {
            //Todo : Save point
            _list_values.at(connector->from())->addPoint(connector->line_start_pos());
            _list_values.at(connector->at())->addPoint(connector->line_end_pos());
        }
        _sorting_index = _sorting_index + 1;
    }

    addLastPoint();
}

QList<Fils *> Network::list_fils() const
{
    return _list_fils;
}

Fils *Network::get_fils_at(int pos) const
{
    return _list_fils.at(pos);
}

int Network::fils_number() const
{
    return _fils_number;
}

QList<Connector *> Network::list_connectors() const
{
    return _list_connectors;
}

QList<Value *> Network::getList_values() const
{
    return _list_values;
}

