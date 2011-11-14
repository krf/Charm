/*
function loadPage(qmlFile, keepOld) {
    var component = Qt.createComponent(qmlFile);
    if (component.status != Component.Ready) {
        console.log(component.errorString());
    }

    var object = component.createObject(pager,
            {width: pager.width, height: pager.height}
    );

    // cleanup
    var oldPage = screen.currentPage;

    screen.currentPage = object;
    screen.onPageLoaded(qmlFile)

    if (!keepOld && oldPage) {
        console.log("Destroying: " + oldPage);
        oldPage.opacity = 0
//         oldPage.destroy()
    }
}
*/

function loadPage(qmlFile)
{
    console.log("Loading: " + qmlFile);
    loader.source = qmlFile;
    rootWindow.onPageLoaded(qmlFile)
}
