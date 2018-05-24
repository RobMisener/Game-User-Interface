#ifndef CHARACTER_H
#define CHARACTER_H


#include "LTexture.h"
#include "LButton.h"
;
#include <sstream> // for
#include <ostream> // for

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h> //for sound

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

extern bool sort_high_to_low_pairSecond(pair<int, int>& firstElem, pair<int, int>& secondElem);

extern int find_avg_ag();
extern int find_avg_am();
extern int find_avg_di();
extern int find_avg_lo();
extern int find_avg_re();


//Memory Class? is this used?
/*
class Memories {

public:
	void setCharacters();
	void mod_traits() {
		//mod traits
		//mod 
	}
	string setMemDescription(string enterDescription){ 
		memDescription = enterDescription;
	}

private:
	Character *MemCharPtr1;
	Character *MemCharPtr2;
	string memDescription;


};

Memories Mdog, Mfire, Mtorture;
*/

class ETrait{
private:
//public:
    int hE;
    int sE;
    int aE;
    int fE;
    int re;
    int iE;

    int hPref;
    int aPref;
    int sPref;
    int fPref;
    int iPref;



    int hIncreasePerRep;
    int saIncreasePerRep;
    int aIncreasePerRep;
    int fIncreasePerRep;
    int inIncreasePerRep;


    int reIncreasePerRep;

    bool haMAX;
    bool saMAX;
    bool anMAX;
    bool reMAX;
    bool inMAX;

    bool haEMP;
    bool saEMP;
    bool anEMP;
    bool reEMP;
    bool inEMP;

public:
    ETrait(){
		hE=0;
		sE=0;
		aE=0;
		fE=0;
		re=0;
		iE=0;

		haMAX=false;
		saMAX=false;
		anMAX=false;
		reMAX=false;
		inMAX=false;

		haEMP=false;
		saEMP=false;
		anEMP=false;
		reEMP=false;
		inEMP=false;

    }


    void setInitialValues(int dip, int agg, int emp, int dec, int log);


    void modEmo(char whichEmo, int modifyBy);

    //get guage of which e he perfers
    int getPref(int whichEmo);

    ////breaks down e level of (1-100) into (0-5) range
    int emoGuage(int whichEmo);

	//current e bar value
    int getHa(){return hE;}
	int getAn() {return aE;}
    int getSa(){return sE;}
    int getFe(){return fE;}
    int getIn(){return iE;};

	//based on trait scores, 0-5 range of preference for particular e
	int getHaPref() {return hPref;}
	int getAnPref() {return aPref;}
	int getSaPref() {return sPref;}
	int getFePref() {return fPref;}
	int getInPref() {return iPref;};

//
//    void setHa(int ha1){
//        hE = ha1;
//    };
//    void setSa(int sa1){
//        sE = sa1;
//    };
//    void setAn(int an1){
//    aE = an1;
//    };
//    void setFe(int fe1){
//    fE = fe1;
//    };
//    void setRe(int re1){
//    re = re1;
//    };
//    void setIn(int in1){
//    iE = in1;
//    };


};


//TUMBLR IS MY SEXUAL SHRINK

class Character : public ETrait{
    public:

        Character(); //constructor
        ~Character();

		void traitPref();
		int prefTraitRank[5];


        int ap;
        int newAp; //new AP generated from balues

        //int myInitial_toNum;

        int to; //turn order

        int find_to_num();//mhust generate generate_initial_toNum for all participating characters before this

        int find_ap_num();//find ap  number

        int birthOrder();
        int birthRank;

        //set face e;
        void sfem(int emo);
        int gfem();



        int energy; //mental energy, health
        int speed;

        int stamina;//amount of
        int attack;
        int defense;
        int armor;
        int health;

        void setCombatStats(){
            health = hea;
            stamina = sta;
            attack = att;
            defense = def;
            armor = arm;
        }

        struct opinionsOfMe {
            int hisOP_aa; //Robert
            int hisOP_bb; //Ranulf
            int hisOP_cc; //John
            int hisOP_dd; //Geoffrey
            int hisOP_ee; //Stephen
            int hisOP_ff; //father
            int hisOP_uu1; //uncle a
            int hisOP_uu2; //uncle b
        } opinionsOfMe;

        struct r { //these need to be balanced a's relationship with b's need to compliment one another.
            int aa; //Robert
            int bb; //Ranulf
            int cc; //John
            int dd; //Geoffrey
            int ee; //Stephen
            int ff; //father
            int uu1; //uncle a
            int uu2; //uncle b
            } r;


        //structure et for individual relationships
        struct er{
            //et toward
            struct an{
                int a;
                int b;
                int c;
                int e;
                int d;
            } an;
            struct fe{
                int a;
                int b;
                int c;
                int e;
                int d;
            } fe;
            struct re{
                int a;
                int b;
                int c;
                int e;
                int d;
            } re;
        } er;
        void setRelate(){
        r.aa = main_relate.a;
        r.bb = main_relate.b;
        r.cc = main_relate.c;
        r.dd = main_relate.d;
        r.ee = main_relate.e;
        r.ff = main_relate.f;
        r.uu1 = main_relate.u1;
        r.uu2 = main_relate.u2;
        }

        struct t{
        int lo;
        int am;
        int ag;
        int de;
        int em;
        int di;
        int re;
        int null;
        int null2;
        int null3;
        int null4;
        } t;

        void setTraits(){
            t.lo = p_traits.lo;
            t.ag = p_traits.ag;
            t.am = p_traits.am;
            t.de = p_traits.de;
            t.em = p_traits.em;
            t.di = p_traits.di;
            t.re = p_traits.re;
            t.null = p_traits.nu1;
            t.null2 = p_traits.nu2;
            t.null3 = p_traits.nu3;
            t.null4 = p_traits.nu4;
        }

        int first_trait();
        int last_trait();
        int love_rel();
        int hate_rel();

        string name; //you don't need to initialize strings
        void setName(){
            name = nm;
        }

        struct e {
            int ha;
            int sa;
            int an;
            int fe;
            int fr;
            int re;
            int in;
            } e;
        void setEmotion(){
            e.ha = emo.hap;
            e.sa = emo.sad;
            e.an = emo.ang;
            e.fe = emo.fea;
            e.fr = emo.fre;
        }


//physical features -- public variables/functions
        struct featuresNum{
        int h1;
        int h2;
        int e1;
        int e2;
        int n1;
        int n2;
        int n3;
        int ht1;
        int ht2;
        int ht3;
        int c1;
        int c2;
        int b1;
        int b2;
        int ea1;
        int j1;
        int v1;
        int ck1;
       } featuresNum;
        void setFeaturesNums(){
                featuresNum.h1 = pfeatNum.h_1;
                featuresNum.h2 = pfeatNum.h_2;
                featuresNum.e1 = pfeatNum.e_1;
                featuresNum.e2 = pfeatNum.e_2 ;
                featuresNum.n1 = pfeatNum.n_1;
                featuresNum.n2 = pfeatNum.n_2;
                featuresNum.n3 = pfeatNum.n_3;
                featuresNum.ht1 = pfeatNum.ht_1;
                featuresNum.ht2 = pfeatNum.ht_2;
                featuresNum.ht3 = pfeatNum.ht_3;
                featuresNum.c1 = pfeatNum.c_1;
                featuresNum.c2 = pfeatNum.c_2;
                featuresNum.b1 = pfeatNum.b_1;
                featuresNum.b2 = pfeatNum.b_2;
                featuresNum.ea1 = pfeatNum.ea_1;
                featuresNum.j1 = pfeatNum.j_1;
                featuresNum.v1 = pfeatNum.v_1;
                featuresNum.ck1 = pfeatNum.ck_1;
            }
        struct features{
            //struct hair
                string ha;
                string hb;
            //struct eyes{
                string eca;
                string ecb;
            //struct nose{
                string na;
                string nb;
                string nc;
            //struct height{
                string hta;
                string htb;
                string htc;
            //struct chin{
                string ca;
                string cb;
            //struct brow{
                string ba;
                string bb;

            //struct ears{
                string ea;
            //struct cheeks{
                string cka;
            //struct jaw{
                string ja;
            //struct voice{
                string va;
            } features;
        void setFeatures(){
                features.ha = pfeat.h_a;
                features.ha = pfeat.h_b;
                features.eca = pfeat.e_ca;
                features.ecb = pfeat.e_cb;
                features.na = pfeat.n_a;
                features.nb = pfeat.n_b;
                features.nc = pfeat.n_c;
                features.hta = pfeat.ht_a;
                features.htb = pfeat.ht_b;
                features.htc = pfeat.ht_c;
                features.ca = pfeat.h_a;
                features.cb = pfeat.h_a;
                features.ba = pfeat.b_a;
                features.bb = pfeat.b_b;
                features.ea = pfeat.e_a;
                features.cka = pfeat.ck_a;
                features.ja = pfeat.j_a;
                features.va = pfeat.v_a;
            }

        string description;
        void set_description(){
            description = description_priv;}
        void print_description(){
            cout << description << endl;}


//        void generate_initial_toNum();////this needs to generate before find_to_num can be generated.
private:
        //private name
        string nm;

        //private relationships
        struct main_relate {
            int a; //Robert
            int b; //Ranulf
            int c; //John
            int d; //Geoffrey
            int e; //Stephen
            int f; //father
            int u1; //uncle a
            int u2; //uncle b
            } main_relate;

        //private stats
        struct p_traits{
        int lo;
        int am;
        int ag;
        int de;
        int em;
        int di;
        int re;
        int nu1;
        int nu2;
        int nu3;
        int nu4;
        } p_traits;

               //private et
        struct emo {
            int hap;
            int sad;
            int ang;
            int fea;
            int fre;
        } emo;

        //private variables for physical features
        string description_priv;
        struct pfeat {
                string h_a;
                string h_b;
                string e_ca;
                string e_cb;
                string n_a;
                string n_b;
                string n_c;
                string ht_a;
                string ht_b;
                string ht_c;
                string c_a;
                string c_b;
                string b_a;
                string b_b;
                string e_a;
                string ck_a;
                string j_a;
                string v_a;
           } pfeat;
        struct pfeatNum{
                int h_1;
                int h_2;
                int e_1;
                int e_2;
                int n_1;
                int n_2;
                int n_3;
                int ht_1;
                int ht_2;
                int ht_3;
                int c_1;
                int c_2;
                int b_1;
                int b_2;
                int ea_1;
                int j_1;
                int v_1;
                int ck_1;
        } pfeatNum;

        //private variables for health/defense stats
        int hea;//health
        int sta;//stamina
        int att;
        int def;
        int arm;
        //int gl[int xx,int yy]; //grid location

	};



#endif

	//copyright Robert Misener 2018
	//www.RobertMisener.com