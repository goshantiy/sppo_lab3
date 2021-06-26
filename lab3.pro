QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    barchart.cpp \
    byfile.cpp \
    bytype.cpp \
    charts.cpp \
    controlstrategy.cpp \
    filebrowsermodel.cpp \
    imodel.cpp \
    main.cpp \
    mainwindow.cpp \
    piechart.cpp \
    stackedbar.cpp

HEADERS += \
    barchart.h \
    byfile.h \
    bytype.h \
    charts.h \
    controlstrategy.h \
    data.h \
    filebrowsermodel.h \
    imodel.h \
    istrategy.h \
    mainwindow.h \
    piechart.h \
    stackedbar.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
