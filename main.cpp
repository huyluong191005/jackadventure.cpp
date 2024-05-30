#include "defs.h"
#include "graphics.h"
#include "background.h"
#include "bullet.h"
#include "monster.h"
#include "music.h"
#include "Initalize.h"
#include "startnoverpage.h"
#include "player.h"



int main(int argc, char* argv[])
{
    Graphics graphics;
    graphics.init();

    Background background;
    background.loadTextures(graphics);
    background.speed=0;
    int delta=0;
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
    Sprite asteroid,asteroid2;
    SDL_Texture* asteroidTexture=graphics.loadTexture(ASTEROID_SPRITE_FILE);
    asteroid.init(asteroidTexture,3,ASTEROID_CLIPS);
    Sprite sunDragon;
    SDL_Texture*dragonTexture=graphics.loadTexture(DRAGON_SPRITE_FILE);
    sunDragon.init(dragonTexture,9,DRAGON_CLIPS);
    Sprite attack;
    SDL_Texture* attackTexture=graphics.loadTexture(ATTACK_SPRITE_FILE);
    attack.init(attackTexture,14,ATTACK_CLIPS);
    Sprite arrowImpact;
    SDL_Texture*arrowimpactTexture=graphics.loadTexture(ARROWIMPACT_SPRITE_FILE);
    arrowImpact.init(arrowimpactTexture,5,ARROWIMPACT_CLIPS);
    Sprite dash;
    SDL_Texture*dashTexture=graphics.loadTexture(DASH_SPRITE_FILE);
    dash.init(dashTexture,14,DASH_CLIPS);
    Sprite melee;
    SDL_Texture*meleeTexture=graphics.loadTexture(MELEE_SPRITE_FILE);
    melee.init(meleeTexture,28,MELEE_CLIPS);

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
    SDL_Texture*sound; SDL_Texture*music;
    SDL_Texture*arrow=graphics.loadTexture("images\\ArrowSpit.png");

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
    Mix_Chunk *shoot = loadSound("sounds\\shoot1.mp3");
    Mix_Chunk *arrowHit2= loadSound("sounds\\arrowHit02.wav");
    Mix_Chunk *arrowHit = loadSound("sounds\\arrow-wood-impact-146418.mp3");

    TTF_Font* font = graphics.loadFont("font\\youmurdererbb_reg.ttf", 81);

    char  score[20];
    char  bScore[20];
    Mouse man; man.x=300; man.y=225; man.isJumping=true; man.isFreefalling=false; man.speed=14;
    Mouse frog; frog.x=-350; frog.y=410; frog.speed=2;
    Mouse monster; monster.x=900; monster.y=570; monster.speed=5;
    Mouse dragon; dragon.x=3000;dragon.y=160;
    Mouse bat; bat.x=1500; bat.y=400; bat.speed=7;
    Mouse crab; crab.x=-200; crab.y=415; crab.speed=5;
    Mouse poi; poi.x=-150; poi.y=570; poi.speed=4;
    Mouse as1; as1.x=350; as1.y=-70;
    Mouse as2; as2.x=50; as2.y=-150;
    Mouse as3; as3.x=500; as3.y=-200;
    Bullet b1;
    b1.x=-100;
    b1.y=-100;
    b1.dx=14;
    b1.dy=0;
    int frame(0);
    int biteframecount(0);
    int disappearcount(0);
    int disappearcount2(0);
    int counttodealth(0);
    int jumptimes=3;
    int falltimes=0;
    int scores=0;
    bool poison(0);
    bool collision(0),collision2(0),collision3(0),collision4(0);
    bool isattacking=false;
    bool isattacking2=false;
    bool isattacking3=false;
    bool over=false;
    bool startgame=false;
    bool quit = false;
    bool replay=true;
    bool menu=true;
    bool game=true;
    bool helb=false;
    bool settings=false;
    bool soundOn=true;
    bool musicOn=true;
    bool leaderboard=false;
    bool isPaused=false;
    int highScore[5];
    int frameCount(0),cooldown(0);

    SDL_Event e;
    while(!quit||game)
    {
       musicNsound(graphics,musicOn,soundOn,gMusic);

        if(!startgame)
        {
            ifstream file1;
            file1.open("highscore.txt");
            for(int i=0;i<5;i++) file1>>highScore[i];
            file1.close();
            handleEvents(quit,startgame,game,helb,settings,soundOn,musicOn,leaderboard,click);
            startPage(graphics,man,back1,start,adventuretime,setting,highscore,help,close,idle,helpTexture,settingbar,sound,soundon,soundoff,music,musicon,musicoff,closePage,helb,settings,soundOn,musicOn,leaderboard,highScore);
        }
        else{
        int scores1=0;
        int scores=0;
        dragon.x=3000;
        dragon.y=170;
        b1.x=-1000;
        b1.y=-1000;
        b1.dx=14;
        b1.dy=0;
        delta=0;
        background.speed=0;
        resetData(man,frog,monster,bat,crab,poi,as1,as2,as3,frame,poison,collision2,collision3,collision4,biteframecount,disappearcount,disappearcount2,over,counttodealth,jumptimes,quit);

    while( !quit ) {
        if(over)
        {

            ifstream file1;
            file1.open("highscore.txt");
            for(int i=0;i<5;i++) file1>>highScore[i];
            if(scores>highScore[4])
            {
                highScore[4]=scores;
                for(int i=0;i<5;i++)
                {
                    for(int j=0;j<5;j++)
                    {
                        if(highScore[i]>highScore[j]) swap(highScore[i],highScore[j]);
                    }
                }
            }
            file1.close();
            ofstream file2;
            file2.open("highscore.txt");
            for(int i=0;i<5;i++) file2<<highScore[i]<<" ";
            file2.close();
            intToCharArray(highScore[0],bScore);
            SDL_Color color = {0, 255, 0, 0};
            SDL_Texture* bscoreText = graphics.renderText(bScore, font, color);
            graphics.renderTexture(bscoreText, 530,420);
            overPage(graphics,gameover,restart,home,score,font);
            handleEvents2(quit,startgame,game,click);
        }
        else
        {
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT )
            {
                quit = true;
                game=false;
            }
            else if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
            {
                isPaused = !isPaused;
            }
        }
        if(!isPaused){
        frame++;//tinh so frame
        scores1++;
        if(scores1%500==0)
        {
            background.speed+=1;
            delta+=1;
        }
        if(frame==1500) frame=0;
        scores=scores1/5;
        intToCharArray(scores,score);
        SDL_Color color = {225, 0, 0, 0};
        SDL_Texture* scoreText = graphics.renderText(score, font, color);

        background.background1(graphics);
        crabMove(graphics,crab,boss2,laser,frame,gLaser,crabGrunt,dropBomb);
        background.background2(graphics);
        asteroidMove(graphics,asteroid,as1,as2,as3,frame,deathFlash);

        //player
        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

            if(currentKeyStates[SDL_SCANCODE_S]&&cooldown>=20&&!isattacking2&&!isattacking3)
        {
            isattacking=true;
        }
        else
        {
            cooldown++;
        }
        if(isattacking&&counttodealth==0)
        {
            if(frameCount==12) play(shoot);
            frameCount++;
            if(frameCount>=3&&frameCount<=10) man.x+=25;

            if(frameCount==23)
                {
                    b1.x=man.x;
                    b1.y=man.y;
                }
             if(frameCount==28)
            {
                frameCount=0;
                cooldown=0;
                isattacking=false;
            }
            if(frameCount<=14)graphics.render2(man.x,man.y,dash);
            if(frameCount>14) graphics.render2(man.x,man.y,attack);
            dash.tick();
            attack.tick();
        }

        if(currentKeyStates[SDL_SCANCODE_D]&&cooldown>=20&&!isattacking&&!isattacking2)
        {
            isattacking3=true;
        }
        else
        {
            cooldown++;
        }
        if(isattacking3&&counttodealth==0)
        {
            if(frameCount==0) play(shoot);
            frameCount++;

            if(frameCount==9)
                {
                    b1.x=man.x;
                    b1.y=man.y;
                }
             if(frameCount==14)
            {
                frameCount=0;
                cooldown=0;
                isattacking3=false;
            }
            graphics.render2(man.x,man.y,attack);
            attack.tick();
        }
        if(currentKeyStates[SDL_SCANCODE_A]&&cooldown>=20&&!isattacking&&!isattacking3&&!man.isFreefalling)
        {
            isattacking2=true;
        }
        else
        {
            cooldown++;
        }
        if(isattacking2&&counttodealth==0)
        {
            frameCount++;

             if(frameCount==28)
            {
                frameCount=0;
                cooldown=0;
                isattacking2=false;
            }
            graphics.render2(man.x,man.y,melee);
            melee.tick();
        }

        graphics.renderTexture(arrow,b1.x+70,b1.y+78);
        b1.move();
         if(isCollisionwithmonster(monster.x,monster.y+6,105,65,b1.x+57,b1.y+86,45,7)||isCollisionwithmonster(b1.x+57,b1.y+86,45,7,bat.x+20,bat.y+10,45,30)) play(arrowHit);
        playerCollision(graphics,man,bat,as1,as2,as3,monster,poi,collision2,collision3,counttodealth,fall1,gDeath,poisonImpact,death,poisonimpact,over);
        playerMove(graphics,delta,currentKeyStates,over,man,collision2,collision3,isattacking,isattacking2,isattacking3,run,jumptimes,gJump,jump,fall1,fall2);
        playerJump(graphics,man,jumptimes,falltimes,gFall,delta);
        //
          //monster
        frogMove(graphics,frog,man,poi,boss1,poisonattack,poisons,poisonimpact,boss1Texture,boss1_2Texture,poisonattackTexture,poisonTexture,poisonimpactTexture,frame,biteframecount,over,poison,frogGrunt,frogGrunt2);
        rhinoMove(graphics,delta,monster,frog,b1,rhino,poisonimpact,arrowImpact,rhinoTexture,rhinohitTexture,disappearcount,poi,frame,collision4,collision,as1,as2,as3,poisonImpact);
        batMove(graphics,delta,batman,arrowImpact,bat,frog,batTexture,bat2Texture,disappearcount2,as1,as2,as3,b1,collision);
        //
        if(b1.x>SCREEN_WIDTH) b1.x=3000;

        }


         SDL_Color color = {225, 0, 0, 0};
        SDL_Texture* scoreText = graphics.renderText(score, font, color);

        if(isPaused) {
            SDL_Texture* pressSpace = graphics.renderText("PRESS SPACE TO CONTINUE", font, color);
            graphics.renderTexture(pressSpace, 100,400);
        }
        if(!over) graphics.renderTexture(scoreText, 0,0);
        graphics.presentScene();
        SDL_Delay(35);
        }
            }
        }
    }

    background.destroyTextures();
    SDL_DestroyTexture( runTexture ); runTexture = nullptr;
    SDL_DestroyTexture( jumpTexture ); jumpTexture = nullptr;
    SDL_DestroyTexture( boss1Texture ); boss1Texture = nullptr;
    SDL_DestroyTexture( boss1_2Texture ); boss1_2Texture = nullptr;
    SDL_DestroyTexture( rhinoTexture ); rhinoTexture = nullptr;
    SDL_DestroyTexture( start); start = nullptr;
    graphics.quit();
    for(int i=0;i<5;i++) cout<<highScore[i]<<" ";
    return 0;
}
