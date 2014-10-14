#ifndef STUDENT_H_
#define STUDENT_H_


#include <cstdlib>
using namespace std;



class Member {
//the array needs to access this info
friend class MemberArray;


	private:

string md_fN;
string md_lN;
int md_wakeTime;
int md_sleepTime;
int	md_MemberID;
int md_napTime;
int md_peakEnergyTime;




	public:
           
Member();
Member( string fname, string lname, int MemberID, int wakeTime, int sleepTime, int napTime, int peakEnergyTime); // Constructor


bool isId(int MemberID);
string retfname();
string retlname();
int retwakeTime();
int retsleepTime();
int retnapTime();
int retpeakEnergyTime();
int retMemberID();
bool removed; 

};

#endif
