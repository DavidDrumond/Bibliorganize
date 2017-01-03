#include "most_cadastro.h"
#include "ui_most_cadastro.h"
#include "global.h"
#include <QtSql>

most_cadastro::most_cadastro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::most_cadastro)
{
    ui->setupUi(this);

    // DETERMINAR NA TELA INICIAL A TABELA DO BANCO DE DADOS
    QString ordenado = ui->comboBox->currentText();

    QSqlQueryModel *t = Datab.Tabela_leitura_completa(cadastro_pessoas, ordenado);
    ui->tableView->setModel(t);

    int quantidade = Datab.numero_dados(cadastro_pessoas);
    ui->lcdNumber->display(quantidade);
    ui->lcdNumber->show();
}

most_cadastro::~most_cadastro()
{
    delete ui;
}

void most_cadastro::on_pushButton_clicked()
{
    // DETERMINAR NA TELA INICIAL A TABELA DO BANCO DE DADOS
    QString ordenado = ui->comboBox->currentText();

    QSqlQueryModel *t = Datab.Tabela_leitura_completa(cadastro_pessoas, ordenado);
    ui->tableView->setModel(t);

    int quantidade = Datab.numero_dados(cadastro_pessoas);
    ui->lcdNumber->display(quantidade);
    ui->lcdNumber->show();
}
