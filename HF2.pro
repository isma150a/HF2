TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    HFForest.cpp \
    HFTree.cpp \
    HFPatch.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    HFForest.h \
    HFTree.h \
    HFPatch.h

