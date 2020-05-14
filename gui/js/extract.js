var component;
var extract;

function createExtractObject() {
    component = Qt.createComponent("../pages/extract.qml");
    if (component.status == Component.Ready)
        finishCreation();
    else
        component.statusChanged.connect(finishCreation);
}

function finishCreation() {
    if (component.status == Component.Ready) {
        extract = component.createObject(window, { x: 300, y: 400 });
        if (extract == null)
            console.log("Error creating object");
    } else if (component.status == Component.Error)
        console.log("Error loading component:", component.errorString());
}