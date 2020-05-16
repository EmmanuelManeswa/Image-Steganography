import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Dialogs 1.3
import QtQuick.Layouts 1.14

ApplicationWindow{
    id: extractWindow
    width: 500
    height: 600
    maximumWidth: width
    maximumHeight: height
    minimumWidth: width
    minimumHeight: height
    color: "#252A35"
    visible: true
    title: qsTr("Extract")

    FileDialog{
        id: stegoImageSelector
        title: qsTr("Choose Stego Image")
        folder: shortcuts.home
        nameFilters: ["Image files (*.jpeg *.jpg *.jpe *.png *.tiff *.tif *.webp *.bmp *.exr *.hdr)"]
        sidebarVisible: true
        onAccepted: {
            element1.text = qsTr("Image Chosen: " + stegoImageSelector.fileUrl)
        }
    }

    RowLayout {
        id: rowLayout
        x: 5
        y: 35
        width: 490
        height: 50

        Text {
            id: element
            text: qsTr("Choose Stego Image:")
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
            onClicked: stegoImageSelector.open()
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
        y: 91
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
        y: 127
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
            echoMode: TextInput.PasswordEchoOnEdit
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
        y: 183
        width: 490
        height: 50

        Text {
            id: element3
            text: qsTr("Information Hidden")
            font.pixelSize: 14
            color: "#A1B4BA"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
    }

    RowLayout {
        id: rowLayout4
        x: 5
        y: 225
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
                readOnly: true
                selectByKeyboard: true
                selectByMouse: true
                placeholderText: qsTr("Secret Information Will be Displayed Here...")

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
        id: rowLayout8
        x: 5
        y: 529
        width: 490
        height: 50

        Button {
            id: extractButton
            width: 87
            height: 32
            text: qsTr("Extract Information")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            contentItem: Text{
                text: extractButton.text
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