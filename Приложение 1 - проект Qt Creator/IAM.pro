CONFIG += static
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IAM
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

FORMS += \
    about.ui \
    guestsinfo.ui \
    mainwindow.ui \
    techused.ui

HEADERS += \
    about.h \
    guestsinfo.h \
    mainwindow.h \
    techused.h

SOURCES += \
    about.cpp \
    databaseutils.cpp \
    guestsdbutils.cpp \
    guestsinfo.cpp \
    main.cpp \
    mainwindow.cpp \
    techused.cpp

RESOURCES += \
    resources.qrc

LIBS += -L$$PWD/qpsql_driver

ICON= /Imagine/imagine/icon.ico
