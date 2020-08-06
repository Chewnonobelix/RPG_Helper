TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS = \
GraphLibrary \
DesignLibrary \
ExpressionLibrary \
DiceRoller \
RpgDll \
CoreRpg \


CoreRpg.depends = RpgDll
RpgDll.depends = GraphLibrary DesignLibrary ExpressionLibrary
