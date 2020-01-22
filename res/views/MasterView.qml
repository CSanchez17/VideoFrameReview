import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property var imageID: 0

    ListModel{
        id: frameList
    }

    Connections{
        target: modelManager
        onNewFrameAdded:{
            //myModel.append(obj)
            frameList.append({"frameId": frameIndex})
            //console.log("onNewFrameAdded: ", frameIndex)
        }
    }

    Rectangle{
        anchors.top: parent.top
        anchors.topMargin: 0
        Text {
            id: element
            x: 47
            y: 36
            width: 148
            height: 32
            text: qsTr("CV_VERSION ")
            font.pixelSize: 25
        }

        Text {
            id: element1
            x: 47
            y: 87
            width: 148
            height: 32
            text: qsTr("CV_MAJOR_VERSION  ")
            font.pixelSize: 25
        }

        Text {
            id: element2
            x: 47
            y: 149
            width: 148
            height: 32
            text: qsTr("CV_MINOR_VERSION ")
            font.pixelSize: 25
        }

        Text {
            id: element3
            x: 47
            y: 205
            width: 148
            height: 32
            text: qsTr("CV_SUBMINOR_VERSION")
            font.pixelSize: 25
        }

        Text {
            id: cv1
            x: 362
            y: 36
            width: 148
            height: 32
            text: qsTr(cvclass._cv1)
            font.pixelSize: 25
        }

        Text {
            id: cv2
            x: 362
            y: 87
            width: 148
            height: 32
            text: qsTr(cvclass._cv2)
            font.pixelSize: 25
        }

        Text {
            id: cv3
            x: 362
            y: 149
            width: 148
            height: 32
            text: qsTr(cvclass._cv3)
            font.pixelSize: 25
        }

        Text {
            id: cv4
            x: 362
            y: 205
            width: 148
            height: 32
            text: cvclass._cv4
            font.pixelSize: 25
        }
    }


    ListView{
        id: listView
        height: 100
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.bottomMargin: 100

        orientation: ListView.Horizontal

        model: frameList

        delegate: SwipeDelegate {
            id: swipeDelegate
            height: parent.height

            Image {
                width: 100
                height: 100
                fillMode: Image.PreserveAspectFit
                source: "image://MyImageProvider/" + frameId
            }

            // describes the action if swipe on the oposite direction
            onClicked: {
                console.log("modelData._frameIndex: ", frameId)
            }
        }

        add: Transition {
            NumberAnimation{ properties: "x"; from: 100; duration: 500}
        }
    }

}


