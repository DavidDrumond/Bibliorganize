#ifndef SALVAR_AQUIVO_H
#define SALVAR_AQUIVO_H

#include <QDialog>

namespace Ui {
class Salvar_aquivo;
}

class Salvar_aquivo : public QDialog
{
    Q_OBJECT

public:
    explicit Salvar_aquivo(QWidget *parent = 0);
    ~Salvar_aquivo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Salvar_aquivo *ui;
};

#endif // SALVAR_AQUIVO_H
