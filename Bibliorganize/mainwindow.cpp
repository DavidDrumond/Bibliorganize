#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QStringList>
#include <QVector>
#include <QtSql>
#include "global.h"
#include "insercao.h"
#include "perdeu.h"
#include "livros_em_baixa.h"
#include "livros_emprestados.h"
#include "emprestimos.h"
#include "alterar_campo.h"
#include "devolucoes.h"
#include "cadastro.h"
#include "most_cadastro.h"
#include "alterar_cadastro.h"
#include "renovacao.h"
#include "salvar_aquivo.h"
#include "deletar_campo.h"
#include "pesquisa_livro.h"






MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
    QSqlDatabase::removeDatabase("QSQLITE");
    qDebug() << "OK";
    exit(EXIT_FAILURE);
    */

    Datab.connect_database();
    Datab.delete_table(banco);
    Datab.delete_table(baixa_b);
    Datab.delete_table(emprestar);
    Datab.delete_table(cadastro_pessoas);
    Datab.create_table(ncolunas,banco,colunas,tipos);
    Datab.create_table(ncolunasb,baixa_b,colunasb,tiposb);
    Datab.create_table(ncolunase,emprestar,colunase,tipose);
    Datab.create_table(ncolunasc,cadastro_pessoas,colunasc,tiposc);


    Demonstrar_dados_emTela();

    MainWindow* m;




}



MainWindow::~MainWindow()
{
    Datab.db.close();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    Demonstrar_dados_emTela();



}

void MainWindow::Demonstrar_dados_emTela(){
    // DETERMINAR NA TELA INICIAL A TABELA DO BANCO DE DADOS
    QString ordenado = ui->comboBox->currentText();

    QSqlQueryModel *t = Datab.Tabela_leitura_completa(banco, ordenado);
    ui->tableView->setModel(t);

    int quantidade = Datab.numero_dados(banco);
    ui->lcdNumber->display(quantidade);
    ui->lcdNumber->show();
}



void MainWindow::on_actionInserir_Livro_triggered()
{
    Insercao insert;
    insert.exec();


}

void MainWindow::on_actionBaixa_de_livro_triggered()
{
    Perdeu perd;
    perd.exec();
}

void MainWindow::on_actionLivros_em_Baixa_triggered()
{
   Livros_em_baixa livr;
   livr.exec();
}

void MainWindow::on_actionAlterar_Campo_triggered()
{
    Alterar_Campo ac;
    ac.exec();
}

void MainWindow::on_actionEmpr_stimo_triggered()
{
    Emprestimos empr;
    empr.exec();
}

void MainWindow::on_actionDevolu_es_triggered()
{
    Devolucoes devol;
    devol.exec();
}

void MainWindow::on_actionCadastro_pessoa_triggered()
{
   cadastro cad;
   cad.exec();

}

void MainWindow::on_actionLivros_emprestados_triggered()
{
    livros_emprestados empre;
    empre.exec();
}

void MainWindow::on_actionLEITORES_triggered()
{
    most_cadastro most_cad;
    most_cad.exec();

}

void MainWindow::on_actionAlterar_Campo_do_Leitor_triggered()
{
    alterar_cadastro alter;
    alter.exec();

}

void MainWindow::on_actionRenova_o_triggered()
{
    Renovacao renov;
    renov.exec();
}

void MainWindow::on_actionSalvar_Tabela_como_arquivo_triggered()
{
    Salvar_aquivo sav;
    sav.exec();
}

void MainWindow::on_actionDeltar_campo_de_tabela_triggered()
{
    Deletar_campo del;
    del.exec();
}

void MainWindow::on_actionPesquisar_Livro_triggered()
{
    Pesquisa_livro pesq;
    pesq.exec();
}
