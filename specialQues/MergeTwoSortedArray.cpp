#include<iostream>
#include<array>
#include<algorithm>

using namespace std;
int main(){
    array<int, 5> uday1 = {1, 4, 7, 9, 20};
    array<int, 7> uday2 = {2, 4, 8, 14, 15, 22, 24};

    int i = 0, j=0, k =0;
    int arr[12] ={[0 ... 11] = 0};

    // for(int i:arr){
    //     cout<<i<<" ";
    // }cout<<endl;


    while (k < 12)
    {

        if (uday1[i] <= uday2[j]){
            arr[k] = uday1[i];
            i++;
        }else{
            arr[k] = uday2[j];
            j++;
        }


        if( j>7){
            arr[k] = uday1[i];
            i++;
        }else if (i>5){
            arr[k] = uday2[j];
            j++;
        }
        
        // cout<<arr[k]<<" ";
        k++;
        // cout<< i<<" " << j <<" "<<k<<endl;

    }

    for( int i: arr){
        cout<<i<<" ";
    }cout<<endl;
    

}