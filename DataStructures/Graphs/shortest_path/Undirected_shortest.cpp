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

int main(){

    int n;
    cout<<"Enter the number of nodes :"<<endl;
    cin>>n;

    int m;
    cout<<"Enter the number of edges :"<<endl;
    cin>>m;

    Graph<int> g;

    for (int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;

        // creating graph
        g.addEdge(u,v,0);
    }

    // printing graph
    g.printAdjList();

    // do bfs
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;

    int from = 1;
    int to = 7;

    q.push(from);
    parent[from] = -1;
    visited[from] = true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        for(auto neighbour : g[frontNode]){
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
            }
        }
    }

    vector<int> ans;
    int currentNode = to;
    ans.push_back(to);

    while(currentNode != from){
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    reverse(ans.begin(), ans.end());
    for(auto i:ans){
        cout<<i<<"->";
    }cout<<endl;


// 8
// 9
// 1 2
// 1 3
// 1 4
// 2 5
// 4 6
// 6 7
// 5 8
// 3 8
// 7 8
    
    return 0;
}