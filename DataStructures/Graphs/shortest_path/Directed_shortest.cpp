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



    // visited maping
    unordered_map<int, bool> visited;
    stack<int> s;

    // call dfs topological sort until fn for all components
    for (auto j: g.adj){ 
        int i = j.first;
        if(!visited[i]){
            g.topo_sort(i, visited, s); 
        }
    }

    int src = 1;
    vector<int> distance(n);
    for (int i = 0; i < n; i++){
        distance[i] = INT_MAX;
    }

    g.get_shortest_path(src, distance, s);

    for (int i = 0; i < distance.size(); i++){
        cout<<distance[i]<<" ";
    }cout<<endl;
    


    
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