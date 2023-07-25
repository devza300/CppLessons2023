TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        DamageOverTime.cpp \
        DartPoison.cpp \
        Explosion.cpp \
        Fireball.cpp \
        Piercing.cpp \
        Skill.cpp \
        Unit.cpp \
        main.cpp

HEADERS += \
    DamageOverTime.h \
    DartPoison.h \
    Explosion.h \
    Fireball.h \
    Piercing.h \
    Skill.h \
    Unit.h
