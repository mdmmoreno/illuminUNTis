#include <iostream>
#include <cstdlib>
#include "MemberArray.h"



using namespace std;
int MAXVALUE = 255;
void MemberArray::modify(){

     int Id;
     string am;

     cout << "Member ID: ";
     cin >> Id;

     int index = find(Id);

     //verify find != -1

     cout<<"-WAKE UP TIME:";
     cin>>members[index].md_wakeTime>>am;

     cout<<"-SLEEP TIME: ";
     cin>>members[index].md_sleepTime>>am;

     cout<<"-NAP TIME: ";
     cin>>members[index].md_napTime>>am;

     cout<<"-PEAK ENERGY TIME: ";
     cin>>members[index].md_peakEnergyTime>>am;

     cout<<"Thank you "<<members[index].md_fN<<". "<<endl;
     cout<<"\nPlease enter your desired Lighting Settings: (R) (G) (B)"<<endl; 
     cout<<"-WAKE UP LIGHT:";

     cin>>members[index].md_wakeLightR>>members[index].md_wakeLightG>>members[index].md_wakeLightB;

     cout<<"-SLEEP LIGHT: ";
     cin>>members[index].md_sleepLightR>>members[index].md_sleepLightG>>members[index].md_sleepLightB;

     cout<<"-NAP LIGHT: ";
     cin>>members[index].md_napLightR>>members[index].md_napLightG>>members[index].md_napLightB;

     cout<<"-PEAK ENERGY LIGHT: ";
     cin>>members[index].md_peakEnergyLightR>>members[index].md_peakEnergyLightG>>members[index].md_peakEnergyLightB;

     cout << "Modified: " << members[index].md_fN << endl;
}
void MemberArray::create(){
    
	Member temp;
	cout<<"\nPlease enter your first name, last name and ID number. "<<endl;
//We need to create boxes to retain this information
     string am; // What's this for?  Answer: to specify the meridian period (am, pm)

     cin >>temp.md_fN>>temp.md_lN>>temp.md_MemberID;
     cout<<"Thank you "<<temp.md_fN<<". "<<endl<<"\nPlease enter your desired Circadian Settings: (TIME) (MERDIAN PERIOD)"<<endl;

     cout<<"-WAKE UP TIME:";
     cin>>temp.md_wakeTime>>am;

     cout<<"-SLEEP TIME: ";
     cin>>temp.md_sleepTime>>am;

     cout<<"-NAP TIME: ";
     cin>>temp.md_napTime>>am;

     cout<<"-PEAK ENERGY TIME: ";
     cin>>temp.md_peakEnergyTime>>am;

     cout<<"Thank you "<<temp.md_fN<<". "<<endl<<"\nPlease enter your desired Lighting Settings: (R) (G) (B)"<<endl;
     cout<<"-WAKE UP LIGHT:";
    //in case RGB  values are out of range
    do{
         cin>>temp.md_wakeLightR>>temp.md_wakeLightG>>temp.md_wakeLightB;

         if(temp.md_wakeLightR > MAXVALUE || temp.md_wakeLightG > MAXVALUE || temp.md_wakeLightB > MAXVALUE)
            cout<<"ERROR: RGB value(s) invalid. Enter values again (0-255): "<<endl;
         else{
              break;
         }
     }while(temp.md_wakeLightR > MAXVALUE || temp.md_wakeLightG > MAXVALUE || temp.md_wakeLightB > MAXVALUE);

     cout<<"-SLEEP LIGHT: ";
    //in case RGB  values are out of range
    do{
         cin>>temp.md_sleepLightR>>temp.md_sleepLightG>>temp.md_sleepLightB;

         if(temp.md_sleepLightR > MAXVALUE || temp.md_sleepLightG > MAXVALUE || temp.md_sleepLightB > MAXVALUE)
            cout<<"ERROR: RGB value(s) invalid. Enter values again (0-255): "<<endl;
         else{
              break;
         }
     }while(temp.md_sleepLightR > MAXVALUE || temp.md_sleepLightG > MAXVALUE || temp.md_sleepLightB > MAXVALUE);

     cout<<"-NAP LIGHT: ";
    //in case RGB  values are out of range
    do{
         cin>>temp.md_napLightR>>temp.md_napLightG>>temp.md_napLightB;

         if(temp.md_napLightR > MAXVALUE || temp.md_napLightG > MAXVALUE || temp.md_napLightB > MAXVALUE)
            cout<<"ERROR: RGB value(s) invalid. Enter values again (0-255): "<<endl;
         else{
              break;
         }
     }while(temp.md_napLightR > MAXVALUE || temp.md_napLightG > MAXVALUE || temp.md_napLightB > MAXVALUE);


     cout<<"-PEAK ENERGY LIGHT: ";
    //in case RGB  values are out of range
    do{
         cin>>temp.md_peakEnergyLightR>>temp.md_peakEnergyLightG>>temp.md_peakEnergyLightB;

         if(temp.md_peakEnergyLightR > MAXVALUE || temp.md_peakEnergyLightG > MAXVALUE || temp.md_peakEnergyLightB > MAXVALUE)
            cout<<"ERROR: RGB value(s) invalid. Enter values again (0-255): "<<endl;
         else{
              break;
         }
     }while(temp.md_peakEnergyLightR > MAXVALUE || temp.md_peakEnergyLightG > MAXVALUE || temp.md_peakEnergyLightB > MAXVALUE);

 if (find(temp.md_MemberID) == -1) {
	members.push_back(temp);
 } else {
 	cout<<  "Error! The ID number already exists "<< endl;
   } 
    cout<<endl;

}

void MemberArray::displayAll(){
	for(int i = 0; i < members.size(); i++) {
		cout<< "Profile " << i+1 << ":" << members[i].md_fN << endl;
	}

	if(members.size() == 0){
		cout << "Nothing to print\n";
	}
}

void MemberArray::del(){
	int ID, index;
	cout << "Member ID to remove: ";
	cin >> ID;
	index = find(ID);
	members.erase(members.begin() + index);
}

int MemberArray::find(int findID){
	for(int i=0; i<members.size(); i++) {
		if(members[i].md_MemberID == findID){
			return i;
		}
	}
	return -1;
}
// End of my stuff

//Constructor
MemberArray::MemberArray() 
{
	vector<Member> members;
} 
