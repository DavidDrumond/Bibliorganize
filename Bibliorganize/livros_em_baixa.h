#ifndef LIVROS_EM_BAIXA_H
#define LIVROS_EM_BAIXA_H

#include <QDialog>

namespace Ui {
class Livros_em_baixa;
}

class Livros_em_baixa : public QDialog
{
    Q_OBJECT

public:
    explicit Livros_em_baixa(QWidget *parent = 0);
    ~Livros_em_baixa();

private slots:
    void on_pushButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::Livros_em_baixa *ui;
};

#endif // LIVROS_EM_BAIXA_H
