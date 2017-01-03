#ifndef ALTERAR_CAMPO_H
#define ALTERAR_CAMPO_H

#include <QDialog>

namespace Ui {
class Alterar_Campo;
}

class Alterar_Campo : public QDialog
{
    Q_OBJECT

public:
    explicit Alterar_Campo(QWidget *parent = 0);
    ~Alterar_Campo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_clicked(const QModelIndex &index);


private:
    Ui::Alterar_Campo *ui;
};

#endif // ALTERAR_CAMPO_H
