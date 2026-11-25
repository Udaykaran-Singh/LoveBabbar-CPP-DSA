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


void reverse_dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int> > &transpose){
    visited[node] = true;
    for(auto nbr : transpose[node]){
        if(!visited[nbr]){
            reverse_dfs(nbr, visited, transpose);
        }
    }
} 

int stronglyConnectedComponents(int v, Graph<int> &g){

    // topo sort
    stack<int> s;
    unordered_map<int, bool> visited;
    for (int i = 0; i < v; i++)
    {
        if(!visited[i]){
            g.topo_sort(i, visited, s);
        }
    }

    // create transpose graph
    unordered_map<int, list<int> > transpose;
    for (int i = 0; i < v; i++){
        visited[i] = 0;
        for(auto nbr : g.adj){
            transpose[nbr].push_back(i);
        }
    }

    // dfs call suing above ordering
    int count = 0;
    while(!s.empty()){
        int top = s.top();
        st.pop();
        if(!visited[top]){
            count++;
            reverse_dfs(node, visited, transpose);
        }
    }

    return count; 
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