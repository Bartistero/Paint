#include "rysowanie.h"
#include "ui_rysowanie.h"

rysowanie::rysowanie(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::rysowanie)
{
    ui->setupUi(this);
}

rysowanie::~rysowanie()
{
    delete ui;
}

