#ifndef STARTNOVERPAGE__H
#define STARTNOVERPAGE_H
#include "button.h"

void musicNsound(Graphics &graphics,bool &musicOn,bool &soundOn, Mix_Music *gMusic)
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
}
void startPage(Graphics &graphics,Mouse &man,SDL_Texture*back1,SDL_Texture*start,SDL_Texture*adventuretime,SDL_Texture*setting,SDL_Texture*highscore,SDL_Texture*help,SDL_Texture*close,Sprite&idle,SDL_Texture*helpTexture,SDL_Texture*settingbar,SDL_Texture*sound,SDL_Texture*soundon,SDL_Texture*soundoff,SDL_Texture*music,SDL_Texture*musicon,SDL_Texture*musicoff,SDL_Texture*closePage,bool &helb,bool &settings,bool & soundOn,bool &musicOn,bool &leaderboard,int highScore[])
{
            man.x=300;
            man.y=225;
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
                graphics.renderTexture(helpTexture,-30,0);
            }
             if(leaderboard)
            {
                SDL_Color color = {255, 255, 255, 0};
                TTF_Font* font = graphics.loadFont("font\\CollegiateFLF.ttf", 31);
                SDL_Texture* hscoreText = graphics.renderText("High score", font, color);
                graphics.renderTexture(hscoreText, 620,250);
                char score1[20],score2[20],score3[20],score4[20],score5[20];
                intToCharArray(highScore[0],score1);
                intToCharArray(highScore[1],score2);
                intToCharArray(highScore[2],score3);
                intToCharArray(highScore[3],score4);
                intToCharArray(highScore[4],score5);
                TTF_Font* font1 = graphics.loadFont("font\\CollegiateFLF.ttf", 26);
                SDL_Texture* score1Text = graphics.renderText(score1, font1, color);
                SDL_Texture* score2Text = graphics.renderText(score2, font1, color);
                SDL_Texture* score3Text = graphics.renderText(score3, font1, color);
                SDL_Texture* score4Text = graphics.renderText(score4, font1, color);
                SDL_Texture* score5Text = graphics.renderText(score5, font1, color);
                graphics.renderTexture(score1Text, 680,320);
                graphics.renderTexture(score2Text, 680,390);
                graphics.renderTexture(score3Text, 680,460);
                graphics.renderTexture(score4Text, 680,530);
                graphics.renderTexture(score5Text, 680,600);

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


            if(helb||settings||leaderboard) graphics.renderTexture(closePage,700,20);

            idle.tick();
            graphics.presentScene();
            SDL_Delay(35);
}
void overPage(Graphics graphics,SDL_Texture*gameover,SDL_Texture*restart,SDL_Texture*home,char score[],TTF_Font* font)
{
            graphics.renderTexture(gameover,-50,-100);
            graphics.renderTexture(restart,280,550);
            graphics.renderTexture(home,450,550);
            SDL_Color color = {225, 0, 225, 0};
            SDL_Texture* scoreText = graphics.renderText(score, font, color);
            SDL_Texture* yourScore = graphics.renderText("YOUR SCORE", font, color);
            SDL_Texture* bestScore = graphics.renderText("BEST SCORE", font, color);
            graphics.renderTexture(scoreText, 530,320);
            graphics.renderTexture(yourScore, 240,320);
            graphics.renderTexture(bestScore, 240,420);
            graphics.presentScene();
}
#endif // STARTNOVERPAGE__H
