
//turn order, attack

#ifndef ATTACK_H
#define ATTACK_H

#include "Character.h"
#include "Thermometers.h"

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
//battle1_interface.step00_setDetermineMotivationPointers(DmPtrArray[0],DmPtrArray[1],DmPtrArray[2],DmPtrArray[3],DmPtrArray[4]);

////

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


extern bool sort_high_to_low_pairSecond(pair<int, int>& firstElem, pair<int, int>& secondElem);
//extern bool sort_low_to_high(pair<int, int>& firstElem, pair<int, int>& secondElem);
extern bool sort_low_to_high_pairFirst(pair<int, int>& firstElem, pair<int, int>& secondElem);
extern bool sort_high_to_low_pairFirst(pair<int, int>& firstElem, pair<int, int>& secondElem);

extern int findRelVal(Character *whoX, Character *whoY);
extern int FIND_Bro_num(Character *findBro);
extern Character *find_Bro_address(int enterNum);


//extern Category Military, Politics, Resources;

extern Relationship_Thermometers RelThermo_A, RelThermo_B, RelThermo_C, RelThermo_D, RelThermo_E;
extern E_Thermometers EThermo_A, EThermo_B, EThermo_C, EThermo_D, EThermo_E;


//not used yet
class attackValue {

private:

	int social_total_tar1;
	int social_total_tar2;
	int social_total_tar3;
	int social_total_tar4;

	bool choose_assist;
	bool choose_defend;
	bool choose_buffSelf;
	bool choose_attack;
	bool choose_skip;

	int assistValue;
	int defendValue;
	int buffSelfValue;
	int attackValues;
	int skipValue;

public:
	Character * theJudger;
	Character *finalAttackTarget;


	 //AI is simply measuring inputs and assigning decision based on highest value

	int perceptionFogOfWar;

	bool targetEmoDanger;

};



//not used yet
class attack {
public:
	void setGraphicMenu(LTexture *ptrEmoMenu);

	void clickDisplayAttackMenu(SDL_Event *ev);

	void assign_Att_Tar(Character *att, Character *tar);

	//anger
	void topic();
	void topicOpinion();
	void repairRelationship();

	void insult();
	void threaten();

	void compliment();

private:
	Character * attacker;
	Character *target;
	ETrait *targetEmo;
	ETrait *attackEmo;
	int timesAttacked;
	LTexture *emoMenu;
	SDL_Rect emoMenuBoundary;


};

//RelateBool classes are declared iE DetermineMotivation
class RelateBool {
public:
	//count number of positive relationships of character from boolVect[i], the reason i is only 3 is the judger and judged are eliminated from the score
	//also adds positive-neg relationships to int totalPvN
	int boolCount();//used iE DetermineMotivation::dm02a_calc_CountFriendsOfTarget()
};


//after deciding target, decide attack? or should this be a combo
class attackType {
private:
	Character * attacker;

	//points
	int attackerAngValue();
	int attackerSadValue();
	int attackerIntValue();
	int attackerHapValue();
	int attackerFeaValue();
public:
	//choose e attack based on highest value e (value determined by many factors)
	void *chooseEmoAttack();



};

class DetermineMotivation {

public:




	void dm001b_setCharacter(Character *whichChar);

	// ((e PREFERENCE)) calculation functions
	void dm01a_calc_MyEmoPreferenceValues_and_GuageLevels();////caclulate characters's e preference and measure their current e levels
	void dm01b_TOTAL_ADD_FINAL_EmotionChoice_motivation();//calculates TOTAL_MO_MyEmo_Preferences[i]
	int dm01c_FINAL_MO_EmotionChoice_Output();

	//  ((TARGET)) calculation functions
	void dm02a_calc_CountFriendsOfTarget();//counts the number of postive relationships of target into countFriendsOfTarget[i] and assigns aE incentive score to mo_social_value_t1[i] based on that
	void dm02b_calc_AnimosityTowardsTargets();


	void dm02c_TOTAL_ADD_IncentiveToAttackTargets();

	void dm02d_FINAL_MO_perferedTarget_Output();

	int emotionChoice[5];
	int targetChoice[5];


private:

	int total_tar[4];

	//stores ture/false values of judgment of &a by b,c,d,e
	RelateBool relbool_a_bJudges;
	RelateBool relbool_a_cJudges;
	RelateBool relbool_a_dJudges;
	RelateBool relbool_a_eJudges;
	//stores ture/false values of judgment of &b by a,c,d,e
	RelateBool relbool_b_aJudges;
	RelateBool relbool_b_cJudges;
	RelateBool relbool_b_dJudges;
	RelateBool relbool_b_eJudges;
	//stores ture/false values of judgment of &c by a,b,d,e
	RelateBool relbool_c_aJudges;
	RelateBool relbool_c_bJudges;
	RelateBool relbool_c_dJudges;
	RelateBool relbool_c_eJudges;
	//stores ture/false values of judgment of &d by a,b,c,e
	RelateBool relbool_d_aJudges;
	RelateBool relbool_d_bJudges;
	RelateBool relbool_d_cJudges;
	RelateBool relbool_d_eJudges;
	//stores ture/false values of judgment of &e by a,b,c,d
	RelateBool relbool_e_aJudges;
	RelateBool relbool_e_bJudges;
	RelateBool relbool_e_cJudges;
	RelateBool relbool_e_dJudges;

	// Character *whichT;
	Character *theJudger; //alias of whichT;

	// all e value and guage arrays
	int mo_MyEmoPreference[5]; //value that stores the modified score (the value assigned to each e based on Character's preference). 
	int mo_MyGuagedEmoValues[5];// value that stores the current e levels of the character (hap,sad,ang, etc)

	int TOTAL_MO_MyEmo_Preferences[5]; //mo_MyEmoPreference[i] += mo_MyGuagedEmoValues[i];

	int getValue();


	int countFriendsOfTarget[4]; //count the positive bools of people who like the target - calculated iE dm02a_calc_CountFriendsOfTarget !!!!! Not USED Globally, why not put iE function instead?
	int mo_MyAnimosityTowardTargets[4];//assign value according to judgers personal opinion of targets
	int TOTAL_MO_IncentiveToAttackTargets[4];


	int mo_social_value_t1[5];
	//character array vector
	//vector <Character*> CharVect = {&a,&b,&c,&d,&e};

};

class battleRound {
public:
	Character * t0; //topic starter - does not take any AP or cost anything
	Character *t1;
	Character *t2;
	Character *t3;
	Character *t4;
	Character *t5;
	//fist stepstep2_decideAction
	void step00_setDetermineMotivationPointers(DetermineMotivation *d1, DetermineMotivation *d2, DetermineMotivation *d3, DetermineMotivation *d4, DetermineMotivation *d5);

	//do this only once - calculates AP
	void step0_calc_ap_and_assign_new_values();

	void step1_assignTurnOrder();
	void step1b_assign_TO_into_DM();
	void step2_decideAction();
	void test_previous();

private:

	DetermineMotivation * dm1;
	DetermineMotivation *dm2;
	DetermineMotivation *dm3;
	DetermineMotivation *dm4;
	DetermineMotivation *dm5;


	DetermineMotivation *dmPtrArray[5]; //the main 

	bool firstTurn = false; // is it the first turn - used to create a topic for first turn.


	Character *chArray[5] = { &a,&b,&c,&d,&e };

};


#endif

//copyright Robert Misener 2018
//www.RobertMisener.com