#include "Thermometers.h"

extern Relationship_Thermometers RelThermo_A, RelThermo_B, RelThermo_C, RelThermo_D, RelThermo_E;
extern E_Thermometers EThermo_A, EThermo_B, EThermo_C, EThermo_D, EThermo_E;

E_Thermometers::E_Thermometers()
{

}

E_Thermometers::~E_Thermometers()
{
}

void E_Thermometers::set_CharacterPtr_ET(Character *EnterCharacterPtr_ET) {
	CharacterPtr_ET = EnterCharacterPtr_ET;
}

//breaks down e level of (1-100) into (0-5) range
int E_Thermometers::emoGuage(int whichEmo) {

	//stores value of Main Character's current e bar score
	int getEmotionValueArray[5] = { CharacterPtr_ET->getHa(), CharacterPtr_ET->getAn(), CharacterPtr_ET->getSa(), CharacterPtr_ET->getFe(),CharacterPtr_ET->getIn() };

	if (getEmotionValueArray[whichEmo] <= 10) {
		return 0;
	}
	else if ((getEmotionValueArray[whichEmo] > 10) && (getEmotionValueArray[whichEmo] <= 20)) {
		return 1;
	}
	else if ((getEmotionValueArray[whichEmo] > 20) && (getEmotionValueArray[whichEmo] <= 40)) {
		return 2;
	}
	else if ((getEmotionValueArray[whichEmo] > 40) && (getEmotionValueArray[whichEmo] <= 60)) {
		return 3;
	}
	else if ((getEmotionValueArray[whichEmo] > 60) && (getEmotionValueArray[whichEmo] <= 80)) {
		return 4;
	}
	else if ((getEmotionValueArray[whichEmo] > 80) && (getEmotionValueArray[whichEmo] <= 100)) {
		return 5;
	}
	else {
		cout << endl << "error int Emotion::emoGuage(int whichEmo) if statment0" << endl;
		return 6;
	}
}

// get character's e preference(based on trait values) and break down into 0-4 ranges
int E_Thermometers::getEmoPref(int whichEmoPref) {
	if (whichEmoPref == 0) return CharacterPtr_ET->getHaPref();
	else if (whichEmoPref == 1) return CharacterPtr_ET->getAnPref();
	else if (whichEmoPref == 2) return CharacterPtr_ET->getSaPref();
	else if (whichEmoPref == 3) return CharacterPtr_ET->getFePref();
	else if (whichEmoPref == 4) return CharacterPtr_ET->getInPref();
	else { cout << "error Emotional_Thermometer::getEmoPref(int whichEmoPref), argument passed into int whichEmoPref parameter not in range " << endl; return 999; }
}

Relationship_Thermometers::Relationship_Thermometers()
{
}

Relationship_Thermometers::~Relationship_Thermometers()
{
}

//internal function used to determine who if whoX has a positive opinion of whoY
bool Relationship_Thermometers::isPosRel(Character *whoX, Character *whoY) {
	//cout << "whoX=" << whoX->name << endl << "whoY=" << whoY->name << endl;
	//y opinion of x
	//int whoXnum = FIND_Bro_num(whoX);
	int whoXYrel;
	int avgRelValue = find_avg_rel();

	//if whoX is x then whoXYrel = y->r.x
	if (whoX == &a) { whoXYrel = whoY->r.aa; }
	else if (whoX == &b) { whoXYrel = whoY->r.bb; }
	else if (whoX == &c) { whoXYrel = whoY->r.cc; }
	else if (whoX == &d) { whoXYrel = whoY->r.dd; }
	else if (whoX == &e) { whoXYrel = whoY->r.ee; }

	cout << "whoXYrel = " << whoXYrel << endl;
	//cout << "find_avg_re() =" << find_avg_re() << endl;

	// if the X's opinion of Y is greater than the aveverage realtional valyue set isPosRel to true
	if (whoXYrel > avgRelValue) { return true; }

	else { return false; }

}

//assigns positive or negative values into vectRelations_posORneg based on opinions of *WhichCharacter_Relationships
void Relationship_Thermometers::set_vectRelations_posORneg() {

	int friends = 0; //total friends counted before 
	int foes = 0; //total foes counted before
	int broNumMainChar = FIND_Bro_num(WhichCharacter_Relationships); //gets bro num of main character - used to eliminate Main C's opionion of himself iE friend/foe count 

	Character *CharacterPtrArray_RelPref[5] = { &a, &b, &c, &d, &e }; //used iE 

	for (int i = 0; i < 5; i++) {
		//isPosRel (does x have a positive opinion, of y) //
		vectRelations_posORneg[i] = isPosRel(CharacterPtrArray_RelPref[i], WhichCharacter_Relationships); //assign true/false to Bool Vect based on whether other brothers have positive view of &a
	}

	////below
	//sets friend count for private variables countedFriends & countedFoes - main C's opinion excluded


	for (int i = 0; i < 5; i++) { (vectRelations_posORneg[i] == true) ? (friends += 1) : (foes += 1); }

	// subtracts Main C's opionion of himself from friend/foe count 
	(vectRelations_posORneg[broNumMainChar] == true) ? (friends -= 1) : (foes -= 1);

	//assign local variables into the private class variables
	countedFriends = friends;
	countedFoes = foes;

}



//public function that returns the number of Pos-Neg relationships of vectRelations_posORneg (excluding the Character and Judger)
int Relationship_Thermometers::get_FriendVsFoeCount() {

	int sumOfPos = 0; //total pos relationships from vectRelations_posORneg
	int sumOfNeg = 0; //total neg relationships from vectRelations_posORneg
	int totalPvN = 0; //total pos - neg relationships from vectRelations_posORneg
	cout << "\"int Relationship_Thermometers::get_FriendVsFoeCount_For_Judger(Character *Judger)\" started" << endl;

	//eliminate the main character from friend count
	if (WhichCharacter_Relationships == &a) {
		vectRelations_posORneg.erase(vectRelations_posORneg.begin());
	}
	else if (WhichCharacter_Relationships == &b) {
		vectRelations_posORneg.erase(vectRelations_posORneg.begin() + 1);
	}
	else if (WhichCharacter_Relationships == &c) {
		vectRelations_posORneg.erase(vectRelations_posORneg.begin() + 2);
	}
	else if (WhichCharacter_Relationships == &d) {
		vectRelations_posORneg.erase(vectRelations_posORneg.begin() + 3);
	}
	else if (WhichCharacter_Relationships == &e) {
		vectRelations_posORneg.erase(vectRelations_posORneg.begin() + 4);
	}
	else {
		cout << "error, parameter does not match anything in if chain :: \" int Relationship_Thermometers::get_FriendVsFoeCount_For_Judger(Character *Judger) : if (WhichCharacter_Relationships == &a) \" " << endl;
	}

	//count pos & neg relationships from vectRelations_posORneg
	for (int i = 0; i < 4; i++) { (vectRelations_posORneg[i] == true) ? (sumOfPos += 1) : (sumOfPos += 0); }
	for (int i = 0; i < 4; i++) { (vectRelations_posORneg[i] == false) ? (sumOfNeg += 1) : (sumOfNeg += 0); }
	totalPvN = sumOfPos - sumOfNeg;

	return totalPvN; //return the total pos - neg
}


//public function that returns the number of Pos-Neg relationships of vectRelations_posORneg (excluding the Character and Judger)
int Relationship_Thermometers::get_FriendVsFoeCount_For_Judger(Character *Judger) {
	int sumOfPos = 0; //total pos relationships from vectRelations_posORneg
	int sumOfNeg = 0; //total neg relationships from vectRelations_posORneg
	int totalPvN = 0; //total pos - neg relationships from vectRelations_posORneg
	cout << "\"int Relationship_Thermometers::get_FriendVsFoeCount_For_Judger(Character *Judger)\" started" << endl;


	//eliminate judger and judged from friend count
	if (Judger == &a) {
		vectRelations_posORneg.erase(vectRelations_posORneg.begin());
	}
	else if (Judger == &b) {
		vectRelations_posORneg.erase(vectRelations_posORneg.begin() + 1);
	}
	else if (Judger == &c) {
		vectRelations_posORneg.erase(vectRelations_posORneg.begin() + 2);
	}
	else if (Judger == &d) {
		vectRelations_posORneg.erase(vectRelations_posORneg.begin() + 3);
	}
	else if (Judger == &e) {
		vectRelations_posORneg.erase(vectRelations_posORneg.begin() + 4);
	}
	else {
		cout << "error, parameter does not match anything in if chain :: \" int Relationship_Thermometers::get_FriendVsFoeCount_For_Judger(Character *Judger) : if (Judger = &a) \" " << endl;
	}

	//eliminate the main character from friend count
	if (WhichCharacter_Relationships == &a) {
		vectRelations_posORneg.erase(vectRelations_posORneg.begin());
	}
	else if (WhichCharacter_Relationships == &b) {
		vectRelations_posORneg.erase(vectRelations_posORneg.begin() + 1);
	}
	else if (WhichCharacter_Relationships == &c) {
		vectRelations_posORneg.erase(vectRelations_posORneg.begin() + 2);
	}
	else if (WhichCharacter_Relationships == &d) {
		vectRelations_posORneg.erase(vectRelations_posORneg.begin() + 3);
	}
	else if (WhichCharacter_Relationships == &e) {
		vectRelations_posORneg.erase(vectRelations_posORneg.begin() + 4);
	}
	else {
		cout << "error, parameter does not match anything in if chain :: \" int Relationship_Thermometers::get_FriendVsFoeCount_For_Judger(Character *Judger) : if (WhichCharacter_Relationships == &a) \" " << endl;
	}

	//count pos & neg relationships from vectRelations_posORneg
	for (int i = 0; i < 3; i++) { (vectRelations_posORneg[i] == true) ? (sumOfPos += 1) : (sumOfPos += 0); }
	for (int i = 0; i < 3; i++) { (vectRelations_posORneg[i] == false) ? (sumOfNeg += 1) : (sumOfNeg += 0); }
	totalPvN = sumOfPos - sumOfNeg;

	return totalPvN; //return the total pos - neg
}

int Relationship_Thermometers::get_TotalFriends()
{
	return countedFriends;
}

int Relationship_Thermometers::get_TotalFoes()
{
	return countedFoes;
}

//set the character who we will monitor
void Topic_Thermometers::set_characterPtr(Character *setCharacterPtr) {
	CharTopicOpinionPtr = setCharacterPtr;
}
//set the topic we will monitor




void Topic_Thermometers::set_OpinionCompatibility() {


}

Motivation_Thermometers::Motivation_Thermometers() {


	//temporary arrays used to store values iE the for loop below - stores emoTherm and relTherm objects declared iE main into them
	Relationship_Thermometers *tempRelThermArray[5] = { &RelThermo_A, &RelThermo_B, &RelThermo_C, &RelThermo_D, &RelThermo_E };
	E_Thermometers *tempEmoThermArray[5] = { &EThermo_A, &EThermo_B, &EThermo_C, &EThermo_D, &EThermo_E };

	Character *CharPtrArray_MT[5] = { &a,&b,&c,&d,&e };

	//assign the objects assigned iE the temporary pointer arrays into the private variable arrays
	for (int i = 0; i < 5; i++) {
		EmoThermoPtrArray[i] = tempEmoThermArray[i];
		RelThermoPtrArray[i] = tempRelThermArray[i];
	}

	for (int i = 0; i < 5; i++) {
		EmoThermoPtrArray[i]->set_CharacterPtr_ET(CharPtrArray_MT[i]);
	}

	//RelThermo_A.set_character(&a);
	//RelThermo_B.set_character(&b);
	//RelThermo_C.set_character(&c);
	//RelThermo_D.set_character(&d);
	//RelThermo_E.set_character(&e);

	//EThermo_A.set_CharacterPtr_ET(&a);
	//EThermo_B.set_CharacterPtr_ET(&b);
	//EThermo_C.set_CharacterPtr_ET(&c);
	//EThermo_D.set_CharacterPtr_ET(&d);
	//EThermo_E.set_CharacterPtr_ET(&e);

}

Motivation_Thermometers::~Motivation_Thermometers()
{
}

//set who is the character whos motivation is measured, assign his emoTherm and relTherm pointers
void Motivation_Thermometers::setCharacterPtr_MT(Character *whoIsCharacter) {
	//Character *CharPtrArray_MT[5] = { &a,&b,&c,&d,&e };

	MainCharacterMT.CharacterPtrMT = whoIsCharacter; //assign argument to main character pointer
	int tempBroNum = FIND_Bro_num(MainCharacterMT.CharacterPtrMT); // assign bro number to temp int, used to assign emoPtr below

																   //assign the main characters e and rel thermometers to the private variables holding the main character emoTherm and relTherm pointers
	MainCharacterMT.MainCharacter_EmoT_ptr = EmoThermoPtrArray[tempBroNum];
	MainCharacterMT.MainCharacter_RelT_ptr = RelThermoPtrArray[tempBroNum];
	//FIND_Bro_num
}

void Motivation_Thermometers::calculate_Motivation_EmotionChoice() {
	//motivation_EmotionChoice
	//breaks down e level of (1-100) into (0-5) range
	MainCharacterMT.MainCharacter_EmoT_ptr->emoGuage(1);
	// get character's e preference(based on trait values) and break down into 0-4 ranges
	int getEmoPref(int whichEmoPref);
}
//copyright Robert Misener 2018
//www.RobertMisener.com
