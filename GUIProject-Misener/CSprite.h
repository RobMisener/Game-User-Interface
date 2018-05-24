#ifndef CSPRITE_H
#define CSPRITE_H

#include "Character.h"
#include "LTexture.h"
#include "DisplayEStatBar.h"
#include "CSprite.h"

#include <sstream> // for
#include <ostream> // for

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <gl/gl.h>
#include <gl/glu.h>


#include <iostream>
#include <fstream>

#include <string>

//#include <unistd.h>// for usleep

#include <stdio.h>      // printf, scanf, puts, NULL */
#include <stdlib.h>     // srand, rand */
#include <time.h>       // time


//below is from main file I did years ago

#include <conio.h>
#include <Windows.h> 	//Sleep(1000)


#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <algorithm> //for *std::min_element(myints,myints+7)

#include <vector>

const int WALK_ANI_FRAMES = 60;

extern bool checkCollision( SDL_Rect a, SDL_Rect b );
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern SDL_Rect quadSpriteA;
extern SDL_Rect quadSpriteB;
extern SDL_Rect quadSpriteC;
extern SDL_Rect quadSpriteD;
extern SDL_Rect quadSpriteE;
extern SDL_Rect quadSpriteU1;
extern SDL_Rect quadSpriteU2;
extern SDL_Rect quadSpriteF;

extern int find_avg_to();

typedef void set_t;
typedef void controls_t;
typedef void render_t;
typedef int get_int_t;
typedef bool get_flag__t;
typedef void displayStatBar_t;
typedef void rectOutline_t;
typedef bool rectOutline_flag_t;
typedef void move_t;



extern int avg_ag();
extern int avg_am();
extern int avg_di();
extern int avg_lo();
extern int avg_re();

//extern Character a;
//extern Character b;
//extern Character c;
//extern Character d;
//extern Characte//recrods whether outline is on for characterr e;




class CommonSprite {

public:
    set_t setSprite(LTexture *sprite);//set texture to CSprite

    CommonSprite();//constructor

    bool animationComplete();//returns whether animation is complete

    int getPosX();//get position x of Sprite
    int getPosY();//get position y of Sprite
    int getWidth();//returns width of sprite quad
    int getHeight();//returns height of sprite quad

	int getFrameNum() {
		return frameNum;
	}


    set_t setPos(int x, int y);//set x and y position of sprite
    set_t setQuads(int w, int h, int r, int c, int spriteRow, bool horizontal);
    set_t setFrameNum(int whichFrame); //set the frame number
    set_t setTotalFrames(int fNum);

    controls_t freeze_final_frame(bool trueOrFalse);//determines whether or not the animation will freeze on final frame
    controls_t resetAnimation();
    controls_t reverseSetFrameNum();
    controls_t slow_clip_by(int x);

    render_t render_forward_reverse();//renders animation forward and backward like a gif
    render_t render (bool reverseRender);//render current sprite frame


	int frameNum;
    void printFrameNum();//print the current frame number of sprite
    void print_quad_cord();//print the coordinates of the q frame number of sprite

    void free();

private:

    LTexture *tSpriteSheet;

    SDL_Rect quadSprite[60];//quads for the sprite images

    bool reverseIsTrue; //flag for whether sprite should go iE reverse

    int slowClip;
    int slowClipNew;
    int nextClipNum;
    bool slowFrameOn;//flag that records whether slow frame is on
    bool animationFinished;//is animation finished


    bool buttonClicked;
    //x and y of image
    SDL_Point mPos;

    //The dimensions of the sprite

    int totalFrames;

    int quadWidth;
    int quadHeight;

    bool spriteAnimationComplete;
    bool freezeFrame;


    bool reverseSetFrameNum_firstTime;
    bool spriteAniComplete;
    bool frameReachedTotal;
};



// TODO (Rob#1#): why not just make cSprite a child of CommonSprite

class CSprite{
    public:


        CSprite();//constructor

        set_t setCharacter(Character *whichCharacter);//set the private Character to specific Character
        set_t setPos(int x, int y);//set position x and y of sprite
        set_t setTotalFrames(int fNum);//set total number of frames
        set_t setSprite(LTexture *sprite);//set texture to CSprite

        set_t boundary(int x, int y, int w, int h);//set boundary x,y,w,h
        set_t targetPlayer(bool trueOrNot);//function to set whether the player is selected
        //set collision walls -- not implemented?
        set_t setWalls(SDL_Rect *qa, SDL_Rect *qb, SDL_Rect *qc, SDL_Rect *qd, SDL_Rect *qe,SDL_Rect *qu1, SDL_Rect *qu2, SDL_Rect *qf );
        set_t setQuads(int w, int h, int r, int c, int spriteRow, bool horizontal);

        controls_t freeze_final_frame(bool trueOrFalse);//determines whether or not the animation will freeze on final frame
        controls_t resetAnimation();

        controls_t slow_clip_by(int x);

        get_int_t getPosX();//get position x of sprite
        get_int_t getPosY();//get position y of sprite
        get_flag__t isBoundaryClicked(); //is the boundary click
        get_flag__t isTargetPlayer();//function to return the private value that stores whether the player is selected

        //following functions are to display the e stats when right click on character
        displayStatBar_t clickDisplayStatBarEvent(SDL_Event *cd);
        displayStatBar_t change_clickDisplayStatBarEvent(bool changeTrue);

        rectOutline_t clickDisplayRectOutlineEvent(SDL_Event *eventRectOutline);
        rectOutline_t enable_clickDisplayRectOutlineEvent(bool isItTrue);
        rectOutline_t change_clickDisplayRectOutlineBool (bool changeButtonPress);
        rectOutline_flag_t get_clickDisplayRectOutlineEvent();//return whether the outline rect button is true;

        move_t movePos();//Moves the dot
        move_t moveNPC(int _direction, int _moveSpaces);//moves npcs

        void renderCSprite();
//
//        void render();//Shows the dot on the screen
        controls_t changeClick(bool changeClickTrueOrFalse);//modify flag status of click;

        void handleEvent( SDL_Event& e );//event handler for game loop

        void printPos();//print position of sprite on scren

        //i have no idea what this is for
        SDL_Rect currentLocBounds();//find the current boundary range and location of cSprite

        //bool isMainC;    <---  still used?

    private:
        LTexture *tSpriteSheet;
        int quad_Width;
        int quad_Height;
        SDL_Rect quadSprite[60];//quads for the sprite images

        int slowClip;
        int slowClipNew;
        int nextClipNum;

        int frameNum;
        //The dimensions of the sprite

        int totalFrames;

        int quadWidth;
        int quadHeight;

        bool spriteAnimationComplete;
        bool freezeFrame;

        bool reverseSetFrameNum_firstTime;

        bool spriteAniComplete;
        bool frameReachedTotal;

        bool slowFrameOn;//flag that records whether slow frame is on
        bool animationFinished;

        bool buttonClicked;


        SDL_Rect cBoundary;//boundary rectangle for collision detection

        bool outlineRectButtonTrue;//flag whether outline is on for character
        bool start_clickDisplayRectOutlineEvent;

        const int CVEL = 2;
        //stat bar to display e stats

        bool rightButtonClicked;

        Character *CharacterPtr;

        //The velocity of the sprite
        int velX, velY;

        //holds the direction and spaces the NPC will move
        int moveNPC_direction;
        int moveSpaces;



        //x and y of image
        SDL_Point mPos;

        int cSpriteWidth;
        int cSpriteHeight;

        bool playerTarget;

        //Dot's collision box
        SDL_Rect cCollision;
        SDL_Rect *wallArray[8];

        SDL_Rect currentLocationAndWidthHeight; //possibily a duplicate of C-Boundary

    };


#endif
