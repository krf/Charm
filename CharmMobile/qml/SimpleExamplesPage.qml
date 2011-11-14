//SimpleExamplesPage.qml
     import QtQuick 1.1
     import Qt.labs.components 1.0
     import com.nokia.meego 1.0

     Page {
         id: buttonsPage
         tools: buttonTools
         anchors.margins: rootWindow.pageMargin

         ToolBarLayout {
             id: buttonTools

             ToolIcon { iconId: "toolbar-back"; onClicked: { myMenu.close(); pageStack.pop(); }  }
             ToolButtonRow {
                 ToolButton {
                     text: "Copy";
                     onClicked: { label.text = textField.text }
                 }
                 ToolButton {
                     text: "Clear";
                     onClicked: { textField.text = ""; label.text = "empty label" }
                 }
             }
             ToolIcon { iconId: "toolbar-view-menu" ; onClicked: myMenu.open(); }
         }

     Flickable {
         id: flickable
         anchors.fill: parent
         flickableDirection: Flickable.VerticalFlick

         Button {
             id: button;
             anchors.topMargin: 32
             anchors.leftMargin: 32
             width: 450
             text: "Copy text from TextField to Label"
             onClicked: { label.text = textField.text }
         }

         TextField {
             id: textField
             placeholderText: "TextField"
             anchors.top: button.bottom
             anchors.left: button.left
             anchors.topMargin: 16
             width: 450
         }

         Label {
             id: label
             anchors.top: textField.bottom
             anchors.left: textField.left
             anchors.topMargin: 16
             text: "empty label"
         }

     }

     ScrollDecorator {
         flickableItem: flickable
     }

     Menu {
         id: myMenu
         visualParent: pageStack

         MenuLayout {
             MenuItem { text: "Move text from TextField to Label"; onClicked: { label.text = textField.text } }
             MenuItem { text: "Clear everything"; onClicked: { textField.text = ""; label.text = "empty label" } }
         }
     }
 }