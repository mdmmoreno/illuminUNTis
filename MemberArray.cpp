#include <iostream>
#include <cstdlib>
#include "MemberArray.h"



using namespace std;
int TSIZE =10;


//Constructor
MemberArray::MemberArray() 
{
// the array is being filled with null
          for (int i=0; i<TSIZE; i++) {this->array[i]= NULL;}
}   

                    
//------------ Assign  
/*
This function will create a node with each index(id) inserted
*/                          
void MemberArray::assign( string fname, string lname, int MemberID, int wakeTime, int sleepTime, int napTime, int peakEnergyTime, int wakeLight, int sleepLight, int napLight, int peakEnergyLight){
           int index, index2;
           int Number= 3445;
           index2= Number % TSIZE;
           index = MemberID % TSIZE;
           
           //mod function
           //array[index2]= new Member ("marina","nishimura",MemberID,  wakeTime, sleepTime, napTime, peakEnergyTime); 
		   //if the id inserted is not causing any collision, do this
           if (array[index]==NULL)
           array[index] = new Member (fname, lname, MemberID,  wakeTime, sleepTime, napTime, peakEnergyTime, wakeLight, sleepLight, napLight, peakEnergyLight);
           
		   //this else if is for when there's a collision
           else if( array[index]!=NULL)
				{
					assign2 (fname, lname, MemberID, wakeTime, sleepTime, napTime, peakEnergyTime, wakeLight, sleepLight, napLight, peakEnergyLight);
          		 
				}
 }
//-----------------Second function-- h(x)+i^2) mod B
void MemberArray::assign2( string fname, string lname, int MemberID, int wakeTime, int sleepTime, int napTime, int peakEnergyTime, int wakeLight, int sleepLight, int napLight, int peakEnergyLight){
           int index;
           /*
           this function is being assigned for a collision
           since i has to go from 0 to 9 there's a for loop
           once it found an empty box it will create the node
           */
	    int i=1;
	    index =( ((MemberID % TSIZE)+ (i*i))%TSIZE) ;
		/*
		here if the new index that is being assigned is 
		empty, insert the info here then 
		*/
	   if ( array[index]==NULL)                             
           array[index] = new Member (fname, lname, MemberID,  wakeTime, sleepTime, napTime, peakEnergyTime,wakeLight, sleepLight, napLight, peakEnergyLight); 
           
		/*
		if we have a second collision, meaning the index is already
		containing information, then we run the formula again incrementing 
		the i 
		*/
 	else {
		i++;
              index =( ((MemberID % TSIZE)+ (i*i))%TSIZE) ;
		      array[index] = new Member (fname, lname, MemberID,  wakeTime, sleepTime, napTime, peakEnergyTime, wakeLight, sleepLight, napLight, peakEnergyLight);
			}
       
     }

//-------------------Remove
void MemberArray::remove(int MemberID){
           int i=1;
	       int index;
           index = MemberID % TSIZE; 
        //checking for id's that did not had a collision   
         if (array[index]->retMemberID()==MemberID)
		{ 
			cout<<"true"<<endl;
			array[index]->removed= true;
		}
        /* 
		in case the id does not match the box, we have two escenarios
		the id had a collision  OR the id doesn't exist
		
		*/
		else if (array[index]->retMemberID()!= MemberID)

		{
		i++;
              index =( ((MemberID % TSIZE)+ (i*i))%TSIZE) ;
              cout<<"true"<<endl;
			  array[index] ->removed= true;
		}
		
}

//----------------Show
void MemberArray::show(){
     /*
     I broke this code into two parts so the last element
     in the array prints out and breaks a new line
     */
      int  index2;
      int Number= 3445;
      index2= Number % TSIZE;
     for (int index=0; index<TSIZE-1;index++)
     {    
        if (array[index]==NULL) cout<<"Empty"<<endl<<endl;
         
        else if (array[index]->removed) cout<<"Deleted"<<endl<<endl;
        else if (array[index2]!= NULL)
         {
         cout<<array[index2]->retfname()<<" ";
         cout<<array[index2]->retlname()<<" ";
         cout<<array[index2]->retMemberID()<<" ";
         cout<<array[index2]->retwakeTime()<<" ";
         cout<<array[index2]->retsleepTime()<<" ";
         cout<<array[index2]->retnapTime()<<" ";
         cout<<array[index2]->retpeakEnergyTime()<<" ";
         cout<<endl<<endl;
         }
         
        else 
         {
         cout<<array[index]->retfname()<<" ";
         cout<<array[index]->retlname()<<" ";
         cout<<array[index]->retMemberID()<<" ";
         cout<<array[index]->retwakeTime()<<" ";
         cout<<array[index]->retsleepTime()<<" ";
         cout<<array[index]->retnapTime()<<" ";
         cout<<array[index]->retpeakEnergyTime()<<" ";
         cout<<endl<<endl;
         }
         
         
         
         
     }   
 // last element to print
         int index=9;
         if (array[index]==NULL)cout<<"Empty"<<endl<<endl;
         
         else if (array[index]->removed) cout<<"Deleted"<<endl<<endl;
         
         else 
         {
         cout<<array[index]->retfname()<<" ";
         cout<<array[index]->retlname()<<" ";
         cout<<array[index]->retMemberID()<<" ";
         cout<<array[index]->retwakeTime()<<" ";
         cout<<array[index]->retsleepTime()<<" ";
         cout<<array[index]->retnapTime()<<" ";
         cout<<array[index]->retpeakEnergyTime()<<" ";
         cout<<endl<<endl; 
              }
     }
