import QtQuick 2.14
import QtQuick.Controls 2.14

ApplicationWindow{
    id: window
    visible: true
    width: 500
    height: 500
    title: qsTr("ImSteg")

    menuBar: MenuBar{
        Menu{
            title: qsTr("Tool")
            Action{
                text: qsTr("Embed")
            }
            Action{
                text: qsTr("Extract")
            }
            MenuSeparator{ }
            Action{
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
        Menu{
            title: qsTr("Help")
            Action{
                text: qsTr("Tutorial")
            }
        }
        Menu{
            title: qsTr("About")
            Action{
                text: qsTr("About")
            }
        }
    }

    Label{
        id: welcome_content1
        text: qsTr("Welcome to ImSteg\n\n\n")
        anchors.centerIn: parent
    }

    Label{
        id: welcome_content2
        text: qsTr("Image Steganography Software")
        anchors.centerIn: parent
    }

}