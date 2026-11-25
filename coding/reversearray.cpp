#include<iostream>
#include<array>
#include<algorithm>

using namespace std;
int main(){
    array<int, 10> uday ={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int m =3;

    // // boss
    // reverse(uday.begin() + m+1, uday.end());

    // // 1st
    // for (int i = 0; i < 4/2; i++){
    //     // int temp = uday[i];
    //     // uday[i] = uday[3-i];
    //     // uday[3-i] = temp;
    //     swap(uday[i], uday[3-i]);
    // }

    int s = m+1;
    
    // // 2nd    reverse after mth position
    // int e = 10;
    // for (int i = s, j=0; i < (s+e)/2; i++, j++)
    // {
    //     swap(uday[i], uday[9-j]);
    // }
    
    // // 3rd    reverse after mth position
    // int e = 9;
    // while (s<=e)
    // {
    //     swap(uday[s], uday[e]);
    //     s++;
    //     e--;
    // }
     
    for(auto i:uday){
        cout<<i<<" ";
    }cout<<endl;


}