#ifndef ALTERAR_CADASTRO_H
#define ALTERAR_CADASTRO_H

#include <QDialog>

namespace Ui {
class alterar_cadastro;
}

class alterar_cadastro : public QDialog
{
    Q_OBJECT

public:
    explicit alterar_cadastro(QWidget *parent = 0);
    ~alterar_cadastro();

private slots:
    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::alterar_cadastro *ui;
};

#endif // ALTERAR_CADASTRO_H
