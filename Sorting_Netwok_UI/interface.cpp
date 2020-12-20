#include "interface.h"
#include "ui_interface.h"

Interface::Interface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Interface)
{
    ui->setupUi(this);

    _network = new Network(4);
    _grid_windows = new QGridLayout();
    _draw_sorting_network = new DrawArea(_network);

    _grbox_sort_param = createSortingParamGroup();
    _grbox_paralle_param = createParallelParamGroup();
    _grbox_input_values = createInputValuesGroup();
    _hbox_ui_button = createUIButtonGroup();

    _grid_windows->addWidget(_grbox_sort_param, 0, 1);
    _grid_windows->addWidget(_grbox_paralle_param, 1, 1);
    _grid_windows->addWidget(_grbox_input_values, 2, 1);
    _grid_windows->addLayout(_hbox_ui_button, 3, 1);
    _grid_windows->addWidget(_draw_sorting_network, 0, 0, 4 , 1);

    setLayout(_grid_windows);
}


Interface::~Interface()
{
    delete ui;
}

QGroupBox *Interface::createSortingParamGroup()
{
    QGroupBox *group_box = new QGroupBox("Sorting Parameters");
    QRadioButton *radio_sorting = new QRadioButton("Sorting Numbers");
    QRadioButton *radio_zeroun = new QRadioButton("Zero-One Test");
    QVBoxLayout *vbox_layout = new QVBoxLayout();

    radio_zeroun->setDisabled(true);

    //Place widget in layout
    vbox_layout->addWidget(radio_sorting);
    vbox_layout->addWidget(radio_zeroun);

    group_box->setMaximumWidth(200);
    //Set layout
    group_box->setLayout(vbox_layout);

    //Connect radio button
    connect(radio_sorting, &QRadioButton::toggled,
            this,&Interface::enableValuesGroup);
//    connect(radio_zeroun, &QRadioButton::toggled,
//            this,&Interface::disableValuesGroup);


    return group_box;
}

QGroupBox *Interface::createParallelParamGroup()
{
    QGroupBox *group_box = new QGroupBox("Parallel Mode");
    QRadioButton *radio_enable = new QRadioButton("Enable");
    QRadioButton *radio_disable = new QRadioButton("Disable");
    QHBoxLayout *hbox_layout = new QHBoxLayout();

    //Place widget
    hbox_layout->addWidget(radio_enable);
    hbox_layout->addWidget(radio_disable);

    group_box->setMaximumWidth(200);
    //Set layout
    group_box->setLayout(hbox_layout);

    group_box->setDisabled(true);

    return group_box;
}

QGroupBox *Interface::createInputValuesGroup()
{
    QLineEdit *line_value1 = new QLineEdit();
    QLineEdit *line_value2 = new QLineEdit();
    QLineEdit *line_value3 = new QLineEdit();
    QLineEdit *line_value4 = new QLineEdit();
    QPushButton *input_values= new QPushButton("Input Values");

    QGroupBox *group_box = new QGroupBox("Values Parameters");

    QLabel *label_value1 = new QLabel("Value 1 :");
    QLabel *label_value2 = new QLabel("Value 2 :");
    QLabel *label_value3 = new QLabel("Value 3 :");
    QLabel *label_value4 = new QLabel("Value 4 :");

    QGridLayout *gridbox_layout = new QGridLayout;

    //Place widget in layout
    gridbox_layout->addWidget(line_value1,0,1);
    gridbox_layout->addWidget(label_value1,0,0);

    gridbox_layout->addWidget(line_value2,1,1);
    gridbox_layout->addWidget(label_value2,1,0);

    gridbox_layout->addWidget(line_value3,2,1);
    gridbox_layout->addWidget(label_value3,2,0);

    gridbox_layout->addWidget(line_value4,3,1);
    gridbox_layout->addWidget(label_value4,3,0);

    gridbox_layout->addWidget(input_values,4,0,1,2);
    group_box->setMaximumWidth(200);
    //set layout and disable it
    group_box->setLayout(gridbox_layout);

    group_box->setDisabled(true);


    //Slot lambda
    connect(line_value1, &QLineEdit::editingFinished, this, [line_value1, this](){setValue(line_value1->text(), 0);});
    connect(line_value2, &QLineEdit::editingFinished, this, [line_value2, this](){setValue(line_value2->text(), 1);});
    connect(line_value3, &QLineEdit::editingFinished, this, [line_value3, this](){setValue(line_value3->text(), 2);});
    connect(line_value4, &QLineEdit::editingFinished, this, [line_value4, this](){setValue(line_value4->text(), 3);});

    connect(input_values, &QPushButton::clicked, this, &Interface::enableStartValues);

    return group_box;
}

QHBoxLayout *Interface::createUIButtonGroup()
{
    QHBoxLayout *hbox_layout = new QHBoxLayout;
    hbox_layout->addWidget(_ui_play);
    hbox_layout->addWidget(_ui_quit);

    connect(_ui_play, &QPushButton::clicked, this, &Interface::playSortingValues);

    _ui_play->setDisabled(true);

    connect(_ui_quit, SIGNAL(clicked()),qApp,SLOT(quit()));

    return hbox_layout;
}

void Interface::enableValuesGroup()
{
    _grbox_input_values->setDisabled(false);
    update();
}

void Interface::setValue(QString str_value, int pos)
{
    if(pos < _network->fils_number())
    {
        bool str_to_int = false;

        int temp_value = str_value.toInt(&str_to_int, 10);

        //Verify Int conversion
        if(str_to_int)
        {
            _network->addValue(temp_value, pos);
        }
    }
}

void Interface::enableStartValues()
{
    _ui_play->setDisabled(false);
    _draw_sorting_network->setStartValues(true);
    _draw_sorting_network->setEndValues(false);
}

void Interface::playSortingValues()
{
    _network->setSorting_index(0);
    _network->sortingValues();

    _draw_sorting_network->setEndValues(true);
}

