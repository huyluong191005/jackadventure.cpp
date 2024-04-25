#ifndef _DEFS__H
#define _DEFS__H


const int SCREEN_WIDTH = 811 ;
const int SCREEN_HEIGHT = 693;
const int safeDistance=200;
const char* WINDOW_TITLE = "JACK97";
const int GRAVITY =9;
const int ACC=1;
const int INITIAL_SPEED= 30;
const char* RUN_SPRITE_FILE = "images\\Run.png";
const char* JUMP_SPRITE_FILE = "images\\Jump.png";
const char* BOSS1_SPRITE_FILE = "images\\bossjump.png";
const char* BOSS1_2_SPRITE_FILE = "images\\bossbite.png";
const char* RHINO_SPRITE_FILE = "images\\Run(52x34).png";
const char* RHINOHIT_SPRITE_FILE = "images\\Hit(52x34).png";
const int RUN_CLIPS[][4] = {
    {0,0,220,220},
    {220,0,220,220},
    {440,0,220,220},
    {660,0,220,220},
    {880,0,220,220},
    {1100,0,220,220},
    {1320,0,220,220},
    {1540,0,220,220},
    {1760,0,220,220}
};
const int RUN_FRAMES = sizeof(RUN_CLIPS)/sizeof(int)/4;
const int BOSS1_CLIPS[][4] = {
    {304,492,304,246},
    {608,492,304,246},
    {912,492,304,246},
    {1216,492,304,246},
    {1520,492,304,246},
    {0,246,304,246},
    {304,246,304,246},
    {608,246,304,246},
    {912,246,304,246},
    {1216,246,304,246},
    {1520,246,304,246},
    {0,246,304,246},
    {304,0,304,246},
    {608,0,304,246},
    {912,0,304,246},
    {1216,0,304,246},
    {1520,0,304,246},

};
const int BOSS1_FRAMES = sizeof(BOSS1_CLIPS)/sizeof(int)/4;
const int BOSS1_2_CLIPS[][4] = {
    {304,492,304,246},
    {608,492,304,246},
    {912,492,304,246},
    {1216,492,304,246},
    {1520,492,304,246},
    {0,246,304,246},
    {304,246,304,246},
    {608,246,304,246},
    {912,246,304,246},
    {1216,246,304,246},
    {1520,246,304,246},
    {0,246,304,246},
    {304,0,304,246},
    {608,0,304,246},
    {912,0,304,246},
    {1216,0,304,246},
    {1520,0,304,246},

};
const int BOSS1_2_FRAMES = sizeof(BOSS1_CLIPS)/sizeof(int)/4;
const int JUMP_CLIPS[][4] = {
    {0,0,220,220},
    {220,0,220,220},
    {440,0,220,220},
    {660,0,220,220}

};

const int RHINO_CLIPS[][4] = {
    {0,0,107,70},
    {107,0,107,70},
    {214,0,107,70},
    {321,0,107,70},
    {428,0,107,70},
    {535,0,107,70}

};
const int RHINOHIT_CLIPS[][4] = {
    {0,0,107,70},
    {107,0,107,70},
    {214,0,107,70},
    {321,0,107,70},
    {428,0,107,70}

};
const int RHINO_FRAMES = sizeof(RHINO_CLIPS)/sizeof(int)/4;

 #endif
