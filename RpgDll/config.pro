#Pour les dll

CONFIG(release, debug|release):FINALDIR = release
CONFIG(debug, debug|release):FINALDIR = debug

INCLUDEPATH += $${PWD}/../DesignLibrary/DesignPattern $${PWD}/../DiceRoller/Dice $${PWD}/../ExpressionLibrary/LibExpression/Core $${PWD}/../../ExpressionLibrary/LibExpression/Operation
INCLUDEPATH += $${PWD}/../GraphLibrary/GraphLib

#DEPENDPATH += $$OUT_PWD/../../DiceRoller/Dice $${OUT_PWD}/../../GraphLibrary/GraphLib $${OUT_PWD}/../../ExpressionLibrary/LibExpression $${OUT_PWD}/../../DesignLibrary/DesignPattern

LIBS += -L$$OUT_PWD/../../DiceRoller/Dice/$$FINALDIR -lDice
LIBS += -L$$OUT_PWD/../../GraphLibrary/GraphLib/$$FINALDIR -lGraph
LIBS += -L$$OUT_PWD/../../ExpressionLibrary/LibExpression/$$FINALDIR -lLibExpression
LIBS += -L$$OUT_PWD/../../DesignLibrary/DesignPattern/$$FINALDIR -lDesignPattern

CONFIG += c++17

QT += core widgets quick xml gui network
