#include "deletar_campo.h"
#include "ui_deletar_campo.h"
#include "global.h"
#include "mainwindow.h"
#include <QtSql>
#include <QObject>
#include <QMessageBox>


Deletar_campo::Deletar_campo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Deletar_campo)
{
    ui->setupUi(this);

    MainWindow *m;
    QObject::connect(ui->pushButton, SIGNAL(clicked(bool)), m, SLOT(Demonstrar_dados_emTela()));

     QString lista = ui->NOME_TABELA->currentText();
     QSqlQueryModel *t = Datab.Tabela_leitura_completa(lista, "Indice");
     ui->tableView->setModel(t);
}

Deletar_campo::~Deletar_campo()
{
    delete ui;


}

void Deletar_campo::on_NOME_TABELA_currentTextChanged(const QString &arg1)
{
    QString lista = ui->NOME_TABELA->currentText();
    QSqlQueryModel *t = Datab.Tabela_leitura_completa(lista, "Indice");
    ui->tableView->setModel(t);
}

void Deletar_campo::on_tableView_clicked(const QModelIndex &index)
{
    QModelIndexList selecionados = ui->tableView->selectionModel()->selectedIndexes();
    qDebug() << selecionados;
    QModelIndex item =  selecionados.at(0);
    int row = item.row();
    int valor_exp = ui->tableView->model()->data(ui->tableView->model()->index(row,0)).toInt();

    ui->INDICE->setValue(valor_exp);

}

void Deletar_campo::on_pushButton_clicked()
{
    QString tabela = ui->NOME_TABELA->currentText();
    QString Indice = ui->INDICE->text();
    QString senha = ui->CHAVE->text();

    if (senha == PASSWORD){
        QSqlQuery qry;
        QString command = "SELECT * FROM "+tabela+" WHERE Indice = '"+Indice+"'";
        qry.exec(command);
        qDebug() << command;
        bool vazio;
        while (qry.next()){
           if (qry.value(0).toString() == ""){
               vazio = false;
           }
           else{
               vazio = true;
           }
        }
        qDebug() <<vazio;
        if (vazio == true){
            command = "DELETE FROM "+tabela+" WHERE Indice = '"+Indice+"';";
            qDebug() << command;
            qry.exec(command);
            qDebug() << qry.lastError();
            QMessageBox caixa3;
            caixa3.warning(this,"CAMPO DELETADO", "VOCÊ DELETOU UM CAMPO SELECIONADO");
        }
        else{
            QMessageBox caixa2;
            caixa2.warning(this,"VALOR DE ÍNDICE INVÁLIDO", "VOCÊ DIGITOU UM ÍNDICE INVÁLIDO");
        }
    }
    else{
        QMessageBox caixa;
        caixa.warning(this,"SENHA INCORRETA","VOCÊ DIGITOU UMA SENHA INCORRETA");
    }

    QString lista = ui->NOME_TABELA->currentText();
    QSqlQueryModel *t = Datab.Tabela_leitura_completa(lista, "Indice");
    ui->tableView->setModel(t);


}
