TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CFLAGS += -g

SOURCES += main.cpp \
    product.cpp \
    finder_and_shower.cpp

HEADERS += \
    product.h Array_with_placement_new.h \
    finder_and_shower.h
