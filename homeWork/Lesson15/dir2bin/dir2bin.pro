QT -= gui

TEMPLATE = lib
DEFINES += DIR2BIN_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Entry.cpp \
    Tools/Converter.cpp \
    Tools/Iterator.cpp \
    dir2bin.cpp

HEADERS += \
    Entry.h \
    Tools/Converter.h \
    Tools/DataList.h \
    Tools/Iterator.h \
    dir2bin_global.h \
    dir2bin.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
