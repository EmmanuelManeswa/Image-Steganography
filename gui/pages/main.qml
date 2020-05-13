import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Dialogs 1.3

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
                onTriggered: {
                    tutorialDialog.open()
                }
            }
        }
        Menu{
            title: qsTr("About")
            Action{
                text: qsTr("About")
                onTriggered: {
                    aboutDialog.open()
                }
            }
        }
    }

    //  Tutorial message box
    MessageDialog{
        id: tutorialDialog
        title: qsTr("Tutorial")
        icon: StandardIcon.Question
        text: qsTr("Tutorial info will be here!")
        Component.onCompleted: visible = false
    }

    //  About message box
    MessageDialog{
        id: aboutDialog
        title: qsTr("About")
        icon: StandardIcon.Information
        text: qsTr("Emmanuel Maneswa - 154409\nSoftware Engineering\nemmanuelmaneswa@gmail.com\nGraduation Project: Image Steganography\nEuropean Univerity of Lefke")
        Component.onCompleted: visible = false
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