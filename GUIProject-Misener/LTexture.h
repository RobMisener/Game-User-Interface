#ifndef LTEXTURE_H
#define LTEXTURE_H

//Using SDL, SDL_image, SDL_ttf, standard IO, math, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>


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

//The window renderer
extern SDL_Renderer* gRenderer;

//Globally used font
extern TTF_Font *gFont;



//Texture wrapper class
class LTexture
{
public:
	//Initializes variables
	LTexture();

	//Deallocates memory
	~LTexture();

	//Creates blank texture
	bool createBlank(int width, int height, SDL_TextureAccess = SDL_TEXTUREACCESS_STREAMING);
	void setAsRenderTarget();
	//Loads image at specified path
	bool loadFromFile(string path);


#ifdef _SDL_TTF_H
	//Creates image from font string
	bool loadFromRenderedText(string textureText, SDL_Color textColor);
#endif

	//Deallocates texture
	void free();

	//Set color modulation
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	//Set blending
	void setBlendMode(SDL_BlendMode blending);

	//Set alpha modulation
	void setAlpha(Uint8 alpha);

	//Renders texture at given point
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//Gets image dimensions
	int getWidth();
	int getHeight();

	//Gets image dimensions
	int getPosX();
	int getPosY();

	inline void setPos(int x, int y) {
		posXX = x;
		posYY = y;
	}

	int setWidthHeight(int w, int h);
	bool BOOLsetWidthHeight;
	int newWidth;
	int newHeight;

	int alphaR;
	int alphaG;
	int alphaB;

private:
	//The actual hardware texture
	SDL_Texture * mTexture;

	int posXX;
	int posYY;

	//Image dimensions
	int mWidth;
	int mHeight;
};

#endif
//copyright Robert Misener 2018
//www.RobertMisener.com