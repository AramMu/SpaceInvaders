TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        collider.cpp \
        config.cpp \
        entity.cpp \
        gamelosescreen.cpp \
        gamescreen.cpp \
        gamewinscreen.cpp \
        guidescreen.cpp \
        helpers.cpp \
        levelwinscreen.cpp \
        main.cpp \
        mainmenuscreen.cpp \
        target.cpp

HEADERS += \
    collider.h \
    config.h \
    entity.h \
    gamelosescreen.h \
    gamescreen.h \
    gamewinscreen.h \
    guidescreen.h \
    helpers.h \
    levelwinscreen.h \
    mainmenuscreen.h \
    target.h
LIBS += -llibsfml-graphics-d -llibsfml-audio-d -llibsfml-window-d -llibsfml-system-d


