#include <QApplication>
#include <QDebug>
#include <QDir>

#include "qmlapplicationviewer.h"
#include "lib/Controller.h"

#include <Core/CharmConstants.h>
#include <Charm/Application.h>
#include <Charm/TaskModelAdapter.h>

#include "config-charmmobile.h"
#include <Charm/ModelConnector.h>
#include <QtDeclarative/QDeclarativeEngine>
#include <QtDeclarative/QDeclarativeContext>
#include <Core/Controller.h>
#include <QDesktopServices>

using namespace Charm::Mobile;

static const int UserId = 1;

static QString charmDataDir() {
    const QByteArray charmHome = qgetenv("CHARM_HOME");
    if ( !charmHome.isEmpty() )
        return QFile::decodeName( charmHome ) + QLatin1String("/data/");
    else
        return QDesktopServices::storageLocation(QDesktopServices::DataLocation) + QLatin1Char('/');
}

static QStringList qmlImportPaths()
{
    QStringList list;
    list << QLatin1String("/usr/lib/qt4/imports/");
    list << QLatin1String(CHARMMOBILE_DATA_DIR);
    list << QLatin1String(CHARMMOBILE_SOURCE_DIR) + QDir::separator() + "CharmMobile/qml/";
    return list;
}

static QString qmlFilePath() {
    QString installedFile = QLatin1String(CHARMMOBILE_DATA_DIR) + QDir::separator() + "Main.qml";
    if (QFile(installedFile).exists())
        return installedFile;

    return QLatin1String(CHARMMOBILE_SOURCE_DIR) + QDir::separator() + "CharmMobile/qml/Main.qml";
}

int main(int argc, char *argv[])
{
    Application app(argc, argv);
/*
    m_configuration->installationId = InstallationId;
    m_configuration->user.setId( UserId );
    m_configuration->localStorageType = CHARM_SQLITE_BACKEND_DESCRIPTOR;
    m_configuration->localStorageDatabase = m_localPath;
    m_configuration->newDatabase = true;
    m_controller = new Controller;
    // ... initialize the backend:
    QVERIFY( m_controller->initializeBackEnd( CHARM_SQLITE_BACKEND_DESCRIPTOR ) );
    QVERIFY( m_controller->connectToBackend() );
    // ... make the data model:
    m_model = new CharmDataModel;
    // ... connect model and controller:
    connectControllerAndModel( m_controller, m_model );
    QVERIFY( m_controller->storage() != 0 );*/
/*
    const QString storageDatabaseDirectory = charmDataDir();
    const QString storageDatabaseFileRelease = "Charm.db";
    const QString storageDatabaseFileDebug = "Charm_debug.db";
    const QString storageDatabaseRelease = storageDatabaseDirectory + storageDatabaseFileRelease;
    const QString storageDatabaseDebug = storageDatabaseDirectory + storageDatabaseFileDebug;


    QString storageDatabase;
#ifdef NDEBUG
    Q_UNUSED( storageDatabaseDebug );
    storageDatabase = storageDatabaseRelease;
#else
    Q_UNUSED( storageDatabaseRelease );
    storageDatabase = storageDatabaseDebug;
#endif

    Configuration& configuration = Configuration::instance();
    configuration.user.setId( UserId );
    configuration.localStorageType = CHARM_SQLITE_BACKEND_DESCRIPTOR;
    configuration.localStorageDatabase = QDir::toNativeSeparators(storageDatabase);
    Controller* controller = new Controller;
    controller->initializeBackEnd(CHARM_SQLITE_BACKEND_DESCRIPTOR);
    bool connected = controller->connectToBackend();

    qDebug() << "Connected:" << connected;

    CharmDataModel* dataModel = new CharmDataModel;
    Task task1( 1000, "Task 1" );
    Task task1_1( 1001, "Task 1-1", task1.id() );
    Task task1_2( 1002, "Task 1-2", task1.id() );
    Task task1_3( 1003, "Task 1-3", task1.id() );
    dataModel->addTask( task1 );
    dataModel->addTask( task1_3 );
    dataModel->addTask( task1_1 );
    dataModel->addTask( task1_2 );

    connectControllerAndModel(controller, dataModel);

    TaskModelAdapter* taskModel = new TaskModelAdapter(dataModel);
    EventModelFilter* eventModel = new EventModelFilter(dataModel);

    qDebug() << taskModel->rowCount() << eventModel->rowCount();
*/

    MobileController controller;

    QmlApplicationViewer viewer;
    Q_FOREACH(const QString& importPath, qmlImportPaths()) {
        qDebug() << "Adding import path:" << importPath;
        viewer.addImportPath(importPath);
    }
    QDeclarativeContext* rootContext = viewer.engine()->rootContext();
    rootContext->setContextProperty("controller", &controller);
    rootContext->setContextProperty("dataModel", app.model().charmDataModel());
    rootContext->setContextProperty("taskModel", app.model().taskModel());
    rootContext->setContextProperty("eventModel", app.model().eventModel());
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(qmlFilePath());
    viewer.showExpanded();

    return app.exec();
}
