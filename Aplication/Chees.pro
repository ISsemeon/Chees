QT += quick qml core

CONFIG += c++14

DEFINES += DEBUG_MODE


SOURCES += \
        src/Position.cpp \
        src/BoardController.cpp \
        src/VoidFigure.cpp \
        src/ChessArmy.cpp \
        src/BishopFigure.cpp \
        src/KingFigure.cpp \
        src/KnightFigure.cpp \
        src/PawnFigure.cpp \
        src/Game.cpp \
        main.cpp \
        src/Figure.cpp \
        src/QueenFigure.cpp \
        src/RookFigure.cpp \
        src/UnitBuilder.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH += $$PWD/qml
QML2_IMPORT_PATH += $$PWD/qml

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


HEADERS += \
	include/BishopFigure.h \
	include/BoardController.h \
	include/ChessArmy.h \
	include/Constants.h \
	include/Figure.h \
	include/Game.h \
	include/KingFigure.h \
	include/KnightFigure.h \
	include/PawnFigure.h \
	include/Position.h \
	include/QueenFigure.h \
	include/RookFigure.h \
	include/UnitBuilder.h \
	include/VoidFigure.h




