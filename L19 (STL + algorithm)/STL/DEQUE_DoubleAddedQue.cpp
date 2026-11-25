#include<iostream>
#include<queue>

using namespace std;
int main(){
    deque<int> uday;

    // .push_back(element) ; .push_front(element)
    cout<<"after pushing :"<<endl;
    uday.push_back(1);
    uday.push_front(2);
    uday.push_back(3);
    uday.push_front(4);
    for(int i:uday){
        cout<<i<<" ";
    }cout<<endl<<endl;

    // .pop_back() ; .pop_front()            // cannot use the value
    cout<<"after popi_back() :"<<endl;
    uday.pop_back();
    for(int i:uday){
        cout<<i<<" ";
    }cout<<endl<<endl;


    // .at(index) ;  .front() ;  .back() .

    // .empty()                                     // give 0 when not empty


    // .erase(startIND, endIND)
    uday.erase(uday.begin()+1, uday.begin()+2);
    for(int i:uday){
        cout<<i<<" ";
    }cout<<endl<<endl;




}