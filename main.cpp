#include <iostream>
#include <cstdlib>
#include "MemberArray.h"
#include "MemberArray.cpp"

/*
T.A. I know it's good practice to include header files. 
However, I'm submitting my program the way it compiles in
the CSE machines.
*/


using namespace std;
//=====variables constantes/ constants
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
cout<<"\nPlease insert your first name, last name and ID number. "<<endl;
     string fname, lname;
     int MemberID, wakeTime, sleepTime;
    
     cin >>fname>>lname>>MemberID;
	 cout<<"Thank you "<<fname<<" . Please insert your desired wake up and sleeping time. "<<endl;
     cin>>wakeTime>>sleepTime;
     
     if (exists_already(MemberID)) cout<<  "Error! The ID number already exists "<< endl;
	
      else {
		MemberA.assign(fname, lname, MemberID, wakeTime, sleepTime);
	    Members[num++] = new Member(fname, lname, MemberID, wakeTime, sleepTime);
        }
cout<<endl;
}

// This function will remove the Member info
void delet () 
{
int MemberID;
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
	cout << "---  Intelligent Lighting Control System  --- "<<endl<<"\n\nWelcome "<<endl;
	cout<<"\n\n Menu Options:"<<endl<<"1. Add"<<endl<<"2. Remove"<<endl;
	cout<<"3. Print"<<endl<<"4. Quit"<<endl<<"\nCommands are case sensitive. Insert them in lower case please"<<endl;
	cin >> input;
	
	//redirecting the program to the correct function
			if (input=="print") print();
			else if (input=="quit" ) exit(0);
			else if (input=="remove") delet  ();
			else if (input=="add" )   insert (); 
		    else { cout << "Error!" << endl;}
	}




}

//main initializes here
int main() {

	funcion ();
	return 0;

}
