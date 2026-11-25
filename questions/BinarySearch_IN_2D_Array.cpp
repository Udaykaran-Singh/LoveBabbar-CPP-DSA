#include<iostream>
using namespace std;

int main(){
    int arr[3][4] = {{1, 3, 5, 7}, {10, 11, 16, 20}, {22, 30, 34, 60}};
    int row = 3, column = 4;
    int target = 10;

    int start = 0, end = row*column -1;
    int mid = start + (end-start)/2;

    while(start<=end){
        int element = arr[mid/column][mid%column];
        if(element == target){
            cout<<"😏"<<endl;
            break;
        }else if(element < target){
            start = mid + 1;
        }else{
            end = mid -1;
        }
        mid = start + (end-start)/2;
    }


}