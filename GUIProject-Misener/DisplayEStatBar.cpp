

#include "Character.h"
#include "LTexture.h"
#include "DisplayEStatBar.h"

#include <sstream> // for
#include <ostream> // for

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

//#include <gl/gl.h>
//#include <gl/glu.h>


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

extern SDL_Renderer* gRenderer;
extern LTexture tor_E_graph_150_232;
extern LTexture tor_R_graph_150_232;
extern int render_Faces(int broNum, int broEmo);

extern LTexture hE_alpha;
extern LTexture aE_alpha;
extern LTexture sE_alpha;
extern LTexture fE_alpha;
extern LTexture iE_alpha;


void DisplayEStatBar::setEChar(Character &whichCharacter) {
	whichChar = &whichCharacter;


}


void DisplayEStatBar::renderStatBars(bool renderIt, int xLoc, int yLoc) {

	SDL_Event _DisplayEmoStatBar_renderStatBars;
	SDL_PollEvent(&_DisplayEmoStatBar_renderStatBars);

	int eR = 0;
	int eG = 0;
	int eB = 0;
	SDL_Rect *fillRectEmo = NULL;

	static int countFramesStatBar_Hap_small = 0;
	static int countFramesStatBar_Ang_small = 0;
	static int countFramesStatBar_Sad_small = 0;
	static int countFramesStatBar_Fea_small = 0;
	static int countFramesStatBar_Int_small = 0;

	if (renderIt) {
		int xLocation = xLoc;
		int yLocation = yLoc;


		modH = whichChar->getHa();
		modA = whichChar->getAn();
		modS = whichChar->getSa();
		modF = whichChar->getFe();
		modI = whichChar->getIn();
		//sdl rect {x,y,w,h}
		SDL_Rect fillRectH = { xLocation + 43, yLocation + 20, modH, eRectHeight };
		SDL_Rect fillRectA = { xLocation + 43, yLocation + 64, modA, eRectHeight };
		SDL_Rect fillRectS = { xLocation + 43, yLocation + 108, modS, eRectHeight };
		SDL_Rect fillRectF = { xLocation + 43, yLocation + 152,modF, eRectHeight };
		SDL_Rect fillRectI = { xLocation + 43, yLocation + 196,modI, eRectHeight };


		tor_E_graph_150_232.render(xLocation, yLocation);//render window which holds graphs



		for (int emotion_small = 1; emotion_small < 6; emotion_small++) {

			eR = 0;
			eG = 0;
			eB = 0;

			if (emotion_small == 1) {

				countFramesStatBar_Hap_small++;

				eR = 255;
				eG = 255;
				eB = 0;
				if (modA <= 89) {

				}
				else if (modA > 89) {
					if ((countFramesStatBar_Hap_small >= 5) && (countFramesStatBar_Hap_small <= 10)) {
						eR = 230;
						eG = 175;
						eB = 0;
					}
					else if ((countFramesStatBar_Hap_small > 10) && (countFramesStatBar_Hap_small < 16)) {
						eR = 210;
						eG = 155;
						eB = 0;
					}
					else if (countFramesStatBar_Hap_small == 16) {
						eR = 240;
						eB = 200;
						eB = 0;
						countFramesStatBar_Hap_small = 0;
					}
				}

				fillRectEmo = &fillRectH;
			}

			else if (emotion_small == 2) {

				countFramesStatBar_Ang_small++;

				eR = 255;
				if (modA <= 89) {

				}
				else if (modA > 89) {
					if ((countFramesStatBar_Ang_small >= 5) && (countFramesStatBar_Ang_small <= 10)) {
						eR = 230;
						eB = 30;
					}
					else if ((countFramesStatBar_Ang_small > 10) && (countFramesStatBar_Ang_small < 16)) {
						eR = 210;
						eB = 60;
					}
					else if (countFramesStatBar_Ang_small == 16) {
						eR = 210;
						eB = 90;
						countFramesStatBar_Ang_small = 0;
					}
				}

				fillRectEmo = &fillRectA;

			}

			else if (emotion_small == 3) {
				countFramesStatBar_Sad_small++;
				eR = 0;
				eG = 0;
				eB = 255;

				if (modS <= 89) {

				}
				else if (modS > 89) {
					if ((countFramesStatBar_Sad_small >= 5) && (countFramesStatBar_Sad_small <= 10)) {
						eR = 50;
						eG = 0;
						eB = 255;
					}
					else if ((countFramesStatBar_Sad_small > 10) && (countFramesStatBar_Sad_small < 16)) {
						eR = 70;
						eG = 50;
						eB = 240;
					}
					else if (countFramesStatBar_Sad_small == 16) {
						eR = 30;
						eG = 45;
						eB = 220;
						countFramesStatBar_Sad_small = 0;
					}
				}

				fillRectEmo = &fillRectS;
			}

			else if (emotion_small == 4) {
				countFramesStatBar_Fea_small++;

				eR = 255;
				eG = 255;
				eB = 255;

				if (modF <= 89) {

				}
				else if (modF > 89) {
					if ((countFramesStatBar_Fea_small >= 5) && (countFramesStatBar_Fea_small <= 10)) {
						eR = 255;
						eG = 230;
						eB = 225;
					}
					else if ((countFramesStatBar_Fea_small > 10) && (countFramesStatBar_Fea_small < 16)) {
						eR = 240;
						eG = 215;
						eB = 235;
					}
					else if (countFramesStatBar_Fea_small == 16) {
						eR = 250;
						eG = 245;
						eB = 230;
						countFramesStatBar_Fea_small = 0;
					}
				}

				fillRectEmo = &fillRectF;
			}

			else if (emotion_small == 5) {

				countFramesStatBar_Int_small++;

				eR = 255;
				eG = 140;
				eB = 0;

				if (modI <= 89) {

				}
				else if (modI > 89) {
					if ((countFramesStatBar_Int_small >= 5) && (countFramesStatBar_Int_small <= 10)) {
						eR = 225;
						eG = 70;
						eB = 0;
					}
					else if ((countFramesStatBar_Int_small > 10) && (countFramesStatBar_Int_small < 16)) {
						eR = 240;
						eG = 115;
						eB = 0;
					}
					else if (countFramesStatBar_Int_small == 16) {
						eR = 255;
						eG = 100;
						eB = 0;
						countFramesStatBar_Int_small = 0;
					}
				}
				fillRectEmo = &fillRectI;
			}

			SDL_SetRenderDrawColor(gRenderer, eR, eG, eB, 0xFF);
			SDL_RenderFillRect(gRenderer, fillRectEmo);

		}
	}
}


void DisplayEStatBar::renderStatBars_large(int multiplier, int eRectH, int xLoc, int yLoc, int em, int subtract) {
	SDL_Event _DisplayRelStatBar___renderStatBars_large;
	SDL_PollEvent(&_DisplayRelStatBar___renderStatBars_large);

	static int countFramesStatBar_H = 0;
	static int countFramesStatBar_A = 0;
	static int countFramesStatBar_S = 0;
	static int countFramesStatBar_F = 0;
	static int countFramesStatBar_I = 0;

	static int countFramesStatBar_sub = 0;

	int eR = 0;
	int eG = 0;
	int eB = 0;

	int xLocation1 = xLoc;
	int yLocation1 = yLoc;


	SDL_Event _DisplayEmoStatBar_renderStatBars_large;
	SDL_PollEvent(&_DisplayEmoStatBar_renderStatBars_large);

	//
	modH = whichChar->getHa();
	modA = whichChar->getAn();
	modS = whichChar->getSa();
	modF = whichChar->getFe();
	modI = whichChar->getIn();


	//sdl rect {x,y,w,h}
	SDL_Rect fillRectH = { xLocation1, yLocation1, modH*multiplier, eRectH };
	SDL_Rect fillRectA = { xLocation1, yLocation1, modA*multiplier, eRectH };
	SDL_Rect fillRectS = { xLocation1, yLocation1, modS*multiplier, eRectH };
	SDL_Rect fillRectF = { xLocation1, yLocation1, modF*multiplier, eRectH };
	SDL_Rect fillRectI = { xLocation1, yLocation1, modI*multiplier, eRectH };

	SDL_Rect *fillRectE = NULL;
	SDL_Rect fillRectSubtract;


	bool highValue = false;

	if (modH >= 89) {
		highValue = true;
	}
	if (modA >= 89) {
		highValue = true;
	}
	if (modS >= 89) {
		highValue = true;
	}
	if (modF >= 89) {
		highValue = true;
	}
	if (modI >= 89) {
		highValue = true;
	}


	if (em == 1) {

		countFramesStatBar_H++;

		eR = 255;
		eG = 255;
		eB = 0;
		if (modA <= 89) {

		}
		else if (modA > 89) {
			if ((countFramesStatBar_H >= 5) && (countFramesStatBar_H <= 10)) {
				eR = 230;
				eG = 175;
				eB = 0;
			}
			else if ((countFramesStatBar_H > 10) && (countFramesStatBar_H < 16)) {
				eR = 210;
				eG = 155;
				eB = 0;
			}
			else if (countFramesStatBar_H == 16) {
				eR = 240;
				eB = 200;
				eB = 0;
				countFramesStatBar_H = 0;
			}
		}

		fillRectE = &fillRectH;
		hE_alpha.render(0, 0);
	}

	else if (em == 2) {

		countFramesStatBar_A++;

		eR = 255;
		if (modA <= 89) {

		}
		else if (modA > 89) {
			if ((countFramesStatBar_A >= 5) && (countFramesStatBar_A <= 10)) {
				eR = 230;
				eB = 30;
			}
			else if ((countFramesStatBar_A > 10) && (countFramesStatBar_A < 16)) {
				eR = 210;
				eB = 60;
			}
			else if (countFramesStatBar_A == 16) {
				eR = 210;
				eB = 90;
				countFramesStatBar_A = 0;
			}
		}

		fillRectE = &fillRectA;
		aE_alpha.render(0, 0);

	}

	else if (em == 3) {
		countFramesStatBar_S++;
		eR = 0;
		eG = 0;
		eB = 255;

		if (modS <= 89) {

		}
		else if (modS > 89) {
			if ((countFramesStatBar_S >= 5) && (countFramesStatBar_S <= 10)) {
				eR = 50;
				eG = 0;
				eB = 255;
			}
			else if ((countFramesStatBar_S > 10) && (countFramesStatBar_S < 16)) {
				eR = 70;
				eG = 50;
				eB = 240;
			}
			else if (countFramesStatBar_S == 16) {
				eR = 30;
				eG = 45;
				eB = 220;
				countFramesStatBar_S = 0;
			}
		}


		fillRectE = &fillRectS;
		sE_alpha.render(0, 0);
	}

	else if (em == 4) {
		countFramesStatBar_F++;

		eR = 255;
		eG = 255;
		eB = 255;

		if (modF <= 89) {

		}
		else if (modF > 89) {
			if ((countFramesStatBar_F >= 5) && (countFramesStatBar_F <= 10)) {
				eR = 255;
				eG = 230;
				eB = 225;
			}
			else if ((countFramesStatBar_F > 10) && (countFramesStatBar_F < 16)) {
				eR = 240;
				eG = 215;
				eB = 235;
			}
			else if (countFramesStatBar_F == 16) {
				eR = 250;
				eG = 245;
				eB = 230;
				countFramesStatBar_F = 0;
			}
		}

		fillRectE = &fillRectF;
		fE_alpha.render(0, 0);

	}

	else if (em == 5) {

		countFramesStatBar_I++;

		eR = 255;
		eG = 140;
		eB = 0;

		if (modI <= 89) {

		}
		else if (modI > 89) {
			if ((countFramesStatBar_I >= 5) && (countFramesStatBar_I <= 10)) {
				eR = 225;
				eG = 70;
				eB = 0;
			}
			else if ((countFramesStatBar_I > 10) && (countFramesStatBar_I < 16)) {
				eR = 240;
				eG = 115;
				eB = 0;
			}
			else if (countFramesStatBar_I == 16) {
				eR = 255;
				eG = 100;
				eB = 0;
				countFramesStatBar_I = 0;
			}
		}


		fillRectE = &fillRectI;
		iE_alpha.render(0, 0);

	}

	if (subtract > 0) {
		countFramesStatBar_sub++;
		if (countFramesStatBar_sub > 5 && countFramesStatBar_sub < 9) {
			fillRectE->w = (fillRectE->w - (subtract*multiplier));
		}
		else if (countFramesStatBar_sub > 8 && countFramesStatBar_sub < 15) {
			fillRectE->w = (fillRectE->w - ((subtract*multiplier) / 2));
		}
		else if (countFramesStatBar_sub > 14 && countFramesStatBar_sub < 20) {
			fillRectE->w = (fillRectE->w - ((subtract*multiplier) / 5));
		}
		else if (countFramesStatBar_sub > 19 && countFramesStatBar_sub < 25) {
			fillRectE->w = (fillRectE->w - ((subtract*multiplier) / 10));
		}
		else if (countFramesStatBar_sub == 25) {
			countFramesStatBar_sub = 0;
			fillRectE->w = (fillRectE->w - (subtract*multiplier));
		}
	}

	else {}

	SDL_SetRenderDrawColor(gRenderer, eR, eG, eB, 0xFF);


	SDL_RenderFillRect(gRenderer, fillRectE);


	if (highValue) {
		fillRectE->x = 0;
		fillRectE->y = 0;
		fillRectE->w = 1600;
		fillRectE->h = 20;
		SDL_SetRenderDrawColor(gRenderer, eR, eG, eB, 50);

		SDL_RenderFillRect(gRenderer, fillRectE);

		fillRectE->x = 0;
		fillRectE->y = SCREEN_HEIGHT - 20;
		fillRectE->w = 1600;
		fillRectE->h = 20;

		SDL_SetRenderDrawColor(gRenderer, eR, eG, eB, 50);

		SDL_RenderFillRect(gRenderer, fillRectE);


		fillRectE->x = 0;
		fillRectE->y = 0;
		fillRectE->w = 20;
		fillRectE->h = 900;

		SDL_SetRenderDrawColor(gRenderer, eR, eG, eB, 50);

		SDL_RenderFillRect(gRenderer, fillRectE);

		fillRectE->x = SCREEN_WIDTH - 20;
		fillRectE->y = 0;
		fillRectE->w = 60;
		fillRectE->h = 900;
		SDL_SetRenderDrawColor(gRenderer, eR, eG, eB, 50);

		SDL_RenderFillRect(gRenderer, fillRectE);
	}

}

void DisplayRelStatBar::setRelChar(Character *assign_whichChar_rel) {
	whichChar_rel = assign_whichChar_rel;
}

void DisplayRelStatBar::rel_renderStatBars(bool renderIt, int xLoc, int yLoc) {

	SDL_Event _DisplayRelStatBar___rel_renderStatBars;
	SDL_PollEvent(&_DisplayRelStatBar___rel_renderStatBars);

	int eR = 0;
	int eG = 0;
	int eB = 0;
	SDL_Rect *fillRectRel = NULL;

	static int countFramesStatBar_relA_small = 0;
	static int countFramesStatBar_relB_small = 0;
	static int countFramesStatBar_relC_small = 0;
	static int countFramesStatBar_relD_small = 0;
	static int countFramesStatBar_relE_small = 0;

	if (renderIt) {
		int xLocation = xLoc;
		int yLocation = yLoc;

		SDL_Event _DisplayEmoStatBar_renderStatBars;
		SDL_PollEvent(&_DisplayEmoStatBar_renderStatBars);


		relA = whichChar_rel->r.aa;
		relB = whichChar_rel->r.bb;
		relC = whichChar_rel->r.cc;
		relD = whichChar_rel->r.dd;
		relE = whichChar_rel->r.ee;


		//sdl rect {x,y,w,h}
		SDL_Rect fillRectAA = { xLocation + 43, yLocation + 20, relA, relRectHeight };
		SDL_Rect fillRectBB = { xLocation + 43, yLocation + 64, relB, relRectHeight };
		SDL_Rect fillRectCC = { xLocation + 43, yLocation + 108, relC, relRectHeight };
		SDL_Rect fillRectDD = { xLocation + 43, yLocation + 152,relD, relRectHeight };
		SDL_Rect fillRectEE = { xLocation + 43, yLocation + 196,relE, relRectHeight };

		tor_R_graph_150_232.render(xLocation, yLocation);


		for (int e_small = 1; e_small < 6; e_small++) {

			eR = 0;
			eG = 0;
			eB = 0;

			if (e_small == 1) {

				countFramesStatBar_relA_small++;

				eR = 255;
				eG = 255;
				eB = 0;
				if (relA <= 89) {

				}
				else if (relA > 89) {
					if ((countFramesStatBar_relA_small >= 5) && (countFramesStatBar_relA_small <= 10)) {
						eR = 230;
						eG = 175;
						eB = 0;
					}
					else if ((countFramesStatBar_relA_small > 10) && (countFramesStatBar_relA_small < 16)) {
						eR = 210;
						eG = 155;
						eB = 0;
					}
					else if (countFramesStatBar_relA_small == 16) {
						eR = 240;
						eB = 200;
						eB = 0;
						countFramesStatBar_relA_small = 0;
					}
				}

				fillRectRel = &fillRectAA;
			}

			else if (e_small == 2) {

				countFramesStatBar_relB_small++;

				relB = 255;
				if (relB <= 89) {

				}
				else if (relB > 89) {
					if ((countFramesStatBar_relB_small >= 5) && (countFramesStatBar_relB_small <= 10)) {
						eR = 230;
						eB = 30;
					}
					else if ((countFramesStatBar_relB_small > 10) && (countFramesStatBar_relB_small < 16)) {
						eR = 210;
						eB = 60;
					}
					else if (countFramesStatBar_relB_small == 16) {
						eR = 210;
						eB = 90;
						countFramesStatBar_relB_small = 0;
					}
				}

				fillRectRel = &fillRectBB;

			}

			else if (e_small == 3) {
				countFramesStatBar_relC_small++;
				eR = 0;
				eG = 0;
				eB = 255;

				if (relC <= 89) {

				}
				else if (relC > 89) {
					if ((countFramesStatBar_relC_small >= 5) && (countFramesStatBar_relC_small <= 10)) {
						eR = 50;
						eG = 0;
						eB = 255;
					}
					else if ((countFramesStatBar_relC_small > 10) && (countFramesStatBar_relC_small < 16)) {
						eR = 70;
						eG = 50;
						eB = 240;
					}
					else if (countFramesStatBar_relC_small == 16) {
						eR = 30;
						eG = 45;
						eB = 220;
						countFramesStatBar_relC_small = 0;
					}
				}

				fillRectRel = &fillRectCC;
			}

			else if (e_small == 4) {
				countFramesStatBar_relD_small++;

				eR = 255;
				eG = 255;
				eB = 255;

				if (relD <= 89) {

				}
				else if (relD > 89) {
					if ((countFramesStatBar_relD_small >= 5) && (countFramesStatBar_relD_small <= 10)) {
						eR = 255;
						eG = 230;
						eB = 225;
					}
					else if ((countFramesStatBar_relD_small > 10) && (countFramesStatBar_relD_small < 16)) {
						eR = 240;
						eG = 215;
						eB = 235;
					}
					else if (countFramesStatBar_relD_small == 16) {
						eR = 250;
						eG = 245;
						eB = 230;
						countFramesStatBar_relD_small = 0;
					}
				}

				fillRectRel = &fillRectDD;
			}

			else if (e_small == 5) {

				countFramesStatBar_relE_small++;

				eR = 255;
				eG = 140;
				eB = 0;

				if (relE <= 89) {

				}
				else if (relE > 89) {
					if ((countFramesStatBar_relE_small >= 5) && (countFramesStatBar_relE_small <= 10)) {
						eR = 225;
						eG = 70;
						eB = 0;
					}
					else if ((countFramesStatBar_relE_small > 10) && (countFramesStatBar_relE_small < 16)) {
						eR = 240;
						eG = 115;
						eB = 0;
					}
					else if (countFramesStatBar_relE_small == 16) {
						eR = 255;
						eG = 100;
						eB = 0;
						countFramesStatBar_relE_small = 0;
					}
				}
				fillRectRel = &fillRectEE;
			}

			SDL_SetRenderDrawColor(gRenderer, eR, eG, eB, 0xFF);
			SDL_RenderFillRect(gRenderer, fillRectRel);

		}
	}


}

//Robert Misener 2018 
//www.RobertMisener.com