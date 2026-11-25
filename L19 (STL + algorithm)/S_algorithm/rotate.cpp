#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main(){
    vector<int> uday;
    uday.push_back(1);
    uday.push_back(3);
    uday.push_back(5);
    uday.push_back(7);
    uday.push_back(8);
    uday.push_back(90);
    uday.push_back(7);

    for(int i:uday){
        cout<<i<<" ";
    }cout<<endl<<endl;


    rotate(uday.begin()+2, uday.begin()+3,uday.end()-1);
    cout<<"after rotating :"<<endl;

    for(int i:uday){
        cout<<i<<" ";
    }cout<<endl;


}