#ifndef DISPLAYESTATBAR_H
#define DISPLAYESTATBAR_H

#include "Character.h"
#include "LTexture.h"

#include <sstream> // for
#include <ostream> // for

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <iostream>
#include <fstream>

#include <string>

#include <stdio.h>      // printf, scanf, puts, NULL */
#include <stdlib.h>     // srand, rand */
#include <time.h>       // time

#include <conio.h>
#include <Windows.h> 	//Sleep(1000)

#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <algorithm> //for *std::min_element(myints,myints+7)

#include <vector>

extern const int emoRectWidth;
extern const int emoRectHeight;
extern SDL_Renderer* gRenderer;

class DisplayEStatBar
{
private:
	int modH;
	int modA;
	int modS;
	int modF;
	int modI;

	ETrait *whichChar;
	Character *whichChar_rel;

	int eRectHeight = 16;
	bool clearDisplay;

public:

	Character * getRelChar() {
		return whichChar_rel;
	}

	void setEChar(Character &whichCharacter);
	void renderStatBars(bool renderIt, int xLoc, int yLoc);
	void renderStatBars_large(int multiplier, int eRectHeight, int xLoc, int yLoc, int em, int subtract);

	void setGraphBackground(LTexture *enterTexture);
};

class DisplayRelStatBar
{
private:
	int relA;
	int relB;
	int relC;
	int relD;
	int relE;

	Character *whichChar_rel;
	int relRectHeight = 16;
	bool clearDisplay;
public:
	void setRelChar(Character *assign_whichChar_rel);
	void rel_renderStatBars(bool renderIt, int xLoc, int yLoc);
};

#endif


//copyright Robert Misener 2018
//www.RobertMisener.com