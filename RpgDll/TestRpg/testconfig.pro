QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app


#Pour les dll

INCLUDEPATH += $${PWD}/../../DesignLibrary/DesignPattern $${PWD}/../../DiceRoller/Dice $${PWD}/../../ExpressionLibrary/LibExpression/Core $${PWD}/../../ExpressionLibrary/LibExpression/Operation
INCLUDEPATH += $${PWD}/../../GraphLibrary/GraphLib
INCLUDEPATH += $${PWD}/../Bestiary/

#DEPENDPATH += $$OUT_PWD/../../DiceRoller/Dice $${OUT_PWD}/../../GraphLibrary/GraphLib $${OUT_PWD}/../../ExpressionLibrary/LibExpression $${OUT_PWD}/../../DesignLibrary/DesignPattern

LIBS += -L$$OUT_PWD/../../../DiceRoller/Dice/debug -lDice
LIBS += -L$$OUT_PWD/../../../GraphLibrary/GraphLib/debug -lGraph
LIBS += -L$$OUT_PWD/../../../ExpressionLibrary/LibExpression/debug -lLibExpression
LIBS += -L$$OUT_PWD/../../../DesignLibrary/DesignPattern/debug -lDesignPattern
LIBS += -L$$OUT_PWD/../../Bestiary/debug -lBestiary

CONFIG += c++17

QT += core widgets quick xml gui
