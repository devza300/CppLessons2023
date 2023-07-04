TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ArgsParser.cpp \
        MassiveMode.cpp \
        VectorMode.cpp \
        main.cpp

DISTFILES += \
    README.md \
    task.jpg

HEADERS += \
    ArgsParser.h \
    MassiveMode.h \
    TaskOperationProvider.h \
    VectorMode.h
