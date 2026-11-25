#include <iostream>
#include<unordered_map>
#include<list>
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

bool checkCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfs_visited, Graph<int> &g){

    visited[node] = true;
    dfs_visited[node] = true;

    for(auto neighbour: g[node]){
        if(!visited[neighbour]){
            bool CycleFound = checkCycleDFS(neighbour, visited, dfs_visited, g);
            if(CycleFound){
                return true;
            }
        }
        else if(dfs_visited[neighbour]){
            return true;
        }
    }

    dfs_visited[node] = false;
    return false;
}

int main(){

    int n;
    cout<<"Enter the numverof nodes :"<<endl;
    cin>>n;

    int m;
    cout<<"Enter the number of edges :"<<endl;
    cin>>m;

    Graph<int> g;

    for (int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;

        g.addEdge(u,v,1);
    }

    // printing graph
    g.printAdjList();
    

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfs_visited;

    for(auto j:g.adj){
        int i = j.first;
        if(!visited[i]){
            bool CycleFound = checkCycleDFS(i, visited, dfs_visited, g);
            if(!visited[i]){
                return true;
            }
        }
    }

// 8
// 9
// 1 2
// 2 3
// 2 4
// 3 7
// 3 8
// 8 7
// 4 5
// 5 6
// 6 4
    
    return 0;
}