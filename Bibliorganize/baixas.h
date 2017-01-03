#ifndef BAIXAS_H
#define BAIXAS_H

#include <QDialog>

namespace Ui {
class Baixas;
}

class Baixas : public QDialog
{
    Q_OBJECT

public:
    explicit Baixas(QWidget *parent = 0);
    ~Baixas();

private:
    Ui::Baixas *ui;
};

#endif // BAIXAS_H
