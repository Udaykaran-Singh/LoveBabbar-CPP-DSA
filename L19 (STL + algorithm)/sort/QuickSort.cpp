#include<iostream>
using namespace std;

int partition(int arr[], int s, int e, int &count_swap, int &count_ite){

    int pivot = arr[s];

    int cnt = 0;
    for (int i = s+1; i <= e; i++){
        count_ite++;
        if(arr[i] <= pivot){
            cnt++;
        }
    }

    // place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);
    count_swap++;

    // left and right wala part
    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot){
            count_ite++;
            i++;
        }
        while(arr[j] > pivot){
            count_ite++;
            j--;
        }

        if(i<pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
            count_swap++;
        }
        count_ite++;
    }

    return pivotIndex;
    
}

void quicksort(int arr[], int s, int e, int &count_swap, int &count_ite){

    // base case
    if (s >= e){
        return;
    }

    // partition
    int p = partition(arr, s, e, count_swap, count_ite);

    // sort left part
    quicksort(arr, s, p-1, count_swap, count_ite);

    // sort right part
    quicksort(arr, p+1, e, count_swap, count_ite);

}

int main(){
    // int arr[10] = {1, 3, 5, 7, 9, 4, 4, 6, 8, 0};
    // int n = 10;

    // int arr[6] = {10, 7, 8, 9, 1, 5};
    // int n = 6;

    // int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9};
    // int n = 10;

    // int arr[10] = {9, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // int n = 10;

    // int arr[10] = {7, 1, 2, 4, 6, 5, 4, 9, 3, 5};
    // int n = 10;

    int n;
    cout<<"Enter n : ";
    cin>>n;

    int arr[n];
    cout<<"Enter elements : ";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int count_swap = 0;
    int count_ite = 0;

    quicksort(arr, 0, n-1, count_swap, count_ite);

    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    cout<<"count_swap : "<<count_swap<<endl;
    cout<<"count_swap : "<<count_ite<<endl;

    return 0;
    
}