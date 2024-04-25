
#ifndef _MOVING__H
#define _MOVING__H
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "graphics.h"

const int birdWidth=70;
const int birdHeight=60;
const int pipeWidth=118;
const int pipeHeight=748;
const int GAP_WIDTH = 118 ;
const int GAP_HEIGHT = 173;
const int GAP_TOP = 337 ;

struct Mouse {
    int x, y,speed,height;
    bool isJumping,isFreefalling;
    int tiltAngle;
    int dx = 0, dy = 0;
    void move() {
        x += dx;
        y += dy;
    }
    void freeFall()
    {
        dx=0;
        dy=GRAVITY;
        if (y>=510){ y=510;
         isFreefalling=false;}
         else isFreefalling=true;
    }
    void run()
    {
        dx=speed;

    }
    void runback()
    {
        dx=-speed/2;
    }
    void makeAjump()
    {
        if(!isJumping){
        dx=0;
        dy=-height;}
        isJumping=true;
        isFreefalling=false;
        SDL_Delay(5);

    }
    void fallDown()
    {
        dy=18;
    }

};
  bool isCollision (SDL_Rect rect1,SDL_Rect rect2)
{
    return SDL_HasIntersection(&rect1, &rect2);
}

bool isCollisionwithmonster(int x1,int y1,int manwidth,int manheight,int x2,int y2,int monsterwidth,int monsterheight)
{
    SDL_Rect manRect = {x1,y1,manwidth,manheight };
    SDL_Rect monsterRect = { x2,y2,monsterwidth,monsterheight };
    if(isCollision(manRect,monsterRect))
    {
        return true;
    }
    return false;


}



bool gameOver(Mouse man,Mouse frog) {
    if((frog.x+130)>=(man.x))
    {
        return true;
    }
    return false;
}

#endif
