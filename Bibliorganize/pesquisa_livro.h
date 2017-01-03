#ifndef PESQUISA_LIVRO_H
#define PESQUISA_LIVRO_H

#include <QDialog>

namespace Ui {
class Pesquisa_livro;
}

class Pesquisa_livro : public QDialog
{
    Q_OBJECT

public:
    explicit Pesquisa_livro(QWidget *parent = 0);
    ~Pesquisa_livro();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Pesquisa_livro *ui;
};

#endif // PESQUISA_LIVRO_H
