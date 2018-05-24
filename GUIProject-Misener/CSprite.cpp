

#include "Character.h"
#include "LTexture.h"
#include "DisplayEStatBar.h"
#include "CSprite.h"



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

//const int WALK_ANI_FRAMES = 60;

extern bool checkCollision( SDL_Rect a, SDL_Rect b );
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern int find_avg_to();


extern int avg_ag();
extern int avg_am();
extern int avg_di();
extern int avg_lo();
extern int avg_re();
//extern Character a;
//extern Character b;
//extern Character c;
//extern Character d;
//extern Character e;



CommonSprite::CommonSprite(){

    slowFrameOn = false;
    slowClip = 0;
    slowClipNew = 0;
    nextClipNum = 0;
    mPos.x = 0;
    mPos.y = 0;
    totalFrames = 0;
    quadWidth = 0;
    quadHeight = 0;

    frameNum = 0;
    buttonClicked = false;
    spriteAnimationComplete = false;
    freezeFrame = false;
    reverseSetFrameNum_firstTime = true;
    spriteAniComplete = false;
    reverseIsTrue = false;
    animationFinished = false;
    frameReachedTotal = false;
}


void CommonSprite::freeze_final_frame(bool trueOrFalse){
freezeFrame = trueOrFalse;
}


//
//int CommonSprite::getHeight(){
//
//return quadHeight;
//
//}

void CommonSprite::setQuads(int w, int h, int r, int c, int spriteRow, bool horizontal){
//spriteRow, is pos of y iE sprite, if muliple sprites


quadWidth = w;
quadHeight = h;
bool printQuadStats;

if (!horizontal){
    for (int column=0;column<c;column++ ){

        for (int row=spriteRow;row<r+spriteRow;row++ ){
            quadSprite[nextClipNum].x = w*column;
            quadSprite[nextClipNum].y = row*h;
            quadSprite[nextClipNum].w = w;
            quadSprite[nextClipNum].h = h;
            nextClipNum++;
//
//            cout << ".x = " << w*column << endl;
//            cout << ".y = " << row*h << endl;
//            cout << ".w = " <<  w << endl;
//            cout << ".h = " << h << endl;
//            cout << ".nextClipNum = " << nextClipNum << endl;
        }

     }
}



if (horizontal){
    for (int row=spriteRow;row<r+spriteRow;row++ ){

         for (int column=0;column<c;column++ ){
                quadSprite[nextClipNum].x = w*column;
                quadSprite[nextClipNum].y = row*h;
                quadSprite[nextClipNum].w = w;
                quadSprite[nextClipNum].h = h;
                nextClipNum++;

//                cout << ".x = " << w*column << endl;
//                cout << ".y = " << row*h << endl;
//                cout << ".w = " <<  w << endl;
//                cout << ".h = " << h << endl;
//                cout << ".nextClipNum = " << nextClipNum << endl;
            }

     }
}


}

void CommonSprite:: setTotalFrames(int fNum){
    totalFrames = fNum;
}

void CommonSprite::print_quad_cord(){
    for (int i=0;i<totalFrames;i++ ){
//        cout << "Quad number = " << i << endl;
//        cout << "x = " << quadSprite[i].x << endl;
//        cout << "y = " << quadSprite[i].y << endl;
//        cout << "w = " << quadSprite[i].w << endl;
//        cout << "h = " << quadSprite[i].h << endl << endl;
    }

}

void CommonSprite::free(){
tSpriteSheet->free();
}


void CommonSprite::setPos(int x, int y){
    mPos.x = x;
    mPos.y = y;
}


int CommonSprite::getWidth()//returns width of sprite quad
{
    return quadSprite[0].w;
}


int CommonSprite::getHeight()//returns width of sprite quad
{
    return quadSprite[0].h;
}


int CommonSprite::getPosX(){
    return mPos.x;
    }


int CommonSprite::getPosY(){
    return mPos.y;
    }

bool CommonSprite::animationComplete(){
    return spriteAniComplete;
}

void CommonSprite::resetAnimation(){
    spriteAniComplete = false;
    frameReachedTotal = false;
    setFrameNum(0);
}

void CommonSprite::render_forward_reverse(){

    //cout << "slowClipNew1 = " << slowClipNew << endl;
//if slow clip enabled
    if (slowClip > 0){

    slowClipNew-=1;

        if (slowClipNew == 1){

            if (!reverseIsTrue){

                //if frame number has not reached the frame limit - 1 (for arrays)
                if ( frameNum < totalFrames-1){
                    frameNum++;
                    if (slowClipNew == 1){slowClipNew = slowClip;}
                }

                else if ( frameNum == totalFrames-1){
                    reverseIsTrue = true;
                    frameNum--;
                    if (slowClipNew == 1){slowClipNew = slowClip;}
                }
            }
            else if (reverseIsTrue){
                if ( frameNum > 0){
                    frameNum--;
                    if (slowClipNew == 1){slowClipNew = slowClip;}
                }

                if (freezeFrame){
                    if ( frameNum == 0){
                        spriteAniComplete = true;
                        if (slowClipNew == 1){slowClipNew = slowClip;}
                    }
                }
                else if (!freezeFrame){
                    if ( frameNum == 0){
                            //if not freeze frame, when frame reaches 0 change the reverse flag off
                        reverseIsTrue = false;
                        if (slowClipNew == 1)slowClipNew = slowClip;//if slow clip reaches 1, reset newslowclip to original slowclip length
                    }
                }
            }
        }
    }

    //if slow is off
    if (slowClip == 0){
    if (!reverseIsTrue){
            if ( frameNum < totalFrames-1){
                frameNum++;
            }

            else if ( frameNum == totalFrames-1){
                reverseIsTrue = true;
                 frameNum--;
            }
    }
    else if (reverseIsTrue){
            if ( frameNum > 0){
                frameNum--;
            }

            if (freezeFrame){
                if ( frameNum == 0){
                    spriteAniComplete = true;
                }
            }
            else if (!freezeFrame){
                if ( frameNum == 0){
                    reverseIsTrue = false;
                }
            }
    }


    }
	tSpriteSheet->render(mPos.x, mPos.y, &quadSprite[frameNum]);
}

void CommonSprite::printFrameNum(){
cout << endl << "frameNum = " << frameNum << endl;

}

void CommonSprite::render(bool reverseRender){
//cout << "slowClipnew = " << slowClipNew << endl;
//cout << "slowClip = " << slowClip << endl;


//if reverse render is not true
    if (!reverseRender){

            //if slow clip enabled
        if (slowClip > 0){

            //if frame has not reached total decrease slowClip changing number by 1
            if (!frameReachedTotal) slowClipNew-=1;

                //if slow clip reaches 1;
                if (slowClipNew == 1){
                       // cout << "slowClip = " << slowClip << endl;
                       // cout << "slowClipNew = " << slowClipNew << endl;

                    //if frame hasnt reached total
                    if (!frameReachedTotal){

                        //if the current frame number is less than total frames and freeze frame is off
                        if ( (frameNum < totalFrames) &&(!freezeFrame) ){
                            frameNum++;
                            if (slowClipNew == 1)slowClipNew = slowClip; // if slowClipNew reaches 1 reset to original slowclip value
                            if ( frameNum == totalFrames)  frameReachedTotal = true;//if reached final frame flag frameReached total true
                        }
                        //else if the current frame number is less than total frames and freeze frame is on
                        else if ( (frameNum < totalFrames) &&(freezeFrame)){
                            frameNum++;
                            if (slowClipNew == 1) slowClipNew = slowClip; // if slowClipNew reaches 1 reset to original slowclip value
                            if ( frameNum == totalFrames)frameReachedTotal = true;//if reached final frame flag frameReached total true
                        }
                    }
                }

    //if freezeFrame
            if (freezeFrame){
                if ( frameNum == totalFrames){
                frameNum = totalFrames-1;
                spriteAniComplete = true;
                }
            }
            else if (!freezeFrame){
                if (frameReachedTotal){
                    frameNum = 0;
                    spriteAniComplete = true;
            }

        }
            //if freezeFrame is enabled and the frame number has reached the total frame limit, subtract one for proper array render and mark animation complete
            if (freezeFrame){
                if ( frameNum == totalFrames){
                    frameNum = totalFrames-1;
                    spriteAniComplete = true;
                }
            }
            //else if freezeFrame is not ebabled and frame number has reached total, set the frame number to the first frame of image and mark animation as complete
            else if (!freezeFrame){
                if (frameReachedTotal){
                    frameNum = 0;
                    spriteAniComplete = true;
                }
            }
        }

    //if slow is off
    if (slowClip == 0){

        if (!frameReachedTotal){

            if ( (frameNum < totalFrames) &&(!freezeFrame) ){
                frameNum++;

                if ( frameNum == totalFrames){
                frameReachedTotal = true;
                }
            }
            else if ( (frameNum < totalFrames) &&(freezeFrame)){
                frameNum++;
            }

        }
//https://en.wikipedia.org/wiki/Nassi%E2%80%93Shneiderman_diagram
    //if freezeFrame
            if (freezeFrame){
                if ( frameNum == totalFrames){
                frameNum = totalFrames-1;
                spriteAniComplete = true;
                }
            }
            else if (!freezeFrame){
                if (frameReachedTotal){
                    frameNum = 0;
                    spriteAniComplete = true;
            }

        }

//if (frameNum == totalFrames-1){}
    }
    tSpriteSheet->render( mPos.x, mPos.y, &quadSprite[frameNum] );
}


///////////////////////////////reverse
    if (reverseRender){
        reverseSetFrameNum();
            //cout << "slowClipNew1 = " << slowClipNew << endl;

    if (slowClip > 0){

    slowClipNew-=1;

    if (slowClipNew == 1){
           // cout << "slowClip = " << slowClip << endl;
           // cout << "slowClipNew = " << slowClipNew << endl;

        if ( frameNum > totalFrames-totalFrames){
            frameNum--;
            if (slowClipNew == 1){
            slowClipNew = slowClip;
            }
        }

        if (freezeFrame){
            if ( frameNum == totalFrames-totalFrames){
                frameNum = totalFrames-totalFrames;
            }
        }

        //cout << frameNum;

    }
    }
        if (slowClip == 0){

            if ( frameNum > totalFrames-totalFrames){
                frameNum--;
            }
                else{}
            if (freezeFrame){
                if ( frameNum == totalFrames-totalFrames){
                frameNum = totalFrames-totalFrames;
                }
            }

        }

if (frameNum == 0){spriteAniComplete = true;}
    tSpriteSheet->render( mPos.x, mPos.y, &quadSprite[frameNum] );
    }



}



void CommonSprite::setSprite(LTexture *sprite){
tSpriteSheet = sprite;
}


void CSprite::setSprite(LTexture *sprite){
tSpriteSheet = sprite;
}

void CommonSprite::setFrameNum(int whichFrame){
    frameNum = whichFrame;
}

void CommonSprite::slow_clip_by(int x){
slowClip = x;
slowClipNew = slowClip;
slowFrameOn = true;
}

void CommonSprite::reverseSetFrameNum(){


    if (reverseSetFrameNum_firstTime){
        frameNum = totalFrames;
        reverseSetFrameNum_firstTime = false;
    }

    tSpriteSheet->render( mPos.x, mPos.y, &quadSprite[frameNum] );

}



CSprite::CSprite(){
  //stat bar to display emotional stats

playerTarget = false;


    quad_Width = 0;
    quad_Height = 0;

    moveSpaces = 0;


    //The velocity of the dot
    velX = 0;
    velY = 0;

    cCollision.w = 0; //not used
    cCollision.h = 0;//not used

    mPos.x = 0;
    mPos.y = 0;
    rightButtonClicked = false;
    //isMainC = false;
}


void CSprite::setCharacter(Character *whichCharacter){
            CharacterPtr = whichCharacter;
        }

bool CSprite::isBoundaryClicked (){
return rightButtonClicked;

}

void CSprite::change_clickDisplayRectOutlineBool (bool changeButtonPress){
            outlineRectButtonTrue = changeButtonPress;
}

bool CSprite::get_clickDisplayRectOutlineEvent(){
    return outlineRectButtonTrue;//cout << "outlineRectButtonTrue = " << outlineRectButtonTrue << endl;
}

void CSprite::change_clickDisplayStatBarEvent(bool changeTrue){
    rightButtonClicked = changeTrue;
}


void CSprite::setWalls(SDL_Rect *qa, SDL_Rect *qb, SDL_Rect *qc, SDL_Rect *qd, SDL_Rect *qe,SDL_Rect *qu1, SDL_Rect *qu2, SDL_Rect *qf ){

SDL_Rect *wallPtrArray[8] = {qa, qb, qc, qd, qe , qu1, qu2};

for (int i=0; i<9; i++){
wallArray[i] = wallPtrArray[i];
}

}





//function to set whether the player is selected
void CSprite::targetPlayer(bool trueOrNot){
    playerTarget = trueOrNot;
}

//function to return the private value that stores whether the player is selected
bool CSprite::isTargetPlayer(){
        return playerTarget;
}


//find the current boundary range and location of cSprite
SDL_Rect CSprite::currentLocBounds(){
    return currentLocationAndWidthHeight;
}


void CSprite::changeClick(bool changeClickTrueOrFalse){
    rightButtonClicked = changeClickTrueOrFalse;
}





void CSprite::clickDisplayStatBarEvent(SDL_Event *cd){
	//If mouse event happened
	if (cd->type == SDL_MOUSEBUTTONDOWN )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );

		//Check if mouse is iE button
		bool inside = true;

		//Mouse is left of the button
		if( x < mPos.x )
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( x > mPos.x + cBoundary.w )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < mPos.y )
		{
			inside = false;
		}
		//Mouse below the button
		else if( y > mPos.y + cBoundary.h )
		{
			inside = false;
		}

		//Mouse is outside button
		if( !inside )
		{
			cout << endl << "8373 : mouse is not on character ";
		}
		//Mouse is inside button
		else
		{

		    if (!rightButtonClicked){
			//Set mouse over sprite
			switch( cd->type  )
			{
			    case SDL_MOUSEBUTTONDOWN:
                rightButtonClicked = true;
                break;

			}
            }
            else if (rightButtonClicked){

                switch( cd->type  )
                {
			    case SDL_MOUSEBUTTONDOWN:
                rightButtonClicked = false;
                break;

                }
            }
        //if previous click false
		    if (!outlineRectButtonTrue){
			//Set mouse over sprite
			switch( cd->type  )
			{
			    case SDL_MOUSEBUTTONDOWN:
                outlineRectButtonTrue = true;
                break;

			}

            }
            //if previous click true
            else if (outlineRectButtonTrue){

                switch( cd->type  )
                {
			    case SDL_MOUSEBUTTONDOWN:
                outlineRectButtonTrue = false;
                break;

                }
            }

















        }
    }
}

//enables clickDisplayRectOutlineEvent, so it does not pick up on early actions
void CSprite::enable_clickDisplayRectOutlineEvent(bool isItTrue){
start_clickDisplayRectOutlineEvent = isItTrue;
}

void CSprite::clickDisplayRectOutlineEvent(SDL_Event *eventRectOutline){

	//If mouse event happened
	if ( eventRectOutline->type == SDL_MOUSEBUTTONDOWN )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );

		//Check if mouse is iE button
		bool inside = true;

		//Mouse is left of the button
		if( x < mPos.x )
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( x > mPos.x + cBoundary.w )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < mPos.y )
		{
			inside = false;
		}
		//Mouse below the button
		else if( y > mPos.y + cBoundary.h )
		{
			inside = false;//
//    tSpriteSheet->render( mPos.x, mPos.y, &quadSprite[frameNum] );//render the image
//
//    //not sure if below is really needed
//    currentLocationAndWidthHeight.x = mPos.x;//set current location structure to current location of sprite x
//    currentLocationAndWidthHeight.y = mPos.y;//set current location structure to current location of sprite y
//    currentLocationAndWidthHeight.w = quadSprite[frameNum].w;//set current widthHeight structure to current width of clip
//    currentLocationAndWidthHeight.h = quadSprite[frameNum].h;//set current widthHeight structure to current height of clip
//}
		}

		//Mouse is outside button
		if( !inside )
		{
		}
		//Mouse is inside button
		else
		{

            //if previous click false
		    if (!outlineRectButtonTrue){
			//Set mouse over sprite
			switch( eventRectOutline->type  )
			{
			    case SDL_MOUSEBUTTONDOWN:
                outlineRectButtonTrue = true;
                break;

			}

            }
            //if previous click true
            else if (outlineRectButtonTrue){

                switch( eventRectOutline->type  )
                {
			    case SDL_MOUSEBUTTONDOWN:
                outlineRectButtonTrue = false;
                break;

                }
            }
        }
    }

}



void CSprite::handleEvent(SDL_Event& e)
{

    //cout << "---|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||---" << endl;

//        if (isMainC == true){
                        //If a key was pressed
            if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
            {
                //Adjust the velocity
                switch( e.key.keysym.sym )
                {
//                    cout << "--------------keydown--------------" << endl;
                    case SDLK_UP: velY -= CVEL; break;
                    case SDLK_DOWN: velY += CVEL; break;
                    case SDLK_LEFT: velX -= CVEL; break;
                    case SDLK_RIGHT: velX += CVEL; break;
                }
            }
                            //If a key was released
            else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
            {
                //Adjust the velocity
                switch( e.key.keysym.sym )
                {
//                    cout << "------------keyup---------" << endl;
                    case SDLK_UP: velY += CVEL; break;
                    case SDLK_DOWN: velY -= CVEL; break;
                    case SDLK_LEFT: velX += CVEL; break;
                    case SDLK_RIGHT: velX -= CVEL; break;
                }
            }
            else{}



        //}
        //else{}

        //}
        //else{}
//cout << "iE here";
//cout << "velY = " << velY;
    }


void CSprite::moveNPC(int _direction, int _moveSpaces){

    SDL_Event cSprite_moveNPC;
    SDL_PollEvent( &cSprite_moveNPC );

    moveSpaces = _direction;



}

void CSprite::movePos(){

   // cout<<"iE here" <<frameNum;

    SDL_Event _CSprite_movePos;
    SDL_PollEvent( &_CSprite_movePos );

    //if move__Spaces is on, increase the velY and velX by 0
    if (moveSpaces>0){

        velY = 0;
        velX = 0;
        moveSpaces--; //subtract the number of movespaces

        if (moveSpaces == 1){ velY -= CVEL; } //if moveNPC direction is up decrease velocity by y
        if (moveSpaces == 2){ velY += CVEL; } //if moveNPC direction is down increase velocity by y
        if (moveSpaces == 3){  velX -= CVEL; } //if moveNPC direction is left decrease velocity by x
        if (moveSpaces == 4){ velX += CVEL; } //if moveNPC direction is right increase velocity by x

        //if moveNPC spaces is equal to 0, reset the velocity and spaces to initial values
        if (moveSpaces == 1) {
            velY = 0;
            velX = 0;
            moveSpaces = 0;
        }
    }

    //else if moveNPC spaces is off do nothing
    else if (moveSpaces <= 0)
    {

    }

    else{}//else do nothing



    int posX_old = mPos.x; //record old x position of sprite into a value

    mPos.x += velX;//increase new x position by velocity value
    cCollision.x = mPos.x; //set collision boundary to new x position

    //If the dot went too far to the left or right
    if( ( mPos.x < 0 ) || (  mPos.x + quadWidth > SCREEN_WIDTH ) ) // || ( checkCollision( cCollision, *wallArray[2]) == true) )
    {
        mPos.x -= velX;//Move position back due to edge collision
        cCollision.x = mPos.x; //set collision boundary to the modified position
    }

/* ununsed collision boundary code
        for (int i=0; i<9; i++){
         if( checkCollision( cCollision, *wallArray[i]))
         {
                         //Move back
            mPos.x -= velX;
            cCollision.x = mPos.x;
         }
        }
*/

    int posY_old = mPos.y; //record old y position of sprite into a value

    mPos.y += velY; //increase new y position by y velocity value
    cCollision.y = mPos.y;//set collision boundary to new y position

    ///If the dot went too far up or down
    if( ( mPos.y < 0 ) || ( mPos.y + quadHeight > SCREEN_HEIGHT ))  //||( checkCollision( cCollision, *wallArray[2]) == true))
    {
        //Move back
        mPos.y -= velY; //Move position back due to edge collision
        cCollision.y = mPos.y; //set collision boundary of y to the modified position
    }

    ///set direction indicator bools
    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;

    ///if position x,y is different than old position, set direction indicators to true
    if (mPos.y > posY_old) { moveDown =true;}
    if (mPos.y < posY_old) { moveUp =true;}
    if (mPos.x > posX_old) { moveRight =true;}
    if (mPos.x < posX_old) { moveLeft =true;}


if (!slowFrameOn){
    if (moveDown){
         frameNum++;
         if (frameNum > 14){frameNum = 0;}
    }

    if (moveUp){
         frameNum++;
        if ((frameNum  < 15) || (frameNum  > 29)){frameNum = 15;}
     }

    if (moveRight){
         frameNum++;
        if ((frameNum < 30) || (frameNum > 44)){frameNum = 30;}

     }
    if (moveLeft){
         frameNum++;
        if ((frameNum < 45) || (frameNum > 59)){frameNum = 45;}
     }
}

//else if slow frame is true
else if (slowFrameOn){
        //code to slow frame rate
    if (slowClipNew == 1){

       if (moveDown){
             frameNum++;
             if (frameNum > 14){frameNum=0;}
        }

        if (moveUp){
             frameNum++;
            if ((frameNum  < 15) || (frameNum  > 29)){frameNum=15;}
         }

        if (moveRight){
             frameNum++;
            if ((frameNum < 30) || (frameNum > 44)){frameNum=30;}

         }
        if (moveLeft){
             frameNum++;
            if ((frameNum < 45) || (frameNum > 59)){frameNum=45;}
         }

        slowClipNew = slowClip;//reset slow clip back to original value
    }

slowClipNew--;

}


//    cout << "moveUP:" << moveUp << endl;
//    cout << "moveDOWN:" << moveDown << endl;
//    cout << "moveRIGHT:" << moveRight << endl;
//    cout << "moveLEFT:" << moveLeft << endl;

    }

void CSprite::setPos(int x, int y){

        mPos.x = x;
        mPos.y = y;

        cBoundary.x = mPos.x;
        cBoundary.y = mPos.y;

}

void CSprite::printPos(){
//cout << "print velocity : VelX = " << velX << ", VelY = " << velY << endl;
//cout << "frame num : " << frameNum << endl;
//cout << "cCollision.w " << cCollision.w << " .h " << cCollision.h << endl;
//cout << "cCollision.x " << cCollision.x << " .y " << cCollision.y << endl;
//
//cout << "wallArray[2].w " << wallArray[2]->w << " .h " << wallArray[2]->h << endl;
//cout << "wallArray[2].x " << wallArray[2]->x << " .y " << wallArray[2]->y << endl;


}

void CSprite::renderCSprite(){


    tSpriteSheet->render( mPos.x, mPos.y, &quadSprite[frameNum]);//render the image
//
//    //not sure if below is really needed
//    currentLocationAndWidthHeight.x = mPos.x;//set current location structure to current location of sprite x
//    currentLocationAndWidthHeight.y = mPos.y;//set current location structure to current location of sprite y
//    currentLocationAndWidthHeight.w = temporary.w;//set current widthHeight structure to current width of clip
//    currentLocationAndWidthHeight.h = temporary.h;//set current widthHeight structure to current height of clip

//    velX = 0;
//    velY = 0;
}


void CSprite::setQuads(int w, int h, int r, int c, int spriteRow, bool horizontal){
//spriteRow, is pos of y iE sprite, if muliple sprites


quadWidth = w;
quadHeight = h;
bool printQuadStats;

if (!horizontal){
    for (int column=0;column<c;column++ ){

        for (int row=spriteRow;row<r+spriteRow;row++ ){
            quadSprite[nextClipNum].x = w*column;
            quadSprite[nextClipNum].y = row*h;
            quadSprite[nextClipNum].w = w;
            quadSprite[nextClipNum].h = h;
            nextClipNum++;

//            cout << ".x = " << w*column << endl;
//            cout << ".y = " << row*h << endl;
//            cout << ".w = " <<  w << endl;
//            cout << ".h = " << h << endl;
//            cout << ".nextClipNum = " << nextClipNum << endl;
        }

     }
}



if (horizontal){
    for (int row=spriteRow;row<r+spriteRow;row++ ){

         for (int column=0;column<c;column++ ){
                quadSprite[nextClipNum].x = w*column;
                quadSprite[nextClipNum].y = row*h;
                quadSprite[nextClipNum].w = w;
                quadSprite[nextClipNum].h = h;
                nextClipNum++;

//                cout << ".x = " << w*column << endl;
//                cout << ".y = " << row*h << endl;
//                cout << ".w = " <<  w << endl;
//                cout << ".h = " << h << endl;
//                cout << ".nextClipNum = " << nextClipNum << endl;
            }

     }
}


}


int CSprite::getPosX(){
    return mPos.x;
    }
int CSprite::getPosY(){
    return mPos.y;
    }


//copyright Robert Misener 2018