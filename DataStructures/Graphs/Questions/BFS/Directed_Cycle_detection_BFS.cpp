#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

template <typename T>
class Graph {
public:
    unordered_map<T, list<T> > adj;

    void addEdge(T u, T v, bool direction) {
        // direction = 0 -> undirected
        // direction = 1 -> directed graph

        // create an edge from u to v
        adj[u].push_back(v);
        if (direction == 0) {
            adj[v].push_back(u);
        }
    }

    void printAdjList() {
        for (auto i : adj) {
            // printing node
            cout << i.first << "->";

            // printing adj list
            for (auto j : i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    list<T> operator[](T a) {
        return adj[a];
    }
};

int main() {
    int n;
    cout << "Enter the number of nodes :" << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges :" << endl;
    cin >> m;

    Graph<int> adjList;

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adjList.addEdge(u, v, 1); // directed graph
    }

    adjList.printAdjList();

    // Initialize indegree map
    unordered_map<int, int> indegree;
    for (auto i : adjList.adj) {
        indegree[i.first] = 0; // initialize indegree for all nodes
    }

    // Calculate indegree
    for (auto i : adjList.adj) {
        for (auto j : i.second) {
            indegree[j]++;
        }
    }

    // Push nodes with indegree 0 into the queue
    queue<int> q;
    for (auto i : indegree) {
        if (i.second == 0) {
            q.push(i.first);
        }
    }

    int count = 0;
    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();

        // Increase count
        count++;

        // Neighbor indegree update
        for (auto neighbor : adjList[frontNode]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Check for cycle
    if (count == indegree.size()) {
        cout << "Not cyclic" << endl;
    } else {
        cout << "Cyclic" << endl;
    }


// 5
// 4
// 0 1
// 0 2
// 2 3
// 3 4


    return 0;
}
