#include<iostream>
#include<string>
using namespace std;

/* object is something having properties and behaviour */

class hero {                // making class
                            // when class has in this, and we make an object then:-
                            // Empty object holds 1 byte of memeory ( Note :- it is not 0)
    

    
    /* Access Modifiers :- 
       1. Public
       2. Private : used by default in class
       3. protected */
    
    /* public :
       int health;
       char rank;
       
       public class means it can be used anywhere (programm and also in class) */
    
    /* private :
       int health;
       char rank;


       private class means it can only be used in class itself ,
       nowhere else by simple means but by getter and setter we can access it in out main code. */
    
    /* protected :
       int health;
       char rank; 
       
       protected class means it cannot be used anywhere */
    
    
    // properties :-
        private:
        int health;

        public:
        char *name = new char[100];
        char rank;

        static int TimeToComplete;
    
    // can be accessed using '.' operator.


    /* creating constructor :                           // created by default, if user do not make this.
                                                        // no need to make it,
                                                        // but user can make it himself also if he wants.
                                // THEN DEFAULT CONSTRUCTOR WILL AUTOMATICALLY WILL BE DELEATED AND ONLY USER MADE WILL RUN. 
        hero(){
            cout<<"Default constructor called ."<<endl; 
        } 
        
        it will run for:-
        1. hero ramesh;
        2. hero *h = new hero;    also new hero();
        
        before this hero previous line will run
        when this comes constructor will run
        after this next lines will run */

    /* Parameterised constructor :

       hero(int health){
            this -> health = health;                    // "this" keyword store adderss of current object (this -> health in ClassHero = health send through parameter.)
                                                        // which means "this" is a pointer.
         } */

    /* Copy constructor :                               // inbuilt . but user can also built it.

       hreo(hero& temp){                                // '&' used because now default copy constructor can not be used, as we have created one.
                                                        //  now we cannot send it 'by value' i.e. creating a copy, so using '&' we send it by refrence i.e. alias.
            this -> health = temp.health;
            this -> rank = temp.rank;
       }*/

    
    // how to get (getter) or set (setter) something : {output, input}
    int gethealth(){
        return health;
    }
    char getrank(){
        return rank;
    }

    void sethealth(int h){
        health = h;
    }
    void setrank(char ch){
        rank = ch;
    }
    void setname(char name[]){
        strcpy(this -> name, name);
    }

    /*  SHALLOW and DEEP copy

        Shallow copy :
        default copy constructor do shallow copy.
        i.e. change in this copy of thing can be shown in real thing
    
        Deep copy :
        copy constructor made by us do Deep copy*/



    // Destructor :                // for static allocation destructor is called automatically
                                   // for dynamic allocation we need to use "delete" keyword to use destructor.
    ~hero(){
        cout<<endl<<"default destructor called."<<endl;
        delete[] this->name;
    }
    /*  int main(){
        hero a;                     // cout will be printed.
        hero *b = new hero();       // cout will not be printed.
        delete b;                   // cout will be printed.
        }*/


};

int hero::TimeToComplete = 60;