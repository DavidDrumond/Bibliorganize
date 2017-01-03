#ifndef INSERCAO_H
#define INSERCAO_H

#include <QDialog>

namespace Ui {
class Insercao;
}

class Insercao : public QDialog
{
    Q_OBJECT

public:
    explicit Insercao(QWidget *parent = 0);
    ~Insercao();

private slots:
    void on_ACEITAR_INSCR_clicked();

    void on_ACEITAR_INSCR_released();

private:
    Ui::Insercao *ui;



};

#endif // INSERCAO_H
