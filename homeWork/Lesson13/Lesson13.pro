QT += core gui widgets qml

CONFIG += c++20

SOURCES += \
    Logic/NontrivialMathematics.cpp \
    Logic/OperationsVectorString.cpp \
    Logic/RandomPainter.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    Logic/HeavyOperationsVectorTemplate.h \
    Logic/NontrivialMathematics.h \
    Logic/OperationsVectorString.h \
    Logic/RandomPainter.h \
    MainWindow.h

FORMS += \
    MainWindow.ui

DISTFILES += \
    README.md \
    task.jpg
