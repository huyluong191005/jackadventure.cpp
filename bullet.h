#ifndef _BULLET__H
#define _BULLET_H
struct Bullet{
    int x;
    int y;
    int dx;
    int dy;
    void move()
    {
        x+=dx;
        y+=dy;
    }
};
#endif // _BULLET__H
