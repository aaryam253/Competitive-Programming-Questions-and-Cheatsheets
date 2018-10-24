#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

list<long long> AL[1000000];
unordered_map<long long, int> incoming;
int n;


bool isCyclicUtil(long long v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;
        
        for(auto i = AL[v].begin(); i != AL[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}

bool isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[n];
    bool *recStack = new bool[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < n; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;
    
    return false;
}


void DFS_recur (long long vertex, unordered_map<long long, int> *visited, list<long long> * topo_list) {
    // Mark visited
    visited->insert(make_pair(vertex, 1));
    // Show its visits
    for (auto it = AL[vertex].begin(); it != AL[vertex].end(); it++) {
        // Traverse thru the columns on the same row
        if (visited->find(*it) == visited->end()) {
            // unvisited vertex
            DFS_recur(*it, visited, topo_list);
        }
        // Else skip it
    }
    // Finish DFS, add to back of list
    topo_list->push_back(vertex);
}


void topo_sort_dfs (long long v) {
    list<long long> topo;
    unordered_map<long long, int> visited;
    DFS_recur(v, &visited, &topo);
    topo.reverse();
    for (auto it : topo ) {
        cout << it << endl;
    }
}


int main(){
    long long m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        long long a, b; cin >> a >> b;
        AL[a].push_back(b);
        incoming[b]++;
    }
    
    if (isCyclic()) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    for (int i = 1; i < n; i++) {
        if (incoming.find(i) == incoming.end()) {
            topo_sort_dfs(i);
            break;
        }
    }
    
    //topo_sort_dfs(1);
    
}

