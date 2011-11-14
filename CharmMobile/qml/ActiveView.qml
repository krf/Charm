import QtQuick 1.0

Item {
    id: activeTaskView

    Component {
        id: taskDelegate

        Item {
            id: task

            property real detailsOpacity : 0

            width: listView.width
            height: 25

            TextButton {
                id: titleButton
                width: parent.width
                text: model.display

                onClicked: {
                    if (model.hasModelChildren) {
                        listView.model.rootIndex = listView.model.modelIndex(index)
                    } else {
                        task.state = 'details'
                    }
                }
            }

            Flickable {
                id: detailsRect
                width: parent.width
                anchors {
                    top: titleButton.bottom
                }
                contentHeight: detailsText.height
                opacity: detailsOpacity

                Text {
                    id: detailsText
                    anchors.top: parent.top
                    text: "ID: " + model.taskid + "\nTask: " + model.name
                    wrapMode: Text.WordWrap
                    width: parent.width
                }

                TextButton {
                    id: startButton
                    anchors.top: detailsText.bottom

                    text: "Start task"

                    onClicked: {
                        taskView.startTaskRequested(model.taskid)
                    }
                }

                TextButton {
                    id: closeButton
                    anchors {
                        right: parent.right;
                        bottom: startButton.bottom
                    }
                    text: "Close"

                    onClicked: task.state = '';
                }
            }

            states: State {
                name: "details"

                PropertyChanges { target: task; detailsOpacity: 1; x: 0 } // Make details visible
                PropertyChanges { target: task; height: 100; }
            }

            transitions: Transition {
                // Make the state changes smooth
                ParallelAnimation {
                    ColorAnimation { property: "color"; duration: 500 }
                    NumberAnimation { duration: 300; properties: "detailsOpacity, x, contentY, height, width" }
                }
            }
        }
    }

    VisualDataModel {
        id: taskDataModel
        model: taskModel
        delegate: taskDelegate
    }

    ListView {
        id: listView
        width: parent.width
        height: parent.height

        highlightFollowsCurrentItem: true

        model: taskDataModel
    }
}
