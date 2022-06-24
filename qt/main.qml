import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")


    // Tạo 4 button
    Button
    {
        id: button1
        x:47
        y:229
        text: "button 1"
        onClicked: move.changeLocation(1)
    }

    Button
    {
        id: button2
        x:163
        y:229
        text: "button 2"
        onClicked: move.changeLocation(2)
    }



    // Tạo 1 rectangle
    Rectangle
    {
        id: rec
        width: 50
        height: 50
        visible: true
        color: "green"
        x: 50
        y: 50

        Connections
        {
            target: move
            onLocationChanged:
            {
                rec.x = loc
            }
        }
    }
}
