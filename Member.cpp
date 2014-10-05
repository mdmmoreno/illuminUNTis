#include <iostream>
#include <cstdlib>
#include "Member.h"



using namespace std; 
//Constructor
Member::Member(): md_MemberID(), md_fN (),md_lN(), md_wakeTime(), md_sleepTime(){}

//Initialiazing data members
Member::Member  (string fname, string lname, int MemberID, int wakeTime, int sleepTime ) 
: md_fN(fname), md_lN(lname), md_MemberID(MemberID), md_wakeTime(wakeTime), md_sleepTime(sleepTime) 
{
                removed = false;
}// Constructor END

// checking for id
 
bool Member::isId(int MemberID){
	if(MemberID == md_MemberID)	return true;
	return false;
}

/*
functions to return the info in order to cout it

*/
string Member::retfname() {
       return md_fN;//return the first Name
       }
string Member::retlname() {
       return md_lN;//return the last name
       }

int Member::retwakeTime() {
       return md_wakeTime;//return the academic wakeTime
       }
int Member::retsleepTime(){
       return md_sleepTime;//return the sleepTime 
       }
int Member::retMemberID() {
       return md_MemberID;//return the id
       }
