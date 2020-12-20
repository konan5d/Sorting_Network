#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QLineEdit>
#include <QLabel>

#include "drawarea.h"
#include "network.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Interface; }
QT_END_NAMESPACE

class Interface : public QWidget
{
    Q_OBJECT
private:
    Network *_network;

    QGridLayout *_grid_windows;
    DrawArea *_draw_sorting_network;
    QGroupBox *_grbox_sort_param;
    QGroupBox *_grbox_paralle_param;
    QGroupBox *_grbox_input_values;

    QHBoxLayout *_hbox_ui_button;
    QPushButton *_ui_play = new QPushButton("Play");
    QPushButton *_ui_quit = new QPushButton("Quit");


public:
    Interface(QWidget *parent = nullptr);
    ~Interface();

    QGroupBox *createSortingParamGroup(void);
    QGroupBox *createParallelParamGroup(void);
    QGroupBox *createInputValuesGroup(void);
    QHBoxLayout *createUIButtonGroup(void);

public slots:
    void enableValuesGroup(void);
    void setValue(QString str_value, int pos);
    void enableStartValues(void);
    void playSortingValues(void);

private:
    Ui::Interface *ui;
};
#endif // INTERFACE_H
