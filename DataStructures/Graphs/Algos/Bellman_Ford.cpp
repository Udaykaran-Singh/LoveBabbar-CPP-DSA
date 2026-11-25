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

int shortest_path_for_negitive_weights(int n, int m, int src, int dest, vector<vector<int> > &edges){
    vector<int> dist(n+1, INT_MAX);
    dist[src] = 0;

    // n-1 times
    for(int i = 1; i <= n; i++){
        // traverse on edge list
        for(int j = 0; j < m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] != INT_MAX && ((dist[u] + wt) < dist[v]) ){
                dist[v] = dist[u] + wt;
            }
        }
    }

    // check for -ve cycle
    bool flag = false;
    for (int j = 0; j < m; j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if(dist[u] != INT_MAX && ((dist[u] + wt) < dist[v])){
            flag = true;
        }
    }

    if(flag == 0){
        return dist[dest];
    }

    return -1;
    
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
        int u, v, wt;
        cin>>u>>v>>wt;

        // creating graph
        g.addEdge(u, v, wt, 0);
    }

    // printing graph
    g.printAdjList();

    return 0;
}