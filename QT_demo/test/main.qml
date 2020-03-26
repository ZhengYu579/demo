import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }

    Text {
        text: qsTr("你好")
        anchors.centerIn: parent
    }
    Item{

    }

    Button{
        id:testbutton
        x:100
        y:100
        height:100
        width:400
        text:"测试按钮"
    }
}
