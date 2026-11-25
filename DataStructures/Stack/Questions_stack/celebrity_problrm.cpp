#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// celebrity knows no one
// everyone knows celebrity

int main(){

    int M[3][3] = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    int n = 3;

    stack<int> s;
    // step 1: push all element in stack
    for (int i = 0; i < n; i++){
        s.push(i);
    }

    // step 2:
    while(s.size() > 1){
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if(M[a][b] == 1){
            s.push(b);
        }else{
            s.push(a);
        }
    }

    int ans = s.top();

    // step 3: single element in stack is potential celeb
    // so verify it

    bool rowcheck = false;
    int zerocount = 0;

    for(int i=0; i<n; i++){
        if(M[ans][i] == 0)
            zerocount++;
    }
    // all zeroes
    if(zerocount == n){
        rowcheck = true;
    }

    // column check
    bool colcheck = false;
    int onecount = 0;
    for(int i = 0; i < n; i++){
        if(M[i][ans] == 1)
            onecount++;
    }
    if(onecount == n-1){
        colcheck = true;
    }

    if(rowcheck && colcheck){
        cout<<ans<<endl;
    }
    

}