QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

CONFIG(release, debug|release):FINALDIR = release
CONFIG(debug, debug|release):FINALDIR = debug

#Pour les dll

INCLUDEPATH += $${PWD}/../../DesignLibrary/DesignPattern $${PWD}/../../DiceRoller/Dice $${PWD}/../../ExpressionLibrary/LibExpression/Core $${PWD}/../../ExpressionLibrary/LibExpression/Operation
INCLUDEPATH += $${PWD}/../../GraphLibrary/GraphLib
INCLUDEPATH += $${PWD}/../Bestiary/ $${PWD}/../MainRpg/

#DEPENDPATH += $$OUT_PWD/../../DiceRoller/Dice $${OUT_PWD}/../../GraphLibrary/GraphLib $${OUT_PWD}/../../ExpressionLibrary/LibExpression $${OUT_PWD}/../../DesignLibrary/DesignPattern

LIBS += -L$$OUT_PWD/../../../DiceRoller/Dice/$$FINALDIR -lDice
LIBS += -L$$OUT_PWD/../../../GraphLibrary/GraphLib/$$FINALDIR -lGraph
LIBS += -L$$OUT_PWD/../../../ExpressionLibrary/LibExpression/$$FINALDIR -lLibExpression
LIBS += -L$$OUT_PWD/../../../DesignLibrary/DesignPattern/$$FINALDIR -lDesignPattern
LIBS += -L$$OUT_PWD/../../Bestiary/$$FINALDIR -lBestiary
LIBS += -L$$OUT_PWD/../../MainRpg/$$FINALDIR -lMainRpg

CONFIG += c++17

QT += core widgets quick xml gui sql
