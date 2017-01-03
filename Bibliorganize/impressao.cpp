#include "impressao.h"
#include "ui_impressao.h"
#include "global.h"
#include <QSqlQuery>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QPrintPreviewDialog>
#include <QPixmap>

Impressao::Impressao(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Impressao)
{
    ui->setupUi(this);

    QString texto = ui->comboBox->currentText();
    QSqlQueryModel *t = Datab.Tabela_leitura_completa(texto, "Indice");
    ui->tableView->setModel(t);


}

Impressao::~Impressao()
{
    delete ui;
}

void Impressao::on_pushButton_clicked()
{

        QSqlQuery qry;
        QString table_name = ui->comboBox->currentText();


        // PROCURE O NUMERO DE COLUNAS DA TABELA SQL

        QString command = "SELECT * FROM " + table_name;
        qDebug() << command;
        qry.exec(command);
        ncolunas = qry.record().count();


        // GRAVE A TABELA SQL NA MEMÓRIA COM UM VETOR DE VETORES

        QVector <QVector <QString>> vec;
        QString tnames;
        for (int i=0;i < ncolunas; i++){
            qry.first();
            qry.exec(command);
            QString linha;
            QVector<QString> vec_coluna;
            tnames = tnames + qry.record().fieldName(i) + "   " ;
            while (qry.next()){
                linha = qry.value(i).toString();
                vec_coluna.push_back(linha);
            }
            vec.push_back(vec_coluna);
        }
        tnames = tnames + " \n";


        // TRANSFORME O ARQUIVO EM UMA UNICA STRING

        QString linha;
        for(int i= 0; i < vec[0].size(); i++){
            for(int j= 0; j< ncolunas; j++){
              linha = linha + vec[j][i] + "    ";
            }
            linha = linha+" \n ";
        }

        // ADICIONE O TITULO A STRING

        linha =  " TABELA DE DADOS GERADOS   \n " +linha;


        QPainter paint;
        paint.begin()

        /*
        QPrintPreviewDialog preview(printer, this);
        preview.setWindowFlags ( Qt::Window );
        QObject::connect(&preview, SIGNAL(paintRequested(QPrinter *)), SLOT(printPreview(QPrinter *)));
        preview.exec();
        */

}


void Impressao::on_comboBox_currentTextChanged(const QString &arg1)
{
    QString texto = ui->comboBox->currentText();
    QSqlQueryModel *t = Datab.Tabela_leitura_completa(texto, "Indice");
    ui->tableView->setModel(t);
}
