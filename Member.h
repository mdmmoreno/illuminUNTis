#ifndef STUDENT_H_
#define STUDENT_H_


#include <cstdlib>
using namespace std;



class Member {
	public:

		string md_fN;
		string md_lN;
		int md_MemberID;

		//circadian settings
		int md_wakeTime;
		int md_sleepTime;
		int md_napTime;
		int md_peakEnergyTime;

		//color settings
		int md_wakeLightR;
		int md_wakeLightG;
		int md_wakeLightB;
		int md_sleepLightR;
		int md_sleepLightG;
		int md_sleepLightB;
		int md_napLightR;
		int md_napLightG;
		int md_napLightB;
		int md_peakEnergyLightR;
		int md_peakEnergyLightG;
		int md_peakEnergyLightB;

		Member();
};

#endif
