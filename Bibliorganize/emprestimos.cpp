#include "emprestimos.h"
#include "ui_emprestimos.h"
#include <QtCore>
#include <QDebug>
#include <QtSql>
#include "global.h"
#include <QMessageBox>


Emprestimos::Emprestimos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Emprestimos)
{
    ui->setupUi(this);

    MainWindow *m;
    QObject::connect(ui->pushButton_2, SIGNAL(clicked(bool)), m, SLOT(Demonstrar_dados_emTela()));

    ui->pushButton->click();
    ui->pushButton_3->click();

}

Emprestimos::~Emprestimos()
{
    delete ui;
}





void Emprestimos::on_CALENDAR_clicked(const QDate &date)
{
    QDate Data_emprestimo = ui->CALENDAR->selectedDate();
    QDate Hoje;
    QDate reference(1700,1,1);
    double dias_para_entrega = Hoje.currentDate().daysTo(reference) - Data_emprestimo.daysTo(reference);
    qDebug() << QString::number(dias_para_entrega);
    ui->lcdNumber->display(QString::number(dias_para_entrega));
    ui->lcdNumber->show();

}

void Emprestimos::on_pushButton_clicked()
{
    // PEGAR PARAMETROS
    QString autor  = ui->NOME_AUTOR->text();
    QString nome = ui->NOME_LIVRO->text();
    QString trilha = ui->TRILHA->text();



    // DETERMINAR NA TELA INICIAL A TABELA DO BANCO DE DADOS
    QSqlQueryModel *t = Datab.Tabela_Livro_Autor_Trilha(banco,autor,nome,trilha, 1);
    ui->tableView->setModel(t);
}

void Emprestimos::on_pushButton_2_clicked()
{
    //PEGAR PARAMETROS
    QString autor  = ui->NOME_AUTOR->text();
    QString nome_livro = ui->NOME_LIVRO->text();
    QString trilha = ui->TRILHA->text();
;

    QString Indice = ui->INDICE_LIVRO->text();
    QString Indice_requerente = ui->INDICE_REQUERENTE->text();
    QString data_emprest = ui->CALENDAR->selectedDate().toString();
    QDate hoje;
    QString data_hoje = hoje.currentDate().toString();

    // EMPRESTAR LIVRO
    bool Testado;
    Testado = Datab.emprestimo_livro(banco,emprestar,Indice, Indice_requerente, data_hoje, data_emprest );

    // DETERMINAR NA TELA INICIAL A TABELA DO BANCO DE DADOS
    QSqlQueryModel *t = Datab.Tabela_Livro_Autor_Trilha(banco,autor,nome_livro,trilha, 1);
    ui->tableView->setModel(t);

    //NOTIFICAR EMPRESTIMO
    QMessageBox caixa;
    if (Testado == true){
        caixa.setText("Livro emprestado");
    }
    else{
        caixa.setText("Voce não digitou um indice valido");
     }
    caixa.exec();

}

void Emprestimos::on_pushButton_3_clicked()
{
    // PEGAR PARAMETROS DAS CAIXAS

    QString nome = ui->NOME_REQUERENTE->text();


    // DETERMINAR NA TELA INICIAL A TABELA DO BANCO DE DADOS
    QSqlQueryModel *t = Datab.Tabela_Nome_pessoa(cadastro_pessoas, nome, 1);
    ui->tableView_2->setModel(t);

}



void Emprestimos::on_tableView_clicked(const QModelIndex &index)
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

    ui->INDICE_LIVRO->setValue(valor_exp);

}

void Emprestimos::on_tableView_2_clicked(const QModelIndex &index)
{
    //ADICIONAR INDICE DA TABELA

    QModelIndexList selecionados = ui->tableView_2->selectionModel()->selectedIndexes();
    qDebug() << selecionados;
    QModelIndex item =  selecionados.at(0);
    int row = item.row();
    qDebug() << row;
    int valor_exp = ui->tableView_2->model()->data(ui->tableView->model()->index(row,0)).toInt();
    qDebug() << valor_exp;

    //CONNECT WITH INDICE LIVROS

    ui->INDICE_REQUERENTE->setValue(valor_exp);
}
