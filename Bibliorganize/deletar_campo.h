#ifndef DELETAR_CAMPO_H
#define DELETAR_CAMPO_H

#include <QDialog>

namespace Ui {
class Deletar_campo;
}

class Deletar_campo : public QDialog
{
    Q_OBJECT

public:
    explicit Deletar_campo(QWidget *parent = 0);
    ~Deletar_campo();

private slots:
    void on_NOME_TABELA_currentTextChanged(const QString &arg1);

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::Deletar_campo *ui;
};

#endif // DELETAR_CAMPO_H
