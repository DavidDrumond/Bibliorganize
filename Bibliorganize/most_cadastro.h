#ifndef MOST_CADASTRO_H
#define MOST_CADASTRO_H

#include <QDialog>

namespace Ui {
class most_cadastro;
}

class most_cadastro : public QDialog
{
    Q_OBJECT

public:
    explicit most_cadastro(QWidget *parent = 0);
    ~most_cadastro();

private slots:
    void on_pushButton_clicked();

private:
    Ui::most_cadastro *ui;
};

#endif // MOST_CADASTRO_H
