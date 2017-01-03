#-------------------------------------------------
#
# Project created by QtCreator 2016-12-27T02:45:25
#
#-------------------------------------------------

QT       += core gui sql printsupport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = teste
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QTPLUGIN    += QSQLMYSQL

SOURCES += main.cpp\
        mainwindow.cpp \
    database.cpp \
    global.cpp \
    insercao.cpp \
    perdeu.cpp \
    livros_em_baixa.cpp \
    alterar_campo.cpp \
    emprestimos.cpp \
    devolucoes.cpp \
    cadastro.cpp \
    livros_emprestados.cpp \
    most_cadastro.cpp \
    alterar_cadastro.cpp \
    renovacao.cpp \
    salvar_aquivo.cpp \
    deletar_campo.cpp \
    pesquisa_livro.cpp

HEADERS  += mainwindow.h \
    database.h \
    global.h \
    insercao.h \
    perdeu.h \
    livros_em_baixa.h \
    alterar_campo.h \
    emprestimos.h \
    devolucoes.h \
    cadastro.h \
    livros_emprestados.h \
    most_cadastro.h \
    alterar_cadastro.h \
    renovacao.h \
    salvar_aquivo.h \
    deletar_campo.h \
    pesquisa_livro.h

FORMS    += mainwindow.ui \
    insercao.ui \
    perdeu.ui \
    livros_em_baixa.ui \
    alterar_campo.ui \
    emprestimos.ui \
    devolucoes.ui \
    cadastro.ui \
    livros_emprestados.ui \
    most_cadastro.ui \
    alterar_cadastro.ui \
    renovacao.ui \
    salvar_aquivo.ui \
    deletar_campo.ui \
    pesquisa_livro.ui
 

RESOURCES += \
    resource_file.qrc
