#include "mostrar_cadastro.h"
#include "ui_mostrar_cadastro.h"

mostrar_cadastro::mostrar_cadastro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mostrar_cadastro)
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

mostrar_cadastro::~mostrar_cadastro()
{
    delete ui;
}
