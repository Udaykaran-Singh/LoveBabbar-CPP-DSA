#include<iostream>
#include<vector>
#include<stack>
#include<math.h>
#include<algorithm>
using namespace std;


vector<int> nextSmallerElement(int* arr, int n){

    stack<int> s;
    s.push(-1);
    vector<int> ans(n) ;

    for(int i=n-1; i>=0 ; i--) {
        int curr = arr [i];
        while(s.top() != -1 && arr[s.top()] >= curr){
            s.pop( );
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;


}

vector<int> prevSmallerElement(int* arr, int n){

    stack<int> s;
    s.push(-1);
    vector<int> ans(n) ;

    for(int i=0; i<n ; i++) {
        int curr = arr [i];
        while(s.top() != -1 && arr[s.top()] >= curr){
            s.pop( );
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;


}

int largestrecarea(int* arr, int n){

    vector<int> next(n);
    next = nextSmallerElement(arr, n);

    vector<int> prev(n);
    prev = prevSmallerElement(arr, n);

    int are = 0;
    for (int i = 0; i < n; i++)
    {
        int ll = arr[i];
 
        if(next[i] == -1){
            next[i] = n;
        }

        int bb = next[i] - prev[i] -1;

        int newArea = ll*bb;
        are = max(are, newArea);
    }

    return are;

}

int main(){
    int arr[4][4] = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};

    for(int i = 0; i < 4; i++){

        for (int j = 0; j < 4; j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
        
    }cout<<endl;

    int n =4 ;

    // compute area for first row
    int area = largestrecarea(arr[0], n);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++){
            // row update: by adding previous row's value
            if(arr[i][j] != 0){
                arr[i][j] = arr[i][j] + arr[i - 1][j];
            }else{
                arr[i][j] = 0;
            }
        }

        // entire row is updated now
        area = max(area, largestrecarea(arr[i], n));
        
    }
    
    cout<<area<<endl;

}