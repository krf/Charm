#ifndef VIEWFILTER_H
#define VIEWFILTER_H

#include <QSortFilterProxyModel>

#include "TaskModelAdapter.h"
#include "Core/TaskModelInterface.h"
#include "Core/Commands/CommandEmitterInterface.h"

class CharmDataModel;
class CharmCommand;

// ViewFilter is implemented as a decorator to avoid accidental direct
// access to the task model with indexes of the proxy
class ViewFilter : public QSortFilterProxyModel,
                   public TaskModelInterface,
                   public CommandEmitterInterface
{
    Q_OBJECT
public:
    ViewFilter( CharmDataModel*, QObject* parent = 0 );
    virtual ~ViewFilter();

    // implement TaskModelInterface
    Task taskForIndex( const QModelIndex& ) const;
    QModelIndex indexForTaskId( TaskId ) const;
    bool taskIsActive( const Task& task ) const;
    bool taskHasChildren( const Task& task ) const;

    // filter for subscriptions:
    void setSubscribedTasksOnlyMode( bool onoff );

    bool taskIdExists( TaskId taskId ) const;
    void commitCommand( CharmCommand* );

signals:
    void eventActivationNotice( EventId id );
    void eventDeactivationNotice( EventId id );

protected:
    bool filterAcceptsRow( int row, const QModelIndex& parent ) const;

private:
    TaskModelAdapter m_model;
    bool m_subscribedTasksOnly;
};

#endif