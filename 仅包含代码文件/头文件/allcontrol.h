#ifndef ALLCONTROL_H
#define ALLCONTROL_H

#include <QObject>
#include "src/control/displayList/displaylist.h"
#include "src/control/playList/controlplaylist.h"
#include "src/control/playList/startplaymusic.h"

class AllControl: QObject
{
    Q_OBJECT
public:
    AllControl(QObject* parent = nullptr);
};

#endif // ALLCONTROL_H
