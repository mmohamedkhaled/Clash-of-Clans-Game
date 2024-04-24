#include "cannon.h"

cannon::cannon()
{
    HP=10000;

}
void cannon :: setr(int row)
{
    r=row;
}
void cannon :: setc(int col)
{
    c=col;
}
int cannon ::getr()
{
    return r;
}
int cannon::getc()
{
    return c;
}
void cannon:: set(int m,int h)
{
    r=m;
    c=h;

    //    r=x;
    //    c=y;
    QPixmap Cannon(":/result (1).png");
    //setPixmap(castle);
    Cannon=Cannon.scaledToHeight(50);
    Cannon=Cannon.scaledToWidth(50);
    setPixmap(Cannon);
    setPos(50+50*c,50+50*r);
}
void cannon::sethp(int Hp)
{
    HP=Hp;
}
int cannon::gethp()
{
    return HP;
}
void cannon::get_damage(int amount)
{
    HP -= amount;
    if (HP <= 0)
    {
    }
}
bool cannon::isDestroyed()
{
    if (HP <= 0)
      return true;
    else
      return false;
}
