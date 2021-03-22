#include "myitem.h"

MyItem::MyItem()
{
    //random start rotation
    angle = (rand() % 360);
    setRotation(angle);

    //set the speed
	//5px in one time
    speed = 5;

    //random start psoition
    int StartX = 0;
    int StartY = 0;

    if((rand() % 1)){
        StartX = (rand() % 200);
        StartY = (rand() % 200);
    }
    else
    {
        StartX = (rand() % -100);
        StartY = (rand() % -100);
    }

    setPos(mapToParent(StartX,StartY));
}

QRectF MyItem::boundingRect() const
{
    return QRect (0,0,20,20);

}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush Brush(Qt::gray);

    //basic Collison detection

    if (scene()->collidingItems(this).isEmpty()) {
        //no collison
		//nincs ütközés
        Brush.setColor(Qt::green);
    }
    else{
       // collison!!!
        Brush.setColor(Qt::red);

        //set the position
        DoCollison();
    }

    painter->fillRect(rec, Brush);
    painter->drawRect(rec);
}

void MyItem::advance(int phase)
    if (!phase) return;
    //QPointF location = this->pos();
    setPos(mapToParent(0,-(speed)));
}

void MyItem::DoCollison()//ütközés
{
    //set a new position
    //change the angle with a little randomness
    if((rand() % 1)){
        setRotation(rotation() + (180 + (rand() % 10)));
    }
    else
    {
        setRotation(rotation() + (180 + (rand() % -10)));
    }

    //see if the new position is in bounds
    QPointF newPoint = mapToParent(-(boundingRect().width()), -(boundingRect().width()) + 2);

    if(!scene()->sceneRect().contains((newPoint))){
        //move it back in bounds
        newPoint = mapToParent(0,0);
    }else{
        //set the new positions
        setPos(newPoint);
    }

}
