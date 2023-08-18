QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    MainWindow.h

FORMS += \
    MainWindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../build-Lessons-Desktop_Qt_6_5_1_GCC_64bit-Debug/homeWork/Lesson15/dir2bin/release/ -ldir2bin
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../build-Lessons-Desktop_Qt_6_5_1_GCC_64bit-Debug/homeWork/Lesson15/dir2bin/debug/ -ldir2bin
else:unix: LIBS += -L$$PWD/../../../../build-Lessons-Desktop_Qt_6_5_1_GCC_64bit-Debug/homeWork/Lesson15/dir2bin/ -ldir2bin

INCLUDEPATH += $$PWD/../../../../build-Lessons-Desktop_Qt_6_5_1_GCC_64bit-Debug/homeWork/Lesson15/dir2bin
DEPENDPATH += $$PWD/../../../../build-Lessons-Desktop_Qt_6_5_1_GCC_64bit-Debug/homeWork/Lesson15/dir2bin
