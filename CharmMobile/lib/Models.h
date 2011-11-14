#ifndef CHARM_MOBILE_MODELS_H
#define CHARM_MOBILE_MODELS_H

#include <QSortFilterProxyModel>

namespace Charm {
namespace Mobile {

class ActiveEventsFilter : public QSortFilterProxyModel
{
public:
    explicit ActiveEventsFilter(QObject* parent = 0);

    virtual void setSourceModel(QAbstractItemModel* sourceModel);

protected:
    virtual bool filterAcceptsRow(int source_row, const QModelIndex& source_parent) const;
};

}
}

#endif