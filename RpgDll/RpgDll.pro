TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS += \
    Bestiary \
    GameMaster \
    MainRpg \
    TestRpg

GameMaster.depends = Bestiary
MainRpg.depends = Bestiary GameMaster
TestRpg.depends = Bestiary GameMaster
