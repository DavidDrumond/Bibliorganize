#ifndef LIVROS_EMPRESTADOS_H
#define LIVROS_EMPRESTADOS_H

#include <QDialog>

namespace Ui {
class livros_emprestados;
}

class livros_emprestados : public QDialog
{
    Q_OBJECT

public:
    explicit livros_emprestados(QWidget *parent = 0);
    ~livros_emprestados();

private slots:
    void on_pushButton_clicked();

private:
    Ui::livros_emprestados *ui;
};

#endif // LIVROS_EMPRESTADOS_H
