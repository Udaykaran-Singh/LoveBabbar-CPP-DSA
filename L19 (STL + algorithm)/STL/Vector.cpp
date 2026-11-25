#include<iostream>
#include<vector>

using namespace std;
int main(){

    vector<int> initialising(5,0);                    // capacity and size 5; all elements 0
    for(int i:initialising){
        cout<<i<<" ";
    }cout<<endl<<"capacity : "<<initialising.capacity()<<endl<<"initialising size : "<<initialising.size()<<endl<<endl;


    // copy initialising vector into other vector 'coping'
    vector<int> coping(initialising);
    cout<<"copied vector :"<<endl;
    for(int i:coping){
        cout<<i<<" ";
    }cout<<endl<<endl; 





    
    vector<int> uday;

    // .capacity()                 // give full capacity of vector (max elements that can be accomodated in vector in current state)
    cout<<"capacity : "<<uday.capacity()<<endl<<endl;

    // .push_back(element);                 // capacity inc as (0 1 2 4 8 16 ....) i.e.  2*(previous capacity);
    uday.push_back(3);
    cout<<"entering an element uday.push_back(1) ."<<endl;
    cout<<"now capacity :"<<uday.capacity()<<endl;
    uday.push_back(2);
    uday.push_back(1);
    cout<<"capacity after 3 enteries : "<<uday.capacity()<<endl<<endl;

    // .size                       // tell total elements in vector
    cout<<"size of vector :"<<uday.size()<<endl<<endl;

    // at(index)
    cout<<"element at index 1 : "<<uday.at(1)<<endl<<endl;

    // .front()  .back()            //same as in array


    // .pop_back()
    cout<<"before pop :"<<endl;
    for (int i = 0; i < 3; i++)
    {
        cout<<uday[i]<<" ";
    }cout<<endl;
                        // cannot use value poped;      size dec by 1 ;    capacity remain same.
    uday.pop_back();
                        // cannot do as above (as done in before part)
                        // otherwise it will print 1 2 3
    cout<<"after pop : "<<endl;
    for (int i:uday)
    {
        cout<<i<<" ";
    }cout<<endl<<endl;
    

    // . clear          // size become 0 (all elements are deleted); capacity remain same.
    cout<<"size before : "<<uday.size()<<endl<<"capacity before : "<<uday.capacity()<<endl;
    uday.clear();
    cout<<"size after : "<<uday.size()<<endl<<"capacity after : "<<uday.capacity()<<endl<<endl;
    
    cout<<"vector :"<<endl;
    for(int i:uday){
        cout<<i<<" ";
    }cout<<endl;

}