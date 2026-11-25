#include<iostream>
using namespace std;

class student {
    private:
        string name;
        int age;
        int height;
    
    public:
        int getage(){
            return this-> age;
        }
};

int main(){
    /* Encapsulation :        this is a class.         // aka Data Hiding or Information Hiding. 
       wrapping up data members and functions. (properties and behaviours(methods)) 
       
       Fully Encapsulated Class :
       all data members are of Private Marked (type). 
       
       Advantage :-
       1. data hide.
       2. if we want, we can make read only class.
       3. code reuseability. 
       4. help in unit testing.  */
    
    student one;
    cout<<"sab chal chuka hai. "<<endl;

    // we have already done everything in ClassHero i.e. use of "getter", "setter" to use "private members" .

}