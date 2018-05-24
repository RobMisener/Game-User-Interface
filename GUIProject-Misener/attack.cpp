


#include "Character.h"
#include "attack.h"

#include <sstream> 
#include <ostream> 

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

extern Character a;
extern Character b;
extern Character c;
extern Character d;
extern Character e;

class Character;
class ETrait;

extern Character *find_Bro_address(int enterNum);

//caclulate characters's e preference and measure their current e levels
void DetermineMotivation::dm01a_calc_MyEmoPreferenceValues_and_GuageLevels() {
	int getPref[5];// temporary value that stores rank 1-5 of characters e perference 
	int emoGuage[5];//  temporary value that stares current e stats of character 
	int traitPref[5];
	theJudger->traitPref(); //assigns and arranges traits iE order to prefTraitRank

	//these scores are used later when player needs to know which e they want to choose
	for (int i = 0; i < 5; i++) {
		if (getPref[i] == 5)
			mo_MyEmoPreference[i] += 30;
		else if (getPref[i] == 4)
			mo_MyEmoPreference[i] += 20;
		else if (getPref[i] == 3)
			mo_MyEmoPreference[i] += 10;
		else if (getPref[i] == 2)
			mo_MyEmoPreference[i] -= 10;
		else if (getPref[i] == 1) //-020
			mo_MyEmoPreference[i] -= 20;
	}

	//assign new score to the mo_MyGuagedEmoValues array based on current e values of character (hap,sad,ang)
	//these scores are used later when player needs to know which e they want to choose
	for (int i = 0; i < 5; i++) {

		if (emoGuage[i] == 5)//80 - 100
			mo_MyGuagedEmoValues[i] += 30;
		else if (emoGuage[i] == 4)//60 - 80
			mo_MyGuagedEmoValues[i] += 20;
		else if (emoGuage[i] == 3)// 40- 60
			mo_MyGuagedEmoValues[i] += 10;
		else if (emoGuage[i] == 2) //20-40
			mo_MyGuagedEmoValues[i] -= 10;
		else if (emoGuage[i] == 1)//0-20
			mo_MyGuagedEmoValues[i] -= 20;
		//else if (emoGuage[i] == 0)//0-10
		//    mo_MyGuagedEmoValues[i] -= 40;
	}

	for (int i = 0; i < 5; i++) {
		if (traitPref[i] == 5)//80 - 100
			mo_MyEmoPreference[i] += 5;
		else if (traitPref[i] == 4)//60 - 80
			mo_MyEmoPreference[i] += 4;
		else if (traitPref[i] == 3)// 40- 60
			mo_MyEmoPreference[i] += 3;
		else if (traitPref[i] == 2) //20-40
			mo_MyEmoPreference[i] += 2;
		else if (traitPref[i] == 1)//0-20
			mo_MyEmoPreference[i] += 1;
	}

	dm01b_TOTAL_ADD_FINAL_EmotionChoice_motivation();
	dm01c_FINAL_MO_EmotionChoice_Output();

}

void DetermineMotivation::dm01b_TOTAL_ADD_FINAL_EmotionChoice_motivation() {

	for (int i = 0; i < 5; i++) {

		TOTAL_MO_MyEmo_Preferences[i] = mo_MyEmoPreference[i] + mo_MyGuagedEmoValues[i];
		cout << endl << "TOTAL_MO_MyEmo_Preferences[i] = " << TOTAL_MO_MyEmo_Preferences[i];
		cout << endl << "mo_MyEmoPreference[i] = " << mo_MyEmoPreference[i];
		cout << endl << "mo_MyGuagedEmoValues[i] = " << mo_MyGuagedEmoValues[i];

	}

	cout << endl << "dm01b_TOTAL_ADD_FINAL_EmotionChoice_motivation completed" << endl;

}

//this returns the e number (from 0-4 range) of the the attackers perfered e (TOTAL_MO_MyEmo_Preferences sorted)
int DetermineMotivation::dm01c_FINAL_MO_EmotionChoice_Output() {

	cout << endl << "dm01c_FINAL_MO_EmotionChoice_Output started" << endl;
	//create pairs to store the (e number , and their TOTAL_MO_MyEmo_Preferences caclulated... 
	//...from void DetermineMotivation::dm01b_TOTAL_ADD_FINAL_EmotionChoice_motivation)
	pair<int, int> emoIncentivePair[5];
	emoIncentivePair[0] = make_pair(0, TOTAL_MO_MyEmo_Preferences[0]);
	emoIncentivePair[1] = make_pair(1, TOTAL_MO_MyEmo_Preferences[1]);
	emoIncentivePair[2] = make_pair(2, TOTAL_MO_MyEmo_Preferences[2]);
	emoIncentivePair[3] = make_pair(3, TOTAL_MO_MyEmo_Preferences[3]);
	emoIncentivePair[4] = make_pair(4, TOTAL_MO_MyEmo_Preferences[4]);

	//
	vector< pair <int, int> > emotionPerfered_vector;
	//add emoIncentivePairs to emotionPerfered_vector vector
	emotionPerfered_vector.emplace_back(emoIncentivePair[0].first, emoIncentivePair[0].second);
	emotionPerfered_vector.emplace_back(emoIncentivePair[1].first, emoIncentivePair[1].second);
	emotionPerfered_vector.emplace_back(emoIncentivePair[2].first, emoIncentivePair[2].second);
	emotionPerfered_vector.emplace_back(emoIncentivePair[3].first, emoIncentivePair[3].second);
	emotionPerfered_vector.emplace_back(emoIncentivePair[4].first, emoIncentivePair[4].second);



	// !!!!!!!!!!WHY DO WE NEED TO STORE THE VALUES OF emotionPerfered_vector INTO emotionPerfered_vector_beforeSorting. IT DOESN'T SEEMED TO BE USED IN ANYTHING...
	// !!!!!!!!! ... WHY NOT JUST USE THE INTIAL emotionPerfered_vector AND SORT IT?
	//store the inital values above from emotionPerfered_vector into holder array - which stores the values of emotionPerfered_vector before it is sorted below
	vector< pair <int, int> > emotionPerfered_vector_beforeSorting = emotionPerfered_vector;

	//aa12// sort from high to low the values iE the second part of the pair (TOTAL_MO_MyEmo_Preferences), iE array from aa11
	sort(emotionPerfered_vector.begin(), emotionPerfered_vector.end(), sort_high_to_low_pairSecond);

	emotionChoice[0] = emotionPerfered_vector_beforeSorting[0].first;
	emotionChoice[1] = emotionPerfered_vector_beforeSorting[1].first;
	emotionChoice[2] = emotionPerfered_vector_beforeSorting[2].first;
	emotionChoice[3] = emotionPerfered_vector_beforeSorting[3].first;
	emotionChoice[4] = emotionPerfered_vector_beforeSorting[4].first;

	//return the value of the 4th spot iE vector (unsure why it is forth, is this backwards?)
	return emotionPerfered_vector_beforeSorting[0].first;



	//cout << endl << "dm01c_FINAL_MO_EmotionChoice_Output completed" << endl;
}

//counts the number of postive relationships of target into countFriendsOfTarget[i] and assigns aE incentive score to mo_social_value_t1[i] based on that
void DetermineMotivation::dm02a_calc_CountFriendsOfTarget() {



	cout << endl << "dm02a_calc_CountFriendsOfTarget() started" << endl;

	//number of freinds potential targets have
	int total_incentive_weakness_relationship_target[4];

	//if judger = &a, count the relationships of the targets
	if (theJudger == &a) {
		total_tar[0] = RelThermo_B.get_FriendVsFoeCount_For_Judger(theJudger);
		total_tar[1] = RelThermo_C.get_FriendVsFoeCount_For_Judger(theJudger);
		total_tar[2] = RelThermo_D.get_FriendVsFoeCount_For_Judger(theJudger);
		total_tar[3] = RelThermo_E.get_FriendVsFoeCount_For_Judger(theJudger);
	}

	else if (theJudger == &b) {
		total_tar[0] = RelThermo_A.get_FriendVsFoeCount_For_Judger(theJudger);
		total_tar[1] = RelThermo_C.get_FriendVsFoeCount_For_Judger(theJudger);
		total_tar[2] = RelThermo_D.get_FriendVsFoeCount_For_Judger(theJudger);
		total_tar[3] = RelThermo_E.get_FriendVsFoeCount_For_Judger(theJudger);
	}

	else if (theJudger == &c) {
		total_tar[0] = RelThermo_A.get_FriendVsFoeCount_For_Judger(theJudger);
		total_tar[1] = RelThermo_B.get_FriendVsFoeCount_For_Judger(theJudger);
		total_tar[2] = RelThermo_D.get_FriendVsFoeCount_For_Judger(theJudger);
		total_tar[3] = RelThermo_E.get_FriendVsFoeCount_For_Judger(theJudger);
	}

	else if (theJudger == &d) {
		total_tar[0] = RelThermo_A.get_FriendVsFoeCount_For_Judger(theJudger);
		total_tar[1] = RelThermo_B.get_FriendVsFoeCount_For_Judger(theJudger);
		total_tar[2] = RelThermo_C.get_FriendVsFoeCount_For_Judger(theJudger);
		total_tar[3] = RelThermo_E.get_FriendVsFoeCount_For_Judger(theJudger);
	}

	else if (theJudger == &e) {
		total_tar[0] = RelThermo_A.get_FriendVsFoeCount_For_Judger(theJudger);
		total_tar[1] = RelThermo_B.get_FriendVsFoeCount_For_Judger(theJudger);
		total_tar[2] = RelThermo_C.get_FriendVsFoeCount_For_Judger(theJudger);
		total_tar[3] = RelThermo_D.get_FriendVsFoeCount_For_Judger(theJudger);
	}


	int incentive_target_socialWeakness[4];

	for (int i = 0; i < 4; i++) {
		if (total_tar[i] == 3)
			total_incentive_weakness_relationship_target[i] = 60;
		if (total_tar[i] == 2)
			total_incentive_weakness_relationship_target[i] = 40;
		if (total_tar[i] == 1)
			total_incentive_weakness_relationship_target[i] = 20;
		if (total_tar[i] == 0)
			total_incentive_weakness_relationship_target[i] = 0;
		if (total_tar[i] == -1)
			total_incentive_weakness_relationship_target[i] = 20;
		if (total_tar[i] == -2)
			total_incentive_weakness_relationship_target[i] = 40;
		if (total_tar[i] == -3)
			total_incentive_weakness_relationship_target[i] = 60;
	}
	cout << endl << "dm02a_calc_CountFriendsOfTarget() started" << endl;
}

void DetermineMotivation::dm02b_calc_AnimosityTowardsTargets() {


	cout << "dm02b_calc_AnimosityTowardsTargets()" << endl;

	int relValuesArray[5];

	Character *charArrayCalcAnimosity[5] = { &a,&b,&c,&d,&e };

	pair<int, int> characterAndMyDislike[5];


	//assign 
	for (int i = 0; i < 5; i++) {
		relValuesArray[i] = FIND_rel_value_of_XY(theJudger, charArrayCalcAnimosity[i]);
	}

	characterAndMyDislike[0] = make_pair(0, relValuesArray[0]);
	characterAndMyDislike[1] = make_pair(1, relValuesArray[1]);
	characterAndMyDislike[2] = make_pair(2, relValuesArray[2]);
	characterAndMyDislike[3] = make_pair(3, relValuesArray[3]);
	characterAndMyDislike[4] = make_pair(4, relValuesArray[4]);



	//aa11// assign values from pair array iE aa10 into new VECTOR pair array
	vector< pair <int, int> > characterAndMyDislike_after;
	characterAndMyDislike_after.emplace_back(characterAndMyDislike[0].first, characterAndMyDislike[0].second);
	characterAndMyDislike_after.emplace_back(characterAndMyDislike[1].first, characterAndMyDislike[1].second);
	characterAndMyDislike_after.emplace_back(characterAndMyDislike[2].first, characterAndMyDislike[2].second);
	characterAndMyDislike_after.emplace_back(characterAndMyDislike[3].first, characterAndMyDislike[3].second);
	characterAndMyDislike_after.emplace_back(characterAndMyDislike[4].first, characterAndMyDislike[4].second);


	// if judging character is X, remove him from the animosity vector
	if (theJudger == &a) // if judging character is &a
		characterAndMyDislike_after.erase(characterAndMyDislike_after.begin()); //erase the firsy bool iE vector
	else if (theJudger == &b)
		characterAndMyDislike_after.erase(characterAndMyDislike_after.begin() + 1);
	else if (theJudger == &c)
		characterAndMyDislike_after.erase(characterAndMyDislike_after.begin() + 2);
	else if (theJudger == &d)
		characterAndMyDislike_after.erase(characterAndMyDislike_after.begin() + 3);
	else if (theJudger == &e)
		characterAndMyDislike_after.erase(characterAndMyDislike_after.begin() + 4);

	//records order before sorting 
	vector< pair <int, int> > characterAndMyDislike_after_before = characterAndMyDislike_after;
	//aa12// sort from high to low, values iE array from aa11
	sort(characterAndMyDislike_after.begin(), characterAndMyDislike_after.end(), sort_high_to_low_pairSecond);

	//if (characterAndMyDislike_after)

	//point range to assign to 
	int motivationArray[4]{ 40,20,10,-10 };



	for (int i = 0; i < 4; i++) {

		if (characterAndMyDislike_after_before[0].first == characterAndMyDislike_after_before[i].first) {
			characterAndMyDislike_after_before[i].second = motivationArray[0];
		}
		else if (characterAndMyDislike_after_before[1].first == characterAndMyDislike_after_before[i].first) {
			characterAndMyDislike_after_before[i].second = motivationArray[1];
		}
		else if (characterAndMyDislike_after_before[2].first == characterAndMyDislike_after_before[i].first) {
			characterAndMyDislike_after_before[i].second = motivationArray[2];
		}
		else if (characterAndMyDislike_after_before[3].first == characterAndMyDislike_after_before[i].first) {
			characterAndMyDislike_after_before[i].second = motivationArray[3];
		}
	}

}

void DetermineMotivation::dm02c_TOTAL_ADD_IncentiveToAttackTargets() {
	for (int i = 0; i < 5; i++) {
		TOTAL_MO_IncentiveToAttackTargets[i] = mo_social_value_t1[i] += mo_MyAnimosityTowardTargets[i];
	}
}

void DetermineMotivation::dm02d_FINAL_MO_perferedTarget_Output() {
	//
	pair<int, int> incentiveToAttackChar[4];
	incentiveToAttackChar[0] = make_pair(0, TOTAL_MO_IncentiveToAttackTargets[0]);
	incentiveToAttackChar[1] = make_pair(1, TOTAL_MO_IncentiveToAttackTargets[1]);
	incentiveToAttackChar[2] = make_pair(2, TOTAL_MO_IncentiveToAttackTargets[2]);
	incentiveToAttackChar[3] = make_pair(3, TOTAL_MO_IncentiveToAttackTargets[3]);

	//assign values from incentiveToAttackChar[i] into incentiveToAttackChar_vector[i]
	vector< pair <int, int> > incentiveToAttackChar_vector;
	incentiveToAttackChar_vector.emplace_back(incentiveToAttackChar[0].first, incentiveToAttackChar[0].second);
	incentiveToAttackChar_vector.emplace_back(incentiveToAttackChar[1].first, incentiveToAttackChar[1].second);
	incentiveToAttackChar_vector.emplace_back(incentiveToAttackChar[2].first, incentiveToAttackChar[2].second);
	incentiveToAttackChar_vector.emplace_back(incentiveToAttackChar[3].first, incentiveToAttackChar[3].second);

	vector< pair <int, int> > characterAndMyDislike_vector_beforeSorting = incentiveToAttackChar_vector;

	//aa12// sort from high to low, values iE array from aa11
	sort(incentiveToAttackChar_vector.begin(), incentiveToAttackChar_vector.end(), sort_high_to_low_pairSecond);

	targetChoice[0] = incentiveToAttackChar_vector[0].first;

}

void DetermineMotivation::dm001b_setCharacter(Character *whichChar) {

	theJudger = whichChar;
}

void battleRound::step00_setDetermineMotivationPointers(DetermineMotivation *d1, DetermineMotivation *d2, DetermineMotivation *d3, DetermineMotivation *d4, DetermineMotivation *d5) {
	dm1 = d1;
	dm2 = d2;
	dm3 = d3;
	dm4 = d4;
	dm5 = d5;

	dmPtrArray[0] = dm1;
	dmPtrArray[1] = dm2;
	dmPtrArray[2] = dm3;
	dmPtrArray[3] = dm4;
	dmPtrArray[4] = dm5;
}

void battleRound::step0_calc_ap_and_assign_new_values() {

	SDL_Event _step0_calc_ap_and_assign_new_values;
	SDL_PollEvent(&_step0_calc_ap_and_assign_new_values);

	Character *chArray[5] = { &a,&b,&c,&d,&e };

	//aa01// assign initial ap bRound1.step0_calc_ap_and_assign_new_values().number values
	for (int i = 0; i < 5; i++) {
		chArray[i]->find_ap_num();
	}

	//aa10//create array to store initial ap values as they are assigned to character
	pair<int, int> pairAP_orderArray[5];
	pairAP_orderArray[0] = make_pair(0, chArray[0]->ap);
	pairAP_orderArray[1] = make_pair(1, chArray[1]->ap);
	pairAP_orderArray[2] = make_pair(2, chArray[2]->ap);
	pairAP_orderArray[3] = make_pair(3, chArray[3]->ap);
	pairAP_orderArray[4] = make_pair(4, chArray[4]->ap);

	//aa11// assign values from pair array iE aa10 into new VECTOR pair array
	vector< pair <int, int> > pairAP_orderArray_Vector;
	pairAP_orderArray_Vector.emplace_back(pairAP_orderArray[0].first, pairAP_orderArray[0].second);
	pairAP_orderArray_Vector.emplace_back(pairAP_orderArray[1].first, pairAP_orderArray[1].second);
	pairAP_orderArray_Vector.emplace_back(pairAP_orderArray[2].first, pairAP_orderArray[2].second);
	pairAP_orderArray_Vector.emplace_back(pairAP_orderArray[3].first, pairAP_orderArray[3].second);
	pairAP_orderArray_Vector.emplace_back(pairAP_orderArray[4].first, pairAP_orderArray[4].second);

	//aa12// sort from high to low, values iE array from aa11
	sort(pairAP_orderArray_Vector.begin(), pairAP_orderArray_Vector.end(), sort_high_to_low_pairSecond);

	//aa13// assign character pointers iE order of highest and lowest values
	Character *ap1, *ap2, *ap3, *ap4, *ap5;

	ap1 = find_Bro_address(pairAP_orderArray_Vector[0].first + 1);
	ap2 = find_Bro_address(pairAP_orderArray_Vector[1].first + 1);
	ap3 = find_Bro_address(pairAP_orderArray_Vector[2].first + 1);
	ap4 = find_Bro_address(pairAP_orderArray_Vector[3].first + 1);
	ap5 = find_Bro_address(pairAP_orderArray_Vector[4].first + 1);

	//aa14// assign highest and lowest ap numbers into temporary integers
	int highestAp = ap1->ap;
	int lowestAp = ap5->ap;

	//aa15//get total range from highest to lowest initial ap, and divide into five ranges
	//cout << endl;
	int rangeOfAp = highestAp - lowestAp;
	int rangeOfAp_level_mark_range = rangeOfAp / 5;

	//a33// assign values into temporary integers based on the five range levels (from aa15) to values to store iE pair values iE a44
	int rangeOfAp_level_mark_1 = rangeOfAp_level_mark_range + lowestAp;
	int rangeOfAp_level_mark_2 = (rangeOfAp_level_mark_range * 2) + lowestAp;
	int rangeOfAp_level_mark_3 = (rangeOfAp_level_mark_range * 3) + lowestAp;
	int rangeOfAp_level_mark_4 = (rangeOfAp_level_mark_range * 4) + lowestAp;

	//a44//assign 5 ranges to pair values for use iE a55
	pair<int, int> rangeOfAp_level_mark_ranges_pair[5];
	rangeOfAp_level_mark_ranges_pair[0] = make_pair(lowestAp, rangeOfAp_level_mark_1);
	rangeOfAp_level_mark_ranges_pair[1] = make_pair(rangeOfAp_level_mark_1, rangeOfAp_level_mark_2);
	rangeOfAp_level_mark_ranges_pair[2] = make_pair(rangeOfAp_level_mark_2, rangeOfAp_level_mark_3);
	rangeOfAp_level_mark_ranges_pair[3] = make_pair(rangeOfAp_level_mark_3, rangeOfAp_level_mark_4);
	rangeOfAp_level_mark_ranges_pair[4] = make_pair(rangeOfAp_level_mark_4, highestAp);

	int increaseAPby1;
	int increaseAPby2;
	int increaseAPby3;
	int increaseAPby4;

	if (rangeOfAp < 5) {
		increaseAPby1 = 0;
		increaseAPby2 = 0;
		increaseAPby3 = 0;
		increaseAPby4 = 0;
	}

	else if (rangeOfAp < 15 && rangeOfAp > 4) {
		increaseAPby1 = 0;
		increaseAPby2 = 1;
		increaseAPby3 = 1;
		increaseAPby4 = 2;
	}

	else if (rangeOfAp > 14 && rangeOfAp < 20) {
		increaseAPby1 = 0;
		increaseAPby2 = 2;
		increaseAPby3 = 2;
		increaseAPby4 = 3;
	}

	else {
		increaseAPby1 = 0;
		increaseAPby2 = 0;
		increaseAPby3 = 0;
		increaseAPby4 = 0;
	}

	//a55//assign new values to new Character AP stat based on ranges from a44
	for (int i = 0; i < 5; i++) {
		if ((chArray[i]->ap >= rangeOfAp_level_mark_ranges_pair[0].first) && (chArray[i]->ap < rangeOfAp_level_mark_ranges_pair[0].second)) {
			chArray[i]->newAp = 5;
		}
		else if ((chArray[i]->ap >= rangeOfAp_level_mark_ranges_pair[1].first) && (chArray[i]->ap < rangeOfAp_level_mark_ranges_pair[1].second)) {
			chArray[i]->newAp = 5 + increaseAPby1;
		}
		else if ((chArray[i]->ap >= rangeOfAp_level_mark_ranges_pair[2].first) && (chArray[i]->ap < rangeOfAp_level_mark_ranges_pair[2].second)) {
			chArray[i]->newAp = 5 + increaseAPby2;
		}
		else if ((chArray[i]->ap >= rangeOfAp_level_mark_ranges_pair[3].first) && (chArray[i]->ap < rangeOfAp_level_mark_ranges_pair[3].second)) {
			chArray[i]->newAp = 5 + increaseAPby3;
		}
		else if ((chArray[i]->ap >= rangeOfAp_level_mark_ranges_pair[4].first) && (chArray[i]->ap <= rangeOfAp_level_mark_ranges_pair[4].second)) {
			chArray[i]->newAp = 5 + increaseAPby4;
		}
	}

}

void battleRound::step1_assignTurnOrder() {

	SDL_Event _function_assignTurnOrder;
	SDL_PollEvent(&_function_assignTurnOrder);

	for (int i = 0; i < 5; i++) {
		chArray[i]->find_to_num();
	}

	pair<int, int> pairTurnOrder[5];

	pairTurnOrder[0] = make_pair(0, chArray[0]->to);
	pairTurnOrder[1] = make_pair(1, chArray[1]->to);
	pairTurnOrder[2] = make_pair(2, chArray[2]->to);
	pairTurnOrder[3] = make_pair(3, chArray[3]->to);
	pairTurnOrder[4] = make_pair(4, chArray[4]->to);

	//first integer is
	vector< pair <int, int> > vecExample;

	vecExample.emplace_back(pairTurnOrder[0].first, pairTurnOrder[0].second);
	vecExample.emplace_back(pairTurnOrder[1].first, pairTurnOrder[1].second);
	vecExample.emplace_back(pairTurnOrder[2].first, pairTurnOrder[2].second);
	vecExample.emplace_back(pairTurnOrder[3].first, pairTurnOrder[3].second);
	vecExample.emplace_back(pairTurnOrder[4].first, pairTurnOrder[4].second);

	sort(vecExample.begin(), vecExample.end(), sort_high_to_low_pairSecond);

	t1 = (find_Bro_address(vecExample[0].first + 1));
	t2 = (find_Bro_address(vecExample[1].first + 1));
	t3 = (find_Bro_address(vecExample[2].first + 1));
	t4 = (find_Bro_address(vecExample[3].first + 1));
	t5 = (find_Bro_address(vecExample[4].first + 1));

}

void battleRound::step1b_assign_TO_into_DM() {

	Character *tPtrArray[5] = { t1,t2,t3,t4,t5 };

	for (int i = 0; i < 5; i++) dmPtrArray[i]->dm001b_setCharacter(tPtrArray[i]);
}

void battleRound::step2_decideAction() {
	srand(time(NULL));

	//if first round assign topic randomly to brother - will not count as turn
	if (firstTurn == true) {
		int whoStartsTopic;

		whoStartsTopic = rand() % 5 + 1;
		//cout << whoStartsTopic;

		if (whoStartsTopic == 1) t0 = &a;
		else if (whoStartsTopic == 2) t0 = &b;
		else if (whoStartsTopic == 3) t0 = &c;
		else if (whoStartsTopic == 4) t0 = &d;
		else if (whoStartsTopic == 5) t0 = &e;

		/// BarbarianInvasion.topicOwner = t0;

		firstTurn = false;

	}

	//else if not first turn decide action
	else if (!firstTurn) {
		//dm1->dm001a_setRelBools();
		dm1->dm01a_calc_MyEmoPreferenceValues_and_GuageLevels();
		cout << "uuuuuuuuuuuuuuuuuuuuuuuuuuuuuu" << "uuuuuuuuuuuuuuuuuuuuuuuuuuuuu" << endl << "uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu";
		dm1->dm01b_TOTAL_ADD_FINAL_EmotionChoice_motivation();

		//calculate judgers favorite e
		dm1->dm01c_FINAL_MO_EmotionChoice_Output();
		cout << "after emotionChoice1";

		dm1->dm02a_calc_CountFriendsOfTarget();
		cout << "after dm02a_calc_CountFriendsOfTarget";
		dm1->dm02b_calc_AnimosityTowardsTargets();
		dm1->dm02c_TOTAL_ADD_IncentiveToAttackTargets();

		//calculate judgers favorite target
		dm1->dm02d_FINAL_MO_perferedTarget_Output();
	}
	else { cout << "error in battle round step2_decideAction" << endl; }

}

void battleRound::test_previous() {
	cout << endl << t1->name << ": I am the first turn. My new ap is " << t1->newAp << ". I am going to attack " << find_Bro_address(dm1->targetChoice[0] + 1)->name << "with the " << dm1->emotionChoice[0] << " attack" << endl;
}
//copyright Robert Misener 2018
//www.RobertMisener.com
