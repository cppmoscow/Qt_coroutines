import QtQuick 2.15
import QtQuick.Window 2.15


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Row {
        Image { source: "image://smiles/0" }
        Image { source: "image://smiles/1" }
        Image { source: "image://smiles/2" }
    }
}
