import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "File System Browser"

    ListView {
        anchors.fill: parent
        model: fileSystemModel
        delegate: Item {
            width: ListView.view.width

            Rectangle {
                width: parent.width
                height: 40
                color: index % 2 === 0 ? "lightblue" : "lightcyan"

                Text {
                    anchors.centerIn: parent
                    text: fileSystemModel.getName(index) + " (" + fileSystemModel.getType(index) + ")"
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        if (model.TypeRole === "Directory") {
                            fileSystemModel.setRootPath(fileSystemModel.fileInfo(index).filePath);
                        }
                    }
                    cursorShape: Qt.PointingHandCursor
                }
            }
        }
    }
}
