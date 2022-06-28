#ifndef TODOMODEL_H
#define TODOMODEL_H

#include <QObject>
#include <QAbstractListModel>


class TodoItem
{
private:
    QString pContent ;
    bool pIsDone ;
public:
     explicit TodoItem(const QString &content, const bool &isDone )
     {
         pContent = content;
         pIsDone = isDone;
     };

    // get content
    QString content () const
    {
        return pContent ;
    }

    //get check box result:
    bool isDone() const
    {
        return pIsDone ;
    }

    //set content
    bool setContent(const QString &content){
        if(pContent == content){
            return false;
        }

        pContent = content;
        return true;
    }

    //set check box status :
    bool setIsDone(const bool &isDone){
        pIsDone = isDone;
        return true;
    }

};

class TodoModel : public QAbstractListModel
{
    Q_OBJECT
private:
    QList<TodoItem>pTodoList;
public:
    TodoModel(QObject *parent = nullptr): QAbstractListModel(parent){}

    //
    enum TodoItemRoles
    {
        ContentRole  ,
        IsDoneRole
    };

    //
    QHash<int, QByteArray> roleNames() const override{
        QHash<int, QByteArray> roles;
        roles[ContentRole] = "noidung";
        roles[IsDoneRole] = "trangthai";

        return roles;
    }

    // Row count func :
    int rowCount(const QModelIndex &parent = QModelIndex()) const override{
        return pTodoList.length();
    }

    // Lấy data từ 1 item
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override{

        if(!index.isValid()){
            return QVariant();
        }
        const TodoItem &item = pTodoList[index.row()];
        switch (role) {
            case ContentRole:
                return item.content();
            case IsDoneRole:
                return item.isDone();
            default:

                return QVariant();
        }
    }

    //Set data cho item :
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override{

        if(!index.isValid()){
            return false;
        }

        TodoItem &item = pTodoList[index.row()];
        switch (role) {
        case ContentRole:
            return item.setContent(value.toString());
        case IsDoneRole:
            return item.setIsDone(value.toBool());
        default:
            return false;
        }
    }

    Q_INVOKABLE void updateData(const int &index , int role ){

         TodoItem &item = pTodoList[index];

         QModelIndex modelIndex = this->index(index);


         if(role == 1)
         {
              item.setContent("abc");
              emit dataChanged(this->index(index), this->index(index));
         }

    }

    Q_INVOKABLE void addItem(){
        beginInsertRows(QModelIndex(), rowCount() ,  rowCount());
        pTodoList.append(TodoItem("",false));
        endInsertRows();
    }

    Q_INVOKABLE void addInsert(const int &index){
        beginInsertRows(QModelIndex(), index ,  index);
        pTodoList.append(TodoItem("",false));
        endInsertRows();
    }

    Q_INVOKABLE void removeItem(const int &index){
        beginRemoveRows(QModelIndex(),index, index);
        pTodoList.removeAt(index);
        endRemoveRows();
    }



};

#endif // TODOMODEL_H
