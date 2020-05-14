import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Dialogs 1.3

ApplicationWindow{
    id: embedWindow
    width: 300
    height: 400
    visible: true
    title: qsTr("Embed")

    Label{
        text: qsTr("Embed page!!!")
        anchors.centerIn: parent
    }
}