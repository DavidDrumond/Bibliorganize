#ifndef EMPRESTIMOS_H
#define EMPRESTIMOS_H

#include <QDialog>

namespace Ui {
class Emprestimos;
}

class Emprestimos : public QDialog
{
    Q_OBJECT

public:
    explicit Emprestimos(QWidget *parent = 0);
    ~Emprestimos();

private slots:

    void on_CALENDAR_clicked(const QDate &date);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_tableView_2_clicked(const QModelIndex &index);

private:
    Ui::Emprestimos *ui;
};

#endif // EMPRESTIMOS_H
