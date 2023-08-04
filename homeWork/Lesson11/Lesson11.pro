TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
#CONFIG -= qt

QT += core

SOURCES += \
    ArgsParser.cpp \
    Config/AbstractConfigLoader.cpp \
    Config/CliConfigLoader.cpp \
    Config/FileConfigLoader.cpp \
    Emulator.cpp \
    Tasks/RoboTask.cpp \
    Tasks/RoboTaskMoveTo.cpp \
    Workshop/AbstractMechanism.cpp \
    Workshop/Joint.cpp \
    Workshop/Leverage.cpp \
    Workshop/OilPomp.cpp \
    Workshop/Robot.cpp \
    Workshop/Wheel.cpp \
    main.cpp

DISTFILES += \
    Bender.conf \
    R2D2.conf \
    README.md \
    task.jpg

HEADERS += \
    ArgsParser.h \
    Config/AbstractConfigLoader.h \
    Config/CliConfigLoader.h \
    Config/FileConfigLoader.h \
    Emulator.h \
    Tasks/RoboTask.h \
    Tasks/RoboTaskMoveTo.h \
    Workshop/AbstractMechanism.h \
    Workshop/Joint.h \
    Workshop/Leverage.h \
    Workshop/OilPomp.h \
    Workshop/Robot.h \
    Workshop/Wheel.h
