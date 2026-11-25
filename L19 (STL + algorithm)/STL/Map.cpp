#include<iostream>
#include<map>

using namespace std;
int main(){
    map<int,string> uday;
    uday[1] = "Udaykaran";
    uday[19] = "Sadioura";  
    uday[3] = "Singh";
    uday[3] = "Sin";

    for(auto i:uday){
        cout<<i.first<<" ";
    }cout<<endl<<endl;

    // uday.insert({10,"Rajput"});                  // it worked on sir's computer.
    uday[10] = "Rajput";
    for(auto i:uday){
        cout<<i.first<<" "<<i.second<<endl;
    }cout<<endl;


    // .count()
    cout<<"no. of 3 present : "<<uday.count(3)<<endl<<endl;


    // .erase()
    uday.erase(19);
    cout<<"after erase"<<endl;
    for(auto i:uday){
        cout<<i.first<<" "<<i.second<<endl;
    }cout<<endl;


    // .find(element)
    auto it = uday.find(3);
    for(auto i = it; i!=uday.end(); i++){
        cout<<(*i).first<<" "<<(*i).second<<endl;
    }cout<<endl;
    

    // .at(key)
    cout<<uday.at(3);
}