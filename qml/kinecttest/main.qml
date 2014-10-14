import QtQuick 2.0
import KinectCamera 1.0
import QtQuick.Controls 1.1
Rectangle {
    id: rectangle2
    width: 800
    height: 600

KinectCamera{
    id:testcamera
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

