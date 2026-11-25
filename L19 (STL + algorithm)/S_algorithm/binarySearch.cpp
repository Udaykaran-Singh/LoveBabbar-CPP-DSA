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

    cout<<"is 5 present : "<<binary_search(uday.begin(), uday.end(),5)<<endl;
    cout<<"is 6 present : "<<binary_search(uday.begin(), uday.end(),6)<<endl;

    cout<<"lower bound : "<<lower_bound(uday.begin(),uday.end(),5)-uday.begin()<<endl<<endl;


}