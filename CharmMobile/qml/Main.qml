import QtQuick 1.1
import com.nokia.meego 1.0

import "./"

import "script.js" as Script

PageStackWindow {
    id: rootWindow
    property int pageMargin: 16

    // ListPage is what we see when the app starts, it links to
    // the component specific pages
    initialPage: MainPage { }

    // These tools are shared by most sub-pages by assigning the
    // id to a page's tools property
    ToolBarLayout {
        id: commonTools
        visible: false
        ToolIcon {
            iconId: "toolbar-back";
            onClicked: { myMenu.close(); pageStack.pop(); }
        }
        ToolIcon {
            iconId: "toolbar-view-menu";
            onClicked: (myMenu.status == DialogStatus.Closed) ? myMenu.open() : myMenu.close()
        }
    }
}

// Rectangle {
//     id: screen
//     width: 250; height: 400;
//
//     property variant currentPage: loader.item;
//
//     function updateScreen() {
//         toolBar_backButton.text = (currentPage && currentPage.canGoBack() ? "Go back" : "-")
//     }
//
//     Rectangle {
//         width: parent.width
//         height: parent.height - toolBar.height
//
//         Loader {
//             id: loader
//             anchors.fill: parent
//             focus: true
//         }
//
//         Connections {
//             target: loader.item
//             onStartTaskRequested: {
//                 var rc = controller.startEvent(taskid)
//                 if (rc) {
//                     Script.loadPage("ActiveView.qml")
//                 } else {
//                     console.warn("Starting event: " + taskid + " failed")
//                 }
//             }
//         }
//     }
//
//     Rectangle {
//         id: toolBar
//
//         anchors.bottom: parent.bottom
//         width: parent.width
//         height: 25
//
//         TextButton {
//             id: toolBar_backButton
//             width:  parent.width/2
//             height: parent.height
//             text: "Go back"
//
//             onClicked: {
//                 console.log("deb")
//                 if (currentPage.canGoBack())
//                     currentPage.goBack()
//                 else if (currentPage.id != homeView)
//                     Script.loadPage("HomeView.qml")
//             }
//         }
//
//         TextButton {
//             x: parent.width/2
//             width:  parent.width/2
//             height: parent.height
//
//             text: "Quit"
//
//             onClicked: {
//                 Qt.quit()
//             }
//         }
//     }
//
//     Component.onCompleted: {
//         Script.loadPage("HomeView.qml", true);
//     }
//
//     function onPageLoaded(qmlFile) {
//         console.log("Page Changed to: " + qmlFile)
//
//         currentPage.stateChanged.connect(updateScreen)
//         updateScreen()
//     }
// }
