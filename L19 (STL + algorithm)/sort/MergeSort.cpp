#include<iostream>
using namespace std;

void merge(int *arr, int s, int e){
    
    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy value
    int minArrindex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[minArrindex++];
    }
    
    minArrindex = mid + 1;
    for (int i = 0; i < len2; i++){
        second[i] = arr[minArrindex++];
    }

    // merge 2 sorted arrays
    int index1 = 0;
    int index2 = 0;
    minArrindex = s;

    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[minArrindex++] = first[index1++];
        }else{
            arr[minArrindex++] = second[index2++];
        }
    }

    while(index1 < len1){
        arr[minArrindex++] = first[index1++];
    }

    while(index2 < len2){
        arr[minArrindex++] = second[index2++];
    }

    delete []first;
    delete []second;
    
}

void mergesort(int *arr, int s, int e){

    // base case
    if(s>=e){
        return;
    }

    // mid
    int mid = (s+e)/2;

    // left part
    mergesort(arr, s, mid);

    // right part
    mergesort(arr, mid+1, e);

    // merge
    merge(arr, s, e);
    
}

int main(){
    int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    int n = 10;
    mergesort(arr, 0, n-1);

    for(int i:arr){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}