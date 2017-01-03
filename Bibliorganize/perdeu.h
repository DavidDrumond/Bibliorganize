#ifndef PERDEU_H
#define PERDEU_H

#include <QDialog>

namespace Ui {
class Perdeu;
}

class Perdeu : public QDialog
{
    Q_OBJECT

public:
    explicit Perdeu(QWidget *parent = 0);
    ~Perdeu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::Perdeu *ui;
};

#endif // PERDEU_H
