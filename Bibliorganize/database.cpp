#include "database.h"
#include <QString>
#include <QVector>
#include <QtSql>
#include <vector>
#include "global.h"
#include <sstream>
#include <QSqlQuery>
#include <QMessageBox>



database::database()
{


}

void database::connect_database(){


    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\\Users\\David\\Desktop\\Biblioteca");
    qDebug() << "OK";

    db.setDatabaseName("C:\\Users\\David\\Desktop\\Biblioteca");
    if (! db.open()){
        qDebug() << db.lastError();
        QMessageBox caixa;
        caixa.setText("BANCO DE DADOS DELETADO OU ALTERADO !!!");
        qDebug() << "not connected to Database";
        db.removeDatabase("QSQLITE");
        exit(EXIT_FAILURE);
    }




}

void database::create_table (int n_colunas, QString tname, QVector <QString>  nomes, QVector <QString>  tipos){
    QSqlQuery qry;
    QString command = "CREATE TABLE IF NOT EXISTS ";
    command = command + tname+ "(";
    for (int i = 0; i < n_colunas; i++){
        if (i < n_colunas-1){
            command = command + nomes[i] + " " + tipos[i] + ",";
        }
        else{
            command = command + nomes[i] + " " + tipos[i] + ");";
        }
    }
    if(!qry.exec(command)){
        qDebug() << command;
        qDebug() << qry.lastError();

    }
}

void database::delete_table(QString tname){
    QSqlQuery qry;
    QString command = "DROP TABLE IF EXISTS "+tname+";";
    if (!qry.exec(command)){
        qDebug() << command;
        qDebug() << qry.lastError();
    }
}

QSqlQueryModel* database::Tabela_leitura_completa(QString tname, QString ordenado){
    QSqlQuery qry;
    QSqlQueryModel * queryModel = new QSqlQueryModel;
    queryModel->setQuery("SELECT * FROM "+ tname + " ORDER BY " + ordenado );
    if(queryModel->lastError().isValid()){
        qDebug() << queryModel->lastError();
    }
    return queryModel;
}

QSqlQueryModel* database::Tabela_Livro_Autor_Trilha(QString tname, QString Autor, QString Nome, QString Trilha, int Check){
    QSqlQueryModel * queryModel = new QSqlQueryModel;
    QString command;
    if (Check == 0){
        command = "SELECT * FROM " + tname +" WHERE Nome_Livro =  '"+Nome+"' AND Nome_autor = '"+Autor+"' AND Trilha = '"+Trilha+"'" ;
    }
    else{
        command = "SELECT * FROM " + tname +" WHERE Nome_Livro LIKE  '%"+Nome+"%' AND Nome_autor LIKE '%"+Autor+"%' AND Trilha LIKE '%"+Trilha+"%'" ;
    }
    queryModel->setQuery(command);
    if(queryModel->lastError().isValid()){
       qDebug() << queryModel->lastError();
    }
    return queryModel;

}

QSqlQueryModel* database::Tabela_Nome_CPF_Telefone(QString tname, QString Nome, QString CPF, QString Telefone){
    QSqlQueryModel * queryModel = new QSqlQueryModel;
    QString command;
    command = "SELECT * FROM " + tname +" WHERE Nome_leitor LIKE  '%"+Nome+"%' AND CPF LIKE '%"+CPF+"%' AND Telefone LIKE '%"+Telefone+"%'" ;

    queryModel->setQuery(command);
    if(queryModel->lastError().isValid()){
       qDebug() << queryModel->lastError();
    }
    return queryModel;

}



QSqlQueryModel* database::Tabela_Nome_Livro_Autor(QString tname, QString Nome_pessoa, QString Nome_livro, QString Autor, int Check){

    QSqlQueryModel * queryModel = new QSqlQueryModel;
    QString command;
    if (Check == 0){
        command = "SELECT * FROM " + tname +" WHERE Nome_Livro =  '"+Nome_livro+"' AND Nome_autor = '"+Autor+"' AND Nome_leitor = '"+Nome_pessoa+"'" ;
    }
    else{
        command = "SELECT * FROM " + tname +" WHERE Nome_Livro LIKE  '%"+Nome_livro+"%' AND Nome_autor LIKE '%"+Autor+"%' AND Nome_leitor LIKE '%"+Nome_pessoa+"%'" ;
    }
    queryModel->setQuery(command);
    if(queryModel->lastError().isValid()){
       qDebug() << queryModel->lastError();
    }
    return queryModel;

}

QSqlQueryModel* database::Tabela_Nome_pessoa(QString tname, QString Nome, int Check){
    QSqlQueryModel * queryModel = new QSqlQueryModel;
    QString command;
    if (Check == 0){
        command = "SELECT * FROM " + tname +" WHERE Nome_leitor =  '"+Nome+"'" ;
    }
    else{
        command = "SELECT * FROM " + tname +" WHERE Nome_leitor LIKE  '%"+Nome+"%'" ;
    }
    queryModel->setQuery(command);
    if(queryModel->lastError().isValid()){
       qDebug() << queryModel->lastError();
    }
    return queryModel;

}


int database:: numero_dados (QString tname){
    QSqlQuery qry;
    int quantidade = 0;
    QString command = "SELECT COUNT(Indice) FROM " + tname;
    if(!qry.exec(command)){
       qDebug() << qry.lastError();
    }
    while(qry.next()){
        quantidade = qry.value(0).toInt();
    }
    return quantidade;

}


void database::insert_line(QString tname, int nvalues, QVector <QString> columns, QVector <QString> values, bool baixa){
    QSqlQuery qry;
    QString c = "SELECT MAX(Indice) FROM " + tname;
    qry.exec(c);
    int maxvalue ;
    while(qry.next()){
      maxvalue = qry.value(0).toInt();
    }
    maxvalue = maxvalue+1;
    QString max = QString::number(maxvalue);
    qry.first();
    QString command = "INSERT INTO " + tname + "(";
    for (int i =0; i < nvalues; i++){
        if (i< nvalues - 1){
            command = command + columns[i] + ",";
        }
        else{
            command = command + columns[i] +")";
        }
    }
    command = command + " VALUES (";
    if (baixa == false){
        command = command +" '"+max+"' "+",";
        for (int i =0; i < (nvalues-1); i++){
            if (i< nvalues - 2){
                command = command + " '"+ values[i] + "' " + ",";
            }
            else{
                command = command + " '" + values[i]+ "' "+ ");";
            }
        }
    }
    else{
        for (int i =0; i < (nvalues); i++){
            if (i< nvalues - 1){
                command = command + " '"+ values[i] + "' " + ",";
            }
            else{
                command = command + " '" + values[i]+ "' "+ ");";
            }
        }
    }
    qDebug() << command;
    if (!qry.exec(command)){
        qDebug() << command;
        qDebug() << qry.lastError();
    }

}

bool database::delete_line(QString tname, QString indice, QString motivo){

   QSqlQuery qry;

    // VERIFICAR SE EXISTE UM CAMPO DE INDICE VALIDO

   QString command = "SELECT * FROM '"+tname+"' WHERE Indice = "+indice;
   qry.exec(command);
   qry.first();
   bool decisao = (qry.value(0).toString() == "") ? false: true;
   if (decisao == false){
       return false;
   }
   else{
           // IMPORTANTE : RETORMAR VALOR DE QUERY PARA O INICIO

           qry.first();

           QVector <QString> valores ;
           for (int i= 0; i< ncolunas; i++){
               valores.push_back(qry.value(i).toString());
           }
           valores.push_back(motivo);
           for (int j=0; j < valores.size(); j++){
               qDebug() << valores[j];
           }

           // INSERIR VALOR NA TABELA DE LIVROS EM BAIXA

           this->insert_line(baixa_b,ncolunasb, colunasb,valores,true);

           // DELETAR DO BANCO DA BIBLIOTECA O LIVRO EM BAIXA

           command = "DELETE FROM " + tname+ " WHERE Indice = '" + indice+"';";
           qry.exec(command);
           return true;
  }

}

void database:: modificar_campo(QString tname, QString indice, QString Campo, QString ValorAlterado){
     QSqlQuery qry;
    QString command = "UPDATE "+tname+" SET "+Campo+" = '"+ValorAlterado+"' WHERE Indice = '"+indice+"'";
    qry.exec(command);
}

bool database:: emprestimo_livro(QString tname, QString tname2, QString indice,QString indice_requerente, QString Data_Emprestimo, QString Data_devolucao){
    QSqlQuery qry;
    QString nome_do_livro, nome_do_autor;
    bool decisao, decisao2, emprestado;


    // EXECUTAR QUERY PARA VERIFICAR SE EXISTE UM LIVRO DISPONÍVEL

    QString command = "SELECT * FROM '"+tname+"' WHERE Indice = "+indice;
    qry.exec(command);
    qDebug() << command;
    while (qry.next()){
        decisao = (qry.value(0).toString() == "") ? false: true;
        nome_do_livro = qry.value(1).toString();
        nome_do_autor = qry.value(2).toString();

        // VERIFICAR SE O LIVRO JA ESTA EMPRESTADO

        emprestado = (qry.value(10).toString() == "EMPRESTADO") ? false: true;
        if (emprestado == false){
            QMessageBox caixa;
            caixa.setText("O livro ja foi emprestado !!!");
            caixa.exec();
            return false;
        }

    }
    if (decisao == false){
        return false;
    }

    // EXECUTAR QUERY PARA VERIFICAR SE UM USUARIO JA ESTA CADASTRADO

    QString nome, telefone, cpf;
    qry.first();
    command = "SELECT * FROM cadastro_pessoas  WHERE Indice = "+indice_requerente;
    qry.exec(command);
    while (qry.next()){
        decisao2 = (qry.value(0).toString() == "") ? false: true;
        nome = qry.value(1).toString();
        cpf =qry.value(10).toString();
        telefone = qry.value(2).toString();
    }
    if (decisao2 == false){
        return false;
    }
    if (decisao == true && decisao2 == true){
        qry.first();

        // ALTERAR CAMPO DA TABELA DE LIVROS SITUACAO PARA EMPRESTADO
        command = "UPDATE " +tname+ " SET situacao = 'EMPRESTADO' WHERE Indice = '"+indice+"'";
        qry.exec(command);
        command = "UPDATE " +tname+ " SET data_emprestimo ='" + Data_Emprestimo+ "' WHERE Indice = '"+indice+"'";
        qry.exec(command);
        command = "UPDATE " +tname+ " SET data_devolucao ='" + Data_devolucao+ "' WHERE Indice = '"+indice+"'";
        qry.exec(command);




        //ADICIONAR VALOR DE EMPRESTADO NA TABELA DE LIVROS EMPRESTADOS

        QVector<QString> valores = {indice,indice_requerente, nome, nome_do_livro, nome_do_autor, telefone, cpf, Data_Emprestimo, Data_devolucao};
        this->insert_line(tname2,ncolunase,colunase,valores,true);
    }
    return true;

}

bool database:: devolucoes(QString tname, QString tname2, QString indice){

    QSqlQuery qry;
    QString command = "SELECT * FROM '"+tname+"' WHERE Indice = "+indice;
    qry.exec(command);
    qry.first();
    bool decisao = (qry.value(0).toString() == "") ? false: true;
    if (decisao == false){
        return false;
    }
    else{
        // ALTERAR CAMPO DA TABELA DE LIVROS SITUACAO PARA LIVRE
        command = "UPDATE " +tname+ " SET situacao = 'LIVRE' WHERE Indice = '"+indice+"'";
        qry.first();
        qry.exec(command);


        // REMOVER LINHA DA TABELA DE EMPRESTIMOS
        command = "DELETE FROM "+tname2+" WHERE Indice = '"+indice+"'";
        qry.exec(command);
    }
    return true;

}


