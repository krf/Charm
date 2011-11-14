import QtQuick 1.0

import "script.js" as Script

Item {
    id: homeView

    property int buttonHeight: 40

    Item {
        id: menu

        TextButton {
            text: "Tasks"
            width: screen.width
            height: buttonHeight

            onClicked: {
                Script.loadPage("TaskSelectorView.qml")
            }
        }
    }

    ActiveView {
        anchors.top: menu.bottom
        height: parent.height - menu.height
    }
}