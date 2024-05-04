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
void startPage(Graphics &graphics,Mouse &man,SDL_Texture*back1,SDL_Texture*start,SDL_Texture*adventuretime,SDL_Texture*setting,SDL_Texture*highscore,SDL_Texture*help,SDL_Texture*close,Sprite&idle,SDL_Texture*helpTexture,SDL_Texture*settingbar,SDL_Texture*sound,SDL_Texture*soundon,SDL_Texture*soundoff,SDL_Texture*music,SDL_Texture*musicon,SDL_Texture*musicoff,SDL_Texture*closePage,bool &helb,bool &settings,bool & soundOn,bool &musicOn)
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
void overPage(Graphics graphics,SDL_Texture*gameover,SDL_Texture*restart,SDL_Texture*home,char score[],TTF_Font* font)
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
}
#endif // STARTNOVERPAGE__H
