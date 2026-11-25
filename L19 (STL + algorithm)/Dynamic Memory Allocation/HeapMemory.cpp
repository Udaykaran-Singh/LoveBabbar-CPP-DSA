#include<iostream>
using namespace std;

/*
"do not run the code. its just so that i can understand.";
*/



// we use keyword 'new' to  use HEAP Memory. until now we have use STACK Memory.
// Stack Memory is small, Heap memory is large.
// in Stack, memory allocation is STATIC memory allocation.
// whereas in Heap, it is DYNAMIC memory allocation.

int main(){

    // stack memory automatically get released.
    // heap memory keeps on increasing (stacking), we need to do everything manually (i.e. clear it by ourself).


    "basic :- how we can use heap memory";

    char* ch = new char;

    // new char i;          // cannot do like this 
    
    /* in Dynamic memory allocation we cannot assign variable name .
       it just mark area equal to size of data type and return its REFRENCE. */

    /* here ch pointer have space in stack memory.
       whereas new char is in heap memory. */
    
    // total memory initially we are playing with = 9.
    // (1 of char in heap + 8 of pointer address stored in stack)


    "how to DELETE (release heap memory)";
    delete ch;


    "(1-D array) how we can make an array in heap memory";


    int* arr = new int[10];
    // total memory use : 4*10 (heap) + 8 (stack) = 48 


    "1-D Variable Size Array (this is right way)";

    int n;
    cin>>n;

    int* arr = new int[n];           // look 2d array

    // int arr[n];                  //  never do like this again.


    "access array as we have done always.      like arr[i]";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    

    "DELETE array";
    delete []arr;


    "2-D array";                            // n rows ; m columns.
    int m ;
    int ** arr1 = new int*[n];
    for (int i = 0; i < n; i++) {
        arr1[i] = new int[m];
    }


    "DELETE 2-D Array";
    for (int i = 0; i < n; i++) {
        delete[] arr1[i];
    }
    delete[] arr1;

    return 0;
}