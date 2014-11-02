#include <iostream>
#include <cstdlib>
#include <vector>
#include "MemberArray.h"
#include "MemberArray.cpp"
#include "Member.h"
#include <unistd.h>
#include <ctime>

using namespace std;

int main() {
	MemberArray array;
	string input;
/*
	// We can use this child process to update the lights every 10 seconds or so.
	pid_t pid = fork();
	cout << "PID: " << pid << endl;
	if(pid == 0) {
	//	cout << "forked";
		int i = 0;
		time_t timer;
		time(&timer);
		while(i<10){
			cout << "The time: " << asctime(localtime(&timer)) << endl;
			sleep(10);
			time(&timer);
			i++;
}*/
//		return 0;
//	}
	// menu
	while (1)
	{
	input = "";
	cout<<"       ---  Intelligent Lighting Control System  ---      "<<endl;
        cout<<"      *                                            *      "<<endl;
        cout<<"      *                                            *      "<<endl;
    	cout<<"      *                   Welcome                  *      "<<endl;
    	cout<<"      *                                            *      "<<endl;
    	cout<<"      *                                            *      "<<endl;
	cout<<"      *____________________________________________*      "<<endl;

	cout<<"     \n\n  *New Member = new       *Existing Member = existing"<<endl;
	cout<<endl<<"\nCommands are case sensitive. Insert them in lower case please"<<endl;

	cin>>input;

	if (input=="new"){
		cout<<"\n\n\n\n\n Menu Options:"<<endl;
		cout<<"                	1. add"<<endl;
		cout<<"			2. quit"<<endl;
		cout<<"			3. remove"<<endl;
		cout<<"                 4. modify"<<endl;
		cout<<"\nCommands are case sensitive. Insert them in lower case please"<<endl;
		cin >> input;

		 if (input=="quit" ) { 
			exit(0);
	        } else if(input=="remove"){ 
			array.del();
		} else if (input=="add" )  { array.create();
		} else if (input=="modify") {
			array.modify();
		} else {	cout << "Error!" << endl;}
	} else if (input=="existing") { 
		array.displayAll(); 
	} else { 
		cout << "Nonsense." << endl;
	}
	}

	return 0;


}
