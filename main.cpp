#include "defs.h"
#include "graphics.h"
#include "moving.h"
#include "background.h"
#include "monster.h"
#include <iostream>

int main(int argc, char* argv[])
{
    int frame(0);
    bool collision(0);
    int biteframecount(0);
    int disappearcount(0);
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
    boss1.init(boss1Texture, 17, BOSS1_CLIPS);
    SDL_Texture* boss1_2Texture = graphics.loadTexture(BOSS1_2_SPRITE_FILE);
    Sprite rhino;
    SDL_Texture* rhinoTexture = graphics.loadTexture(RHINO_SPRITE_FILE);
    rhino.init(rhinoTexture,6,RHINO_CLIPS);
    Sprite rhinohit;
    SDL_Texture* rhinohitTexture = graphics.loadTexture(RHINOHIT_SPRITE_FILE);
    rhinohit.init(rhinohitTexture,5,RHINOHIT_CLIPS);
    Sprite death;
    SDL_Texture* deathTexture = graphics.loadTexture(DEATH_SPRITE_FILE);
    death.init(deathTexture,24,DEATH_CLIPS);

    SDL_Texture *start=graphics.loadTexture("images\\start.png");
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
    monster.x=700;
    monster.y=570;
    monster.speed=4;

     int jumptimes=3;

    bool quit = false;
    SDL_Event e;
    while( !quit ) {
        if(over)
        {
            graphics.presentScene();
            waitUntilKeyPressed();
            quit=true;

        }

        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT ) quit = true;

        }



        frame++;//tinh so frame

        background1(graphics,layer1,layer2,layer3,lights1,layer4,layer5,lights2);
        background2(graphics,layer6,layer7,layer8,layer9);



        //random monster
        rhinoMove(graphics,monster,frog,rhino,rhinoTexture,rhinohitTexture,disappearcount);

        //
        //va cham

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
        if(!over&&(!currentKeyStates[SDL_SCANCODE_UP])&&!man.isFreefalling&&!(collision&&man.x+95<monster.x))
        {
           graphics.render2(man.x,man.y,run);
        }


        if (currentKeyStates[SDL_SCANCODE_UP]&&!man.isJumping&&!(collision&&man.x+95<monster.x))
        {
            graphics.render2(man.x,man.y,jump);
            jump.tick();
            man.makeAjump();
            jumptimes--;
        }else{
            man.freeFall();
            if(currentKeyStates[SDL_SCANCODE_RIGHT]&&man.isFreefalling&&!collision)
        {
            graphics.renderTexture(fall2,man.x,man.y);

        }
            else if(man.isFreefalling&&man.y<510&&!collision)
            {
              graphics.renderTexture(fall1,man.x,man.y);
            }
        }

        if(currentKeyStates[SDL_SCANCODE_RIGHT])
        {
            man.run();
            if(!currentKeyStates[SDL_SCANCODE_UP])
            {
                run.tick();
            }

        }
        if(currentKeyStates[SDL_SCANCODE_LEFT])
        {
            man.runback();
            run.tick();

        }
        if(currentKeyStates[SDL_SCANCODE_DOWN]&&man.y<=495)
        {
            man.fallDown();
        }
        //
          //chuyen dong cua frog
        frogMove(graphics,frog,man,boss1,boss1Texture,boss1_2Texture,frame,biteframecount,over);
        //
        //xu li nhay nhan vat
        if(jumptimes<=0) man.isJumping=true;
        else if(jumptimes>0) man.isJumping=false;
        if(man.y>=510) jumptimes=7;//so lan nhay toi da

        if(man.y<=348 ){
          man.isJumping=true;
        }
        if(man.y<=350) man.height=1;
        else if(man.y<=410) man.height=10;
        else if(man.y<=470) man.height=30;
        else man.height=40;
        //

        //hitbox
        graphics.drawRect(man.x+90,man.y+60,45,80);
        graphics.drawRect(monster.x,monster.y+6,105,65);
        graphics.drawRect(frog.x+100,frog.y+80,200,150);
        //
        man.move();

        man.x-=4;
        monster.x-=monster.speed;
        graphics.presentScene();
        SDL_Delay(45);
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
