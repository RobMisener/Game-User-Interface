
#ifndef TTIMER_H
#define TTIMER_H


//Using SDL, SDL_image, SDL_ttf, standard IO, strings, and string streams
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <sstream>

//Screen dimension constants
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;



class TTimer
{
public:
	//Initializes variables
	TTimer();

	//The various clock actions
	void start();
	void stop();
	void pause();
	void unpause();

	//Gets the timer's time
	Uint32 getTicks();

	//Checks the status of the timer
	bool isStarted();
	bool isPaused();

	void get_keypresses(SDL_Event *whatEvent); // get key presses from event loop

	void printStatus();

	//increases frame to next frame
	void inceaseFrame();

	Uint32 getAvgFPS();

private:
	//The clock time when the timer started
	Uint32 mStartTicks;

	//The ticks stored when the timer was paused
	Uint32 mPausedTicks;

	int countedFrames;

	float avgFPS;
	//The timer status
	bool mPaused;
	bool mStarted;
};


#endif
//copyright Robert Misener 2018