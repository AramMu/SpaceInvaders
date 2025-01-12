TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        collider.cpp \
        config.cpp \
        entity.cpp \
        game.cpp \
        helpers.cpp \
        levelwinscreen.cpp \
        main.cpp \
        mainmenu.cpp \
        target.cpp

HEADERS += \
    collider.h \
    config.h \
    entity.h \
    game.h \
    helpers.h \
    levelwinscreen.h \
    mainmenu.h \
    target.h
LIBS += -llibsfml-graphics-d -llibsfml-audio-d -llibsfml-window-d -llibsfml-system-d


