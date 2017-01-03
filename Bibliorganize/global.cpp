#include "global.h"
#include <QString>
#include <database.h>
#include "globalv.cpp"
#include <QVector>


int ncolunas =  14;
int ncolunasb = 15;
int ncolunase = 9;
int ncolunasc = 12 ;
QString banco = "livros";
QString baixa_b = "livros_em_baixa";
QString emprestar = "emprestimos";
QString cadastro_pessoas = "cadastro_pessoas";
QVector <QString> colunas = {"Indice", "Nome_livro", "Nome_autor", "Trilha", "CDU", "Editora", "Colecao","Local","Data_edic","n_exemplar", "situacao","data_entrada", "data_emprestimo", "data_devolucao"};
QVector <QString> tipos = {"INT","TEXT","TEXT", "TEXT", "TEXT", "TEXT","TEXT","TEXT", "TEXT", "INT", "TEXT","TEXT", "TEXT", "TEXT"};
QVector <QString> colunasb = {"Indice", "Nome_livro", "Nome_autor", "Trilha", "CDU", "Editora", "Colecao","Local","Data_edic","n_exemplar", "situacao", "data_emprestimo", "data_saida","data_devolucao", "MOTIVO"};
QVector <QString> tiposb = {"INT","TEXT","TEXT", "TEXT", "TEXT", "TEXT","TEXT","TEXT", "TEXT", "INT", "TEXT","TEXT", "TEXT", "TEXT","TEXT"};
QVector <QString> colunase = {"Indice","Indice_leitor","Nome_leitor", "Nome_livro","Nome_autor", "Telefone","CPF", "Data_Emprestimo", "Data_Devolucao"};
QVector <QString> tipose = {"INT","INT","TEXT","TEXT","TEXT","TEXT","TEXT","TEXT","TEXT"};
QVector <QString> colunasc = {"Indice", "Nome_leitor", "Telefone", "Rua", "Numero","Bairro","Cidade", "Estado", "CEP", "E_mail", "CPF", "RG"};
QVector <QString> tiposc = {"INT","TEXT","TEXT","TEXT","TEXT","TEXT","TEXT","TEXT","TEXT","TEXT","TEXT","TEXT"};

database Datab;


