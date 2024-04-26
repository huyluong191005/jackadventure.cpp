
#ifndef _MONSTER __H
#define _MONSTER__H
#include "background.h"
#include "defs.h"
#include "graphics.h"
#include "moving.h"

void frogMove(Graphics &graphics,Mouse &frog,Mouse &man,Sprite &boss1,SDL_Texture* boss1Texture,SDL_Texture* boss1_2Texture,int &frame,int &biteframecount,bool &over )
{
    //if(frame>=200&&frame<=400) frog.speed=0;
    //else frog.speed=2;
    if(frog.x<=-180)
        {
            frog.x+=frog.speed;
        }
        if(frog.x<=-120)
        {
            frog.x+=frog.speed;
        }


        if(frog.x+265>man.x)
        {
            boss1.init(boss1_2Texture,17,BOSS1_2_CLIPS);
            frog.x+=(4*frog.speed);
            if(frog.x+160>man.x) {
                    biteframecount++;
                    man.x=frog.x+120;
                    man.y=frog.y+50;
                    if(biteframecount%15==0) over=true;

            }


        }

        else {
                boss1.init(boss1Texture,17,BOSS1_CLIPS);
                biteframecount=0;
        }
        graphics.render2(frog.x,frog.y,boss1);
        boss1.tick();


        if(frame%17<=6) frog.x-=(4*frog.speed);
        if(frame%17>=7) frog.x+=frog.speed;
        //
}
void rhinoMove(Graphics &graphics,Mouse &monster,Mouse &frog,Sprite &rhino,SDL_Texture* rhinoTexture,SDL_Texture* rhinohitTexture,int & disappearcount)
{
    if(monster.speed!=0)
        {
            rhino.init(rhinoTexture,6,RHINO_CLIPS);
        }
        else{
            disappearcount++;
            if(disappearcount<=20){
            rhino.init(rhinohitTexture,5,RHINOHIT_CLIPS);
        }
        else
        {
            monster.x=800+(rand()%300);
            monster.speed=4;
            disappearcount=0;

        }
        }
        if(frog.x+250>=monster.x)
        {
            monster.speed=0;
        }
        monster.x-=monster.speed;
        rhino.tick();
        graphics.render2(monster.x,monster.y,rhino);
}
void batMove(Graphics &graphics,Sprite &batman,Mouse &bat,Mouse &frog,SDL_Texture *batTexture,SDL_Texture *bat2Texture,int &disappearcount2)
{
         if(bat.speed!=0)
        {
            batman.init(batTexture,7,BAT_CLIPS);
        }
        else {
             disappearcount2++;
            if(disappearcount2<=20){
                    batman.init(bat2Texture,5,BAT2_CLIPS);
            }
            else{
                 bat.x=1000+(rand()%500);
                 bat.y=400+(rand()%100);
                 disappearcount2=0;
                 bat.speed=4;
            }
        }

        bat.x-=bat.speed;
        if(bat.x<=-50) {
            bat.x=1000+(rand()%500);
            bat.y=400+(rand()%100);
        }
        if(isCollisionwithmonster(frog.x+100,frog.y+80,200,150,bat.x+20,bat.y+10,45,30))
        {
            bat.speed=0;
        }

        graphics.render2(bat.x,bat.y,batman);
        batman.tick();
}

#endif
