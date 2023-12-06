import QtQuick 2.15
import QtQuick.Window 2.15




Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Row {
        Column {
            Image { source: "image://standard_images/yellow" }
            Image { source: "image://standard_images/red" }
        }
        Column {
            Image { source: "image://async_images/blue" }
            Image { source: "image://async_images/cyan" }
        }
        Column {
            Image { source: "image://coro_images/green" }
            Image { source: "image://coro_images/magenta" }
        }
    }
}
