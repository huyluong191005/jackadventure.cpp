#ifndef _DEFS__H
#define _DEFS__H


const int SCREEN_WIDTH = 811 ;
const int SCREEN_HEIGHT = 693;
const int safeDistance=200;
const int maxVolume=128;
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
const char* DEATH_SPRITE_FILE = "images\\Death.png";
const char* BAT_SPRITE_FILE = "images\\Flying (46x30).png";
const char* BOSS2_SPRITE_FILE = "images\\walk_look up.png";
const char* POISONATTACK_SPRITE_FILE = "images\\poison-attack.png";
const char* BAT2_SPRITE_FILE = "images\\Hit (46x30).png";
const char* POISON_SPRITE_FILE = "images\\poison-spit.png";
const char* POISONIMPACT_SPRITE_FILE = "images\\poison-impact.png";
const char* LASER_SPRITE_FILE = "images\\laser.png";
const char* ASTEROID_SPRITE_FILE = "images\\asteroid.png";
const char* IDLE_SPRITE_FILE = "images\\Idle.png";
const int IDLE_CLIPS[][4] = {
     {0,0,220,220},
    {220,0,220,220},
    {440,0,220,220},
    {660,0,220,220},
    {880,0,220,220},
    {1100,0,220,220},
    {1320,0,220,220},
    {1540,0,220,220}
};


const int ASTEROID_CLIPS[][4] = {
    {50,0,50,50},
    {0,0,50,50},
    {50,50,50,50}


};
const int LASER_CLIPS[][4] = {
    {0,0,182,500},
    {0,500,182,500},
    {0,1000,182,500},
    {0,1500,182,500},
    {0,2000,182,500},
    {0,2500,182,500}
};

const int POISONIMPACT_CLIPS[][4] = {
    {0,0,63,100},
    {63,0,63,100},
    {126,0,63,100},
    {189,0,63,100},
    {0,100,63,100},
    {63,100,63,100},
    {126,100,63,100},
    {189,100,63,100},
    {0,200,63,100},
    {63,200,63,100},
    {126,200,63,100},
    {189,200,63,100}
};

const int POISON_CLIPS[][4] = {

    {0,0,89,29},
    {89,0,89,29},
    {178,0,89,29},
    {267,0,89,29},
    {0,29,89,29},
    {89,29,89,29},
    {178,29,89,29},
    {267,29,89,29},
    {0,58,89,29},
    {89,58,89,29},
    {178,58,89,29},
    {267,58,89,29}

};

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
const int DEATH_CLIPS[][4] = {
    {0,0,220,220},
    {220,0,220,220},
    {440,0,220,220},
    {660,0,220,220},
    {880,0,220,220},
    {1100,0,220,220},
    {1320,0,220,220},
    {1540,0,220,220},
    {1760,0,220,220},
    {1980,0,220,220},
    {2200,0,220,220},
    {2420,0,220,220},
    {2640,0,220,220},
    {2860,0,220,220},
    {3080,0,220,220},
    {3300,0,220,220},
    {3520,0,220,220},
    {3740,0,220,220},
    {3960,0,220,220},
    {4180,0,220,220},
    {4400,0,220,220},
    {4620,0,220,220},
    {4840,0,220,220},
    {5060,0,220,220}

};
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
const int BOSS1_2_FRAMES = sizeof(BOSS1_2_CLIPS)/sizeof(int)/4;
const int JUMP_CLIPS[][4] = {
    {0,0,220,220},
    {220,0,220,220},
    {440,0,220,220},
    {660,0,220,220}

};
const int POISONATTACK_CLIPS[][4] = {

   {905,0,181,152},
   {724,0,181,152},
   {543,0,181,152},
   {362,0,181,152},
   {181,0,181,152},
   {0,0,181,152},
   {905,152,181,152},
   {724,152,181,152},
   {543,152,181,152},
   {362,152,181,152},
   {181,152,181,152},
   {0,152,181,152},
   {905,304,181,152},
   {724,304,181,152},
   {543,304,181,152},
   {362,304,181,152},
   {181,304,181,152}






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
const int BAT_CLIPS[][4] = {
   {0,0,75,49},
   {75,0,75,49},
   {150,0,75,49},
   {225,0,75,49},
   {300,0,75,49},
   {375,0,75,49},
   {450,0,75,49},
};
const int BAT2_CLIPS[][4] = {
   {0,0,75,49},
   {75,0,75,49},
   {150,0,75,49},
   {225,0,75,49},
   {300,0,75,49}

};
const int BOSS2_CLIPS[][4] = {

    {639,630,213,210},
    {426,630,213,210},
    {213,630,213,210},
    {0,630,213,210},
    {852,420,213,210},
    {639,420,213,210},
    {426,420,213,210},
    {213,420,213,210},
    {0,420,213,210},
    {852,210,213,210},
    {639,210,213,210},
    {426,210,213,210},
    {213,210,213,210},
    {0,210,213,210},
    {852,0,213,210},
    {639,0,213,210},
    {426,0,213,210},
    {213,0,213,210},
    {0,0,213,210}



};
const int RHINO_FRAMES = sizeof(RHINO_CLIPS)/sizeof(int)/4;

 #endif
