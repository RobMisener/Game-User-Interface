#ifndef THERMOMETERS_H
#define THERMOMETERS_H

#include "Character.h"

#include <sstream> // for
#include <ostream> // for

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

extern int find_avg_to();

template<class T, class U>
extern void assign_xyz(int Y_Xplus, T *x, U *y, int X_Yplus);

extern int find_avg_ag();
extern int find_avg_am();
extern int find_avg_di();
extern int find_avg_lo();
extern int find_avg_re();

extern int find_avg_rel();

extern int FIND_rel_value_of_XY(Character *theJudger, Character *charArrayCalcAnimosity);
extern Character a, b, c, d, e;

extern bool sort_high_to_low_pairSecond(pair<int, int>& firstElem, pair<int, int>& secondElem);
//extern bool sort_low_to_high(pair<int, int>& firstElem, pair<int, int>& secondElem);
extern bool sort_low_to_high_pairFirst(pair<int, int>& firstElem, pair<int, int>& secondElem);
extern bool sort_high_to_low_pairFirst(pair<int, int>& firstElem, pair<int, int>& secondElem);


extern int findRelVal(Character *whoX, Character *whoY);
extern int FIND_Bro_num(Character *findBro);
extern Character *find_Bro_address(int enterNum);

class E_Thermometers {

public:
	E_Thermometers();
	~E_Thermometers();

	//sets main character of class
	void set_CharacterPtr_ET(Character *EnterCharacterPtr_ET);
	//breaks down e level of (1-100) into (0-5) range
	int emoGuage(int whichEmo);
	// get character's e preference(based on trait values) and break down into 0-4 ranges
	int getEmoPref(int whichEmoPref);



private:
	Character * CharacterPtr_ET = NULL;

};

class Relationship_Thermometers {
public:
	typedef void _01_void;
	typedef void _02_void;
	typedef int _03_int;
	Relationship_Thermometers();
	~Relationship_Thermometers();


	//set Main Character into *WhichCharacter_Relationships variable; will measure his relationships
	_01_void set_character_RT(Character *setCharacter) {
		WhichCharacter_Relationships = setCharacter;
	}

	//MUST USE BEFORE ANY CALCULATIONS
	//assigns positive or negative values into vectRelations_posORneg based on opinions of *WhichCharacter_Relationships
	_02_void set_vectRelations_posORneg();//sets vector <bool> vectRelations_posORneg // uses bool isPosRel(Character *whoX, Character *whoY)

	//NEEDS _02_void TO WORK
	//return Friend-Foe count (only excluding main character) (a possible total of 4)
	_03_int get_FriendVsFoeCount();

	//return Friend-Foe count (excluding the Main Character and the judger) returns value of 0-3
	int get_FriendVsFoeCount_For_Judger(Character *Judger);

	//retrieve values from private variables int countedFriends and int countedFoes - which counts the number of positive and negative relationships excluding the character himself
	int get_TotalFriends();
	int get_TotalFoes();

	//int ranked_relationships_HighToLow();

private:
	//main character that you will be getting relationship status of
	Character * WhichCharacter_Relationships = NULL;

	//total friends and foes of main character - calculated currently iE Relationship_Thermometer::set_vectRelations_posORneg()
	int countedFriends;//retrieved publicly using int get_TotalFriends()
	int countedFoes;//retrieved publicly using int get_TotalFoes()
					//holds positive or negative of *WhichCharacter_Relationships relationships
	vector <bool> vectRelations_posORneg = { false,false,false,false,false }; // assigned iE set_vectRelations_posORneg()


									  //isPosRel (does x have a positive opinion, of y) 
	bool isPosRel(Character *whoX, Character *whoY);//used by void set_vectRelations_posORneg()
};

class Topic_Thermometers {
public:

	//set the character who we will monitor
	void set_characterPtr(Character *setCharacterPtr);

	//fill values of categoryCompatibility array with the imporatance of trait iE the Topic's category
	void set_CategoryCompatibility();

	void set_OpinionCompatibility();

private:
	Character * CharTopicOpinionPtr;
	int categoryCompatibility[5]; //holds value of 

	struct opinionCompatability {
		//di,ag,em,de,lo
		int traitArray_diAgEmDeLo[5]{ 0,0,0,0,0 };

	}opinionCompatability[5];

	//flag array to indicate topic availability
	bool TopicAvailable_FlagArray[5] = { false,false,false,false,false };
};

class Motivation_Thermometers {
public:

	Motivation_Thermometers();
	~Motivation_Thermometers();

	//set who is the character whos motivation is measured, assign his emoTherm and relTherm pointers
	void setCharacterPtr_MT(Character *whoIsCharacter);

	void calculate_Motivation_EmotionChoice();

private:
	int motivation_EmotionChoice[5];
	int motivation_Category[5];
	int motivation_Opinion[5];

	struct choiceTarget {
		int motivation_HurtFoeChar[5];//motivation to attack foe
		int motivation_HelpFriendChar[5];//motivation to help ally
		int arrayHelpOrHurt[10]; //array of above two arrays, sorted from highest to lowest
	} choiceTarget;

	struct choiceOpin {

	} choiceOpin;

	struct choiceTopic {
		int motivation_Military_Diplomacy_Justice_Intellegence_Economy[5];

	} choiceTopic;

	//are these used???? no refrences or definitions
	int getAPpref;//get 1-3 value of ap
	bool firstTurn_flag;

	//thermometers of the main character
	struct MainCharacterMT {
		Character *CharacterPtrMT; //character who you are determining motivation for
		E_Thermometers *MainCharacter_EmoT_ptr;
		Relationship_Thermometers *MainCharacter_RelT_ptr;
		pair <int, int> ePrefRank[5];
	} MainCharacterMT;

	//ptr arrays for above variables
	E_Thermometers *EmoThermoPtrArray[5];
	Relationship_Thermometers *RelThermoPtrArray[5];
};

class DECISION_Thermometer {
public:
	typedef void _01_void;
	typedef void _02_void;

	_01_void set_Character_Thermometers(Character *CharacterDeciderPtr, Relationship_Thermometers *RelThermo_Ptr_Array[]) {
		int broNum = 99; //initialize, not 0 because 0 is a valid number
		CharacterDeciderPtr = CharacterDecider;
		broNum = FIND_Bro_num(CharacterDeciderPtr); //get bro number so we can use the switch statement to eliminate the Bro from the RelThermoVectorForTargets Vector


		for (int i = 0; i < 5; i++)
		{
			RelThermoVectorForTargets.push_back(RelThermo_Ptr_Array[i]);
		}

		switch (broNum) {
		case 0:
			RelThermoVectorForTargets.erase(RelThermoVectorForTargets.begin());
			break;
		case 1:
			RelThermoVectorForTargets.erase(RelThermoVectorForTargets.begin() + 1);
			break;
		case 2:
			RelThermoVectorForTargets.erase(RelThermoVectorForTargets.begin() + 2);
			break;
		case 3:
			RelThermoVectorForTargets.erase(RelThermoVectorForTargets.begin() + 3);
			break;
		case 4:
			RelThermoVectorForTargets.erase(RelThermoVectorForTargets.begin() + 4);
			break;
		default:
			break;
		}


	}

private:

	vector  <Relationship_Thermometers*> RelThermoVectorForTargets;
	E_Thermometers *EThermo_ForMainCharacter;

	Character *CharacterDecider;//main character who is making the decision
	Character *ThisIsWhoIAttack;

};


#endif


//copyright Robert Misener 2018
//www.RobertMisener.com