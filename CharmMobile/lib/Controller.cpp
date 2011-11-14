#include "Controller.h"

#include <Core/TaskTreeItem.h>
#include <Core/CharmConstants.h>
#include <Charm/ViewHelpers.h>

#include <QtDeclarative/QtDeclarative>

// TODO: Do not hardcode versions
#define QML_REGISTER(Type) qmlRegisterType<Type>("com.kdab.charm.##Type", 1, 5, "##Type")

using namespace Charm::Mobile;

MobileController::MobileController(QObject* parent)
    : QObject(parent)
{
    // TODO: *shrug*. how to register TaskId to QML?
    // QML_REGISTER(TaskId);
}

bool MobileController::startEvent(int id)
{
    qDebug() << Q_FUNC_INFO << (TaskId)id;

    const TaskTreeItem& item = DATAMODEL->taskTreeItem( id );
    if ( CONFIGURATION.eventsInLeafsOnly && item.childCount() > 0 ) {
        qDebug() << "FIXME this should be prevented by disabling the menu items";
        return false;
    }

    if( item.task().isCurrentlyValid() ) {
        DATAMODEL->startEventRequested( item.task() );
    }
    return true;
}

QVariant MobileController::activeEvents() const
{
    return QVariant::fromValue(DATAMODEL->activeEvents());
}

#include "Controller.moc"
