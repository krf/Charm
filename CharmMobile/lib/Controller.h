#ifndef CHARM_MOBILE_CONTROLLER_H
#define CHARM_MOBILE_CONTROLLER_H

#include <QObject>

#include <Core/Task.h>
#include <QVariant>

class CharmDataModel;

namespace Charm {

namespace Mobile {

class MobileController : public QObject
{
    Q_OBJECT

public:
    MobileController(QObject* parent = 0);

    Q_INVOKABLE bool startEvent(int id);

    Q_INVOKABLE QVariant activeEvents() const;

private:
    CharmDataModel* m_model;
};

}
}

#endif // CHARM_MOBILE_CONTROLLER_H
