#ifndef RENOVACAO_H
#define RENOVACAO_H

#include <QDialog>

namespace Ui {
class Renovacao;
}

class Renovacao : public QDialog
{
    Q_OBJECT

public:
    explicit Renovacao(QWidget *parent = 0);
    ~Renovacao();

private slots:
    void on_pushButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_calendarWidget_clicked(const QDate &date);

private:
    Ui::Renovacao *ui;
};

#endif // RENOVACAO_H
