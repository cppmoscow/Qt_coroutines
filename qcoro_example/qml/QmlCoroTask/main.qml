import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QCoro 0
import app.modules 1.0

ApplicationWindow {
    id: page
    width: 320; height: 100
    color: "lightgray"
    visible: true
    title: qsTr("Hello World")

    RandomNumberUploader{ id: uploader }
    Row {
        Button {
            text: "dada"
            onClicked: label.provider = uploader.generate().await()
        }
        Text {
            id: label
            property var provider: uploader.generate().await()
            text: provider.value
        }
    }
}
//ApplicationWindow {
//    width: 640
//    height: 480
//    visible: true
//    title: qsTr("Hello World")
//    RandomNumberUploader { id: store }
//    Rectangle {
//        x: 0
//        y:0
//        width: 640
//        height: 480
//        color: "red"
//    }
//}
