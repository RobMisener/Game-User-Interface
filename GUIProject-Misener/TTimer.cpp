#include "TTimer.h"

#include <sstream> // for
#include <ostream> // for

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
//
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

TTimer::TTimer()
{
	//Initialize the variables
	mStartTicks = 0;
	mPausedTicks = 0;
	countedFrames = 0;
	countedFrames = 0;

	mPaused = false;
	mStarted = false;
}

void TTimer::start()
{
	//Start the timer
	mStarted = true;
	//Unpause the timer
	mPaused = false;

	//Get the current clock time
	mStartTicks = SDL_GetTicks();
	mPausedTicks = 0;
}

void TTimer::stop()
{
	//Stop the timer
	mStarted = false;

	//Unpause the timer
	mPaused = false;

	//Clear tick variables
	mStartTicks = 0;
	mPausedTicks = 0;
}

void TTimer::pause()
{
	//If the timer is running and isn't already paused
	if (mStarted && !mPaused)
	{
		//Pause the timer
		mPaused = true;

		//Calculate the paused ticks
		mPausedTicks = SDL_GetTicks() - mStartTicks;
		mStartTicks = 0;
	}
}

void TTimer::unpause()
{
	//If the timer is running and paused
	if (mStarted && mPaused)
	{
		//Unpause the timer
		mPaused = false;

		//Reset the starting ticks
		mStartTicks = SDL_GetTicks() - mPausedTicks;

		//Reset the paused ticks
		mPausedTicks = 0;
	}
}

Uint32 TTimer::getTicks()
{
	//The actual timer time
	Uint32 time = 0;

	//If the timer is running
	if (mStarted)
	{
		//If the timer is paused
		if (mPaused)
		{
			//Return the number of ticks when the timer was paused
			time = mPausedTicks;
		}
		else
		{
			//Return the current time minus the start time
			time = SDL_GetTicks() - mStartTicks;
		}
	}

	return time;
}

bool TTimer::isStarted()
{
	//Timer is running and paused or unpaused
	return mStarted;
}

bool TTimer::isPaused()
{
	//Timer is running and paused
	return mPaused && mStarted;
}



void TTimer::get_keypresses(SDL_Event *whatEvent) {
	//Reset start time on return keypress
	if (whatEvent->type == SDL_KEYDOWN)
	{
		//Start/stop
		if (whatEvent->key.keysym.sym == SDLK_s)
		{
			if (isStarted())
			{
				stop();
			}
			else
			{
				start();
			}
		}
		//Pause/unpause
		else if (whatEvent->key.keysym.sym == SDLK_p)
		{
			if (isPaused())
			{
				unpause();
			}
			else
			{
				pause();
			}
		}
	}

}

//increases frame to next frame
void TTimer::inceaseFrame() {
	countedFrames++;

}

Uint32 TTimer::getAvgFPS() {
	if (avgFPS > 2000000)
	{
		avgFPS = 0;
	}

	avgFPS = countedFrames / (getTicks() / 1000.f);

	return avgFPS;
}

//Robert Misener 2018
//www.RobertMisener.com
