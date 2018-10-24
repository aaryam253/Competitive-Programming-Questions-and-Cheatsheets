#include <iostream>
#include <stdio.h>
#include <queue>
#include <list>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;




class adj_list {
    // Space complexity: O(V+E)
private:
    int numV;
    int numEdges;
    list<int> AL[200000]; // Push back when we wanna add new adjacent vertices
    // We can also use vector of vectors due to its dynamic properties (ability to push_back)
    
    // Size of array is also num vertices
    set<int> connected;
    
    
    void DFS_recur (int vertex, unordered_map<int, int> *visited) {
        // Mark visited
        visited->insert(make_pair(vertex, 1));
        // Show its visits
        cout << vertex << endl;
        for (auto it = AL[vertex].begin(); it != AL[vertex].end(); it++) {
            // Traverse thru the columns on the same row
            if (visited->find(*it) == visited->end()) {
                // unvisited vertex
                DFS_recur(*it, visited);
            }
        }
    }
    
    void scan_neighbours (queue<int> *q, int vertex, unordered_map<int, int> *visited) {
        for (auto it = AL[vertex].begin(); it != AL[vertex].end(); it++) {
            if (visited->find(*it) == visited->end()) {
                visited->insert(make_pair(*it, 1));
                q->push(*it);
            }
        }
    }
    
public:
    adj_list (int numV) {
        this->numV = numV;
    }
    
    void connect (int v, int v2) {
        auto it = find(AL[v].begin(), AL[v].end(), v2);
        if (it == AL[v].end()) {
            AL[v].push_back(v2);
            AL[v2].push_back(v);
            numEdges++;
        }
    }
    
    
    bool isConnected (int v, int v2) {
        // Slower - O(k)
        auto it = find(AL[v].begin(), AL[v].end(), v2);
        if (it != AL[v].end()) return true;
        return false;
    }
    
    
    void DFS (int vertex) {
        unordered_map<int, int> visited;
        DFS_recur(vertex, &visited);
        // Will create a minimum spanning tree - IE a path thru all vertices with least edges
        // when we backtrack
    }
    
    void BFS (int vertex) {
        unordered_map<int, int> visited;
        queue<int> q;
        int curr = vertex;
        q.push(curr); // Initial push
        visited[curr] = 1; // Mark as visited
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            connected.insert(curr);
            scan_neighbours(&q, curr, &visited);
        }
    }
    
    void print_not_connected () {
        for (int i = 0; i < numV; i++) {
            if (connected.find(i) == connected.end()) cout << i+1 << endl;
        }
        if (connected.size() == numV) cout << "Connected" << endl;
    }
};



int main () {
    int num, edges;
    cin >> num >> edges;
    adj_list mygraph (num);
    while (edges--) {
        int v, v2;
        cin >> v >> v2;
        mygraph.connect(v2-1, v-1);
    }
    
    mygraph.BFS(0);
    mygraph.print_not_connected();
}
