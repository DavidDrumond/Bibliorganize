#include "salvar_aquivo.h"
#include "ui_salvar_aquivo.h"
#include "global.h"
#include <QFileDialog>
#include <QFile>
#include <fstream>
#include <QMessageBox>
#include <QVector>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>

Salvar_aquivo::Salvar_aquivo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Salvar_aquivo)
{
    ui->setupUi(this);
}

Salvar_aquivo::~Salvar_aquivo()
{
    delete ui;
}

void Salvar_aquivo::on_pushButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save file", "", ".txt");
    QString table_name = ui->comboBox->currentText();
    std::ofstream offile;
    offile.open(filename.toStdString());
    if (!offile.is_open()){
        QMessageBox caixa;
        caixa.warning(this,"ATENÇÃO","Local de arquivo não existe");

    }
    else{

        QSqlQuery qry;
        int ncolunas;
        qry.first();



        QString command = "SELECT * FROM " + table_name;
        qDebug() << command;
        qry.exec(command);
        ncolunas = qry.record().count();


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

        QVector<QString> oneline;
        for(int i= 0; i < vec[0].size(); i++){
            QString linha;
            for(int j= 0; j< ncolunas; j++){
              linha = linha + vec[j][i] + "    ";
            }
            linha = linha+"\n";
            oneline.push_back(linha);
        }

        offile << " TABELA DE DADOS GERADOS   \n";
        offile << tnames.toStdString();
        offile << " ----------------------------------------------------------------------------------------------------------------- \n";
        for(int i=0; i< vec[0].size(); i++){
            offile << oneline[i].toStdString();
        }

        qDebug() << oneline;
        offile.close();
        qDebug() << filename;

    }



}
