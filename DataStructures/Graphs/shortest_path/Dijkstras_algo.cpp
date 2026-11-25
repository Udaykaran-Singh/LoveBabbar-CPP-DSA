#include <iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
#include<stack>
#include<set>
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

        g.addEdge(u, v, d, 0);
    }


    g.printAdjList();


    // distance vector
    vector<int> dist(n);
    for (int i = 0; i < n; i++){
        dist[i] = INT_MAX;
    }

    set<pair<int, int> > st;
    
    int source = 0;
    dist[source] = 0;                     // source to itself
    
    st.insert(make_pair(0, source));      // make_pair( distance(weight) form source node, to node)

    while(!st.empty()){
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        // remove top record now
        st.erase(st.begin());

        // traverse on neighbours
        for(auto neighbour : g[topNode]){
            if(nodeDistance + neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                // if record found, then erase it
                if(record != st.end()){
                    st.erase(record);
                }

                // distance update
                dist[neighbour.first] = nodeDistance + neighbour.second;

                // record push in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
                 
            }
        }
    }

    for(auto i:dist){
        cout<<i<<" ";
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