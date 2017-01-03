#ifndef DEVOLUCOES_H
#define DEVOLUCOES_H

#include <QDialog>

namespace Ui {
class Devolucoes;
}

class Devolucoes : public QDialog
{
    Q_OBJECT

public:
    explicit Devolucoes(QWidget *parent = 0);
    ~Devolucoes();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::Devolucoes *ui;
};

#endif // DEVOLUCOES_H
