project( CharmMobile )

include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}

    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/Charm

    ${QT_QTDECLARATIVE_INCLUDE}

    qmlapplicationviewer
    qml
)

INCLUDE( UseQt4 )

set(DATA_INSTALL_DIR "share/data/apps/")

QT4_ADD_RESOURCES( Resources_SRC ${CMAKE_SOURCE_DIR}/Charm/CharmResources.qrc )

set(charmmobile_SRCS
    lib/Application.cpp
    lib/Controller.cpp
    qmlapplicationviewer/qmlapplicationviewer.cpp

    main.cpp
)
qt4_automoc(${charmmobile_SRCS})

set(charmmobile_qml_SRCS
    qml/script.js

    qml/ActiveView.qml
    qml/DialogsPage.qml
    qml/EventView.qml
    qml/Main.qml
    qml/MainPage.qml
    qml/HomeView.qml
    qml/SimpleExamplesPage.qml
    qml/SingleTaskView.qml
    qml/TaskSelectorView.qml
    qml/TextButton.qml
)

add_executable(CharmMobile ${charmmobile_SRCS} ${Resources_SRC})
target_link_libraries(CharmMobile
    CharmApplication
    CharmCore

    ${QT_LIBRARIES}
    ${QT_QTDECLARATIVE_LIBRARY}
)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/config-charmmobile.h.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/config-charmmobile.h
)

install(FILES
    ${charmmobile_qml_SRCS}

    DESTINATION ${CMAKE_INSTALL_PREFIX}/${DATA_INSTALL_DIR}/Charm
)
