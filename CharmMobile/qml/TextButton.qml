import QtQuick 1.0

Rectangle {
    id: container

    property alias text: label.text

    signal clicked

    width: parent.width; height: label.height + 6
    smooth: true
    radius: 10

    gradient: Gradient {
        GradientStop { id: gradientStop; position: 0.0; color: palette.light }
        GradientStop { position: 1.0; color: palette.button }
    }

    SystemPalette { id: palette }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: { container.clicked() }
    }

    Text {
        id: label
        width: parent.width - 10
        elide: Text.ElideRight
        horizontalAlignment: Text.AlignHCenter
        anchors.centerIn: parent
    }

    states: State {
        name: "pressed"
        when: mouseArea.pressed
        PropertyChanges { target: gradientStop; color: palette.dark }
    }
}