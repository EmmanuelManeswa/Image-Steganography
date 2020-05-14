import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Dialogs 1.3

ApplicationWindow{
    id: extractWindow
    width: 300
    height: 400
    visible: true
    title: qsTr("Extract")

    Label{
        text: qsTr("Extract page!!!")
        anchors.centerIn: parent
    }
}