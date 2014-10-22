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
int	md_MemberID;
//circadian settings
int md_wakeTime;
int md_sleepTime;
int md_napTime;
int md_peakEnergyTime;
//color settings
int md_wakeLight;
int md_sleepLight;
int md_napLight;
int md_peakEnergyLight;



	public:
           
Member();
Member( string fname, string lname, int MemberID, int wakeTime, int sleepTime, int napTime, int peakEnergyTime, int wakeLight, int sleepLight, int napLight, int peakEnergyLight); // Constructor


bool isId(int MemberID);
string retfname();
string retlname();
int retwakeTime();
int retsleepTime();
int retnapTime();
int retpeakEnergyTime();
int retMemberID();
int retwakeLight();
int retsleepLight();
int retnapLight();
int retpeakEnergyLight();
bool removed; 

};

#endif
