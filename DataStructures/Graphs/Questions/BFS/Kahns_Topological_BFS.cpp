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


    vector<int> indegree(n);
    for(auto i: adjList.adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
    // do bfs
    vector<int> ans;
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        // ans store
        ans.push_back(frontNode);

        // neighbour indegree update
        for(auto neighbour : adjList[frontNode]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }

    for(auto i:ans){
        cout<<i<<" ";
    }cout<<endl;
    

// 5
// 4
// 0 1
// 0 2
// 2 3
// 3 4

    
    return 0;
}