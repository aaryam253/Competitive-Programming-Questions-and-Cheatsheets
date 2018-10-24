class adj_mtx {
    // Big space complexity of O(V^2)
    
    // Used for quick random access
    
private:
    bool arr[10][10] = {{0}}; // Simple unwieghted adjacency mtx
    // Num rows is also num of vertices
    int numEdges, numV;
    
    // BFS is a queue, DFS is a stack/ implicit stack
    // O (V + E)
    // O (VE) in edge list as we have to traverse the entire edge list on every vertex
    // O (V^2) in AM
    void DFS_recur (int vertex, unordered_map<int, int> *visited) {
        // Mark visited
        visited->insert(make_pair(vertex, 1));
        // Show its visits
        cout << vertex << endl;
        for (int i = 0; i < numV; i++) {
            // Traverse thru the columns on the same row
            if (arr[vertex][i] == true && i != vertex) {
                // Connected vertex
                if (visited->find(i) == visited->end()) {
                    // unvisited vertex
                    DFS_recur(i, visited);
                }
            }
        }
    }
    
    void scan_neighbours (queue<int> *q, int vertex, unordered_map<int, int> *visited) {
        for (int i = 0; i < numV; i++) {
            if (arr[vertex][i] == true && visited->find(i) == visited->end()) {
                // Not visited
                visited->insert(make_pair(i, 1));
                q->push(i); // Push the vertices to the queue
            }
        }
    }
    
    
public:
    adj_mtx (int numV) {this->numV = numV;}
    
    void connect (int v, int v2) {
        arr[v][v2] = true;
        arr[v2][v] = true; // Add this to make it undirected
        numEdges++;
    }
    void disconnect (int v, int v2) {
        arr[v][v2] = false;
        arr[v2][v] = false; // Add this to make it undirected
        numEdges--;
    }
    
    bool isConnected (int v, int v2) {
        // O(1)
        return arr[v][v2];
    }
    
    int getEdges () {
        return numEdges;
    }
    int getV () {
        return numV;
    }
    
    void find_neighbour (int v) {
        // Slow - O(N)
        for (int i = 0; i < numV; i++) {
            if (arr[v][i]) {
                cout << i << endl;
            }
        }
    }
    
    void DFS (int vertex) {
        unordered_map<int, int> visited;
        DFS_recur(vertex, &visited);
        // Will create a minimum spanning tree - IE a path thru all vertices with least edges
        // when we backtrack
    }

    // O (V + E)
    // O (VE) in edge list as we have to traverse the entire edge list on every vertex
    void BFS (int vertex) {
        unordered_map<int, int> visited;
        queue<int> q;
        int curr = vertex;
        q.push(curr); // Initial push
        visited[curr] = 1; // Mark as visited
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            cout << curr << endl;
            scan_neighbours(&q, curr, &visited);
        }
        
        
    }
    
    void print_mtx () {
        for (int i = 0; i < numV; i++) {
            for (int d = 0; d < numV; d++) {
                cout << arr[i][d] << " ";
            }
            cout << endl;
        }
    }
    
    
};


class adj_list {
    // Space complexity: O(V+E)
protected:
    int numV;
    int numEdges;
    list<int> AL[10]; // Push back when we wanna add new adjacent vertices
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

    bool isCyclicUtil(long long v, bool visited[], bool *recStack)
    {
        if(visited[v] == false) {
            // Mark the current node as visited and part of recursion stack
            visited[v] = true;
            recStack[v] = true;
            
            for(auto i = AL[v].begin(); i != AL[v].end(); ++i) {
                if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                    return true;
                else if (recStack[*i])
                    return true;
            }
        }
        recStack[v] = false;  // remove the vertex from recursion stack
        return false;
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
    
    // Time complexities
    // O (V + E)
    // If everything is not connected: O (V + E)
    // O (V^2) in AM
    void DFS (int vertex) {
        unordered_map<int, int> visited;
        DFS_recur(vertex, &visited);
        // Will create a minimum spanning tree - IE a path thru all vertices with least edges
        // when we backtrack
    }
    
    // O (V + E)
    void BFS (int vertex) {
        unordered_map<int, int> visited;
        queue<int> q;
        int curr = vertex;
        q.push(curr); // Initial push
        visited[curr] = 1; // Mark as visited
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            cout << curr << endl;
            scan_neighbours(&q, curr, &visited);
        }
    }

    // Check for cycle 
    bool isCyclic() {
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

};


class edge_list {
    // Space complexity: O(E)
private:
    set<tuple<int,int,int>> EL; // Normally we store the weights as well to be sorted for algos like Kruskal's algo
    int numV, numEdges;
public:
    edge_list (int numV) {this->numV = numV;}
    
    void connect (int v, int v2, int weight) {
        EL.insert(make_tuple(weight, v, v2)); // Follow the format of weight, v, v2
    }
    
    void disconnect (int v, int v2) {
        for (auto it = EL.begin(); it != EL.end(); it++) {
            if (get<1>(*it) == v && get<2>(*it) == v2) {
                EL.erase(it);
                break;
            }
        }
    }
    
    
};


class sample_topo_sort : adj_list {
    
//Topological sort of a DAG is a linear ordering of the DAG's vertices 
//in which each vertex comes before all vertices to which it has outbound edges.

// Min: When its only a straight line from front to end 
// Max: All unconnected components, V! 

private:
    unordered_map<int, int> incoming;
    
    // Note: The ordering of operations here is very impt. We need to only push back to the list after iterating thru all of its neighbours
    void DFS_recur (int vertex, unordered_map<int, int> *visited, list<int> * topo_list) {
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

public:
    
    void connect (int v, int v2) {
        AL[v].push_back(v2);
        incoming[v2]++;
    }
    
    sample_topo_sort () : adj_list(10) {
        // Init a sample graph  CP3 4.17 DAG
        // Override
        connect(0, 3);
        connect(0, 1);
        connect(0, 2);
        connect(1, 3);
        connect(1, 4);
        connect(2, 4);
        connect(3, 4);
    }
    
    void topo_sort_dfs (int v) {
        list<int> topo;
        unordered_map<int, int> visited;
        DFS_recur(v, &visited, &topo);
        topo.reverse();
        for (auto it : topo ) {
            cout << it << " ";
        }
        cout << endl;
    }
    
    // Warning: This will delete all your edges
    void topo_sort_bfs (int v) {
        queue<int> Q;
        // Add vertices with no incoming edges to Q
        
        for (int i = 0; i < 5 ; i++) {
            if (incoming.find(i) == incoming.end()) {
                // No incoming edges
                Q.push(i);
            }
        }

        int curr;
        while (!Q.empty()) {
            curr = Q.front(); Q.pop();
            cout << curr << " ";
            for (auto it = AL[curr].begin(); it != AL[curr].end(); it++) {
                AL[curr].erase(it); // Delete the edge
                if (incoming.find(*it) != incoming.end()) incoming[*it]--; // Remove 1 from num incoming for that neighbour
                if (incoming[*it] == 0) Q.push(*it); // If it has no incoming edge, add it to Q
            }
        }
        cout << endl;
    }
};



// Vertex in cycle checker 

class vertex_in_cycle : adj_list {
private:
    
    unordered_map<int, int> degree;
    unordered_map<int, int> is_cycle;

    
public:
    vertex_in_cycle (int size):adj_list (size) {}
    
    void connect (int v, int v2) {
        AL[v2].push_back(v); // Notice how we link up v2 to v instead of the other way round
        // We need to traverse the other ways in this case
        degree[v]++; // Degree is the number of outgoing edges from this vertex
        
        // Mark them all as part of cycle first
        is_cycle[v] = 1;
        is_cycle[v2] = 1;
    }
    
    void search () {
        queue<int> q;
        // We target the vertices with no outgoing edges first
        for (int i = 0; i < numV; i++) {
            if (degree[i] == 0) {
                q.push(i);
            }
        }
        // When it has no outgoing arrows, it is automatically not in a cycle already.
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            is_cycle[curr] = 0;
            for (auto it = AL[curr].begin(); it != AL[curr].end(); it++) {
                degree[*it]--;
                if (degree[*it] == 0) q.push(*it);
            }
        }
    }
    
    int is_part_of_cycle (int v) {
        return is_cycle[v];
    }
    
};



// Count connected components 

class self_labelling {
protected:
    list<int> AL[10];
    unordered_map<int, int> painted;
    int color;
    int numv;
    
    void DFS_recur (int vertex) {
        // Mark visited
        painted.insert(make_pair(vertex, color));
        // Show its visits
        for (auto it = AL[vertex].begin(); it != AL[vertex].end(); it++) {
            // Traverse thru the columns on the same row
            if (painted.find(*it) == painted.end()) {
                // unvisited vertex
                DFS_recur(*it);
            }
        }
    }

    
public:
    self_labelling (int size) {this->numv = size; color = 1;}
    
    void connect (int v, int v2) {
        AL[v].push_back(v2);
        AL[v2].push_back(v);
        // Undirected graph
    }
    
    void DFS () {
        for (int i = 0; i < numv; i++) {
            if (painted.find(i) == painted.end()) {
                DFS_recur(i);
                color++;
            }
        }
    }
    
    void get_color (int v) {
        DFS();
        // BFS should be similar
        
        // This technique can be good for counting num disjointed sets too by checking how many colors have been painted
        cout << painted[v] << endl;
    }
};




// TODO: Fill in more theory on graphs like acyclic or special graphs down here.


/*
    DAG proof: 
    - Suppose you can reach u again through some series of directed edges 
    - Then it violates acyclic property and cannot be a DAG 


*/

// Some notes: 
/*
    Bipartite graphs: 
    - A set of vertices seperated into 2 disjoint sets where vertices of the same set are not directly adjacent to each other 

    DAGs: 
    - A graph which is direct and acylic (Warning: it cannot be weighted too)

    Toposort: 
    - Consider all vertices with only outgoing edges first (smallest to largest) - visualgo 
    - Follow same style as BFS topo sort

    Edges that will always be present in min spanning tree:
    - Basically edges to a vertex that cannot be substituted with any other (non cycles, single path)

    Misc: 
    - During BFS/ DFS always go in order of elements (smallest first) in visualgo 
    - Complete graph has edges = v(v-1)/2,  v is num vertices 
    - Complete directed graph has edges = v(v-1)


    Adjacency lists 
    - used for large vertices where v*v is beyond memory size
    - Also used when neighbours are frequently enumerated 

    Adjacency matrix 
    - used when the vertice and its neighbours are randomly accessed 
    - When size permits 

    Edge list 
    - Used when we need the edges to be sorted 
    - Usually stored in the PQ of dijkstra 
*/


