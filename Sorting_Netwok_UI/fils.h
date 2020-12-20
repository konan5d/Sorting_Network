#ifndef FILS_H
#define FILS_H

#include <QPoint>

class Fils
{
private:
    int _position = 0;
    QPoint *_line_start_pos;
    QPoint *_line_end_pos;
    int _lenght = 0;

public:
    Fils(int pos);

    void calculatePosition(int fils_nb, int wind_w, int window_h, int w_offset);
    QPoint *line_start_pos() const;
    void setLine_start_pos(QPoint *line_start_pos);
    QPoint *line_end_pos() const;
    void setLine_end_pos(QPoint *line_end_pos);
    int lenght() const;
    int position() const;
};

#endif // FILS_H
