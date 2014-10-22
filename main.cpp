#include <iostream>
#include <cstdlib>
#include "MemberArray.h"
#include "MemberArray.cpp"




using namespace std;
//=====constants
int MAX = 10;
int num = 0;


Member **Members = new Member* [MAX];

MemberArray MemberA;


//=====will check for the id
bool exists_already (int MemberID) 
{
 for (int i=0; i< num; i++) 
     {
          if (Members[i]->isId(MemberID)) return true;
     }
     return false;
          
}

//We will add the Member info with this function
void insert () 
{
cout<<"\nPlease enter your first name, last name and ID number. "<<endl;
     string fname, lname, am, pm, Nishimura;
     int MemberID, wakeTime, sleepTime, napTime, peakEnergyTime;
     int wakeLight, sleepLight, napLight, peakEnergyLight;
    
     cin >>fname>>lname>>MemberID;
	 cout<<"Thank you "<<fname<<". "<<endl<<"\nPlease enter your desired Circadian Settings"<<endl;
     cout<<"-WAKE UP TIME:";
     cin>>wakeTime>>am;
     cout<<"-SLEEP TIME: ";
     cin>>sleepTime>>am;
     cout<<"-NAP TIME: ";
     cin>>napTime>>am;
     cout<<"-PEAK ENERGY TIME: ";
     cin>>peakEnergyTime>>am;
     
     cout<<"Thank you "<<fname<<". "<<endl<<"\nPlease enter your desired Lighting Settings"<<endl;
     cout<<"-WAKE UP LIGHT:";
     cin>>wakeLight>>am;
     cout<<"-SLEEP LIGHT: ";
     cin>>sleepLight>>am;
     cout<<"-NAP LIGHT: ";
     cin>>napLight>>am;
     cout<<"-PEAK ENERGY LIGHT: ";
     cin>>peakEnergyLight>>am;
     
     
     if (exists_already(MemberID)) cout<<  "Error! The ID number already exists "<< endl;
	
      else {
		MemberA.assign(fname, lname, MemberID, wakeTime, sleepTime, napTime, peakEnergyTime, wakeLight, sleepLight, napLight, peakEnergyLight);
	    Members[num++] = new Member(fname, lname, MemberID, wakeTime, sleepTime, napTime, peakEnergyTime, wakeLight, sleepLight, napLight, peakEnergyLight);
        
        }
cout<<endl;
}

// This function will remove the Member info
void delet () 
{
int MemberID;
cout<<"Enter Member ID: ";
cin>>MemberID;		 
	        int i;
	for (i=0; i<num; i++)
		if (Members[i]->isId(MemberID))
	{
			delete Members[i];
			break;
	}
	if (i==num) cout<<"false"<<endl;
	
	
	else	 MemberA.remove(MemberID);
	

}

//This function modify member info 
/*void modify ()
{
int MemberID;
cout<<"Enter member ID: ";
cin>>MemberID;
               int i;
	for (i=0; i<num; i++)
		if (Members[i]->isId(MemberID))
	{
			break;
	}
        if (i==num) cout<<"wrong ID"<<endl;

        else MemberA.change(MemberID);
	
}*/

// This function will show the information
void print ()
{  
       MemberA.show();
}


// this function will prompt the user to type in the comands
// the input will direct the action to the functions.
void funcion() {


while (1)
	{
	string input;
	cout<<"            ---  Intelligent Lighting Control System  --- "<<endl;
    cout<<"            *                                            *"<<endl;
    cout<<"            *                Welcome                     *"<<endl;
    cout<<"            *                                            *"<<endl;
    cout<<"            *____________________________________________*"<<endl;
    
    cout<<"   \n \n   *New Member = new       *Existing Member = Member ID"<<endl;
    cout<<endl<<"\nCommands are case sensitive. Insert them in lower case please"<<endl;
    cin>>input;
    
    if (input=="new"){
	                  cout<<"\n\n Menu Options:"<<endl<<"1. Add"<<endl;
                      cout<<"2. Quit"<<endl<<"\nCommands are case sensitive. Insert them in lower case please"<<endl;
	                  cin >> input;
	
	//redirecting the program to the correct function
			if (input=="print") print();
			else if (input=="quit" ) exit(0);
			else if (input=="remove") delet  ();
			else if (input=="add" )   insert ();
           // else if (input=="modify") modify(); 
		    else { cout << "Error!" << endl;}
           }
           
      else  { print(); }

}


}

//main initializes here
int main() {

	funcion ();
	return 0;

}
