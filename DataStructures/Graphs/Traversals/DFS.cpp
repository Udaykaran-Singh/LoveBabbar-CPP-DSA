#include <iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class Graph{
    public:
        unordered_map<T, list<T> > adj;

        void addEdge(T u, T v, bool direction){
            // direction = 0 -> undirected
            // direction = 1 -> directed graph

            // create and edge from u to v
            adj[u].push_back(v);
            if(direction == 0){
                adj[v].push_back(u);
            }
        }

        void printAdjList(){
            for(auto i:adj){
                // printint node
                cout<<i.first<<"->";

                // printing adj list
                for(auto j:i.second){
                    cout<<j<<", ";
                }cout<<endl;
            }
        }

        list<T> operator [](T a){
            return adj[a];
        }
};

void dfs(Graph<int> &adjList, unordered_map<int, bool> &visited, vector<int> &component, int node){
    component.push_back(node);
    visited[node] = true; 

    // hr connected node k liye recursive call
    for(auto i:adjList[node]){
        if(!visited[i]){
            dfs(adjList, visited, component, i);
        }
    }
}

int main(){

    int n;
    cout<<"Enter the number of nodes :"<<endl;
    cin>>n;

    int m;
    cout<<"Enter the number of edges :"<<endl;
    cin>>m;

    Graph<int> adjList;

    for (int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;

        adjList.addEdge(u,v,0);
    }


    adjList.printAdjList();


    // visited maping
    unordered_map<int, bool> visited;
    vector<vector<int> > ans;


    for (auto j: adjList.adj){ 
        int i = j.first;
        if(!visited[i]){
            vector<int> component;
            dfs(adjList, visited, component, i);
            ans.push_back(component);
        }

    }
    

    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
    }cout<<endl;

// 9
// 9
// 0 4
// 4 2
// 4 1
// 2 3
// 3 5
// 5 1
// 10 11
// 11 12
// 12 10

    
    return 0;
}