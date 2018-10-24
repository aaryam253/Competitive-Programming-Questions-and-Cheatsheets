#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <list>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;


class adj_list {
    // Space complexity: O(V+E)
protected:
    int numV;
    int numEdges;
    list<int> AL[1000]; // Push back when we wanna add new adjacent vertices
    // We can also use vector of vectors due to its dynamic properties (ability to push_back)
    
    // Size of array is also num vertices
    
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
    
    void disconnect (int v, int v2) {
        auto it = find(AL[v].begin(), AL[v].end(), v2);
        auto it2 = find(AL[v2].begin(), AL[v2].end(), v);
        if (it != AL[v].end()) {
            AL[v].erase(it);
            numEdges--;
        }
        if (it2 != AL[v2].end()) AL[v2].erase(it2);
        // Have to find first then delete
    }
    
    bool isConnected (int v, int v2) {
        // Slower - O(k)
        auto it = find(AL[v].begin(), AL[v].end(), v2);
        if (it != AL[v].end()) return true;
        return false;
    }
    
    int getV () {
        return numV;
    }
    
    int getEdges () {
        return numEdges;
        // We can also get the num of edges by summing up all the sizes of list and then dividing by 2
    }
    void find_neighbour (int v) {
        for (auto it = AL[v].begin(); it != AL[v].end(); it++) {
            cout << *it << endl;
        }
        // Will only traverse as many as number of neighbour the node V has
    }
    
    void DFS (int vertex) {
        unordered_map<int, int> visited;
        DFS_recur(vertex, &visited);
        // Will create a minimum spanning tree - IE a path thru all vertices with least edges
        // when we backtrack
    }
    
    int BFS (int vertex) {
        int count = 0;

        while (true) {
            unordered_map<int, int> visited;
            queue<int> q;
            int curr = vertex;
            q.push(curr); // Initial push
            visited[curr] = 1; // Mark as visited
            while (!q.empty()) {
                curr = q.front();
                q.pop();
                scan_neighbours(&q, curr, &visited);
            }
            
            // Check for num elements in visited.
            if (visited.size() == numV) break;
            else {
                for (int i = 0; i < numV; i++) {
                    if (visited.find(i) == visited.end()) {
                        // Visited does not contain the element
                        count++;
                        AL[visited.begin()->first].push_back(i);
                        break;
                    }
                }
            }
        }
        return count;
    }
};


int main () {
    int TC; cin >> TC;
    while (TC--) {
        int numv; cin >> numv;
        adj_list graph (numv);
        int edges; cin >> edges;
        while (edges--) {
            int v, v2; cin >> v >> v2;
            graph.connect(v, v2);
        }
        cout << graph.BFS(0) << endl;
    }
}

