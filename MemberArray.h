#ifndef STUDENTARRAY_H_	
#define STUDENTARRAY_H_
#include <cstdlib>
#include "Member.cpp"






class MemberArray {
	private:
		int md_MemberID;
		Member* array[10];
			
	public: 
		MemberArray();
		MemberArray( string fname, string lname, int MemberID, int wakeTime, int sleepTime); 
		
		
		void assign (string fname, string lname, int MemberID, int wakeTime, int sleepTime); 
		void assign2 (string fname, string lname, int MemberID, int wakeTime, int sleepTime); 
		void remove (int MemberID);
		void show();
		
};

#endif
	
	
