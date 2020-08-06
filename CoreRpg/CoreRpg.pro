# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

RESOURCES +=

TRANSLATIONS += \
    CoreRpg_en_150.ts

CONFIG += c++17

QT += core widgets quick xml gui

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += $$PWD/../RpgDll/GameMaster
#DEPENDPATH += $$OUT_PWD/../RpgDll/GameMaster
LIBS += -L$$OUT_PWD/../RpgDll/GameMaster/debug -lGameMaster

INCLUDEPATH += $${PWD}/DesignLibrary/DesignPattern $${PWD}/DiceRoller/Dice $${PWD}/ExpressionLibrary/LibExpression/Core $${PWD}/ExpressionLibrary/LibExpression/Operation
INCLUDEPATH += $${PWD}/GraphLibrary/GraphLib

#DEPENDPATH += $$OUT_PWD/../DiceRoller/Dice $${OUT_PWD}/../GraphLibrary/GraphLib $${OUT_PWD}/../ExpressionLibrary/LibExpression $${OUT_PWD}/../DesignLibrary/DesignPattern

LIBS += -L$$OUT_PWD/../DiceRoller/Dice/debug -lDice
LIBS += -L$$OUT_PWD/../GraphLibrary/GraphLib/debug -lGraph
LIBS += -L$$OUT_PWD/../ExpressionLibrary/LibExpression/debug -lLibExpression
LIBS += -L$$OUT_PWD/../DesignLibrary/DesignPattern/debug -lDesignPattern

