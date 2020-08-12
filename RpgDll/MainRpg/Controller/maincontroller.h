#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QtCore/qglobal.h>
#include "abstractcontroller.h"
#include "../MainRpg_global.h"
#include "sqldatabase.h"

class MAINRPG_EXPORT MainController : public AbstractController
{
    Q_OBJECT
public:
    MainController();
    ~MainController();
};

#endif // MAINCONTROLLER_H
