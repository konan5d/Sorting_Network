#include "fils.h"

QPoint *Fils::line_start_pos() const
{
    return _line_start_pos;
}

void Fils::setLine_start_pos(QPoint *line_start_pos)
{
    _line_start_pos = line_start_pos;
}

QPoint *Fils::line_end_pos() const
{
    return _line_end_pos;
}

void Fils::setLine_end_pos(QPoint *line_end_pos)
{
    _line_end_pos = line_end_pos;
}

int Fils::lenght() const
{
    return _lenght;
}

int Fils::position() const
{
    return _position;
}

Fils::Fils(int pos):_position(pos)
{
    
}

void Fils::calculatePosition(int fils_nb, int win_w, int win_h, int w_offset)
{
    int h_offset = (win_w/(fils_nb*2))*2;

    _line_start_pos = new QPoint();
    _line_start_pos->setX(w_offset);
    _line_start_pos->setY((win_w/(fils_nb*2))+(h_offset*_position));

    _line_end_pos = new QPoint();
    _line_end_pos->setX(win_h-w_offset);
    _line_end_pos->setY(_line_start_pos->y());

    _lenght = line_end_pos()->x() - _line_start_pos->x();
}
