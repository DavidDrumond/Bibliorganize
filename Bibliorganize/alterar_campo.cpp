#include "alterar_campo.h"
#include "ui_alterar_campo.h"
#include "global.h"
#include <QtSql>
#include <QMessageBox>

Alterar_Campo::Alterar_Campo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Alterar_Campo)
{
    ui->setupUi(this);

    MainWindow *m;
    QObject::connect(ui->pushButton_2, SIGNAL(clicked(bool)), m, SLOT(Demonstrar_dados_emTela()));
    ui->pushButton->click();

}

Alterar_Campo::~Alterar_Campo()
{
    delete ui;
}

void Alterar_Campo::on_pushButton_clicked()
{
    // PEGAR PARAMETROS
    QString autor  = ui->NOME_AUTOR->text();
    QString nome = ui->NOME_LIVRO->text();
    QString trilha = ui->TRILHA->text();



    // DETERMINAR NA TELA INICIAL A TABELA DO BANCO DE DADOS
    QSqlQueryModel *t = Datab.Tabela_Livro_Autor_Trilha(banco,autor,nome,trilha, 1);
    ui->tableView->setModel(t);
}

void Alterar_Campo::on_pushButton_2_clicked()
{
    // PEGAR PARAMETROS
    QString Indice = ui->INDICE->text();
    QString Campo = ui->CAMPO->currentText();
    QString Alterado = ui->VALOR_ALTERADO->text();
    QString autor  = ui->NOME_AUTOR->text();
    QString nome = ui->NOME_LIVRO->text();
    QString trilha = ui->TRILHA->text();


    //MODIFICAR CAMPO
    Datab.modificar_campo(banco,Indice,Campo,Alterado);

    // CHAMAR CAIXA DE NOTIFICACAO
    QMessageBox caixa;
    caixa.setText("Campo modificado com sucesso");
    caixa.exec();

    // DETERMINAR NA TELA INICIAL A TABELA DO BANCO DE DADOS
    QSqlQueryModel *t = Datab.Tabela_Livro_Autor_Trilha(banco,autor,nome,trilha, 1);
    ui->tableView->setModel(t);

}

void Alterar_Campo::on_tableView_clicked(const QModelIndex &index)
{
    //ADICIONAR INDICE DA TABELA

    QModelIndexList selecionados = ui->tableView->selectionModel()->selectedIndexes();
    qDebug() << selecionados;
    QModelIndex item =  selecionados.at(0);
    int row = item.row();
    int colum = item.column();
    qDebug() << "coluna " << colum;
    int valor_exp = ui->tableView->model()->data(ui->tableView->model()->index(row,0)).toInt();
    qDebug() << valor_exp;


    //CONECTAR COM INDICE DOS LEITORES

    if (colum == 0 || colum > 9){
        QMessageBox caixa;
        caixa.warning(this,"CAMPO NÃO PODE SER ALTERADO","Este campo não pode ser alterado !!!" );
        caixa.show();
    }
    colum = colum -1;
    ui->CAMPO->setCurrentIndex(colum);
    ui->INDICE->setValue(valor_exp);
}
