#include "bullet.h"
#include <QCursor>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPoint>
#include <QTimer>
#include <QWidget>
#include "enemytroops.h"

bullet::bullet(int damage)
{
    Point=QCursor ::pos();
    timer = new QTimer(this);
    this->damage=damage;
}

void bullet::setr(int row)
{
    r=row;
}
void bullet::setc(int col)
{
    c=col;
}
int bullet::getr()
{
    return r;
}
int bullet::getc()
{
    return c;
}
void bullet::set(int m,int h)
{
    r=m;
    c=h;

    QPixmap Bullet(":/Mbullet.png");
    Bullet=Bullet.scaledToHeight(20);
    Bullet=Bullet.scaledToWidth(20);
    setPixmap(Bullet);
    setPos(60 + 50 * c, 50 + 50 * r);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(16);


    float inc_x = (Point.x() - x());
    float inc_y = (Point.y() - y());

    delta_x = inc_x / sqrtf((inc_x * inc_x) + (inc_y * inc_y));
    delta_y = inc_y / sqrtf((inc_x * inc_x) + (inc_y * inc_y));

}
void bullet::move()
{
    attackTroop();
    if (x() < 800 && y() < 800 && y() > 0 && x() > 0) {
      setPos(x() + (delta_x * speed_factor), y() + (delta_y * speed_factor));

    } else {
      scene()->removeItem(this);
      timer->stop();
      this->deleteLater();
    }
}
void bullet::attackTroop()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    foreach (QGraphicsItem *item, colliding_items) {
      if (typeid(*item) == typeid(enemytroops))
      {
        enemytroops *troop = static_cast<enemytroops *>(item);
        troop->get_damage(damage);
      }
    }
}
