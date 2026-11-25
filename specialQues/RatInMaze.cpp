#include<iostream>
#include<vector>
using namespace std;

bool issafe(int x, int y, int n, vector<vector<int>  > visited, int m[4][4]){
    if((x>=0 && x<n) && (y>=0 && y<n) && (visited[x][y] == 0) && (m[x][y] == 1)){
        return true;
    }else{
        return false;
    }
}

void solve(int m[4][4], int n, vector<string>& ans, int x, int y, vector<vector<int> > visited, string path){

    // base case
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // down
        
    if(issafe(x+1, y, n, visited, m)){
        int newx = x+1;
        int newy = y;
        path.push_back('D');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // left
        
    if(issafe(x, y-1, n, visited, m)){
        int newx = x;
        int newy = y-1;
        path.push_back('L');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    } 

    // right
        
    if(issafe(x, y + 1, n, visited, m)){
        int newx = x;
        int newy = y+1;
        path.push_back('R');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    } 

    // up
        
    if(issafe(x-1, y, n, visited, m)){
        int newx = x-1;
        int newy = y;
        path.push_back('U');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    } 

    visited[x][y] = 0;

}
 
int main(){

    int m[4][4]= {{1, 0, 0, 0},{1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int n = 4;
    
    vector<string> ans;

    if(m[0][0] != 0){
        int srcx = 0, srcy = 0;

        vector<vector<int> > visited ;
        vector<int> zero;
        for (int j = 0; j < n; j++){
            zero.push_back(0);
        }
        for (int i = 0; i < n; i++){
            visited.push_back(zero);
        }

        string path = ""; 

        solve(m, n, ans, srcy, srcy, visited, path);

        sort(ans.begin(), ans.end());
    }

    for(string i: ans){
        cout<<i <<" ";
    }cout<<endl;

    return 0;
    
}