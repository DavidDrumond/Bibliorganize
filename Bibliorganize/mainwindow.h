#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

    void Demonstrar_dados_emTela();

private slots:




    void on_pushButton_clicked();

    void on_actionInserir_Livro_triggered();

    void on_actionBaixa_de_livro_triggered();

    void on_actionLivros_em_Baixa_triggered();

    void on_actionAlterar_Campo_triggered();

    void on_actionEmpr_stimo_triggered();

    void on_actionDevolu_es_triggered();

    void on_actionCadastro_pessoa_triggered();

    void on_actionLivros_emprestados_triggered();

    void on_actionLEITORES_triggered();

    void on_actionAlterar_Campo_do_Leitor_triggered();

    void on_actionRenova_o_triggered();

    void on_actionSalvar_Tabela_como_arquivo_triggered();

    void on_actionDeltar_campo_de_tabela_triggered();

    void on_actionPesquisar_Livro_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
