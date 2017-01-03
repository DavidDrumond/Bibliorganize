#include "pesquisa_livro.h"
#include "ui_pesquisa_livro.h"
#include "global.h"


Pesquisa_livro::Pesquisa_livro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pesquisa_livro)
{
    ui->setupUi(this);
    ui->pushButton->click();
}

Pesquisa_livro::~Pesquisa_livro()
{
    delete ui;
}

void Pesquisa_livro::on_pushButton_clicked()
{
    QString Pesquisa1;
    QString Campo1;

    Pesquisa1 = ui->lineEdit->text();

    Campo1 = ui->comboBox->currentText();

    QSqlQueryModel * queryModel = new QSqlQueryModel;
    QString command;

    command = "SELECT * FROM " + banco +" WHERE "+Campo1+" LIKE  '%"+Pesquisa1+"%';" ;
    queryModel->setQuery(command);
    if(queryModel->lastError().isValid()){
       qDebug() << queryModel->lastError();
    }

    ui->tableView->setModel(queryModel);
}
