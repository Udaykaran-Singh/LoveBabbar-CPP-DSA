#include<iostream>
using namespace std;

int main(){
    int n = 6;
    int arr[] = {5, 3, 19, 20, 11, 10};
    int temp;


    // // sort
    // for (int i = 0; i < n-1; i++)
    // {
    //    for (int j = i+1; j < n; j++)
    //    {
    //        if (arr[i]>arr[j])
    //        {
    //            temp = arr[j];
    //            arr[j] = arr[i];
    //            arr[i] = temp;
    //        }
    //    }
    // }


    // // selection sort (take smallest element to first)
    // for (int i = 0; i < n-1; i++)
    // {
    //     int MinAtInd = i;
    //     for (int j = i+1; j < n; j++)
    //     {
    //         if (arr[MinAtInd] > arr[j])
    //         {
    //             MinAtInd = j;          
    //         }
    //         // cout<<arr[MinAtInd]<<" ";   
    //     }
    //     // cout<<endl;
    //     int temp = arr[i];
    //     arr[i] = arr[MinAtInd];
    //     arr[MinAtInd] = temp;
    // }


    // // bubble sort (take largest element to last)
    // for (int i = 0; i < n-1; i++)
    // {
    //     bool swapdone = false;
    //     for (int j = 0; j < n-1-i; j++)
    //     {
    //         if (arr[j] > arr[j+1])
    //         {
    //             swap(arr[j], arr[j+1]);
    //             swapdone = true;
    //         }  
    //         // cout<<arr[j]<<" ";
    //     }
    //     // cout<<endl;
    //     if (swapdone == false)
    //     {
    //         break;
    //     }  
    // }
    

    // // insertion sort
    // for (int i = 0; i < n; i++)
    // {
    //     int temp = arr[i];
    //     int j = i-1;
    //     for (; j >= 0; j--)
    //     {
    //         if (arr[j] > temp)
    //         {
    //             // shift
    //             arr[j+1] = arr[j];
    //         }
    //         else{
    //             break;
    //         }
    //         // cout<<arr[j]<<" ";
    //     }
    //     // cout<<endl;
    //     arr[j+1] = temp;
    // }
    

    // // printing arr
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }

    return 0;

}