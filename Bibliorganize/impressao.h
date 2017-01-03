#ifndef IMPRESSAO_H
#define IMPRESSAO_H

#include <QDialog>

namespace Ui {
class Impressao;
}

class Impressao : public QDialog
{
    Q_OBJECT

public:
    explicit Impressao(QWidget *parent = 0);
    ~Impressao();


private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);



private:
    Ui::Impressao *ui;
};

#endif // IMPRESSAO_H
