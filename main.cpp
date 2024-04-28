#include "defs.h"
#include "graphics.h"
#include "moving.h"
#include "background.h"
#include "monster.h"
#include "music.h"
#include <iostream>

int main(int argc, char* argv[])
{
    int frame(0);
    bool poison(0);
    bool collision(0),collision2(0),collision3(0),collision4(0);
    int biteframecount(0);
    int disappearcount(0);
    int disappearcount2(0);
    bool over=false;
    bool startgame=false;
    int counttodealth(0);
    Graphics graphics;
    graphics.init();

    ScrollingBackground layer1,layer2,layer3,lights1,layer4,layer5,lights2,layer6,layer7,layer8,layer9;
    backtexture(graphics,layer1,layer2,layer3,lights1,layer4,layer5,lights2,layer6,layer7,layer8,layer9);
    Sprite run;
    SDL_Texture* runTexture = graphics.loadTexture(RUN_SPRITE_FILE);
    run.init(runTexture, 8, RUN_CLIPS);
    Sprite jump;
    SDL_Texture* jumpTexture = graphics.loadTexture(JUMP_SPRITE_FILE);
    jump.init(jumpTexture, 4, JUMP_CLIPS);
    Sprite boss1;
    SDL_Texture* boss1Texture = graphics.loadTexture(BOSS1_SPRITE_FILE);
    SDL_Texture* boss1_2Texture = graphics.loadTexture(BOSS1_2_SPRITE_FILE);
    Sprite poisonattack;
    SDL_Texture* poisonattackTexture = graphics.loadTexture(POISONATTACK_SPRITE_FILE);
    Sprite rhino;
    SDL_Texture* rhinoTexture = graphics.loadTexture(RHINO_SPRITE_FILE);
    rhino.init(rhinoTexture,6,RHINO_CLIPS);
    SDL_Texture* rhinohitTexture = graphics.loadTexture(RHINOHIT_SPRITE_FILE);
    Sprite death;
    SDL_Texture* deathTexture = graphics.loadTexture(DEATH_SPRITE_FILE);
    death.init(deathTexture,24,DEATH_CLIPS);
    Sprite batman;
    SDL_Texture* batTexture = graphics.loadTexture(BAT_SPRITE_FILE);
    SDL_Texture* bat2Texture = graphics.loadTexture(BAT2_SPRITE_FILE);
    Sprite boss2;
    SDL_Texture* boss2Texture=graphics.loadTexture(BOSS2_SPRITE_FILE);
    boss2.init(boss2Texture,19,BOSS2_CLIPS);
    Sprite poisons;
    SDL_Texture* poisonTexture=graphics.loadTexture(POISON_SPRITE_FILE);
    Sprite poisonimpact;
    Sprite laser;
    SDL_Texture* laserTexture=graphics.loadTexture(LASER_SPRITE_FILE);
    laser.init(laserTexture,6,LASER_CLIPS);
    Sprite asteroid;
    Sprite asteroid2;
    Sprite asteroid3;
    SDL_Texture* asteroidTexture=graphics.loadTexture(ASTEROID_SPRITE_FILE);
    asteroid.init(asteroidTexture,3,ASTEROID_CLIPS);
    asteroid2.init(asteroidTexture,3,ASTEROID_CLIPS);
    asteroid3.init(asteroidTexture,3,ASTEROID_CLIPS);
    SDL_Texture* poisonimpactTexture=graphics.loadTexture(POISONIMPACT_SPRITE_FILE);
    SDL_Texture *start=graphics.loadTexture("images\\start.png");
    SDL_Texture *gameover=graphics.loadTexture("images\\gameover1.png");
    SDL_Texture *fall1=graphics.loadTexture("images\\fall1.png");
    SDL_Texture *fall2=graphics.loadTexture("images\\fall2.png");


    Mouse man;
    man.x=350;
    man.y=350;
    man.isJumping=true;
    man.isFreefalling=false;
    man.speed=11;
    Mouse frog;
    frog.x=-350;
    frog.y=410;
    frog.speed=2;
    Mouse monster;
    monster.x=900;
    monster.y=570;
    monster.speed=5;
    Mouse bat;
    bat.x=500;
    bat.y=400;
    bat.speed=7;
    Mouse crab;
    crab.x=-200;
    crab.y=415;
    crab.speed=5;
    Mouse poi;
    poi.x=-150;
    poi.y=570;
    poi.speed=4;
    Mouse as1;
    as1.x=350;
    as1.y=-70;
    Mouse as2;
    as2.x=50;
    as2.y=-150;
    Mouse as3;
    as3.x=500;
    as3.y=-200;

    int jumptimes=3;
    bool quit = false;
    SDL_Event e;
    while( !quit ) {
        if(over)
        {
            graphics.renderTexture(gameover,-50,0);
            graphics.presentScene();
            waitUntilKeyPressed();
            quit=true;
        }
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT ) quit = true;

        }
        frame++;//tinh so frame
        if(frame==1200) frame=0;

        background1(graphics,layer1,layer2,layer3,lights1,layer4,layer5,lights2);
        crabMove(graphics,crab,boss2,laser,frame);

        background2(graphics,layer6,layer8,layer9);
        background3(graphics,layer7);

        asteroidMove(graphics,asteroid,asteroid2,asteroid3,as1,as2,as3,frame);


        //va cham


        if(isCollisionwithmonster(man.x+90,man.y+70,45,70,bat.x+15,bat.y+5,40,30)||isCollisionwithmonster(man.x+90,man.y+70,45,70,as1.x+9,as1.y+5,41,41)||isCollisionwithmonster(man.x+90,man.y+70,45,70,as2.x+9,as2.y+5,41,41)||isCollisionwithmonster(man.x+90,man.y+70,45,70,as3.x+9,as3.y+5,41,41))
        {
            collision2=true;
        }
        if(collision2)
        {

            counttodealth++;

            for(int i=1;i<=8;i++)
            {
                if(counttodealth==i){
                man.y+=(510-man.y)/(10-i);
                graphics.renderTexture(fall1,man.x,man.y);
                }
            }
            if(counttodealth==9) man.y=510;

            if(counttodealth>=9&&counttodealth<=32)
            {
                graphics.render2(man.x,man.y,death);
                death.tick();
            }

            if(counttodealth==32) over=true;
        }
          if(isCollisionwithmonster(man.x+90,man.y+80,45,60,poi.x,poi.y+1,84,29))
        {
            collision3=true;
        }
        if(collision3)
        {
            man.y=510;
            counttodealth++;
            if(counttodealth<=11)
            {
                graphics.render2(man.x+45,545,poisonimpact);
            }
            graphics.render2(man.x,man.y,death);
            death.tick();
            if(counttodealth==23) over=true;
        }

         if(isCollisionwithmonster(man.x+90,man.y+60,45,80,monster.x,monster.y+6,95,65)&&man.x+87>monster.x)
        {
            man.y=monster.y-110;
            man.isFreefalling=false;
            collision=true;

        }
        else if(isCollisionwithmonster(man.x+90,man.y+60,40,80,monster.x,monster.y+6,105,65)&&man.x+95<monster.x)
        {
            counttodealth++;
            collision=true;
            man.speed=0;
            graphics.render2(man.x,man.y,death);
            death.tick();

            if(counttodealth==23) over=true;
        }
        else collision=false;

        //xu li chuyen dong bang mui ten
         const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
        if(!over&&(!currentKeyStates[SDL_SCANCODE_UP])&&!man.isFreefalling&&!(collision&&man.x+95<monster.x)&&!collision2)
        {
           graphics.render2(man.x,man.y,run);
        }
        if (currentKeyStates[SDL_SCANCODE_UP]&&!man.isJumping&&!(collision&&man.x+95<monster.x)&&!collision2)
        {
            graphics.render2(man.x,man.y,jump);
            jump.tick();
            man.makeAjump();
            jumptimes--;
        }else{
            man.freeFall();
            if(currentKeyStates[SDL_SCANCODE_RIGHT]&&man.isFreefalling&&!collision&&!collision2)
        {
            graphics.renderTexture(fall2,man.x,man.y);

        }
            else if(man.isFreefalling&&man.y<510&&!collision&&!collision2)
            {
              graphics.renderTexture(fall1,man.x,man.y);
            }
        }

        if(currentKeyStates[SDL_SCANCODE_RIGHT]&&!collision2)
        {
            man.run();
        }

        if(currentKeyStates[SDL_SCANCODE_LEFT]&&!collision2)
        {
            man.runback();
        }
        if(currentKeyStates[SDL_SCANCODE_DOWN]&&man.y<=495&&!collision2)
        {
            man.fallDown();
        }
        //
          //monster
        frogMove(graphics,frog,man,poi,boss1,poisonattack,poisons,poisonimpact,boss1Texture,boss1_2Texture,poisonattackTexture,poisonTexture,poisonimpactTexture,frame,biteframecount,over,poison);
        rhinoMove(graphics,monster,frog,rhino,poisonimpact,rhinoTexture,rhinohitTexture,disappearcount,poi,frame,collision4,as1,as2,as3);
        batMove(graphics,batman,bat,frog,batTexture,bat2Texture,disappearcount2,as1,as2,as3);
        //
        //xu li nhay nhan vat
        if(jumptimes<=0) man.isJumping=true;
        else if(jumptimes>0) man.isJumping=false;
        if(man.y>=510) jumptimes=7;//so lan nhay toi da

        if(man.y<=280 ){
          man.isJumping=true;
        }
        if(man.y<=290) man.height=1;
        else if(man.y<=350) man.height=10;
        else if(man.y<=470) man.height=30;
        else man.height=40;
        //hitbox
        graphics.drawRect(man.x+90,man.y+80,45,60);
        graphics.drawRect(monster.x,monster.y+6,105,65);
        graphics.drawRect(frog.x+100,frog.y+80,200,150);
        graphics.drawRect(bat.x+15,bat.y+5,40,30);
        graphics.drawRect(poi.x,poi.y+1,84,29);
        graphics.drawRect(as1.x+9,as1.y+5,41,41);
        graphics.drawRect(as2.x+9,as2.y+5,41,41);
        graphics.drawRect(as3.x+9,as3.y+5,41,41);
        //
        run.tick();
        man.move();
        man.x-=4;
        graphics.presentScene();
        SDL_Delay(35);
    }



    destroybackground(graphics,layer1,layer2,layer3,lights1,layer4,layer5,lights2,layer6,layer7,layer8,layer9);
    SDL_DestroyTexture( runTexture ); runTexture = nullptr;
    SDL_DestroyTexture( jumpTexture ); jumpTexture = nullptr;
    SDL_DestroyTexture( boss1Texture ); boss1Texture = nullptr;
    SDL_DestroyTexture( boss1_2Texture ); boss1_2Texture = nullptr;
    SDL_DestroyTexture( rhinoTexture ); rhinoTexture = nullptr;
    SDL_DestroyTexture( start); start = nullptr;
    graphics.quit();

    return 0;
}
