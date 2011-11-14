#include "Models.h"

#include <Charm/ViewHelpers.h>
#include <Core/Event.h>

using namespace Charm::Mobile;

ActiveEventsFilter::ActiveEventsFilter(QObject* parent)
    : QSortFilterProxyModel(parent)
{

}

void ActiveEventsFilter::setSourceModel(QAbstractItemModel* sourceModel)
{
    Q_ASSERT(qobject_cast<EventModelFilter*>(sourceModel));

    QSortFilterProxyModel::setSourceModel(sourceModel);
}

bool ActiveEventsFilter::filterAcceptsRow(int source_row, const QModelIndex& source_parent) const
{
    EventId id =
    if (!DATAMODEL->isEventActive(id))
        return false;

    return QSortFilterProxyModel::filterAcceptsRow(source_row, source_parent);
}
