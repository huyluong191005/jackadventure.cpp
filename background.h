#ifndef _BACKGROUND__H
#define _BACKGROUND__H

#include "graphics.h"
#include "defs.h"

void backtexture(Graphics &graphics,ScrollingBackground &layer1,ScrollingBackground &layer2,ScrollingBackground &layer3,ScrollingBackground &lights1,ScrollingBackground &layer4,ScrollingBackground &layer5,ScrollingBackground &lights2,ScrollingBackground &layer6,ScrollingBackground &layer7,ScrollingBackground &layer8,ScrollingBackground &layer9)
{
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
}

void background1(Graphics &graphics,ScrollingBackground &layer1,ScrollingBackground &layer2,ScrollingBackground &layer3,ScrollingBackground &lights1,ScrollingBackground &layer4,ScrollingBackground &layer5,ScrollingBackground &lights2)
{
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
}
void background2(Graphics graphics,ScrollingBackground &layer6,ScrollingBackground &layer8,ScrollingBackground &layer9)
{
       layer6.scroll(6);
        graphics.render(layer6);
        layer8.scroll(4);
        graphics.render(layer8);
        layer9.scroll(3);
        graphics.render(layer9);
}
void background3(Graphics &graphics,ScrollingBackground &layer7)
{
    layer7.scroll(4);
    graphics.render(layer7);
}
void destroybackground(Graphics &graphics,ScrollingBackground &layer1,ScrollingBackground &layer2,ScrollingBackground &layer3,ScrollingBackground &lights1,ScrollingBackground &layer4,ScrollingBackground &layer5,ScrollingBackground &lights2,ScrollingBackground &layer6,ScrollingBackground &layer7,ScrollingBackground &layer8,ScrollingBackground &layer9)
{
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
}



#endif // _BACKGROUND__H

