INCLUDEPATH += $${PWD}/DesignLibrary/DesignPattern $${PWD}/DiceRoller/Dice $${PWD}/ExpressionLibrary/LibExpression/Core $${PWD}/ExpressionLibrary/LibExpression/Operation
INCLUDEPATH += $${PWD}/GraphLibrary/GraphLib

DEPENDPATH += $$OUT_PWD/../DiceRoller/Dice $${OUT_PWD}/../GraphLibrary/GraphLib $${OUT_PWD}/../ExpressionLibrary/LibExpression $${OUT_PWD}/../DesignLibrary/DesignPattern

LIBS += -L$$OUT_PWD/../DiceRoller/Dice -lDice
LIBS += -L$$OUT_PWD/../GraphLibrary/GraphLib -lGraph
LIBS += -L$$OUT_PWD/../ExpressionLibrary/LibExpression -lLibExpression
LIBS += -L$$OUT_PWD/../DesignLibrary/DesignPattern -lDesignPattern











INCLUDEPATH += $${PWD}/../DesignLibrary/DesignPattern $${PWD}/../DiceRoller/Dice $${PWD}/../ExpressionLibrary/LibExpression/Core $${PWD}/../ExpressionLibrary/LibExpression/Operation
INCLUDEPATH += $${PWD}/../GraphLibrary/GraphLib

DEPENDPATH += $$OUT_PWD/../../DiceRoller/Dice $${OUT_PWD}/../../GraphLibrary/GraphLib $${OUT_PWD}/../../ExpressionLibrary/LibExpression $${OUT_PWD}/../../DesignLibrary/DesignPattern

LIBS += -L$$OUT_PWD/../../DiceRoller/Dice -lDice
LIBS += -L$$OUT_PWD/../../GraphLibrary/GraphLib -lGraph
LIBS += -L$$OUT_PWD/../../ExpressionLibrary/LibExpression -lLibExpression
LIBS += -L$$OUT_PWD/../../DesignLibrary/DesignPattern -lDesignPattern

CONFIG += c++17

QT += core widgets quick xml gui
