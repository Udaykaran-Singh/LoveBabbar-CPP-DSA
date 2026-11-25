#include<iostream>
#include<algorithm>
#include<array>
using namespace std;
int main(){
    array<int, 11> uday = {2, 0, 1, 0, 0, 3, 0, 93, 24, 0, 0};
    
    // array<int,11>::iterator it = uday.begin();
    // int i = 0, j = 0, count = 0; 
    // while(count<=11){
    //     count++;
    //     if(uday[j]==0){
    //         rotate(it+i, it+i + 1,uday.end());
    //         continue;
    //     }
    //     cout<<*it<<" "<<uday[i]<<endl;
    //     j++;
    //     i++;
    // }

    int j=0;
    for(int i = 0; i<11; i++){
        if(uday[i] !=0){
            swap(uday[j], uday[i]);
            j++;
        }
    }


    for(int i:uday){
        cout<<i<<" ";
    }cout<<endl;
}