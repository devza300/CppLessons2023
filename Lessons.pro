TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS = \
    classWork \
    homeWork \

DISTFILES += \
    $$files("lessons-c-plus-plus/*", true)
