#include "defs.h"
#include "graphics.h"
#include "moving.h"
#include "background.h"
#include "monster.h"
#include "music.h"
#include "Initalize.h"
#include <string>
using namespace std;
void handleEvents(bool& quit, bool& startGame,bool &game,bool &helb,bool &settings,bool &soundOn,bool &musicOn,Mix_Chunk *click) {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            quit = true;
            game=false;
        } else if (e.type == SDL_MOUSEBUTTONDOWN) {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            // Check if "Play" button is clicked
            if (mouseX >= 350 && mouseX <= 465 && mouseY >= 350 && mouseY <= 465&&!helb&&!settings) {
                startGame = true;
                play(click);
            }
            else if(mouseX>=490&&mouseX<=559&&mouseY>=465&&mouseY<=534&&!helb&&!settings)
            {
                quit = true;
                game=false;
                play(click);
            }
            else if(mouseX>=410&&mouseX<=479&&mouseY>=465&&mouseY<=534&&!helb&&!settings)
            {
                helb=true;
                play(click);
            }
             else if((mouseX-752)*(mouseX-752)+(mouseY-70)*(mouseY-70)<=50*50)
            {
                helb=false;
                settings=false;
                play(click);
            }
             else if(mouseX>=250&&mouseX<=319&&mouseY>=465&&mouseY<=534&&!helb&&!settings)
            {
                settings=true;
                play(click);
            }
            else if(settings&&mouseX>=250&&mouseX<=380&&mouseY>=410&&mouseY<=540)
            {
               soundOn=!soundOn;
               play(click);
            }
            else if(settings&&mouseX>=430&&mouseX<=560&&mouseY>=410&&mouseY<=540)
            {
               musicOn=!musicOn;
               play(click);
            }



        }
    }
}
void handleEvents2(bool& quit, bool& startGame,bool &game) {
    SDL_Event e;
    while (true) {
            SDL_PollEvent(&e);
        if (e.type == SDL_QUIT) {
            quit = true;
            game =false;
            break;
        } else if (e.type == SDL_MOUSEBUTTONDOWN) {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);

            if (mouseX >= 280 && mouseX <= 378 && mouseY >= 550 && mouseY <= 648) {
                startGame = true;
                quit=true;
                break;
            }
            else if(mouseX >= 450 && mouseX <= 548 && mouseY >= 550 && mouseY <= 648)
            {
                startGame=false;
                quit=true;
                break;
            }

        }
    }
}


void intToCharArray(int number, char charArray[]) {
    std::string str = std::to_string(number);
    strcpy(charArray, str.c_str());
}

int main(int argc, char* argv[])
{

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
    Sprite idle;
    SDL_Texture* idleTexture=graphics.loadTexture(IDLE_SPRITE_FILE);
    idle.init(idleTexture,8,IDLE_CLIPS);
    Sprite asteroid;
    Sprite asteroid2;
    SDL_Texture* asteroidTexture=graphics.loadTexture(ASTEROID_SPRITE_FILE);
    asteroid.init(asteroidTexture,3,ASTEROID_CLIPS);

    SDL_Texture* poisonimpactTexture=graphics.loadTexture(POISONIMPACT_SPRITE_FILE);
    SDL_Texture *start=graphics.loadTexture("images\\play.png");
    SDL_Texture *gameover=graphics.loadTexture("images\\gameover1.png");
    SDL_Texture *fall1=graphics.loadTexture("images\\fall1.png");
    SDL_Texture *fall2=graphics.loadTexture("images\\fall2.png");
    SDL_Texture *back1=graphics.loadTexture("images\\Background.png");
    SDL_Texture *adventuretime=graphics.loadTexture("images\\pngegg.png");
    SDL_Texture *restart=graphics.loadTexture("images\\restart.png");
    SDL_Texture *home=graphics.loadTexture("images\\menu.png");
    SDL_Texture *setting=graphics.loadTexture("images\\settings.png");
    SDL_Texture *highscore=graphics.loadTexture("images\\prize.png");
    SDL_Texture *help=graphics.loadTexture("images\\faq.png");
    SDL_Texture *helpTexture=graphics.loadTexture("images\\maxresdefault.jpg");
    SDL_Texture *close=graphics.loadTexture("images\\close.png");
    SDL_Texture *closePage=graphics.loadTexture("images\\close_2.png");
    SDL_Texture *soundon=graphics.loadTexture("images\\misic.png");
    SDL_Texture *soundoff=graphics.loadTexture("images\\music_off.png");
    SDL_Texture *musicon=graphics.loadTexture("images\\sound.png");
    SDL_Texture *musicoff=graphics.loadTexture("images\\sound_off.png");
    SDL_Texture *settingbar=graphics.loadTexture("images\\settingbar.png");
    Mix_Music *gMusic = loadMusic("sounds\\Uprising.wav");

    Mix_Chunk *click = loadSound("sounds\\Menu Selection Click.wav");
    Mix_Chunk *gJump = loadSound("sounds\\Data_Sounds_Playersounds - Track 10 - Jump2.wav");
    Mix_Chunk *gFall = loadSound("sounds\\fall.wav");
    Mix_Chunk *gLaser = loadSound("sounds\\Laser Shot.wav");
    Mix_Chunk *crabGrunt = loadSound("sounds\\Monster Growl-SoundBible.com-344645592.wav");
    Mix_Chunk *dropBomb = loadSound("sounds\\dropbomb-2seconds.wav");
    Mix_Chunk *deathFlash = loadSound("sounds\\DeathFlash.wav");
    Mix_Chunk *gDeath = loadSound("sounds\\Playersounds - Track 6 - Hurt2.wav");
    Mix_Chunk *poisonImpact = loadSound("sounds\\impactsplat03.wav");
    Mix_Chunk *frogGrunt = loadSound("sounds\\Large Monster Grunt Hit 02.wav");
    Mix_Chunk *frogGrunt2 = loadSound("sounds\\monster-5.wav");
    Mix_Chunk *runNing = loadSound("sounds\\running-14658.mp3");

    TTF_Font* font = graphics.loadFont("font\\ka1.ttf", 31);

    char  score[]="0";
    Mouse man;
    man.x=300;
    man.y=225;
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
    bat.x=1500;
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
    int frame(0);
    bool poison(0);
    bool collision(0),collision2(0),collision3(0),collision4(0);
    int biteframecount(0);
    int disappearcount(0);
    int disappearcount2(0);
    bool over=false;
    bool startgame=false;
    int counttodealth(0);
    int jumptimes=3;
    int falltimes=0;
    bool quit = false;
    bool replay=true;
    bool menu=true;
    bool game=true;
    int scores=0;
    SDL_Event e;
    bool helb=false;
    bool settings=false;
    bool soundOn=true;
    bool musicOn=true;
    SDL_Texture*sound;
    SDL_Texture*music;


    while(!quit||game)
    {
        if(musicOn) play(gMusic);
            else Mix_HaltMusic();

        if(soundOn)
        {
            Mix_VolumeMusic(10);
            setVolume(100);
        }
        else
        {
            Mix_VolumeMusic(0);
            setVolume(0);
        }

        if(!startgame)
        {
            man.x=300;
            man.y=225;
            handleEvents(quit,startgame,game,helb,settings,soundOn,musicOn,click);

            graphics.renderTexture(back1,0,0);
            graphics.renderTexture(start,350,350);
            graphics.renderTexture(adventuretime,180,90);
            graphics.renderTexture(setting,250,465);
            graphics.renderTexture(highscore,330,465);
            graphics.renderTexture(help,410,465);
            graphics.renderTexture(close,490,465);
            graphics.render2(man.x,man.y,idle);
             if(helb)
            {
                graphics.renderTexture(helpTexture,100,100);
            }

            if(settings)
            {
                if(soundOn) {
                sound=soundon;
            }
            else { sound=soundoff;}
            if(musicOn) {
                music=musicon;
            }
            else music=musicoff;


               graphics.renderTexture(settingbar,150,230);
               graphics.renderTexture(sound,250,410);
               graphics.renderTexture(music,430,410);

            }


            if(helb||settings) graphics.renderTexture(closePage,700,20);

            idle.tick();
            graphics.presentScene();
            SDL_Delay(35);

        }
        else{
         int scores1=0;
        int scores=0;
        resetData(man,frog,monster,bat,crab,poi,as1,as2,as3,frame,poison,collision,collision2,collision3,collision4,biteframecount,disappearcount,disappearcount2,over,counttodealth,jumptimes,quit);

    while( !quit ) {

        if(over)
        {

            graphics.renderTexture(gameover,-50,0);
            graphics.renderTexture(restart,280,550);
            graphics.renderTexture(home,450,550);
            SDL_Color color = {225, 0, 225, 0};
            SDL_Texture* scoreText = graphics.renderText(score, font, color);
            SDL_Texture* yourScore = graphics.renderText("YOUR SCORE", font, color);
            graphics.renderTexture(scoreText, 510,420);
            graphics.renderTexture(yourScore, 220,420);
            graphics.presentScene();
            handleEvents2(quit,startgame,game);
        }
        else
        {

        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT )
            {
                quit = true;
                game=false;
            }

        }

        frame++;//tinh so frame
        scores1++;

        if(frame==1500) frame=0;
        scores=scores1/5;
        intToCharArray(scores,score);
        SDL_Color color = {225, 0, 0, 0};
        SDL_Texture* scoreText = graphics.renderText(score, font, color);

        background1(graphics,layer1,layer2,layer3,lights1,layer4,layer5,lights2);
        crabMove(graphics,crab,boss2,laser,frame,gLaser,crabGrunt,dropBomb);

        background2(graphics,layer6,layer8,layer9);
        background3(graphics,layer7);
        asteroidMove(graphics,asteroid,as1,as2,as3,frame,deathFlash);



        //va cham


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



        //xu li chuyen dong bang mui ten
         const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
        if(!over&&(!currentKeyStates[SDL_SCANCODE_UP])&&!man.isFreefalling&&!(collision&&man.x+95<monster.x)&&!collision2&&!collision3)
        {
           graphics.render2(man.x,man.y,run);

        }
        if (currentKeyStates[SDL_SCANCODE_UP]&&!man.isJumping&&!(collision&&man.x+95<monster.x)&&!collision2&&!collision3)
        {

            if(jumptimes==6) play(gJump);graphics.render2(man.x,man.y,jump);
            jump.tick();
            man.makeAjump();

            jumptimes--;


        }else{
            man.freeFall();
            if(currentKeyStates[SDL_SCANCODE_RIGHT]&&man.isFreefalling&&!collision&&!collision2&&!collision3)
        {
            graphics.renderTexture(fall2,man.x,man.y);

        }
            else if(man.isFreefalling&&man.y<510&&!collision&&!collision2&&!collision3)
            {
              graphics.renderTexture(fall1,man.x,man.y);
            }
        }

        if(currentKeyStates[SDL_SCANCODE_RIGHT]&&!collision2&&!collision3)
        {
            man.run();

        }

        if(currentKeyStates[SDL_SCANCODE_LEFT]&&!collision2&&!collision3)
        {
            man.runback();
        }
        if(currentKeyStates[SDL_SCANCODE_DOWN]&&man.y<=495&&!collision2&&!collision3)
        {
            man.fallDown();
        }
        //
          //monster
        frogMove(graphics,frog,man,poi,boss1,poisonattack,poisons,poisonimpact,boss1Texture,boss1_2Texture,poisonattackTexture,poisonTexture,poisonimpactTexture,frame,biteframecount,over,poison,frogGrunt,frogGrunt2);
        rhinoMove(graphics,monster,frog,rhino,poisonimpact,rhinoTexture,rhinohitTexture,disappearcount,poi,frame,collision4,as1,as2,as3,poisonImpact);
        batMove(graphics,batman,bat,frog,batTexture,bat2Texture,disappearcount2,as1,as2,as3);
        //
        //xu li nhay nhan vat
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
        //hitbox
        //graphics.drawRect(man.x+90,man.y+80,45,60);
        //graphics.drawRect(monster.x,monster.y+6,105,65);
        //graphics.drawRect(frog.x+100,frog.y+80,200,150);
        //graphics.drawRect(bat.x+15,bat.y+5,40,30);
        //graphics.drawRect(poi.x,poi.y+1,84,29);
        //graphics.drawRect(as1.x+9,as1.y+5,41,41);
        //graphics.drawRect(as2.x+9,as2.y+5,41,41);
        //graphics.drawRect(as3.x+9,as3.y+5,41,41);
        //
        run.tick();
        man.move();
        man.x-=4;
        if(!over) graphics.renderTexture(scoreText, 0,0);
        graphics.presentScene();
        SDL_Delay(30);
        }
    }
    }

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
