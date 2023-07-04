TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS = \
    classWork \
    homeWork \

DISTFILES += \
    $$files("lessons-c-plus-plus/*cpp", true) \
    $$files("lessons-c-plus-plus/*.h", true) \
    $$files("lessons-c-plus-plus/*.docx", true)
