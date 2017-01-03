#include "renovacao.h"
#include "ui_renovacao.h"
#include "global.h"
#include "mainwindow.h"
#include <QSql>
#include <QMessageBox>

Renovacao::Renovacao(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Renovacao)
{
    ui->setupUi(this);

    ui->pushButton->click();

    MainWindow *m2;
    QObject::connect(ui->pushButton_2,SIGNAL(clicked(bool)),m2,SLOT(Demonstrar_dados_emTela()));
}

Renovacao::~Renovacao()
{
    delete ui;


}

void Renovacao::on_pushButton_clicked()
{
    // PEGAR PARAMETROS
    QString autor  = ui->NOME_AUTOR->text();
    QString livro = ui->NOME_LIVRO->text();
    QString nome = ui->NOME->text();


    // DETERMINAR NA TELA INICIAL A TABELA DO BANCO DE DADOS
    QSqlQueryModel *t = Datab.Tabela_Nome_Livro_Autor(emprestar,nome,livro,autor, 1);
    ui->tableView->setModel(t);

}

void Renovacao::on_tableView_clicked(const QModelIndex &index)
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

void Renovacao::on_pushButton_2_clicked()
{
    QString indice = ui->INDICE->text();
    QDate Data_emprestimo = ui->calendarWidget->selectedDate();
    QString Data_emprestimo_string = Data_emprestimo.toString();
    Datab.modificar_campo(banco,indice,"data_devolucao", Data_emprestimo_string);
    Datab.modificar_campo(emprestar,indice,"Data_Devolucao",Data_emprestimo_string);

    QMessageBox caixa;
    caixa.setText("O livro foi renovado");
    caixa.exec();

    ui->pushButton->click();
}

void Renovacao::on_calendarWidget_clicked(const QDate &date)
{
    QDate Data_emprestimo = ui->calendarWidget->selectedDate();
    QDate Hoje;
    QDate reference(1700,1,1);
    double dias_para_entrega = Hoje.currentDate().daysTo(reference) - Data_emprestimo.daysTo(reference);
    qDebug() << QString::number(dias_para_entrega);
    ui->lcdNumber->display(QString::number(dias_para_entrega));
    ui->lcdNumber->show();
}
