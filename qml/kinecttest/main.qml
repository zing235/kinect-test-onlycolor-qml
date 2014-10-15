//import QtQuick 2.0
//import KinectCamera 1.0
//import QtQuick.Controls 1.1
//Rectangle {
//    id: rectangle2
//    width: 800
//    height: 600

//KinectCamera{
//    id:testcamera
//    anchors.rightMargin: 0
//    anchors.bottomMargin: 0
//    anchors.leftMargin: 0
//    anchors.topMargin: 0
//    anchors.fill: parent
//            Timer{
//                id:updateview
//                interval: 1
//                repeat: true
//                running: true
//                onTriggered: {
//                    time.text = Date().toString()
//                    testcamera.updatecamera()
//                     }
//                }
//                Button{
//                    id:closecamera
//                    width: 82
//                    height: 23
//                    text: "关闭kinect"
//                    anchors.left: parent.left
//                    anchors.leftMargin: 0
//                    anchors.top: parent.top
//                    anchors.topMargin: 0
//                    onClicked:testcamera.closecamera()
//               }
//                Text {
//                    id: time
//                    x: 318
//                    height: 20
//                    text: "time"
//                    anchors.right: parent.right
//                    anchors.rightMargin: 0
//                    anchors.top: parent.top
//                    anchors.topMargin: 0
//                    style: Text.Raised
//                    font.pointSize: 15
//               }
//           }
//}




import KinectCamera 1.0
import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
Rectangle {
    id: rectangle1
    width: 800
    height: 600

    ColumnLayout {
        id: columnLayout1
        width: rectangle1.width*2/5
        spacing: 50
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.top: parent.top
        anchors.topMargin: 8

        Rectangle {
            id: rectangle2
            height: rectangle1.height*14/30
            color: "#c92c2c"
            border.color: "#d2c1c1"
            anchors.right: parent.right
            anchors.rightMargin: 8
            anchors.left: parent.left
            anchors.leftMargin: 8
            anchors.top: parent.top
            anchors.topMargin: 8

            Rectangle {
                id: rectangle6
                x: 48
                y: 72
                height: rectangle1.height*12/30
                color: "#ffffff"
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 8
                anchors.right: parent.right
                anchors.rightMargin: 8
                anchors.left: parent.left
                anchors.leftMargin: 8
                KinectCamera{
                    id:testcamera
                    streamsource:"color"
                    anchors.rightMargin: 0
                    anchors.bottomMargin: 0
                    anchors.leftMargin: 0
                    anchors.topMargin: 0
                    anchors.fill: parent
                    Timer{
                        id:updateview
                        interval: 1
                        repeat: true
                        running: true
                        onTriggered: {
                            time.text = Date().toString()
                            testcamera.updatecamera()
                        }
                    }
                    Button{
                        id:closecamera
                        width: 82
                        height: 23
                        text: "关闭kinect"
                        anchors.left: parent.left
                        anchors.leftMargin: 0
                        anchors.top: parent.top
                        anchors.topMargin: 0
                        onClicked:testcamera.closecamera()
                    }
                    Text {
                        id: time
                        x: 318
                        height: 20
                        text: "time"
                        anchors.right: parent.right
                        anchors.rightMargin: 0
                        anchors.top: parent.top
                        anchors.topMargin: 0
                        style: Text.Raised
                        font.pointSize: 15
                    }
                }
            }

            Rectangle {
                id: rectangle4
                height: rectangle1.height/30
                color: "#ffffff"
                radius: 8
                anchors.right: parent.right
                anchors.rightMargin: 40
                anchors.left: parent.left
                anchors.leftMargin: 40
                anchors.top: parent.top
                anchors.topMargin: 8

                Text {
                    id: text1
                    color: "#f30707"
                    anchors.centerIn: parent
                    text: qsTr("camera1")
                    font.pixelSize: 16
                }
        }

        }

        Rectangle {
            id: rectangle3
            y: 362
            height: rectangle1.height*14/30
            color: "#c92c2c"
            anchors.right: parent.right
            anchors.rightMargin: 8
            anchors.left: parent.left
            anchors.leftMargin: 8
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 8
            Rectangle {
                id: rectangle8
                x: 48
                y: 72
                height: rectangle1.height*12/30
                color: "#ffffff"
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 8
                anchors.right: parent.right
                anchors.rightMargin: 8
                anchors.left: parent.left
                anchors.leftMargin: 8
                KinectCamera{
                    id:testcamera2
                    streamsource:"depth"
                    anchors.rightMargin: 0
                    anchors.bottomMargin: 0
                    anchors.leftMargin: 0
                    anchors.topMargin: 0
                    anchors.fill: parent
                    Timer{
                        id:updateview2
                        interval: 1
                        repeat: true
                        running: true
                        onTriggered: {
                            time2.text = Date().toString()
                            testcamera2.updatecamera()
                        }
                    }
                    Button{
                        id:closecamera2
                        width: 82
                        height: 23
                        text: "关闭kinect"
                        anchors.left: parent.left
                        anchors.leftMargin: 0
                        anchors.top: parent.top
                        anchors.topMargin: 0
                        onClicked:testcamera2.closecamera()
                    }
                    Text {
                        id: time2
                        x: 318
                        height: 20
                        text: "time"
                        anchors.right: parent.right
                        anchors.rightMargin: 0
                        anchors.top: parent.top
                        anchors.topMargin: 0
                        style: Text.Raised
                        font.pointSize: 15
                    }
                }
            }
            Rectangle {
                id: rectangle5
                height: rectangle1.height/30
                color: "#ffffff"
                radius: 8
                anchors.right: parent.right
                anchors.rightMargin: 40
                anchors.left: parent.left
                anchors.leftMargin: 40
                anchors.top: parent.top
                anchors.topMargin: 8

                Text {
                    id: text2
                    color: "#f30707"
                    anchors.centerIn: parent
                    text: qsTr("camera2")
                    font.pixelSize: 16
                }
        }
    }

}
}

