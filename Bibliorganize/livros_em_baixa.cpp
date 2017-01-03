#include "livros_em_baixa.h"
#include "ui_livros_em_baixa.h"
#include "global.h"
#include <QtSql>

Livros_em_baixa::Livros_em_baixa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Livros_em_baixa)
{
    ui->setupUi(this);

    // DETERMINAR NA TELA INICIAL A TABELA DO BANCO DE DADOS
    QString ordenado = ui->comboBox->currentText();

    QSqlQueryModel *t = Datab.Tabela_leitura_completa(baixa_b, ordenado);
    ui->tableView->setModel(t);

    int quantidade = Datab.numero_dados(baixa_b);
    ui->lcdNumber->display(quantidade);
    ui->lcdNumber->show();
}

Livros_em_baixa::~Livros_em_baixa()
{
    delete ui;
}

void Livros_em_baixa::on_pushButton_clicked()
{
    // DETERMINAR NA TELA INICIAL A TABELA DO BANCO DE DADOS
    QString ordenado = ui->comboBox->currentText();

    QSqlQueryModel *t = Datab.Tabela_leitura_completa(baixa_b, ordenado);
    ui->tableView->setModel(t);

    int quantidade = Datab.numero_dados(baixa_b);
    ui->lcdNumber->display(quantidade);
    ui->lcdNumber->show();
}

void Livros_em_baixa::on_tableView_clicked(const QModelIndex &index)
{

}
