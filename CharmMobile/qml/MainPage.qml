//MainPage.qml
 import QtQuick 1.1
 import com.nokia.meego 1.0

 Page {
     id: listPage
     anchors.margins: rootWindow.pageMargin

     function openFile(file) {
         var component = Qt.createComponent(file)
         if (component.status == Component.Ready)
             pageStack.push(component);
         else
             console.log("Error loading component:", component.errorString());
     }

     ListModel {
         id: pagesModel
         ListElement {
             page: "SimpleExamplesPage.qml"
             title: "Simple examples"
             subtitle: "Buttons, TextField, ToolBar and ViewMenu"
         }
         ListElement {
             page: "DialogsPage.qml"
             title: "Dialogs"
             subtitle: "How to use different dialogs"
         }
     }

     ListView {
         id: listView
         anchors.fill: parent
         model: pagesModel

         delegate:  Item {
             id: listItem
             height: 88
             width: parent.width

             BorderImage {
                 id: background
                 anchors.fill: parent
                 // Fill page borders
                 anchors.leftMargin: -listPage.anchors.leftMargin
                 anchors.rightMargin: -listPage.anchors.rightMargin
                 visible: mouseArea.pressed
                 source: "image://theme/meegotouch-list-background-pressed-center"
             }

             Row {
                 anchors.fill: parent

                 Column {
                     anchors.verticalCenter: parent.verticalCenter

                     Label {
                         id: mainText
                         text: model.title
                         font.weight: Font.Bold
                         font.pixelSize: 26
                     }

                     Label {
                         id: subText
                         text: model.subtitle
                         font.weight: Font.Light
                         font.pixelSize: 22
                         color: "#cc6633"

                         visible: text != ""
                     }
                 }
             }

             Image {
                 source: "image://theme/icon-m-common-drilldown-arrow" + (theme.inverted ? "-inverse" : "")
                 anchors.right: parent.right;
                 anchors.verticalCenter: parent.verticalCenter
             }

             MouseArea {
                 id: mouseArea
                 anchors.fill: background
                 onClicked: {
                     listPage.openFile(page)
                 }
             }
         }
     }
     ScrollDecorator {
         flickableItem: listView
     }
 }