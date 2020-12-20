#include "drawarea.h"

DrawArea::DrawArea(Network *network)
{
    _network = network;
    _window_size_h = this->height();
    _window_size_w = this->width();

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    //Calculate Position : Fils and Connectors
    calculateFilsPosition(_network->list_fils(), _network->fils_number());
    calculateConnectorsPosition(_network->list_connectors(), 5);

    _list_color.append(new QColor(Qt::blue));
    _list_color.append(new QColor(Qt::red));
    _list_color.append(new QColor(Qt::magenta));
    _list_color.append(new QColor(Qt::green));
}

void DrawArea::paintEvent(QPaintEvent *event)
{
    _painter = new QPainter(this);

    QPen black(Qt::black, 2);
    QPen blue(Qt::blue, 2);
    QPen red(*_list_color.at(1));
    red.setWidth(2);

    _painter->setWindow(0, 0, _window_size_h, _window_size_w);

    _painter->setPen(black);
    drawFils(_network->list_fils(), _painter);

    black.setStyle(Qt::DashLine);
    _painter->setPen(black);

    drawConnectors(_network->list_connectors(), _painter);

    if(_draw_start_values)
    {
        drawStartValues(_painter);
    }

    if(_draw_end_values)
    {
        drawEndValues(_painter);

        red.setStyle(Qt::DashLine);
        _painter->setPen(red);
        drawSortingRoad(_painter);
    }

    _painter->end();
}

void DrawArea::calculateFilsPosition(QList<Fils *> fils, int fils_nb)
{
    foreach (Fils *f, fils)
    {
        f->calculatePosition(fils_nb, _window_size_w, _window_size_h, _network_x_offset);
    }
}

void DrawArea::drawFils(QList<Fils *> fils, QPainter *painter)
{
    foreach (Fils *f, fils)
    {
        painter->drawLine(*f->line_start_pos(), *f->line_end_pos());
    }
}

void DrawArea::calculateConnectorsPosition(QList<Connector *> conn, int conn_nb)
{
    foreach (Connector *conn, conn)
    {
        conn->calculateCoordinates(5, _network->list_fils());
    }
}

void DrawArea::drawConnectors(QList<Connector *> conn, QPainter *painter)
{
    foreach (Connector *conn, conn)
    {
        painter->drawLine(*conn->line_start_pos(), *conn->line_end_pos());
    }
}

void DrawArea::drawStartValues(QPainter *painter)
{
    QPoint pos_offset(0, -5);
    QPoint *position;

    foreach (Value *v, _network->getList_values())
    {
        QPen pen(*_list_color.at(v->position()));

        _painter->setPen(pen);

        position = v->fils_nb()->line_start_pos();

        painter->drawText(*position + pos_offset, QString::number(v->value(), 10));
    }
}

void DrawArea::drawEndValues(QPainter *painter)
{
    QPoint pos_offset(0, -5);
    QPoint *position;

    foreach (Value *v, _network->getList_values())
    {
        QPen pen(*_list_color.at(v->position()));

        _painter->setPen(pen);

        position = v->list_point().last();

        painter->drawText(*position + pos_offset, QString::number(v->value(), 10));
    }
}

void DrawArea::drawSortingRoad(QPainter *painter)
{
    QPoint *point_1;
    QPoint *point_2;
    QPoint *point_offset = new QPoint(0, 10);


    foreach (Value *v, _network->getList_values())
    {
        QPen pen(*_list_color.at(v->position()));
        pen.setWidth(2);
        pen.setStyle(Qt::DashLine);

        _painter->setPen(pen);

        int nb_point = v->list_point().size();

        for(int index_point = 1; index_point < nb_point ; index_point++)
        {
            point_1 = v->list_point().at(index_point-1);
            point_2 = v->list_point().at(index_point);

            painter->drawLine(*point_1 + *point_offset, *point_2 + *point_offset);
        }
    }

}

void DrawArea::setStartValues(bool value)
{
    _draw_start_values = value;
    repaint();
}

void DrawArea::setEndValues(bool value)
{
    _draw_end_values = value;
    repaint();
}

int DrawArea::window_size_w() const
{
    return _window_size_w;
}

int DrawArea::window_size_h() const
{
    return _window_size_h;
}

void DrawArea::setWindow_size_h(int window_size_h)
{
    _window_size_h = window_size_h;
}

void DrawArea::setWindow_size_w(int window_size_w)
{
    _window_size_w = window_size_w;
}
