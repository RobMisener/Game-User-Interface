

#include "LTexture.h"

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


LTexture::LTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
	alphaR = 255;
	alphaG = 0;
	alphaB = 255;

	posXX = NULL;
    posYY = NULL;

BOOLsetWidthHeight = false;
}

LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool LTexture::createBlank( int width, int height, SDL_TextureAccess access )
{
    //Create uninitialized texture
    mTexture = SDL_CreateTexture( gRenderer, SDL_PIXELFORMAT_RGBA8888, access, width, height );
    if( mTexture == NULL )
    {
        printf( "Unable to create blank texture! SDL Error: %s\n", SDL_GetError() );
    }
    else
    {
        mWidth = width;
        mHeight = height;
    }

    return mTexture != NULL;
}

void LTexture::setAsRenderTarget()
{
    //Make self render target
    SDL_SetRenderTarget( gRenderer, mTexture );
}

int LTexture::setWidthHeight(int w, int h){
mWidth = w;
mHeight = h;
newWidth = w;
newHeight = h;

return true;

}


int LTexture::getPosX(){
return posXX;
}

int LTexture::getPosY(){
return posYY;
}


bool LTexture::loadFromFile( string path )
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;


	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );


	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
	    Uint32 colorkey = SDL_MapRGB( loadedSurface->format, alphaR, alphaG, alphaB );
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, colorkey );
		//SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
		    if (BOOLsetWidthHeight == false){
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		    }
		    else if (BOOLsetWidthHeight == true)
            {
           mWidth = newWidth;
           mHeight = newHeight;
            }
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}


#ifdef _SDL_TTF_H
bool LTexture::loadFromRenderedText( string textureText, SDL_Color textColor )
{
	//Get rid of preexisting texture
	free();

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
	if( textSurface == NULL )
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
		if( mTexture == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface( textSurface );
	}

	//Return success
	return mTexture != NULL;
}
#endif

void LTexture::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	//Modulate texture rgb
	SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void LTexture::setBlendMode( SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( mTexture, blending );
}

void LTexture::setAlpha( Uint8 alpha )
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod( mTexture, alpha );
}

void LTexture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
    if( x != NULL ){
        posXX = x;
    }

    if( y != NULL ){
        posYY = y;
    }
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { posXX, posYY, mWidth, mHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}



	//Render to screen
	SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}



//copyright Robert Misener 2018