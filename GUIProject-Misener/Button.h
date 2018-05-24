#ifndef Button_H
#define Button_H

#include "LTexture.h"
#include "tVariables.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <iostream>
#include <fstream>

#include <string>

using namespace std;

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


//Screen dimension constants
extern const int SCREEN_WIDTH ;
extern const int SCREEN_HEIGHT;



extern LTexture gButtonSpriteSheetTexture;

extern SDL_Renderer* gRenderer;


enum ButtonSprite1
{
	enChoice_BUTTON_SPRITE_MOUSE_OUT1 = 0,
	enChoice_BUTTON_SPRITE_MOUSE_OVER_MOTION1 = 1,
	enChoice_BUTTON_SPRITE_MOUSE_DOWN1 = 2,
	enChoice_BUTTON_SPRITE_MOUSE_UP1 = 3,
    numberOfClips = 4
};



//The mouse button
class Button
{
	public:


		//Initializes internal variables
		Button();

		//Sets top left position
		void setXY( int x, int y);

        void setSpriteSheet (string filename);

		//Handles mouse event
		void handleEvent( SDL_Event* e );

		//Shows button sprite
		void render();

        void setSpriteClips(int x, int y, int w, int h );

		bool buttonClick;



		void free();

		SDL_Texture *gSpriteSheetTexture;
		//Mouse button sprites
        SDL_Rect SDL_Rect_gSpriteClips[numberOfClips ];
        //SDL_Rect gSpriteClips2[ BUTTON_SPRITE_TOTAL ];
        int getWidth();
        int getHeight();

	private:
		//Top left position
		SDL_Point mPosition;

		//Currently used global sprite
		ButtonSprite1 enum_mCurrentSprite;

		    //Button constants
    int BUTTON_WIDTH;
    int BUTTON_HEIGHT;

    int BUTTON_CLIP_POSITION_X;
    int BUTTON_CLIP_POSITION_Y;

    int numberOfClips;

    int cropW;
    int cropH;

				//Image dimensions
		int mWidth;
		int mHeight;
};


#endif


//copyright Robert Misener 2018
//www.RobertMisener.com