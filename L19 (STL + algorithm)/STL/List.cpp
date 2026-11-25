#include<iostream>
#include<list>

using namespace std;
int main(){
    list<int> uday;

    // .push_back(element) ; .push_front(element)
    cout<<"after pushing :"<<endl;
    uday.push_back(1);
    uday.push_front(2);
    uday.push_back(3);
    uday.push_front(4);
    for(int i:uday){
        cout<<i<<" ";
    }cout<<endl<<endl; 

    // .erase() ; .size()

    // .pop_back() ; .pop_front()



    // // .at(index)                               // no such thing
    // cout<<uday.at(1)<<endl; 


}