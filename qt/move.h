#ifndef MOVE_H
#define MOVE_H

#include <QObject>
#include <QString>


class ToaDo
{
  public:
    int x ;
    int y ;
};

//Q_DECLARE_METATYPE(ToaDo);
class Move : public QObject
{
    Q_OBJECT

    public:
        explicit Move(QObject *parent = nullptr);
    signals:
        void locationChanged( int loc);

    public slots:
        void changeLocation(int a);

};

#endif // MOVE_H
