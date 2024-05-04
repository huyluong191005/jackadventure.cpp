#ifndef _BUTTON__H
#define _BUTTON_H
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
void handleEvents2(bool& quit, bool& startGame,bool &game,Mix_Chunk *click) {
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
                play(click);
                break;
            }
            else if(mouseX >= 450 && mouseX <= 548 && mouseY >= 550 && mouseY <= 648)
            {
                startGame=false;
                quit=true;
                play(click);
                break;
            }

        }
    }
}
void intToCharArray(int number, char charArray[]) {
    std::string str = std::to_string(number);
    strcpy(charArray, str.c_str());
}
#endif // _BUTTON__H
