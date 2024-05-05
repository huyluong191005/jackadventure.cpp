#include "defs.h"
#include "graphics.h"
#include "background.h"
#include "monster.h"
#include "music.h"
#include "Initalize.h"
#include "startnoverpage.h"
#include "player.h"


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
    Sprite asteroid,asteroid2;
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
    SDL_Texture*sound; SDL_Texture*music;

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

    TTF_Font* font = graphics.loadFont("font\\youmurdererbb_reg.ttf", 81);

    char  score[20];
    char  bScore[20];
    Mouse man; man.x=300; man.y=225; man.isJumping=true; man.isFreefalling=false; man.speed=14;
    Mouse frog; frog.x=-350; frog.y=410; frog.speed=2;
    Mouse monster; monster.x=900; monster.y=570; monster.speed=5;
    Mouse bat; bat.x=1500; bat.y=400; bat.speed=7;
    Mouse crab; crab.x=-200; crab.y=415; crab.speed=5;
    Mouse poi; poi.x=-150; poi.y=570; poi.speed=4;
    Mouse as1; as1.x=350; as1.y=-70;
    Mouse as2; as2.x=50; as2.y=-150;
    Mouse as3; as3.x=500; as3.y=-200;
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
    int highScore[5];

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

        //player
        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
        playerCollision(graphics,man,bat,as1,as2,as3,monster,poi,collision2,collision3,counttodealth,fall1,gDeath,poisonImpact,death,poisonimpact,over);
        playerMove(graphics,currentKeyStates,over,man,collision2,collision3,run,jumptimes,gJump,jump,fall1,fall2);
        playerJump(graphics,man,jumptimes,falltimes,gFall);
        //
          //monster
        frogMove(graphics,frog,man,poi,boss1,poisonattack,poisons,poisonimpact,boss1Texture,boss1_2Texture,poisonattackTexture,poisonTexture,poisonimpactTexture,frame,biteframecount,over,poison,frogGrunt,frogGrunt2);
        rhinoMove(graphics,monster,frog,rhino,poisonimpact,rhinoTexture,rhinohitTexture,disappearcount,poi,frame,collision4,as1,as2,as3,poisonImpact);
        batMove(graphics,batman,bat,frog,batTexture,bat2Texture,disappearcount2,as1,as2,as3);
        //

        if(!over) graphics.renderTexture(scoreText, 0,0);
        graphics.presentScene();
        SDL_Delay(35);
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
    for(int i=0;i<5;i++) cout<<highScore[i]<<" ";
    return 0;
}
