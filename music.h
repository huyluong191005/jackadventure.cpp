#ifndef _MUSIC__H
#define _MUSIC__H

#include "graphics.h"

Mix_Music *loadMusic(const char* path)
    {
        Mix_Music *gMusic = Mix_LoadMUS(path);
        if (gMusic == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
                           SDL_LOG_PRIORITY_ERROR,
                "Could not load music! SDL_mixer Error: %s", Mix_GetError());
        }
        return gMusic;
    }
    void play(Mix_Music *gMusic)
    {
        if (gMusic == nullptr) return;

        if (Mix_PlayingMusic() == 0) {
            Mix_PlayMusic( gMusic, -1 );
        }
        else if( Mix_PausedMusic() == 1 ) {
            Mix_ResumeMusic();
        }
    }
  Mix_Chunk* loadSound(const char* path) {
        Mix_Chunk* gChunk = Mix_LoadWAV(path);
        if (gChunk == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
                           SDL_LOG_PRIORITY_ERROR,
               "Could not load sound! SDL_mixer Error: %s", Mix_GetError());
        }
    }
    void play(Mix_Chunk* gChunk) {
        if (gChunk != nullptr) {
            Mix_PlayChannel( -1, gChunk, 0 );
        }
    }
       void playSoundIfNotPlaying(Mix_Chunk* sound) {
    if (Mix_Playing(-1) == 0) {
        Mix_PlayChannel(-1, sound, 0);
    }
}
void adjustVolume(int change) {
    int volume = Mix_Volume(-1, -1);
    volume += change;
    if(volume < 0) volume = 0;
    if(volume > 128) volume = 128;
    Mix_Volume(-1, volume);
}
void setVolume(int volume) {
    if(volume < 0) volume = 0;
    if(volume > MIX_MAX_VOLUME) volume = MIX_MAX_VOLUME;
    Mix_Volume(-1, volume);
}
#endif
