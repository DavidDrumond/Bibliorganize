#include "baixas.h"
#include "ui_baixas.h"

Baixas::Baixas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Baixas)
{
    ui->setupUi(this);
}

Baixas::~Baixas()
{
    delete ui;
}
