TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        StartupMenu.cpp \
        StorageIface.cpp \
        main.cpp

HEADERS += \
    StartupMenu.h \
    StorageIface.h
