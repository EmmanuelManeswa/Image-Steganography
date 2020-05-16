import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Dialogs 1.3
import QtQuick.Layouts 1.14

ApplicationWindow{
    id: embedWindow
    width: 500
    height: 600
    maximumWidth: width
    maximumHeight: height
    minimumWidth: width
    minimumHeight: height
    color: "#252A35"
    visible: true
    title: qsTr("Embed")

    FileDialog{
        id: coverImageSelector
        title: qsTr("Choose Cover Image")
        folder: shortcuts.home
        nameFilters: ["Image files (*.jpeg *.jpg *.jpe *.png *.tiff *.tif *.webp *.bmp *.exr *.hdr)"]
        sidebarVisible: true
        onAccepted: {
            element1.text = qsTr("Image Chosen: " + coverImageSelector.fileUrl)
        }
    }

    FileDialog{
        id: stegoSaveLocation
        title: qsTr("Choose Location to Save Stego Image")
        folder: shortcuts.home
        selectFolder: true
        sidebarVisible: true
        selectExisting: false
        onAccepted: {
            element5.text = qsTr("Folder Chosen: " + stegoSaveLocation.fileUrl)
        }
    }

    RowLayout {
        id: rowLayout
        x: 5
        y: 0
        width: 490
        height: 50

        Text {
            id: element
            text: qsTr("Choose Cover Image:")
            font.family: "Times New Roman"
            font.pixelSize: 14
            color: "#A1B4BA"
        }

        Button {
            id: openFileDialog
            x: 248
            y: 10
            width: 87
            height: 32
            text: qsTr("Load Image")
            onClicked: coverImageSelector.open()
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            contentItem: Text{
                text: openFileDialog.text
                color: "#252A35"
            }

            background: Rectangle{
                border.width: 2
                border.color: "#46A29F"
                color: "#46A29F"
                radius: 4
            }
        }
    }

    RowLayout {
        id: rowLayout1
        x: 5
        y: 41
        width: 490
        height: 30

        Text {
            id: element1
            text: qsTr("Image Chosen:")
            font.pixelSize: 11
            color: "#A1B4BA"
        }
    }

    RowLayout {
        id: rowLayout2
        x: 5
        y: 61
        width: 490
        height: 50

        Text {
            id: element2
            text: qsTr("Password:")
            font.pixelSize: 14
            color: "#A1B4BA"
        }

        TextField {
            id: password
            x: 248
            y: 128
            width: 272
            height: 32
            font.pointSize: 10
            color: "#A1B4BA"
            placeholderText: qsTr("Enter Password......")
            echoMode:TextInput.PasswordEchoOnEdit
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            background: Rectangle{
                border.width: 1
                border.color: "#46A29F"
                radius: 4
                color: "#292D3E"
            }
        }
    }

    RowLayout {
        id: rowLayout3
        x: 5
        y: 98
        width: 490
        height: 50

        Text {
            id: element3
            text: qsTr("Information to Hide")
            font.pixelSize: 14
            color: "#A1B4BA"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
    }

    RowLayout {
        id: rowLayout4
        x: 5
        y: 131
        width: 490
        height: 298

        ScrollView {
            id: secretInfoScrollView
            hoverEnabled: true
            Layout.fillHeight: true
            Layout.fillWidth: true
            clip: true
            ScrollBar.horizontal.policy: ScrollBar.AlwaysOn
            ScrollBar.vertical.policy: ScrollBar.AlwaysOn

            TextArea {
                id: secretInfoText
                Layout.fillHeight: true
                Layout.fillWidth: true
                font.pointSize: 10
                color: "#A1B4BA"
                placeholderText: qsTr("Enter Secret Information.....")

                background: Rectangle{
                    border.width: 1
                    border.color: "#46A29F"
                    radius: 4
                    color: "#292D3E"
                }
            }
        }
    }

    RowLayout {
        id: rowLayout5
        x: 5
        y: 428
        width: 490
        height: 50

        Text {
            id: element4
            text: qsTr("Choose Location to Save Image:")
            font.pixelSize: 14
            color: "#A1B4BA"
        }

        Button {
            id: saveLocationButton
            x: 248
            height: 32
            text: qsTr("Choose Location")
            onClicked: stegoSaveLocation.open()
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            contentItem: Text{
                text: saveLocationButton.text
                color: "#252A35"
            }

            background: Rectangle{
                border.width: 2
                border.color: "#46A29F"
                color: "#46A29F"
                radius: 4
            }
        }
    }

    RowLayout {
        id: rowLayout6
        x: 5
        y: 468
        width: 490
        height: 30

        Text {
            id: element5
            text: qsTr("Folder Chosen:")
            font.pixelSize: 11
            color: "#A1B4BA"
        }
    }

    RowLayout {
        id: rowLayout7
        x: 5
        y: 489
        width: 490
        height: 50

        Text {
            id: element6
            text: qsTr("Stego Image Name:")
            font.pixelSize: 14
            color: "#A1B4BA"
        }

        TextField {
            id: textField1
            x: 248
            y: 128
            width: 272
            height: 32
            font.pointSize: 10
            color: "#A1B4BA"
            placeholderText: qsTr("Stego Image Name.....")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            background: Rectangle{
                border.width: 1
                border.color: "#46A29F"
                radius: 4
                color: "#292D3E"
            }
        }
    }

    RowLayout {
        id: rowLayout8
        x: 5
        y: 545
        width: 490
        height: 50

        Button {
            id: embedButton
            width: 87
            height: 32
            text: qsTr("Embed Information")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            contentItem: Text{
                text: embedButton.text
                color: "#252A35"
            }

            background: Rectangle{
                border.width: 2
                border.color: "#46A29F"
                color: "#46A29F"
                radius: 4
            }
        }
    }

}