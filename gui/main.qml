import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14

ApplicationWindow{
    id: window
    visible: true
    width: 500
    height: 500
    title: "ImSteg"

    Drawer{
        id: drawer
        width: 0.30 * window.width
        height: window.height
        readonly property bool inPotrait: window.width < window.height
        modal: inPotrait
        interactive: inPotrait
        position: inPotrait ? 0 : 1
        visible: !inPotrait

        ColumnLayout{
            spacing: 1

            Rectangle {
                id: drawer_embed_button
                height: 40
                width: drawer.width
                color: embed_button_mouse_area.pressed ? "gray" : "lightgray"
                Column {
                    anchors.centerIn: parent
                    Text {
                        text: "Embed"
                        color: "black"
                        font.pixelSize: 12
                    }
                }
                MouseArea {
                    id: embed_button_mouse_area
                    anchors.fill: parent
                    //onClicked: 
                }
            }

            Rectangle {
                id: drawer_extract_button
                height: 40
                width: drawer.width
                color: extract_button_mouse_area.pressed ? "gray" : "lightgray"
                Column {
                    anchors.centerIn: parent
                    Text {
                        text: "Extract"
                        color: "black"
                        font.pixelSize: 12
                    }
                }
                MouseArea {
                    id: extract_button_mouse_area
                    anchors.fill: parent
                    //onClicked: 
                }
            }
            
            Rectangle {
                id: drawer_tutorial_button
                height: 40
                width: drawer.width
                color: tutorial_button_mouse_area.pressed ? "gray" : "lightgray"
                Column {
                    anchors.centerIn: parent
                    Text {
                        text: "Tutorial"
                        color: "black"
                        font.pixelSize: 12
                    }
                }
                MouseArea {
                    id: tutorial_button_mouse_area
                    anchors.fill: parent
                    //onClicked: 
                }
            }

            Rectangle {
                id: drawer_about_button
                height: 40
                width: drawer.width
                color: about_button_mouse_area.pressed ? "gray" : "lightgray"
                Column {
                    anchors.centerIn: parent
                    Text {
                        text: "About"
                        color: "black"
                        font.pixelSize: 12
                    }
                }
                MouseArea {
                    id: about_button_mouse_area
                    anchors.fill: parent
                    //onClicked: 
                }
            }

            Rectangle {
                id: drawer_exit_button
                height: 40
                width: drawer.width
                color: exit_button_mouse_area.pressed ? "gray" : "lightgray"
                Column {
                    anchors.centerIn: parent
                    Text {
                        text: "Exit"
                        color: "black"
                        font.pixelSize: 12
                    }
                }
                MouseArea {
                    id: exit_button_mouse_area
                    anchors.fill: parent
                    //onClicked: 
                }
            }
        }
    }

    Label{
        id: welcome_content1
        text: "Welcome to ImSteg\n\n\n"
        anchors.centerIn: parent
    }

    Label{
        id: welcome_content2
        text: "Image Steganography Software"
        anchors.centerIn: parent
    }

}