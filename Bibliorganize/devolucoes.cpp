#include "devolucoes.h"
#include "ui_devolucoes.h"
#include "global.h"
#include <QtSql>
#include <QMessageBox>

Devolucoes::Devolucoes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Devolucoes)
{
    ui->setupUi(this);

    ui->pushButton->click();

    MainWindow *m;
    QObject::connect(ui->pushButton_2, SIGNAL(clicked(bool)), m, SLOT(Demonstrar_dados_emTela()));
}

Devolucoes::~Devolucoes()
{
    delete ui;
}

void Devolucoes::on_pushButton_clicked()
{
    // PEGAR PARAMETROS
    QString autor  = ui->NOME_AUTOR->text();
    QString livro = ui->NOME_LIVRO->text();
    QString nome = ui->NOME->text();
    QString indice = ui->Indice->text();



    // DETERMINAR NA TELA INICIAL A TABELA DO BANCO DE DADOS
    QSqlQueryModel *t = Datab.Tabela_Nome_Livro_Autor(emprestar,nome,livro,autor, 1);
    ui->tableView->setModel(t);


}

void Devolucoes::on_pushButton_2_clicked()
{
    // PEGAR PARAMETROS
    QString autor  = ui->NOME_AUTOR->text();
    QString livro = ui->NOME_LIVRO->text();
    QString nome = ui->NOME->text();
    QString indice = ui->Indice->text();


    //RETIRAR LIVRO DA TABELA DE EMPRESTIMOS
    bool devol = Datab.devolucoes(banco,emprestar,indice);

    QMessageBox caixa;
    if (devol == true){
        caixa.setText("Livro devolvido a biblioteca");
    }
    else{
        caixa.setText("Voce não digitou um indice valido");
    }
    caixa.exec();

    // DETERMINAR NA TELA INICIAL A TABELA DO BANCO DE DADOS
    QSqlQueryModel *t = Datab.Tabela_Nome_Livro_Autor(emprestar,nome,livro,autor, 1);
    ui->tableView->setModel(t);
}

void Devolucoes::on_tableView_clicked(const QModelIndex &index)
{

    QModelIndexList selecionados = ui->tableView->selectionModel()->selectedIndexes();
    qDebug() << selecionados;
    QModelIndex item =  selecionados.at(0);
    int row = item.row();
    qDebug() << row;
    int valor_exp = ui->tableView->model()->data(ui->tableView->model()->index(row,0)).toInt();
    qDebug() << valor_exp;

    //CONNECT WITH INDICE LIVROS


    ui->Indice->setValue(valor_exp);

}


