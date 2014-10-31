#ifndef MEMBERARRAY_H_	
#define MEMBERARRAY_H_
#include <cstdlib>
#include <vector>
#include "Member.cpp"


using namespace std;

class MemberArray {
	public:
		vector <Member> members;
		MemberArray();
		void modify();
		void create();
		void del();
		int find(int); // returns -1 if not found
		void displayAll();
};

#endif
