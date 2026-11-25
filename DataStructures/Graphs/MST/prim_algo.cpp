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
        unordered_map<T, list<pair<T, int> > > adj;

        void addEdge(T u, T v, int weight, bool direction){
            // direction = 0 -> undirected
            // direction = 1 -> directed graph

            // create and edge from u to v
            adj[u].push_back(make_pair(v, weight));
            if(direction == 0){
                adj[v].push_back(make_pair(u, weight));
            }
        }

        void printAdjList(){
            for(auto i:adj){
                // printint node
                cout<<i.first<<"->";

                // printing adj list
                for(auto j:i.second){
                    cout<<"("<<j.first<<", "<<j.second<<"), ";
                }cout<<endl;
            }
        }


        void topo_sort(int node, unordered_map<int, bool> &visited, stack<int> &s){

            visited[node] = true;

            for(auto neighbour: adj[node]){
                if(!visited[neighbour.first]){
                    topo_sort(neighbour.first, visited, s);
                }
            }

            // important
            s.push(node);
        }


        void get_shortest_path(int src, vector<int> &dist, stack<int> &s){
            dist[src] = 0;
 
            while(!s.empty()){
                int top = s.top();
                s.pop();

                if(dist[top] != INT_MAX){
                    for(auto i:adj[top]){
                        if(dist[top] + i.second < dist[i.first]){
                            dist[i.first] = dist[top] + i.second;
                        }
                    }
                }
            }
        }

        list<pair<T, int> > operator [](T a){
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

    Graph<int> g;

    for (int i = 0; i < m; i++){
        int u, v, d;
        cin>>u>>v>>d;

        g.addEdge(u, v, d, 1);
    }


    g.printAdjList();


    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    for (int i = 0; i <= n; i++){
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    // let's start the algo
    key[1] = 0;
    parent[1] = -1;

    for (int i = 1; i < n; i++){
        int mini = INT_MAX;
        int u;

        for (int v = 1; v <= n; v++){
            if(mst[v] == false && key[v] < mini){
                u = v;
                mini = key[v];
            }
        }
        
        // mark min node as true;
        mst[u] = true;

        // check its adjacent nodes
        for(auto it:g[u]){
            int v = it.first;
            int w = it.second;
            if(mst[v] == false && w < key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int> > result;              // { { u -> v }, w8 }

    for (int i = 2; i <= n; i++){
        result.push_back({{parent[i], i}, key[i]});
    }

    
// 6
// 9
// 0 1 5 
// 0 2 3
// 1 2 2
// 1 3 6
// 2 3 7
// 2 4 4
// 2 5 2
// 3 4 -1
// 4 5 -2

    
    return 0;
}