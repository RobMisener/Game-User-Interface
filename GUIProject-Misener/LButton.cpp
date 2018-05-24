
#include "LButton.h"
#include "LTexture.h"

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


CommonButton::CommonButton(){
            buttonClickOn = false;
            currentSpriteEnumNumber = 0;

            numberOfClips = 0;
            mPosition.x = 0;
            mPosition.y = 0;

            buttonXYWH.x = 0;
            buttonXYWH.y = 0;
            buttonXYWH.w = 0;
            buttonXYWH.h = 0;


}





void CommonButton::handleEvent( SDL_Event* e ){
static int mouseOver = 30;

	//If mouse event happened
	if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );

		//Check if mouse is iE button
		bool inside = true;

		//Mouse is left of the button
		if( x < mPosition.x )
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( x > mPosition.x + buttonXYWH.w )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < mPosition.y )
		{
			inside = false;
		}
		//Mouse below the button
		else if( y > mPosition.y + buttonXYWH.h )
		{
			inside = false;
		}

		//Mouse is outside button
		if( !inside )
		{
			currentSpriteEnumNumber = enChoice_BUTTON_SPRITE_MOUSE_OUT;
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch( e->type )
			{
				case SDL_MOUSEMOTION:
					//Mix_PlayChannel( -1, tHover, 0 );
					currentSpriteEnumNumber = enChoice_BUTTON_SPRITE_MOUSE_OVER_MOTION;
					if (mouseOver == 30){
					//Mix_PlayChannel( -1, tHover, 0 );
					mouseOver -= 30;
					}
					mouseOver += 1;

					break;

				case SDL_MOUSEBUTTONDOWN:
					currentSpriteEnumNumber = enChoice_BUTTON_SPRITE_MOUSE_DOWN;
					if (!buttonClickOn){
					buttonClickOn = true;
					}
					if (buttonClickOn){
					buttonClickOn = false;
					}
					break;
				case SDL_MOUSEBUTTONUP:
					currentSpriteEnumNumber = enChoice_BUTTON_SPRITE_MOUSE_UP;
					break;
			}
		}
	}

}


void CommonButton::setPosition( int xx, int yy ){
    buttonXYWH.x=xx;
    buttonXYWH.y=yy;
}
void CommonButton::setWidthHeight( int ww, int hh ){
    buttonXYWH.w=ww;
    buttonXYWH.h=hh;
}
void CommonButton::howManyClips(int numOfClips){
numberOfClips = numOfClips;
}
void CommonButton::setQuads() {
		   for (int i = 0; i<numberOfClips; i++){
			SDL_Rect_gSpriteClips[ i ].x = buttonXYWH.x;
			SDL_Rect_gSpriteClips[ i ].y = buttonXYWH.h;
			SDL_Rect_gSpriteClips[ i ].w = buttonXYWH.w;
			SDL_Rect_gSpriteClips[ i ].h = buttonXYWH.h;
		}
}




bool LButton::getButtonClickOn(){
            return buttonClickOn;
//            cout << endl << "button click on = " << getButtonClickOn()<< endl;
        }


LButton::LButton()
{
	mPosition.x = 0;
	mPosition.y = 0;
    buttonClickOn = false;


}

void LButton::setPosition( int x, int y )
{
    mPosition.x = x;
	mPosition.y = y;
}


int LButton::getPositionX(){
return mPosition.x;
}

int LButton::getPositionY(){
return mPosition.y;
}


void LButton::setWidthHeight( int w, int h )
{
	BUTTON_WIDTH = w;
	BUTTON_HEIGHT = h;
}



void LButton::setButtonClickon(bool isTrue){
            buttonClickOn = isTrue;
		}

void LButton::handleEvent( SDL_Event* e )
{
	static int mouseOver = 30;
	static int clickOn = 0;

	//If mouse event happened
	if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );

		//Check if mouse is iE button
		bool inside = true;

		//Mouse is left of the button
		if( x < mPosition.x )
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( x > mPosition.x + BUTTON_WIDTH )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < mPosition.y )
		{
			inside = false;
		}
		//Mouse below the button
		else if( y > mPosition.y + BUTTON_HEIGHT )
		{
			inside = false;
		}

		//Mouse is outside button
		if( !inside )
		{
			enum_mCurrentSprite = enChoice_BUTTON_SPRITE_MOUSE_OUT;
		}

		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch( e->type )
			{
				case SDL_MOUSEMOTION:

                //Mix_PlayChannel( -1, tHover, 0 );
				enum_mCurrentSprite = enChoice_BUTTON_SPRITE_MOUSE_OVER_MOTION;
                if (mouseOver == 30){
                //Mix_PlayChannel( -1, tHover, 0 );
                mouseOver -= 30;
                }
                mouseOver += 1;

				break;

				case SDL_MOUSEBUTTONDOWN:

				enum_mCurrentSprite = enChoice_BUTTON_SPRITE_MOUSE_DOWN;
//                static int countthis = 0;
//                countthis++;
//                cout << "click" << countthis << endl;

				if (clickOn == 0){
				buttonClickOn = true;
				clickOn = 1;
				}
				else {
                    buttonClickOn = false;
                    clickOn = 0;

				}

				break;

				case SDL_MOUSEBUTTONUP:
				enum_mCurrentSprite = enChoice_BUTTON_SPRITE_MOUSE_UP;
				break;
			}
		}
	}
}

void LButton::setSpriteSheet (string filename){

//Get rid of preexisting texture
//free();

SDL_Texture *newTexture;
//Load image at specified path
SDL_Surface* loadedSurface = IMG_Load( filename.c_str() );

//Color key image
SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

//Create texture from surface pixels
newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );

//Get image dimensions
mWidth = loadedSurface->w;
mHeight = loadedSurface->h;

//Get rid of old loaded surface
SDL_FreeSurface( loadedSurface );

//Return success
gSpriteSheetTexture = newTexture;

/*

gSpriteSheetTexture = &getSpriteSheetTexture;

    if( !gSpriteSheetTexture->loadFromFile( filename )) {
            cout << "error" << endl;}
    else{}
*/
}

void LButton::free()
{
	//Free texture if it exists
	if( gSpriteSheetTexture != NULL )
	{
		SDL_DestroyTexture( gSpriteSheetTexture );
		gSpriteSheetTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}



void LButton::setSpriteClips4(int x, int y, int w, int h){
		//Set sprites
/*		cout << " y = " << y << endl;
		cout << "BUTTON_WIDTH = " << BUTTON_WIDTH <<  " BUTTON_HEIGHT= " << BUTTON_HEIGHT << endl;
*/
		//for( int i = 0; i < 4; ++i )
		//{
		   //cout  << " i = " << i << endl;

		   for (int i = 0; i<4; i++){

			SDL_Rect_gSpriteClips[ i ].x = x;
			SDL_Rect_gSpriteClips[ i ].y = i * h;
			SDL_Rect_gSpriteClips[ i ].w = w;
			SDL_Rect_gSpriteClips[ i ].h = h;

		}
		//}
}

void LButton::setSpriteClips3(int x, int y, int w, int h){
		//Set sprites
/*		cout << " y = " << y << endl;
		cout << "BUTTON_WIDTH = " << BUTTON_WIDTH <<  " BUTTON_HEIGHT= " << BUTTON_HEIGHT << endl;
*/
		//for( int i = 0; i < 4; ++i )
		//{
		   //cout  << " i = " << i << endl;

		   for (int i = 0; i<3; i++){
			SDL_Rect_gSpriteClips[ i ].x = x*i;
			SDL_Rect_gSpriteClips[ i ].y = i * y;
			SDL_Rect_gSpriteClips[ i ].w = w;
			SDL_Rect_gSpriteClips[ i ].h = h;
		}
		//}
}

void LButton::setSpriteClips2(int x, int y, int w, int h){
		//Set sprites
/*		cout << " y = " << y << endl;
		cout << "BUTTON_WIDTH = " << BUTTON_WIDTH <<  " BUTTON_HEIGHT= " << BUTTON_HEIGHT << endl;
*/
		//for( int i = 0; i < 4; ++i )
		//{
		   //cout  << " i = " << i << endl;

		   for (int i = 0; i<2; i++){
			SDL_Rect_gSpriteClips[ i ].x = x*i;
			SDL_Rect_gSpriteClips[ i ].y = i * y;
			SDL_Rect_gSpriteClips[ i ].w = w;
			SDL_Rect_gSpriteClips[ i ].h = h;
		}
		//}
}

int LButton:: getWidth(){
return SDL_Rect_gSpriteClips[0].w;
}

int LButton:: getHeight(){
return SDL_Rect_gSpriteClips[0].h;

}


void LButton::printQuads(int howMany){

for (int i=0; i< howMany; i++ ){
    cout << "quad " << i << "x= " << SDL_Rect_gSpriteClips[i].x << endl;
    cout << "quad " << i << "y= " <<  SDL_Rect_gSpriteClips[i].y << endl;
    cout << "quad " << i << "w= "  << SDL_Rect_gSpriteClips[i].w << endl;
    cout << "quad " << i << "h= "  << SDL_Rect_gSpriteClips[i].h << endl;
}


}

void LButton::render(){

double angle = 0.0;
SDL_Point* center = NULL;
SDL_RendererFlip flip = SDL_FLIP_NONE;

//SDL_Rect SDL2222_Rect_gSpriteClips = {0 , 68, 125 , 68 };

SDL_Rect* clip = &SDL_Rect_gSpriteClips[enum_mCurrentSprite];

//SDL_Rect_gSpriteClips

	//Set rendering space and render to screen
SDL_Rect renderQuad = { mPosition.x, mPosition.y, mWidth, mHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	/*
                                            SDL_Renderer * renderer,
                                           SDL_Texture * texture,
                                           const SDL_Rect * srcrect,
                                           const SDL_Rect * dstrect,
                                           const double angle,
                                           const SDL_Point *center,
                                           const SDL_RendererFlip flip);

                   */

	SDL_RenderCopyEx( gRenderer, gSpriteSheetTexture, clip, &renderQuad, angle, center, flip);

    //cout << enum_mCurrentSprite;
	//Show current button sprite
	//gSpriteSheetTexture->render( mPosition.x, mPosition.y, &SDL_Rect_gSpriteClips[ enum_mCurrentSprite ] );

}

//Copyright Robert Misener 2018 
//www.RobertMisener.com
