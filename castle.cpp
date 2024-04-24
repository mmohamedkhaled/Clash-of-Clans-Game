#include "castle.h"
#include<QGraphicsPixmapItem>
#include<QPixmap>
#include <QCoreApplication>

Castle::Castle()
{
    HP=100000;
}
void Castle :: setr(int row)
{
    r=row;
}
void Castle :: setc(int col)
{
    c=col;
}
int Castle ::getr()
{
    return r;
}
int Castle::getc()
{
    return c;
}
void Castle:: set(int m,int h)
{
    r=m;
    c=h;

    QPixmap castle(":/result.png");
    castle=castle.scaledToHeight(100);
    castle=castle.scaledToWidth(100);
    setPixmap(castle);
    setPos(30 + 50 * c, 30 + 50 * r);
    //setPixmap(castle);
}
void Castle::sethp(int Hp)
{
    HP=Hp;
}
int Castle::gethp()
{
    return HP;
}
void Castle::get_damage(int amount)
{
    HP -= amount;
    if (HP <= 0)
    {
    }
}

bool Castle::isDestroyed()
{
    if (HP <= 0)
      return true;
    else
      return false;
}
