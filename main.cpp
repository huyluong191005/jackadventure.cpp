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
    bool collision(0),collision2(0);
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
    poi.y=570;
    poi.speed=4;

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

        background1(graphics,layer1,layer2,layer3,lights1,layer4,layer5,lights2);
        if(frame==1200) frame=0;
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

        background2(graphics,layer6,layer7,layer8,layer9);
        //va cham
        if(isCollisionwithmonster(man.x+90,man.y+70,45,70,bat.x+15,bat.y+5,40,30)||isCollisionwithmonster(man.x+90,man.y+80,45,60,poi.x,poi.y+1,84,29))
        {
            collision2=true;
        }
        if(collision2)
        {
            man.y=510;
            counttodealth++;
            if(frame==1) man.y=man.y+(510-man.y)/12;
            if(frame==2) man.y=man.y+(510-man.y)/11;
            if(frame==3) man.y=man.y+(510-man.y)/5;
            if(frame==4) man.y=man.y+(510-man.y)/4;
            if(frame==5) man.y=man.y+(510-man.y)/3;
            if(frame==6) man.y=man.y+(510-man.y)/2;
            if(frame==7) man.y=510;
            if(frame>7){
            graphics.render2(man.x,man.y,death);
            death.tick();
            }
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
        frogMove(graphics,frog,man,poi,boss1,poisonattack,poisons,boss1Texture,boss1_2Texture,poisonattackTexture,poisonTexture,frame,biteframecount,over,poison);
        rhinoMove(graphics,monster,frog,rhino,rhinoTexture,rhinohitTexture,disappearcount);
        batMove(graphics,batman,bat,frog,batTexture,bat2Texture,disappearcount2);
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
        //
        //hitbox
        graphics.drawRect(man.x+90,man.y+80,45,60);
        graphics.drawRect(monster.x,monster.y+6,105,65);
        //graphics.drawRect(frog.x+100,frog.y+80,200,150);
        graphics.drawRect(bat.x+15,bat.y+5,40,30);
        graphics.drawRect(poi.x,poi.y+1,84,26);
        //graphics.drawRect(crab.x+35,crab.y+5,155,215);
        //
        run.tick();
        man.move();
        man.x-=4;
        graphics.presentScene();
        SDL_Delay(40);
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
