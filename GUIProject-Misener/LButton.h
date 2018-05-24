#ifndef LBUTTON_H
#define LBUTTON_H

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "LTexture.h"


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

extern Mix_Chunk *tHover;

//Screen dimension constants
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

//Button constants

extern const int TOTAL_BUTTONS;

extern LTexture gButtonSpriteSheetTexture;

extern SDL_Renderer* gRenderer;

enum LButtonSprite
{
	enChoice_BUTTON_SPRITE_MOUSE_OUT = 0,
	enChoice_BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	enChoice_BUTTON_SPRITE_MOUSE_DOWN = 2,
	enChoice_BUTTON_SPRITE_MOUSE_UP = 3,
	enChoice_BUTTON_SPRITE_TOTAL = 4
};

class CommonButton {
public:

	CommonButton();

	void setQuads();
	void howManyClips(int numOfClips);
	//Sets position and height
	void setPosition(int xx, int yy);
	void setWidthHeight(int w, int h);

	//Handles mouse event
	void handleEvent(SDL_Event* e);

	inline bool getButtonClickOn() {
		return buttonClickOn;
	}

	//void setSpriteSheet (string filename);


private:
	SDL_Rect SDL_Rect_gSpriteClips[10];

	int numberOfClips;

	struct buttonXYWH {
		int x;
		int y;
		int w;
		int h;
	}buttonXYWH;

	//Top left position
	SDL_Point mPosition;

	bool buttonClickOn;

	int currentSpriteEnumNumber;


};

//The mouse button
class LButton
{
public:
	//Initializes internal variables
	LButton();

	void setButtonClickon(bool isTrue);
	//Sets top left position
	void setPosition(int x, int y);
	int getPositionX();
	int getPositionY();

	//Handles mouse event
	void handleEvent(SDL_Event* e);

	//Shows button sprite
	void render();

	void setSpriteClips4(int x, int y, int w, int h);
	void setSpriteClips3(int x, int y, int w, int h);
	void setSpriteClips2(int x, int y, int w, int h);

	void setSpriteSheet(string filename);

	void free();

	SDL_Texture *gSpriteSheetTexture;
	//Mouse button sprites
	SDL_Rect SDL_Rect_gSpriteClips[enChoice_BUTTON_SPRITE_TOTAL];
	//SDL_Rect gSpriteClips2[ BUTTON_SPRITE_TOTAL ];
	int getWidth();
	int getHeight();

	void setWidthHeight(int w, int h);
	void printQuads(int howMany);

	bool reverseClick;

	bool getButtonClickOn();


private:
	//Top left position
	SDL_Point mPosition;
	bool buttonClickOn;

	//Currently used global sprite
	int enum_mCurrentSprite;
	int BUTTON_WIDTH;
	int BUTTON_HEIGHT;
	//Image dimensions
	int mWidth;
	int mHeight;

	int buttonClickNumber;
};


#endif

//copyright Robert Misener 2018
//www.RobertMisener.com
