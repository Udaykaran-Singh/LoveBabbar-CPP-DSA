#include <iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
#include<stack>
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

void topo_sort(int node, unordered_map<int, bool> &visited, stack<int> &s, Graph<int> &adjList){

    visited[node] = true;

    for(auto neighbour: adjList[node]){
        if(!visited[neighbour]){
            topo_sort(neighbour, visited, s, adjList);
        }
    }

    // important
    s.push(node);
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

        adjList.addEdge(u,v,1);
    }


    adjList.printAdjList();



    // visited maping
    unordered_map<int, bool> visited;
    stack<int> s;

    // call dfs topological sort until fn for all components
    for (auto j: adjList.adj){ 
        int i = j.first;
        if(!visited[i]){
            topo_sort(i, visited, s, adjList); 
        }
    }

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    

    
// 5
// 4
// 1 2
// 1 3
// 2 4
// 4 5


    
    return 0;
}