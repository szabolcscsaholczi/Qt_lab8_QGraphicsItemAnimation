#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

class MyItem : public QGraphicsItem
{
public:
    MyItem();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void advance(int phase);

private:
    qreal angle;
    qreal speed;
    void DoCollison();
};

#endif // MYITEM_H
