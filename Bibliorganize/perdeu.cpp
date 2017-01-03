#include "perdeu.h"
#include "ui_perdeu.h"
#include "global.h"
#include "mainwindow.h"
#include <QObject>
#include <QStringList>
#include <vector>
#include <QVector>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>

Perdeu::Perdeu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Perdeu)
{
    ui->setupUi(this);


    MainWindow *m2;
    QObject::connect(ui->pushButton_2,SIGNAL(clicked(bool)),m2,SLOT(Demonstrar_dados_emTela()));

    ui->pushButton->click();
}

Perdeu::~Perdeu()
{
    delete ui;
}

void Perdeu::on_pushButton_clicked()
{

    // PEGAR PARAMETROS
    QString autor  = ui->NOME_AUTOR->text();
    QString nome = ui->NOME_LIVRO->text();
    QString trilha = ui->TRILHA->text();



    // DETERMINAR NA TELA INICIAL A TABELA DO BANCO DE DADOS
    QSqlQueryModel *t = Datab.Tabela_Livro_Autor_Trilha(banco,autor,nome,trilha,1);
    ui->tableView->setModel(t);

}

void Perdeu::on_pushButton_2_clicked()
{
    // PEGAR PARAMETROS
    QString autor  = ui->NOME_AUTOR->text();
    QString nome = ui->NOME_LIVRO->text();
    QString trilha = ui->TRILHA->text();
    QString motivo = ui->MOTIVO->text();
    QString indice = ui->INDICE->text();

    // DELETAR LINHA INDICADA
    bool decisao = Datab.delete_line(banco,indice,motivo);

    // CHAMAR CAIXA DE NOTIFICACAO
    QMessageBox caixa;
    if (decisao == true){
        caixa.setText("Você retirou um livro do sistema");
    }
    else{
        caixa.setText("Você não retirou um livro com indice valido");
    }
    caixa.exec();

    // DETERMINAR NA TELA INICIAL A TABELA DO BANCO DE DADOS
    QSqlQueryModel *t = Datab.Tabela_Livro_Autor_Trilha(banco,autor,nome,trilha, 1);
    ui->tableView->setModel(t);


}

void Perdeu::on_tableView_clicked(const QModelIndex &index)
{
    //ADICIONAR INDICE DA TABELA

    QModelIndexList selecionados = ui->tableView->selectionModel()->selectedIndexes();
    qDebug() << selecionados;
    QModelIndex item =  selecionados.at(0);
    int row = item.row();
    qDebug() << row;
    int valor_exp = ui->tableView->model()->data(ui->tableView->model()->index(row,0)).toInt();
    qDebug() << valor_exp;

    //CONNECT WITH INDICE LIVROS

    ui->INDICE->setValue(valor_exp);
}
