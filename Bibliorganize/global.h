#ifndef GLOBAL_H
#define GLOBAL_H

#define PASSWORD "biblioteca_22"

#include <QString>
#include <QVector>
#include <vector>
#include <database.h>
#include "globalv.cpp"

extern int ncolunas;
extern int ncolunasb;
extern int ncolunase;
extern int ncolunasc;
extern QString banco;
extern QString baixa_b;
extern QString cadastro_pessoas;
extern QString emprestar;
extern QVector <QString>  colunas;
extern QVector <QString> tipos;
extern QVector <QString> colunasb;
extern QVector <QString>tiposb;
extern QVector <QString> colunase;
extern QVector <QString> tipose;
extern QVector <QString> colunasc;
extern QVector <QString> tiposc;
extern database Datab;


#endif // GLOBAL_H
