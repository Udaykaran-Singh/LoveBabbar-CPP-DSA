#include<iostream>
#include "ClassHero.cpp"
using namespace std;

// int hero::TimeToComplete = 60;

int main(){
    // class is user define datatype         e.g. hero uday;      similar to      char ch;
                                             // here hero is class

    cout<<endl<<"Static used :"<<hero::TimeToComplete<<endl;


    /* making object out of class */


    /* // dynamic allocation
    hero* h = new hero;    

    h->sethealth(999);
    h->rank = 'a' ;           
    cout<<"health of h : "<<(*h).gethealth()<<endl;
    cout<<"Rank of h : "<<(*h).rank<<endl;

    // can also do like :-
    cout<<"health of h : "<< h->gethealth()<<endl;
    cout<<"Rank of h : "<<h->rank<<endl;

    // because : 
    // (*var_Holding_Address).dot_opperator = var_Holding_Address -> something 

    delete h; */


    // static allocation
    hero Uday;
    Uday.rank = 'S';

    // Uday.health = 100;                                     // this give error as health is private
    // cout<<"Health is : "<<Uday.health<<endl;

    // using setter
    Uday.sethealth(100);

    char name[] = "Udaykaran Singh";
    Uday.setname(name); 

    cout<<endl<<"size of hero class : "<<sizeof(Uday)<<endl<<endl;      // padding done :- [roof<(Total bits used)/32>]*


    // copying Uday into ram : 
    // hero ram(Uday);
    // cout<<"ram rank : "<<ram.rank<<endl<<"ram health : "<<ram.gethealth()<<endl;

    // copy assignment operator :
    // ram = uday;

    // using getter
    cout<<"[ Name :"<<Uday.name<<", ";
    cout<<"Health : "<<Uday.gethealth()<<", ";      // this will work 
    cout<<"Rank : "<<Uday.rank<<" ]"<<endl;
    
    // delete []Uday.name;


    return 0;
}