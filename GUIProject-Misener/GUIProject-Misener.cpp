// _TOR_.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Character.h"
#include "CSprite.h"
#include "LButton.h"
#include "LTexture.h"
#include "DisplayEStatBar.h"
#include "attack.h"

#include "Thermometers.h"
#include "TTimer.h"

#include <sstream> // for
#include <ostream> // for

#include <windows.h>


#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h> //for sound

#include <iostream>
#include <fstream>

#include <string>

using namespace std;

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

std::stringstream timerText;

TTimer MyTimerFPS;

battleRound bRound1;

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;
//const SDL_Point SCREEN_CENTER = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};


const bool TURN_ON_FPS_COUNTER = false;
const bool TURN_ON_PRINT_X_Y_COORD = true;
const bool TURN_ON_PIXEL_GRAPH = false;
//record rectangle size from mouse up and mouse down
const bool TURN_ON_BOX_RECORD = false;
const bool TURN_ON_PLAYMUSIC = true;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
//The window renderer
SDL_Renderer* gRenderer = NULL;

//Globally used font
TTF_Font *gFont = NULL;

Mix_Music *tMusic = NULL;

//holds character color values
typedef struct colorValues {
	int x;
	int y;
	int z;
}colorValues;

colorValues text_set_color(int broNum);

Character a, b, c, d, e;
Character u1, u2, f;
Character *charBroPtrArray[5] = { &a,&b,&c,&d,&e };

ETrait *ea, *eb, *ec, *ed, *ee;
ETrait *emoBroPtrArray[5] = { ea,eb,ec,ed,ee };

Relationship_Thermometers RelThermo_A, RelThermo_B, RelThermo_C, RelThermo_D, RelThermo_E;
Relationship_Thermometers *RelThermo_Ptr_Array[5]{ &RelThermo_A, &RelThermo_B, &RelThermo_C, &RelThermo_D, &RelThermo_E };

E_Thermometers EThermo_A, EThermo_B, EThermo_C, EThermo_D, EThermo_E;
E_Thermometers *EmoThermo_Ptr_Array[5]{ &EThermo_A, &EThermo_B, &EThermo_C, &EThermo_D, &EThermo_E };

Motivation_Thermometers MotiThermo_A, MotiThermo_B, MotiThermo_C, MotiThermo_D, MotiThermo_E;

DetermineMotivation dmA, dmB, dmC, dmD, dmE;

typedef LTexture LTcharSprite;
typedef LTexture LTtitle;
typedef LTexture LTgraph;

//Title Screen
LButton bStartButton;
LButton bExitButton;

LTtitle tTitleBackground;
LTtitle tButtonBox;

LTtitle tBlankTitleBox;
LTtitle tTitleAnimation;

LTexture tPortrait_icons_movement_122x122_A;
LTexture tPortrait_icons_movement_122x122_B;
LTexture tPortrait_icons_movement_122x122_C;
LTexture tPortrait_icons_movement_122x122_D;
LTexture tPortrait_icons_movement_122x122_E;

CommonSprite sTitleSprite;
CommonSprite sPortraitIconsMovement_122x122_A;
CommonSprite sPortraitIconsMovement_122x122_B;
CommonSprite sPortraitIconsMovement_122x122_C;
CommonSprite sPortraitIconsMovement_122x122_D;
CommonSprite sPortraitIconsMovement_122x122_E;

//LTEXTURES
LTexture menu_icons;
LTexture DialogueBox_1600x50;

/////////e and Relation Graphs and Window
LTgraph tor_E_graph_150_232;
LTgraph tor_R_graph_150_232;
LTgraph sqaure_window_RELemo_Info_480wh;
//////////END
LTgraph large_bar_e_graph;

LTexture bg_green1;

LTexture hE_alpha;
LTexture aE_alpha;
LTexture sE_alpha;
LTexture fE_alpha;
LTexture iE_alpha;


LTexture sqaure_window_480x480;
LTexture SheildTemp1;

//Rendered text
LTexture tTextTexture;
LTexture tTextTurnorder;
LTexture tTextTextureStats[3];
LTexture tTextTextureBoxSelectSize;
LTexture tTextTimeTexture;
LTexture tTopicTexture[3];

//SPRITES

LTcharSprite tSprite_a;
LTcharSprite tSprite_b;
LTcharSprite tSprite_c;
LTcharSprite tSprite_d;
LTcharSprite tSprite_e;
//array for easy cleanup
LTexture *array_tSprites[5] = { &tSprite_a,&tSprite_b,&tSprite_c,&tSprite_d,&tSprite_e };

LTexture portraitTurnOrder[5];


//sprites of Characters

CSprite sRo;
CSprite sRa;
CSprite sJo;
CSprite sSte;
CSprite sGe;
CSprite sUn;
CSprite sU2;
//array for easy cleanup
CSprite *array_cCSprites[5] = { &sRo,&sRa,&sJo,&sGe,&sSte };

//Display Graphs 
DisplayEStatBar deBarRobert;
DisplayEStatBar deBarRanulf;
DisplayEStatBar deBarJohn;
DisplayEStatBar deBarStephen;
DisplayEStatBar deBarGeoffrey;
DisplayRelStatBar drBarRobert;
DisplayRelStatBar drBarRanulf;
DisplayRelStatBar drBarJohn;
DisplayRelStatBar drBarStephen;
DisplayRelStatBar drBarGeoffrey;



//SDL_Point find_center_rect (SDL_Point *whichSDL_POINT ,int ww, int hh);
int find_avg_lo();
int find_avg_ag();
int find_avg_am();
int find_avg_em();
int find_avg_di();
int find_avg_de();
int find_avg_re();
int find_avg_to();
int find_avg_rel();

bool GENERATE_INITIAL_STATS();
void GENERATE_initial_values();
void GENERATE_birth_order();

void GUAGE_THERMOS_Emo(Character *GuageThermosEmoChar);
void GUAGE_THERMOS_Motiv(Character *GuageThermosMotivChar);

bool sort_low_to_high_pairSecond(pair<int, int>& firstElem, pair<int, int>& secondElem) {
	return (firstElem.second < secondElem.second);
}

bool sort_high_to_low_pairSecond(pair<int, int>& firstElem, pair<int, int>& secondElem) {
	return (firstElem.second > secondElem.second);
}

bool sort_low_to_high_pairFirst(pair<int, int>& firstElem, pair<int, int>& secondElem) {
	return (firstElem.first < secondElem.first);
}
bool sort_high_to_low_pairFirst(pair<int, int>& firstElem, pair<int, int>& secondElem) {
	return (firstElem.first > secondElem.first);
}

void MOD_physical_relMods();
template<class T, class U>
bool MOD_assign_xyz(int Y_Xplus, T *x, U *y, int X_Yplus);
bool MOD_sameRels();//modify relationships based on similar Relationships
bool MOD_sameTraits();//modify relationships based on similar traits

int  FIND_Bro_num(Character *findBro);
Character *find_Bro_address(int enterNum);

int FIND_rel_value_of_XY(Character *theJudger, Character *charArrayCalcAnimosity);

bool R_titleScreen();
bool R_Scene1();
bool R_r_Windows_EmoStats();

bool R_r_PortraitMovement();

bool R_r_GUI_turnOrder();
bool R_r_Battle_text();
bool R_r_Timer_text();
bool  R_pixel_overlay();
bool R_r_FPS();

void Z_Close_R_titleScreen();

int xPixelPoint[SCREEN_WIDTH];
int yPixelPoint[SCREEN_HEIGHT];
bool GENERATE_pixel_points();

void T_ty(Character *talking, string enterText);
void T_ty_mPos(Character *talking, string enterText);

void set_to_neg1();

bool Z_init(); //Start up SDL and create window
bool Z_z_init_GlobalVariables();

bool Z_LOADMEDIA(); //Load media
bool Z_loadTitleMenu();

bool Z_LOADMEDIA_loadCharacters();
bool Z_LOADMEDIA_loadBackgrounds();
bool Z_LOADMEDIA_loadGUI();

bool Z_LOADMEDIA_loadPortraits();
bool Z_LOADMEDIA_loadGraphs();
bool Z_loadSound();

void Z_Close();

const int PIXEL_GRID_SIZE = 10;
int X_mousePosPixel;
int Y_mousePosPixel;
int DOWNrecordMouseState_X;
int DOWNrecordMouseState_Y;
int UPrecordMouseState_X;
int UPrecordMouseState_Y;
int BOXSIZErecordMouseState_X;
int BOXSIZErecordMouseState_Y;

bool BUTTONDOWNrecordMouseState_X;


int main(int argc, char* args[]) {

	vector <bool> boolVect1 = { false,false,false,false };
	boolVect1[3] = 0;
	int ash = true;
	cout << ash;
	boolVect1[2] = true;

	//if pixel grid is turned on generate pixel points for grid
	if (TURN_ON_PIXEL_GRAPH == true)GENERATE_pixel_points();

	//set names

	bool quit = false; //Main loop flag
	bool quit_title = false;

	int yyyyyy = false;

	SDL_Event event; //Event handler

	Z_init(); //Start up SDL and create window
	Z_z_init_GlobalVariables();
	Z_LOADMEDIA(); //Load media

	bRound1.step00_setDetermineMotivationPointers(&dmA, &dmB, &dmC, &dmD, &dmE);

	bRound1.step0_calc_ap_and_assign_new_values();
	bRound1.step1_assignTurnOrder();
	bRound1.step1b_assign_TO_into_DM();


	if (TURN_ON_PLAYMUSIC == true) Mix_PlayMusic(tMusic, -1);

	while (!quit)
	{

		if (!quit_title) {
			//Handle events on queue
			while (SDL_PollEvent(&event) != 0)
			{
				//User requests quit
				if (event.type == SDL_QUIT)quit = true;

				bStartButton.handleEvent(&event);
				bExitButton.handleEvent(&event);
			}

			if (bStartButton.getButtonClickOn() == true) {
				//render title screen
				quit_title = true;
				Z_Close_R_titleScreen(); //free texturesl
			}
			//if exit button clicked, initiate close and quit
			if (bExitButton.getButtonClickOn() == true) {
				Z_Close();
				quit = true;
			}

			R_titleScreen();
		}

		//if start button clicked start game
		if (bStartButton.getButtonClickOn() == true)
		{
			SDL_Event start_ev;//ev loop that occurs once start is pressed
			bool quit_start_ev = false;//flag to end start_ev loop

			//the start button pressed loop
			while (SDL_PollEvent(&start_ev) != 0)
			{
				SDL_GetMouseState(&X_mousePosPixel, &Y_mousePosPixel);
				//if User requests quit
				if (start_ev.type == SDL_QUIT) {
					quit_start_ev = true;
				}
				//insert character event handlers here

				//MyTimer.get_keypresses(&start_ev);
				if (TURN_ON_FPS_COUNTER == true)MyTimerFPS.get_keypresses(&start_ev);
			}

			SDL_RenderClear(gRenderer);

			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

			R_Scene1();

			SDL_RenderPresent(gRenderer);
			if (TURN_ON_FPS_COUNTER == true)MyTimerFPS.inceaseFrame();

		}

	}

	Z_Close();
	return 0;
}

int find_avg_lo() {
	int avg = (a.t.lo + b.t.lo + c.t.lo + d.t.lo + e.t.lo + u1.t.lo + u2.t.lo) / 7;
	return avg;
}
int find_avg_ag() {
	int avg = (a.t.ag + b.t.ag + c.t.ag + d.t.ag + e.t.ag + u1.t.ag + u2.t.ag) / 7;
	return avg;
}
int find_avg_am() {
	int avg = (a.t.am + b.t.am + c.t.am + d.t.am + e.t.am + u1.t.am + u2.t.am) / 7;
	return avg;
}
int find_avg_em() {
	int avg = (a.t.em + b.t.em + c.t.em + d.t.em + e.t.em + u1.t.em + u2.t.em) / 7;
	return avg;
}
int find_avg_di() {
	int avg = (a.t.di + b.t.di + c.t.di + d.t.di + e.t.di + u1.t.di + u2.t.di) / 7;
	return avg;
}
int find_avg_de() {
	int avg = (a.t.de + b.t.de + c.t.de + d.t.de + e.t.de + u1.t.de + u2.t.de) / 7;
	return avg;
}
int find_avg_re() {
	int avg = (a.t.re + b.t.re + c.t.re + d.t.re + e.t.re) / 5;
	return avg;
}
int find_avg_to() {
	int avg;
	avg = (a.to + b.to + c.to + d.to + e.to) / 5;
	return avg;
}
int find_avg_rel() {

	int value = ((((a.r.bb + a.r.cc + a.r.dd + a.r.ee) / 4) + ((b.r.aa + b.r.cc + b.r.dd + b.r.ee) / 4) + ((c.r.aa + c.r.bb + c.r.dd + c.r.ee) / 4) + ((d.r.aa + d.r.bb + d.r.cc + d.r.ee) / 4) + ((e.r.aa + e.r.bb + e.r.cc + e.r.dd) / 4)) / 5);
	return value;
}

bool GENERATE_INITIAL_STATS() {
	SDL_Event _GENERATE_INITIAL_STATS;
	SDL_PollEvent(&_GENERATE_INITIAL_STATS);
	printf("Start GENERATE_INITIAL_STATS()........ \n");
	bool success = true;

	GENERATE_initial_values();
	GENERATE_birth_order();

	MOD_physical_relMods();
	MOD_sameTraits();
	MOD_sameRels();

	//initialize and polymorphize em pointers
	for (int i = 0; i < 5; i++) {
		emoBroPtrArray[i] = charBroPtrArray[i];
	}

	//set initial emptional values of e objects by their traits
	for (int i = 0; i < 5; i++) {
		emoBroPtrArray[i]->setInitialValues(charBroPtrArray[i]->t.di, charBroPtrArray[i]->t.ag, charBroPtrArray[i]->t.em, charBroPtrArray[i]->t.de, charBroPtrArray[i]->t.lo);
	}
	////////Xxxxxxxxxxxxxxxxxxxxxxx END Generate Initial et xxxxxxxxxxxxxxx////////////

	printf("........End GENERATE_INITIAL_STATS() \n");
	return success;
}

void GENERATE_birth_order() {
	SDL_Event _GENERATE_birth_order;
	SDL_PollEvent(&_GENERATE_birth_order);

	printf("Start GENERATE_birth_order()........ \n");
	Character *charPtrArray[5] = { &a,&b,&c,&d,&e };
	Character *birthOrderNum_1 = NULL;
	Character *birthOrderNum_2 = NULL;
	Character *birthOrderNum_3 = NULL;
	Character *birthOrderNum_4 = NULL;
	Character *birthOrderNum_5 = NULL;

	//use birth order function iE character to assign to birthOrderNum pointers which record iE order the birth order
	for (int i = 0; i < 5; i++) {

		int x = charPtrArray[i]->birthOrder();

		if (x == 1)birthOrderNum_1 = charPtrArray[i];
		else if (x == 2) birthOrderNum_2 = charPtrArray[i];
		else if (x == 3) birthOrderNum_3 = charPtrArray[i];
		else if (x == 4) birthOrderNum_4 = charPtrArray[i];
		else if (x == 5) birthOrderNum_5 = charPtrArray[i];
	}

	//modify relationships according to birthorder
	MOD_assign_xyz(-4, birthOrderNum_1, birthOrderNum_2, -3);
	MOD_assign_xyz(2, birthOrderNum_1, birthOrderNum_3, 2);
	MOD_assign_xyz(2, birthOrderNum_1, birthOrderNum_4, 3);
	MOD_assign_xyz(3, birthOrderNum_1, birthOrderNum_5, 4);

	//modify trait stats according to birthorder
	birthOrderNum_1->t.lo -= 1;
	birthOrderNum_1->t.ag -= 1;
	birthOrderNum_1->t.am += 2;
	birthOrderNum_1->t.em -= 1;
	birthOrderNum_1->t.di += 1;
	birthOrderNum_1->t.de -= 1;
	birthOrderNum_1->t.re += 4;


	MOD_assign_xyz(2, birthOrderNum_2, birthOrderNum_3, 2);
	MOD_assign_xyz(1, birthOrderNum_2, birthOrderNum_4, 1);
	MOD_assign_xyz(-1, birthOrderNum_2, birthOrderNum_5, -1);

	birthOrderNum_2->t.lo -= 1;
	birthOrderNum_2->t.ag += 3;
	birthOrderNum_2->t.am += 4;
	birthOrderNum_2->t.em -= 1;
	birthOrderNum_2->t.di -= 2;
	birthOrderNum_2->t.de -= 2;
	birthOrderNum_2->t.re += 2;

	MOD_assign_xyz(3, birthOrderNum_3, birthOrderNum_4, 3);
	MOD_assign_xyz(2, birthOrderNum_3, birthOrderNum_5, 2);

	birthOrderNum_3->t.lo += 1;
	birthOrderNum_3->t.ag -= 1;
	birthOrderNum_3->t.am += 1;
	birthOrderNum_3->t.em += 1;
	birthOrderNum_3->t.di += 4;
	birthOrderNum_3->t.de += 0;
	birthOrderNum_3->t.re += 1;

	MOD_assign_xyz(4, birthOrderNum_4, birthOrderNum_5, 4);

	birthOrderNum_4->t.lo += 3;
	birthOrderNum_4->t.ag += 3;
	birthOrderNum_4->t.am += 2;
	birthOrderNum_4->t.em -= 2;
	birthOrderNum_4->t.di += 2;
	birthOrderNum_4->t.de += 4;
	birthOrderNum_5->t.re -= 1;

	birthOrderNum_5->t.lo += 4;
	birthOrderNum_5->t.ag += 2;
	birthOrderNum_5->t.am += 2;
	birthOrderNum_5->t.em -= 2;
	birthOrderNum_5->t.di += 2;
	birthOrderNum_5->t.de += 2;
	birthOrderNum_5->t.re -= 3;

}

void GENERATE_initial_values() {
	SDL_Event _GENERATE_initial_values;
	SDL_PollEvent(&_GENERATE_initial_values);

	srand(time(0));
	Character *a1 = &a;
	Character *b1 = &b;
	Character *c1 = &c;
	Character *d1 = &d;
	Character *e1 = &e;
	Character *u_1 = &u1;
	Character *u_2 = &u2;

	//determine father personality
	int fatherEmp = rand() % 3 + 1;
	int fatherAgg = rand() % 3 + 1;
	int fatherDip = rand() % 3 + 1;
	int fatherAmb = rand() % 3 + 1;
	int fatherDec = rand() % 3 + 1;
	int fatherLog = rand() % 3 + 1;

	if (fatherEmp == 1) {
		f.t.em = 25;
	}
	else if (fatherEmp == 2) {
		f.t.em = 50;
	}
	else if (fatherEmp == 3) {
		f.t.em = 75;
	}

	if (fatherAgg == 1) {
		f.t.ag = 25;
	}
	else if (fatherAgg == 2) {
		f.t.ag = 50;
	}
	else if (fatherAgg == 3) {
		f.t.ag = 75;
	}

	if (fatherDip == 1) {
		f.t.di = 25;
	}
	else if (fatherDip == 2) {
		f.t.di = 50;
	}
	else if (fatherDip == 3) {
		f.t.di = 75;
	}

	if (fatherAmb == 1) {
		f.t.am = 25;
	}
	else if (fatherAmb == 2) {
		f.t.am = 50;
	}
	else if (fatherAmb == 3) {
		f.t.am = 75;
	}

	if (fatherDec == 1) {
		f.t.de = 25;
	}
	else if (fatherDec == 2) {
		f.t.de = 50;
	}
	else if (fatherDec == 3) {
		f.t.de = 75;
	}
	if (fatherLog == 1) {
		f.t.lo = 25;
	}
	else if (fatherLog == 2) {
		f.t.lo = 50;
	}
	else if (fatherLog == 3) {
		f.t.lo = 75;
	}

	Character *humPtrArray[7] = { a1,b1,c1,d1,e1,u_1,u_2 };

	for (int i = 0; i < 7; i++) {

		//Set traits, relationships, names, and physical features to random values
		humPtrArray[i]->r.aa = 50;
		humPtrArray[i]->r.bb = 50;
		humPtrArray[i]->r.cc = 50;
		humPtrArray[i]->r.dd = 50;
		humPtrArray[i]->r.ee = 50;
		humPtrArray[i]->r.uu1 = 50;
		humPtrArray[i]->r.uu2 = 50;

		humPtrArray[i]->t.lo = 30;
		humPtrArray[i]->t.am = 30;
		humPtrArray[i]->t.ag = 30;
		humPtrArray[i]->t.de = 30;
		humPtrArray[i]->t.em = 30;
		humPtrArray[i]->t.di = 30;
		humPtrArray[i]->t.null = 0;
		humPtrArray[i]->t.null2 = 0;
		humPtrArray[i]->t.null3 = 0;
		humPtrArray[i]->t.null4 = 0;


		//set features
		humPtrArray[i]->featuresNum.h1 = rand() % 5 + 1;
		humPtrArray[i]->featuresNum.h2 = rand() % 3 + 1;
		humPtrArray[i]->featuresNum.e1 = rand() % 5 + 1;
		humPtrArray[i]->featuresNum.e2 = rand() % 5 + 1;
		humPtrArray[i]->featuresNum.n1 = rand() % 3 + 1;
		humPtrArray[i]->featuresNum.n2 = rand() % 3 + 1;
		humPtrArray[i]->featuresNum.n3 = rand() % 2 + 1;
		humPtrArray[i]->featuresNum.ht1 = rand() % 3 + 1;
		humPtrArray[i]->featuresNum.ht2 = rand() % 3 + 1;
		humPtrArray[i]->featuresNum.ht3 = rand() % 3 + 1;
		humPtrArray[i]->featuresNum.c1 = rand() % 3 + 1;
		humPtrArray[i]->featuresNum.c2 = rand() % 5 + 1;
		humPtrArray[i]->featuresNum.b1 = rand() % 4 + 1;
		humPtrArray[i]->featuresNum.b2 = rand() % 5 + 1;
		humPtrArray[i]->featuresNum.ea1 = rand() % 3 + 1;
		humPtrArray[i]->featuresNum.j1 = rand() % 3 + 1;
		humPtrArray[i]->featuresNum.v1 = rand() % 5 + 1;
		humPtrArray[i]->featuresNum.ck1 = rand() % 3 + 1;


		switch (humPtrArray[i]->featuresNum.h1) {
		case 1:
			humPtrArray[i]->features.ha = "He has light brown, ";
			break;
		case 2:
			humPtrArray[i]->features.ha = "He has dark brown, ";
			break;
		case 3:
			humPtrArray[i]->features.ha = "He has black, ";
			break;
		case 4:
			humPtrArray[i]->features.ha = "He has red, ";
			break;
		case 5:
			humPtrArray[i]->features.ha = "He has blonde, ";
			break;
		}

		switch (humPtrArray[i]->featuresNum.h2) {
		case 1:
			humPtrArray[i]->features.hb = "long hair. ";
			break;
		case 2:
			humPtrArray[i]->features.hb = "short hair. ";
			break;
		case 3:
			humPtrArray[i]->features.hb = "medium length hair. ";
			break;
		}

		switch (humPtrArray[i]->featuresNum.e1) {
		case 1:
			humPtrArray[i]->features.eca = "He has blue, ";
			break;
		case 2:
			humPtrArray[i]->features.eca = "He has brown, ";
			break;
		case 3:
			humPtrArray[i]->features.eca = "He has blue, ";
			break;
		case 4:
			humPtrArray[i]->features.eca = "He has hazel, ";
			break;
		case 5:
			humPtrArray[i]->features.eca = "He has green, ";
			break;
		}

		switch (humPtrArray[i]->featuresNum.e2) {
		case 1:
			humPtrArray[i]->features.ecb = "large eyes. ";
			break;
		case 2:
			humPtrArray[i]->features.ecb = "squinty eyes. ";
			break;
		case 3:
			humPtrArray[i]->features.ecb = "small eyes. ";
			break;
		case 4:
			humPtrArray[i]->features.ecb = "sleepy eyes. ";
			break;
		case 6:
			humPtrArray[i]->features.ecb = "beady eyes. ";
			break;
		}

		switch (humPtrArray[i]->featuresNum.n1) {
		case 1:
			humPtrArray[i]->features.na = "He has an upturned, ";
			break;
		case 2:
			humPtrArray[i]->features.na = "He has a downturned, ";
			break;
		case 3:
			humPtrArray[i]->features.na = "He has an straight, ";
			break;
		}

		switch (humPtrArray[i]->featuresNum.n2) {
		case 1:
			humPtrArray[i]->features.nb = "long,";
			break;
		case 2:
			humPtrArray[i]->features.nb = "short, ";
			break;
		case 3:
			humPtrArray[i]->features.nb = "medium sized, ";
			break;
		}

		switch (humPtrArray[i]->featuresNum.n3) {
		case 1:
			humPtrArray[i]->features.nc = "and well defined nose. ";
			break;
		case 2:
			humPtrArray[i]->features.nc = "and softly featured nose. ";
			break;
		}
		switch (humPtrArray[i]->featuresNum.ht1) {
		case 1:
			humPtrArray[i]->features.hta = "He is tall, ";
			humPtrArray[i]->t.lo -= 1;
			humPtrArray[i]->t.ag -= 1;
			humPtrArray[i]->t.am += 3;
			humPtrArray[i]->t.em -= 2;
			humPtrArray[i]->t.di += 2;
			humPtrArray[i]->t.de -= 2;
			humPtrArray[i]->t.re += 3;
			break;
		case 2:
			humPtrArray[i]->features.hta = "He is medium sized, ";
			humPtrArray[i]->t.lo += 1;
			humPtrArray[i]->t.ag += 0;
			humPtrArray[i]->t.am += 2;
			humPtrArray[i]->t.em += 0;
			humPtrArray[i]->t.di += 1;
			humPtrArray[i]->t.de += 0;
			humPtrArray[i]->t.re += 0;
			break;
		case 3:
			humPtrArray[i]->features.hta = "He is shorter than most, ";
			humPtrArray[i]->t.lo += 2;
			humPtrArray[i]->t.ag += 3;
			humPtrArray[i]->t.am += 1;
			humPtrArray[i]->t.em += 2;
			humPtrArray[i]->t.di -= 2;
			humPtrArray[i]->t.de += 3;
			humPtrArray[i]->t.re -= 2;
			break;
		}


		switch (humPtrArray[i]->featuresNum.ht2) {
		case 1:
			humPtrArray[i]->features.htb = "with broad shoulders, ";
			humPtrArray[i]->t.ag += 1;
			humPtrArray[i]->t.am += 1;
			humPtrArray[i]->t.de -= 1;
			humPtrArray[i]->t.re += 1;
			humPtrArray[i]->t.lo -= 1;
			humPtrArray[i]->t.em -= 1;
			humPtrArray[i]->t.di += 1;
			break;
		case 2:
			humPtrArray[i]->features.htb = "with medium shoulders, ";
			humPtrArray[i]->t.ag += 0;
			humPtrArray[i]->t.am += 0;
			humPtrArray[i]->t.de += 0;
			humPtrArray[i]->t.re += 0;
			humPtrArray[i]->t.lo += 0;
			humPtrArray[i]->t.em -= 1;
			humPtrArray[i]->t.di += 2;
			break;
		case 3:
			humPtrArray[i]->features.htb = "with narrow shoulders, ";
			humPtrArray[i]->t.ag -= 1;
			humPtrArray[i]->t.am += 1;
			humPtrArray[i]->t.de += 2;
			humPtrArray[i]->t.re -= 1;
			humPtrArray[i]->t.lo += 1;
			humPtrArray[i]->t.em -= 1;
			humPtrArray[i]->t.di -= 1;
			break;
		}

		switch (humPtrArray[i]->featuresNum.ht3) {
		case 1:
			humPtrArray[i]->features.htc = "and a wide waist. ";
			humPtrArray[i]->t.ag += 0;
			humPtrArray[i]->t.am -= 1;
			humPtrArray[i]->t.de -= 1;
			humPtrArray[i]->t.re -= 1;
			humPtrArray[i]->t.lo += 1;
			humPtrArray[i]->t.em += 1;
			humPtrArray[i]->t.di += 1;
			break;
		case 2:
			humPtrArray[i]->features.htc = "and a medium waist. ";
			humPtrArray[i]->t.ag += 1;
			humPtrArray[i]->t.am += 1;
			humPtrArray[i]->t.de += 0;
			humPtrArray[i]->t.re += 1;
			humPtrArray[i]->t.lo += 0;
			humPtrArray[i]->t.em -= 0;
			humPtrArray[i]->t.di += 1;
			break;
		case 3:
			humPtrArray[i]->features.htc = "and a narrow waist. ";
			humPtrArray[i]->t.ag -= 1;
			humPtrArray[i]->t.am += 0;
			humPtrArray[i]->t.de += 1;
			humPtrArray[i]->t.re -= 1;
			humPtrArray[i]->t.lo += 1;
			humPtrArray[i]->t.em -= 0;
			humPtrArray[i]->t.di -= 1;
			break;
		}
		switch (humPtrArray[i]->featuresNum.c1) {
		case 1:
			humPtrArray[i]->features.ca = "He has a large chin that ";
			break;
		case 2:
			humPtrArray[i]->features.ca = "He has a small chin that ";
			humPtrArray[i]->t.de += 1;
			break;
		case 3:
			humPtrArray[i]->features.ca = "He has a medium sized chin that ";
			humPtrArray[i]->t.di += 1;
			break;
		}
		switch (humPtrArray[i]->featuresNum.c2) {
		case 1:
			humPtrArray[i]->features.cb = "receeds backward. ";
			humPtrArray[i]->t.em -= 1;
			break;
		case 2:
			humPtrArray[i]->features.cb = "tilts forward. ";
			break;
		case 3:
			humPtrArray[i]->features.cb = "is pointy. ";
			break;
		case 4:
			humPtrArray[i]->features.cb = "is broad. ";
			humPtrArray[i]->t.di += 1;
			break;
		case 5:
			humPtrArray[i]->features.cb = "is round. ";
			break;
		}
		switch (humPtrArray[i]->featuresNum.b1) {
		case 1:
			humPtrArray[i]->features.ba = "He has bushy, ";
			break;
		case 2:
			humPtrArray[i]->features.ba = "He has thin, ";
			break;
		case 3:
			humPtrArray[i]->features.ba = "He has long, ";
			break;
		case 4:
			humPtrArray[i]->features.ba = "He has messy, ";
			break;
		}
		switch (humPtrArray[i]->featuresNum.b2) {
		case 1:
			humPtrArray[i]->features.bb = "low eyebrows. ";
			break;
		case 2:
			humPtrArray[i]->features.bb = "high eyebrows. ";
			break;
		case 3:
			humPtrArray[i]->features.bb = "normal eyebrows. ";
			break;
		case 4:
			humPtrArray[i]->features.bb = "close together, eyebrows. ";
			break;
		case 5:
			humPtrArray[i]->features.bb = "far apart, eyebrows. ";
			break;
		}
		switch (humPtrArray[i]->featuresNum.ea1) {
		case 1:
			humPtrArray[i]->features.ea = "He has small ears. ";
			break;
		case 2:
			humPtrArray[i]->features.ea = "He has medium sized ears. ";
			break;
		case 3:
			humPtrArray[i]->features.ea = "He has large ears. ";
			break;
		}
		switch (humPtrArray[i]->featuresNum.j1) {
		case 1:
			humPtrArray[i]->features.ja = "A broad jaw. ";
			humPtrArray[i]->t.ag += 1;
			humPtrArray[i]->t.am += 1;
			humPtrArray[i]->t.de -= 0;
			humPtrArray[i]->t.re += 1;
			humPtrArray[i]->t.lo -= 1;
			humPtrArray[i]->t.em -= 1;
			humPtrArray[i]->t.di += 1;
			break;
		case 2:
			humPtrArray[i]->features.ja = "A receeding jaw. ";
			humPtrArray[i]->t.ag += 0;
			humPtrArray[i]->t.am += 0;
			humPtrArray[i]->t.de += 1;
			humPtrArray[i]->t.re -= 1;
			humPtrArray[i]->t.lo += 1;
			humPtrArray[i]->t.em -= 1;
			humPtrArray[i]->t.di -= 1;
			break;
		case 3:
			humPtrArray[i]->features.ja = "A normal jaw. ";
			humPtrArray[i]->t.ag += 0;
			humPtrArray[i]->t.am += 0;
			humPtrArray[i]->t.de += 0;
			humPtrArray[i]->t.re += 0;
			humPtrArray[i]->t.lo += 0;
			humPtrArray[i]->t.em += 0;
			humPtrArray[i]->t.di += 1;
			break;
		}

		switch (humPtrArray[i]->featuresNum.v1) {
		case 1:
			humPtrArray[i]->features.va = "He has a booming voice.";
			break;
		case 2:
			humPtrArray[i]->features.va = "soft";
			break;
		case 3:
			humPtrArray[i]->features.va = "He has a very low pitched voice.";
			break;
		case 4:
			humPtrArray[i]->features.va = "He has a quickly paced voice. ";
			break;
		case 5:
			humPtrArray[i]->features.va = "He has a voice filled with thoughtful pauses. ";
			break;
		}

		switch (humPtrArray[i]->featuresNum.ck1) {
		case 1:
			humPtrArray[i]->features.cka = "He has full cheeks. ";
			humPtrArray[i]->t.ag += 0;
			humPtrArray[i]->t.am -= 1;
			humPtrArray[i]->t.de += 0;
			humPtrArray[i]->t.re -= 1;
			humPtrArray[i]->t.lo += 0;
			humPtrArray[i]->t.em -= 0;
			humPtrArray[i]->t.di -= 1;
			break;
		case 2:
			humPtrArray[i]->features.cka = "He has low cheekbones. ";
			humPtrArray[i]->t.ag += 1;
			humPtrArray[i]->t.am += 1;
			humPtrArray[i]->t.de += 1;
			humPtrArray[i]->t.re -= 1;
			humPtrArray[i]->t.lo += 1;
			humPtrArray[i]->t.em -= 1;
			humPtrArray[i]->t.di -= 1;
			break;
		case 3:
			humPtrArray[i]->features.cka = "He has high cheekbones. ";
			humPtrArray[i]->t.ag -= 0;
			humPtrArray[i]->t.am += 0;
			humPtrArray[i]->t.de -= 1;
			humPtrArray[i]->t.re += 1;
			humPtrArray[i]->t.lo += 0;
			humPtrArray[i]->t.em -= 1;
			humPtrArray[i]->t.di += 1;
			break;
		}

		humPtrArray[i]->description = humPtrArray[i]->features.ha + humPtrArray[i]->features.hb + humPtrArray[i]->features.eca + humPtrArray[i]->features.ecb + humPtrArray[i]->features.nb + humPtrArray[i]->features.nc + humPtrArray[i]->features.hta + humPtrArray[i]->features.htb + humPtrArray[i]->features.htc +
			humPtrArray[i]->features.ca + humPtrArray[i]->features.cb + humPtrArray[i]->features.ba + humPtrArray[i]->features.bb + humPtrArray[i]->features.ea + humPtrArray[i]->features.ja + humPtrArray[i]->features.va + humPtrArray[i]->features.cka;
	}
}

int get_xCo(int whichPerson) {
	SDL_Event _get_xCo;
	SDL_PollEvent(&_get_xCo);

	switch (whichPerson) {
	case 1:
		return sRo.getPosX();
		break;
	case 2:
		return sRa.getPosX();
		break;
	case 3:
		return sJo.getPosX();
		break;
	case 4:
		return sGe.getPosX();
		break;
	case 5:
		return sSte.getPosX();
		break;
	case 6:
		return  sUn.getPosX();
		break;
	case 7:
		return sU2.getPosX();
		break;
	default:
		return 0;
		break;
	}
}

bool MOD_sameRels() {

	bool success = true;

	SDL_Event _MOD_sameRels;
	SDL_PollEvent(&_MOD_sameRels);

	Character *CharacterArray[5] = { &a, &b, &c, &d, &e };
	Character *CharacterArray2[5] = { &a, &b, &c, &d, &e };

	for (int i = 0; i < 5; i++) {
		set_to_neg1();
		for (int ii = 0; ii < 5; ii++) {
			if ((CharacterArray[i]->r.aa - CharacterArray2[ii]->r.aa <= 3) &&
				(CharacterArray[i]->r.aa - CharacterArray2[ii]->r.aa >= 0) &&
				((CharacterArray[i]->r.aa != -1) && (CharacterArray2[ii]->r.aa != -1))) {
				MOD_assign_xyz(0, CharacterArray[i], CharacterArray2[ii], 1);
			}
			set_to_neg1();
			if ((CharacterArray[i]->r.bb - CharacterArray2[ii]->r.bb <= 3) &&
				(CharacterArray[i]->r.bb - CharacterArray2[ii]->r.bb >= 0) &&
				((CharacterArray[i]->r.bb != -1) && (CharacterArray2[ii]->r.bb != -1))) {
				MOD_assign_xyz(0, CharacterArray[i], CharacterArray2[ii], 1);
			}
			set_to_neg1();
			if ((CharacterArray[i]->r.cc - CharacterArray2[ii]->r.cc <= 3) &&
				(CharacterArray[i]->r.cc - CharacterArray2[ii]->r.cc >= 0) &&
				((CharacterArray[i]->r.cc != -1) && (CharacterArray2[ii]->r.cc != -1))) {
				MOD_assign_xyz(0, CharacterArray[i], CharacterArray2[ii], 1);
			}
			set_to_neg1();
			if ((CharacterArray[i]->r.dd - CharacterArray2[ii]->r.dd <= 3) &&
				(CharacterArray[i]->r.dd - CharacterArray2[ii]->r.dd >= 0) &&
				((CharacterArray[i]->r.dd != -1) && (CharacterArray2[ii]->r.dd != -1))) {
				MOD_assign_xyz(0, CharacterArray[i], CharacterArray2[ii], 1);
			}
			set_to_neg1();
			set_to_neg1();
			if ((CharacterArray[i]->r.ee - CharacterArray2[ii]->r.ee <= 3) &&
				(CharacterArray[i]->r.ee - CharacterArray2[ii]->r.ee >= 0) &&
				((CharacterArray[i]->r.ee != -1) && (CharacterArray2[ii]->r.ee != -1))) {
				MOD_assign_xyz(0, CharacterArray[i], CharacterArray2[ii], 1);
			}
			set_to_neg1();

		}


		set_to_neg1();


		for (int ii = 0; ii < 5; ii++) {
			if ((CharacterArray[i]->r.aa - CharacterArray2[ii]->r.aa >= 6) &&
				((CharacterArray[i]->r.aa != -1) && (CharacterArray2[ii]->r.aa != -1))) {
				MOD_assign_xyz(0, CharacterArray[i], CharacterArray2[ii], -1);
			}
			set_to_neg1();
			if ((CharacterArray[i]->r.bb - CharacterArray2[ii]->r.bb >= 6) &&
				((CharacterArray[i]->r.bb != -1) && (CharacterArray2[ii]->r.bb != -1))) {
				MOD_assign_xyz(0, CharacterArray[i], CharacterArray2[ii], -1);
			}
			set_to_neg1();
			if ((CharacterArray[i]->r.cc - CharacterArray2[ii]->r.cc >= 6) &&
				((CharacterArray[i]->r.cc != -1) && (CharacterArray2[ii]->r.cc != -1))) {
				MOD_assign_xyz(0, CharacterArray[i], CharacterArray2[ii], -1);
			}
			set_to_neg1();
			if ((CharacterArray[i]->r.dd - CharacterArray2[ii]->r.dd >= 6) &&
				((CharacterArray[i]->r.dd != -1) && (CharacterArray2[ii]->r.dd != -1))) {
				MOD_assign_xyz(0, CharacterArray[i], CharacterArray2[ii], -1);
			}
			set_to_neg1();
			if ((CharacterArray[i]->r.ee - CharacterArray2[ii]->r.ee > 6) &&
				((CharacterArray[i]->r.ee != -1) && (CharacterArray2[ii]->r.ee != -1))) {
				MOD_assign_xyz(0, CharacterArray[i], CharacterArray2[ii], -1);
			}
			set_to_neg1();

		}

	}


	set_to_neg1();

	return success;
}

bool MOD_sameTraits() {
	SDL_Event _MOD_sameTraits;
	SDL_PollEvent(&_MOD_sameTraits);

	bool success = true;

	Character *CharacterArray[5] = { &a, &b, &c, &d, &e };
	Character *CharacterArray2[5] = { &a, &b, &c, &d, &e };

	for (int i = 0; i < 5; i++) {
		//cout << endl << "mod_sameTraits round # = " << i << endl;
		for (int ii = 0; ii < 5; ii++) {
			//cout << endl << "start trait similarities <= 3 rnd = " << ii << endl;
			if ((CharacterArray[i]->t.lo - CharacterArray2[ii]->t.lo <= 3) &&
				(CharacterArray[i]->t.lo - CharacterArray2[ii]->t.lo >= 0)) {
				MOD_assign_xyz(0, CharacterArray[i], CharacterArray2[ii], 1);
				//cout << CharacterArray[i]->t.lo << "& " << CharacterArray2[ii]->t.lo;
			}
			if ((CharacterArray[i]->t.ag - CharacterArray2[ii]->t.ag <= 3) &&
				(CharacterArray[i]->t.ag - CharacterArray2[ii]->t.ag >= 0)) {
				MOD_assign_xyz(0, CharacterArray[i], CharacterArray2[ii], 1);
			}
			if ((CharacterArray[i]->t.am - CharacterArray2[ii]->t.am <= 3) &&
				(CharacterArray[i]->t.am - CharacterArray2[ii]->t.am >= 0)) {
				MOD_assign_xyz(0, CharacterArray[i], CharacterArray2[ii], -1);
			}
			if ((CharacterArray[i]->t.em - CharacterArray2[ii]->t.em <= 3) &&
				(CharacterArray[i]->t.em - CharacterArray2[ii]->t.em >= 0)) {
				MOD_assign_xyz(0, CharacterArray[i], CharacterArray2[ii], 1);
			}
			if ((CharacterArray[i]->t.di - CharacterArray2[ii]->t.di <= 3) &&
				(CharacterArray[i]->t.di - CharacterArray2[ii]->t.di >= 0)) {
				MOD_assign_xyz(0, CharacterArray[i], CharacterArray2[ii], 1);
			}
			if ((CharacterArray[i]->t.de - CharacterArray2[ii]->t.de <= 3) &&
				(CharacterArray[i]->t.de - CharacterArray2[ii]->t.de >= -0)) {
				MOD_assign_xyz(0, CharacterArray[i], CharacterArray2[ii], 1);
			}
		}

		for (int ii = 0; ii < 5; ii++) {
			if //((CharacterArray[i]->t.di - CharacterArray2[ii]->t.di <= 7) &&
				(CharacterArray[i]->t.lo - CharacterArray2[ii]->t.lo >= 7) {
				MOD_assign_xyz(0, CharacterArray[i], CharacterArray2[ii], -1);
				//cout << CharacterArray[i]->t.lo << "& " << CharacterArray2[ii]->t.lo;
			}
			if  //((CharacterArray[i]->t.ag - CharacterArray2[ii]->t.ag  <= 3 ) &&
				(CharacterArray[i]->t.ag - CharacterArray2[ii]->t.ag >= 7) {
				MOD_assign_xyz(0, CharacterArray[i], CharacterArray2[ii], -1);
			}
			if  //((CharacterArray[i]->t.am - CharacterArray2[ii]->t.am  <= 3 ) &&
				(CharacterArray[i]->t.am - CharacterArray2[ii]->t.am >= 7) {
				MOD_assign_xyz(0, CharacterArray[i], CharacterArray2[ii], 1);
			}
			if // ((CharacterArray[i]->t.em - CharacterArray2[ii]->t.em <= 3) &&
				(CharacterArray[i]->t.em - CharacterArray2[ii]->t.em >= 7) {
				MOD_assign_xyz(0, CharacterArray[i], CharacterArray2[ii], -1);
			}
			if  //((CharacterArray[i]->t.di - CharacterArray2[ii]->t.di  <= 3) &&
				(CharacterArray[i]->t.di - CharacterArray2[ii]->t.di >= 7) {
				MOD_assign_xyz(0, CharacterArray[i], CharacterArray2[ii], -1);
			}
			if //((CharacterArray[i]->t.de - CharacterArray2[ii]->t.de  <= 3) &&
				(CharacterArray[i]->t.de - CharacterArray2[ii]->t.de >= 7) {
				MOD_assign_xyz(0, CharacterArray[i], CharacterArray2[ii], -1);
			}
		}

	}

	a.r.aa = -1;
	b.r.bb = -1;
	c.r.cc = -1;
	d.r.dd = -1;
	e.r.ee = -1;

	return success;
}



//01_assign physical features to characters
void MOD_physical_relMods() {
	SDL_Event _MOD_sameTraits;
	SDL_PollEvent(&_MOD_sameTraits);

	Character *heightPtrArray[7] = { &a,&b,&b,&b,&b,&u1,&u2 };

	//assign physical features to characters
	for (int i = 0; i < 7; i++) {
		int ih = -1;
		while (ih < 6) {
			ih++;
			cout << ih << endl;
			if ((heightPtrArray[i]->featuresNum.ht1 == 3) && (heightPtrArray[ih]->featuresNum.ht1 == 1)) {
				MOD_assign_xyz(0, heightPtrArray[i], heightPtrArray[ih], -2); // small|big-2
			}
			else if ((heightPtrArray[i]->featuresNum.ht1 == 2) && (heightPtrArray[ih]->featuresNum.ht1 == 1)) {
				MOD_assign_xyz(0, heightPtrArray[i], heightPtrArray[ih], -1); // med|big -1
			}
			else if ((heightPtrArray[i]->featuresNum.ht1 == 1) && (heightPtrArray[ih]->featuresNum.ht1 == 1)) {
				MOD_assign_xyz(0, heightPtrArray[i], heightPtrArray[ih], -1); // big | big +1
			}
			else if ((heightPtrArray[i]->featuresNum.ht1 == 3) && (heightPtrArray[ih]->featuresNum.ht1 == 2)) {
				MOD_assign_xyz(0, heightPtrArray[i], heightPtrArray[ih], -1); // small || med -1
			}
			else if ((heightPtrArray[i]->featuresNum.ht1 == 2) && (heightPtrArray[ih]->featuresNum.ht1 == 2)) {
				MOD_assign_xyz(0, heightPtrArray[i], heightPtrArray[ih], +1); //med|med +1
			}
			else if ((heightPtrArray[i]->featuresNum.ht1 == 1) && (heightPtrArray[ih]->featuresNum.ht1 == 2)) {
				MOD_assign_xyz(0, heightPtrArray[i], heightPtrArray[ih], 0); //big| medium
			}
			else if ((heightPtrArray[i]->featuresNum.ht1 == 3) && (heightPtrArray[ih]->featuresNum.ht1 == 3)) {
				MOD_assign_xyz(0, heightPtrArray[i], heightPtrArray[ih], +2); // small small +2
			}
			else if ((heightPtrArray[i]->featuresNum.ht1 == 2) && (heightPtrArray[ih]->featuresNum.ht1 == 3)) {
				MOD_assign_xyz(0, heightPtrArray[i], heightPtrArray[ih], -1); // med|small -1
			}
			else if ((heightPtrArray[i]->featuresNum.ht1 == 1) && (heightPtrArray[ih]->featuresNum.ht1 == 3)) {
				MOD_assign_xyz(0, heightPtrArray[i], heightPtrArray[ih], -1); //large| small-1
			}
			else {}
		}

	}

}

//modify opinion
template<class T, class U>
bool MOD_assign_xyz(int Y_Xplus, T *x, U *y, int X_Yplus) {

	const bool DISPLAY_ON_CONSOLE = false;

	SDL_Event _assignXyz;
	SDL_PollEvent(&_assignXyz);

	bool success = true;

	if (DISPLAY_ON_CONSOLE) {//print the modded opinion changes
		cout << x->name << "'s opinion = " << y->name << " " << X_Yplus << endl;
		cout << x->name << "'s opinion = " << y->name << " " << Y_Xplus << endl;
		//cout << endl << Y_Xplus << x->name << "|" << y->name << X_Yplus << endl0
	}
	else {}
	int c_x; //person number x
	int c_y; //person number y

			 //integers that arguments will be assigned to
	int x_y1 = 0; //pos value
	int y_x1 = 0; //pos value
	int x_yM1 = 0; //minus value
	int y_xM1 = 0; //minus value

 //Assign negative or positive values to the integer arguments if above or below 0
	if (X_Yplus > 0) {
		x_y1 = X_Yplus;
	}
	else if (X_Yplus < 0) {
		x_yM1 = X_Yplus * -1;
		//cout << x_yM1;
	}
	if (Y_Xplus > 0) {
		y_x1 = Y_Xplus;
	}
	else if (Y_Xplus < 0) {
		y_xM1 = Y_Xplus * -1;
		//cout << y_xM1;
	}

	//Assign brother number to integer c_x based on Character argument
	if (x == &a) {
		c_x = 0;
	}
	else if (x == &b) {
		c_x = 1;
	}
	else if (x == &c) {
		c_x = 2;
	}
	else if (x == &d) {
		c_x = 3;
	}
	else if (x == &e) {
		c_x = 4;
	}
	else if (x == &u1) {
		c_x = 5;
	}
	else if (x == &u2) {
		c_x = 6;
	}
	else {
		success = false;
		cout << endl << "error = MOD_assign_xyz : assign brother number x " << endl;
	}

	//Assign brother number to integer c_y based on Character argument
	if (y == &a) {
		c_y = 0;
	}
	else if (y == &b) {
		c_y = 1;
	}
	else if (y == &c) {
		c_y = 2;
	}
	else if (y == &d) {
		c_y = 3;
	}
	else if (y == &e) {
		c_y = 4;
	}
	else if (y == &u1) {
		c_y = 5;
	}
	else if (y == &u2) {
		c_y = 6;
	}
	else {
		success = false;
		cout << endl << "error = MOD_assign_xyz : assign brother number y " << endl;
	}

	//modify c_y's opinion of c_xx
	switch (c_x) {
	case 0:
		y->r.aa += y_x1; // y | x+-      chbroID_plus_hbro
		y->r.aa -= y_xM1; // y | x+-      chbroID_plus_hbro
		break;
	case 1:
		y->r.bb += y_x1; // y | x+-      chbroID_plus_hbro
		y->r.bb -= y_xM1; // y | x+-      chbroID_plus_hbro
		break;
	case 2:
		y->r.cc += y_x1; // y | x+-      chbroID_plus_hbro
		y->r.cc -= y_xM1; // y | x+-      chbroID_plus_hbro
		break;
	case 3:
		y->r.dd += y_x1; // y | x+-      chbroID_plus_hbro
		y->r.dd -= y_xM1; // y | x+-      chbroID_plus_hbro
		break;
	case 4:
		y->r.ee += y_x1; // y | x+-      chbroID_plus_hbro
		y->r.ee -= y_xM1; // y | x+-      chbroID_plus_hbro
		break;
	case 5:
		y->r.uu1 += y_x1; // y | x+-      chbroID_plus_hbro
		y->r.uu1 -= y_xM1; // y | x+-      chbroID_plus_hbro
		break;
	case 6:
		y->r.uu2 += y_x1; // y | x+-      chbroID_plus_hbro
		y->r.uu2 -= y_xM1; // y | x+-      chbroID_plus_hbro
		break;
	default:
		success = false;
		cout << endl << "error = MOD_assign_xyz : switch (c_x) - modify c_y's opinion of c_xx" << endl;
		break;
	}

	//modify c_x's opinion of c_y
	switch (c_y) {
	case 0:
		x->r.aa += x_y1; // x | y+-      chbroID_plus_hbro
		x->r.aa -= x_yM1; // x | y+-      chbroID_plus_hbro
		break;
	case 1:
		x->r.bb += x_y1; // x | y+-      chbroID_plus_hbro
		x->r.bb -= x_yM1; // x | y+-      chbroID_plus_hbro
		break;
	case 2:
		x->r.cc += x_y1; // x | y+-      chbroID_plus_hbro
		x->r.cc -= x_yM1; // x | y+-      chbroID_plus_hbro
		break;
	case 3:
		x->r.dd += x_y1; // x | y+-      chbroID_plus_hbro
		x->r.dd -= x_yM1; // x | y+-      chbroID_plus_hbro
		break;
	case 4:
		x->r.ee += x_y1; // x | y+-      chbroID_plus_hbro
		x->r.ee -= x_yM1; // x | y+-      chbroID_plus_hbro
		break;
	case 5:
		x->r.uu1 += x_y1; // y | x+-      chbroID_plus_hbro
		x->r.uu1 -= x_yM1; // y | x+-      chbroID_plus_hbro
		break;
	case 6:
		x->r.uu2 += x_y1; // y | x+-      chbroID_plus_hbro
		x->r.uu2 -= x_yM1; // y | x+-      chbroID_plus_hbro
		break;
	default:
		success = false;
		cout << endl << "error = MOD_assign_xyz : switch (c_x) - modify c_y's opinion of c_xx" << endl;
		break;
	}

	//clear_rel_mods - likely unneccessary 
	x_y1 = 0;
	y_x1 = 0;
	x_yM1 = 0;
	y_xM1 = 0;

	return success;
}

void set_to_neg1() {
	a.r.aa = -1;
	b.r.bb = -1;
	c.r.cc = -1;
	d.r.dd = -1;
	e.r.ee = -1;
}




bool GENERATE_pixel_points() {
	SDL_Event _GENERATE_pixel_points;
	SDL_PollEvent(&_GENERATE_pixel_points);

	bool success = true;

	//if pixel grid is on, generate points
	if (TURN_ON_PIXEL_GRAPH == true) {
		for (int i = 0; i < SCREEN_WIDTH; i++) {
			xPixelPoint[i] = i;
		}

		for (int ii = 0; ii < SCREEN_HEIGHT; ii++) {
			yPixelPoint[ii] = ii;
		}
	}

	return success;

}


bool R_pixel_overlay() {

	SDL_Event _R_pixel_overlay;
	SDL_PollEvent(&_R_pixel_overlay);

	bool success = true;

	//set font type and color
	gFont = TTF_OpenFont("TOR_Graphics/Text/ariblk.ttf", 23);     //set font type
	SDL_Color textColor = { 255, 255, 255 };     //set text color


												 //if pixel grid is on, draw lines
	if (TURN_ON_PIXEL_GRAPH == true) {

		//SDL_RenderClear(gRenderer);
		SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);


		for (int i = 0; i < SCREEN_WIDTH; i += PIXEL_GRID_SIZE) {
			SDL_RenderDrawLine(gRenderer, xPixelPoint[i], 0, xPixelPoint[i], SCREEN_HEIGHT);
		}

		for (int i = 0; i < SCREEN_HEIGHT; i += PIXEL_GRID_SIZE) {
			SDL_RenderDrawLine(gRenderer, 0, yPixelPoint[i], SCREEN_WIDTH, yPixelPoint[i]);
		}
	}

	//rectangle to put text on
	SDL_Rect rect_pixel_XY;
	rect_pixel_XY.x = 0;
	rect_pixel_XY.y = 0;
	rect_pixel_XY.w = 32;
	rect_pixel_XY.h = 32;
	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255); // the rect color (solid red)
	SDL_RenderFillRect(gRenderer, &rect_pixel_XY);

	//load the mouse capture event to stringstream
	std::stringstream strmX;
	std::stringstream strmY;
	strmX << X_mousePosPixel;
	char comma = ',';
	strmY << Y_mousePosPixel;

	//Render text
	if (!tTextTexture.loadFromRenderedText(strmX.str() + comma + strmY.str(), textColor)) {
		printf("Unable to render tTextTexture texture!\n");
	}

	tTextTexture.render(rect_pixel_XY.x, rect_pixel_XY.y);

	//if box size recording is on, print text to screen
	if (TURN_ON_BOX_RECORD) {
		std::stringstream strmX_box;
		std::stringstream strmY_box;

		strmX_box << BOXSIZErecordMouseState_X;
		strmY_box << BOXSIZErecordMouseState_Y;
		tTextTextureBoxSelectSize.loadFromRenderedText(strmX_box.str() + comma + strmY_box.str(), textColor);
		tTextTextureBoxSelectSize.render(SCREEN_WIDTH - 300, 20);
	}
	return success;

}

bool R_r_FPS() {

	bool success = true;

	std::stringstream ssFPS;

	gFont = TTF_OpenFont("TOR_Graphics/Text/ariblk.ttf", 23);   //set font type
	SDL_Color textColor = { 255, 255, 255 };     //set text color
												 //Set text to be rendered
	ssFPS.str("");
	ssFPS << "Average Frames Per Second " << MyTimerFPS.getAvgFPS();

	//  cout << "( MyTimer.getTicks() / 1000.f ) =" << ( MyTimer.getTicks() / 1000.f ) << endl;

	//Load and Render text
	if (!tTextTimeTexture.loadFromRenderedText(ssFPS.str().c_str(), textColor)) {
		printf("Unable to render tTextTimeTexture texture!\n");
		success = false;
	}
	tTextTimeTexture.render(SCREEN_WIDTH / 2, 0); // render

	return success;
}


bool R_r_PortraitMovement() {
	sPortraitIconsMovement_122x122_A.render_forward_reverse();
	sPortraitIconsMovement_122x122_B.render_forward_reverse();
	sPortraitIconsMovement_122x122_C.render_forward_reverse();
	sPortraitIconsMovement_122x122_D.render_forward_reverse();
	sPortraitIconsMovement_122x122_E.render_forward_reverse();

	return true;
}

bool R_r_Windows_EmoStats() {
	SDL_Event _R_r_Windows_EmoStats;
	SDL_PollEvent(&_R_r_Windows_EmoStats);

	bool success = true;

	static bool inPortraitBox = false; // (A) Flag to Mark whether mouse over portrait
	Character *CharacterChosen = NULL; //(A) & (B)

									   //(A) width and height of rectangle outline
	int rectWidth = 155;
	int rectHeight = 155;

	//(A) x and y position of relationship and e graphs
	int xPositionDisplayRel = 1180;
	int yPositionDisplayEmo = 210;

	//(B) stringsteam used to store text of physical descriptions
	std::stringstream ssStatsBasic[10];

	//(A) generate rectangle outlines to fit around character portraits on mouse over
	SDL_Rect outlineRect[5];
	outlineRect[0].w = rectWidth; outlineRect[0].h = rectHeight; outlineRect[0].x = 295; outlineRect[0].y = 177;
	outlineRect[1].w = rectWidth; outlineRect[1].h = rectHeight; outlineRect[1].x = 105; outlineRect[1].y = 349;
	outlineRect[2].w = rectWidth; outlineRect[2].h = rectHeight; outlineRect[2].x = 295; outlineRect[2].y = 349;
	char comma = ',';   std::stringstream turnOrder[5];      outlineRect[3].w = rectWidth; outlineRect[3].h = rectHeight; outlineRect[3].x = 105; outlineRect[3].y = 524;
	outlineRect[4].w = rectWidth; outlineRect[4].h = rectHeight; outlineRect[4].x = 295; outlineRect[4].y = 524;

	//(A) (R1) if iE boundaries of charactder portrait, draw outline/character color around portrait and render stat bars
	if ((X_mousePosPixel > outlineRect[0].x && X_mousePosPixel < outlineRect[0].x + outlineRect[0].w) && (Y_mousePosPixel > outlineRect[0].y && Y_mousePosPixel < outlineRect[0].y + outlineRect[0].h))
	{
		SDL_SetRenderDrawColor(gRenderer, text_set_color(0).x, text_set_color(0).y, text_set_color(0).z, 0xFF);
		SDL_RenderDrawRect(gRenderer, &outlineRect[0]);
		//render e bar
		drBarRobert.rel_renderStatBars(true, xPositionDisplayRel, yPositionDisplayEmo);
		deBarRobert.renderStatBars(true, xPositionDisplayRel + 170, yPositionDisplayEmo);

		CharacterChosen = &a;
		inPortraitBox = true;
	}
	if ((X_mousePosPixel > outlineRect[1].x && X_mousePosPixel < outlineRect[1].x + outlineRect[1].w) && (Y_mousePosPixel > outlineRect[1].y && Y_mousePosPixel < outlineRect[1].y + outlineRect[1].h))
	{
		SDL_SetRenderDrawColor(gRenderer, text_set_color(1).x, text_set_color(1).y, text_set_color(1).z, 0xFF);
		SDL_RenderDrawRect(gRenderer, &outlineRect[1]); //draw outline
		drBarRanulf.rel_renderStatBars(true, xPositionDisplayRel, yPositionDisplayEmo);
		deBarRanulf.renderStatBars(true, xPositionDisplayRel + 170, yPositionDisplayEmo);

		CharacterChosen = &b;
		inPortraitBox = true;
	}
	if ((X_mousePosPixel > outlineRect[2].x && X_mousePosPixel < outlineRect[2].x + outlineRect[2].w) && (Y_mousePosPixel > outlineRect[2].y && Y_mousePosPixel < outlineRect[2].y + outlineRect[2].h))
	{
		SDL_SetRenderDrawColor(gRenderer, text_set_color(2).x, text_set_color(2).y, text_set_color(2).z, 0xFF);
		SDL_RenderDrawRect(gRenderer, &outlineRect[2]); //draw outline
		drBarJohn.rel_renderStatBars(true, xPositionDisplayRel, yPositionDisplayEmo);
		deBarJohn.renderStatBars(true, xPositionDisplayRel + 170, yPositionDisplayEmo);

		CharacterChosen = &c;
		inPortraitBox = true;
	}
	if ((X_mousePosPixel > outlineRect[3].x && X_mousePosPixel < outlineRect[3].x + outlineRect[3].w) && (Y_mousePosPixel > outlineRect[3].y && Y_mousePosPixel < outlineRect[3].y + outlineRect[3].h))
	{
		SDL_SetRenderDrawColor(gRenderer, text_set_color(3).x, text_set_color(3).y, text_set_color(3).z, 0xFF);
		SDL_RenderDrawRect(gRenderer, &outlineRect[3]);//draw outline
		drBarGeoffrey.rel_renderStatBars(true, xPositionDisplayRel, yPositionDisplayEmo);
		deBarGeoffrey.renderStatBars(true, xPositionDisplayRel + 170, yPositionDisplayEmo);

		CharacterChosen = &d;
		inPortraitBox = true;
	}
	if ((X_mousePosPixel > outlineRect[4].x && X_mousePosPixel < outlineRect[4].x + outlineRect[4].w) && (Y_mousePosPixel > outlineRect[4].y && Y_mousePosPixel < outlineRect[4].y + outlineRect[4].h))
	{
		SDL_SetRenderDrawColor(gRenderer, text_set_color(4).x, text_set_color(4).y, text_set_color(4).z, 0xFF);
		SDL_RenderDrawRect(gRenderer, &outlineRect[4]);//draw outline

		drBarStephen.rel_renderStatBars(true, xPositionDisplayRel, yPositionDisplayEmo);
		deBarStephen.renderStatBars(true, xPositionDisplayRel + 170, yPositionDisplayEmo);

		CharacterChosen = &e; // fpr
		inPortraitBox = true;
	}

	//(B) (R2) if mouse is iE a portrait box render stats of character to screen
	if (inPortraitBox == true) {

		//set font type, size and  color
		gFont = TTF_OpenFont("TOR_Graphics/Text/ariblk.ttf", 10); //set font type
		SDL_Color textColor = { 255, 255, 255 };// set color

												//put stat information into string stream to be used iE text,
		ssStatsBasic[0] << "Aggression = " << CharacterChosen->t.ag;
		ssStatsBasic[1] << ", Ambition = " << CharacterChosen->t.am;
		ssStatsBasic[2] << ", Deception = " << CharacterChosen->t.de;
		ssStatsBasic[3] << "Diplomacy = " << CharacterChosen->t.di;
		ssStatsBasic[4] << ", Empathy = " << CharacterChosen->t.em;
		ssStatsBasic[5] << ", Logic = " << CharacterChosen->t.lo;
		ssStatsBasic[6] << ", Respect = " << CharacterChosen->t.re;

		ssStatsBasic[7] << "Birth Order = " << CharacterChosen->birthRank;
		ssStatsBasic[8] << ", Turn Order Score = " << CharacterChosen->to;
		ssStatsBasic[9] << ", AP Score = " << CharacterChosen->newAp;

		//load tTextTurnorder with string stream from above entered iE 
		if (!tTextTextureStats[0].loadFromRenderedText(ssStatsBasic[0].str() + ssStatsBasic[1].str() + ssStatsBasic[2].str(), textColor)) {
			printf("Unable to render tTextTextureStats texture!\n");
		}
		if (!tTextTextureStats[1].loadFromRenderedText(ssStatsBasic[3].str() + ssStatsBasic[4].str() + ssStatsBasic[5].str() + ssStatsBasic[6].str(), textColor)) {
			printf("Unable to render tTextTextureStats texture!\n");
		}
		if (!tTextTextureStats[2].loadFromRenderedText(ssStatsBasic[7].str() + ssStatsBasic[8].str() + ssStatsBasic[9].str(), textColor)) {
			printf("Unable to render tTextTextureStats texture!\n");
		}

		//render the three font textures to screen, each one under each other
		tTextTextureStats[0].render(1177, 440);
		tTextTextureStats[1].render(1177, 470);
		tTextTextureStats[2].render(1177, 500);
	}

	inPortraitBox = false;

	return success;
}

//display turn order portraits
bool R_r_GUI_turnOrder() {

	bool success = true;
	//array used to render portraits iE for() below
	Character *turnOrderArray[5] = { bRound1.t1,bRound1.t2,bRound1.t3,bRound1.t4,bRound1.t5 };

	//reder turn order portraits to screen
	for (int i = 0; i < 5; i++) {
		if (turnOrderArray[i] == &a) {
			portraitTurnOrder[0].render(504 + (52 * i), 96);
		}
		else if (turnOrderArray[i] == &b) {
			portraitTurnOrder[1].render(504 + (52 * i), 96);
		}
		else if (turnOrderArray[i] == &c) {
			portraitTurnOrder[2].render(504 + (52 * i), 96);
		}
		else if (turnOrderArray[i] == &d) {
			portraitTurnOrder[3].render(504 + (52 * i), 96);
		}
		else if (turnOrderArray[i] == &e) {
			portraitTurnOrder[4].render(504 + (52 * i), 96);
		}
		else {
			cout << "error in R_r_GUI_turnOrder() " << endl;
		}
	}

	return success;
}

bool R_Scene1() {

	SDL_Event _R_Scene1;
	SDL_PollEvent(&_R_Scene1);

	bool success = true;
	SheildTemp1.render(0, 0);



	R_r_Windows_EmoStats();
	R_r_PortraitMovement();


	if (TURN_ON_PRINT_X_Y_COORD == true) R_pixel_overlay();
	if (TURN_ON_FPS_COUNTER == true)R_r_FPS(); // print fps
	R_r_GUI_turnOrder();

	return success;

}

bool R_titleScreen() {

	bool success = true;
	SDL_Event _R_titleScreen;
	SDL_PollEvent(&_R_titleScreen);
	//clear screen to draw color
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);


	//render background
	tTitleBackground.render(0, 0);

	//render buttons and box behind buttons
	tButtonBox.render(bStartButton.getPositionX() - 25, bStartButton.getPositionY() - 25);
	bStartButton.render();
	bExitButton.render();

	//render titlebox
	tBlankTitleBox.render((SCREEN_WIDTH / 2) - (tBlankTitleBox.getWidth() / 2), 0);
	//render title animation
	sTitleSprite.render(false);

	//render images
	SDL_RenderPresent(gRenderer);

	return success;
}

void Z_Close_R_titleScreen() {
	tButtonBox.free();
	bStartButton.free();
	bExitButton.free();
	tBlankTitleBox.free();
	sTitleSprite.free();
}

colorValues text_set_color(int broNum) {
	colorValues result;
	cout << "bro num = " << broNum;
	if (broNum == 1) {
		result.x = 215;
		result.y = 8;
		result.z = 17;
		return result;
	}
	else if (broNum == 2) {
		result.x = 47;
		result.y = 135;
		result.z = 26;
		return result;
	}
	else if (broNum == 3) {
		result.x = 16;
		result.y = 116;
		result.z = 116;
		return result;
	}
	else if (broNum == 4) {
		result.x = 146;
		result.y = 9;
		result.z = 155;
		return result;
	}
	else if (broNum == 5) {
		result.x = 193;
		result.y = 116;
		result.z = 15;
		return result;
	}
	else if (broNum == 6) {
		result.x = 40;
		result.y = 103;
		result.z = 16;
		return result;
	}
	else if (broNum == 7) {
		result.x = 218;
		result.y = 231;
		result.z = 3;
		return result;
	}
	else if (broNum == 8) {
		result.x = 33;
		result.y = 16;
		result.z = 200;
		return result;
	}
	else {
		cout << "error in parameter \"colorValues text_set_color (int broNum)\"" << endl;
		result.x = 0;
		result.y = 0;
		result.z = 0;
		return result;
	}

}

Character *find_Bro_address(int enterNum) {
	SDL_Event _find_Bro_address;
	SDL_PollEvent(&_find_Bro_address);

	if (enterNum == 1) {
		return &a;
	}
	else if (enterNum == 2) {
		return &b;
	}
	else if (enterNum == 3) {
		return &c;
	}
	else if (enterNum == 4) {
		return &d;
	}
	else if (enterNum == 5) {
		return &e;
	}
	/*
	else if (enterNum == 6){
	return &u1;
	}
	else if(enterNum == 7){
	return &u2;
	}
	*/
	else {
		cout << "error function change_Bro_num";
		return &a;
	}
}

int FIND_rel_value_of_XY(Character *theJudger, Character *charArrayCalcAnimosity) {

	SDL_Event _FIND_rel_value;
	SDL_PollEvent(&_FIND_rel_value);

	if (theJudger == &a && charArrayCalcAnimosity == &a) return a.r.aa;
	else if (theJudger == &a && charArrayCalcAnimosity == &b) return a.r.bb;
	else if (theJudger == &a && charArrayCalcAnimosity == &c) return a.r.cc;
	else if (theJudger == &a && charArrayCalcAnimosity == &d) return a.r.dd;
	else if (theJudger == &a && charArrayCalcAnimosity == &e) return a.r.ee;

	if (theJudger == &b && charArrayCalcAnimosity == &a) return b.r.aa;
	else if (theJudger == &b && charArrayCalcAnimosity == &b) return b.r.bb;
	else if (theJudger == &b && charArrayCalcAnimosity == &c) return b.r.cc;
	else if (theJudger == &b && charArrayCalcAnimosity == &d) return b.r.dd;
	else if (theJudger == &b && charArrayCalcAnimosity == &e) return b.r.ee;

	if (theJudger == &c && charArrayCalcAnimosity == &a) return c.r.aa;
	else if (theJudger == &c && charArrayCalcAnimosity == &b) return c.r.bb;
	else if (theJudger == &c && charArrayCalcAnimosity == &c) return c.r.cc;
	else if (theJudger == &c && charArrayCalcAnimosity == &d) return c.r.dd;
	else if (theJudger == &c && charArrayCalcAnimosity == &e) return c.r.ee;

	if (theJudger == &d && charArrayCalcAnimosity == &a) return d.r.aa;
	else if (theJudger == &d && charArrayCalcAnimosity == &b) return d.r.bb;
	else if (theJudger == &d && charArrayCalcAnimosity == &c) return d.r.cc;
	else if (theJudger == &d && charArrayCalcAnimosity == &d) return d.r.dd;
	else if (theJudger == &d && charArrayCalcAnimosity == &e) return d.r.ee;

	if (theJudger == &e && charArrayCalcAnimosity == &a) return e.r.aa;
	else if (theJudger == &e && charArrayCalcAnimosity == &b) return e.r.bb;
	else if (theJudger == &e && charArrayCalcAnimosity == &c) return e.r.cc;
	else if (theJudger == &e && charArrayCalcAnimosity == &d) return e.r.dd;
	else if (theJudger == &e && charArrayCalcAnimosity == &e) return e.r.ee;

	return 0;
}

int FIND_Bro_num(Character *findBro) {
	//cout << endl << "findBro" << findBro << endl;
	SDL_Event _findBronumChar;
	SDL_PollEvent(&_findBronumChar);

	if (findBro == &a) {
		return 1;
	}
	else if (findBro == &b) {
		return 2;
	}
	else if (findBro == &c) {
		return 3;
	}
	else if (findBro == &d) {
		return 4;
	}
	else if (findBro == &e) {
		return 5;
	}
	if (findBro == &u1) {
		return 6;
	}
	else if (findBro == &u2) {
		return 7;
	}
	else if (findBro == &f) {
		return 8;
	}
	else { cout << "error int find_Bro_num (Character *findBro)"; return 0; }
}

bool Z_z_init_GlobalVariables() {

	bool success = true;

	//set names to characters
	a.name = "Robert"; b.name = "Ranulf"; c.name = "John"; d.name = "Geoffrey"; e.name = "Stephen";

	//assign characters to RelThermos
	printf("\n Assigning Characters to RelThermo Array, ");
	for (int i = 0; i < 5; i++) {
		RelThermo_Ptr_Array[i]->set_character_RT(charBroPtrArray[i]);
	}

	//assign characters to EmoThermos
	for (int i = 0; i < 5; i++) {
		EmoThermo_Ptr_Array[i]->set_CharacterPtr_ET(charBroPtrArray[i]);
	}printf("EmoThermo Array \n");

	MotiThermo_A.setCharacterPtr_MT(&a);
	MotiThermo_B.setCharacterPtr_MT(&b);
	MotiThermo_C.setCharacterPtr_MT(&c);
	MotiThermo_D.setCharacterPtr_MT(&d);
	MotiThermo_E.setCharacterPtr_MT(&e);

	return success;
}

bool Z_init() {
	//sA_gBgFrames.MaxFrames = 256;
	//Initialization flag
	bool success = true;

	//Initialize SDL
	SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	//Set texture filtering to linear
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	//Create window
	gWindow = SDL_CreateWindow("Tides Of Regicide | Version 0.00.00", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	//Create vsynced renderer for window
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//Initialize renderer color
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;

	if (!(IMG_Init(imgFlags) & imgFlags)) {
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		success = false;
	}
	//Initialize SDL_ttf
	if (TTF_Init() == -1) {
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		success = false;
	}
	return success;
}

bool Z_LOADMEDIA() {

	bool success = true;
	printf("Start Z_LOADMEDIA()............. \n");
	gFont = TTF_OpenFont("TOR_Graphics/Text/ariblk.ttf", 28);
	if (gFont == NULL) {
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	else { printf("gFont = Success \n"); }

	if (!Z_LOADMEDIA_loadPortraits()) {
		printf("Z_LOADMEDIA_loadPortraits = Failed!\n");
		success = false;
	}
	else { printf("Z_LOADMEDIA_loadPortraits() = Success\n"); }

	if (!Z_loadTitleMenu()) {
		printf("Z_loadTitleMenu() = Failed!\n");
		success = false;
	}
	else { printf("Z_loadTitleMenu() = Success\n"); }


	if (!Z_LOADMEDIA_loadGUI()) {
		printf("Z_LOADMEDIA_loadGUI() = Failed! \n");
		success = false;
	}
	else { printf("Z_LOADMEDIA_loadGUI() = Success\n"); }
	if (!Z_LOADMEDIA_loadGraphs()) {
		printf("Z_LOADMEDIA_loadGraphs() = Failed! \n");
		success = false;
	}
	else { printf("Z_LOADMEDIA_loadGraphs() = Success\n"); }
	if (!GENERATE_INITIAL_STATS()) {
		printf("GENERATE_INITIAL_STATS() = Failed! \n");
		success = false;
	}
	else { printf("GENERATE_INITIAL_STATS() = Success\n"); }

	if (!Z_loadSound()) {
		printf("Z_loadSound() = Failed! \n");
		success = false;
	}
	else { printf("Z_loadSound() = Success\n"); }

	printf(" .............End Z_LOADMEDIA() \n");
	return success;
}

bool Z_LOADMEDIA_loadGraphs() {
	bool success = true;

	printf("\n \t Start Z_LOADMEDIA_loadGraphs()............. \n");

	if (!hE_alpha.loadFromFile("TOR_Graphics/BG_images/Alpha_Overlays/hap_alpha.png")) {
		printf("Failed to load hap_alpha.png texture!\n");
		success = false;
	} printf("texture hap_alpha.loadFromFile() = success \n");
	if (!aE_alpha.loadFromFile("TOR_Graphics/BG_images/Alpha_Overlays/ang_alpha.png")) {
		printf("Failed to load ang_alpha.png texture!\n");
		success = false;
	} printf("texture ang_alpha.loadFromFile() = success \n");
	if (!sE_alpha.loadFromFile("TOR_Graphics/BG_images/Alpha_Overlays/sad_alpha.png")) {
		printf("Failed to load sad_alpha.png texture!\n");
		success = false;
	} printf("texture sad_alpha.loadFromFile() = success \n");
	if (!fE_alpha.loadFromFile("TOR_Graphics/BG_images/Alpha_Overlays/fea_alpha.png")) {
		printf("Failed to load fea_alpha.png texture!\n");
		success = false;
	} printf("texture fea_alpha.loadFromFile() = success \n");
	if (!iE_alpha.loadFromFile("TOR_Graphics/BG_images/Alpha_Overlays/int_alpha.png")) {
		printf("Failed to load int_alpha.png texture!\n");
		success = false;
	} printf("texture int_alpha.loadFromFile() = success \n");

	//load e graph
	if (!tor_E_graph_150_232.loadFromFile("TOR_Graphics/GUI/Graphs/tor_E_graph_150_232.png")) {
		printf("Failed to load tor_E_graph_150_232.png texture!\n");
		success = false;
	}
	else { printf("texture tor_E_graph_150_232.loadFromFile() = success \n"); }

	//load relational graph graph
	if (!tor_R_graph_150_232.loadFromFile("TOR_Graphics/GUI/Graphs/tor_R_graph_150_232.png")) {
		printf("Failed to load tor_R_graph_150_232.png texture!\n");
		success = false;
	} printf("texture tor_R_graph_150_232.loadFromFile() = success \n");

	deBarRobert.setEChar(a);
	deBarRanulf.setEChar(b);
	deBarJohn.setEChar(c);
	deBarGeoffrey.setEChar(d);
	deBarStephen.setEChar(e);

	drBarRobert.setRelChar(&a);
	drBarRanulf.setRelChar(&b);
	drBarJohn.setRelChar(&c);
	drBarGeoffrey.setRelChar(&d);
	drBarStephen.setRelChar(&e);

	printf("\t .............End Z_LOADMEDIA_loadGraphs()\n");
	return success;
}

bool Z_LOADMEDIA_loadGUI() {
	bool success = true;
	printf("\n \t Start Z_LOADMEDIA_loadGUI().............  \n");

	//load icond
	if (!menu_icons.loadFromFile("TOR_Graphics/GUI/Icons/menu_icons.png")) {
		printf("Failed to load menu_icons.png texture!\n");
		success = false;
	}


	//load 480x480 window that holds the Rel and e graphs
	if (!sqaure_window_RELemo_Info_480wh.loadFromFile("TOR_Graphics/Menus/Windows/sqaure_window_RELemo_Info_480wh.png")) {
		printf("Failed to load sqaure_window_RELemo_Info_480wh.png texture!\n");
		success = false;
	}

	//load 480x480 window that's empty
	if (!sqaure_window_480x480.loadFromFile("TOR_Graphics/Menus/Windows/sqaure_window_480x480.png")) {
		printf("Failed to load sqaure_window_480x480.png texture!\n");
		success = false;
	}

	//load 480x480 window that holds the Rel and e graphs
	if (!SheildTemp1.loadFromFile("TOR_Graphics/GUI/MAIN_TEMPLATES/SheildTemp1.png")) {
		printf("Failed to load SheildTemp1.png texture!\n");
		success = false;
	}

	//load a large empty single bar of e graph
	if (!large_bar_e_graph.loadFromFile("TOR_Graphics/GUI/Graphs/large_bar_emo_graph.png")) {
		printf("Failed to load large_bar_emo_graph.png texture!\n");
		success = false;
	}

	//load a large empty single bar of e graph
	if (!DialogueBox_1600x50.loadFromFile("TOR_Graphics/GUI/Dialogue/DialogueBox_1600x50.png")) {
		printf("Failed to load DialogueBox_1600x50.png texture!\n");
		success = false;
	}

	if (!portraitTurnOrder[0].loadFromFile("TOR_Graphics/GUI/Icons/smallPortraitA_52x52.png")) {
		printf("Failed to load smallPortraitA.png texture!\n");
		success = false;
	}
	if (!portraitTurnOrder[1].loadFromFile("TOR_Graphics/GUI/Icons/smallPortraitB_52x52.png")) {
		printf("Failed to load smallPortraitB.png texture!\n");
		success = false;
	}
	if (!portraitTurnOrder[2].loadFromFile("TOR_Graphics/GUI/Icons/smallPortraitC_52x52.png")) {
		printf("Failed to load smallPortraitC.png texture!\n");
		success = false;
	}
	if (!portraitTurnOrder[3].loadFromFile("TOR_Graphics/GUI/Icons/smallPortraitD_52x52.png")) {
		printf("Failed to load smallPortraitD.png texture!\n");
		success = false;
	}
	if (!portraitTurnOrder[4].loadFromFile("TOR_Graphics/GUI/Icons/smallPortraitE_52x52.png")) {
		printf("Failed to load DialogueBox_1600x50.png texture!\n");
		success = false;
	}
	printf("\t .............End Z_LOADMEDIA_loadGUI()  \n");

	//set global variables
	return success;
}

bool Z_LOADMEDIA_loadPortraits() {
	bool success = true;
	printf("\n \t Start Z_LOADMEDIA_loadPortraits().............  \n");


	if (!tPortrait_icons_movement_122x122_A.loadFromFile("TOR_Graphics/GUI/Icons/portrait_icon_movement_122x122/portrait_icons_movement_122x122_A.png")) {
		printf("Failed to load portrait_icons_movement_122x122_A.png texture!\n");
		success = false;
	}
	if (!tPortrait_icons_movement_122x122_B.loadFromFile("TOR_Graphics/GUI/Icons/portrait_icon_movement_122x122/portrait_icons_movement_122x122_B.png")) {
		printf("Failed to load portrait_icons_movement_122x122_B.png!\n");
		success = false;
	}
	if (!tPortrait_icons_movement_122x122_C.loadFromFile("TOR_Graphics/GUI/Icons/portrait_icon_movement_122x122/portrait_icons_movement_122x122_C.png")) {
		printf("Failed to load portrait_icons_movement_122x122_C.png texture!\n");
		success = false;
	}
	if (!tPortrait_icons_movement_122x122_D.loadFromFile("TOR_Graphics/GUI/Icons/portrait_icon_movement_122x122/portrait_icons_movement_122x122_D.png")) {
		printf("Failed to load portrait_icons_movement_122x122_D.png texture!\n");
		success = false;
	}
	if (!tPortrait_icons_movement_122x122_E.loadFromFile("TOR_Graphics/GUI/Icons/portrait_icon_movement_122x122/portrait_icons_movement_122x122_E.png")) {
		printf("Failed to load portrait_icons_movement_122x122_E.png texture!\n");
		success = false;
	}

	sPortraitIconsMovement_122x122_A.setTotalFrames(46);
	sPortraitIconsMovement_122x122_A.setSprite(&tPortrait_icons_movement_122x122_A);
	sPortraitIconsMovement_122x122_A.setQuads(122, 122, 6, 8, 0, true);
	sPortraitIconsMovement_122x122_A.setPos(310, 190);
	sPortraitIconsMovement_122x122_A.slow_clip_by(5);
	sPortraitIconsMovement_122x122_A.freeze_final_frame(false);


	sPortraitIconsMovement_122x122_B.setTotalFrames(46);
	sPortraitIconsMovement_122x122_B.setSprite(&tPortrait_icons_movement_122x122_B);
	sPortraitIconsMovement_122x122_B.setQuads(122, 122, 6, 8, 0, true);
	sPortraitIconsMovement_122x122_B.setPos(121, 361);
	sPortraitIconsMovement_122x122_B.slow_clip_by(5);
	sPortraitIconsMovement_122x122_B.freeze_final_frame(false);

	sPortraitIconsMovement_122x122_C.setTotalFrames(46);
	sPortraitIconsMovement_122x122_C.setSprite(&tPortrait_icons_movement_122x122_C);
	sPortraitIconsMovement_122x122_C.setQuads(122, 122, 6, 8, 0, true);
	sPortraitIconsMovement_122x122_C.setPos(310, 361);
	sPortraitIconsMovement_122x122_C.slow_clip_by(5);
	sPortraitIconsMovement_122x122_C.freeze_final_frame(false);

	sPortraitIconsMovement_122x122_D.setTotalFrames(46);
	sPortraitIconsMovement_122x122_D.setSprite(&tPortrait_icons_movement_122x122_D);
	sPortraitIconsMovement_122x122_D.setQuads(122, 122, 6, 8, 0, true);
	sPortraitIconsMovement_122x122_D.setPos(121, 536);
	sPortraitIconsMovement_122x122_D.slow_clip_by(5);
	sPortraitIconsMovement_122x122_D.freeze_final_frame(false);

	sPortraitIconsMovement_122x122_E.setTotalFrames(46);
	sPortraitIconsMovement_122x122_E.setSprite(&tPortrait_icons_movement_122x122_E);
	sPortraitIconsMovement_122x122_E.setQuads(122, 122, 6, 8, 0, true);
	sPortraitIconsMovement_122x122_E.setPos(310, 536);
	sPortraitIconsMovement_122x122_E.slow_clip_by(5);
	sPortraitIconsMovement_122x122_E.freeze_final_frame(false);

	printf("\t .............END Z_LOADMEDIA_loadPortraits()  \n");
	return success;
}

bool Z_loadTitleMenu() {
	bool success = true;

	//load title background texture
	if (!tTitleBackground.loadFromFile("TOR_Graphics/BG_images/bg2_water_spray_big.png")) {
		printf("Failed to load bg2_water_spray_big.png texture!\n");
		success = false;
	}

	//set width height of buttons
	bStartButton.setWidthHeight(125, 68);
	bExitButton.setWidthHeight(125, 68);

	//set button sprite clips
	bStartButton.setSpriteClips4(0, 0, 125, 68);
	bExitButton.setSpriteClips4(0, 0, 125, 68);

	//set positon of buttons
	bStartButton.setPosition((SCREEN_WIDTH / 2) - (bStartButton.getWidth() / 2), SCREEN_HEIGHT / 3);
	bExitButton.setPosition((SCREEN_WIDTH / 2) - (bExitButton.getWidth() / 2), (SCREEN_HEIGHT / 3) + 75);

	//load image for box begind button
	if (!tButtonBox.loadFromFile("TOR_Graphics/GUI/buttonBox.png")) {
		printf("Failed to load buttonBox.png texture!\n");
		success = false;
	}

	//load button textures
	bStartButton.setSpriteSheet("TOR_Graphics/Sprites/Buttons/start.png");
	bExitButton.setSpriteSheet("TOR_Graphics/Sprites/Buttons/exit.png");

	//load title blank texture
	if (!tBlankTitleBox.loadFromFile("TOR_Graphics/BG_images/Title/title_blank.png")) {
		printf("Failed to load title_blank.png texture!\n");
		success = false;
	}

	//load title animation sprite sheet to texture
	if (!tTitleAnimation.loadFromFile("TOR_Graphics/BG_images/Title/TitleAnimation/TOR_title_animation.png")) {
		printf("Failed to load TitleAnimation.png texture!\n");
		success = false;
	}
	//set up title animation sprite sheet
	sTitleSprite.setTotalFrames(54);
	sTitleSprite.setSprite(&tTitleAnimation);
	sTitleSprite.setQuads(825, 200, 7, 8, 0, true);
	sTitleSprite.setPos((SCREEN_WIDTH / 2) - (sTitleSprite.getWidth() / 2), 30);
	sTitleSprite.slow_clip_by(5);
	sTitleSprite.freeze_final_frame(true);

	return success;
}

bool Z_loadSound() {
	bool success = true;
	tMusic = Mix_LoadMUS("TOR_Sound/draft.wav");

	if (tMusic == NULL)
	{
		cout << "tMusic did not load" << endl;
		return false;
	}

	return success;
}

bool Z_LOADMEDIA_loadCharacters() {

	bool success = true;

	printf("\t Start Z_LOADMEDIA_loadCharacters()....... \n");
	//load Character sprite textures
	if (!tSprite_a.loadFromFile("TOR_Graphics/Sprites/character_sprites/sprite_char1.png")) {
		printf("Failed to load sprite_char1.png texture!\n");
		success = false;
	}
	if (!tSprite_b.loadFromFile("TOR_Graphics/Sprites/character_sprites/sprite_char2.png")) {
		printf("Failed to load sprite_char2.png texture!\n");
		success = false;
	}
	if (!tSprite_c.loadFromFile("TOR_Graphics/Sprites/character_sprites/sprite_char3.png")) {
		printf("Failed to load sprite_char3.png texture!\n");
		success = false;
	}
	if (!tSprite_d.loadFromFile("TOR_Graphics/Sprites/character_sprites/sprite_char4.png")) {
		printf("Failed to load sprite_char4.png texture!\n");
		success = false;
	}
	if (!tSprite_e.loadFromFile("TOR_Graphics/Sprites/character_sprites/sprite_char5.png")) {
		printf("Failed to load sprite_char5.png texture!\n");
		success = false;
	}

	//assign character pointers to cSprite characters
	sRo.setCharacter(&a);
	sRa.setCharacter(&b);
	sJo.setCharacter(&c);
	sGe.setCharacter(&d);
	sSte.setCharacter(&e);

	//assign texture to cSprite characters
	sRo.setSprite(&tSprite_a);
	sRa.setSprite(&tSprite_b);
	sJo.setSprite(&tSprite_c);
	sGe.setSprite(&tSprite_d);
	sSte.setSprite(&tSprite_e);
	//
	//set initial position of sprites
	sRo.setPos(200, 200);
	sRa.setPos(400, 200);
	sJo.setPos(300, 650);
	sGe.setPos(500, 100);
	sSte.setPos(500, 600);

	//    sTitleSprite.setTotalFrames(60);
	sRo.setQuads(50, 100, 12, 5, 0, true);
	sRa.setQuads(50, 100, 12, 5, 0, true);
	sJo.setQuads(50, 100, 12, 5, 0, true);
	sGe.setQuads(50, 100, 12, 5, 0, true);
	sSte.setQuads(50, 100, 12, 5, 0, true);

	printf("\t ....... End Z_LOADMEDIA_loadCharacters() \n");
	//ctrl b = bookmark
	return success;
}

bool Z_LOADMEDIA_loadBackgrounds() {
	printf("\t  Start Z_LOADMEDIA_loadBackgrounds()....... \n");
	bool success = true;
	//load Character sprite textures
	if (!bg_green1.loadFromFile("TOR_Graphics/BG_images/Terrain/bg_green1.png")) {
		printf("Failed to load bg_green1.png texture!\n");
		success = false;
	}
	printf("\t ....... End Z_LOADMEDIA_loadBackgrounds() \n");
	return success;
}

void Z_Close() {

	tTextTextureStats[0].free();
	tTextTextureStats[1].free();
	tTextTextureStats[2].free();

	//Free buttons
	bStartButton.free();
	bExitButton.free();

	/////////////////////////////////////////FREE TEXTURES /////////////////////////////////////////////////////
	menu_icons.free();
	DialogueBox_1600x50.free();

	/////////e and Relation Graphs and Window
	tor_E_graph_150_232.free();
	tor_R_graph_150_232.free();
	sqaure_window_RELemo_Info_480wh.free();
	//////////END
	large_bar_e_graph.free();

	bg_green1.free();

	hE_alpha.free();
	aE_alpha.free();
	sE_alpha.free();
	fE_alpha.free();
	iE_alpha.free();

	sqaure_window_480x480.free();
	SheildTemp1.free();    tTitleBackground.free();
	tButtonBox.free();
	tBlankTitleBox.free();
	tTitleAnimation.free();

	//Rendered text
	tTextTexture.free();
	tTextTurnorder.free();
	tTextTextureBoxSelectSize.free();
	tTopicTexture[3].free();

	tTitleBackground.free();
	tButtonBox.free();
	tBlankTitleBox.free();
	tTitleAnimation.free();
	menu_icons.free();
	bg_green1.free();

	for (int i = 0; i < 5; i++) {
		array_tSprites[i]->free();
		array_tSprites[i]->free();
	}
	//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx END FREE TEXTURES xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx ///

	//Free global font
	Mix_FreeMusic(tMusic);

	TTF_CloseFont(gFont);
	gFont = NULL;

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	Mix_CloseAudio();
	SDL_Quit();

}



//copyright Robert Misener 2018
//www.RobertMisener.com
