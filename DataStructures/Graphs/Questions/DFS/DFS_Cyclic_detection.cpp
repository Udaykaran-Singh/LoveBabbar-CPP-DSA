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

bool isCyclic_dfs(Graph<int> &adjList, int parent, unordered_map<int, bool> &visited, int node){

    visited[node] = true;

    // hr connected node k liye recursive call
    for(auto neighbour:adjList[node]){
        if(!visited[neighbour]){
            bool cycle_detected = isCyclic_dfs(adjList, node, visited, neighbour);
            if(cycle_detected){
                return true;
            }
        }
        else if(neighbour != parent){
            // cycle present
            return true;
        }

    }
    return false;    

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
    bool ans;


    for (auto j: adjList.adj){
        int i = j.first;
        if(!visited[i]){
            ans = isCyclic_dfs(adjList, -1, visited, i);
        }

    }
    
    cout<<(ans?"true":"flase");

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