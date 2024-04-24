#include "enemytroops.h"
#include <QApplication>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QList>
#include <QObject>
#include <QTimer>
#include <QtCore>
#include "cannon.h"
#include "castle.h"
#include "fence.h"
/*enemytroops::enemytroops(QObject *parent): QObject(parent)
{
    timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT (move()));
    timer->start(30);

}*/
enemytroops::enemytroops()
{
    timer = new QTimer(this);
    timer2= new QTimer(this);
   // timer3=new QTimer(this);
    damage=100;
    HP=1000;

}
void enemytroops :: setr(int row)
{
    r=row;
}
void enemytroops :: setc(int col)
{
    c=col;
}
int enemytroops ::getr()
{
    return r;
}
int enemytroops::getc()
{
    return c;
}

void enemytroops::sethp(int Hp)
{
    HP=Hp;
}
int enemytroops::gethp()
{
    return HP;
}
void enemytroops:: set(int m,int h)
{
    r=m;
    c=h;
//    QPixmap Enemytroop(":/result (4) (1).png");
//    Enemytroop=Enemytroop.scaledToHeight(50);
//    Enemytroop=Enemytroop.scaledToWidth(50);
//    setPixmap(Enemytroop);
    setPos(50+50*c,50+50*r);


   connect(timer,SIGNAL(timeout()),this,SLOT (move()));
    timer->start(200);

}

//void enemytroops:: motion()
//{


//        if (myBool ==false)
//         {
//             QPixmap Enemytroop(":/result (4) (1).png");
//             Enemytroop=Enemytroop.scaledToHeight(50);
//             Enemytroop=Enemytroop.scaledToWidth(50);
//             setPixmap(Enemytroop);
//             setPos(50+50*c,50+50*r);
//             //myBool=true;
//         }
//         else
//        {
//             QPixmap Enemytroop2(":/E:/ENG Mohamed/CS2/project/Cs2 sources/enemy troops/download (2).jpeg");
//                         Enemytroop2=Enemytroop2.scaledToHeight(50);
//                         Enemytroop2=Enemytroop2.scaledToWidth(50);
//                         setPixmap(Enemytroop2);
//                         setPos(50+50*c,50+50*r);
//                         myBool=false;
//        }




//}

void enemytroops::set2(int z,int a)
{
    this->z=z;
    this->a=a;
}
void enemytroops ::move()
{


    attackFence();
    attackCannon();
    attackCastle();
    double cx = (50 + z * 50 - x()) / 100.0;
    double cy = (50 + a * 50 - y()) / 100.0;
    if (can_move) {
      setPos(x() + cx, y() + cy);
    }
    if (myBool ==false)
    {
      QPixmap Enemytroop(":/result (4) (1).png");
      Enemytroop=Enemytroop.scaledToHeight(50);
      Enemytroop=Enemytroop.scaledToWidth(50);
      setPixmap(Enemytroop);
      myBool=true;
    }
    else
    {
      QPixmap Enemytroop2(":/E:/ENG Mohamed/CS2/project/Cs2 sources/enemy troops/download (2).jpeg");
      Enemytroop2=Enemytroop2.scaledToHeight(50);
      Enemytroop2=Enemytroop2.scaledToWidth(50);
      setPixmap(Enemytroop2);
      myBool=false;
    }
}

void enemytroops::attackFence()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    foreach (QGraphicsItem *item, colliding_items) {
      if (typeid(*item) == typeid(fence)) {
	can_move = false;
	fence *Fence = static_cast<fence *>(item);
	Fence->damage(damage);
	if (Fence->isDestroyed()) {
	  can_move = true;
	  scene()->removeItem(Fence);
	}
      }
    }
}
void enemytroops::get_damage(int amount)
{
    HP -= amount;
    if (HP <= 0) {
      this->deleteLater();
    }
}
void enemytroops::attackCannon()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    foreach (QGraphicsItem *item, colliding_items) {
      if (typeid(*item) == typeid(cannon)) {
	can_move = false;
	cannon *c = static_cast<cannon *>(item);
	c->get_damage(damage);
	if (c->isDestroyed()) {
	  can_move = true;
	  scene()->removeItem(c);
	}
      }
    }
}
void enemytroops::attackCastle()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    foreach (QGraphicsItem *item, colliding_items)
    {
    if (typeid(*item) == typeid(Castle))
    {
        Castle *c = static_cast<Castle *>(item);
        c->get_damage(damage);
        if (c->isDestroyed())
    {
	  can_move = true;
	  scene()->removeItem(c);
	}
      }
    }
}
bool enemytroops::isDestroyed()
{
    if (HP <= 0)
      return true;
    else
      return false;
}


