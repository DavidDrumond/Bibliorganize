#include "alterar_cadastro.h"
#include "ui_alterar_cadastro.h"
#include "global.h"
#include <QMessageBox>


alterar_cadastro::alterar_cadastro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alterar_cadastro)
{
    ui->setupUi(this);

   ui->pushButton_2->click();
}

alterar_cadastro::~alterar_cadastro()
{
    delete ui;
}

void alterar_cadastro::on_tableView_clicked(const QModelIndex &index)
{
    //ADICIONAR INDICE DA TABELA

    QModelIndexList selecionados = ui->tableView->selectionModel()->selectedIndexes();
    QModelIndex item =  selecionados.at(0);
    int row = item.row();
    int colum = item.column();
    int valor_exp = ui->tableView->model()->data(ui->tableView->model()->index(row,0)).toInt();


    //CONNECT WITH INDICE LIVROS

    if (colum == 0){
        QMessageBox caixa;
        caixa.warning(this,"CAMPO NÃO PODE SER ALTERADO","Este campo não pode ser alterado !!!" );
        caixa.show();
    }
    colum = colum -1;
    ui->CAMPO->setCurrentIndex(colum);
    ui->INDICE->setValue(valor_exp);
}

void alterar_cadastro::on_pushButton_2_clicked()
{
    // PEGAR PARAMETROS
    QString nome  = ui->NOME->text();
    QString cpf = ui->CPF->text();
    QString telefone = ui->TELEFONE->text();


    // DETERMINAR NA TELA INICIAL A TABELA DO BANCO DE DADOS
    QSqlQueryModel *t = Datab.Tabela_Nome_CPF_Telefone(cadastro_pessoas,nome,cpf,telefone);
    ui->tableView->setModel(t);
}

void alterar_cadastro::on_pushButton_clicked()
{
    // PEGAR PARAMETROS
    QString Indice = ui->INDICE->text();
    QString Campo = ui->CAMPO->currentText();
    QString Alterado = ui->VALOR_ALTERADO->text();
    QString nome  = ui->NOME->text();
    QString cpf = ui->CPF->text();
    QString telefone = ui->TELEFONE->text();


    //MODIFICAR CAMPO
    Datab.modificar_campo(cadastro_pessoas,Indice,Campo,Alterado);

    // CHAMAR CAIXA DE NOTIFICACAO
    QMessageBox caixa;
    caixa.setText("Campo modificado com sucesso");
    caixa.exec();

    // DETERMINAR NA TELA INICIAL A TABELA DO BANCO DE DADOS
    QSqlQueryModel *t = Datab.Tabela_Nome_CPF_Telefone(cadastro_pessoas,nome,cpf,telefone);
    ui->tableView->setModel(t);
}
