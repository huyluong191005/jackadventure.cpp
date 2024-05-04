#ifndef _INITALIZE__H
#define _INITALIZE__H

void resetData(Mouse &man,Mouse &frog,Mouse &monster,Mouse &bat,Mouse &crab,Mouse &poi,Mouse &as1,Mouse &as2,Mouse &as3,int &frame,bool &poison,bool &collision2,bool &collision3,bool &collision4,int &biteframecount,int &disappearcount,int &disappearcount2,bool &over,int&counttodeath,int&jumptimes,bool &quit)
{
      man.x=300;
    man.y=225;
    man.isJumping=true;
    man.isFreefalling=false;
    man.speed=14;
    frog.x=-350;
    frog.y=410;
    frog.speed=2;
    monster.x=900;
    monster.y=570;
    monster.speed=5;
    bat.x=1500;
    bat.y=400;
    bat.speed=7;
    crab.x=-200;
    crab.y=415;
    crab.speed=5;
    poi.x=-150;
    poi.y=570;
    poi.speed=4;
    as1.x=350;
    as1.y=-70;
    as2.x=50;
    as2.y=-150;
    as3.x=500;
    as3.y=-200;
     frame=0;
     poison=(0);
     collision2=(0);collision3=(0);collision4=(0);
     biteframecount=(0);
     disappearcount=(0);
     disappearcount2=(0);
     over=false;
     counttodeath=0;
     jumptimes=3;
     quit=false;

}
#endif
