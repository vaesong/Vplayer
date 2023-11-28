QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

unix {
LIBS += \
    -L/usr/local/ffmpeg/lib \
    -lSDL2 \
    -lavcodec \
    -lavdevice \
    -lavfilter \
    -lavformat \
    -lavutil \
    -lswresample \
    -lswscale \
    -lpostproc

INCLUDEPATH += lib \
    /usr/local/ffmpeg/include
}

SOURCES += \
    src/ctrlbar.cpp \
    src/globalhelper.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/medialist.cpp \
    src/playlist.cpp \
    src/show.cpp \
    src/title.cpp \
    src/videoctl.cpp

HEADERS += \
    src/ctrlbar.h \
    src/globalhelper.h \
    src/mainwindow.h \
    src/medialist.h \
    src/playlist.h \
    src/show.h \
    src/title.h \
    src/videoctl.h

FORMS += \
    src/CtrlBar.ui \
    src/mainwindow.ui \
    src/playlist.ui \
    src/settingwid.ui \
    src/show.ui \
    src/title.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src/mainwindow.qrc
