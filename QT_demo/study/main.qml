import QtQuick 2.9
import QtQuick.Window 2.2

Window{
    visible: true
    title: "helloworld"
    height: 720
    width: 1280
    Rectangle
    {
        id:rect1
        x: 590
        y: 310
        width: 100
        height: 100
        border.color: "black"
        border.width: 5
        visible: true
        color: "red"
        radius: 20
    }
}
