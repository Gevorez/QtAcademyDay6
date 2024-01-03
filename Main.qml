import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import FileSystemModel

ApplicationWindow {
    visible: true
    width: 1280
    height: 720
    title: "File System Browser"
    color: "black"

    FileSystemModel {
        id: fileSystemModel
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 10

        RowLayout {
            spacing: 10
            Button {
                text: "Back to Parent Directory"
                Layout.preferredWidth: 200
                enabled: !fileSystemModel.isRootDirectory
                onClicked: fileSystemModel.setPath(fileSystemModel.currentPath + "/..")
            }
            Label {
                text: "Current Directory: " + fileSystemModel.currentPath
                elide: Text.ElideLeft
                Layout.fillWidth: true
            }
        }

        ListView {
            Layout.fillWidth: true
            Layout.fillHeight: true
            model: fileSystemModel
            delegate: Rectangle {
                width: parent.width
                height: 50
                color: index % 2 == 0 ? "#ffffff" : "#f9f9f9"

                Row {
                    spacing: 10
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 10

                    Text {
                        text: fileName
                        font.bold: isDirectory
                        color: isDirectory ? "#2a82da" : "#333333"
                        font.pixelSize: 16
                    }

                    Text {
                        text: isDirectory ? "[Folder]" : "[File]"
                        color: "#666666"
                        font.pixelSize: 14
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        if (isDirectory) {
                            fileSystemModel.setPath(fileSystemModel.currentPath + "/" + fileName)
                        }
                    }
                }
            }
        }
    }
}
