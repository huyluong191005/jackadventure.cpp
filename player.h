#ifndef _PLAYER__H
#define _PLAYER_H

#include "moving.h"
void playerCollision(Graphics graphics,Mouse &man,Mouse &bat,Mouse &as1,Mouse &as2,Mouse &as3,Mouse &monster,Mouse &poi,bool &collision2,bool &collision3,int &counttodealth,SDL_Texture* fall1,Mix_Chunk*gDeath,Mix_Chunk*poisonImpact,Sprite &death,Sprite &poisonimpact,bool &over)
{
    if(isCollisionwithmonster(man.x+90,man.y+70,45,70,bat.x+15,bat.y+5,40,30)||isCollisionwithmonster(man.x+90,man.y+70,45,70,as1.x+9,as1.y+5,41,41)||isCollisionwithmonster(man.x+90,man.y+70,45,70,as2.x+9,as2.y+5,41,41)||isCollisionwithmonster(man.x+90,man.y+70,45,70,as3.x+9,as3.y+5,41,41)||isCollisionwithmonster(man.x+90,man.y+60,40,80,monster.x,monster.y+6,105,65))
        {
            collision2=true;
        }
        if(collision2)
        {
            counttodealth++;
            man.y-=4;
            for(int i=1;i<=8;i++)
            {
                if(counttodealth==i){
                graphics.renderTexture(fall1,man.x,man.y);
                man.y+=(510-man.y)/(10-i);
                }
            }
            if(counttodealth==9) play(gDeath);
            if(counttodealth>=9)
                {

                     man.y=510;
                     graphics.render2(man.x,man.y,death);
                     death.tick();
                }

            if(counttodealth>=32) over=true;
        }
          if(isCollisionwithmonster(man.x+90,man.y+80,45,60,poi.x,poi.y+1,84,29))
        {
            collision3=true;
        }
        if(collision3)
        {
             counttodealth++;
             if(counttodealth==1) play(poisonImpact);
             man.y-=4;
             if(counttodealth<=12) graphics.render2(man.x+50,545,poisonimpact);

                 for(int i=1;i<=8;i++)
            {
                if(counttodealth==i){
                graphics.renderTexture(fall1,man.x,man.y);
                man.y+=(510-man.y)/(10-i);
                }
            }
            if(counttodealth==9) play(gDeath);
            if(counttodealth>=9)
                {
                     man.y=510;
                     graphics.render2(man.x,man.y,death);
                     death.tick();
                }


            if(counttodealth>=32) over=true;
        }

}
void manJump(Graphics &graphics,Mouse &man,int &jumptimes,int &falltimes,Mix_Chunk*gFall)
{
     if(jumptimes<=0) man.isJumping=true;
        else if(jumptimes>0) man.isJumping=false;
        if(man.y>=510)
        {   jumptimes=7;//so lan nhay toi da
           if(falltimes==1) play(gFall);
           falltimes--;
        }
        else falltimes=1;

        if(man.y<=280 ){
          man.isJumping=true;
        }
        if(man.y<=290) man.height=1;
        else if(man.y<=350) man.height=10;
        else if(man.y<=470) man.height=30;
        else man.height=40;
        man.move();
        man.x-=4;
}

#endif
