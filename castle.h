#ifndef CASTLE_H
#define CASTLE_H

#include<QGraphicsPixmapItem>
class Castle : public QGraphicsPixmapItem
{
public:
    Castle();
    void setr(int row);
    void setc(int col);
    int getr();
    int getc();
    void  set(int m,int h);
    void sethp(int Hp);
    int gethp();
    void get_damage(int amount);
    bool isDestroyed();

  private:
    int r;
    int c;
    int HP;
};

#endif // CASTLE_H
