#-------------------------------------------------
#
# Project created by QtCreator 2015-01-16T03:45:33
#
#-------------------------------------------------

QT       += core gui webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = touhoufm-chat
TEMPLATE = app


SOURCES += main.cpp\
        chatwidget.cpp \
    authorizechat.cpp

HEADERS  += chatwidget.h \
    authorizechat.h

FORMS    += chatwidget.ui \
    authorizechat.ui
