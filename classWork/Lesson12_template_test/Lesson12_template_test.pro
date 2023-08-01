TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        DoubleOnly.cpp \
        FloatOnly.cpp \
        IntOnly.cpp \
        main.cpp

HEADERS += \
    DoubleOnly.h \
    FloatOnly.h \
    IntOnly.h \
    tTest.h
