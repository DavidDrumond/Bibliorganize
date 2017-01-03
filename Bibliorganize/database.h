#ifndef DATABASE_H
#define DATABASE_H
#include <QString>
#include <QtSql>
#include <string.h>
#include "mainwindow.h"




class database
{




public:

    QSqlDatabase db;


    database();
    void connect_database();
    void create_table(int n_colunas, QString tname, QVector <QString> nomes, QVector <QString> tipos);
    void delete_table(QString tname);
    QSqlQueryModel* Tabela_leitura_completa(QString tname, QString ordenado);
    QSqlQueryModel* Tabela_Livro_Autor_Trilha(QString tname, QString Autor, QString Nome, QString Trilha, int Check);
    QSqlQueryModel* Tabela_Nome_Livro_Autor(QString tname, QString Nome_pessoa, QString Nome_livro, QString Autor, int Check);
    QSqlQueryModel* Tabela_Nome_pessoa(QString tname, QString Nome, int Check);
    QSqlQueryModel* Tabela_Nome_CPF_Telefone(QString tname, QString Nome, QString CPF, QString Telefone);
    void insert_line(QString tname, int nvalues, QVector <QString> columns, QVector <QString> values,bool baixa);
    int numero_dados (QString tname);
    bool delete_line(QString tname, QString indice, QString motivo);
    void modificar_campo(QString tname, QString indice, QString Campo, QString ValorAlterado);
    bool emprestimo_livro(QString tname, QString tname2, QString indice, QString indice_requerente,  QString Data_Emprestimo, QString Data_devolucao);
    bool devolucoes(QString tname, QString tname2, QString indice);
};

#endif // DATABASE_H
