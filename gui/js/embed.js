var component;
var embed;

function createEmbedObject() {
    component = Qt.createComponent("../pages/embed.qml");
    if (component.status == Component.Ready)
        finishCreation();
    else
        component.statusChanged.connect(finishCreation);
}

function finishCreation() {
    if (component.status == Component.Ready) {
        embed = component.createObject(window, { x: 300, y: 400 });
        if (embed == null)
            console.log("Error creating object");
    } else if (component.status == Component.Error)
        console.log("Error loading component:", component.errorString());
}