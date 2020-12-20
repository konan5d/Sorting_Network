#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QWidget>
#include <QPainter>
#include <QPolygon>
#include <QApplication>
#include <QList>
#include "network.h"
#include "value.h"

class DrawArea : public QWidget
{
private:
    int _window_size_w;
    int _window_size_h;

    int _network_x_offset = 20;

    QPainter *_painter;
    Network *_network;

    QList <QColor *> _list_color;

    bool _draw_start_values = false;
    bool _draw_end_values = false;

public:
    DrawArea(Network *network);

    void paintEvent(QPaintEvent *event) override;

    int window_size_w() const;
    void setWindow_size_w(int window_size_w);
    int window_size_h() const;
    void setWindow_size_h(int window_size_h);

    void calculateFilsPosition(QList <Fils *> fils, int fils_nb);
    void drawFils(QList <Fils *> fils, QPainter *painter);

    void calculateConnectorsPosition(QList <Connector *> conn, int conn_nb);
    void drawConnectors(QList <Connector *> conn, QPainter *painter);

    void drawStartValues(QPainter *painter);
    void drawEndValues(QPainter *painter);

    void drawSortingRoad(QPainter *painter);

public slots:
    void setStartValues(bool value);
    void setEndValues(bool value);

};

#endif // DRAWAREA_H
