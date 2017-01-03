#include "cadastro.h"
#include "ui_cadastro.h"
#include "global.h"
#include <QtCore>
#include <QtDebug>
#include <QtSql>
#include <QMessageBox>


cadastro::cadastro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastro)
{
    ui->setupUi(this);
}

cadastro::~cadastro()
{
    delete ui;
}

void cadastro::on_pushButton_clicked()
{
    // PEGAR CAMPOS DO FORMULARIO
    QString nome = ui->NOME->text();
    QString telefone = ui->TELEFONE->text();
    QString rua = ui->RUA->text();
    QString numero = ui->NUMERO->text();
    QString bairro  = ui->BAIRRO->text();
    QString cidade = ui->CIDADE->text();
    QString estado = ui->ESTADO->currentText();
    QString cep = ui->CEP->text();
    QString e_mail = ui->E_MAIL->text();
    QString cpf = ui->CPF->text();
    QString rg = ui->RG->text();

    // INSERIR VALORES NA TABELA

    QVector <QString> valores = { nome, telefone, rua, numero, bairro, cidade, estado, cep, e_mail, cpf, rg};
    Datab.insert_line(cadastro_pessoas, ncolunasc, colunasc, valores, false);

    // MOSTRAR MENSAGEM DE NOTIFICACAO

    QMessageBox caixa;
    caixa.setText("Pessoa cadastrada devidamente");
    caixa.exec();


}
