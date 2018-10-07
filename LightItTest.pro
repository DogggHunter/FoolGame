TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    card.cpp \
    player.cpp \
    game.cpp \
    carddeck.cpp

HEADERS += \
    card.h \
    player.h \
    game.h \
    carddeck.h
