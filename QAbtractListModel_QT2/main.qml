import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window
{
    width: 800
    height: 480
    visible: true
    title: qsTr("Hello World")

//    ListModel{
//        id: myModel
//        ListElement
//        {
//            content:"abc"
//            isDone: false
//        }

//        ListElement
//        {
//            content:"xyz"
//            isDone: true
//        }

//    }

//    TodoModel
//    {
//        id: myModel
//    }

    ListView{
        id: myTodoList
        anchors.fill: parent
        model: myModel
        header:
            Row{
            Button{
                text: "append/add"
                onClicked: {
//                    myModel.append
//                    (
//                    {
//                        content:"",
//                        isDone: true

//                    }
//                    )
                    myModel.addItem() ;

                }
            }


        }
        spacing: 20

        delegate:
        Row{
            width: parent.width
            anchors.left: parent.left
            anchors.leftMargin: 20
            TextField{
                text: noidung
                width: parent.width -500
                onTextEdited: {
                    noidung = text
                }
            }
            CheckBox{
                checked: trangthai
                onCheckedChanged: {
                    trangthai = checked
                }
            }
            Button{
                text: "Add"
                onClicked:
                {
                    //console.log("huy " + index)
                    myModel.addInsert(index)
                }
            }

            Button {
                text: "modify"
                onClicked: {
                    myModel.updateData(index , 1) ;
                }
            }

            Button{
                text: "Remove"
                onClicked:
                {
                    console.log("huy " + index)
                    myModel.removeItem(index)
                }
            }
        }
    }


}
