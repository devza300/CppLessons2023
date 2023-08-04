TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Config/AbstractConfigLoader.cpp \
    Tasks/RoboTask.cpp \
    Tasks/RoboTaskMoveTo.cpp \
    Workshop/AbstractMechanism.cpp \
    main.cpp

DISTFILES += \
    README.md \
    task.jpg

HEADERS += \
    Config/AbstractConfigLoader.h \
    Config/Coordinate.h \
    Tasks/RoboTask.h \
    Tasks/RoboTaskMoveTo.h \
    Workshop/AbstractMechanism.h
