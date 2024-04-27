
#ifndef _MONSTER __H
#define _MONSTER__H
#include "background.h"
#include "defs.h"
#include "graphics.h"
#include "moving.h"

void frogMove(Graphics &graphics,Mouse &frog,Mouse &man,Mouse &poi,Sprite &boss1,Sprite& poisonattack,Sprite &poisons,Sprite &poisonimpact,SDL_Texture* boss1Texture,SDL_Texture* boss1_2Texture,SDL_Texture *poisonattackTexture,SDL_Texture *poisonTexture,SDL_Texture* poisonimpactTexture,int &frame,int &biteframecount,bool &over,bool &poison )
{
    poisonattack.init(poisonattackTexture,17,POISONATTACK_CLIPS);
    poisons.init(poisonTexture,12,POISON_CLIPS);
    poisonimpact.init(poisonimpactTexture,12,POISONIMPACT_CLIPS);

    if(isCollisionwithmonster(man.x+90,man.y+80,45,60,poi.x,poi.y+1,84,29)) poi.x=3000;

    frog.speed=2;
        if(frame>=100&&frame<=122||frame>=300&&frame<=322||frame>=500&&frame<=522||frame>=700&&frame<=722||frame>=900&&frame<=922||frame>=1100&&frame<=1122)
        {

        if(frame==118||frame==318||frame==518||frame==718||frame==918||frame==1118) poi.x=frog.x+250;

            graphics.render2(frog.x+110,frog.y+95,poisonattack);

        }
         else {
       if(frog.x<=-180)
        {
            frog.x+=frog.speed;
        }
        if(frog.x<=-110)
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

        if(frame>=118){graphics.render2(poi.x,poi.y,poisons);
        poi.x+=poi.speed;}


        graphics.render2(frog.x,frog.y,boss1);

        boss1.tick();

        }

        poisonattack.tick();
        poisons.tick();
        poisonimpact.tick();
        if(frame%17<=6) frog.x-=(4*frog.speed);
        if(frame%17>=7) frog.x+=frog.speed;
        //
}
void rhinoMove(Graphics &graphics,Mouse &monster,Mouse &frog,Sprite &rhino,Sprite &poisonimpact,SDL_Texture* rhinoTexture,SDL_Texture* rhinohitTexture,int & disappearcount,Mouse &poi,int &frame,bool &collision4)
{

    if(monster.speed!=0)
        {
            rhino.init(rhinoTexture,6,RHINO_CLIPS);
        }
    if(monster.speed==0)
        {
            disappearcount++;
            if(disappearcount<=16){
            if(disappearcount<=12&&collision4)
            {
                graphics.render2(monster.x-15,545,poisonimpact);
                monster.x+=5;
            }
            rhino.init(rhinohitTexture,5,RHINOHIT_CLIPS);
        }
        else
        {
            collision4=0;
            poi.x=3000;
            monster.x=800+(rand()%300);
            monster.speed=4;
            disappearcount=0;
        }
        }
        if(frog.x+250>=monster.x||isCollisionwithmonster(monster.x,monster.y+6,105,65,poi.x,poi.y+1,84,29))
        {
            if(isCollisionwithmonster(monster.x,monster.y+6,105,65,poi.x,poi.y+1,84,29)) collision4=true;
            monster.speed=0;
            poi.x=3000;
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
                 bat.y=400+(rand()%150);
                 disappearcount2=0;
                 bat.speed=7;
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
void crabMove(Graphics &graphics,Mouse &crab,Sprite &boss2,int &frame)
{
    if(frame==200)
        {
            if(crab.x<=0)
            {
                crab.x=-200;
                crab.speed=5;
            }
            if(crab.x>290)
            {
                crab.x=SCREEN_WIDTH;
                crab.speed=-5;
            }
        }
        if(frame>200&&frame<=650)
        {
            crab.x+=crab.speed;
            if(crab.x>=290&&crab.speed>0&&frame<=550)
            {
                crab.x=290;
            }
            if(crab.x<=290&&crab.speed<0&&frame<=550)
            {
                crab.x=290;
            }
            graphics.render2(crab.x,crab.y,boss2);
            boss2.tick();
        }
}

#endif
