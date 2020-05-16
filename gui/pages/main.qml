import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Dialogs 1.3
import "../js/embed.js" as EmbedScript
import "../js/extract.js" as ExtractScript

ApplicationWindow{
    id: window
    visible: true
    width: 650
    height: 650
    maximumWidth: width
    maximumHeight: height
    minimumWidth: width
    minimumHeight: height
    color: "#252A35"
    title: qsTr("ImSteg")

    menuBar: MenuBar{
        Menu{
            title: qsTr("Tool")
            Action{
                text: qsTr("Embed")
                onTriggered: EmbedScript.createEmbedObject()
            }
            Action{
                text: qsTr("Extract")
                onTriggered: ExtractScript.createExtractObject()
            }
            MenuSeparator{ }
            Action{
                text: qsTr("Exit")
                onTriggered: Qt.quit()
            }
        }
        Menu{
            title: qsTr("Help")
            Action{
                text: qsTr("Tutorial")
                onTriggered: tutorialDialog.open()
            }
        }
        Menu{
            title: qsTr("About")
            Action{
                text: qsTr("About")
                onTriggered: aboutDialog.open()
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
        color: "#A1B4BA"
        text: qsTr("Welcome to ImSteg\n\n\n")
        font.pixelSize: 14
        anchors.centerIn: parent
    }

    Label{
        id: welcome_content2
        color: "#A1B4BA"
        text: qsTr("Image Steganography Software")
        font.pixelSize: 14
        anchors.centerIn: parent
    }

}