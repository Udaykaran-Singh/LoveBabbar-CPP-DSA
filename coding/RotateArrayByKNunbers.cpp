#include<iostream>
#include<array>

using namespace std;
int main(){
    array<int, 6> uday = {1, 2, 3, 4, 5, 6};
    int k = 2, i = 0;
    int arr[2] = {[0 ... 1] = 0};
    for (int i = 0; i < k; i++)
    {
        arr[i] = uday[i];
    }

    while (i < 6-k)
    {
        uday[i] = uday[i+2];
        i++;
    }
    for (int j = 0; j < k; j++)
    {
        uday[i] = arr[j];
        i++;
    }
    
    for(int i:uday){
        cout<<i<<" ";
    }cout<<endl;
    

    
    
    
}