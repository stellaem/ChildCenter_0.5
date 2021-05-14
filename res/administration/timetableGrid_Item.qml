import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    property string typeName: ""
    property int idClass: 0
    property date time: new Date()
    property int cabinet: 0
    property int specialist: 0
    property int type: 0

    color: "blue"
    border.width: 1
    radius: 10

    MouseArea {
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        anchors.fill: parent
        hoverEnabled : true
        onClicked: (mouse) => {
            if(mouse.button & Qt.RightButton)
            {
                _contextMenu.popup()
            }
            else
            {
                console.log("leftClicked");
            }

        }
    }

    Menu {
        id: _contextMenu
        width: 100
        MenuItem { text: "Cut" }
        MenuItem { text: "Copy" }
        MenuItem { text: "Paste" }
    }
 }

