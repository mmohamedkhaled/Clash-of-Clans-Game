#ifndef CANNON_H
#define CANNON_H
#include<QGraphicsPixmapItem>

class cannon : public QGraphicsPixmapItem
{
private:
    int HP;
    int r;
    int c;
public:
    cannon();
    void setr(int row);
    void setc(int col);
    int getr();
    int getc();
    void  set(int m,int h);
    void sethp(int Hp);
    int gethp();
    void get_damage(int amount);
    bool isDestroyed();
};


#endif // CANNON_H
