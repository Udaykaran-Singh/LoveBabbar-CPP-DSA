#include<iostream>
using namespace std;

int main(){
    int n = 6;
    int petrol[6] = {6, 7, 4, 10, 6, 5};
    int distance[6] = {5, 6, 7, 8, 6, 4};



    int deficit = 0;
    int balance = 0;
    int start = 0;

    for (int i = 0; i < n; i++){
        balance = balance + petrol[i] - distance[i];
        if(balance < 0){
            deficit += balance; 
            start = i+1;
            balance = 0;
        }
    }
    
    if(deficit+balance >= 0){
        cout<<start+1<<endl;
        cout<<"pertol pump having petrol "<<petrol[start]<<" and next petrol pump at distance "<<distance[start]<<endl;
    }else{
        cout<<"cannot complete loop form any petrol pump";
    }

    return 0;
}