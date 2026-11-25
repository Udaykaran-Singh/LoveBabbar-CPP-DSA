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

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<int> &result, Graph &g){

    visited[node] = true;
    disc[node] = low[node] = timer++;

    for(auto nbr : g[node]){
        
        if(nbr == parent) continue;

        if(!visited[nbr]){
            dfs(nbr, node, timer, disc, low, result, adj, vis);
            low[node] = min(low[node], low[nbr]);

            // check edge is bridge
            if(low[nbr] > disc[node]){
                vector<int> ans;
                ans..push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else{
            // back edge
            low[node] = min(low[node], disc[nbr]);
        }
    }

}

vector<vector<int> > Articulation_point(Graph<int> &g, int &v, int &e){
    vector<vector<int> > result;
    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    int parent = -1;
    vector<int> vis(v, false);

    // dfs
    for(int i = 0; i < v; i++){
        if(!vis[i]){
            dfs(i, parent, timer, disc, low, result, g);
        }
    }

    return result;
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