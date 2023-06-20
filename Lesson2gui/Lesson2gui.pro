QT += core gui
QT += widgets

CONFIG += c++20

SOURCES += \
    MainWindow.cpp \
    Models/RaceModel.cpp \
    main.cpp

HEADERS += \
    MainWindow.h \
    Models/Race.h \
    Models/RaceModel.h

FORMS += \
    MainWindow.ui
