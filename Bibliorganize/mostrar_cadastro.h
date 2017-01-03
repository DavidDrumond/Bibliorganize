#ifndef MOSTRAR_CADASTRO_H
#define MOSTRAR_CADASTRO_H

#include <QDialog>

namespace Ui {
class mostrar_cadastro;
}

class mostrar_cadastro : public QDialog
{
    Q_OBJECT

public:
    explicit mostrar_cadastro(QWidget *parent = 0);
    ~mostrar_cadastro();

private:
    Ui::mostrar_cadastro *ui;
};

#endif // MOSTRAR_CADASTRO_H
