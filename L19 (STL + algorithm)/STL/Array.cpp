#include<iostream>
#include<array>

using namespace std;
int main(){
    array<int, 4> uday = {1, 2, 3, 4};

    uday[1] = 19;

    for (int i = 0; i < 4; i++)
    {
        cout<<uday[i]<<" ";
    }
    cout<<endl;

    // .at(index)
    cout<<"element at index 2 : "<<uday.at(2)<<endl;

    // .empty()                // if not empty give 0 (i.e. false)
    cout<<"empty or not : "<<uday.empty()<<endl;

    // .front()
    cout<<"first element : "<<uday.front()<<endl;

    // .back()
    cout<<"last element :"<<uday.back()<<endl;

    // .size()
    cout<<"size : "<<uday.size()<<endl;

    // .fill(element)
    uday.fill(3);
    for (int i = 0; i < 4; i++)
    {
        cout<<uday[i]<<" ";
    }cout<<endl;


    


    // // .capacity()                               // no such thing
    // cout<<"capacity : "<<uday.capacity()<<endl;

    // // .clear()                                  // no such thing
    // uday.clear();





}
