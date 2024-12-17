TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Correc_Prof/game.cpp \
    Correc_Prof/gridmanagement.cpp \
    Correc_Prof/params.cpp \
    main.cpp

DISTFILES += \
    Nos_fichiers/config.yaml

HEADERS += \
    Correc_Prof/game.h \
    Correc_Prof/gridmanagement.h \
    Correc_Prof/params.h \
    Correc_Prof/type.h
