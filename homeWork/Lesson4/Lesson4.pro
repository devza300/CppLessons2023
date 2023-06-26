TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ArgsParser.cpp \
        FileManager.cpp \
        main.cpp

HEADERS += \
    ArgsParser.h \
    FileManager.h

DISTFILES += \
    README.md
