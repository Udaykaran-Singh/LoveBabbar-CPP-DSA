#include<iostream>
#include<vector>
#include<stack>
#include<math.h>
using namespace std;

// by sir

vector<int> nextSmallerElement(vector<int> arr, int n){

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

vector<int> prevSmallerElement(vector<int> arr, int n){

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





// by me
void area_his(vector<int> &area, vector<int> &arr){

    for (int i = 0; i < arr.size(); i++){

        int left = 0, right = 0;
        int j = i+1;
        // left and right dekh lo kitne me length fit aa skti ha oos block ko consider nahi kiya 
        while(arr[i] <= arr[j] && j < arr.size()  ){
            right++;
            j++;
        }
        j = i-1;
        while(j >= 0 && arr[i] <= arr[j]){
            j--;
            left++;
        }

        area[i] = arr[i]*(left + right + 1);
        // cout<<area[i]<<"   "<<arr[i]<<"   "<<left<<"   "<<right<<endl;

    }
}

int main(){

    // arr vector show block of width 1 and length equal arr[i]
    vector<int> arr(6,0);

    arr[0] = 2;
    arr[1] = 1;
    arr[2] = 5;
    arr[3] = 6;
    arr[4] = 2;
    arr[5] = 3;

    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" "; 
    }cout<<endl<<endl;
    

    vector<int> area(6,0);
    // max area kya nikal skte he arr me se (rectangle hi hona chahiaa)
    area_his(area, arr);

    for (int i = 0; i < area.size(); i++)
    {
        cout<<area[i]<<" "; 
    }cout<<endl;
    








    // acc to sir

    int n = arr.size();

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

    cout<<are<<endl;


}