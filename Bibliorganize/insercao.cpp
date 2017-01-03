#include "insercao.h"
#include "ui_insercao.h"
#include "global.h"
#include "mainwindow.h"
#include <vector>
#include <cstring>
#include <QMessageBox>
#include <QObject>




Insercao::Insercao(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Insercao)
{
    ui->setupUi(this);

    MainWindow *m;
    QObject::connect(ui->ACEITAR_INSCR, SIGNAL(clicked(bool)), m, SLOT(Demonstrar_dados_emTela()));
}

Insercao::~Insercao()
{
    delete ui;

    // MOSTRE NA TELA INICIAL O VALOR MODIFICADO



}

void Insercao::on_ACEITAR_INSCR_clicked()
{
    //PEGUE OS VALORES DAS CAIXAS

    QString nome_livro = ui->nome_livro_inscr->text();
    QString nome_autor = ui->NOME_AUTOR_INSCR->text();
    QString trilha = ui->TRILHA_INSCR->text();
    QString cdu = ui->CDU_INSCR->text();
    QString colecao = ui->COLECAO_INSCR->text();
    QString Editora = ui->EDITORA_INSCR->text();
    QString Ano = ui->ANO_PUBL_INSCR->text();
    QString Local = ui->LOCAL_EDITORA_INSCR->text();
    QDate data;
    QString Data_entrada = data.currentDate().toString();
    QString n_exemplares = ui->N_EXEMPLARES_INSCR->text();

    // INSIRA A LINHA NO BANCO DE DADOS

    QVector <QString> entrada = { nome_livro, nome_autor, trilha, cdu, Editora, colecao, Local, Ano, n_exemplares,"LIVRE",Data_entrada, "---", "---" } ;
    Datab.insert_line(banco,ncolunas,colunas,entrada,false);







    // MOSTRE A MENSAGEM DE NOTIFICACAO

    QMessageBox caixa;
    caixa.setText("Voce cadastrou um exemplar no sistema");
    caixa.exec();



}





void Insercao::on_ACEITAR_INSCR_released()
{

}
