#ifndef BULLET_H
#define BULLET_H
#include<QTimer>
#include<QCursor>
#include<QPoint>
#include<QGraphicsPixmapItem>
#include <QWidget>
#include <cmath>
class bullet :  public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int damage;
    int r;
    int c;
    float delta_x;
    float delta_y;
    float speed_factor = 4;
    QTimer* timer;
public:
    bullet(int damage);
    QPoint Point;
    void setr(int row);
    void setc(int col);
    int getr();
    int getc();
    void set(int m,int h);
    void attackTroop();
  public slots:
    void move();
};

#endif // BULLET_H
