import QtQuick

Window {
    width: 900
    height: 900
    visible: true
    title: qsTr("Hello World")

    Item {

        width  : 600
        height : 600

        Rectangle
        {
            id : rect
            height : parent.height /2
            width  : parent.width /2
            color  : "#2E2E2E"

            anchors
            {
                centerIn : parent
            }
        }

    }
}


