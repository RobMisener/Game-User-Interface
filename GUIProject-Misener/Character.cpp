
#include "LTexture.h"
#include "LButton.h"
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

//brraks down e level of (1-100) into (0-5) range
int ETrait::emoGuage(int whichEmo) {

	if (whichEmo == 0) {
		if (hE <= 10) {
			return 0;
		}
		else if ((hE > 10) && (hE <= 20)) {
			return 1;
		}
		else if ((hE > 20) && (hE <= 40)) {
			return 2;
		}
		else if ((hE > 40) && (hE <= 60)) {
			return 3;
		}
		else if ((hE > 60) && (hE <= 80)) {
			return 4;
		}
		else if ((hE > 80) && (hE <= 100)) {
			return 5;
		}
		else {
			return 6;
		}
	}

	else if (whichEmo == 1) {

		if (aE <= 10)
			return 0;
		else if ((aE > 10) && (aE <= 20)) {
			return 1;
		}
		else if ((aE > 40) && (aE <= 60)) {
			return 3;
		}
		else if ((aE > 60) && (aE <= 80)) {
			return 4;
		}
		else if ((aE > 80) && (aE <= 100)) {
			return 5;
		}
		else {
			return 6;
		}
	}

	else if (whichEmo == 2) {
		if (sE <= 10) {
			return 0;
		}
		else if ((sE > 10) && (sE <= 20)) {
			return 1;
		}
		else if ((sE > 20) && (sE <= 40)) {
			return 2;
		}
		else if ((sE > 40) && (sE <= 60)) {
			return 3;
		}
		else if ((sE > 60) && (sE <= 80)) {
			return 4;
		}
		else if ((sE > 80) && (sE <= 100)) {
			return 5;
		}
		else {
			return 6;
		}
	}

	else if (whichEmo == 3) {
		if (fE <= 10) {
			return 0;
		}
		else if ((fE > 10) && (fE <= 20)) {
			return 1;
		}
		else if ((fE > 20) && (fE <= 40)) {
			return 2;
		}
		else if ((fE > 40) && (fE <= 60)) {
			return 3;
		}
		else if ((fE > 60) && (fE <= 80)) {
			return 4;
		}
		else if ((fE > 80) && (fE <= 100)) {
			return 5;
		}
		else {
			return 6;
		}
	}

	else if (whichEmo == 4) {
		if (iE <= 10) {
			return 0;
		}
		else if ((iE > 10) && (iE <= 20)) {
			return 1;
		}
		else if ((iE > 20) && (iE <= 40)) {
			return 2;
		}
		else if ((iE > 40) && (iE <= 60)) {
			return 3;
		}
		else if ((iE > 60) && (iE <= 80)) {
			return 4;
		}
		else if ((iE > 80) && (iE <= 100)) {
			return 5;
		}
		else {
			return 6;
		}
	}

	else {
		return 7;
	}

}

void ETrait::setInitialValues(int dT, int aT, int eE, int dTe, int lT) {

	int ModNum1 = -5;
	int ModNum2 = 10;
	int ModNum3 = 15;
	int ModNum4 = 20;

	//set preferences for e 
	if (dT < 30) {
		hE = 40;
		hIncreasePerRep = ModNum1;
		hPref = 1;
	}
	else if ((dT >= 30) && (dT < 34)) {
		hE = 50;
		hIncreasePerRep = ModNum2;
		hPref = 2;
	}
	else if ((dT >= 34) && (dT < 38)) {
		hE = 60;
		hIncreasePerRep = ModNum3;
		hPref = 3;
	}
	else if ((dT >= 38)) {
		hE = 70;
		hIncreasePerRep = ModNum4;
		hPref = 4;

	}

	if (aT < 30) {
		aE = 40;
		aIncreasePerRep = ModNum1;
		aPref = 1;
	}
	if ((aT >= 30) && (aT < 34)) {
		aE = 50;
		aIncreasePerRep = ModNum2;
		aPref = 2;
	}
	else if ((aT >= 34) && (aT < 38)) {
		aE = 60;
		aIncreasePerRep = ModNum3;
		aPref = 3;
	}
	else if ((aT >= 38)) {
		aE = 70;
		aIncreasePerRep = ModNum4;
		aPref = 4;
	}

	if (eE < 30) {
		sE = 40;
		saIncreasePerRep = ModNum1;
		sPref = 1;
	}
	else if ((eE >= 30) && (eE < 34)) {
		sE = 50;
		saIncreasePerRep = ModNum2;
		sPref = 2;
	}
	else if ((eE >= 34) && (eE < 38)) {
		sE = 60;
		saIncreasePerRep = ModNum3;
		sPref = 3;
	}
	else if ((eE >= 38)) {
		sE = 70;
		saIncreasePerRep = ModNum4;
		sPref = 4;
	}

	if (dTe < 30) {
		fE = 40;
		fIncreasePerRep = ModNum1;
		fPref = 1;
	}
	else if ((dTe >= 30) && (dTe < 34)) {
		fE = 50;
		fIncreasePerRep = ModNum2;
		fPref = 2;
	}
	else if ((dTe >= 34) && (dTe < 38)) {
		fE = 60;
		fIncreasePerRep = ModNum3;
		fPref = 3;
	}
	else if ((dTe >= 38)) {
		fE = 70;
		fIncreasePerRep = ModNum4;
		fPref = 4;
	}


	if (lT < 30) {
		iE = 40;
		inIncreasePerRep = ModNum1;
		iPref = 1;
	}
	else if ((lT >= 30) && (lT < 34)) {
		iE = 50;
		inIncreasePerRep = ModNum2;
		iPref = 2;
	}
	else if ((lT >= 34) && (lT < 38)) {
		iE = 60;
		inIncreasePerRep = ModNum3;
		iPref = 3;
	}
	else if ((lT >= 38)) {
		iE = 70;
		inIncreasePerRep = ModNum4;
		iPref = 4;
	}

}

int ETrait::getPref(int whichEmo) {
	if (0) return hPref;
	if (1) return aPref;
	if (2) return sPref;
	if (3) return fPref;
	if (4) return iPref;
}

void ETrait::modEmo(char whichETrait, int modifyBy) {

	if (whichETrait == 'h') hE += modifyBy;
	if (whichETrait == 's')  sE += modifyBy;
	if (whichETrait == 'a')  aE += modifyBy;
	if (whichETrait == 'f')  fE += modifyBy;
	if (whichETrait == 'i')  iE += modifyBy;
	if (whichETrait == 'r') re += modifyBy;

}

void Character::traitPref() {

	pair<int, int> traitRank_pair[5];
	traitRank_pair[0] = make_pair(0, t.di);
	traitRank_pair[1] = make_pair(1, t.ag);
	traitRank_pair[2] = make_pair(2, t.em);
	traitRank_pair[3] = make_pair(3, t.de);
	traitRank_pair[4] = make_pair(4, t.lo);
	//
	vector< pair <int, int> > traitRank_vector;
	//add emoIncentivePairs to emotionPerfered_vector vector
	traitRank_vector.emplace_back(traitRank_pair[0].first, traitRank_pair[0].second);
	traitRank_vector.emplace_back(traitRank_pair[1].first, traitRank_pair[1].second);
	traitRank_vector.emplace_back(traitRank_pair[2].first, traitRank_pair[2].second);
	traitRank_vector.emplace_back(traitRank_pair[3].first, traitRank_pair[3].second);
	traitRank_vector.emplace_back(traitRank_pair[4].first, traitRank_pair[4].second);

	sort(traitRank_vector.begin(), traitRank_vector.end(), sort_high_to_low_pairSecond);

	for (int i = 0; i < 5; i++)
	{
		if (traitRank_vector[0].first == i) {
			prefTraitRank[i] = 5;
		}
		else if (traitRank_vector[1].first == i) {
			prefTraitRank[i] = 4;
		}
		else if (traitRank_vector[2].first == i) {
			prefTraitRank[i] = 3;
		}
		else if (traitRank_vector[3].first == i) {
			prefTraitRank[i] = 2;
		}
		else if (traitRank_vector[4].first == i) {
			prefTraitRank[i] = 1;
		}

	}
}

Character::Character() {
	setRelate();
	setTraits();
	setName();

}

Character::~Character() {

}

int Character::first_trait() {

	int TraitArray[5] = { Character::t.lo,Character::t.am, Character::t.ag,Character::t.em,Character::t.di };

	int largest = 0;

	for (int i = 0; i < 5; i++) {
		if (TraitArray[i] > largest)
			largest = TraitArray[i];
	}

	if (largest == Character::t.lo) {
		return 1;
	}
	else if (largest == Character::t.ag) {
		return 2;
	}
	else if (largest == Character::t.am) {
		return 3;
	}
	else if (largest == Character::t.em) {
		return 4;
	}
	else if (largest == Character::t.di)
	{
		return 5;
	}
	else {
		return 0;
	}
}

int Character::last_trait() {

	int TraitArray[5] = { Character::t.lo,Character::t.am, Character::t.ag,Character::t.em,Character::t.di };
	int smallest = 500;

	for (int i = 0; i < 5; i++) {
		if (TraitArray[i] < smallest)
			smallest = TraitArray[i];
	}

	if (smallest == Character::t.lo) {
		return 1;
	}
	else if (smallest == Character::t.ag) {
		return 2;
	}
	else if (smallest == Character::t.am) {
		return 3;
	}
	else if (smallest == Character::t.em) {
		return 4;
	}
	else if (smallest == Character::t.di) {
		return 5;
	}
	else {
		cout << "error Character::last_trait() " << endl;
		return 0;
	}
}

int Character::love_rel() {

	int bestRelArray[5] = { Character::r.aa,Character::r.bb,Character::r.cc,Character::r.dd,Character::r.ee };
	int relLargest = 0;

	for (int i = 0; i < 5; i++) {
		if (bestRelArray[i] > relLargest)
			relLargest = bestRelArray[i];
	}

	if (relLargest == bestRelArray[0]) {
		return 1;
	}
	else if (relLargest == bestRelArray[1]) {
		return 2;
	}
	else if (relLargest == bestRelArray[2]) {
		return 3;
	}
	else if (relLargest == bestRelArray[3]) {
		return 4;
	}
	else if (relLargest == bestRelArray[4]) {
		return 5;
	}
	else {
		cout << "error Character::love_rel in Character.cpp" << endl;
	}
}


int Character::hate_rel() {
	int relSmallest = 500;

	int worstRelArray[5] = { Character::r.aa,Character::r.bb,Character::r.cc,Character::r.dd,Character::r.ee };

	for (int i = 0; i < 5; i++) {
		if ((worstRelArray[i] < relSmallest) && (worstRelArray[i] > -1)) {
			relSmallest = worstRelArray[i];
		}

		else if (worstRelArray[i] < -1) {
		}
	}

	if (relSmallest == worstRelArray[0]) {
		return 1;
	}
	else if (relSmallest == worstRelArray[1]) {
		return 2;
	}
	else if (relSmallest == worstRelArray[2]) {
		return 3;
	}
	else if (relSmallest == worstRelArray[3]) {
		return 4;
	}
	else if (relSmallest == worstRelArray[4]) {
		return 5;
	}
	else {
		cout << "error Character::hate_rel in Character.cpp" << endl;
	}
}

int Character::birthOrder() {

	//static int iii;
	int bOrderNum;
	static int bOrder1;
	static int bOrder2;
	static int bOrder3;
	static int bOrder4;
	static int bOrder5;

	do {
		bOrderNum = rand() % 5 + 1;
	} while ((bOrderNum == bOrder1) || (bOrderNum == bOrder2) || (bOrderNum == bOrder3) || (bOrderNum == bOrder4) || (bOrderNum == bOrder5));
	switch (bOrderNum) {
	case 1:
		bOrder1 = bOrderNum;
		birthRank = 1;
		return 1;
		break;
	case 2:
		bOrder2 = bOrderNum;
		birthRank = 2;
		return 2;
		break;
	case 3:
		bOrder3 = bOrderNum;
		birthRank = 3;
		return 3;
		break;
	case 4:
		bOrder4 = bOrderNum;
		birthRank = 4;
		return 4;
		break;
	case 5:
		bOrder5 = bOrderNum;
		birthRank = 5;
		return 5;
		break;
	}

}

void Character::sfem(int emo) {

}

int Character::gfem() {
	return 0;
}

//must generate generate_initial_toNum for all participating characters before this
int Character::find_to_num() {
	to = t.ag + (t.am / 2) + (t.di / 4) + (t.re / 3) + (t.lo / 6);
	//to =  myInitial_toNum - find_avg_to();
	return 0;
}



int Character::find_ap_num() {

	int myNumAP;

	myNumAP = (t.re) + (t.lo) + (t.am / 2) + (t.di / 2) + (t.ag / 4);

	ap = myNumAP;

	return 0;
}
//copyright Robert Misener 2018
//www.RobertMisener.com
