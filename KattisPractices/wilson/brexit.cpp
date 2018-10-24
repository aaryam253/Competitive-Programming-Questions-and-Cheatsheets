#include <iostream>
#include <stdio.h>
#include <list>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <unordered_set>

#define INT_MAX 1000000

using namespace std;

struct node {
    int before;
    unordered_set<int> adj;
};

class adj_list {
    // Space complexity: O(V+E)
private:
    int numV;
    int numEdges;
    node AL[200005];
    
    void scan_neighbours (queue<int> *q, int vertex, unordered_set<int> *left) {
        if (AL[vertex].adj.size() <= AL[vertex].before/2) {
            //cout << "vertex: "<< vertex << endl;
            left->insert(vertex);
            while (!AL[vertex].adj.empty()) {
                if (left->find(*AL[vertex].adj.begin()) == left->end()) {
                    int curr = *AL[vertex].adj.begin();
                    q->push(curr);
                    auto it = AL[curr].adj.find(vertex);
                    AL[curr].adj.erase(it);
                    AL[vertex].adj.erase(AL[vertex].adj.begin());
                    
                }
            }
        }
    }
    
public:
    adj_list (int numV) {
        this->numV = numV;
    }
    
    void connect (int v, int v2) {
        AL[v2].adj.insert(v);
        AL[v].adj.insert(v2);
        
        AL[v2].before++;
        AL[v].before++;
        
    }
    
    void disconnect (int v, int v2) {
        auto it = find(AL[v].adj.begin(), AL[v].adj.end(), v2);
        auto it2 = find(AL[v2].adj.begin(), AL[v2].adj.end(), v);
        if (it != AL[v].adj.end()) {
            AL[v].adj.erase(it);
        }
        if (it2 != AL[v2].adj.end()) AL[v2].adj.erase(it2);
        // Have to find first then delete
    }
    
    
    void BFS (int vertex) {
        unordered_set<int> left;
        queue<int> q;
        int curr = vertex;
        q.push(curr); // Initial push
        left.insert(curr); // Mark as left
        AL[vertex].before = INT_MAX;
        
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            //cout << curr << endl;
            
            scan_neighbours(&q, curr, &left);
        }
    }
    
    void chain_reaction (int vertex) {
        BFS(vertex);
    }
    
    int getsize (int vertex) {
        return AL[vertex].adj.size();
    }
    
    int getsize_before (int vertex) {
        return AL[vertex].before;
    }
    
};


int main () {
    int v , e;
    cin >> v;
    cin >> e;
    adj_list mygraph(v);
    
    int home, target; cin >> home >> target;
    
    while (e--) {
        int v, v2; cin >> v >> v2;
        mygraph.connect(v, v2);
    }
    mygraph.chain_reaction(target);
    if (!mygraph.getsize(home)) {
        cout << "leave" << endl;
    }else {
        cout << "stay" << endl;
    }
    //cout << mygraph.getsize(home) << endl;
    //cout << mygraph.getsize_before(home) << endl;
    
}

