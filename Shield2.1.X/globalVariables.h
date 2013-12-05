//Michael Lenth
/*Global Variables*/
#ifndef globalV
#define globalV
char irOccured = 0; //Flag: Will set upon attack reception in IR
//*********************************************************
char numAttacks = 0; //Counter for the number of attacks received once the countdown timer has begun.
//*********************************************************
char absorbAtt = 1; //Global Var for absorbing attacks.
char countdown = 2; //Global Var for countdown.
char attReflect = 3; //Global Var for attack reflection.
char heal = 4; //Global Var for healing.
char takeDmg = 5; //Global Var for taking damage.
char shldBroke = 6; //Global Var for a breaking shield.
char cheater = 7; //Global Var for cheating.
char mime = 8; //Global Var for doing nothing.
//*********************************************************
int timerX = 0; //Iteration that the timer is on.
//*********************************************************
char pushedBttn = 0;//Set to 0,1,2. 0 = No button has been pressed. 1 - Reflect, 2-Heal
//*********************************************************
char dmgCounter = 0;//Damage Tracker; counter.
//*********************************************************
unsigned int Cap1, Cap2, Cap3, Cap4, Cap5, Cap6, Cap7, Cap8, x;
//*********************************************************
unsigned int HP = 6000;
unsigned int percentHP = 100;
unsigned int DAMAGE = 1000;
//*********************************************************
char countVar = 0;
unsigned int idleCnt = 0;
char noSoundFlag = 0;
unsigned int Fall_Time = 0;
unsigned int Rise_Time = 0;
unsigned int Width = 0;
unsigned int level = 0;
unsigned int MAGE = NOT_CONNECTED;
unsigned int delayvar = 40;
#endif