#include "defs.h"
#include "graphics.h"
#include "moving.h"
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
    layer1.setTexture(graphics.loadTexture("images\\Layer_0010_1.png"));
    layer2.setTexture(graphics.loadTexture("images\\Layer_0009_2.png"));
    layer3.setTexture(graphics.loadTexture("images\\Layer_0008_3.png"));
    lights1.setTexture(graphics.loadTexture("images\\Layer_0007_Lights.png"));
    layer4.setTexture(graphics.loadTexture("images\\Layer_0006_4.png"));
    layer5.setTexture(graphics.loadTexture("images\\Layer_0005_5.png"));
    lights2.setTexture(graphics.loadTexture("images\\Layer_0004_Lights.png"));
    layer6.setTexture(graphics.loadTexture("images\\Layer_0003_6.png"));
    layer7.setTexture(graphics.loadTexture("images\\Layer_0002_7.png"));
    layer8.setTexture(graphics.loadTexture("images\\Layer_0001_8.png"));
    layer9.setTexture(graphics.loadTexture("images\\Layer_0000_9.png"));
    Sprite run;
    SDL_Texture* manTexture = graphics.loadTexture(RUN_SPRITE_FILE);
    run.init(manTexture, 8, RUN_CLIPS);
    Sprite jump;
    SDL_Texture* jumpTexture = graphics.loadTexture(JUMP_SPRITE_FILE);
    jump.init(jumpTexture, 4, JUMP_CLIPS);
    Sprite boss1;
    SDL_Texture* boss1Texture = graphics.loadTexture(BOSS1_SPRITE_FILE);
    boss1.init(boss1Texture, 17, BOSS1_CLIPS);
    Sprite boss1_2;
    SDL_Texture* boss1_2Texture = graphics.loadTexture(BOSS1_2_SPRITE_FILE);
    boss1_2.init(boss1_2Texture, 17, BOSS1_2_CLIPS);
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

        layer1.scroll(0);
        graphics.render(layer1);
        layer2.scroll(2);
        graphics.render(layer2);
        layer3.scroll(3);
        graphics.render(layer3);
        lights1.scroll(3);
        graphics.render(lights1);
        layer4.scroll(3);
        graphics.render(layer4);
        layer5.scroll(4);
        graphics.render(layer5);
        lights2.scroll(3);
        graphics.render(lights2);
        layer6.scroll(6);
        graphics.render(layer6);
        layer7.scroll(4);
        graphics.render(layer7);
        layer8.scroll(4);
        graphics.render(layer8);
        layer9.scroll(3);
        graphics.render(layer9);

        boss1.tick();
        boss1_2.tick();

        //random monster
        if(monster.speed!=0)
        {
            graphics.render2(monster.x,monster.y,rhino);
            rhino.tick();
        }
        else{
            disappearcount++;
            if(disappearcount<=20){
            graphics.render2(monster.x,monster.y,rhinohit);
            rhinohit.tick();
        }
        else
        {
            monster.x=1500;
            monster.speed=4;
            disappearcount=0;

        }
        }
        if(frog.x+250>=monster.x)
        {
            monster.speed=0;
        }

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
        if(frog.x<=-180)
        {
            frog.x+=2;
        }
        if(frog.x<=-120)
        {
            frog.x+=2;
        }


        if(frog.x+265>man.x||frog.x+310>monster.x)
        {
            graphics.render2(frog.x,frog.y,boss1_2);
            frog.x+=7;
            if(frog.x+160>man.x) {
                    biteframecount++;
                    man.x=frog.x+120;
                    man.y=frog.y+50;
                    if(biteframecount%15==0) over=true;

            }


        }

        else {
                graphics.render2(frog.x,frog.y,boss1);
                biteframecount=0;
        }


        if(frame%17<=6) frog.x-=8;
        if(frame%17>=7) frog.x+=2;
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
        //graphics.drawRect(man.x+90,man.y+60,45,80);
        //graphics.drawRect(monster.x,monster.y+6,105,65);
        //graphics.drawRect(frog.x+100,frog.y+80,200,150);
        //
        man.move();

        man.x-=4;
        monster.x-=monster.speed;
        graphics.presentScene();
        SDL_Delay(45);
    }



    SDL_DestroyTexture( layer1.texture );
    SDL_DestroyTexture( layer2.texture );
    SDL_DestroyTexture( layer3.texture );
    SDL_DestroyTexture( lights1.texture);
    SDL_DestroyTexture( layer4.texture );
    SDL_DestroyTexture( layer5.texture );
    SDL_DestroyTexture( lights2.texture);
    SDL_DestroyTexture( layer6.texture );
    SDL_DestroyTexture( layer7.texture );
    SDL_DestroyTexture( layer8.texture );
    SDL_DestroyTexture( layer9.texture );
    SDL_DestroyTexture( manTexture ); manTexture = nullptr;
    SDL_DestroyTexture( jumpTexture ); jumpTexture = nullptr;
    SDL_DestroyTexture( boss1Texture ); boss1Texture = nullptr;
    SDL_DestroyTexture( boss1_2Texture ); boss1_2Texture = nullptr;
    SDL_DestroyTexture( rhinoTexture ); rhinoTexture = nullptr;
    SDL_DestroyTexture( start); start = nullptr;

    graphics.quit();

    return 0;
}
