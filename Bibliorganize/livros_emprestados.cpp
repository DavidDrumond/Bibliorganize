#include "livros_emprestados.h"
#include "ui_livros_emprestados.h"
#include "global.h"
#include <QtSql>

livros_emprestados::livros_emprestados(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::livros_emprestados)
{
    ui->setupUi(this);

    // DETERMINAR NA TELA INICIAL A TABELA DO BANCO DE DADOS
    QString ordenado = ui->comboBox->currentText();

    QSqlQueryModel *t = Datab.Tabela_leitura_completa(emprestar, ordenado);
    ui->tableView->setModel(t);

    int quantidade = Datab.numero_dados(emprestar);
    ui->lcdNumber->display(quantidade);
    ui->lcdNumber->show();
}

livros_emprestados::~livros_emprestados()
{
    delete ui;


}

void livros_emprestados::on_pushButton_clicked()
{
    // DETERMINAR NA TELA INICIAL A TABELA DO BANCO DE DADOS
    QString ordenado = ui->comboBox->currentText();

    QSqlQueryModel *t = Datab.Tabela_leitura_completa(emprestar, ordenado);
    ui->tableView->setModel(t);

    int quantidade = Datab.numero_dados(emprestar);
    ui->lcdNumber->display(quantidade);
    ui->lcdNumber->show();
}
